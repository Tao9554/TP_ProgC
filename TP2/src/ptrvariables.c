#include <stdio.h>

int main(void)
{
    char c = 'A';
    short s = -1000;
    int i = -100000;
    long int l = -1000000L;
    long long int ll = -1000000000LL;
    float f = 3.14f;
    double d = 3.14159;
    long double ld = 3.141592653589793L;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pl = &l;
    long long int *pll = &ll;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    printf("Avant modification :\n");
    printf("char : adresse=%p valeur=%c (0x%02x)\n",
           (void *)&c, c, (unsigned int)(unsigned char)c);
    printf("short : adresse=%p valeur=%hd (0x%hx)\n",
           (void *)&s, s, (unsigned short)s);
    printf("int : adresse=%p valeur=%d (0x%x)\n",
           (void *)&i, i, (unsigned int)i);
    printf("long int : adresse=%p valeur=%ld (0x%lx)\n",
           (void *)&l, l, (unsigned long)l);
    printf("long long int : adresse=%p valeur=%lld (0x%llx)\n",
           (void *)&ll, ll, (unsigned long long)ll);
    printf("float : adresse=%p valeur=%f\n", (void *)&f, f);
    printf("double : adresse=%p valeur=%f\n", (void *)&d, d);
    printf("long double : adresse=%p valeur=%Lf\n", (void *)&ld, ld);

    *pc = 'B';
    *ps = -900;
    *pi = -90000;
    *pl = -900000L;
    *pll = -900000000LL;
    *pf = 6.28f;
    *pd = 6.28318;
    *pld = 6.283185307179586L;

    printf("\nApres modification par les pointeurs :\n");
    printf("char : adresse=%p valeur=%c (0x%02x)\n",
           (void *)&c, c, (unsigned int)(unsigned char)c);
    printf("short : adresse=%p valeur=%hd (0x%hx)\n",
           (void *)&s, s, (unsigned short)s);
    printf("int : adresse=%p valeur=%d (0x%x)\n",
           (void *)&i, i, (unsigned int)i);
    printf("long int : adresse=%p valeur=%ld (0x%lx)\n",
           (void *)&l, l, (unsigned long)l);
    printf("long long int : adresse=%p valeur=%lld (0x%llx)\n",
           (void *)&ll, ll, (unsigned long long)ll);
    printf("float : adresse=%p valeur=%f\n", (void *)&f, f);
    printf("double : adresse=%p valeur=%f\n", (void *)&d, d);
    printf("long double : adresse=%p valeur=%Lf\n", (void *)&ld, ld);

    return 0;
}