/**
 * @file 30_multithreaded_file_analyzer.c
 * @author dunamismax 
 * @date 2025-06-10
 *
 * @brief An expert-level project: A concurrent file analyzer using multiple threads.
 *
 * ---
 *
 * Welcome to Concurrent Programming
 *
 * This program analyzes a text file to count total lines, words, and character
 * frequencies. To make it fast for large files, it divides the work among
 * multiple threads, which run in parallel.
 *
 * This is one of the most complex topics in C.
 *
 * Core Concepts:
 * 1.  **Concurrency vs. Parallelism:** Concurrency is about dealing with many things at
 *     once. Parallelism is about doing many things at once. Our threaded program
 *     is concurrent by design and can run in parallel on a multi-core processor.
 *
 * 2.  **pthreads (POSIX Threads):** The standard C library for threading on Linux/macOS.
 *     We use it to create and manage the lifecycle of our threads.
 *
 * 3.  **Race Condition:** This is the #1 danger in concurrent programming. It happens when
 *     multiple threads try to access and modify the same shared data (like a global
 *     word count) at the same time. The final result depends on the unpredictable
 *     order of their execution, leading to incorrect results.
 *
 * 4.  **Mutex (Mutual Exclusion):** To prevent race conditions, we use a "mutex."
 *     A mutex is like a locked room with a single key. A thread must acquire the
 *     key (lock the mutex) before it can enter the "critical section" where it
 *     modifies shared data. Once it's done, it releases the key (unlocks the mutex),
 *     allowing another thread to enter. This ensures only one thread can update the
 *     global counts at a time.
 *
 * 5.  **Strategy:** Each thread will process a unique chunk of the file. To be
 *     efficient, it will calculate its own *local* counts. Only when it's finished
 *     with its chunk will it lock the mutex and add its local counts to the
 *     *global* totals. This minimizes the time spent waiting for the lock.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * **This program requires a POSIX system (Linux, macOS, WSL).**
 *
 * 1.  **Create a large test file:** You need a file large enough to notice the
 *     performance difference. You can download one or create one:
 *     `head -c 50M /dev/urandom | base64 > large_file.txt` (Creates a ~65MB file)
 *
 * 2.  **Compile the code:** You must link the pthreads library with the `-pthread` flag.
 *     `gcc -Wall -Wextra -std=c11 -o analyzer 30_multithreaded_file_analyzer.c -pthread`
 *
 * 3.  **Run the executable:**
 *     `./analyzer large_file.txt`
 *
 * 4.  The program will print the final analysis after all threads have completed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> // The POSIX Threads header
#include <ctype.h>   // For isspace(), isalpha()

#define NUM_THREADS 4
#define ALPHABET_SIZE 26

// --- Shared Data and Synchronization ---

// Structure to hold the final, aggregated results from all threads.
typedef struct
{
    long long total_lines;
    long long total_words;
    long long char_counts[ALPHABET_SIZE];
    pthread_mutex_t lock; // The mutex to protect access to this structure
} AnalysisResult;

// Structure to pass data to each thread.
typedef struct
{
    const char *buffer_start;
    size_t size;
    AnalysisResult *global_result;
} ThreadData;

// --- The Worker Function ---
void *analyze_chunk(void *arg);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // --- 1. Read the entire file into memory ---
    FILE *file = fopen(argv[1], "rb"); // Open in binary read mode to get accurate size
    if (!file)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *file_buffer = (char *)malloc(file_size + 1);
    if (!file_buffer || fread(file_buffer, 1, file_size, file) != file_size)
    {
        fprintf(stderr, "Error reading file into buffer\n");
        free(file_buffer);
        fclose(file);
        return EXIT_FAILURE;
    }
    file_buffer[file_size] = '\0'; // Null-terminate the buffer
    fclose(file);

    // --- 2. Initialize Shared Data and Threads ---
    AnalysisResult global_result = {0};
    if (pthread_mutex_init(&global_result.lock, NULL) != 0)
    {
        fprintf(stderr, "Mutex init failed\n");
        free(file_buffer);
        return EXIT_FAILURE;
    }

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    size_t chunk_size = file_size / NUM_THREADS;

    printf("Starting analysis with %d threads...\n", NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        thread_data[i].buffer_start = file_buffer + (i * chunk_size);
        thread_data[i].global_result = &global_result;

        // If it's the last thread, give it all remaining data
        if (i == NUM_THREADS - 1)
        {
            thread_data[i].size = file_buffer + file_size - thread_data[i].buffer_start;
        }
        else
        {
            thread_data[i].size = chunk_size;
            // Ensure chunks don't split words - extend to the next space
            size_t end_pos = i * chunk_size + chunk_size;
            while (end_pos < file_size && !isspace(file_buffer[end_pos]))
            {
                thread_data[i].size++;
                end_pos++;
            }
        }

        // Create the thread, passing it the worker function and its data
        if (pthread_create(&threads[i], NULL, analyze_chunk, &thread_data[i]) != 0)
        {
            fprintf(stderr, "Error creating thread %d\n", i);
        }
    }

    // --- 3. Wait for all threads to complete ---
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }
    printf("All threads finished.\n\n");

    // --- 4. Print Final Results and Clean Up ---
    printf("--- File Analysis Complete ---\n");
    printf("Total Lines: %lld\n", global_result.total_lines);
    printf("Total Words: %lld\n", global_result.total_words);
    printf("Character Frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("  %c: %lld\n", 'a' + i, global_result.char_counts[i]);
    }
    printf("------------------------------\n");

    pthread_mutex_destroy(&global_result.lock);
    free(file_buffer);

    return EXIT_SUCCESS;
}

/**
 * @brief The function executed by each thread.
 *        It analyzes its assigned chunk of the file and updates global results.
 */
void *analyze_chunk(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    const char *chunk_end = data->buffer_start + data->size;

    // --- Create LOCAL counts to avoid constant locking ---
    long long local_lines = 0;
    long long local_words = 0;
    long long local_char_counts[ALPHABET_SIZE] = {0};
    int in_word = 0;

    for (const char *ptr = data->buffer_start; ptr < chunk_end; ++ptr)
    {
        // Count lines
        if (*ptr == '\n')
        {
            local_lines++;
        }

        // Count words (state machine)
        if (isspace(*ptr))
        {
            in_word = 0;
        }
        else
        {
            if (in_word == 0)
            {
                local_words++;
                in_word = 1;
            }
        }

        // Count characters
        if (isalpha(*ptr))
        {
            local_char_counts[tolower(*ptr) - 'a']++;
        }
    }

    // --- CRITICAL SECTION ---
    // Now that local counting is done, lock the mutex to update the global results.
    pthread_mutex_lock(&data->global_result->lock);

    data->global_result->total_lines += local_lines;
    data->global_result->total_words += local_words;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        data->global_result->char_counts[i] += local_char_counts[i];
    }

    // Don't forget to unlock the mutex!
    pthread_mutex_unlock(&data->global_result->lock);
    // --- END CRITICAL SECTION ---

    return NULL; // Threads in this design don't need to return a value.
}