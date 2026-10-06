#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nombres[100];
    int recherche;
    int present = 0;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++) {
        nombres[i] = rand() % 1000 + 1;
    }

    printf("Tableau :\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n\nEntrez l'entier que vous souhaitez chercher : ");

    if (scanf("%d", &recherche) != 1) {
        fprintf(stderr, "Erreur : entree invalide.\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        if (nombres[i] == recherche) {
            present = 1;
            break;
        }
    }

    if (present) {
        printf("Resultat : entier present\n");
    } else {
        printf("Resultat : entier absent\n");
    }

    return 0;
}