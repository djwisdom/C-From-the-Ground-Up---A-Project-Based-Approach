/**
 * @file 28_hash_table_implementation.c
 * @author dunamismax 
 * @date 2025-06-10
 *
 * @brief An expert-level project: Building a hash table from scratch.
 *
 * ---
 *
 * What is a Hash Table?
 *
 * A hash table (or hash map) is a powerful data structure that maps "keys" to "values."
 * It's the underlying structure for dictionaries in Python, Objects in JavaScript, and
 * HashMap in Java. It allows for incredibly fast lookups, insertions, and deletions.
 *
 * Core Concepts:
 * 1.  **Hash Function:** The magic of a hash table is the hash function. It takes a key
 *     (e.g., the string "name") and computes an integer index. This index determines
 *     where in our internal array the corresponding value should be stored. A good
 *     hash function distributes keys evenly across the array.
 *
 * 2.  **Array (The Table):** The core of the hash table is a simple array. The index
 *     from the hash function tells us which "bucket" or "slot" in this array to use.
 *
 * 3.  **Collision Handling:** What happens if two different keys hash to the same index?
 *     This is called a "collision." Our implementation will handle this using a
 *     common technique called **"separate chaining."** Each slot in our array will be
 *     the head of a linked list. If a collision occurs, we simply add the new
 *     key-value pair as a new node in that slot's linked list.
 *
 * ---
 *
 * How to Compile and Run This Program:
 *
 * This program is not a command-line utility but a demonstration of the data structure.
 *
 * 1.  **Compile the code:**
 *     `gcc -Wall -Wextra -std=c11 -o hash_table 28_hash_table_implementation.c`
 *
 * 2.  **Run the executable:**
 *     `./hash_table` or `hash_table.exe`
 *
 * 3.  **Observe the output:** The `main` function will demonstrate creating the table,
 *     inserting items, searching for them, handling updates, deleting an item, and
 *     finally, freeing all memory.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 53 // A prime number is often a good choice for table size.

// --- Data Structures ---

// Represents a single key-value entry. This will be a node in our linked lists.
typedef struct EntryNode
{
    char *key;
    char *value;
    struct EntryNode *next;
} EntryNode;

// The main hash table structure.
typedef struct HashTable
{
    // The "table" itself is an array of pointers to EntryNodes.
    // Each element is a "bucket" which is the head of a linked list.
    EntryNode **entries;
    size_t size;
} HashTable;

// --- Core Functions ---

/**
 * @brief The hash function (djb2 algorithm).
 * @param key The string key to hash.
 * @return An unsigned long integer hash value.
 */
unsigned long hash_function(const char *key)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
    {
        // hash = hash * 33 + c
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

/**
 * @brief Creates and initializes a new hash table.
 * @return A pointer to the newly created HashTable, or NULL on failure.
 */
HashTable *ht_create(void)
{
    // Allocate memory for the HashTable structure itself.
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (table == NULL)
        return NULL;
    table->size = TABLE_SIZE;

    // Allocate memory for the array of entry pointers. Use calloc to ensure
    // all pointers are initialized to NULL, meaning all buckets are initially empty.
    table->entries = (EntryNode **)calloc(table->size, sizeof(EntryNode *));
    if (table->entries == NULL)
    {
        free(table);
        return NULL;
    }

    return table;
}

/**
 * @brief Creates a new key-value entry node.
 */
EntryNode *create_entry(const char *key, const char *value)
{
    EntryNode *entry = (EntryNode *)malloc(sizeof(EntryNode));
    // strdup allocates memory and copies the string. We must free it later.
    entry->key = strdup(key);
    entry->value = strdup(value);
    entry->next = NULL;
    return entry;
}

/**
 * @brief Inserts or updates a key-value pair in the hash table.
 */
void ht_insert(HashTable *table, const char *key, const char *value)
{
    // 1. Calculate the bucket index for this key.
    unsigned long hash_val = hash_function(key);
    size_t index = hash_val % table->size;

    // 2. Go to the bucket (the head of the linked list at this index).
    EntryNode *current = table->entries[index];

    // 3. Traverse the list to see if the key already exists.
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            // Key found: this is an UPDATE.
            free(current->value);           // Free the old value.
            current->value = strdup(value); // Assign the new value.
            return;
        }
        current = current->next;
    }

    // 4. Key not found: this is an INSERT.
    // Create a new entry node.
    EntryNode *new_entry = create_entry(key, value);
    // Insert the new node at the beginning of the list.
    new_entry->next = table->entries[index];
    table->entries[index] = new_entry;
}

/**
 * @brief Searches for a value by its key.
 * @return The value string if found, otherwise NULL.
 */
const char *ht_search(HashTable *table, const char *key)
{
    size_t index = hash_function(key) % table->size;
    EntryNode *current = table->entries[index];

    // Traverse the list in the bucket.
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value; // Key found, return the value.
        }
        current = current->next;
    }

    return NULL; // Key not found.
}

/**
 * @brief Deletes a key-value pair from the hash table.
 */
void ht_delete(HashTable *table, const char *key)
{
    size_t index = hash_function(key) % table->size;
    EntryNode *current = table->entries[index];
    EntryNode *prev = NULL;

    // Traverse the list to find the node to delete.
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            // Unlink the node from the list.
            if (prev == NULL)
            { // It's the head node.
                table->entries[index] = current->next;
            }
            else
            { // It's in the middle or at the end.
                prev->next = current->next;
            }
            // Free the memory for the deleted node's contents and the node itself.
            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

/**
 * @brief Frees all memory associated with the hash table.
 */
void ht_free(HashTable *table)
{
    for (size_t i = 0; i < table->size; ++i)
    {
        EntryNode *current = table->entries[i];
        while (current != NULL)
        {
            EntryNode *next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }
    }
    free(table->entries);
    free(table);
}

// --- Demonstration ---

int main(void)
{
    printf("--- Creating Hash Table ---\n");
    HashTable *ht = ht_create();
    if (!ht)
    {
        fprintf(stderr, "Failed to create hash table.\n");
        return EXIT_FAILURE;
    }

    printf("\n--- Inserting Key-Value Pairs ---\n");
    ht_insert(ht, "name", "Alice");
    ht_insert(ht, "age", "30");
    ht_insert(ht, "city", "New York");
    ht_insert(ht, "country", "USA");
    // This key might collide with "name" depending on the hash function and table size
    ht_insert(ht, "occupation", "Engineer");
    printf("Items inserted.\n");

    printf("\n--- Searching for Keys ---\n");
    printf("Name: %s\n", ht_search(ht, "name"));
    printf("City: %s\n", ht_search(ht, "city"));
    printf("Occupation: %s\n", ht_search(ht, "occupation"));
    // Search for a key that doesn't exist
    const char *status = ht_search(ht, "status");
    printf("Status: %s\n", status ? status : "(not found)");

    printf("\n--- Updating a Key ---\n");
    printf("Old city: %s\n", ht_search(ht, "city"));
    ht_insert(ht, "city", "London");
    printf("New city: %s\n", ht_search(ht, "city"));

    printf("\n--- Deleting a Key ---\n");
    printf("Searching for 'age' before deletion: %s\n", ht_search(ht, "age"));
    ht_delete(ht, "age");
    printf("Searching for 'age' after deletion: %s\n", ht_search(ht, "age") ? ht_search(ht, "age") : "(not found)");
    printf("Searching for 'name' to confirm it's still there: %s\n", ht_search(ht, "name"));

    printf("\n--- Freeing Hash Table ---\n");
    ht_free(ht);
    printf("Memory freed successfully.\n");

    return EXIT_SUCCESS;
}