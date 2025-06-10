/**
 * @file 2_variables_and_data_types.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief An introduction to variables and fundamental data types in C.
 *
 * ---
 *
 * What's New in This Program?
 *
 * In our first program, we printed a fixed string. Now, we'll learn to store and
 * manage data using "variables".
 *
 * A variable is like a labeled box in the computer's memory where you can store a
 * piece of information. You give it a name (an identifier) and tell C what "type"
 * of data it will hold. This is crucial because C needs to know how much memory
 * to reserve for the box and what kind of value to expect (a whole number, a
 * decimal number, a single character, etc.).
 *
 * This program will demonstrate four basic data types:
 * - `int`: For whole numbers (integers).
 * - `float` / `double`: For numbers with decimal points.
 * - `char`: For single characters.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Save the Code:** Save this code as `2_variables_and_data_types.c`.
 *
 * 2.  **Open Your Terminal:** Open your command-line interface.
 *
 * 3.  **Compile the Code:** Use a C compiler like GCC.
 *
 *     `gcc -Wall -Wextra -std=c11 -o variables 2_variables_and_data_types.c`
 *
 *     - We've chosen `variables` as the name for our output executable file (`-o variables`).
 *
 * 4.  **Run the Executable:**
 *
 *     - On Linux or macOS: `./variables`
 *     - On Windows: `variables.exe` or `variables`
 *
 * 5.  **Expected Output:**
 *
 *     --- Variable Examples ---
 *     I am 35 years old.
 *     The letter grade is: A
 *     The price of the item is: 19.99
 *     A more precise PI is: 3.141593
 *     --- Values Can Change ---
 *     One year has passed. Now I am 36 years old.
 *
 */

// We still need this library for our `printf` function. It's fundamental
// for almost any program that needs to display output.
#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 *
 * This function will declare variables, assign them values, and then print
 * those values to the console to show how they work.
 *
 * @param void This function accepts no arguments.
 * @return int Returns 0 to indicate successful execution.
 */
int main(void)
{
    printf("--- Variable Examples ---\n");

    // --- Integer (int) ---
    // An 'int' is used to store whole numbers (e.g., -5, 0, 100).
    // Here, we declare a variable named `age` of type `int` and "initialize" it
    // with the value 35. The `=` is the assignment operator.
    int age = 35;

    // Now we print it. Notice the `%d` inside the string. This is a "format specifier".
    // It acts as a placeholder for an integer. The `printf` function replaces `%d`
    // with the value of the `age` variable we provide after the comma.
    printf("I am %d years old.\n", age);

    // --- Character (char) ---
    // A 'char' stores a single character (like 'a', 'Z', or '?').
    // Note that we use single quotes `' '` for a single character.
    char grade = 'A';

    // The format specifier for a character is `%c`.
    printf("The letter grade is: %c\n", grade);

    // --- Floating-Point (float and double) ---
    // These types store numbers with decimal points. 'float' is for standard
    // precision, while 'double' is for "double precision", allowing more decimal places.
    // It's good practice to use 'double' for floating-point math unless you have a
    // specific reason (like memory constraints) to use 'float'.

    // When writing a float constant, it's good practice to add an 'f' at the end.
    float price = 19.99f;

    // The format specifier for a float or double is `%f`.
    // By default, it often prints with 6 decimal places.
    printf("The price of the item is: %f\n", price);

    // Let's use a double for more precision.
    double pi = 3.14159265;
    printf("A more precise PI is: %f\n", pi);

    // --- Variables Can Be Changed (they are "mutable") ---
    printf("--- Values Can Change ---\n");
    // The value stored in a variable is not permanent. You can update it.
    // Here, we take our existing `age` variable and assign it a new value.
    age = 36; // We don't need to write `int` again, as the variable is already declared.

    printf("One year has passed. Now I am %d years old.\n", age);

    // Signal to the operating system that the program completed successfully.
    return 0;
}