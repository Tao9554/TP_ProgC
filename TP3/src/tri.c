#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nombres[100];

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++) {
        nombres[i] = rand() % 1000 + 1;
    }

    printf("Tableau non trie :\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");

    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99 - i; j++) {
            if (nombres[j] > nombres[j + 1]) {
                int temporaire = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = temporaire;
            }
        }
    }

    printf("Tableau trie par ordre croissant :\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");

    return 0;
}