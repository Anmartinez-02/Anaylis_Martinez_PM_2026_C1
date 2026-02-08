#include <stdio.h>
#include <stdlib.h>

/* Prueba de parámetros por valor */
int f1(int);

int main(void)
{
    int i, k = 4;

    for (i = 1; i <= 3; i++)
    {
        printf("\n\nValor de k antes de llamar a la funcion: %d", ++k);
        printf("\nValor de k despues de llamar a la funcion: %d", f1(k));
    }

    return 0;
}

int f1(int r)
{
    r += r;
    return r;
}

