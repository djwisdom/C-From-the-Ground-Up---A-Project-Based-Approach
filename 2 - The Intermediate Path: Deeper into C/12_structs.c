/**
 * @file 12_structs.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to create custom, composite data types using `struct`.
 *
 * ---
 *
 * What's New in This Program?
 *
 * We've used built-in types like `int` and `char`, and arrays to group them. But what
 * if you want to represent something more complex, like a "Student"? A student has a
 * name (a string), an ID (an integer), and a GPA (a float). These are different types,
 * so an array won't work.
 *
 * This is where `struct` (short for structure) comes in. A struct is a way to bundle
 * several related variables of different types into a single, user-defined type.
 *
 * - *Analogy:* A struct is like a blueprint for creating a custom form or a contact
 *   card. The blueprint defines the fields ("Name:", "ID:", "GPA:"). Each `struct`
 *   variable you create is like a physical card you've filled out with specific data.
 *
 * Key Concepts:
 *
 * 1.  **Definition:** You first define the "blueprint" for your struct, usually
 *     outside of `main`. This doesn't create any variables yet, it just tells the
 *     compiler what a `struct Student` looks like.
 *
 * 2.  **Declaration:** You create an "instance" of the struct just like any other
 *     variable: `struct Student student1;`.
 *
 * 3.  **Member Access Operator (`.`):** To access a field (a "member") inside a
 *     struct variable, you use the dot operator. For example: `student1.gpa = 3.5;`.
 *
 * 4.  **Pointers to Structs and the Arrow Operator (`->`):** Just like with other
 *     variables, you can have pointers to structs. To access a member through a
 *     pointer, you could write `(*p_student).gpa`, but C provides a much cleaner
 *     "syntactic sugar" for this: the arrow operator `->`. So, `p_student->gpa` is
 *     the preferred way to do it.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o structs 12_structs.c`
 * `./structs` (or `structs.exe` on Windows)
 *
 */

#include <stdio.h>
#include <string.h> // We need this for strcpy()

// --- 1. Struct Definition (The Blueprint) ---
// This defines a new compound type called `struct Student`.
// It groups together three "members": a character array, an integer, and a float.
struct Student
{
    char name[50];
    int id;
    float gpa;
};

// --- Function Prototype ---
// This function will take a pointer to a Student struct to avoid copying the whole thing.
void print_student_info(struct Student *s);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // --- Part 1: Declaring and Initializing a Struct Variable ---
    printf("--- Part 1: Initializing a Struct ---\n");

    // Declare a variable of type `struct Student`. Think of `student1` as a blank contact card.
    struct Student student1;

    // Use the dot operator `.` to access the members and fill the card out.
    // For strings, we must use `strcpy`, not the `=` operator.
    strcpy(student1.name, "Alice Wonderland");
    student1.id = 101;
    student1.gpa = 3.8f; // The 'f' makes it an explicit float literal.

    printf("Student 1's Name: %s\n", student1.name);
    printf("Student 1's ID: %d\n", student1.id);
    printf("Student 1's GPA: %.2f\n", student1.gpa); // `%.2f` prints the float with 2 decimal places.

    // --- Part 2: Using an Initializer List ---
    printf("\n--- Part 2: Using an Initializer List ---\n");

    // A more concise way to initialize a struct is with a brace-enclosed list.
    // The values must be in the same order as they are defined in the struct.
    struct Student student2 = {"Bob Builder", 102, 3.5f};
    printf("Student 2's Name: %s, ID: %d, GPA: %.2f\n", student2.name, student2.id, student2.gpa);

    // --- Part 3: Pointers to Structs ---
    printf("\n--- Part 3: Pointers to Structs ---\n");

    // Create a pointer that can hold the address of a `struct Student`.
    struct Student *p_student = NULL;

    // Make the pointer point to our first student variable.
    p_student = &student1;

    // Now we can access the members through the pointer.
    // The arrow operator `->` is the clean and standard way to do this.
    // It combines the dereference `*` and the dot `.` in one step.
    printf("Accessing GPA via pointer->arrow: %.2f\n", p_student->gpa);

    // You can also use the explicit dereference, but it's clunky and less common.
    // The parentheses are required due to operator precedence.
    printf("Accessing ID via (*pointer).dot: %d\n", (*p_student).id);

    // --- Part 4: Passing a Struct to a Function ---
    printf("\n--- Part 4: Passing to a Function ---\n");
    printf("Printing student 2's info using a function:\n");

    // We pass the ADDRESS of student2. This is efficient because only the address (a pointer)
    // is copied, not the entire, potentially large, struct.
    print_student_info(&student2);

    return 0;
}

/**
 * @brief Prints the details of a student using a pointer to the student's struct.
 *
 * @param s A pointer to the `struct Student` variable that should be printed.
 */
void print_student_info(struct Student *s)
{
    // Inside the function, we use the arrow operator on the pointer parameter
    // to access the members of the original struct.
    printf("  Name: %s\n", s->name);
    printf("  ID:   %d\n", s->id);
    printf("  GPA:  %.2f\n", s->gpa);
}