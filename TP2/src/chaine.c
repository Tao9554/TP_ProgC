#include <stdio.h>

int main(void)
{
    char premiere[] = "Hello";
    char deuxieme[] = " World!";
    char copie[20];
    char concatenee[20];
    int longueur = 0;
    int i = 0;

    while (premiere[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de \"%s\" : %d\n", premiere, longueur);

    while (premiere[i] != '\0') {
        copie[i] = premiere[i];
        i++;
    }
    copie[i] = '\0';
    printf("Copie : %s\n", copie);

    i = 0;
    while (premiere[i] != '\0') {
        concatenee[i] = premiere[i];
        i++;
    }

    int j = 0;
    while (deuxieme[j] != '\0') {
        concatenee[i] = deuxieme[j];
        i++;
        j++;
    }
    concatenee[i] = '\0';
    printf("Concaténation : %s\n", concatenee);

    return 0;
}