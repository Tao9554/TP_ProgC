#include <stdio.h>

int main() {
    int num1 = 16;
    int num2 = 3;
    char op = '+';

    switch (op) {
        case '+':
            printf("Resultat : %d\n", num1 + num2);
            break;

        case '-':
            printf("Resultat : %d\n", num1 - num2);
            break;

        case '*':
            printf("Resultat : %d\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 / num2);
            } else {
                printf("Erreur : division par zero\n");
            }
            break;

        case '%':
            if (num2 != 0) {
                printf("Resultat : %d\n", num1 % num2);
            } else {
                printf("Erreur : modulo par zero\n");
            }
            break;

        case '&':
            printf("Resultat : %d\n", num1 & num2);
            break;

        case '|':
            printf("Resultat : %d\n", num1 | num2);
            break;

        case '~':
            printf("Resultat : %d\n", ~num1);
            break;

        default:
            printf("Operateur invalide\n");
            break;
    }

    return 0;
}