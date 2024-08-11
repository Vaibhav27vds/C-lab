#include <stdio.h>

void insert(int arr[], int *n, int element) {
    int i;
    for (i = *n - 1; i >= 0 && arr[i] > element; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = element;
    *n = *n + 1;
}

int main() {
    int n;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
    int arr[n + 1];
    
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int element;
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    
    insert(arr, &n, element);

    printf("The array after insertion is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
