#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100


#define M 10 
struct Employee {
    int key;    
    int data;   
};

struct Employee hashTable[M];

void initializeHashTable() {
    for (int i = 0; i < M; i++) {
        hashTable[i].key = -1;  
        hashTable[i].data = -1;
    }
}

int hashFunction(int key) {
    return key % M;  
}

void insert(int key, int data) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            printf("Employee with key %d already exists.\n", key);
            return;  
        }
        index = (index + 1) % M;  
        if (index == originalIndex) {
            printf("Hash table is full.\n");
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].data = data;
    printf("Employee with key %d inserted at address %d.\n", key, index);
}

int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return hashTable[index].data; 
        }
        index = (index + 1) % M;
        if (index == originalIndex) {
            break;
        }
    }

    return -1;  
}

void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < M; i++) {
        if (hashTable[i].key != -1) {
            printf("Address %d -> Key: %d, Data: %d\n", i, hashTable[i].key, hashTable[i].data);
        } else {
            printf("Address %d -> Empty\n", i);
        }
    }
}

int main() {
    int choice, key, data;

    initializeHashTable();  

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Employee\n");
        printf("2. Search Employee\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee Key (4-digit): ");
                scanf("%d", &key);
                printf("Enter Employee Data: ");
                scanf("%d", &data);
                insert(key, data);
                break;
            case 2:
                printf("Enter Employee Key to search (4-digit): ");
                scanf("%d", &key);
                data = search(key);
                if (data != -1) {
                    printf("Employee with key %d found, Data: %d\n", key, data);
                } else {
                    printf("Employee with key %d not found.\n", key);
                }
                break;
            case 3:
                displayHashTable();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
