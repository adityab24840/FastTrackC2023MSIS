#include <stdio.h>

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("  ");
        }
        for (int j = i; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printPattern(rows);

    return 0;
}
