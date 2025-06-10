/**
 * @file 9_strings.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Explains how to work with strings, which are arrays of characters in C.
 *
 * ---
 *
 * What's New in This Program?
 *
 * Many programming languages have a special "string" type for working with text. C does
 * not. In C, a string is simply an array of characters (`char`). However, there is one
 * critical rule: a C string must always end with a special character called the
 * **null terminator**, which is written as `\0`.
 *
 * - *Analogy:* Think of a sentence. The null terminator `\0` is the full stop (period)
 *   at the end. It doesn't count as a letter of the sentence, but it's essential
 *   because it tells you where the sentence ends. Functions like `printf` read the
 *   characters one by one until they find this `\0`.
 *
 * Key Concepts:
 *
 * 1.  **String Declaration:** You can declare strings using double quotes `""`, and the
 *     compiler will automatically add the `\0` for you. `char my_name[] = "Bob";`
 *     actually creates an array of 4 characters: `{'B', 'o', 'b', '\0'}`.
 *
 * 2.  **The `%s` Format Specifier:** Used with `printf` to print a string. `printf`
 *     will start printing from the beginning of the character array until it hits the
 *     null terminator.
 *
 * 3.  **The `<string.h>` Library:** Since strings are so common, C provides a standard
 *     "toolbox" of functions for manipulating them. We'll introduce some of the most
 *     important ones like `strlen`, `strcpy`, `strcat`, and `strcmp`.
 *
 * 4.  **Reading Strings:** `scanf` has major limitations for reading strings (it stops
 *     at spaces). We will learn a much safer and more robust function, `fgets`, for
 *     reading a whole line of text from the user.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o strings 9_strings.c`
 * `./strings` (or `strings.exe` on Windows)
 *
 */

#include <stdio.h>
// We must include the string library to use functions like strlen(), strcpy(), etc.
#include <string.h>

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: Declaring and Printing Strings ---
    printf("--- Part 1: String Declaration ---\n");

    // The easy way: use double quotes. The compiler adds the `\0` terminator automatically.
    // "Alice" is 5 characters, but this array has a size of 6 to hold 'A','l','i','c','e','\0'.
    char name[] = "Alice";
    printf("Hello, %s!\n", name);

    // The manual way: This shows what's happening behind the scenes.
    // Notice we have to add the null terminator ourselves!
    char title[] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'e', 'r', '\0'};
    printf("Your title is: %s\n", title);

    // --- Part 2: Using the <string.h> Library ---
    printf("\n--- Part 2: String Library Functions ---\n");

    // `strlen()` - String Length
    // It counts the characters *before* the null terminator.
    printf("The name '%s' has %zu characters.\n", name, strlen(name));
    // Note: strlen returns a special unsigned type `size_t`. We use the `%zu` format specifier to print it.

    // `strcpy()` - String Copy
    // You CANNOT copy strings using `=`. `char new_name = name;` is an error.
    // You must copy the characters from the source array to the destination array.
    char name_copy[20]; // The destination must be large enough to hold the source!
    strcpy(name_copy, name);
    printf("We made a copy of the name: %s\n", name_copy);
    // **WARNING:** `strcpy` is unsafe! If the destination isn't big enough, it can crash your program.

    // `strcat()` - String Concatenation (Joining)
    char greeting[50] = "Good morning, "; // Destination must have space for the new part.
    strcat(greeting, name);               // Appends the `name` string to the end of `greeting`.
    printf("Concatenated string: %s\n", greeting);

    // `strcmp()` - String Comparison
    // You CANNOT compare strings with `==`. `name == name_copy` checks if they are the *exact same array*, not if they have the same content.
    // `strcmp` compares them alphabetically. It returns:
    //  - 0 if they are identical.
    //  - A negative number if string 1 comes before string 2 alphabetically.
    //  - A positive number if string 1 comes after string 2 alphabetically.
    printf("Comparing 'Apple' and 'Apple': %d\n", strcmp("Apple", "Apple"));
    printf("Comparing 'Apple' and 'Banana': %d\n", strcmp("Apple", "Banana"));
    printf("Comparing 'Banana' and 'Apple': %d\n", strcmp("Banana", "Apple"));

    // --- Part 3: Getting String Input from the User ---
    printf("\n--- Part 3: Reading a Line of Text ---\n");

    char full_name[100]; // Create a "buffer" to hold the user's input.

    printf("Please enter your full name: ");

    // `fgets` is the safe way to read a string.
    // It takes 3 arguments: the buffer, the max size to read, and the input source (`stdin` is the keyboard).
    // It stops reading when it hits a newline (Enter key) or reaches the size limit.
    fgets(full_name, 100, stdin);

    // **IMPORTANT:** `fgets` includes the newline character (`\n`) in the string. We usually want to remove it.
    // This line finds the first occurrence of `\n` and replaces it with a null terminator `\0`.
    full_name[strcspn(full_name, "\n")] = '\0';

    printf("Hello, %s! Nice to meet you.\n", full_name);

    return 0; // Signal successful execution.
}