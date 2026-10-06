#include "operator.h"

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int convertir_entier(const char *texte, int *valeur)
{
    char *fin;
    long resultat;

    errno = 0;
    resultat = strtol(texte, &fin, 10);
    if (errno != 0 || fin == texte || *fin != '\0' ||
        resultat < INT_MIN || resultat > INT_MAX) {
        return 0;
    }

    *valeur = (int)resultat;
    return 1;
}

int main(int argc, char *argv[])
{
    int num1;
    int num2;
    int resultat;
    char op;

    if (argc != 4 || argv[1][0] == '\0' || argv[1][1] != '\0' ||
        !convertir_entier(argv[2], &num1) ||
        !convertir_entier(argv[3], &num2)) {
        fprintf(stderr, "Usage : %s operateur entier entier\n", argv[0]);
        return 1;
    }
    op = argv[1][0];

    switch (op) {
    case '+':
        resultat = somme(num1, num2);
        break;
    case '-':
        resultat = difference(num1, num2);
        break;
    case '*':
        resultat = produit(num1, num2);
        break;
    case '/':
        if (num2 == 0 || (num1 == INT_MIN && num2 == -1)) {
            fprintf(stderr, "Erreur : division impossible.\n");
            return 1;
        }
        resultat = quotient(num1, num2);
        break;
    case '%':
        if (num2 == 0 || (num1 == INT_MIN && num2 == -1)) {
            fprintf(stderr, "Erreur : modulo impossible.\n");
            return 1;
        }
        resultat = modulo(num1, num2);
        break;
    case '&':
        resultat = bit_et(num1, num2);
        break;
    case '|':
        resultat = bit_ou(num1, num2);
        break;
    case '~':
        resultat = negation(num1, num2);
        break;
    default:
        fprintf(stderr, "Erreur : operateur non pris en charge.\n");
        return 1;
    }

    printf("Resultat : %d\n", resultat);
    return 0;
}