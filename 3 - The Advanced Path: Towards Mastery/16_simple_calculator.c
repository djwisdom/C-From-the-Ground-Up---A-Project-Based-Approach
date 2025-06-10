/**
 * @file 16_simple_calculator.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief A project that combines previous concepts to create a command-line calculator.
 *
 * ---
 *
 * What's New in This Program?
 *
 * This is a practical project, not just a lesson. We will build a functioning
 * calculator that takes its input directly from the command line. This requires
 * us to use several skills we've developed in a coordinated way.
 *
 * Concepts We Are Combining:
 *
 * 1.  **`main(int argc, char *argv[])`:** To read the user's calculation request
 *     (e.g., `./calculator 10 + 5`).
 *
 * 2.  **Argument Validation:** Checking `argc` to ensure the user provided the
 *     correct number of inputs.
 *
 * 3.  **Type Conversion:** The numbers from `argv` are strings. We will use the
 *     `atof()` function ("ASCII to float") from `<stdlib.h>` to convert them
 *     to `double` so we can perform mathematical operations.
 *
 * 4.  **Conditional Logic:** We'll use a `switch` statement to check which
 *     operator the user entered (+, -, x, /) and perform the correct action.
 *
 * 5.  **Error Handling:** We will handle bad input, like an unknown operator or
 *     the classic error of dividing by zero.
 *
 * This project demonstrates how individual C features come together to create a
 * robust and useful application.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1. Compile as usual:
 *    `gcc -Wall -Wextra -std=c11 -o calculator 16_simple_calculator.c`
 *
 * 2. Run from the command line with three arguments: a number, an operator, and another number.
 *
 *    **Example Usage:**
 *
 *    `./calculator 27.5 + 14.5`
 *    (Expected Output: `27.50 + 14.50 = 42.00`)
 *
 *    `./calculator 100 - 55`
 *    (Expected Output: `100.00 - 55.00 = 45.00`)
 *
 *    `./calculator 10 x 5`
 *    (Expected Output: `10.00 x 5.00 = 50.00`)
 *
 *    `./calculator 42 / 7`
 *    (Expected Output: `42.00 / 7.00 = 6.00`)
 *
 *    `./calculator 10 / 0`
 *    (Expected Output: `Error: Division by zero is not allowed.`)
 *
 */

#include <stdio.h>
#include <stdlib.h> // For atof()

/**
 * @brief The main function where our program's execution begins.
 */
int main(int argc, char *argv[])
{
    // --- Step 1: Validate the number of command-line arguments ---
    // We need exactly 4 arguments:
    // argv[0]: program name (e.g., "./calculator")
    // argv[1]: first number
    // argv[2]: operator
    // argv[3]: second number
    if (argc != 4)
    {
        // If the count is wrong, print a helpful usage message and exit.
        fprintf(stderr, "Usage: %s <number1> <operator> <number2>\n", argv[0]);
        fprintf(stderr, "Operators can be: + - x /\n");
        // We use `stderr` (standard error) for error messages. It's good practice.
        return 1; // Exit with an error code.
    }

    // --- Step 2: Convert arguments and store them in variables ---
    double num1 = atof(argv[1]); // Convert the first argument string to a double
    char operator = argv[2][0];  // Get the first character of the operator string
    double num2 = atof(argv[3]); // Convert the third argument string to a double
    double result = 0.0;

    // Why argv[2][0]? `argv[2]` is a string (e.g., "+"). We only care about the
    // first character of that string. We also support 'x' for multiplication because
    // '*' is often a special character (wildcard) in command-line shells.

    // --- Step 3: Use a switch statement to perform the correct operation ---
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        break; // `break` exits the switch statement.

    case '-':
        result = num1 - num2;
        break;

    case 'x': // We use 'x' as it's easier to type on the command line than '*'.
    case '*': // But we can support '*' as well. This is a "fall-through" case.
        result = num1 * num2;
        break;

    case '/':
        // Special error case: division by zero.
        if (num2 == 0)
        {
            fprintf(stderr, "Error: Division by zero is not allowed.\n");
            return 1; // Exit with an error code.
        }
        result = num1 / num2;
        break;

    default:
        // Handle cases where the operator is not recognized.
        fprintf(stderr, "Error: Invalid operator '%c'. Please use +, -, x, or /.\n", operator);
        return 1; // Exit with an error code.
    }

    // --- Step 4: Print the result ---
    // Using %.2f to format the output nicely to two decimal places.
    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0; // Signal successful execution!
}