/**
 * @file 27_build_your_own_grep.c
 * @author dunamismax (enhanced by Gemini)
 * @date 2025-06-10
 *
 * @brief An expert-level project: A simplified version of the 'grep' utility.
 *
 * ---
 *
 * What is `grep`?
 *
 * `grep` (Global Regular Expression Print) is a powerful command-line tool used to
 * search for a specific text pattern within files. Our version will be simplified:
 * it will search for a fixed substring (not a complex regular expression) inside
 * a single file and print any lines that contain it.
 *
 * This project is a perfect example of how to build a useful command-line utility.
 *
 * Core Concepts:
 * 1.  **Command-Line Arguments (`argc`, `argv`):** This program doesn't ask for input
 *     while it's running. Instead, you provide the necessary information (the pattern
 *     and the filename) when you launch it. We'll learn how to process these arguments.
 * 2.  **Robust File Handling:** The program must gracefully handle errors, such as the
 *     user providing the wrong number of arguments or the specified file not existing.
 * 3.  **Efficient Line-by-Line Reading:** We will read the file one line at a time
 *     using `fgets()`. This is memory-efficient because we don't need to load the
 *     entire file into memory at once.
 * 4.  **String Searching:** For each line we read, we will use the standard library
 *     function `strstr()` to check if our search pattern exists as a substring.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Create a test file:** Before you begin, create a text file to search in.
 *     For example, save the following lines in a file named `poem.txt`:
 *
 *     The quick brown fox jumps over the lazy dog.
 *     A C program is a wonderful thing.
 *     Searching for patterns is key to many tools.
 *     The lazy dog naps in the sun.
 *
 * 2.  **Compile the code:**
 *     `gcc -Wall -Wextra -std=c11 -o my_grep 27_build_your_own_grep.c`
 *
 * 3.  **Run the executable with arguments:**
 *     The format is: `./my_grep <pattern> <filename>`
 *
 *     **Example 1: Search for the word "lazy"**
 *     `./my_grep lazy poem.txt`
 *     Expected Output:
 *     The quick brown fox jumps over the lazy dog.
 *     The lazy dog naps in the sun.
 *
 *     **Example 2: Search for the word "program"**
 *     `./my_grep program poem.txt`
 *     Expected Output:
 *     A C program is a wonderful thing.
 *
 *     **Example 3: Show error for wrong arguments**
 *     `./my_grep`
 *     Expected Output:
 *     Usage: ./my_grep <pattern> <filename>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void search_in_file(const char *pattern, const char *filename);

/**
 * @brief Main entry point. Handles command-line arguments and initiates the search.
 *
 * @param argc "Argument Count" - An integer containing the number of command-line arguments.
 *             It includes the program name itself.
 * @param argv "Argument Vector" - An array of strings. `argv[0]` is the program name,
 *             `argv[1]` is the first argument, `argv[2]` is the second, and so on.
 *
 * @return int 0 for success, 1 for error.
 */
int main(int argc, char *argv[])
{
    // A command-line utility must first validate its input.
    // We expect exactly 3 arguments:
    // argv[0]: ./my_grep (the program name)
    // argv[1]: pattern   (the string to search for)
    // argv[2]: filename  (the file to search in)
    if (argc != 3)
    {
        // If the count is wrong, print a usage message to standard error.
        // `stderr` is the appropriate place for error messages.
        fprintf(stderr, "Usage: %s <pattern> <filename>\n", argv[0]);
        // Exit with a non-zero status to indicate an error occurred.
        return EXIT_FAILURE;
    }

    // If the argument count is correct, extract the pattern and filename.
    const char *pattern = argv[1];
    const char *filename = argv[2];

    search_in_file(pattern, filename);

    return EXIT_SUCCESS; // Indicate success.
}

/**
 * @brief Opens a file and searches for a pattern line by line.
 *
 * @param pattern The substring to search for.
 * @param filename The name of the file to open and read.
 */
void search_in_file(const char *pattern, const char *filename)
{
    // Attempt to open the file in "read" mode ("r").
    FILE *file = fopen(filename, "r");

    // `fopen` returns NULL if it fails (e.g., file not found, no permissions).
    // Always check the return value of file operations.
    if (file == NULL)
    {
        // `perror` is a great function that prints a descriptive error message
        // based on the system's last error code.
        perror("Error opening file");
        // We exit here because there's nothing more to do if the file won't open.
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];

    // This is the main processing loop.
    // `fgets` reads one line from the file (or up to MAX_LINE_LENGTH-1 characters),
    // stores it in the `line` buffer, and includes the newline character `\n`.
    // It returns NULL when it reaches the end of the file (EOF) or if an error occurs.
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // `strstr(haystack, needle)` searches for the "needle" string within the "haystack" string.
        // It returns a pointer to the beginning of the found substring, or NULL if not found.
        if (strstr(line, pattern) != NULL)
        {
            // If the pattern was found, print the entire line to standard output.
            // Since `fgets` keeps the `\n`, `printf` will correctly print the line
            // and move the cursor to the next, just like the real `grep`.
            printf("%s", line);
        }
    }

    // Always close a file when you are finished with it to release system resources.
    fclose(file);
}