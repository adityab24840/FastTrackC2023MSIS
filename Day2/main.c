#include <stdio.h>
#include <math.h>

// Function to calculate sum of digits of a number
int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to reverse a number
int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Function to count occurrences of a digit in a number
int count_digit_occurrences(int num, int digit) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == digit) {
            count++;
        }
        num /= 10;
    }
    return count;
}

// Function to check if a number is palindrome
int is_palindrome(int num) {
    int original = num;
    int reversed = reverse_number(num);
    return original == reversed;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to generate first N prime numbers
void generate_primes(int N) {
    printf("First %d prime numbers: ", N);
    int count = 0, num = 2;
    while (count < N) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

// Function to calculate sum of the series 1 + 11 + 111 + ... + 111 up to n
int sum_of_series(int n) {
    int sum = 0, term = 1;
    for (int i = 0; i < n; i++) {
        sum += term;
        term = term * 10 + 1;
    }
    return sum;
}

// Function to check if a number is an Armstrong number
int is_armstrong(int num) {
    int original = num, sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }
    return original == sum;
}

// Function to check if a pair of numbers is amicable
int are_amicable(int num1, int num2) {
    int sum_divisors_num1 = 0, sum_divisors_num2 = 0;

    for (int i = 1; i <= num1 / 2; i++) {
        if (num1 % i == 0) {
            sum_divisors_num1 += i;
        }
    }

    for (int i = 1; i <= num2 / 2; i++) {
        if (num2 % i == 0) {
            sum_divisors_num2 += i;
        }
    }

    return sum_divisors_num1 == num2 && sum_divisors_num2 == num1;
}

// Function to calculate total charge amount for electricity usage
double calculate_electricity_charge(int units) {
    double charge = 0;
    if (units <= 200) {
        charge = units * 5;
    } else if (units <= 300) {
        charge = 200 * 5 + (units - 200) * 7;
    } else {
        charge = 200 * 5 + 100 * 7 + (units - 300) * 10;
    }
    return charge;
}

int main() {
    int choice;

    do {
        printf("\n-----------------------------\n");
        printf("1. Sum of Digits\n");
        printf("2. Reverse Number\n");
        printf("3. Count Digit Occurrences\n");
        printf("4. Check Palindrome\n");
        printf("5. Generate First N Prime Numbers\n");
        printf("6. Sum of Series\n");
        printf("7. Check Armstrong Number\n");
        printf("8. Check Amicable Numbers\n");
        printf("9. Calculate Electricity Charge\n");
        printf("0. Exit\n");
        printf("-----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter a 5-digit number: ");
                scanf("%d", &num);
                if (num >= 10000 && num <= 99999) {
                    int sum = sum_of_digits(num);
                    printf("Sum of digits: %d\n", sum);
                } else {
                    printf("Invalid input. Please enter a 5-digit number.\n");
                }
                break;
            }
            case 2: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                int reversed = reverse_number(num);
                printf("Reversed number: %d\n", reversed);
                break;
            }
            case 3: {
                int num, digit;
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Enter a digit to count: ");
                scanf("%d", &digit);
                int count = count_digit_occurrences(num, digit);
                printf("Occurrences of digit %d: %d\n", digit, count);
                break;
            }
            case 4: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                if (is_palindrome(num)) {
                    printf("%d is a palindrome.\n", num);
                } else {
                    printf("%d is not a palindrome.\n", num);
                }
                break;
            }
            case 5: {
                int N;
                printf("Enter the value of N: ");
                scanf("%d", &N);
                generate_primes(N);
                break;
            }
            case 6: {
                int n;
                printf("Enter the value of n: ");
                scanf("%d", &n);
                int sum = sum_of_series(n);
                printf("Sum of the series: %d\n", sum);
                break;
            }
            case 7: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                if (is_armstrong(num)) {
                    printf("%d is an Armstrong number.\n", num);
                } else {
                    printf("%d is not an Armstrong number.\n", num);
                }
                break;
            }
            case 8: {
                int num1, num2;
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (are_amicable(num1, num2)) {
                    printf("%d and %d are amicable numbers.\n", num1, num2);
                } else {
                    printf("%d and %d are not amicable numbers.\n", num1, num2);
                }
                break;
            }
            case 9: {
                int units;
                printf("Enter number of units consumed: ");
                scanf("%d", &units);
                double charge = calculate_electricity_charge(units);
                printf("Total charge amount: %.2lf\n", charge);
                break;
            }
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
