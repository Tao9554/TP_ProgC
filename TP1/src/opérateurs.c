#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    printf("Addition : %d\n", a + b);
    printf("Soustraction : %d\n", a - b);
    printf("Multiplication : %d\n", a * b);
    printf("Division : %d\n", a / b);
    printf("Modulo : %d\n", a % b);

    printf("a est egal a b : %d\n", a == b);
    printf("a est superieur a b : %d\n", a > b);

    return 0;
}