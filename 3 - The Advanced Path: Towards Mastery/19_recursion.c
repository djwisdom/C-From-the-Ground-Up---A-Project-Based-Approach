/**
 * @file 19_recursion.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Introduces recursion, the concept of a function calling itself.
 *
 * ---
 *
 * What's New in This Program?
 *
 * Recursion is a problem-solving technique where a function calls itself to solve a
 * smaller version of the same problem. This continues until it reaches a simple case
 * that can be solved directly, without any further calls.
 *
 * - *Analogy:* Think of Russian Matryoshka nesting dolls. To find the innermost doll,
 *   you open the current doll (`recursive step`) to reveal a smaller, identical doll.
 *   You repeat this process until you open a doll that is solid and doesn't open
 *   any further (`base case`).
 *
 * Every recursive function MUST have two parts:
 *
 * 1.  **Base Case:** A condition that stops the recursion. It's the simplest possible
 *     version of the problem that doesn't require another recursive call. Without a
 *     base case, the function would call itself forever, leading to a "stack overflow"
 *     error as the computer runs out of memory for function calls.
 *
 * 2.  **Recursive Step:** The part of the function that calls itself, but with a
 *     modified argument that brings it one step closer to the base case.
 *
 * Pros and Cons of Recursion:
 * - **Pros:** Can lead to very elegant, clean, and easy-to-read solutions for problems
 *   that are naturally recursive (e.g., traversing tree data structures, mathematical
 *   sequences like factorial).
 * - **Cons:** Can be less efficient than an iterative (loop-based) solution due to the
 *   overhead of multiple function calls. Can also lead to stack overflow if the
 *   recursion goes too deep.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o recursion 19_recursion.c`
 * `./recursion` (or `recursion.exe` on Windows)
 *
 */

#include <stdio.h>

// --- Function Prototypes ---

// Calculates the factorial of a number using recursion.
unsigned long long factorial_recursive(int n);

// Calculates the same factorial using a standard loop for comparison.
unsigned long long factorial_iterative(int n);

// Calculates the nth Fibonacci number using recursion.
int fibonacci_recursive(int n);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    int number = 15;

    // --- Part 1: Factorial Example ---
    // The factorial of a number n (written as n!) is the product of all positive
    // integers up to n. E.g., 5! = 5 * 4 * 3 * 2 * 1 = 120.
    // This is a classic example of recursion because n! = n * (n-1)!
    printf("--- Part 1: Factorial of %d ---\n", number);

    // Using the elegant recursive solution.
    unsigned long long result_rec = factorial_recursive(number);
    printf("  Recursive result: %llu\n", result_rec); // %llu for unsigned long long

    // Using the more efficient iterative solution.
    unsigned long long result_iter = factorial_iterative(number);
    printf("  Iterative result: %llu\n", result_iter);

    // --- Part 2: Fibonacci Sequence Example ---
    // The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, ... where each number
    // is the sum of the two preceding ones.
    // This is also naturally recursive: Fib(n) = Fib(n-1) + Fib(n-2).
    printf("\n--- Part 2: The first 10 Fibonacci Numbers ---\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
    // NOTE: While elegant, the recursive Fibonacci implementation is highly INEFFICIENT
    // because it calculates the same values over and over again. An iterative solution
    // is much faster for this particular problem.

    return 0;
}

/**
 * @brief Calculates the factorial of n using recursion.
 */
unsigned long long factorial_recursive(int n)
{
    // --- Base Case ---
    // The factorial of 0 or 1 is defined as 1. This stops the recursion.
    if (n <= 1)
    {
        return 1;
    }
    // --- Recursive Step ---
    // The problem is broken down: n! is n multiplied by the factorial of (n-1).
    else
    {
        return (unsigned long long)n * factorial_recursive(n - 1);
    }
}

/**
 * @brief Calculates the factorial of n using a simple for loop (iteration).
 */
unsigned long long factorial_iterative(int n)
{
    unsigned long long result = 1;
    // Loop from n down to 2, multiplying the result each time.
    for (int i = n; i > 1; i--)
    {
        result *= i;
    }
    return result;
}

/**
 * @brief Calculates the nth Fibonacci number using recursion.
 */
int fibonacci_recursive(int n)
{
    // --- Base Case 1 ---
    if (n <= 0)
    {
        return 0;
    }
    // --- Base Case 2 ---
    if (n == 1)
    {
        return 1;
    }
    // --- Recursive Step ---
    // The definition of the sequence.
    else
    {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}