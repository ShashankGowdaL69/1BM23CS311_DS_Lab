#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void insert() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        printf("Enter value to insert: ");
        scanf("%d", &value);
        queue[++rear] = value;
        printf("Inserted %d\n", value);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
