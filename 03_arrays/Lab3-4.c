/*WAP to represent a given sparse matrix in 3-tuple format using 2-D array*/
#include<stdio.h>
int main(){
    int n1,n2;
    printf("Enter the number of rows :");
    scanf("%d",&n1);
    printf("Enter the number of cols :");
    scanf("%d",&n2);
    int arr[n1][n2];
    int i , j ;
    //input in the matrix
    for ( i = 0; i <n1; i++)
    {
       for ( j = 0; j <n2; j++)
       {
         printf("Element arr[%d][%d]:",i,j);
         scanf("%d",&arr[i][j]);
       }
       
    }
    //output matrix 
    for ( i = 0; i < n1; i++)
    {
        for ( j = 0; j <n2; j++)
        {
            printf("%d\t",arr[i][j]);

        }
        printf("\n");

    }
    //Checking it is a sparse matrix or not 
    int zero = 0,nonzero= 0   ;
    for ( i = 0; i <n1; i++)
    {
        for ( j = 0; j <n2; j++)
        {
            if (arr[i][j]==0)
            {
                zero++; 
            }
            else
            {
                nonzero++;
            }
            
        }
        
    }
    printf("Number of zeros:%d\n",zero);
    printf("Number of nonzeros:%d\n",nonzero);
    if (nonzero>zero)
    {
        printf("The Entered matrix is not a sparse matrix\n ");

    }
    else
    {
        printf("The Entered matrix is a sparse matrix\n ");
        int S[i][3],k=0;
        for ( i = 0; i <n1; i++)
        {
            for ( j = 0; j <n2; j++)
            {
                if (arr[i][j]!= 0 )
                {
                    S[k][0] = i ;
                    S[k][1] = j ;
                    S[k][2] = arr[i][j];
                    k++;

                }
                
            }
            
        }
        //printing the 3 tuple representation
        printf(" 3-tuple format\n");
        
        for ( i = 0; i < nonzero; i++)
        {
            printf("\n");
            for ( j = 0; j <3; j++)
            {
                printf("%d ",S[i][j]);
            }
            
        }
        
        
    }
    
    
return 0 ;
}   