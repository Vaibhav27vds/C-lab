// Write a menu driven program to implement circular queue operations
// such as Insert, Delete,Display, whether queue is empty etc by using Linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue() {
    int item;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Insert the element in queue: ");
    scanf("%d", &item);
    newNode->data = item;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    Node *temp = front;
    printf("Element deleted from queue is: %d\n", front->data);
    front = front->next;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void isEmpty() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert element to queue\n");
        printf("2.Delete element from queue\n");
        printf("3.Display all elements of queue\n");
        printf("4.Check if queue is empty\n");
        printf("5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
