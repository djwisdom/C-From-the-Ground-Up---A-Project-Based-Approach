/**
 * @file 18_function_pointers.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Introduces the advanced concept of pointers to functions.
 *
 * ---
 *
 * What's New in This Program?
 *
 * We know that pointers can store the memory address of a variable (`int`, `struct`, etc.).
 * A **function pointer** takes this one step further: it is a special pointer that stores
 * the memory address of a **function**.
 *
 * This means you can treat functions like data: you can store them in variables, pass
 * them as arguments to other functions, and call them dynamically.
 *
 * - *Analogy:* Imagine you have a universal remote control (`main` logic). A function
 *   pointer is like a programmable button on that remote. You can program that button
 *   to point to the "Play" function of your TV, or the "Add" function of a calculator.
 *   When you press the button, it invokes whichever function it's currently pointing to.
 *
 * The Syntax (The Tricky Part):
 *
 *   `return_type (*pointer_name)(parameter_type1, parameter_type2);`
 *
 * - `return_type`: The return type of the function the pointer can hold.
 * - `(*pointer_name)`: The name of the pointer variable, prefixed with a `*` and
 *   wrapped in parentheses. The parentheses are crucial! Without them, you would be
 *   declaring a function that returns a pointer.
 * - `(parameter_types)`: The list of parameter types the function must accept.
 *
 * Why are function pointers useful?
 * - **Callbacks:** You can pass a function (let's call it `my_callback`) as an argument
 *   to another function (e.g., `do_work`). The `do_work` function can then "call back"
 *   to `my_callback` when it's done, making the code more generic.
 * - **Dispatch Tables:** An array of function pointers can be used to replace a complex
 *   `switch` or `if-else` chain, leading to cleaner and more extensible code.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o func_ptr 18_function_pointers.c`
 * `./func_ptr` (or `func_ptr.exe` on Windows)
 *
 */

#include <stdio.h>

// --- Simple functions to which we will point ---
// Note they all have the same "signature": they take two ints and return an int.
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

// --- A function that takes a function pointer as an argument (a "callback") ---
void perform_calculation(int a, int b, int (*operation_func)(int, int))
{
    // First, check if the passed function pointer is valid (not NULL).
    if (operation_func == NULL)
    {
        printf("Error: No operation function provided.\n");
        return;
    }
    // Call the function provided by the caller and print the result.
    int result = operation_func(a, b);
    printf("  [Inside perform_calculation] The result is: %d\n", result);
}

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: Basic Declaration, Assignment, and Usage ---
    printf("--- Part 1: Basic Function Pointer Usage ---\n");

    // Declare a function pointer `p_operation`. It can point to any function
    // that takes (int, int) and returns an int.
    int (*p_operation)(int, int);

    // Assign it the address of the `add` function.
    // The `&` is optional, as a function name by itself decays into a pointer.
    p_operation = &add;

    // Call the function through the pointer.
    int sum = p_operation(10, 5);
    printf("Using pointer to 'add': 10 + 5 = %d\n", sum);

    // Now, point the SAME pointer to a different function.
    p_operation = &subtract;
    int difference = p_operation(10, 5);
    printf("Using pointer to 'subtract': 10 - 5 = %d\n", difference);

    // --- Part 2: Passing a Function Pointer as a Callback ---
    printf("\n--- Part 2: Function Pointers as Callbacks ---\n");

    int x = 20, y = 4;
    printf("Calling 'perform_calculation' with the 'add' function...\n");
    perform_calculation(x, y, &add);

    printf("Calling 'perform_calculation' with the 'multiply' function...\n");
    perform_calculation(x, y, &multiply);

    // --- Part 3: Array of Function Pointers (Dispatch Table) ---
    printf("\n--- Part 3: Array of Function Pointers ---\n");

    // Create an array that holds three function pointers.
    // This is a "dispatch table". It maps an index to an operation.
    int (*operations[3])(int, int) = {add, subtract, multiply};
    const char *op_names[] = {"Addition", "Subtraction", "Multiplication"};

    // We can now loop through the array and call each function in turn.
    // This is much cleaner than a big switch statement.
    for (int i = 0; i < 3; i++)
    {
        int result = operations[i](100, 25);
        printf("%s result: %d\n", op_names[i], result);
    }

    return 0;
}