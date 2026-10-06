#include <stdio.h>

int main(void)
{
    int n = 7;
    int precedent = 0;
    int courant = 1;
    int suivant;

    /* n représente ici le nombre de termes affichés, à partir de U0. */
    for (int i = 0; i < n; i++) {
        printf("%d", precedent);
        if (i < n - 1) {
            printf(", ");
        }

        suivant = precedent + courant;
        precedent = courant;
        courant = suivant;
    }
    printf("\n");

    return 0;
}