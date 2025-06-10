/**
 * @file 14_file_io.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to read from and write to files (File Input/Output).
 *
 * ---
 *
 * What's New in This Program?
 *
 * Until now, any data our program created (like user input or calculated results)
 * disappeared the moment the program ended. To save data permanently, we need to
 * write it to a file. This process is called File Input/Output (I/O).
 *
 * C handles file operations using a special type from `<stdio.h>` called `FILE`. You
 * can't see its internal details, and you don't need to. You just need to work with
 * a pointer to it, a `FILE*`.
 *
 * - *Analogy:* Think of a `FILE*` as a remote control for a file on your disk. You
 *   don't hold the file itself in your program's memory; you hold a remote (`FILE*`)
 *   that lets you play (`read`), record (`write`), or rewind.
 *
 * Key Functions:
 *
 * 1.  **`fopen(filename, mode)`:** "File Open". You give it a filename and a "mode" to
 *     specify what you want to do. It returns a `FILE*` remote control.
 *     - `"w"` (write): Creates a new file. **Warning: If the file already exists, it will be completely erased!**
 *     - `"r"` (read): Opens an existing file for reading. Returns NULL if the file doesn't exist.
 *     - `"a"` (append): Opens an existing file to add new data to the *end* of it. If the file doesn't exist, it's created.
 *
 * 2.  **`fclose(file_pointer)`:** "File Close". This is crucial. It finalizes any writing,
 *     saves the changes to the disk, and releases the file so other programs can use it.
 *     It's the equivalent of `free()` for `fopen()`.
 *
 * 3.  **`fprintf(file_pointer, ...)`:** Works exactly like `printf`, but it sends the
 *     formatted text to the file pointed to by your `FILE*` instead of the console.
 *
 * 4.  **`fgets(buffer, size, file_pointer)`:** The safe and recommended way to read from a file
 *     line by line.
 *
 * The Golden Rule of File I/O:
 * **For every successful call to `fopen`, there must be a corresponding `fclose`.**
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o file_io 14_file_io.c`
 * `./file_io` (or `file_io.exe` on Windows)
 *
 * After running, check the directory where you ran the program. You will find a new
 * file named `my_diary.txt` containing the output!
 *
 */

#include <stdio.h>
#include <stdlib.h> // For exit()

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // A FILE pointer to be our "remote control" for the file.
    FILE *pFile = NULL;
    const char *filename = "my_diary.txt";

    // --- Part 1: Writing to a File ("w" mode) ---
    printf("--- Part 1: Writing to '%s' (erases previous content) ---\n", filename);

    // Try to open the file for writing.
    pFile = fopen(filename, "w");

    // **CRITICAL CHECK:** fopen returns NULL if it fails (e.g., disk is full, no permissions).
    if (pFile == NULL)
    {
        perror("Error opening file for writing"); // perror prints a user-friendly error message.
        return 1;                                 // Exit with an error code.
    }

    // Use fprintf to write formatted strings to the file.
    fprintf(pFile, "My C Programming Diary\n");
    fprintf(pFile, "------------------------\n");
    fprintf(pFile, "Lesson 14: Learned about file I/O.\n");
    fprintf(pFile, "It's not as hard as I thought!\n");

    // **CRITICAL STEP:** Close the file to save changes and release it.
    fclose(pFile);
    printf("Successfully wrote initial entries to the diary.\n");

    // --- Part 2: Appending to the File ("a" mode) ---
    printf("\n--- Part 2: Appending to '%s' ---\n", filename);

    // Re-open the same file, but this time in append mode.
    pFile = fopen(filename, "a");

    if (pFile == NULL)
    {
        perror("Error opening file for appending");
        return 1;
    }

    // This text will be added to the END of the file, without erasing what's there.
    fprintf(pFile, "\nLater that day...\n");
    fprintf(pFile, "I added this new line using append mode!\n");

    fclose(pFile); // Always remember to close!
    printf("Successfully appended a new entry.\n");

    // --- Part 3: Reading from the File ("r" mode) ---
    printf("\n--- Part 3: Reading from '%s' ---\n\n");

    // Open the file for reading.
    pFile = fopen(filename, "r");

    if (pFile == NULL)
    {
        perror("Error opening file for reading");
        return 1;
    }

    printf("--- FILE CONTENT ---\n");
    // Create a buffer (a character array) to hold each line as we read it.
    char line_buffer[256];

    // Loop as long as `fgets` successfully reads a line.
    // `fgets` returns NULL when it reaches the end-of-file (EOF) or if an error occurs.
    while (fgets(line_buffer, sizeof(line_buffer), pFile) != NULL)
    {
        // Print the line we just read from the file to the console.
        printf("%s", line_buffer);
    }
    printf("--- END OF FILE ---\n");

    fclose(pFile); // Close the file after we are done reading.

    return 0; // Signal successful execution.
}