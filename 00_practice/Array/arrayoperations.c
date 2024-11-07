#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 100

typedef struct {
    int coeffs[MAX_DEGREE + 1];
    int degree;
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

void printPolynomial(Polynomial *poly) {
    for (int i = poly->degree; i >= 0; i--) {
        if (poly->coeffs[i] != 0) {
            if (i != poly->degree) {
                printf(" + ");
            }
            if (i == 0) {
                printf("%d", poly->coeffs[i]);
            } else if (i == 1) {
                printf("%dx", poly->coeffs[i]);
            } else {
                printf("%dx^%d", poly->coeffs[i], i);
            }
        }
    }
    printf("\n");
}

Polynomial addPolynomials(Polynomial *p1, Polynomial *p2) {
    Polynomial result;
    int maxDegree = (p1->degree > p2->degree) ? p1->degree : p2->degree;
    initPolynomial(&result, maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        int sum = 0;
        if (i <= p1->degree) sum += p1->coeffs[i];
        if (i <= p2->degree) sum += p2->coeffs[i];
        result.coeffs[i] = sum;
    }

    return result;
}

Polynomial multiplyPolynomials(Polynomial *p1, Polynomial *p2) {
    Polynomial result;
    int resultDegree = p1->degree + p2->degree;
    initPolynomial(&result, resultDegree);

    for (int i = 0; i <= p1->degree; i++) {
        for (int j = 0; j <= p2->degree; j++) {
            result.coeffs[i + j] += p1->coeffs[i] * p2->coeffs[j];
        }
    }

    return result;
}

int main() {
    Polynomial p1, p2, sum, product;

    initPolynomial(&p1, 3);
    setCoefficient(&p1, 3, 2);
    setCoefficient(&p1, 1, 3);
    setCoefficient(&p1, 0, 1);

    initPolynomial(&p2, 2);
    setCoefficient(&p2, 2, 1);
    setCoefficient(&p2, 0, 2);

    printf("Polynomial 1: ");
    printPolynomial(&p1);
    printf("Polynomial 2: ");
    printPolynomial(&p2);

    sum = addPolynomials(&p1, &p2);
    printf("Sum: ");
    printPolynomial(&sum);

    product = multiplyPolynomials(&p1, &p2);
    printf("Product: ");
    printPolynomial(&product);

    return 0;
}