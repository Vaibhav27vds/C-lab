#include <stdio.h>

int addTwoNumbers(int a, int b){
    return a + b;
}
int main(){
    int num1, num2;
    int sum = 0;
printf("Enter the first number \n ");
scanf("%d", &num1);
printf("Enter the second number \n");
scanf("%d", &num2);

sum = addTwoNumbers(num1,num2);
printf("The sum of the two numbers is %d", sum);
return 0;
}

