/**
 * @file 25_simple_text_editor.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief A line-based text editor, your final capstone project.
 *
 * ---
 *
 * Congratulations! This project combines all the major C concepts you've learned.
 *
 * Core Design:
 *
 * - **Data Structure:** The heart of the editor is a **doubly-linked list**. Each node
 *   in the list represents one line of text. This is an upgrade from a singly-linked
 *   list, as it allows for easier insertion and deletion.
 * - **Dynamic Memory:** Every line (node) is created on the heap using `malloc` and
 *   destroyed with `free`, allowing the document to be any length.
 * - **File I/O:** The editor can save its current text buffer to a file and load an
 *   existing file into memory, making it a persistent, useful tool.
 * - **Modular Functions:** The code is broken down into clean, single-purpose functions
 *   (e.g., `display_text`, `delete_line`) for good organization.
 * - **Robust Input:** It handles user input carefully, using `fgets` for text and a
 *   helper function to manage the input buffer, preventing common `scanf` pitfalls.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * 1. Compile as usual:
 *    `gcc -Wall -Wextra -std=c11 -o editor 25_simple_text_editor.c`
 *
 * 2. Run the executable:
 *    `./editor` or `editor.exe`
 *    You can also provide a filename to automatically load: `./editor my_document.txt`
 *
 * 3. Interact with the menu. Add, insert, and delete lines. Save your work.
 *    Exit and run the program again with the same filename to see your work reloaded.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constants and Type Definitions ---
#define MAX_LINE_LENGTH 256
#define DEFAULT_FILENAME "untitled.txt"

// The blueprint for a single line in our editor (a node in a doubly-linked list).
typedef struct LineNode
{
    char text[MAX_LINE_LENGTH];
    struct LineNode *prev;
    struct LineNode *next;
} LineNode;

// Global pointers to the start and end of our list for easy access.
LineNode *head = NULL;
LineNode *tail = NULL;
int line_count = 0;
char current_filename[MAX_LINE_LENGTH];

// --- Function Prototypes ---
void display_menu(void);
void handle_append_line(void);
void handle_insert_line(void);
void handle_delete_line(void);
void display_text(void);
void save_to_file(void);
void load_from_file(const char *filename);
void free_all_lines(void);
void clean_input_buffer(void);

/**
 * @brief Main entry point. Sets up the editor and runs the main loop.
 */
int main(int argc, char *argv[])
{
    // Determine the filename: use the command-line argument or the default.
    if (argc > 1)
    {
        strncpy(current_filename, argv[1], MAX_LINE_LENGTH - 1);
    }
    else
    {
        strcpy(current_filename, DEFAULT_FILENAME);
    }
    current_filename[MAX_LINE_LENGTH - 1] = '\0'; // Ensure null termination.

    load_from_file(current_filename);

    int choice;
    do
    {
        display_menu();
        if (scanf("%d", &choice) != 1)
        {
            choice = -1; // Invalid input
        }
        clean_input_buffer();

        switch (choice)
        {
        case 1:
            handle_append_line();
            break;
        case 2:
            handle_insert_line();
            break;
        case 3:
            handle_delete_line();
            break;
        case 4:
            display_text();
            break;
        case 5:
            save_to_file();
            break;
        case 6:
            printf("Exiting the editor.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        printf("\n");
    } while (choice != 6);

    // Free all dynamically allocated memory before the program closes.
    free_all_lines();
    return 0;
}

void display_menu(void)
{
    printf("--- C Simple Text Editor ---\n");
    printf("File: %s | Lines: %d\n", current_filename, line_count);
    printf("----------------------------\n");
    printf("1. Append a new line\n");
    printf("2. Insert a line at a specific position\n");
    printf("3. Delete a line\n");
    printf("4. Display all text\n");
    printf("5. Save to file\n");
    printf("6. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: ");
}

/**
 * @brief Appends a new line of text to the end of the document.
 */
void handle_append_line(void)
{
    printf("Enter text to append: ");
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, MAX_LINE_LENGTH, stdin);

    LineNode *newNode = (LineNode *)malloc(sizeof(LineNode));
    if (!newNode)
    {
        perror("Failed to allocate memory");
        return;
    }

    strcpy(newNode->text, buffer);
    newNode->next = NULL;

    if (head == NULL)
    { // If list is empty
        newNode->prev = NULL;
        head = tail = newNode;
    }
    else
    { // Append to the end
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    line_count++;
}

/**
 * @brief Displays the entire text buffer with line numbers.
 */
void display_text(void)
{
    printf("--- Document: %s ---\n", current_filename);
    if (head == NULL)
    {
        printf("[ Document is empty ]\n");
    }
    else
    {
        LineNode *current = head;
        int num = 1;
        while (current != NULL)
        {
            printf("%4d: %s", num++, current->text);
            current = current->next;
        }
    }
    printf("--- End of Document ---\n");
}

/**
 * @brief Deletes a line specified by its number.
 */
void handle_delete_line(void)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n");
        return;
    }
    printf("Enter line number to delete (1-%d): ", line_count);
    int line_num;
    if (scanf("%d", &line_num) != 1)
    {
        clean_input_buffer();
        printf("Invalid input.\n");
        return;
    }
    clean_input_buffer();

    if (line_num < 1 || line_num > line_count)
    {
        printf("Invalid line number.\n");
        return;
    }

    LineNode *to_delete = head;
    for (int i = 1; i < line_num; i++)
    {
        to_delete = to_delete->next;
    }

    if (to_delete->prev)
        to_delete->prev->next = to_delete->next;
    else
        head = to_delete->next;
    if (to_delete->next)
        to_delete->next->prev = to_delete->prev;
    else
        tail = to_delete->prev;

    free(to_delete);
    line_count--;
    printf("Line %d deleted.\n", line_num);
}

/**
 * @brief Inserts a line at a specific position.
 */
void handle_insert_line(void)
{
    printf("Enter line number to insert before (1-%d, or %d to append): ", line_count, line_count + 1);
    int line_num;
    if (scanf("%d", &line_num) != 1)
    {
        clean_input_buffer();
        printf("Invalid input.\n");
        return;
    }
    clean_input_buffer();

    if (line_num < 1 || line_num > line_count + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    if (line_num == line_count + 1)
    {
        handle_append_line();
        return;
    }

    printf("Enter text to insert: ");
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, MAX_LINE_LENGTH, stdin);

    LineNode *newNode = (LineNode *)malloc(sizeof(LineNode));
    if (!newNode)
    {
        perror("Failed to allocate memory");
        return;
    }
    strcpy(newNode->text, buffer);

    LineNode *current = head;
    for (int i = 1; i < line_num; i++)
    {
        current = current->next;
    }

    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev)
        current->prev->next = newNode;
    else
        head = newNode;
    current->prev = newNode;

    line_count++;
}

/**
 * @brief Saves the entire text buffer to the current file.
 */
void save_to_file(void)
{
    FILE *file = fopen(current_filename, "w");
    if (file == NULL)
    {
        perror("Error saving file");
        return;
    }
    LineNode *current = head;
    while (current != NULL)
    {
        fprintf(file, "%s", current->text);
        current = current->next;
    }
    fclose(file);
    printf("Successfully saved to %s\n", current_filename);
}

/**
 * @brief Loads text from a file, replacing any current text.
 */
void load_from_file(const char *filename)
{
    free_all_lines(); // Clear any existing content first.
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        // This is not an error, it just means a new file will be created on save.
        printf("Starting new file: %s\n\n", filename);
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL)
    {
        // Use the same append logic, but without user prompts.
        LineNode *newNode = (LineNode *)malloc(sizeof(LineNode));
        if (!newNode)
        {
            perror("Failed to allocate memory during load");
            fclose(file);
            return;
        }
        strcpy(newNode->text, buffer);
        newNode->next = NULL;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        line_count++;
    }
    fclose(file);
    printf("Successfully loaded %d lines from %s\n\n", line_count, filename);
}

/**
 * @brief Frees all nodes in the linked list to prevent memory leaks.
 */
void free_all_lines(void)
{
    LineNode *current = head;
    LineNode *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    head = tail = NULL;
    line_count = 0;
}

/**
 * @brief Utility to consume leftover characters in the input stream.
 */
void clean_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}