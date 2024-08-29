#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode; 
}

void display(Node *head){
    while( head != NULL){
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("END");
}

int main(){
    struct Node* head = NULL;
    insert(&head,10);
    insert(&head,20);

    display(head);
}