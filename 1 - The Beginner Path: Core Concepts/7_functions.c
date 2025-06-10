/**
 * @file 7_functions.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to organize code into reusable blocks called functions.
 *
 * ---
 *
 * What's New in This Program?
 *
 * As programs grow, putting all your code inside the `main` function becomes messy
 * and hard to manage. "Functions" are the solution. A function is a named,
 * self-contained block of code that performs a specific task.
 *
 * Think of `main` as the manager of a project. The manager shouldn't do all the
 * work themselves. Instead, they delegate tasks to specialists. Functions are those
 * specialists.
 *
 * Key Concepts:
 *
 * 1.  **Function Prototype (or Declaration):** This is a forward-declaration at the
 *     top of the file. It tells the compiler what a function is called, what kind of
 *     data it returns, and what arguments it expects. It's like a table of contents
 *     that lets `main` know which functions are available to be called.
 *
 * 2.  **Function Definition:** This is the actual implementation of the function—the
 *     code that performs the task. This is where the specialist's instructions live.
 *
 * 3.  **Function Call:** This is the act of "invoking" or "running" a function from
 *     `main` or from another function. This is the manager delegating the task.
 *
 * Why use functions?
 * - **Organization:** Keeps `main` clean and easy to read.
 * - **Reusability:** Write a task once and call it many times. No more copy-pasting!
 * - **Abstraction:** You can use a function without needing to know the complex details of *how* it works.
 * - **Easier Debugging:** When something goes wrong, you can often isolate the problem to a specific function.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o functions 7_functions.c`
 * `./functions` (or `functions.exe` on Windows)
 *
 */

// We still need stdio.h for I/O, which our functions will use.
#include <stdio.h>

// --- 1. Function Prototypes ---
// Here we declare the functions we are going to define later.
// The compiler now knows they exist before it even sees the `main` function.

// A function that takes no arguments (void) and returns no value (void).
void print_separator_line(void);

// A function that takes two integers as input and returns their sum as an integer.
int add_two_numbers(int num1, int num2);

// A function that takes an integer, but returns no value.
void print_user_age(int age);

// --- 2. The `main` function (The "Manager") ---
/**
 * @brief The main entry point. Its job is to call other functions to get the work done.
 */
int main(void)
{
    // Our main function is now clean and high-level. It's easy to read what our program does.

    // Call the function to print a decorative line.
    print_separator_line();
    printf("Welcome to the Functions Program!\n");
    print_separator_line();

    // Declare variables to hold our data.
    int value1 = 15;
    int value2 = 7;
    int my_age = 30;

    // Call the 'add_two_numbers' function, passing `value1` and `value2` as "arguments".
    // The value that the function `returns` is then stored in our `sum` variable.
    int sum = add_two_numbers(value1, value2);

    printf("The sum of %d and %d is: %d\n", value1, value2, sum);

    // Let's reuse the function with different arguments!
    int another_sum = add_two_numbers(100, 50);
    printf("Another sum is: %d\n", another_sum);

    // Call a function that just performs an action but doesn't return a value.
    print_user_age(my_age);

    print_separator_line();

    return 0; // The manager reports that the job was completed successfully.
}

// --- 3. Function Definitions (The "Specialists") ---

/**
 * @brief Prints a simple line of asterisks to the console.
 *
 * This is an example of a simple function that neither takes input nor returns
 * a value. Its only job is to perform an action.
 *
 * @param void It accepts no arguments.
 */
void print_separator_line(void)
{
    printf("***********************************\n");
}

/**
 * @brief Adds two integers together.
 *
 * This function takes two integer "parameters" (num1 and num2) and calculates
 * their sum. It then uses the `return` keyword to send the result back to
ator
 * whoever called it.
 *
 * @param num1 The first integer.
 * @param num2 The second integer.
 * @return int The sum of num1 and num2.
 */
int add_two_numbers(int num1, int num2)
{
    int result = num1 + num2;
    return result; // Send the calculated value back.
}

/**
 * @brief Prints a formatted string including the user's age.
 *
 * This demonstrates a function that accepts data but does not return
 * any new data.
 *
 * @param age The age to be printed.
 */
void print_user_age(int age)
{
    printf("A person in this program is %d years old.\n", age);
}