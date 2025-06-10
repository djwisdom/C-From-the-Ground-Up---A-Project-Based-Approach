/**
 * @file 4_basic_operators.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief An exploration of C's basic operators.
 *
 * ---
 *
 * What's New in This Program?
 *
 * Variables are containers for data, but to do anything useful with that data, we need
 * "operators". Operators are special symbols that perform operations on variables
 * and values. This program introduces the three most common types.
 *
 * 1.  **Arithmetic Operators:** Your standard math symbols for addition (`+`),
 *     subtraction (`-`), multiplication (`*`), and division (`/`). We will also
 *     introduce a very useful new one: the modulus operator (`%`), which gives
 *     you the remainder of a division.
 *
 * 2.  **Relational Operators:** These are used to compare two values. They let you
 *     ask questions like "is this value equal to that one?" (`==`) or "is this
 *     value greater than that one?" (`>`). These operators always result in either
 *     `1` (representing true) or `0` (representing false).
 *
 * 3.  **Logical Operators:** These are used to combine the true/false results from
 *     relational operators. They allow you to check multiple conditions at once,
 *     such as "is it sunny AND is it the weekend?" (`&&`) or "is the user's
 *     choice 'A' OR 'a'?" (`||`).
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Save the Code:** Save this code as `4_basic_operators.c`.
 *
 * 2.  **Open Your Terminal:** Open your command-line interface.
 *
 * 3.  **Compile the Code:** Use a C compiler like GCC.
 *
 *     `gcc -Wall -Wextra -std=c11 -o operators 4_basic_operators.c`
 *
 * 4.  **Run the Executable:**
 *
 *     - On Linux or macOS: `./operators`
 *     - On Windows: `operators.exe`
 *
 * 5.  **Expected Output:** The program will print a series of calculations
 *     and comparisons, demonstrating what each operator does.
 *
 */

// We include stdio.h for our trusty printf function to display the results.
#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 *
 * This program will perform a series of calculations and comparisons to
 * demonstrate C's fundamental operators. It is not interactive.
 *
 * @param void This function accepts no arguments.
 * @return int Returns 0 to indicate successful execution.
 */
int main(void)
{
    // --- 1. Arithmetic Operators ---
    printf("--- 1. Arithmetic Operators ---\n");

    int a = 10;
    int b = 4;

    // The basic four: +, -, *
    printf("%d + %d = %d\n", a, b, a + b); // Addition
    printf("%d - %d = %d\n", a, b, a - b); // Subtraction
    printf("%d * %d = %d\n", a, b, a * b); // Multiplication

    // Integer Division: A common pitfall!
    // When you divide two integers, C also produces an integer result.
    // It "truncates" the result, meaning it simply cuts off the decimal part.
    // So, 10 / 4 is 2.5, but C will report it as 2.
    printf("Integer Division: %d / %d = %d\n", a, b, a / b);

    // Floating-Point Division: To get the correct decimal answer, at least one
    // of the numbers in the division must be a floating-point type (like float or double).
    // We can temporarily "cast" our integer `a` to a `double` for the calculation.
    printf("Floating-Point Division: %d / %d = %f\n", a, b, (double)a / b);

    // Modulus Operator (%): This gives you the remainder of an integer division.
    // Example: 10 divided by 4 is 2 with a remainder of 2.
    // This is incredibly useful for many tasks, like checking if a number is even or odd.
    printf("Modulus (remainder): %d %% %d = %d\n", a, b, a % b);
    // Note: To print a literal '%' character in printf, you must write '%%'.

    // --- 2. Relational Operators ---
    printf("\n--- 2. Relational Operators (1=True, 0=False) ---\n");

    int x = 5;
    int y = 5;
    int z = 10;

    // == (Is Equal To)
    // IMPORTANT: `==` is for comparison. `=` is for assignment. Mixing them up is a common bug!
    printf("Is x equal to y? (%d == %d) --> Result: %d\n", x, y, x == y);

    // != (Is Not Equal To)
    printf("Is x not equal to z? (%d != %d) --> Result: %d\n", x, z, x != z);

    // > (Greater Than) and < (Less Than)
    printf("Is z greater than x? (%d > %d) --> Result: %d\n", z, x, z > x);
    printf("Is z less than x? (%d < %d) --> Result: %d\n", z, x, z < x);

    // >= (Greater Than or Equal To) and <= (Less Than or Equal To)
    printf("Is x less than or equal to y? (%d <= %d) --> Result: %d\n", x, y, x <= y);

    // --- 3. Logical Operators ---
    printf("\n--- 3. Logical Operators (1=True, 0=False) ---\n");
    // We use integers 1 and 0 to represent true and false.
    int is_raining = 0;   // false
    int has_umbrella = 1; // true

    // && (AND): Result is true (1) only if BOTH sides are true.
    // Can I go outside without getting wet? (Is it NOT raining AND I have an umbrella?)
    // This expression is a bit silly, let's try a better one.
    // Can I stay dry? (Is it NOT raining OR do I have an umbrella?)
    // Let's re-evaluate.
    int temp_celsius = 25;
    int is_sunny = 1;

    // Do I need sunscreen? (Is the temperature warm AND is it sunny?)
    printf("Temp > 20C (%d) AND Is Sunny (%d)? Result: %d\n", temp_celsius > 20, is_sunny, (temp_celsius > 20) && is_sunny);

    // || (OR): Result is true (1) if AT LEAST ONE side is true.
    // Is it a good day? (Is it sunny OR is the temperature warm?)
    printf("Is Sunny (%d) OR Temp > 20C (%d)? Result: %d\n", is_sunny, temp_celsius > 20, is_sunny || (temp_celsius > 20));

    // ! (NOT): Inverts the value. Turns true (1) to false (0), and false (0) to true (1).
    printf("Is it NOT raining? (!%d) --> Result: %d\n", is_raining, !is_raining);

    return 0; // Signal successful execution.
}