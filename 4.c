#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create() {
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}

void insertFirst() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert at first position: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition() {
    int pos, data;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert: ");
    scanf("%d", &newNode->data);
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position out of range.\n");
        free(newNode);
    }
}

void insertEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert at end: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        printf("Linked List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Create Linked List\n2. Insert at First\n3. Insert at Position\n4. Insert at End\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: insertFirst(); break;
            case 3: insertAtPosition(); break;
            case 4: insertEnd(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
