// Write a C program, which will print two digit numbers whose sum of both digit is nine. e.g. 18,27,36......
#include <stdio.h>

// Function to print two-digit numbers whose sum of digits is nine
void printNumbersWithSumNine() {
    printf("Two-digit numbers whose sum of digits is nine:\n");

    for (int i = 10; i <= ; i++) {
        int tens_digit = i / 10;
        int ones_digit = i % 10;

        if (tens_digit + ones_digit == 9) {
            printf("%d\n", i);
        }
    }
}

int main() {
    printNumbersWithSumNine();
    return 0;
}
