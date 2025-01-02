#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int key;
    int value;
    int isOccupied;
} HashTable;

int hashFunction(int key, int size) {
    return key % size;
}

void initializeTable(HashTable table[], int size) {
    for (int i = 0; i < size; i++) {
        table[i].isOccupied = 0;
    }
}

void insert(HashTable table[], int size, int key, int value) {
    int index = hashFunction(key, size);
    int originalIndex = index;

    while (table[index].isOccupied) {
        index = (index + 1) % size;
        if (index == originalIndex) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }

    table[index].key = key;
    table[index].value = value;
    table[index].isOccupied = 1;
    printf("Inserted key %d at index %d\n", key, index);
}

int search(HashTable table[], int size, int key) {
    int index = hashFunction(key, size);
    int originalIndex = index;

    while (table[index].isOccupied) {
        if (table[index].key == key) {
            return index;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
            break;
        }
    }
    return -1;
}

void display(HashTable table[], int size) {
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied) {
            printf("Index %d: Key = %d, Value = %d\n", i, table[i].key, table[i].value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int size, choice, key, value;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    HashTable table[MAX];
    initializeTable(table, size);

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(table, size, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int result = search(table, size, key);
                if (result != -1) {
                    printf("Key %d found at index %d with value %d\n", key, result, table[result].value);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 3:
                display(table, size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
