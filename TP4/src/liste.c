#include "liste.h"

#include <stdio.h>
#include <stdlib.h>

void init_liste(struct liste_couleurs *liste)
{
    liste->tete = NULL;
}

int insertion(const struct couleur *couleur, struct liste_couleurs *liste)
{
    struct noeud_couleur *nouveau = malloc(sizeof(*nouveau));
    struct noeud_couleur *courant;

    if (nouveau == NULL) {
        return -1;
    }

    nouveau->valeur = *couleur;
    nouveau->suivant = NULL;

    if (liste->tete == NULL) {
        liste->tete = nouveau;
    } else {
        courant = liste->tete;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = nouveau;
    }
    return 0;
}

void parcours(const struct liste_couleurs *liste)
{
    const struct noeud_couleur *courant = liste->tete;

    while (courant != NULL) {
        printf("R=%u G=%u B=%u A=%u\n",
               (unsigned int)courant->valeur.r,
               (unsigned int)courant->valeur.g,
               (unsigned int)courant->valeur.b,
               (unsigned int)courant->valeur.a);
        courant = courant->suivant;
    }
}

void liberer_liste(struct liste_couleurs *liste)
{
    struct noeud_couleur *courant = liste->tete;

    while (courant != NULL) {
        struct noeud_couleur *suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    liste->tete = NULL;
}