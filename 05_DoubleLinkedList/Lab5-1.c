// WAP to create a double linked list of n nodes and display the linked list by using suitable
// user defined functions for create and display operations.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void insertAtStart(Node *head, Node *tail){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

    void insertAtEnd(Node *head, Node*tail){
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display(Node *head){
        Node *temp = head;
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }

    int main(){
        Node *head = NULL;
        Node *tail = NULL;
        int n;
        while(1){
        printf("Enter your choice : \n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &n);
        switch(n){
            case 1:
                insertAtStart(head, tail);
                break;
            case 2:
                insertAtEnd(head, tail);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
        }
    }