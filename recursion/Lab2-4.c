//Write a C program to check whether a number is palindrome or not using recursion

#include<stdio.h>

int reverseNumber(int num, int rev){
    if(num == 0){
        return rev;
    }
    else{
        rev = rev * 10 + (num % 10);
        return reverseNumber(num / 10, rev);
}
}

int isPalindrome(int num){
    if(num == reverseNumber(num, 0)){
        return 1;
    }
    else{
        return 0;
    }
}


int main () {
    int num; 
    printf("Enter a number: ");
    scanf("%d", &num);
    if(isPalindrome(num)){
        printf("%d is a palindrome number.\n", num);
        }
        else{
            printf("%d is not a palindrome number.\n", num);
            }
            return 0;
}