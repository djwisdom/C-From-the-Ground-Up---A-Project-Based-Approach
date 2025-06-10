/**
 * @file 23_unions_and_enums.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Explains enumerations for creating named constants and unions for memory overlay.
 *
 * ---
 *
 * What's New in This Program?
 *
 * 1.  **`enum` (Enumeration):** An `enum` is a user-defined type that consists of a set
 *     of named integer constants. It makes your code more readable and self-documenting.
 *
 *     - *Analogy:* Instead of remembering that `0` means "running", `1` means "paused",
 *       and `2` means "stopped", you can define an `enum` to use meaningful names like
 *       `STATE_RUNNING`, `STATE_PAUSED`, and `STATE_STOPPED`. The compiler treats these
 *       as integers, but your code is much easier to understand.
 *
 * 2.  **`union`:** A union is a special data type that allows you to store different
 *     data types in the **same memory location**. While a `struct` allocates enough
 *     space to store all its members, a `union` allocates only enough space for its
 *     **largest member**. Only one member of the union can contain a value at any given time.
 *
 *     - *Analogy:* A `union` is like a single parking spot. You can park a motorcycle,
 *       a car, or a van in it, but only one at a time. The size of the parking spot
 *       must be large enough to accommodate the biggest vehicle (the van). If you park
 *       the car, the motorcycle is no longer there.
 *
 * 3.  **Tagged Unions:** The most common and safest way to use a union is to pair it
 *     with a `struct` and an `enum`. The `enum` acts as a "tag" that tells you which
 *     member of the union is currently active and valid, preventing you from
 *     misinterpreting the data.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o special_types 23_unions_and_enums.c`
 * `./special_types` (or `special_types.exe` on Windows)
 *
 */

#include <stdio.h>

// --- Part 1: Enum Declaration ---
// Define a set of named constants for a machine's state.
// By default, OPEN is 0, CLOSED is 1, LOCKED is 2.
enum DoorState
{
    STATE_OPEN,
    STATE_CLOSED,
    STATE_LOCKED
};

// --- Part 2: Union Declaration ---
// This union can hold an integer, a float, or a single character.
// Its total size in memory will be the size of its largest member (likely float).
union Data
{
    int i;
    float f;
    char c;
};

// --- Part 3: Tagged Union "Blueprint" ---
// This pattern combines a struct, enum, and union for safe usage.

// 1. The tag to identify the type
enum GenericType
{
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_CHAR
};

// 2. The struct that holds both the tag and the union
struct GenericValue
{
    enum GenericType type; // What kind of data are we storing?
    union Data value;      // The data itself.
};

// --- Function Prototypes ---
void process_door_state(enum DoorState current_state);
void print_generic_value(struct GenericValue gv);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: Using Enums ---
    printf("--- Part 1: Enumerations (enums) ---\n");
    enum DoorState my_door = STATE_CLOSED;
    process_door_state(my_door);
    process_door_state(STATE_LOCKED);

    // --- Part 2: Understanding Unions (the unsafe way) ---
    printf("\n--- Part 2: Understanding Unions ---\n");
    union Data data_point;

    data_point.i = 10;
    printf("As an integer: %d\n", data_point.i);

    data_point.f = 220.5f;
    printf("As a float:    %f\n", data_point.f);

    // Now, let's try to access the integer again. Its value has been
    // overwritten by the bits of the float. The result is garbage!
    printf("As an integer (after float was set): %d (Garbage!)\n", data_point.i);
    printf("Size of union Data: %zu bytes (size of largest member)\n", sizeof(union Data));

    // --- Part 3: Using Tagged Unions (the safe way) ---
    printf("\n--- Part 3: Tagged Unions ---\n");

    // Create a generic value that holds an integer.
    struct GenericValue val1;
    val1.type = TYPE_INTEGER;
    val1.value.i = 42;
    print_generic_value(val1);

    // Create another that holds a float.
    struct GenericValue val2;
    val2.type = TYPE_FLOAT;
    val2.value.f = 3.14f;
    print_generic_value(val2);

    return 0;
}

/**
 * @brief A function that uses an enum to make a switch statement readable.
 */
void process_door_state(enum DoorState current_state)
{
    switch (current_state)
    {
    case STATE_OPEN:
        printf("The door is currently open.\n");
        break;
    case STATE_CLOSED:
        printf("The door is currently closed.\n");
        break;
    case STATE_LOCKED:
        printf("The door is securely locked.\n");
        break;
        // No 'default' is needed if we handle all enum constants.
    }
}

/**
 * @brief Safely prints the value of a tagged union by first checking its type tag.
 */
void print_generic_value(struct GenericValue gv)
{
    printf("Processing generic value: ");
    switch (gv.type)
    {
    case TYPE_INTEGER:
        printf("It's an integer with value %d\n", gv.value.i);
        break;
    case TYPE_FLOAT:
        printf("It's a float with value %f\n", gv.value.f);
        break;
    case TYPE_CHAR:
        printf("It's a char with value %c\n", gv.value.c);
        break;
    default:
        printf("Unknown data type!\n");
        break;
    }
}