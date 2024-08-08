#include <stdio.h>

// function prototype
void reverse(int num) 
{
    // if num is 0, exit the function
    if (num==0)
        return;

    // print the last digit of the number
    printf("%d",num%10);

    // recursive function to call reverse without the last digit
    reverse(num/10);
}

// main function
int main() 
{
    int n;

    // user input
    printf("Enter a positive number: ");
    scanf("%d", &n);

    // Check if the number is negative
    if (n<0) 
    {
        printf("Enter a positive number");
        return 1; 
    }

    // print the reverse
    printf("Reverse of %d is: ", n);
    reverse(n); // call the reverse function

    return 0; 
}