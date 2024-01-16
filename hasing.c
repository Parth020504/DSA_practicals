#include <stdio.h>

#define TABLE_SIZE 10

// Hash Function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table using Linear Probing
void linearProbingInsert(int hashTable[], int key) {
    int index = hash(key);
    int i = 1;

    while (hashTable[index] != -1) {
        index = (index + i) % TABLE_SIZE;
        i++;
    }

    hashTable[index] = key;
    printf("Key %d inserted at index %d using linear probing.\n", key, index);
}

// Function to search for a key in the hash table using Linear Probing
int linearProbingSearch(int hashTable[], int key) {
    int index = hash(key);
    int i = 1;

    while (hashTable[index] != key) {
        if (hashTable[index] == -1)
            return -1; // Key not found
        index = (index + i) % TABLE_SIZE;
        i++;
    }

    return index; // Key found at index
}

// Function to insert a key into the hash table using Quadratic Probing
void quadraticProbingInsert(int hashTable[], int key) {
    int index = hash(key);
    int i = 1;

    while (hashTable[index] != -1) {
        index = (index + i * i) % TABLE_SIZE;
        i++;
    }

    hashTable[index] = key;
    printf("Key %d inserted at index %d using quadratic probing.\n", key, index);
}

// Function to search for a key in the hash table using Quadratic Probing
int quadraticProbingSearch(int hashTable[], int key) {
    int index = hash(key);
    int i = 1;

    while (hashTable[index] != key) {
        if (hashTable[index] == -1)
            return -1; // Key not found
        index = (index + i * i) % TABLE_SIZE;
        i++;
    }

    return index; // Key found at index
}

// Function to print the hash table
void printHashTable(int hashTable[]) {
    printf("Hash Table:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> %d\n", i, hashTable[i]);
    }
}

int main() {
    int linearProbingTable[TABLE_SIZE];
    int quadraticProbingTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        linearProbingTable[i] = -1; // Initialize to -1 (indicating empty slot)
        quadraticProbingTable[i] = -1;
    }

    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Print Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert using linear probing: ");
                scanf("%d", &key);
                linearProbingInsert(linearProbingTable, key);
                break;

            case 2:
                printf("Enter key to insert using quadratic probing: ");
                scanf("%d", &key);
                quadraticProbingInsert(quadraticProbingTable, key);
                break;

            case 3:
                printHashTable(linearProbingTable);
                printHashTable(quadraticProbingTable);
                break;

            case 4:
                printf("Program exited.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
