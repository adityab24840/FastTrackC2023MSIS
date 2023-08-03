#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define WINNING_POSITION 100
#define NUM_LADDERS 6
#define NUM_SNAKES 7

struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

struct Complex {
    float real;
    float imag;
};

struct SnakeLadder {
    int start;
    int end;
};

void inputStudentData(struct Student *student) {
    printf("Enter Roll No: ");
    scanf("%d", &student->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", student->name);

    printf("Enter Age: ");
    scanf("%d", &student->age);

    printf("Enter Marks: ");
    scanf("%f", &student->marks);
}

void printStudentData(const struct Student *student) {
    printf("Roll No: %d\n", student->rollNo);
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Marks: %.2f\n", student->marks);
    printf("--------------------------\n");
}

struct Complex add(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

struct Complex subtract(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

struct Complex multiply(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

float calculateTotalPrice(float prices[], int quantities[], int numItems) {
    float total = 0;
    for (int i = 0; i < numItems; ++i) {
        total += prices[i] * quantities[i];
    }
    return total;
}

float calculateDiscount(float totalPrice) {
    if (totalPrice < 1000)
        return 0.05 * totalPrice;
    else if (totalPrice < 5000)
        return 0.10 * totalPrice;
    else
        return 0.15 * totalPrice;
}

void printReceipt(float prices[], int quantities[], int numItems) {
    printf("Item\tPrice\tQuantity\tSubtotal\n");
    float total = 0;
    for (int i = 0; i < numItems; ++i) {
        float subtotal = prices[i] * quantities[i];
        printf("Item %d:\t%.2f\t%d\t\t%.2f\n", i + 1, prices[i], quantities[i], subtotal);
        total += subtotal;
    }
    printf("----------------------------------------\n");
    printf("TOTAL\t%.2f\n", total);

    float discount = calculateDiscount(total);
    printf("Discount %.0f%%\t%.2f\n", (discount / total) * 100, discount);

    printf("----------------------------------------\n");
    printf("GRAND TOTAL\t%.2f\n", total - discount);
}

void initializeBoard(int board[], int size) {
    for (int i = 0; i < size; ++i) {
        board[i] = i + 1;
    }
}

void displayBoard(const int board[], int size, int player1Pos, int player2Pos) {
    printf("\nBoard:\n");
    int k = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (j == player1Pos && i == BOARD_SIZE - 1) {
                    printf("P1\t");
                } else if (j == player2Pos && i == BOARD_SIZE - 1) {
                    printf("P2\t");
                } else {
                    printf("%d\t", board[k]);
                }
                ++k;
            }
        } else {
            for (int j = BOARD_SIZE - 1; j >= 0; --j) {
                if (j == player1Pos && i == BOARD_SIZE - 1) {
                    printf("P1\t");
                } else if (j == player2Pos && i == BOARD_SIZE - 1) {
                    printf("P2\t");
                } else {
                    printf("%d\t", board[k]);
                }
                ++k;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void initializeSnakesAndLadders(struct SnakeLadder snakes[], struct SnakeLadder ladders[]) {
    // Initialize snake positions
    snakes[0].start = 16; snakes[0].end = 6;
    snakes[1].start = 47; snakes[1].end = 26;
    snakes[2].start = 49; snakes[2].end = 11;
    snakes[3].start = 56; snakes[3].end = 53;
    snakes[4].start = 62; snakes[4].end = 19;
    snakes[5].start = 64; snakes[5].end = 60;
    snakes[6].start = 87; snakes[6].end = 24;

    // Initialize ladder positions
    ladders[0].start = 1; ladders[0].end = 38;
    ladders[1].start = 4; ladders[1].end = 14;
    ladders[2].start = 9; ladders[2].end = 31;
    ladders[3].start = 21; ladders[3].end = 42;
    ladders[4].start = 28; ladders[4].end = 84;
    ladders[5].start = 36; ladders[5].end = 44;
}

void rollDice(int *dice) {
    *dice = (rand() % 6) + 1;
}

void playSnakeLadder(int *position, int dice, struct SnakeLadder snakes[], struct SnakeLadder ladders[]) {
    int newPosition = *position + dice;

    // Check for snakes
    for (int i = 0; i < NUM_SNAKES; ++i) {
        if (newPosition == snakes[i].start) {
            printf("Oops! Snake bite! Going down from %d to %d.\n", newPosition, snakes[i].end);
            newPosition = snakes[i].end;
            break;
        }
    }

    // Check for ladders
    for (int i = 0; i < NUM_LADDERS; ++i) {
        if (newPosition == ladders[i].start) {
            printf("Yay! Climbing the ladder from %d to %d.\n", newPosition, ladders[i].end);
            newPosition = ladders[i].end;
            break;
        }
    }

    if (newPosition <= WINNING_POSITION) {
        *position = newPosition;
    }
}

int main() {
    int choice;

    srand(time(0)); // Seed the random number generator

    struct SnakeLadder snakes[NUM_SNAKES];
    struct SnakeLadder ladders[NUM_LADDERS];
    initializeSnakesAndLadders(snakes, ladders);

    int board[BOARD_SIZE * BOARD_SIZE];
    initializeBoard(board, BOARD_SIZE * BOARD_SIZE);

    int player1Position = 0, player2Position = 0;
    int dice;

    do {
        printf("\nMenu:\n");
        printf("1. Student Information\n");
        printf("2. Complex Number Operations\n");
        printf("3. Calculate Price, Discount, and Final Price\n");
        printf("4. Two Player Snake and Ladder Game\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                const int numStudents = 5;
                struct Student students[numStudents];

                printf("Enter information of %d students:\n", numStudents);
                for (int i = 0; i < numStudents; ++i) {
                    printf("Student %d:\n", i + 1);
                    inputStudentData(&students[i]);
                }

                printf("Student Information:\n");
                for (int i = 0; i < numStudents; ++i) {
                    printf("Student %d:\n", i + 1);
                    printStudentData(&students[i]);
                }
                break;
            }
            case 2: {
                struct Complex num1, num2, sum, diff, product;

                printf("Enter real and imaginary parts of the first complex number: ");
                scanf("%f %f", &num1.real, &num1.imag);

                printf("Enter real and imaginary parts of the second complex number: ");
                scanf("%f %f", &num2.real, &num2.imag);

                sum = add(num1, num2);
                diff = subtract(num1, num2);
                product = multiply(num1, num2);

                printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
                printf("Difference: %.2f + %.2fi\n", diff.real, diff.imag);
                printf("Product: %.2f + %.2fi\n", product.real, product.imag);
                break;
            }
            case 3: {
                const int numItems = 5;
                float prices[numItems];
                int quantities[numItems];

                for (int i = 0; i < numItems; ++i) {
                    printf("Enter price and quantity for Item %d: ", i + 1);
                    scanf("%f %d", &prices[i], &quantities[i]);
                }

                float total = calculateTotalPrice(prices, quantities, numItems);
                printReceipt(prices, quantities, numItems);
                break;
            }
            case 4: {
                printf("Welcome to the Two Player Snake and Ladder Game!\n");

                do {
                    // Player 1's turn
                    printf("\nPlayer 1's turn (user)\n");
                    rollDice(&dice);
                    printf("You rolled: %d\n", dice);
                    playSnakeLadder(&player1Position, dice, snakes, ladders);
                    displayBoard(board, BOARD_SIZE * BOARD_SIZE, player1Position, player2Position);
                    printf("Player 1's position: %d\n", player1Position);

                    if (player1Position >= WINNING_POSITION) {
                        printf("Congratulations! Player 1 (user) wins!\n");
                        break;
                    }

                    // Player 2's turn (computer)
                    printf("\nPlayer 2's turn (computer)\n");
                    rollDice(&dice);
                    printf("Computer rolled: %d\n", dice);
                    playSnakeLadder(&player2Position, dice, snakes, ladders);
                    displayBoard(board, BOARD_SIZE * BOARD_SIZE, player1Position, player2Position);
                    printf("Player 2's position: %d\n", player2Position);

                    if (player2Position >= WINNING_POSITION) {
                        printf("Computer wins!\n");
                        break;
                    }
                } while (1);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
