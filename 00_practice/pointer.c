#include <stdio.h>

int swap(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("After swap\n");
    printf("a=%d, b=%d\n", x,y);
    return 0;
}

 int main(){
    int a=10;
    int b=20;

    int *p1 = &a;

    int **q = &p1;

    int *p2 = &b;

    printf("Before swap\n");
    printf("a=%d, b=%d\n", a, b);
    printf("Print using pointer\n");
    printf("a=%x, b=%x\n", p1, p2);
    printf("p1 has the address of a so on printing only p1 it gives %x which is the address of a\n", p1);
    printf("p2 has the address of b so on printing only p2 it gives %x which is the address of b\n", p2);

    printf("when we print *p we get : %d", *p1);

    printf(" printing **q : %d", **q);

    swap(a,b); 

    printf("a=%d and b=%d", a,b);
 }