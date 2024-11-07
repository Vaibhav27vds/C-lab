#include <stdio.h>
#define MAX_DEGREE 100

typedef struct {
    int coeffs[MAX_DEGREE + 1];  // coefficients
    int degree;                  // degree of polynomial
} Polynomial;

void initPolynomial(Polynomial *poly, int degree) {
    poly->degree = degree;
    for (int i = 0; i <= degree; i++) {
        poly->coeffs[i] = 0;
    }
}

void setCoefficient(Polynomial *poly, int power, int coeff) {
    if (power <= poly->degree) {
        poly->coeffs[power] = coeff;
    }
}

void display(Polynomial *poly, int degree){
    for (int i = poly->degree; i >= 0; i--) {
        printf("%dx^%d + ", poly->coeffs[i], i);
    }
    printf("\n");
}

// Example usage
int main() {
    Polynomial p, p1;
    initPolynomial(&p, 6);  // 5x^5 + 10x^3 + 6x^2 + 3
    setCoefficient(&p, 5, 3);
    setCoefficient(&p, 4, 32);
    setCoefficient(&p, 3, 10);
    setCoefficient(&p, 2, 6);
    setCoefficient(&p, 1, 0);
    initPolynomial(&p1, 3);
    setCoefficient(&p1, 3, 3);
    setCoefficient(&p1, 2, 2);
    setCoefficient(&p1, 1, 1);
    setCoefficient(&p1, 0, 0);
    display(&p, 5);
    display(&p1, 3);
    return 0;
}