/**
 * @file 10_pointers.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief An introduction to pointers, one of C's most powerful and unique features.
 *
 * ---
 *
 * What's New in This Program?
 *
 * Welcome to pointers! This is a foundational concept in C that allows for powerful
 * and efficient memory management.
 *
 * Up until now, a variable has been like a box holding a value. A **pointer** is a
 * special kind of variable that doesn't hold a value directly; instead, it holds the
 * **memory address** of another variable.
 *
 * - *Analogy:* Imagine a variable `age` is a house. The value `30` is the family
 *   living inside the house. A pointer is a piece of paper where you have written
 *   down the *street address* of that house. With the address, you can find the house
 *   and see who lives inside. You can even use the address to move a new family in!
 *
 * Two New Operators are Key:
 *
 * 1.  **The Address-Of Operator (`&`):** When you put `&` in front of a variable
 *     name, it gives you that variable's memory address.
 *     - `&age` means "Give me the address of the `age` variable."
 *
 * 2.  **The Dereference Operator (`*`):** This operator has two roles.
 *     a) In a declaration (`int *p_age;`), the `*` tells the compiler that `p_age` is
 *        a pointer variable.
 *     b) In use (`*p_age`), it means "go to the address stored in this pointer and get
 *        the value from that location." This is called "dereferencing".
 *
 * Why are pointers so important? They are essential for dynamic memory allocation,
 * building complex data structures (like linked lists), and allowing functions to
 * modify their arguments efficiently.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o pointers 10_pointers.c`
 * `./pointers` (or `pointers.exe` on Windows)
 *
 */

#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: The Basics - Getting the Address of a Variable ---
    printf("--- Part 1: Addresses and Values ---\n");

    int age = 30; // Our "house" with the value 30 inside.

    // Let's print the value and the memory address.
    // The `%p` format specifier is used to print pointer addresses in hexadecimal format.
    printf("The variable 'age' has the value: %d\n", age);
    printf("The variable 'age' is stored at memory address: %p\n", &age);

    // --- Part 2: Declaring and Using a Pointer ---
    printf("\n--- Part 2: Using a Pointer ---\n");

    // Declaration: `int *p_age;` means "`p_age` is a pointer that can hold the address of an `int`".
    // It's good practice to initialize pointers to NULL. NULL is a special value
    // that means "this pointer doesn't point to anything".
    int *p_age = NULL;

    // Assignment: We store the address of `age` in our pointer variable.
    // Now, `p_age` holds the address of `age`. It "points to" age.
    p_age = &age;

    printf("The pointer `p_age` holds the address: %p\n", p_age);

    // Dereferencing: To get the value AT the address the pointer holds, we use `*`.
    // `*p_age` means "go to the address stored in p_age and get the value".
    printf("The value at the address `p_age` points to is: %d\n", *p_age);

    // --- Part 3: Modifying Data Through a Pointer ---
    printf("\n--- Part 3: Modifying Data via Pointer ---\n");

    printf("Original value of 'age': %d\n", age);

    // We can use the dereferenced pointer on the left side of an assignment
    // to change the value of the original variable it points to.
    *p_age = 31; // This means "Go to the house at this address and move the value 31 in."

    printf("We changed the value using the pointer!\n");
    printf("New value of 'age': %d\n", age); // The original variable is changed!

    // --- Part 4: The Importance of NULL ---
    printf("\n--- Part 4: The NULL Pointer ---\n");

    // A pointer that doesn't point to a valid memory location is dangerous.
    // Trying to dereference a NULL pointer will crash your program.
    int *dangerous_pointer = NULL;

    // It's crucial to check if a pointer is NULL before you try to use it.
    if (dangerous_pointer == NULL)
    {
        printf("The dangerous_pointer is NULL. It's unsafe to use it!\n");
    }
    else
    {
        // This code will not run, preventing a crash.
        printf("Value from dangerous_pointer: %d\n", *dangerous_pointer);
    }

    // Pointers are a huge topic, but understanding `&` and `*` is the perfect start!

    return 0; // Signal successful execution.
}