/**
 * @file 13_dynamic_memory_allocation.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Introduces manual memory management using malloc, free, and friends.
 *
 * ---
 *
 * What's New in This Program?
 *
 * So far, all the variables and arrays we've created have had their size fixed when we
 * wrote the program. This memory is managed automatically on the "stack". When a
 * function ends, its stack variables are destroyed.
 *
 * But what if you don't know how much memory you need until the program is running?
 * What if you need data to exist beyond the lifetime of a single function? For this,
 * we need **dynamic memory allocation**, which happens on the "heap".
 *
 * - *Analogy:*
 *   - **The Stack:** Like renting a locker at the gym. It's assigned to you when you
 *     start (call a function), it's fast, but it's small, and you have to empty it
 *     when you leave (the function returns).
 *   - **The Heap:** Like a vast public warehouse. You can request a storage unit of any
 *     size, at any time. You get a key (a pointer) to your unit. The data stays
 *     there as long as you want, but you are **responsible** for telling the warehouse
 *     manager when you are done with it so it can be used by someone else.
 *
 * Key Functions from `<stdlib.h>` (Standard Library):
 *
 * 1.  **`malloc(size)`:** "Memory Allocation". This is the most common function. You tell
 *     it how many bytes of memory you want, and it returns a pointer to the start of
 *     that block. It returns a generic `void*` which must be "cast" to your desired pointer type.
 *
 * 2.  **`free(pointer)`:** This is the "giving back the key" step. You pass it the
 *     pointer you got from `malloc`, and it releases the memory back to the system.
 *
 * The Golden Rule of Dynamic Memory:
 * **For every call to `malloc`, there must be exactly one corresponding call to `free`.**
 * - Forgetting to `free` causes a **memory leak**. The program holds onto memory it's no
 *   longer using, which can eventually cause it to run out of memory and crash.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o dynamic_mem 13_dynamic_memory_allocation.c`
 * `./dynamic_mem` (or `dynamic_mem.exe` on Windows)
 *
 */

#include <stdio.h>
// We need the Standard Library header for malloc() and free().
#include <stdlib.h>
#include <string.h> // For strcpy

// We'll reuse our Student struct from the previous lesson
struct Student
{
    char name[50];
    int id;
};

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: Allocating Memory for a Single Integer ---
    printf("--- Part 1: Allocating a single int ---\n");

    // We want to create an integer on the heap.
    // 1. Declare a pointer to hold the address.
    int *p_num = NULL;

    // 2. Request memory from the system.
    //    We use `sizeof(int)` to be portable. Don't hardcode `4`!
    //    We cast the `void*` result from malloc to an `int*`.
    p_num = (int *)malloc(sizeof(int));

    // 3. **CRITICAL STEP:** Check if malloc was successful.
    //    If the system is out of memory, malloc returns NULL. Using a NULL
    //    pointer will crash the program.
    if (p_num == NULL)
    {
        printf("Memory allocation failed! Exiting.\n");
        return 1; // Return a non-zero value to indicate an error.
    }

    // 4. Use the allocated memory via the pointer.
    *p_num = 42;
    printf("Dynamically allocated integer has value: %d\n", *p_num);
    printf("It is stored at heap address: %p\n", p_num);

    // 5. Release the memory back to the system.
    free(p_num);
    p_num = NULL; // Good practice: set pointer to NULL after freeing to prevent accidental reuse.
    printf("Memory has been freed.\n");

    // --- Part 2: Allocating an Array Dynamically ---
    printf("\n--- Part 2: Allocating an array ---\n");

    int num_of_elements;
    printf("How many grades do you want to store? ");
    scanf("%d", &num_of_elements);

    // Declare a pointer to hold the base address of our new array.
    int *p_grades = NULL;

    // Allocate space for `num_of_elements` integers.
    p_grades = (int *)malloc(num_of_elements * sizeof(int));

    if (p_grades == NULL)
    {
        printf("Failed to allocate memory for grades array.\n");
        return 1;
    }

    // Use the memory just like a normal array.
    printf("Memory allocated. Now filling the array.\n");
    for (int i = 0; i < num_of_elements; i++)
    {
        p_grades[i] = (i + 1) * 10; // Fill with some data: 10, 20, 30...
        printf("  p_grades[%d] = %d\n", i, p_grades[i]);
    }

    // When we are done with the array, we free it.
    // We only need one `free()` call, which frees the entire block we allocated.
    free(p_grades);
    p_grades = NULL;
    printf("Grades array memory has been freed.\n");

    // --- Part 3: Allocating a Struct ---
    printf("\n--- Part 3: Allocating a struct ---\n");

    struct Student *p_student = NULL;
    p_student = (struct Student *)malloc(sizeof(struct Student));

    if (p_student == NULL)
    {
        printf("Failed to allocate memory for the student struct.\n");
        return 1;
    }

    // Use the arrow operator `->` to access members of a struct via a pointer.
    strcpy(p_student->name, "John Doe");
    p_student->id = 205;

    printf("Dynamically allocated student: %s, ID: %d\n", p_student->name, p_student->id);

    // Free the memory for the struct.
    free(p_student);
    p_student = NULL;
    printf("Student struct memory has been freed.\n");

    return 0;
}