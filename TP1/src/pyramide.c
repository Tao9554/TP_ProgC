#include <stdio.h>

int main() {
    int n = 5;
    int i;
    int j;

    for (i = 1; i <= n; i++) {

        // Affichage des espaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Nombres croissants
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Nombres décroissants
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    printf("Generation de la pyramide terminee.\n");

    return 0;
}