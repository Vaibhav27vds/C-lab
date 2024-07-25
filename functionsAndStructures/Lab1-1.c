#include <stdio.h>

void callByValue(int a, int b);
void callByAddress(int *a, int *b);
int main(){
int num1, num2;
printf("Enter the first number \n ");
scanf("%d", &num1);
printf("Enter the second number \n");
scanf("%d", &num2);

printf("Enter `1` to call by value and `2` to call by address \n ");

int value;
scanf("%d", &value);

switch (value)
{
case 1 :
    callByValue(num1,num2);
    break;

case 2 :
callByAddress(&num1,&num2);
break;

default:
printf("Choose a valid option");
    break;
}

return 0;

}

void callByValue(int a, int b){
    if(a>b){
        printf("Call By Value \n");
        printf("%d is greater than %d", a, b);
    }
    if(b>a){ 
        printf("Call By Value \n");
        printf("%d is greater than %d", b,a);
    }
    if(a==b){
        printf("Call By Value \n");
        printf("%d is equal to %d", b,a);
    }
}

void callByAddress(int *a, int *b){
    if(*a>*b){
        printf("Call By address \n");
        printf("%d is greater than %d", *a, *b);
    }
    if(*b>*a){ 
        printf("Call By address \n");
        printf("%d is greater than %d", *b,*a);
    }
    if(*a==*b){
        printf("Call By address \n");
        printf("%d is equal to %d", *b,*a);
    }
}
