#include <stdio.h>

int main(void)
{
    int nombres[100];
    int recherche;
    int gauche = 0;
    int droite = 99;
    int present = 0;

    for (int i = 0; i < 100; i++) {
        nombres[i] = i + 1;
    }

    printf("Tableau trie :\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n\nEntrez l'entier que vous souhaitez chercher : ");

    if (scanf("%d", &recherche) != 1) {
        fprintf(stderr, "Erreur : entree invalide.\n");
        return 1;
    }

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (nombres[milieu] == recherche) {
            present = 1;
            break;
        } else if (nombres[milieu] < recherche) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    if (present) {
        printf("Resultat : entier present\n");
    } else {
        printf("Resultat : entier absent\n");
    }

    return 0;
}