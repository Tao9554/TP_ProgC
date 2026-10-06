#include <stdio.h>

static int factorielle(int nombre)
{
    if (nombre == 0) {
        printf("fact(0): 1\n");
        return 1;
    }

    int valeur = nombre * factorielle(nombre - 1);
    printf("fact(%d): %d\n", nombre, valeur);
    return valeur;
}

int main(void)
{
    const int valeurs[] = {0, 1, 5, 7};
    const size_t nombre_valeurs = sizeof(valeurs) / sizeof(valeurs[0]);

    for (size_t i = 0; i < nombre_valeurs; i++) {
        printf("Factorielle de %d : %d\n",
               valeurs[i], factorielle(valeurs[i]));
    }

    return 0;
}