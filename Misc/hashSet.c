#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 101 // Preferably a prime number

int hashTable[TABLE_SIZE]; // Or use dynamic allocation

void init();                 // Initialize the table
void insert(int value);      // Add value
void removeValue(int value); // Remove value
int contains(int value);     // Check if value exists
void display();
int main()
{
    init();
    int choice, value;

    while (1)
    {
        printf("\n----- Hash Set Menu -----\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Contains\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            printf("Inserted %d\n", value);
            break;
        case 2:
            printf("Enter value to remove: ");
            scanf("%d", &value);
            removeValue(value);
            printf("Removed %d (if present)\n", value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (contains(value))
                printf("%d is present in the set.\n", value);
            else
                printf("%d is NOT present in the set.\n", value);
            break;
        case 4:
            printf("Hash Table Contents:\n");
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void init()
{
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}
void insert(int value)
{
    int index = value % TABLE_SIZE;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == value)
            return;
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = value;
}

void removeValue(int value)
{

    int index = value % TABLE_SIZE;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == value)
        {
            hashTable[index] = -1;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
}

int contains(int value)
{
    int index = value % TABLE_SIZE;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == value)
            return true;
        index = (index + 1) % TABLE_SIZE;
    }
    return false;
}

void display()
{
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != -1)
        {
            printf("%d ", hashTable[i]);
        }
    }
    printf("\n");
}