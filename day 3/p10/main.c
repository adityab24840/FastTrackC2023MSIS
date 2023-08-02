//Find square of a number using macros.

#include<stdio.h>
#define SQUARE(x) ((x) * (x))

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int square = SQUARE(num);
    printf("Square of %d is: %d\n", num, square);
    return 0;
}
