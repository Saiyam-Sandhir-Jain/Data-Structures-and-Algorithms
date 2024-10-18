#include <stdio.h>

// Horner's Rule by taking elements from 0th index to the last index
int hornerRulePolynomialEvalutation1(int coeffs[], int degree, int x) {
    int result = coeffs[0];

    for (int i = 1; i <= degree; ++i) {
        result = result * x + coeffs[i];
    }

    return result;
}

// Horner's Rule by taking elements from the last index to the 0th index
int hornerRulePolynomialEvaluation2(int coeffs[], int degree, int x) {
    int result = coeffs[degree];
    int tempMultiplier = x;

    for (int i = degree - 1; i >= 0; --i) {
        result = result + coeffs[i] * tempMultiplier;
        tempMultiplier *= x;
    }

    return result;
}

int main() {
    int coeffs[] = { 1, 2, 3, 4, 5 };
    int degree = sizeof(coeffs)/sizeof(int) - 1;
    int x = 10;

    printf("%d", hornerRulePolynomialEvalutation1(coeffs, degree, x));
    printf("\n%d", hornerRulePolynomialEvaluation2(coeffs, degree, x));
    return 0;
}