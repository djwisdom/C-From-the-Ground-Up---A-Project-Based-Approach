/**
 * @file 8_arrays.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to store and manage a collection of data using arrays.
 *
 * ---
 *
 * What's New in This Program?
 *
 * So far, each variable we've used could only hold one value at a time (e.g., `int age = 30;`).
 * What if you needed to store the ages of 100 people? Declaring 100 different variables
 * would be a nightmare! The solution is the "array".
 *
 * An array is a collection of elements of the **same data type**, stored together under
 * a single variable name.
 *
 * - *Analogy:* If a variable is a single box, an array is a chest of drawers. The
 *   whole chest has one name (e.g., `grades`), and each drawer is numbered so you can
 *   access it individually.
 *
 * Key Concepts:
 *
 * 1.  **Declaration:** You declare an array by specifying the data type, the name, and
 *     the size in square brackets. `int scores[5];` creates an array named `scores`
 *     that can hold 5 integers.
 *
 * 2.  **Zero-Based Indexing:** This is the most important concept for arrays. The "drawers"
 *     or "slots" in an array are numbered starting from **0**, not 1.
 *     - For an array of size 5, the valid indexes are 0, 1, 2, 3, and 4.
 *     - `my_array[0]` is the **first** element.
 *     - `my_array[4]` is the **last** element.
 *     - Trying to access `my_array[5]` is an error!
 *
 * 3.  **Initialization:** You can provide the array's contents when you declare it using
 *     curly braces: `int grades[] = {88, 92, 75};`. The compiler automatically figures
 *     out the size.
 *
 * 4.  **Loops and Arrays:** `for` loops are the perfect tool for working with arrays.
 *     You can loop from index 0 up to the last index to process every element.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o arrays 8_arrays.c`
 * `./arrays` (or `arrays.exe` on Windows)
 *
 */

#include <stdio.h>

/**
 * @brief The main function where our program's execution begins.
 *
 * This program will demonstrate how to declare, initialize, access, and
 * iterate over an array of integers.
 *
 * @param void This function accepts no arguments.
 * @return int Returns 0 to indicate successful execution.
 */
int main(void)
{
    printf("--- Introduction to Arrays ---\n");

    // We declare and initialize an array of 5 integers.
    // The elements are:
    // Index 0: 88
    // Index 1: 92
    // Index 2: 75
    // Index 3: 98
    // Index 4: 85
    int grades[] = {88, 92, 75, 98, 85};

    // Accessing an element: To get an element, you use the array name
    // followed by the index in square brackets.
    // Let's get the grade of the 3rd student (at index 2).
    printf("The third student's grade is: %d\n", grades[2]);

    // Modifying an element: You can change the value at a specific index
    // using the assignment operator `=`.
    printf("Oops, there was a grading error for the third student.\n");
    grades[2] = 79; // Change the value at index 2 from 75 to 79.
    printf("The third student's corrected grade is: %d\n", grades[2]);

    printf("\n--- Looping Through an Array ---\n");

    // A 'for' loop is the perfect way to process every element in an array.
    // We need to know how many elements the array has. Let's find out!
    // The `sizeof` operator gives the size of something in bytes.
    // - `sizeof(grades)` = total bytes of the whole array (e.g., 5 ints * 4 bytes/int = 20 bytes).
    // - `sizeof(grades[0])` = bytes of a single element (e.g., 4 bytes for one int).
    // Dividing them gives us the number of elements. This is the standard way to get array length in C.
    int num_of_grades = sizeof(grades) / sizeof(grades[0]);
    printf("The grades array has %d elements.\n", num_of_grades);

    // Now we loop from index 0 up to (but not including) the number of elements.
    for (int i = 0; i < num_of_grades; i++)
    {
        printf("Grade at index %d is: %d\n", i, grades[i]);
    }

    printf("\n--- Practical Example: Calculating the Average Grade ---\n");

    // Let's use a loop to calculate the sum of all grades.
    int sum = 0;
    for (int i = 0; i < num_of_grades; i++)
    {
        // On each iteration, add the current grade to the running total.
        sum = sum + grades[i]; // or using shorthand: `sum += grades[i];`
    }
    printf("Sum of all grades: %d\n", sum);

    // To calculate the average, we need floating-point division.
    // We "cast" the sum to a `double` before dividing.
    double average = (double)sum / num_of_grades;
    printf("Average grade: %f\n", average);

    return 0; // Signal successful execution.
}