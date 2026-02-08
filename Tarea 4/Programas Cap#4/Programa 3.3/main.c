#include <stdio.h>

void f1(void);
int k = 5;

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
    return 0;
}

void f1(void)
{
    int k_local = 2;
    k_local += k_local;

    printf("\n\nEl valor de la variable local es: %d", k_local);

    k = k + k_local;
    printf("\nEl valor de la variable global es: %d", k);
}
