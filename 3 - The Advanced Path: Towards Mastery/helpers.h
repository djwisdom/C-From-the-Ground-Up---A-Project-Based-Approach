/**
 * @file helpers.h
 * @brief Header file for demonstrating extern variables.
 */

// Include guard to prevent multiple inclusions.
#ifndef HELPERS_H
#define HELPERS_H

// By using 'extern' in a header file, we DECLARE that a global variable
// named 'shared_counter' exists somewhere in the project. We are not
// DEFINING it here (not allocating memory). We are telling any file that
// includes this header, "Trust me, this variable is available and the
// linker will find it for you."
extern int shared_counter;

// A regular function prototype.
void increment_shared_counter(void);

#endif // HELPERS_H