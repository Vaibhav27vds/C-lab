#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    printf("Insert the element in queue: ");
    scanf("%d", &item);
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is: %d\n", queue[front]);
    front++;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void isEmpty() {
    if (front == -1 || front > rear) {
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
                printf("Wrong choice\n");
        }
    }
    return 0;
}