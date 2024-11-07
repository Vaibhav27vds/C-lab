#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void Enqueue(Node *front, Node *rear, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void Dequeue(Node *front, Node *rear){
    Node *temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
}

void Display(Node *front){
    Node *temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node *front = NULL;
    Node *rear = NULL;
    int choice;
    int value;
    while (1)
    {
        printf("Enter your choice\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("ENter the value");
        scanf("%d", &value);
        Enqueue(front, rear, value);
            break;
        case 2:
            Dequeue(front, rear);
            break;
        case 3:
            Display(front);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}