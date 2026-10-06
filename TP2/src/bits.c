#include <limits.h>
#include <stdio.h>

int main(void)
{
    int d = 0x10001000;
    const unsigned int largeur = (unsigned int)(sizeof(d) * CHAR_BIT);
    const unsigned int valeur = (unsigned int)d;
    const unsigned int masque4 = 1u << (largeur - 4u);
    const unsigned int masque20 = 1u << (largeur - 20u);

    /* Les bits sont comptés à partir du bit le plus à gauche. */
    if ((valeur & masque4) != 0u && (valeur & masque20) != 0u) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}