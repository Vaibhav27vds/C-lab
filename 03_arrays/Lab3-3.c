/*3.Write a program to perform the following operations on a given square matrix:
i. Find the no.of nonzero elements
ii. Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/
#include <stdio.h>

int zeros(int arr[][10], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

void utm(int arr[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < j)
            {
                printf("%d ", arr[i][j]);
            }
            else
            {
                printf("  "); // To keep formatting aligned
            }
        }
        printf("\n");
    }
}

void diag_elements(int arr[][10], int n, int m)
{
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j - 1 || i == j + 1)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main()
{
    int n, m, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of cols: ");
    scanf("%d", &m);
    int arr[10][10];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter element A%d%d: ", i + 1, j + 1); // Displaying 1-based index for user
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int a;
    printf("Enter the operation you want:\n");
    printf("1. Find the number of nonzero elements\n");
    printf("2. Display upper triangular matrix\n");
    printf("3. Display the elements just above and below the main diagonal\n");
    scanf("%d", &a);

    if (a == 1)
    {
        printf("The number of nonzero elements: %d\n", zeros(arr, n, m));
    }
    else if (a == 2)
    {
        printf("The Upper Triangular Matrix:\n");
        utm(arr, n, m);
    }
    else if (a == 3)
    {
        diag_elements(arr, n, m);
    }
    else
    {
        printf("Invalid option.\n");
    }

    return 0;
}