#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;


void stackPush() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to push: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto stack.\n", value);
}

void stackPop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Popped %d from stack.\n", temp->data);
        top = top->next;
        free(temp);
    }
}


void queueInsert() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert in queue: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d in queue.\n", value);
}

void queueDelete() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = front;
        printf("Deleted %d from queue.\n", temp->data);
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
    }
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = front;
        printf("Queue: ");
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
        printf("\n1. Stack Push\n2. Stack Pop\n3. Display Stack\n4. Queue Insert\n5. Queue Delete\n6. Display Queue\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: stackPush(); break;
            case 2: stackPop(); break;
            case 3: displayStack(); break;
            case 4: queueInsert(); break;
            case 5: queueDelete(); break;
            case 6: displayQueue(); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
