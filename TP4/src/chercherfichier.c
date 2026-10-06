#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nom_de_fichier[256];
    char phrase[256];
    char ligne[2048];
    FILE *fichier;
    unsigned long numero_ligne = 0;

    if (argc > 2) {
        fprintf(stderr, "Usage : %s [fichier]\n", argv[0]);
        return 1;
    }
    if (argc == 2) {
        if (snprintf(nom_de_fichier, sizeof(nom_de_fichier), "%s",
                     argv[1]) >= (int)sizeof(nom_de_fichier)) {
            fprintf(stderr, "Erreur : nom de fichier trop long.\n");
            return 1;
        }
    } else {
        printf("Entrez le nom du fichier : ");
        if (fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin) == NULL) {
            fprintf(stderr, "Erreur : lecture du nom de fichier impossible.\n");
            return 1;
        }
        nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';
    }

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    if (fgets(phrase, sizeof(phrase), stdin) == NULL) {
        fprintf(stderr, "Erreur : lecture de la phrase impossible.\n");
        return 1;
    }
    phrase[strcspn(phrase, "\n")] = '\0';
    if (phrase[0] == '\0') {
        fprintf(stderr, "Erreur : la phrase recherchee ne peut pas etre vide.\n");
        return 1;
    }

    fichier = fopen(nom_de_fichier, "r");
    if (fichier == NULL) {
        perror(nom_de_fichier);
        return 1;
    }

    printf("Resultats de la recherche :\n");
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        int occurrences = 0;
        size_t longueur_phrase = strlen(phrase);
        size_t longueur_ligne = strlen(ligne);

        numero_ligne++;
        for (size_t i = 0; i + longueur_phrase <= longueur_ligne; i++) {
            if (strncmp(ligne + i, phrase, longueur_phrase) == 0) {
                occurrences++;
            }
        }
        if (occurrences > 0) {
            printf("Ligne %lu, %d fois\n", numero_ligne, occurrences);
        }
    }

    if (ferror(fichier)) {
        perror("Erreur de lecture");
        fclose(fichier);
        return 1;
    }
    if (fclose(fichier) != 0) {
        perror("Erreur de fermeture");
        return 1;
    }

    return 0;
}