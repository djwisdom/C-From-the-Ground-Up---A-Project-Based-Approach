/**
 * @file 1_hello_world.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief The traditional first program for learning a new language: "Hello, World!"
 *
 * ---
 *
 * Welcome to C Programming!
 *
 * This program is the simplest complete application you can write in C. Its only job
 * is to display the message "Hello, World!" on your screen. We start here because it
 * introduces the most basic building blocks of a C program without being overwhelming.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Save the Code:** Make sure this code is saved in a file named `1_hello_world.c`.
 *
 * 2.  **Open Your Terminal:** This is your command-line interface (like Terminal on macOS/Linux, or Command Prompt/PowerShell on Windows).
 *
 * 3.  **Navigate to the File:** Use the `cd` (change directory) command to go to the folder where you saved this file.
 *
 * 4.  **Compile the Code:** Use a C compiler, like GCC, to turn this human-readable source code into a machine-executable program.
 *
 *     `gcc -Wall -Wextra -std=c11 -o hello_world 1_hello_world.c`
 *
 *     Let's break down that command:
 *     - `gcc`: The name of the compiler program.
 *     - `-Wall -Wextra`: These are flags that tell the compiler to warn you about all potential problems. This is a very good habit!
 *     - `-std=c11`: This specifies that we are using the 2011 standard of the C language.
 *     - `-o hello_world`: This tells the compiler to name the final executable file `hello_world`.
 *     - `1_hello_world.c`: This is the name of the source code file you are compiling.
 *
 * 5.  **Run the Executable:**
 *
 *     - On Linux or macOS: `./hello_world`
 *     - On Windows: `hello_world.exe` or just `hello_world`
 *
 * 6.  **You should see the following output on your screen:**
 *
 *     Hello, World!
 *
 */

// This line is a "preprocessor directive". It runs before the main compilation begins.
// `#include <stdio.h>` tells the compiler to include the "Standard Input/Output" library.
// Think of it like grabbing the right toolbox. This specific toolbox (`stdio.h`)
// contains pre-written code for input/output functions, including `printf`.
#include <stdio.h>

/**
 * @brief This is the `main` function, where every C program begins execution.
 *
 * When you run your compiled program, the operating system looks for this specific
 * function and starts running the code inside its curly braces `{}`.
 *
 * @param void The keyword `void` here explicitly means that this function accepts
 *             no arguments or parameters.
 *
 * @return int The `int` before `main` declares that this function will return an
 *             integer value when it finishes. This integer is an "exit code" that
 *             tells the operating system how the program ended.
 */
int main(void)
{
    // This line calls the `printf` function to print text to the standard output (your terminal).
    // - `printf`: Short for "print formatted". It's a versatile function for displaying text.
    // - `"Hello, World!\n"`: This is the "string literal" we want to print. It is the argument passed to the function.
    // - `\n`: This is a special "escape sequence" that represents a newline character.
    //   It's an instruction to move the cursor to the start of the next line. Without it,
    //   your command prompt would appear immediately after "Hello, World!".
    printf("Hello, World!\n");

    // This line ends the `main` function and returns the integer `0` to the operating system.
    // By convention, returning `0` signals that the program ran successfully without errors.
    // Think of it as giving a "thumbs-up" to the system. A non-zero return value (like `1`)
    // would signal that something went wrong. This is a critical feature for scripting and automation.
    return 0;
}