#include <stdio.h>

int fibonaci(int num){
    if(num == 0 || num == 1){
        return num;
}
else{
    return fibonaci(num-1) + fibonaci(num-2);
}
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Fibonacci number at position %d is %d", num, fibonaci(num));
}