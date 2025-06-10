/**
 * @file my_math_helpers.c
 * @brief The implementation for the functions declared in my_math_helpers.h
 */

// We include our own header file to ensure the function definition here
// perfectly matches the prototype we declared. This is a best practice.
#include "my_math_helpers.h"

/**
 * @brief Calculates the square of an integer.
 * @param x The integer to square.
 * @return The square of x.
 */
int square(int x)
{
    return x * x;
}