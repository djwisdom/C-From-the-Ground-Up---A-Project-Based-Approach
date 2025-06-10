/**
 * @file 5_conditional_statements.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to control the flow of a program with decision-making.
 *
 * ---
 *
 * What's New in This Program?
 *
 * This program introduces "conditional statements." These are the building blocks of
 * decision-making in C. They allow your program to take different paths based on
 * whether a certain condition is true or false. Think of it as a fork in the road for
 * your code.
 *
 * We will use the relational and logical operators we learned in the previous lesson
 * to build these conditions.
 *
 * 1.  **`if` Statement:** This is the most basic decision. It says, "IF this
 *     condition is true, then execute the block of code inside the curly braces `{}`."
 *     If the condition is false, the code block is skipped entirely.
 *
 * 2.  **`else` Statement:** This is the "otherwise" part of a decision. It must
 *     follow an `if` statement. It says, "IF the first condition was false, then
 *     execute THIS block of code instead."
 *
 * 3.  **`else if` Statement:** This lets you chain multiple conditions together.
 *     It says, "IF the first condition was false, THEN let's check this new
 *     condition." You can have many `else if` statements in a row to check for
 *     multiple different possibilities.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1.  **Save the Code:** Save this code as `5_conditional_statements.c`.
 *
 * 2.  **Open Your Terminal:** Open your command-line interface.
 *
 * 3.  **Compile the Code:** Use a C compiler like GCC.
 *
 *     `gcc -Wall -Wextra -std=c11 -o conditionals 5_conditional_statements.c`
 *
 * 4.  **Run the Executable:**
 *
 *     - On Linux or macOS: `./conditionals`
 *     - On Windows: `conditionals.exe`
 *
 * 5.  **Interact with the program!** Here is an example interaction:
 *
 *     --- Part 1: Simple 'if-else' ---
 *     Please enter your age: 25
 *     You are eligible to vote.
 *
 *     --- Part 2: The 'if-else if-else' Chain ---
 *     Please enter your test score (0-100): 88
 *     Your grade is: B
 *
 */

// We include stdio.h for printf and scanf.
#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 *
 * This program demonstrates decision-making by asking the user for their
 * age and a test score and providing feedback based on those values.
 *
 * @param void This function accepts no arguments.
 * @return int Returns 0 to indicate successful execution.
 */
int main(void)
{
    // --- Part 1: A simple 'if-else' statement ---
    printf("--- Part 1: Simple 'if-else' ---\n");

    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);

    // This is the condition. We use the 'greater than or equal to' operator.
    // If the expression `age >= 18` evaluates to true (1), the code inside the
    // first set of `{}` is executed.
    if (age >= 18)
    {
        printf("You are eligible to vote.\n");
    }
    // If the condition `age >= 18` was false (0), the program skips the 'if' block
    // and executes the 'else' block instead.
    else
    {
        printf("You are not yet eligible to vote.\n");
    }

    // --- Part 2: The 'if-else if-else' Chain ---
    printf("\n--- Part 2: The 'if-else if-else' Chain ---\n");

    int score;
    printf("Please enter your test score (0-100): ");
    scanf("%d", &score);

    // The program checks these conditions in order from top to bottom.
    // As soon as it finds one that is true, it runs that block of code
    // and then skips the rest of the entire chain.

    // 1. First, check if the score is 90 or higher.
    if (score >= 90)
    {
        printf("Your grade is: A\n");
    }
    // 2. If not, THEN check if it's 80 or higher.
    else if (score >= 80)
    {
        printf("Your grade is: B\n");
    }
    // 3. If not, THEN check if it's 70 or higher.
    else if (score >= 70)
    {
        printf("Your grade is: C\n");
    }
    // 4. If not, THEN check if it's 60 or higher.
    else if (score >= 60)
    {
        printf("Your grade is: D\n");
    }
    // 5. If NONE of the above conditions were true, the final 'else' block runs.
    //    This is the "catch-all" or default case.
    else
    {
        printf("Your grade is: F\n");
    }

    // --- A note on good practice ---
    // Even if you don't need an 'else' case, it's often wise to have one to
    // handle unexpected values, like if the user entered 110 for the score.
    // We could make the code more robust like this:
    if (score > 100 || score < 0)
    {
        printf("Invalid score entered. Please enter a value between 0 and 100.\n");
    }

    return 0; // Signal successful execution.
}