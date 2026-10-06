#include "fichier.h"

#include <stdio.h>

int lire_fichier(const char *nom_de_fichier)
{
    char ligne[512];
    FILE *fichier = fopen(nom_de_fichier, "r");

    if (fichier == NULL) {
        perror(nom_de_fichier);
        return -1;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        fputs(ligne, stdout);
    }

    if (ferror(fichier)) {
        perror("Erreur de lecture");
        fclose(fichier);
        return -1;
    }
    if (fclose(fichier) != 0) {
        perror("Erreur de fermeture");
        return -1;
    }
    return 0;
}

int ecrire_dans_fichier(const char *nom_de_fichier, const char *message)
{
    FILE *fichier = fopen(nom_de_fichier, "w");

    if (fichier == NULL) {
        perror(nom_de_fichier);
        return -1;
    }

    if (fputs(message, fichier) == EOF) {
        perror("Erreur d'ecriture");
        fclose(fichier);
        return -1;
    }
    if (fclose(fichier) != 0) {
        perror("Erreur de fermeture");
        return -1;
    }

    printf("Le message a ete ecrit dans le fichier %s.\n", nom_de_fichier);
    return 0;
}