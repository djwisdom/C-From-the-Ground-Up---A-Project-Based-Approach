/**
 * @file 6_loops.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to perform repetitive tasks using loops.
 *
 * ---
 *
 * What's New in This Program?
 *
 * Imagine you needed to print "Hello!" five times. You could write `printf("Hello!\n");`
 * five times, but what if you needed to do it 100 times? Or a million? This is where
 * loops are essential. Loops allow you to execute a block of code repeatedly as
 * long as a certain condition remains true.
 *
 * C provides three kinds of loops, each suited for different situations:
 *
 * 1.  **The `for` Loop:** This is your go-to loop when you know in advance exactly
 *     how many times you want to repeat an action. It's highly structured and bundles
 *     the initialization, condition, and update steps all in one line.
 *     - *Analogy:* Following a recipe that says, "Stir exactly 10 times."
 *
 * 2.  **The `while` Loop:** This loop is ideal when you want to repeat an action as long
 *     as a condition is true, but you don't know how many repetitions it will take.
 *     The condition is checked *before* each iteration. If it's false the first
 *     time, the loop never runs.
 *     - *Analogy:* "Keep stirring *while* the soup is lumpy."
 *
 * 3.  **The `do-while` Loop:** This is a variation of the `while` loop. The key
 *     difference is that the condition is checked *after* each iteration. This
 *     guarantees that the code block inside the loop will run at least once.
 *     - *Analogy:* "Taste the soup. *Keep tasting* it while it needs more salt."
 *       You always perform the action (tasting) at least one time.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Save the Code:** Save this code as `6_loops.c`.
 *
 * 2.  **Open Your Terminal:** Open your command-line interface.
 *
 * 3.  **Compile the Code:** Use a C compiler like GCC.
 *
 *     `gcc -Wall -Wextra -std=c11 -o loops 6_loops.c`
 *
 * 4.  **Run the Executable:**
 *
 *     - On Linux or macOS: `./loops`
 *     - On Windows: `loops.exe`
 *
 * 5.  **Interact with the program!**
 *
 */

// We include stdio.h for printf and scanf.
#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 *
 * This program will demonstrate the use of for, while, and do-while loops.
 *
 * @param void This function accepts no arguments.
 * @return int Returns 0 to indicate successful execution.
 */
int main(void)
{
    // --- Part 1: The 'for' loop (Counting) ---
    printf("--- Part 1: The 'for' loop ---\n");
    printf("Let's count from 1 to 5:\n");

    // The 'for' loop has three parts inside the parentheses, separated by semicolons:
    // 1. Initialization: `int i = 1` creates a counter variable `i` and starts it at 1. This runs only once.
    // 2. Condition: `i <= 5` is checked BEFORE each loop. If it's true, the loop runs. If false, the loop stops.
    // 3. Update: `i++` increments `i` by 1 AFTER each time the loop's code block is executed.
    for (int i = 1; i <= 5; i++)
    {
        printf("  Iteration number: %d\n", i);
    }

    // --- Part 2: The 'while' loop (Countdown) ---
    printf("\n--- Part 2: The 'while' loop ---\n");
    printf("Simple rocket countdown:\n");

    // With a while loop, we must create and initialize our counter variable *before* the loop starts.
    int counter = 5;

    // The loop will only run as long as this condition is true.
    while (counter > 0)
    {
        printf("  %d...\n", counter);

        // We must manually update the counter inside the loop.
        // If you forget this line, you create an INFINITE LOOP because `counter` will always be 5!
        counter--; // This is shorthand for `counter = counter - 1;`
    }
    printf("  Blast off!\n");

    // --- Part 3: The 'do-while' loop (User Input Validation) ---
    printf("\n--- Part 3: The 'do-while' loop ---\n");

    int user_number;

    // A do-while loop is perfect for user input where you need to get at least one response.
    // The code block runs first...
    do
    {
        // Prompt the user. This part is guaranteed to run at least once.
        printf("Please enter a number between 1 and 10 (or 0 to quit): ");
        scanf("%d", &user_number);

        if (user_number > 10 || (user_number < 1 && user_number != 0))
        {
            printf("Invalid number, please try again.\n");
        }

    } while (user_number != 0); // ...then the condition is checked. If it's true, we loop again.

    printf("You entered 0. Exiting the loop. Goodbye!\n");

    return 0; // Signal successful execution.
}