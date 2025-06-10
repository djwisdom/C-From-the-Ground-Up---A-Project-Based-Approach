/**
 * @file 17_student_record_system.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief A menu-driven program to manage a database of student records.
 *
 * ---
 *
 * What's New in This Program?
 *
 * This is a capstone project for your beginner C journey. It combines nearly all
 * previous concepts to create a practical, interactive application.
 *
 * Concepts We Are Integrating:
 *
 * - **Structs:** To define the blueprint for a `Student` record (id, name, gpa).
 * - **Arrays of Structs:** To act as our in-memory database, holding all the students.
 * - **Functions:** To create a modular and organized program (e.g., add_student, print_database).
 * - **File I/O:** To save the student database to a file (`students.db`) so data
 *   persists between runs, and to load it back when the program starts.
 * - **Pointers:** Used implicitly when passing arrays and explicitly when needed.
 * - **Menu-Driven Interface:** Using a `do-while` loop and a `switch` statement to
 *   continuously prompt the user for actions.
 * - **Robust User Input:** Using `fgets` to safely read names with spaces and handling
 *   the input buffer carefully.
 *
 * This project represents a significant step up from single-concept scripts to building
 * complete, stateful applications.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1. Compile as usual:
 *    `gcc -Wall -Wextra -std=c11 -o student_system 17_student_record_system.c`
 *
 * 2. Run the executable:
 *    `./student_system` (or `student_system.exe` on Windows)
 *
 * 3. Interact with the menu. Add some students, print the database, then exit.
 *    Run the program again, and you'll see your records are automatically loaded!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constants and Global Variables ---

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100
#define DATABASE_FILE "students.db"

// Define the blueprint for a single student record.
struct Student
{
    int id;
    char name[MAX_NAME_LEN];
    float gpa;
};

// Our in-memory database: an array of Student structs.
// We make these global for simplicity in this single-file project,
// so we don't have to pass them to every single function.
struct Student database[MAX_STUDENTS];
int student_count = 0; // Keeps track of how many students are currently in the database.

// --- Function Prototypes ---
void print_menu(void);
void add_student(void);
void print_database(void);
void save_database_to_file(void);
void load_database_from_file(void);
void clean_input_buffer(void);

/**
 * @brief The main control hub of our application.
 */
int main(void)
{
    int choice;
    load_database_from_file(); // Load existing records on startup.

    do
    {
        print_menu();
        scanf("%d", &choice);
        clean_input_buffer(); // Clean up the newline left by scanf.

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            print_database();
            break;
        case 3:
            save_database_to_file();
            printf("Database saved.\n");
            break;
        case 4:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        printf("\n");

    } while (choice != 4);

    // Automatically save before quitting for convenience.
    save_database_to_file();

    return 0;
}

/**
 * @brief Displays the main menu options to the user.
 */
void print_menu(void)
{
    printf("--- Student Record System ---\n");
    printf("1. Add a new student\n");
    printf("2. Print all student records\n");
    printf("3. Save database to file\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Enter your choice: ");
}

/**
 * @brief Adds a new student record to the in-memory database.
 */
void add_student(void)
{
    if (student_count >= MAX_STUDENTS)
    {
        printf("Error: Database is full. Cannot add more students.\n");
        return;
    }

    printf("--- Add New Student ---\n");
    struct Student new_student;

    printf("Enter Student ID: ");
    scanf("%d", &new_student.id);
    clean_input_buffer();

    printf("Enter Student Name: ");
    fgets(new_student.name, MAX_NAME_LEN, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0'; // Remove trailing newline from fgets

    printf("Enter Student GPA: ");
    scanf("%f", &new_student.gpa);
    clean_input_buffer();

    // Add the newly created student to our database array.
    database[student_count] = new_student;
    student_count++; // Increment the count of students.

    printf("Student added successfully!\n");
}

/**
 * @brief Prints all student records currently in the database to the console.
 */
void print_database(void)
{
    printf("--- Student Database ---\n");
    if (student_count == 0)
    {
        printf("The database is currently empty.\n");
        return;
    }

    // Print a formatted header for our table.
    printf("%-5s %-30s %-5s\n", "ID", "Name", "GPA");
    printf("----- ------------------------------ -----\n");

    for (int i = 0; i < student_count; i++)
    {
        // Print each student's data in a formatted row.
        printf("%-5d %-30s %-5.2f\n", database[i].id, database[i].name, database[i].gpa);
    }
}

/**
 * @brief Writes the entire in-memory database to the specified file.
 */
void save_database_to_file(void)
{
    FILE *pFile = fopen(DATABASE_FILE, "w");
    if (pFile == NULL)
    {
        perror("Error saving database to file");
        return;
    }

    for (int i = 0; i < student_count; i++)
    {
        // Write each record on a new line. We use a simple format: ID GPA Name
        // This format is chosen so the name (which can have spaces) is last,
        // making it easier to parse when reading back in.
        fprintf(pFile, "%d %.2f %s\n", database[i].id, database[i].gpa, database[i].name);
    }

    fclose(pFile);
}

/**
 * @brief Reads student records from the specified file into the in-memory database.
 */
void load_database_from_file(void)
{
    FILE *pFile = fopen(DATABASE_FILE, "r");
    // If the file doesn't exist, that's okay. It just means no records have been saved yet.
    if (pFile == NULL)
    {
        return; // Silently return, program will start with an empty database.
    }

    // Read from the file until we can't read any more valid records
    // or the database array is full.
    while (student_count < MAX_STUDENTS &&
           fscanf(pFile, "%d %f ", &database[student_count].id, &database[student_count].gpa) == 2)
    {
        // The space after %f in fscanf is important. It consumes the trailing whitespace.
        // Now, fgets will read the rest of the line, which is just the student's name.
        if (fgets(database[student_count].name, MAX_NAME_LEN, pFile) != NULL)
        {
            database[student_count].name[strcspn(database[student_count].name, "\n")] = '\0';
            student_count++;
        }
    }

    fclose(pFile);
    printf("Loaded %d student(s) from %s.\n\n", student_count, DATABASE_FILE);
}

/**
 * @brief A utility function to consume leftover characters in the input stream,
 *        especially the newline character left by `scanf`.
 */
void clean_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Read and discard characters until a newline or end-of-file is found.
    }
}