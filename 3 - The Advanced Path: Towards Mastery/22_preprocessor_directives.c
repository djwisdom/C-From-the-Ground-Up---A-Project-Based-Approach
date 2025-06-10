/**
 * @file 22_preprocessor_directives.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Explains the C preprocessor and its most common directives.
 *
 * ---
 *
 * What's New in This Program?
 *
 * The C Preprocessor is a text-processing tool that scans your source code before
 * the actual compiler does. It modifies your code based on "directives"—lines that
 * begin with a `#` symbol. It doesn't understand C syntax; it just follows orders
 * to include files, replace text, and conditionally add or remove code blocks.
 *
 * Key Directives:
 *
 * 1.  `#include`: We've used this from day one!
 *     - `#include <...>`: For standard system libraries.
 *     - `#include "..."`: For your own custom header files (like `my_math_helpers.h`).
 *
 * 2.  `#define`: Used to create "macros".
 *     - **Object-like Macros:** Simple text replacements, often used for constants.
 *     - **Function-like Macros:** Parameterized text replacements that look like functions
 *       but can be dangerous if not written carefully!
 *
 * 3.  **Conditional Compilation (`#if`, `#ifdef`, `#endif`):** Allows you to include or
 *     exclude blocks of code from compilation. This is essential for writing code that
 *     can be configured (e.g., with a "debug mode") or for creating "include guards".
 *
 * 4.  **Predefined Macros (`__FILE__`, `__LINE__`):** Useful built-in macros that provide
 *     information about the current file and line number, perfect for debugging.
 *
 * ---
 *
 * How to Compile and Run This Multi-File Program:
 *
 * 1. Save all three files (`my_math_helpers.h`, `my_math_helpers.c`, and
 *    `22_preprocessor_directives.c`) in the same directory.
 *
 * 2. To compile, you must now tell GCC about ALL the `.c` source files:
 *
 *    `gcc -Wall -Wextra -std=c11 -o preprocessor 22_preprocessor_directives.c my_math_helpers.c`
 *
 * 3. Run the executable:
 *    `./preprocessor` (or `preprocessor.exe` on Windows)
 *
 */

#include <stdio.h>

// We include our own header file using double quotes.
#include "my_math_helpers.h"

// --- Part 1: #define for constants and function-like macros ---

// This creates an object-like macro. Before compilation, every instance of `PI`
// in this file will be literally replaced with `3.14159`.
#define PI 3.14159

// A function-like macro. Note the heavy use of parentheses!
// They are ESSENTIAL to avoid operator precedence errors.
#define SAFE_MAX(a, b) ((a) > (b) ? (a) : (b))

// An UNSAFE macro to demonstrate the danger.
#define UNSAFE_MAX(a, b) a > b ? a : b

// This defines a macro `DEBUG` but gives it no value. We can still check for its existence.
#define DEBUG

// --- Part 2: Main function demonstrating the directives ---
int main(void)
{
    printf("--- Part 1: Macros ---\n");
    printf("The value of PI is approximately: %f\n", PI);

    // Let's see why the extra parentheses in macros are so important.
    int x = 5, y = 10;
    printf("Safe max of %d and %d is: %d\n", x, y, SAFE_MAX(x, y));

    // This looks like it should be `(2+3) > 5 ? (2+3) : 5`, which is `5 > 5 ? 5 : 5`, resulting in 5.
    // BUT, because there are no parentheses, the preprocessor expands it to `2 + 3 > 5 ? 2 + 3 : 5`.
    // Operator precedence makes `3 > 5` evaluate first (false), so the expression becomes `2 + 5`, giving 7!
    printf("Unsafe max of 2+3 and 5 is: %d  <-- WRONG ANSWER!\n", UNSAFE_MAX(2 + 3, 5));

    printf("\n--- Part 2: Conditional Compilation ---\n");

    // The code inside this block will only be compiled if the `DEBUG` macro is defined.
#ifdef DEBUG
    printf("Debug mode is ON.\n");
    // Predefined macros are useful for logging and debugging messages.
    printf("This message is from file '%s' on line %d.\n", __FILE__, __LINE__);
#endif

    // This block is excluded because `RELEASE` is not defined.
#ifdef RELEASE
    printf("This will never print.\n");
#endif

    printf("\n--- Part 3: Using Our Own Header ---\n");

    // This call works because we included "my_math_helpers.h", which told the
    // compiler about the `square` function's existence (its prototype).
    // The linker will then connect this call to the compiled code from `my_math_helpers.c`.
    int num = 7;
    printf("The square of %d is %d.\n", num, square(num));

    return 0;
}