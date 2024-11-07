#include <stdio.h>
void add_polynomials(int poly1[], int poly2[], int result[], int n1, int n2) {
    int max_degree = (n1 > n2) ? n1 : n2;
    for (int i = 0; i < max_degree; i++) {
        result[i] = 0;
    }
    for (int i = 0; i < n1; i++) {
        result[i] += poly1[i];
    }
    for (int i = 0; i < n2; i++) {
        result[i] += poly2[i];
    }
}
void print_polynomial(int poly[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != size - 1 && poly[i] > 0) {
                printf(" + ");
            }
            if (i == 0) {
                printf("%d", poly[i]);
            } else if (i == 1) {
                printf("%dx", poly[i]);
            } else {
                printf("%dx^%d", poly[i], i);
            }
        }
    }
    printf("\n");
}
int main() {
    int n1, n2;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &n1);
    int poly1[n1 + 1];
    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = 0; i <= n1; i++) {
        scanf("%d", &poly1[i]);
    }
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n2);
    int poly2[n2 + 1];
    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = 0; i <= n2; i++) {
        scanf("%d", &poly2[i]);
    }
    int max_degree = (n1 > n2) ? n1 : n2;
    int result[max_degree + 1];
    add_polynomials(poly1, poly2, result, n1 + 1, n2 + 1);
    printf("The resultant polynomial is: ");
    print_polynomial(result, max_degree + 1);
    return 0;
}