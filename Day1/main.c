#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert uppercase to lowercase
void convert_upper_to_lower() {
    char uppercase;
    printf("Enter an uppercase character: ");
    scanf(" %c", &uppercase);

    if (uppercase >= 'A' && uppercase <= 'Z') {
        char lowercase = uppercase + 32;
        printf("Lowercase equivalent: %c\n", lowercase);
    } else {
        printf("Invalid input. Please enter an uppercase character.\n");
    }
}

// Function to calculate area of circle
void calculate_circle_area() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    if (radius >= 0) {
        float area = 3.14159 * radius * radius;
        printf("Area of the circle: %.2f\n", area);
    } else {
        printf("Invalid input. Radius cannot be negative.\n");
    }
}

// Function to find number of characters between two inputs
void find_characters_between() {
    char char1, char2;
    printf("Enter two characters: ");
    scanf(" %c %c", &char1, &char2);

    if (char1 < char2) {
        int count = char2 - char1 - 1;
        printf("Number of characters between %c and %c: %d\n", char1, char2, count);
    } else {
        printf("Invalid input. The second character should come after the first character.\n");
    }
}

// Function to convert Celsius to Fahrenheit
void convert_celsius_to_fahrenheit() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
}

// Function to check even or odd
void check_even_or_odd() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }
}

// Function to check leap year
void check_leap_year() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
}

// Function to find power of 2^N using left shift operator
void find_power_of_two() {
    int n;
    printf("Enter a value for N: ");
    scanf("%d", &n);

    if (n >= 0) {
        int result = 1 << n;
        printf("2^%d = %d\n", n, result);
    } else {
        printf("Invalid input. N should be non-negative.\n");
    }
}

// Function to check character or integer
void check_character_or_integer() {
    char input;
    printf("Enter a character or integer (0-9): ");
    scanf(" %c", &input);

    if (input >= '0' && input <= '9') {
        printf("Input is an integer: %c\n", input);
    } else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
        printf("Input is a character: %c\n", input);
    } else {
        printf("Invalid input.\n");
    }
}

// Function to generate random numbers and find sum
void generate_random_numbers_and_sum() {
    int num1 = rand() % 100; // Generate random number between 0 and 99
    int num2 = rand() % 100;

    printf("Random Number 1: %d\n", num1);
    printf("Random Number 2: %d\n", num2);
    printf("Sum: %d\n", num1 + num2);
}

int main() {
    int choice;

    srand(time(NULL)); // Seed the random number generator

    do {
        printf("\n-----------------------------\n");
        printf("1. Convert Uppercase to Lowercase\n");
        printf("2. Calculate Area of Circle\n");
        printf("3. Find Characters Between Two Inputs\n");
        printf("4. Convert Celsius to Fahrenheit\n");
        printf("5. Check Even or Odd\n");
        printf("6. Check Leap Year\n");
        printf("7. Find Power of 2^N\n");
        printf("8. Check Character or Integer\n");
        printf("9. Generate Random Numbers and Find Sum\n");
        printf("0. Exit\n");
        printf("-----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_upper_to_lower();
                break;
            case 2:
                calculate_circle_area();
                break;
            case 3:
                find_characters_between();
                break;
            case 4:
                convert_celsius_to_fahrenheit();
                break;
            case 5:
                check_even_or_odd();
                break;
            case 6:
                check_leap_year();
                break;
            case 7:
                find_power_of_two();
                break;
            case 8:
                check_character_or_integer();
                break;
            case 9:
                generate_random_numbers_and_sum();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
