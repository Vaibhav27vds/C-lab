#include <stdio.h>

// Function to reverse the array
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap the elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // Move the pointers towards the center
        start++;
        end--;
    }
}

int main() {
    int size;

    // Ask the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare the array with the user-defined size
    int arr[size];

    // Ask the user to input the elements of the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the function to reverse the array
    reverseArray(arr, size);

    // Print the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
