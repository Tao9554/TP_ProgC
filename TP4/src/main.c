
#include "fichier.h"
#include "liste.h"
#include "operator.h"

#include <limits.h>
#include <stdio.h>

static int exercice_operateurs(void)
{
    int num1;
    int num2;
    int resultat;
    char op;

    printf("Entrez num1 : ");
    if (scanf("%d", &num1) != 1) {
        fprintf(stderr, "Erreur : entier invalide.\n");
        return 1;
    }
    printf("Entrez num2 : ");
    if (scanf("%d", &num2) != 1) {
        fprintf(stderr, "Erreur : entier invalide.\n");
        return 1;
    }
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    if (scanf(" %c", &op) != 1) {
        fprintf(stderr, "Erreur : operateur invalide.\n");
        return 1;
    }

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

static int exercice_fichiers(void)
{
    char nom_de_fichier[256];
    char message[1024];
    int choix;

    printf("Que souhaitez-vous faire ?\n"
           "1. Lire un fichier\n"
           "2. Ecrire dans un fichier\n"
           "Votre choix : ");
    if (scanf("%d", &choix) != 1) {
        fprintf(stderr, "Erreur : choix invalide.\n");
        return 1;
    }

    if (choix == 1) {
        printf("Entrez le nom du fichier a lire : ");
        if (scanf("%255s", nom_de_fichier) != 1) {
            fprintf(stderr, "Erreur : nom de fichier invalide.\n");
            return 1;
        }
        return lire_fichier(nom_de_fichier) != 0;
    }
    if (choix == 2) {
        int caractere;
        printf("Entrez le nom du fichier dans lequel ecrire : ");
        if (scanf("%255s", nom_de_fichier) != 1) {
            fprintf(stderr, "Erreur : nom de fichier invalide.\n");
            return 1;
        }
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
        printf("Entrez le message a ecrire : ");
        if (fgets(message, sizeof(message), stdin) == NULL) {
            fprintf(stderr, "Erreur : lecture du message impossible.\n");
            return 1;
        }
        for (int i = 0; message[i] != '\0'; i++) {
            if (message[i] == '\n') {
                message[i] = '\0';
                break;
            }
        }
        return ecrire_dans_fichier(nom_de_fichier, message) != 0;
    }

    fprintf(stderr, "Erreur : choix non pris en charge.\n");
    return 1;
}

static int exercice_liste(void)
{
    const struct couleur couleurs[10] = {
        {0xff, 0x00, 0x00, 0xff}, {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff}, {0xff, 0xff, 0x00, 0xff},
        {0xff, 0x00, 0xff, 0xff}, {0x00, 0xff, 0xff, 0xff},
        {0x12, 0x34, 0x56, 0xff}, {0x78, 0x9a, 0xbc, 0xff},
        {0xef, 0x78, 0x12, 0xff}, {0x00, 0x00, 0x00, 0xff}
    };
    struct liste_couleurs liste;

    init_liste(&liste);
    for (int i = 0; i < 10; i++) {
        if (insertion(&couleurs[i], &liste) != 0) {
            fprintf(stderr, "Erreur : allocation memoire impossible.\n");
            liberer_liste(&liste);
            return 1;
        }
    }

    printf("Liste des couleurs :\n");
    parcours(&liste);
    liberer_liste(&liste);
    return 0;
}

int main(void)
{
    int choix;

    printf("Choisissez l'exercice a executer :\n"
           "1. Calcul avec operateurs (4.1)\n"
           "2. Gestion de fichiers (4.2)\n"
           "7. Liste de couleurs (4.7)\n"
           "Votre choix : ");
    if (scanf("%d", &choix) != 1) {
        fprintf(stderr, "Erreur : choix invalide.\n");
        return 1;
    }

    switch (choix) {
    case 1:
        return exercice_operateurs();
    case 2:
        return exercice_fichiers();
    case 7:
        return exercice_liste();
    default:
        fprintf(stderr, "Erreur : exercice non pris en charge.\n");
        return 1;
    }
}
