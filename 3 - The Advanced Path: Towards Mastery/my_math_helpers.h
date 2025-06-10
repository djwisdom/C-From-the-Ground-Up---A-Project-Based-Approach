/**
 * @file my_math_helpers.h
 * @brief A header file with a math helper function prototype and include guards.
 */

// This is an "Include Guard". It is the single most important technique
// for writing header files. It prevents the contents of this file from being
// included more than once, which would cause "duplicate definition" errors.
#ifndef MY_MATH_HELPERS_H // "if not defined" - checks if this unique name has been seen before.
#define MY_MATH_HELPERS_H // If not, define it now so future includes will fail the check.

// --- All header content goes between the #ifndef and #endif ---

// Function prototype for a function that is defined in my_math_helpers.c
int square(int x);

// If this file were included again, the #ifndef check would be false, and the
// preprocessor would skip straight to the #endif, ignoring the content in between.

#endif // End of the include guard.