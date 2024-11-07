#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Polynomial;

Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void addTerm(Polynomial* poly, int coeff, int power) {
    Node* newNode = createNode(coeff, power);
    if (poly->head == NULL || power > poly->head->power) {
        newNode->next = poly->head;
        poly->head = newNode;
    } else {
        Node* current = poly->head;
        while (current->next != NULL && current->next->power > power) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display(Polynomial *p){
    Node *temp = p->head;
    while (temp != NULL)
    {
        printf("%dx^%d + ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    Polynomial p = {NULL};  // 5x^5 + 10x^3 + 6x^2 + 3
    addTerm(&p, 5, 5);
    addTerm(&p, 10, 3);
    addTerm(&p, 6, 2);
    addTerm(&p, 3, 0);
    display(&p);
    return 0;
}