#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int entiers[10];
    float reels[10];
    int *p_entiers = entiers;
    float *p_reels = reels;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        *(p_entiers + i) = rand() % 100;
        *(p_reels + i) = (float)(rand() % 100) / 10.0f;
    }

    printf("Tableaux avant modification :\nEntiers : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(p_entiers + i));
    }
    printf("\nFlottants : ");
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", *(p_reels + i));
    }

    for (int i = 0; i < 10; i += 2) {
        *(p_entiers + i) *= 3;
        *(p_reels + i) *= 3.0f;
    }

    printf("\n\nTableaux apres modification :\nEntiers : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(p_entiers + i));
    }
    printf("\nFlottants : ");
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", *(p_reels + i));
    }
    printf("\n");

    return 0;
}