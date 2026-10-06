#include <stdio.h>

struct Couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

int main(void)
{
    struct Couleur couleurs[10] = {
        {0xef, 0x78, 0x12, 0xff},
        {0x12, 0x34, 0x56, 0xff},
        {0xff, 0x00, 0x00, 0xff},
        {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff},
        {0xff, 0xff, 0x00, 0xff},
        {0xff, 0x00, 0xff, 0xff},
        {0x00, 0xff, 0xff, 0xff},
        {0x80, 0x80, 0x80, 0xff},
        {0x00, 0x00, 0x00, 0xff}
    };

    for (int i = 0; i < 10; i++) {
        printf("Couleur %d : R=%u G=%u B=%u A=%u\n",
               i + 1,
               (unsigned int)couleurs[i].r,
               (unsigned int)couleurs[i].g,
               (unsigned int)couleurs[i].b,
               (unsigned int)couleurs[i].a);
    }

    return 0;
}