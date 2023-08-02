//Write a menu driven program to display the mathematical functions like square root, natural log, log10x, power(x,n), Cos(x). (use math.h)

#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double x, result;

    do {
        printf("Mathematical Functions Menu:\n");
        printf("1. Square Root\n");
        printf("2. Natural Logarithm\n");
        printf("3. Logarithm Base 10\n");
        printf("4. Power (x^n)\n");
        printf("5. Cosine (Cos(x))\n");
        printf("0. Exit\n");
        printf("Enter your choice (0-5): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter a number: ");
        scanf("%lf", &x);

        switch (choice) {
            case 1: result = sqrt(x);
                    break;

            case 2: result = log(x);
                    break;

            case 3: result = log10(x);
                    break;

            case 4: printf("Enter the exponent (n): ");
                        int n;
                    scanf("%d", &n);
                    result = pow(x, n);
                    break;

            case 5: result = cos(x);
                    break;

            default: printf("Invalid choice. Please try again.\n");
                    continue;
        }

        printf("Result: %.2lf\n\n", result);
    } while (choice != 0);

    return 0;
}
