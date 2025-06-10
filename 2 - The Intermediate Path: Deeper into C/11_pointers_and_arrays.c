/**
 * @file 11_pointers_and_arrays.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Explores the fundamental relationship between pointers and arrays in C.
 *
 * ---
 *
 * What's New in This Program?
 *
 * In C, there is an inseparable link between pointers and arrays. The name of an
 * array, by itself, acts as a **pointer constant** to the array's very first element.
 * This is a critical concept.
 *
 * - *Analogy:* If an array is a row of houses, the array's name (`my_array`) is like
 *   a permanent, unchangeable signpost planted in front of the first house, pointing
 *   at it. You can't move the signpost, but you can read it to find where the row begins.
 *
 * Key Concepts:
 *
 * 1.  **Array Name is an Address:** The expression `my_array` evaluates to the memory
 *     address of `my_array[0]`. Therefore, `my_array` and `&my_array[0]` are equivalent.
 *
 * 2.  **Pointer Arithmetic:** When you add a number to a pointer, you aren't just adding
 *     to the memory address. The compiler is smart and adds `n * sizeof(the_type)`.
 *     So, `my_pointer + 1` correctly moves the pointer to the **next element** in the
 *     array, regardless of whether that element is a 1-byte `char` or a 4-byte `int`.
 *
 * 3.  **The Equivalence of `[]` and `*()`:** The square bracket notation we've been
 *     using is actually "syntactic sugar" (a convenient alternative syntax) for
 *     pointer arithmetic. The compiler treats them the same way:
 *     - `my_array[i]` is exactly equivalent to `*(my_array + i)`.
 *
 * 4.  **Passing Arrays to Functions:** When you pass an array as an argument to a
 *     function, you are NOT passing a copy of the entire array. You are only passing
 *     a pointer (the address of the first element). This is extremely efficient but also
 *     means the function can modify the original array's contents!
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o ptr_arrays 11_pointers_and_arrays.c`
 * `./ptr_arrays` (or `ptr_arrays.exe` on Windows)
 *
 */

#include <stdio.h>

// --- Function Prototype ---
// When we declare a function that takes an array, we can write it in two equivalent ways:
// 1. As a pointer: `void print_array(int *arr, int size)`
// 2. With array brackets: `void print_array(int arr[], int size)`
// Both mean the same thing: "This function accepts a pointer to an integer".
// Using the pointer syntax is often clearer about what's actually happening.
void print_array(int *arr, int size);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    int scores[] = {90, 85, 97, 100, 78};
    int size = sizeof(scores) / sizeof(scores[0]);

    // --- Part 1: The Array Name is a Pointer ---
    printf("--- Part 1: Array Name as a Pointer ---\n");

    // The name 'scores' itself evaluates to an address.
    // The address-of operator on the first element `&scores[0]` gives the same address.
    printf("Address from array name 'scores':     %p\n", scores);
    printf("Address of first element '&scores[0]': %p\n", &scores[0]);

    // We can create a pointer and assign it the address of the array.
    int *p_scores = scores; // No `&` is needed, because `scores` is already an address!
    printf("Address stored in `p_scores`:         %p\n", p_scores);

    // --- Part 2: Accessing Elements with Pointers ---
    printf("\n--- Part 2: Accessing Elements ---\n");

    // We can use standard array notation and pointer notation interchangeably.
    printf("Accessing the first element:\n");
    printf("  Using array notation scores[0]:   %d\n", scores[0]);
    printf("  Using pointer notation *p_scores: %d\n", *p_scores);

    printf("Accessing the third element (index 2):\n");
    printf("  Using array notation scores[2]:     %d\n", scores[2]);
    // `*(p_scores + 2)` means: "start at the address in p_scores, move forward 2 elements, then dereference".
    printf("  Using pointer notation *(p_scores + 2): %d\n", *(p_scores + 2));

    // --- Part 3: Iterating with a Pointer ---
    printf("\n--- Part 3: Iterating with a Pointer ---\n");

    // Let's print the array using a pointer in a for loop.
    printf("Printing all scores using a pointer:\n");
    for (int i = 0; i < size; i++)
    {
        // On each iteration, we add 'i' to the base address and get the value.
        printf("  Element %d is %d\n", i, *(p_scores + i));
    }

    // --- Part 4: Passing an Array to a Function ---
    printf("\n--- Part 4: Passing to a Function ---\n");
    printf("Calling a function to print the array...\n");

    // We pass `scores` (which is just the address) and the size to our function.
    // The function receives a POINTER to the original `scores` array.
    print_array(scores, size);
    printf("...function has finished.\n");

    return 0;
}

/**
 * @brief Prints the elements of an integer array.
 *
 * @param arr A pointer to the first element of the array.
 * @param size The number of elements in the array.
 */
void print_array(int *arr, int size)
{
    printf("  [Inside the function] Printing array contents:\n");
    for (int i = 0; i < size; i++)
    {
        // Even though `arr` is a pointer, we can still use the convenient
        // square bracket notation on it! `arr[i]` is the same as `*(arr + i)`.
        printf("    Element %d: %d\n", i, arr[i]);
    }
    // Since `arr` points to the original array, if we changed a value here,
    // e.g., `arr[0] = 50;`, it would change the `scores` array back in `main`.
}