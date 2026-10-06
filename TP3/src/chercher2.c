#include <stdio.h>

int main(void)
{
    const char *phrases[10] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };
    char recherche[200];
    int trouve = 0;

    printf("Entrez la phrase a rechercher : ");
    if (fgets(recherche, sizeof(recherche), stdin) == NULL) {
        fprintf(stderr, "Erreur : lecture de la phrase impossible.\n");
        return 1;
    }

    int longueur = 0;
    while (recherche[longueur] != '\0' && recherche[longueur] != '\n') {
        longueur++;
    }
    recherche[longueur] = '\0';

    for (int i = 0; i < 10; i++) {
        int j = 0;
        while (phrases[i][j] != '\0' &&
               recherche[j] != '\0' &&
               phrases[i][j] == recherche[j]) {
            j++;
        }

        if (phrases[i][j] == '\0' && recherche[j] == '\0') {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Phrase trouvee\n");
    } else {
        printf("Phrase non trouvee\n");
    }

    return 0;
}
