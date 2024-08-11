#include<stdio.h>
#include<stdlib.h>

int main(){
    int row,column;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    int **arr = (int **)malloc(row*sizeof(int *));
    for(int i=0; i<=row; i++){
        arr[i]= (int *)malloc(column*sizeof(int));
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Enter the element at position (%d,%d): ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The elements of the array are: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<row; i++){
        free(arr[i]);
    }
    free(arr);

    int **arr2 = (int **)calloc(row,sizeof(int *));
    for(int i=0; i<row; i++){
        arr2[i]= (int *)calloc(column, sizeof(int));
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("Enter the element at position (%d,%d): ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("The elements of the calloc array are: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<row; i++){
        free(arr2[i]);
    }
    free(arr2);
    

    int row1, column1;
    printf("Enter the new row of array");
    scanf("%d", &row1);
    printf("Enter the new column of array");
    scanf("%d", &column1);

    // realloc 

    arr2 = (int **)realloc(arr, row1*sizeof(int *));
    for(int i=row; i<row1; i++){
        arr[i]= (int *)malloc(column1*sizeof(int));
    }

    for(int i=0; i<row1; i++){
        for(int j=0; j<column1; j++){
            printf("Enter the element at position (%d,%d): ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("The elements of the realloc array are: \n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<column1; j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<row1; i++){
        free(arr2[i]);
    }
    free(arr2);

    return 0;
}