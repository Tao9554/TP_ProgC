#include "fichier.h"

#include <stdio.h>

struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[150];
    int note1;
    int note2;
};

int main(void)
{
    struct Etudiant etudiants[5];
    char contenu[1500];
    size_t utilise = 0;

    for (int i = 0; i < 5; i++) {
        int ecrit;

        printf("Entrez les details de l'etudiant.e %d :\n", i + 1);
        printf("Nom : ");
        if (scanf(" %49[^\n]", etudiants[i].nom) != 1) {
            fprintf(stderr, "Erreur : nom invalide.\n");
            return 1;
        }
        printf("Prenom : ");
        if (scanf(" %49[^\n]", etudiants[i].prenom) != 1) {
            fprintf(stderr, "Erreur : prenom invalide.\n");
            return 1;
        }
        printf("Adresse : ");
        if (scanf(" %149[^\n]", etudiants[i].adresse) != 1) {
            fprintf(stderr, "Erreur : adresse invalide.\n");
            return 1;
        }
        printf("Note 1 : ");
        if (scanf("%d", &etudiants[i].note1) != 1) {
            fprintf(stderr, "Erreur : note invalide.\n");
            return 1;
        }
        printf("Note 2 : ");
        if (scanf("%d", &etudiants[i].note2) != 1) {
            fprintf(stderr, "Erreur : note invalide.\n");
            return 1;
        }

        ecrit = snprintf(contenu + utilise, sizeof(contenu) - utilise,
                         "%s;%s;%s;%d;%d\n",
                         etudiants[i].nom, etudiants[i].prenom,
                         etudiants[i].adresse, etudiants[i].note1,
                         etudiants[i].note2);
        if (ecrit < 0 || (size_t)ecrit >= sizeof(contenu) - utilise) {
            fprintf(stderr, "Erreur : donnees etudiant trop volumineuses.\n");
            return 1;
        }
        utilise += (size_t)ecrit;
    }

    if (ecrire_dans_fichier("etudiant.txt", contenu) != 0) {
        return 1;
    }
    printf("Les details des etudiants ont ete enregistres dans "
           "le fichier etudiant.txt.\n");
    return 0;
}