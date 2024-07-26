#include<stdio.h>

 typedef struct {
    float real;
    float imaginary;
}complex;



complex callByValue(complex a, complex b){
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}
complex callByReference( const complex *a,  const complex *b){
    complex *result;
    result->real = a->real + b->real - a->imaginary + b->imaginary;
    result->imaginary = a->real + b->imaginary + a->imaginary + b->real;
    return *result;

}

complex displayResult(complex result){
    printf("Complex number is: %.2f + %.2fi\n", result.real, result.imaginary);
}

int main() {
    complex a,b,result;
    printf("Enter the real part and imaginary part of the first complex number\n");
    scanf("%f %f", &a.real, &a.imaginary);
    printf("Enter the real part and imaginary part of the second complex number\n");
    scanf("%f %f", &b.imaginary , &b.imaginary);
    int value;
    printf("To add press `1` to multiply press `2` \n");
    scanf("%d", &value);
    switch (value){
    case 1: 
    result = callByValue(a, b);
    displayResult(result);
        break;
    case 2: 
    result = callByReference(&a,&b);
    break;
    default:
    printf("Invalid input. Try entering something else");
        break;
    }
    return 0; 
    }