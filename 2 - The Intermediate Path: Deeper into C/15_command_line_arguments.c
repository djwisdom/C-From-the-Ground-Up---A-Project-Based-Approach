/**
 * @file 15_command_line_arguments.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to accept and use input provided on the command line.
 *
 * ---
 *
 * What's New in This Program?
 *
 * Until now, our `main` function has been `int main(void)`, meaning it takes no arguments.
 * However, we can change its "signature" to accept arguments directly from the user
 * when they launch the program from the terminal. This is how commands like
 * `gcc -o my_app my_app.c` work; `-o`, `my_app`, and `my_app.c` are all command-line
 * arguments passed to the `gcc` program.
 *
 * The new main function signature is: `int main(int argc, char *argv[])`
 *
 * 1.  **`int argc` (Argument Count):** An integer that stores the *number* of command-line
 *     arguments. It is always at least 1, because the name of the program itself is
 *     counted as the first argument.
 *
 * 2.  **`char *argv[]` (Argument Vector):** An array of strings (an array of character
 *     pointers). Each element of the array is one of the arguments provided on the
 *     command line.
 *     - `argv[0]` is always the name of the program's executable file.
 *     - `argv[1]` is the first actual argument the user typed.
 *     - `argv[2]` is the second, and so on.
 *
 * - *Analogy:* When you run `./my_app Alice 30`, you are placing an order.
 *   - `argc` is the total number of items on your order slip: 3.
 *   - `argv` is the list of items: `{"./my_app", "Alice", "30"}`.
 *
 * **Important:** All command-line arguments, even numbers, are passed to your program
 * as **strings**. If you need to treat "30" as a number, you must convert it.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1. Compile as usual:
 *    `gcc -Wall -Wextra -std=c11 -o cmd_args 15_command_line_arguments.c`
 *
 * 2. Run it with different arguments to see what happens!
 *
 *    - **Run with no arguments:** `./cmd_args`
 *      (Output will show argc=1 and the program name)
 *
 *    - **Run with two string arguments:** `./cmd_args hello world`
 *      (Output will show argc=3)
 *
 *    - **Run with a name to test the greeter:** `./cmd_args Alice`
 *      (Output: "Hello, Alice!")
 *
 *    - **Run with numbers to test the adder:** `./cmd_args 15 27`
 *      (Output: "The sum of 15 and 27 is 42.")
 *
 */

#include <stdio.h>
// For `atoi()`, a function that converts a string to an integer
#include <stdlib.h>

// The new main signature for accepting command-line arguments.
int main(int argc, char *argv[])
{
    // --- Part 1: Inspecting argc and argv ---
    printf("--- Part 1: Inspecting argc and argv ---\n");

    // Print the number of arguments received.
    printf("Argument count (argc): %d\n", argc);

    // Loop through the argv array and print each argument string.
    printf("Argument vector (argv) contents:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("  argv[%d] ---> \"%s\"\n", i, argv[i]);
    }

    // --- Part 2: A Practical Example - Simple Greeter ---
    printf("\n--- Part 2: Practical Greeter ---\n");

    // We check if the user provided the correct number of arguments.
    // We expect 2: the program name (argv[0]) and a user's name (argv[1]).
    if (argc == 2)
    {
        // Greet the user by using the first argument.
        printf("Hello, %s!\n", argv[1]);
    }
    else
    {
        // If the user provides too few or too many arguments, print a helpful "usage" message.
        // This is standard practice for command-line tools.
        printf("Usage for greeter: %s <your_name>\n", argv[0]);
    }

    // --- Part 3: Parsing Numbers from Arguments ---
    printf("\n--- Part 3: Simple Adder ---\n");

    // Here, we expect 3 arguments: program name, number 1, number 2.
    if (argc == 3)
    {
        // `argv[1]` and `argv[2]` are STRINGS (e.g., "15" and "27").
        // We use the `atoi` ("ASCII to integer") function to convert them to actual integers.
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);

        int sum = num1 + num2;
        printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    }
    else
    {
        printf("Usage for adder: %s <number1> <number2>\n", argv[0]);
    }

    return 0; // Signal successful execution.
}