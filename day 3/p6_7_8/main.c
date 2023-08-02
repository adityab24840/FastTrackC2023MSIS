#include <stdio.h>

// Recursive function to calculate power of a number
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1.0 / (base * power(base, -exponent - 1));
    }
}

// Recursive function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Recursive function to evaluate F(x) = x + x^3/3! + x^5/5! + x^7/7! + ...
double evaluateSeries(int n, double x) {
    if (n == 0) {
        return x;
    } else {
        return power(x, 2 * n - 1) / factorial(2 * n - 1) + evaluateSeries(n - 1, x);
    }
}

// Driver function to call recursive functions
int main() {
    int choice;
    double base, result;
    int exponent, n;

    printf("Choose an operation:\n");
    printf("1. Calculate power of a number\n");
    printf("2. Calculate factorial\n");
    printf("3. Evaluate the series\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the base number: ");
            scanf("%lf", &base);

            printf("Enter the exponent: ");
            scanf("%d", &exponent);

            result = power(base, exponent);
            printf("Power of %lf raised to %d is: %lf\n", base, exponent, result);
            break;

        case 2:
            printf("Enter a number: ");
            scanf("%d", &n);

            result = factorial(n);
            printf("Factorial of %d is: %lf\n", n, result);
            break;

        case 3:
            printf("Enter the value of n for the series: ");
            scanf("%d", &n);

            printf("Enter the base number: ");
            scanf("%lf", &base);

            result = evaluateSeries(n, base);
            printf("Value of F(%lf) for n = %d is: %lf\n", base, n, result);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
