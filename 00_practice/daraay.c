#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(arr));
    for(int i=0; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    //realloc
    int new_size;
    printf("\nEnter the new size of the array: ");
    scanf("%d", &new_size);
    arr = (int *)realloc(arr, new_size*sizeof(arr));
    for(int i=n; i<new_size; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for(int i=0; i<new_size; i++){
        printf("%d ", arr[i]);
    }


    // using calloc 

    int *carr = (int *)calloc(n, sizeof(arr));

    for(int i = 0; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &carr[i]);
    }

    printf("\nThe elements of the calloc array are: ");
    for(int i=0; i<n; i++){
        printf("%d ", carr[i]);
    }

    free(arr);
    free(carr);

    return 0;
}