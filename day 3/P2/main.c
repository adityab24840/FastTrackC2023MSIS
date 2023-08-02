#include <stdio.h>

// Function to generate Fibonacci + 1 series
void fibonacciPlusOne(int n) {
    int first = 0, second = 0, third = 1, next;

    printf("Fibonacci + 1 Series:\n");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second + third;
            first = second;
            second = third;
            third = next ;
        }
        printf("%d ", next);
    }

    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    fibonacciPlusOne(terms);

    return 0;
}
