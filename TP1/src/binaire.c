#include <stdio.h>

int main() {
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = 5;

    for (int n = 0; n < taille; n++) {
        int nombre = nombres[n];

        printf("%d en binaire : ", nombre);

        if (nombre == 0) {
            printf("0");
        } else {
            int puissance = 1;

            while (puissance <= nombre / 2) {
                puissance *= 2;
            }

            for (; puissance > 0; puissance /= 2) {
                if (nombre >= puissance) {
                    printf("1");
                    nombre -= puissance;
                } else {
                    printf("0");
                }
            }
        }

        printf("\n");
    }

    return 0;
}