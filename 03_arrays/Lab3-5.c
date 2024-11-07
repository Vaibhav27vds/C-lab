/*WAP to perform transpose of a given sparse matrix in 3-tuple format*/
#include <stdio.h>
void Tuple(int trans[][10], int n1, int n2)
{
    // Checking it is a sparse matrix or not
    int i, j;

    int zero = 0, nonzero = 0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (trans[i][j] == 0)
            {
                zero++;
            }
            else
            {
                nonzero++;
            }
        }
    }
    printf("Number of zeros:%d\n", zero);
    printf("Number of nonzeros:%d\n", nonzero);
    if (nonzero > zero)
    {
        printf("The Entered matrix is not a sparse matrix\n ");
    }
    else
    {
        printf("The Entered matrix is a sparse matrix\n ");
        int S[i][3], k = 0;
        for (i = 0; i < n1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                if (trans[i][j] != 0)
                {
                    S[k][0] = i;
                    S[k][1] = j;
                    S[k][2] = trans[i][j];
                    k++;
                }
            }
        }
        // printing the 3 tuple representation
        printf(" 3-tuple format\n");

        for (i = 0; i < nonzero; i++)
        {
            printf("\n");
            for (j = 0; j < 3; j++)
            {
                printf("%d ", S[i][j]);
            }
        }
    }
}

int main()
{
    int n1, n2, i, j, check = 1;
    printf("Enter a matrix:\n");
    printf("Enter number of row:");
    scanf("%d", &n1);
    printf("Enter number of cols:");
    scanf("%d", &n2);
    int mat[n1][n2];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("Enter element a[%d][%d]", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
    // main Matrix
    printf("The main Matrix\n");

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    int trans[10][10];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }
    printf("Transpose of matrix:\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }
    Tuple(trans,n1,n2);


    return 0;
}