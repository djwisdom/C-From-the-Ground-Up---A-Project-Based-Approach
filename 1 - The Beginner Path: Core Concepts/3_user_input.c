/**
 * @file 3_user_input.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Demonstrates how to make a program interactive by reading user input.
 *
 * ---
 *
 * What's New in This Program?
 *
 * So far, our programs have been static; they do the same thing every time. Now, we
 * will make our program dynamic by asking the user for information.
 *
 * We will use a new function from our `<stdio.h>` toolbox: `scanf()`.
 *
 * - `printf()` is for **output**: It sends data from your program to the console.
 * - `scanf()` is for **input**: It reads data from the console (the keyboard) and
 *   stores it in your variables.
 *
 * A very important new symbol is the ampersand `&`, the "address-of" operator.
 * When you use `scanf()`, you must tell it *where* in memory to store the data.
 * Think of it like this: to receive a package, you don't give the delivery
 * person the *contents* of your mailbox, you give them the *address* of your mailbox.
 * The `&` gives `scanf()` the memory address of your variable.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Save the Code:** Save this code as `3_user_input.c`.
 *
 * 2.  **Open Your Terminal:** Open your command-line interface.
 *
 * 3.  **Compile the Code:** Use a C compiler like GCC.
 *
 *     `gcc -Wall -Wextra -std=c11 -o user_input 3_user_input.c`
 *
 * 4.  **Run the Executable:**
 *
 *     - On Linux or macOS: `./user_input`
 *     - On Windows: `user_input.exe`
 *
 * 5.  **Interact with the program!** The program will pause and wait for you to type.
 *     Here is an example interaction:
 *
 *     Please enter your age: 30
 *     What is your favorite letter? T
 *     What is your favorite number (can have a decimal)? 7.77
 *
 *     --- Thank you! Here is the data you entered ---
 *     Your age is: 30
 *     Your favorite letter is: T
 *     Your favorite number is: 7.770000
 *
 */

// We need stdio.h for both printf (output) and scanf (input).
#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 *
 * This function will declare variables to hold user data, prompt the user
 * to enter information, and then read that information from the keyboard.
 *
 * @param void This function accepts no arguments.
 * @return int Returns 0 to indicate successful execution.
 */
int main(void)
{
    // --- Step 1: Declare Variables ---
    // We declare variables to store the user's input. Notice we don't initialize
    // them with a value, because we expect the user to provide the value.
    int user_age;
    char favorite_letter;
    double favorite_number; // Using a double is good practice for decimal numbers.

    // --- Step 2: Prompt for and Read Input ---

    // Ask for the user's age.
    printf("Please enter your age: ");
    // Use scanf to read an integer (`%d`) and store it at the address of `user_age`.
    // The program will PAUSE here until you type a number and press Enter.
    scanf("%d", &user_age);

    // Ask for the user's favorite letter.
    printf("What is your favorite letter? ");
    // ** IMPORTANT TRICK **
    // Notice the space before `%c`. When you entered your age and hit Enter, the
    // newline character `\n` was left waiting in the input stream. Without the
    // space, scanf("%c") would read that newline character instantly instead of
    // waiting for your letter. The space ` ` tells scanf to skip any leftover
    // "whitespace" (spaces, tabs, newlines) before reading the character.
    scanf(" %c", &favorite_letter);

    // Ask for the user's favorite number.
    printf("What is your favorite number (can have a decimal)? ");
    // When reading a `double` with `scanf`, you MUST use the `%lf` format specifier.
    // `l` stands for "long", so it's a "long float", which is a double.
    scanf("%lf", &favorite_number);

    // --- Step 3: Display the Stored Data ---
    // It's always a good idea to print the data back to the user to confirm
    // that the program read it correctly.
    printf("\n--- Thank you! Here is the data you entered ---\n");
    printf("Your age is: %d\n", user_age);
    printf("Your favorite letter is: %c\n", favorite_letter);
    // Note: For printf, you can use `%f` for both float and double. But for scanf,
    // you must use `%f` for float and `%lf` for double.
    printf("Your favorite number is: %f\n", favorite_number);

    return 0; // Signal successful execution.
}