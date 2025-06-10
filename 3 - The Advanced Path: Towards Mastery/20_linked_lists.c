/**
 * @file 20_linked_lists.c
 * @author dunamismax
 * @date 2025-06-09
 *
 * @brief Teaches how to build and manage a linked list, a fundamental dynamic data structure.
 *
 * ---
 *
 * What's New in This Program?
 *
 * We are building a **Linked List**. Unlike an array, which stores data in a single,
 * contiguous block of memory, a linked list is made of individual "nodes" that can be
 * stored anywhere in memory. Each node contains a piece of data and, crucially, a
 * pointer to the next node in the sequence.
 *
 * - *Analogy:* A linked list is like a treasure hunt.
 *   - The **`head`** pointer is the first clue, which tells you where to start.
 *   - Each **`node`** is a treasure chest containing some data (the treasure) and a
 *     pointer (the location of the next clue).
 *   - The last node's pointer is `NULL`, which means "the treasure hunt ends here."
 *
 * Why use a Linked List instead of an Array?
 * - **Dynamic Size:** Linked lists can grow and shrink easily at runtime using `malloc`
 *   and `free`. You don't need to know the size beforehand.
 * - **Efficient Insertions/Deletions:** Adding or removing an element at the beginning
 *   is extremely fast. With an array, you would have to shift all other elements,
 *   which is very slow for large arrays.
 *
 * Key Concepts:
 * - **The `Node` struct:** The building block of our list, containing data and a pointer
 *   to the next `Node`.
 * - **The `head` pointer:** A standalone pointer that always keeps track of the very
 *   first node in the list. If `head` is `NULL`, the list is empty.
 * - **Traversal:** Moving through the list by starting at the `head` and following the
 *   `next` pointers until we reach `NULL`.
 * - **Double Pointers (`**head`):** When a function needs to modify the `head` pointer
 *   itself (like when adding a new first node), we must pass the *address of the head pointer*
 *   to that function. This is an advanced but essential pointer concept.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * `gcc -Wall -Wextra -std=c11 -o linked_list 20_linked_lists.c`
 * `./linked_list` (or `linked_list.exe` on Windows)
 *
 */

#include <stdio.h>
#include <stdlib.h>

// --- The Node "Blueprint" ---
// A struct to represent one link (one node) in our list.
struct Node
{
    int data;          // The data stored in this node.
    struct Node *next; // A pointer to the next node in the list.
};

// --- Function Prototypes ---
void insert_at_beginning(struct Node **head_ref, int new_data);
void print_list(struct Node *node);
void free_list(struct Node **head_ref);

/**
 * @brief The main function where our program's execution begins.
 */
int main(void)
{
    // Start with an empty list. The head pointer is our entry point to the list.
    struct Node *head = NULL;

    printf("Starting with an empty list.\n");
    print_list(head);

    printf("\nInserting 30 at the beginning...\n");
    insert_at_beginning(&head, 30);
    print_list(head);

    printf("\nInserting 20 at the beginning...\n");
    insert_at_beginning(&head, 20);
    print_list(head);

    printf("\nInserting 10 at the beginning...\n");
    insert_at_beginning(&head, 10);
    print_list(head);

    printf("\nFreeing all memory used by the list...\n");
    free_list(&head);
    print_list(head);

    return 0;
}

/**
 * @brief Inserts a new node at the very beginning of the list.
 * @param head_ref A pointer to the head pointer. We use a double pointer so we can
 *                 modify the head pointer in main() from within this function.
 * @param new_data The data to store in the new node.
 */
void insert_at_beginning(struct Node **head_ref, int new_data)
{
    // 1. Allocate memory for the new node.
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        perror("Failed to allocate memory for new node");
        return;
    }

    // 2. Put the data in the new node.
    new_node->data = new_data;

    // 3. Make the `next` of the new node point to the current head of the list.
    //    `*head_ref` gives us the actual head pointer.
    new_node->next = *head_ref;

    // 4. Move the head pointer to point to our new node, making it the new head.
    *head_ref = new_node;
}

/**
 * @brief Traverses the linked list and prints the data from each node.
 * @param node The starting node of the list to print (usually the head).
 */
void print_list(struct Node *node)
{
    printf("List: ");
    // Handle the case of an empty list.
    if (node == NULL)
    {
        printf("[EMPTY]\n");
        return;
    }

    // Traverse from the given node until we reach the end (NULL).
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next; // Move to the next node.
    }
    printf("NULL\n"); // The end of the list.
}

/**
 * @brief Deallocates all memory used by the list to prevent memory leaks.
 * @param head_ref A pointer to the head pointer.
 */
void free_list(struct Node **head_ref)
{
    struct Node *current = *head_ref; // Start at the head.
    struct Node *next_node;

    while (current != NULL)
    {
        // 1. Save a pointer to the next node before we free the current one.
        next_node = current->next;

        // 2. Free the memory for the current node.
        free(current);

        // 3. Move on to the next node that we saved.
        current = next_node;
    }

    // 4. Finally, set the original head pointer in main() back to NULL.
    //    This is crucial to show that the list is now officially empty.
    *head_ref = NULL;
}