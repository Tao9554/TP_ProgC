#include <stdio.h>

int main(void)
{
    char noms[5][20] = {"Martin", "Durand", "Bernard", "Petit", "Robert"};
    char prenoms[5][20] = {"Alice", "Lucas", "Emma", "Hugo", "Lea"};
    char adresses[5][40] = {
        "1 rue des Lilas", "2 avenue Victor Hugo", "3 rue de Paris",
        "4 boulevard Victor", "5 place Centrale"
    };
    float notes_c[5] = {15.5f, 12.0f, 17.0f, 14.5f, 10.0f};
    float notes_systeme[5] = {14.0f, 13.5f, 16.0f, 11.0f, 15.0f};

    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d\n", i + 1);
        printf("Nom : %s\n", noms[i]);
        printf("Prenom : %s\n", prenoms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Programmation C : %.1f\n", notes_c[i]);
        printf("Systeme d'exploitation : %.1f\n\n", notes_systeme[i]);
    }

    return 0;
}