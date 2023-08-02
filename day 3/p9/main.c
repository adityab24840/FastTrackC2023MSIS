// Concatenate two integer values using macros

#include <stdio.h>

#define CONCATENATE(x, y) (x * 10 + y)

int main() {
    int num1, num2;

    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    int concatenated = CONCATENATE(num1, num2);

    printf("Concatenated value: %d\n", concatenated);

    return 0;
}

