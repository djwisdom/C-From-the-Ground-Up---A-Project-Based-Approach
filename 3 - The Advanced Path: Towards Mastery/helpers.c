/**
 * @file helpers.c
 * @brief Implementation file defining the shared extern variable.
 */

#include <stdio.h>
#include "helpers.h"

// Here, in ONE and ONLY ONE .c file, we provide the actual DEFINITION
// of the shared global variable. This is where memory is allocated for it.
// It is initialized to 0 by default.
int shared_counter;

// This is a global variable that is local to this file ONLY.
// The 'static' keyword on a global variable gives it "internal linkage,"
// meaning it cannot be accessed from other .c files, even with 'extern'.
// It's a way to create private global variables for a specific module.
static int private_helper_counter = 0;

/**
 * @brief Increments the shared counter and the private static counter.
 */
void increment_shared_counter(void)
{
    shared_counter++;
    private_helper_counter++;
    printf("[helpers.c] >> Incremented counters. Shared is now %d, Private is %d.\n",
           shared_counter, private_helper_counter);
}