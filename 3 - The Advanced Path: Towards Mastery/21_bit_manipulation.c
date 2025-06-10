/**
 * @file 21_bit_manipulation.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to perform low-level operations on individual bits.
 *
 * ---
 *
 * What's New in This Program?
 *
 * All data in a computer is stored as bits (binary digits: 0 or 1). Bit manipulation
 * is the act of algorithmically operating on these individual bits. This is done
 * using **bitwise operators**.
 *
 * - *Analogy:* Think of a variable like an 8-switch light panel. Until now, you've
 *   only been able to turn the entire panel on or off. Bitwise operators let you
 *   precisely flip each individual switch.
 *
 * The Six Bitwise Operators:
 *
 * 1.  **`&` (Bitwise AND):** The resulting bit is 1 only if *both* corresponding input bits are 1.
 *     - Used to **check for** or **clear** a specific bit.
 *
 * 2.  **`|` (Bitwise OR):** The resulting bit is 1 if *at least one* of the input bits is 1.
 *     - Used to **set** a specific bit to 1.
 *
 * 3.  **`^` (Bitwise XOR):** "Exclusive OR". The resulting bit is 1 if the input bits are *different*.
 *     - Used to **toggle** or **flip** a specific bit.
 *
 * 4.  **`~` (Bitwise NOT):** Inverts all bits of a number (0s become 1s, 1s become 0s).
 *
 * 5.  **`<<` (Left Shift):** Shifts all bits to the left by a specified number of places.
 *     - `x << n` is a fast way to calculate `x * 2^n`.
 *
 * 6.  **`>>` (Right Shift):** Shifts all bits to the right.
 *     - `x >> n` is a fast way to calculate `x / 2^n` (for unsigned integers).
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o bitwise 21_bit_manipulation.c`
 * `./bitwise` (or `bitwise.exe` on Windows)
 *
 */

#include <stdio.h>

// --- Function Prototype for our helper function ---
void print_binary(unsigned char byte);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // We use `unsigned char` because it's typically an 8-bit integer,
    // making it perfect for demonstrating bitwise operations.
    unsigned char a = 93;  // Binary: 01011101
    unsigned char b = 170; // Binary: 10101010

    printf("--- Part 1: The Basic Bitwise Operators ---\n");
    printf("a        = %3u = ", a);
    print_binary(a);
    printf("\nb        = %3u = ", b);
    print_binary(b);
    printf("\n---------------------------\n");

    printf("a & b    = %3u = ", a & b);
    print_binary(a & b); // AND
    printf("\na | b    = %3u = ", a | b);
    print_binary(a | b); // OR
    printf("\na ^ b    = %3u = ", a ^ b);
    print_binary(a ^ b); // XOR
    printf("\n~a       = %3u = ", ~a);
    print_binary(~a); // NOT
    printf("\na << 1   = %3u = ", a << 1);
    print_binary(a << 1); // Left Shift
    printf("\na >> 2   = %3u = ", a >> 2);
    print_binary(a >> 2); // Right Shift
    printf("\n\n");

    // --- Part 2: Practical Use Case - Status Flags ---
    // We can pack 8 boolean flags into a single byte to save memory.
    printf("--- Part 2: Practical Example with Status Flags ---\n");

    // Define masks for each flag. A mask is an integer with specific bits set.
    // Using left shifts makes it readable and easy to define.
    const unsigned char FLAG_ACTIVE = 1 << 0;   // 00000001
    const unsigned char FLAG_VISIBLE = 1 << 1;  // 00000010
    const unsigned char FLAG_EDITABLE = 1 << 2; // 00000100
    const unsigned char FLAG_ADMIN = 1 << 7;    // 10000000

    unsigned char user_status = 0; // Start with no flags set.
    printf("Initial status: ");
    print_binary(user_status);

    // 1. Set a flag using OR (|)
    user_status |= FLAG_ACTIVE;
    printf("\nSet ACTIVE:     ");
    print_binary(user_status);

    user_status |= FLAG_EDITABLE;
    printf("\nSet EDITABLE:   ");
    print_binary(user_status);

    // 2. Check for a flag using AND (&)
    printf("\n\nChecking flags:\n");
    if (user_status & FLAG_ACTIVE)
    {
        printf("  User is ACTIVE.\n");
    }
    if (!(user_status & FLAG_VISIBLE))
    { // Check if a flag is NOT set
        printf("  User is NOT VISIBLE.\n");
    }

    // 3. Clear (unset) a flag using AND with a NOT'd mask
    user_status &= ~FLAG_ACTIVE;
    printf("\nCleared ACTIVE: ");
    print_binary(user_status);

    // 4. Toggle a flag using XOR (^)
    // The EDITABLE flag is currently on, so this will turn it off.
    user_status ^= FLAG_EDITABLE;
    printf("\nToggled EDITABLE: ");
    print_binary(user_status);
    // Now it's off, so toggling again will turn it back on.
    user_status ^= FLAG_EDITABLE;
    printf("\nToggled again:  ");
    print_binary(user_status);
    printf("\n");

    return 0;
}

/**
 * @brief A helper function to print the 8-bit binary representation of a byte.
 * @param byte The unsigned character to print in binary.
 */
void print_binary(unsigned char byte)
{
    // Loop through each bit from most significant (leftmost, bit 7) to least (bit 0).
    for (int i = 7; i >= 0; i--)
    {
        // Right-shift the byte by `i` positions to move the bit we want into the
        // rightmost position. Then, use bitwise AND with 1 to isolate it.
        // If the result is 1, the bit was 1. Otherwise, it was 0.
        if ((byte >> i) & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}