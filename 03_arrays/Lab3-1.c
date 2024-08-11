#include <stdio.h>

void insert(int arr[], int *length, int target, int position) {
    if (position < 0 || position > *length) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *length; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = target;
    (*length)++;

    printf("The array after insertion is: ");
    for (int i = 0; i < *length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete(int arr[], int *length, int position) {
    if (position < 0 || position >= *length) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;

    printf("The array after deletion is: ");
    for (int i = 0; i < *length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linear_search(int arr[], int length, int target) {
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == target) {
            printf("Element %d found at position %d\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", target);
    }
}


void traverse(int arr[], int length) {
    printf("The array elements are: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void lengthOfArray(int x){
    printf("The size of the following array is : %d\n", x);
}

int main() {
    int n, value, target, position;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 1];
    int length = n;

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nChoose the operation to perform on the provided array\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Length\n");
        printf("6. Exit\n");

        scanf("%d", &value);

        switch (value) {
            case 1:
                printf("Enter the position to insert the element in the array: ");
                scanf("%d", &position);
                printf("Enter the element to be added to the array: ");
                scanf("%d", &target);
                insert(arr, &length, target, position);
                break;

            case 2:
                printf("Enter the position to delete the element from the array: ");
                scanf("%d", &position);
                delete(arr, &length, position);
                break;

            case 3:
                printf("Enter the element to be searched in the array: ");
                scanf("%d", &target);
                linear_search(arr, length, target);
                break;

            case 4:
                traverse(arr, length);
                break;

            case 5:
             int length;
            length = sizeof(arr)/sizeof(arr[0]);
            lengthOfArray(length);
            break;

            case 6: 
            printf("Exiting the program...\n");
            return 0;
            break;


            default:
                printf("Invalid input!\n");
                break;
        }
    }

    return 0;
}
