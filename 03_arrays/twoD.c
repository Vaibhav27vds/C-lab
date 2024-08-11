#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *rows, int *columns, int targetRow, int targetColumn, int element) {
    if (targetRow < 0 || targetRow >= *rows || targetColumn < 0 || targetColumn > *columns) {
        printf("Invalid position!\n");
        return;
    }

    // Expand the column size by 1
    *columns += 1;

    for (int i = 0; i < *rows; i++) {
        arr[i] = realloc(arr[i], (*columns) * sizeof(int));
    }

    // Shift elements to the right in the row of insertion
    for (int j = *columns - 1; j > targetColumn; j--) {
        arr[targetRow][j] = arr[targetRow][j - 1];
    }

    // Insert the element
    arr[targetRow][targetColumn] = element;

    printf("The array after insertion is:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void traverse(int **arr, int rows, int columns) {
    printf("The array elements are:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, columns, targetRow, targetColumn, element;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Allocate memory for the 2D array
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(columns * sizeof(int));
    }

    // Input array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    while (1) {
        int choice;
        printf("\nOptions for array:\n");
        printf("1. Insert\n2. Traverse\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the row to insert the element: ");
                scanf("%d", &targetRow);
                printf("Enter the column to insert the element: ");
                scanf("%d", &targetColumn);
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insert(arr, &rows, &columns, targetRow - 1, targetColumn - 1, element);
                break;
            case 2:
                traverse(arr, rows, columns);
                break;
            case 3:
                for (int i = 0; i < rows; i++) {
                    free(arr[i]);
                }
                free(arr);
                return 0;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}
