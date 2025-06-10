/**
 * @file 24_static_and_extern_variables.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Explains storage classes, focusing on `static` and `extern`.
 *
 * ---
 *
 * What's New in This Program?
 *
 * A variable's "storage class" determines its visibility (scope) and its lifetime.
 * We've mostly used `auto` variables (regular local variables) so far. Now we
 * explore the powerful `static` and `extern` keywords.
 *
 * 1.  **`static` (The "Private" and "Persistent" Keyword):**
 *
 *     - **Inside a function:** When you declare a local variable as `static`, it is
 *       no longer temporary. It's stored in a special memory segment and **retains
 *       its value between function calls**. Its scope is still limited to the
 *       function, but its lifetime is the entire duration of the program.
 *
 *     - **Outside a function (global scope):** When you declare a global variable or
 *       function as `static`, it gets **internal linkage**. This means it is only
 *       visible within the `.c` file where it is defined. It's a way to create
 *       private helper variables/functions for a specific "module."
 *
 * 2.  **`extern` (The "Shared" or "External" Keyword):**
 *
 *     The `extern` keyword is used to **declare** a global variable that is
 *     **defined** in another source file. It tells the compiler, "Don't allocate
 *     memory for this. Just know that it exists somewhere else, and the linker
 *     will connect everything for us later." This is how you share global
 *     variables across a multi-file project.
 *
 * ---
 *
 * How to Compile and Run This Multi-File Program:
 *
 * 1. Save all three files (`helpers.h`, `helpers.c`, and
 *    `24_static_and_extern_variables.c`) in the same directory.
 *
 * 2. You must provide all `.c` source files to the compiler:
 *
 *    `gcc -Wall -Wextra -std=c11 -o storage 24_static_and_extern_variables.c helpers.c`
 *
 * 3. Run the executable:
 *    `./storage` (or `storage.exe` on Windows)
 *
 */

#include <stdio.h>
#include "helpers.h" // Include our custom header to get the declarations.

// --- Function Prototypes for functions in this file ---
void regular_local_counter(void);
void static_local_counter(void);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: `static` inside a function (Persistent Value) ---
    printf("--- Part 1: Local variable persistence ---\n");

    printf("Calling regular counter:\n");
    regular_local_counter(); // count will be 1
    regular_local_counter(); // count will be 1 again (it's re-created each time)

    printf("\nCalling static counter:\n");
    static_local_counter(); // static_count will be 1
    static_local_counter(); // static_count will be 2 (it remembers its value!)
    static_local_counter(); // static_count will be 3

    // --- Part 2: `extern` for sharing across files ---
    printf("\n--- Part 2: Sharing variables with 'extern' ---\n");

    // We can directly access `shared_counter` because we included `helpers.h`
    // which declared `extern int shared_counter;`
    printf("Initial value of shared_counter in main: %d\n", shared_counter);

    shared_counter = 100;
    printf("Set shared_counter to 100 in main.\n");

    // Now call the function from the other file. It will modify the SAME variable.
    increment_shared_counter();

    // Check the value back in main. It has been changed by the external function.
    printf("Value of shared_counter back in main: %d\n", shared_counter);

    // --- Part 3: `static` at the global level (Internal Linkage) ---
    printf("\n--- Part 3: File-scope static variables ---\n");
    printf("Trying to access 'private_helper_counter' will cause a compile/link error.\n");
    // Uncommenting the line below would cause a linker error like "undefined reference to `private_helper_counter`"
    // because that variable is `static` in `helpers.c` and thus invisible to this file.
    // printf("%d", private_helper_counter);
    printf("We can only see its effects through the public function that can access it.\n");
    increment_shared_counter(); // This will increment both the shared and the private counter.

    return 0;
}

/**
 * @brief Demonstrates a regular 'auto' local variable.
 * This variable is created and destroyed every time the function is called.
 */
void regular_local_counter(void)
{
    int count = 0; // This is an 'auto' variable by default.
    count++;
    printf("  'count' is now %d\n", count);
}

/**
 * @brief Demonstrates a `static` local variable.
 * This variable is initialized only once and retains its value across calls.
 */
void static_local_counter(void)
{
    // `static` means this variable is initialized to 0 only the FIRST time
    // this function is ever called. On subsequent calls, this line is effectively skipped.
    static int static_count = 0;
    static_count++;
    printf("  'static_count' is now %d\n", static_count);
}