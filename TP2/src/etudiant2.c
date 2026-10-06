#include <stdio.h>
#include <string.h>

struct Etudiant {
    char nom[20];
    char prenom[20];
    char adresse[40];
    float note_c;
    float note_systeme;
};

int main(void)
{
    struct Etudiant etudiants[5];

    strcpy(etudiants[0].nom, "Martin");
    strcpy(etudiants[0].prenom, "Alice");
    strcpy(etudiants[0].adresse, "1 rue des Lilas");
    etudiants[0].note_c = 15.5f;
    etudiants[0].note_systeme = 14.0f;

    strcpy(etudiants[1].nom, "Durand");
    strcpy(etudiants[1].prenom, "Lucas");
    strcpy(etudiants[1].adresse, "2 avenue Victor Hugo");
    etudiants[1].note_c = 12.0f;
    etudiants[1].note_systeme = 13.5f;

    strcpy(etudiants[2].nom, "Bernard");
    strcpy(etudiants[2].prenom, "Emma");
    strcpy(etudiants[2].adresse, "3 rue de Paris");
    etudiants[2].note_c = 17.0f;
    etudiants[2].note_systeme = 16.0f;

    strcpy(etudiants[3].nom, "Petit");
    strcpy(etudiants[3].prenom, "Hugo");
    strcpy(etudiants[3].adresse, "4 boulevard Victor");
    etudiants[3].note_c = 14.5f;
    etudiants[3].note_systeme = 11.0f;

    strcpy(etudiants[4].nom, "Robert");
    strcpy(etudiants[4].prenom, "Lea");
    strcpy(etudiants[4].adresse, "5 place Centrale");
    etudiants[4].note_c = 10.0f;
    etudiants[4].note_systeme = 15.0f;

    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Programmation C : %.1f\n", etudiants[i].note_c);
        printf("Systeme d'exploitation : %.1f\n\n",
               etudiants[i].note_systeme);
    }

    return 0;
}