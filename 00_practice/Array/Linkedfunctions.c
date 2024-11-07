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

void printPolynomial(Polynomial* poly) {
    Node* current = poly->head;
    int first = 1;
    while (current != NULL) {
        if (first) {
            first = 0;
        } else {
            printf(" + ");
        }
        if (current->power == 0) {
            printf("%d", current->coeff);
        } else if (current->power == 1) {
            printf("%dx", current->coeff);
        } else {
            printf("%dx^%d", current->coeff, current->power);
        }
        current = current->next;
    }
    printf("\n");
}

Polynomial addPolynomials(Polynomial* p1, Polynomial* p2) {
    Polynomial result = {NULL};
    Node *t1 = p1->head, *t2 = p2->head;

    while (t1 != NULL && t2 != NULL) {
        if (t1->power > t2->power) {
            addTerm(&result, t1->coeff, t1->power);
            t1 = t1->next;
        } else if (t1->power < t2->power) {
            addTerm(&result, t2->coeff, t2->power);
            t2 = t2->next;
        } else {
            addTerm(&result, t1->coeff + t2->coeff, t1->power);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL) {
        addTerm(&result, t1->coeff, t1->power);
        t1 = t1->next;
    }

    while (t2 != NULL) {
        addTerm(&result, t2->coeff, t2->power);
        t2 = t2->next;
    }

    return result;
}

Polynomial multiplyPolynomials(Polynomial* p1, Polynomial* p2) {
    Polynomial result = {NULL};
    Node *t1 = p1->head;

    while (t1 != NULL) {
        Node *t2 = p2->head;
        while (t2 != NULL) {
            int coeff = t1->coeff * t2->coeff;
            int power = t1->power + t2->power;
            
            Node *existing = result.head;
            while (existing != NULL) {
                if (existing->power == power) {
                    existing->coeff += coeff;
                    break;
                }
                existing = existing->next;
            }
            
            if (existing == NULL) {
                addTerm(&result, coeff, power);
            }
            
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    return result;
}

int main() {
    Polynomial p1 = {NULL}, p2 = {NULL};

    addTerm(&p1, 2, 3);
    addTerm(&p1, 3, 1);
    addTerm(&p1, 1, 0);

    addTerm(&p2, 1, 2);
    addTerm(&p2, 2, 0);

    printf("Polynomial 1: ");
    printPolynomial(&p1);
    printf("Polynomial 2: ");
    printPolynomial(&p2);

    Polynomial sum = addPolynomials(&p1, &p2);
    printf("Sum: ");
    printPolynomial(&sum);

    Polynomial product = multiplyPolynomials(&p1, &p2);
    printf("Product: ");
    printPolynomial(&product);

    return 0;
}