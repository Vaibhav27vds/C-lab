#include<stdio.h>

int primeOrNot(int num){
    if(num <=1){
        return 0;
    }
    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            return 0;
    }
}
return 1;
}

int main(){
    int a;
    printf("Enter a number \n");
    scanf("%d", &a);
    int output = primeOrNot(a);
    if( output == 1){
        printf("It is a Prime number \n");
    }
    else{
        printf("It is not a Prime number \n");
    }
    return 0;
}