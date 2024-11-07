#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an element in the list
int searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; // Element found
        }
        temp = temp->next;
    }
    return 0; // Element not found
}

// Function to sort the list in ascending order
void sortList(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* i = *head;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

// Function to reverse the list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* temp = *head;
    Node* next = NULL;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Sort List\n");
        printf("4. Reverse List\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                if (searchElement(head, key)) {
                    printf("Element found in the list.\n");
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 3:
                sortList(&head);
                printf("List sorted in ascending order.\n");
                break;
            case 4:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}