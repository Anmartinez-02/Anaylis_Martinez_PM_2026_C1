#include <stdio.h>
#include <stdlib.h>
// Cubo -3.
//El programa calcula el cubo de los 10 primeros numeros naturales con la ayuda de una funcion y utilizando parametros por valor.

int cubo (int);
void main (void)

{
   int i;
   for (i = 1; i <= 10; i++)
   printf("\nEl cubo de i es:%d", cubo(i));
/* Llamada a la función cubo. El paso del parámetro es por valor. */
}
int cubo(int k)
        /*
k es un parámetro por valor de tipo entero. */
/* La función calcula el cubo del parámetro k. */
{
return (k*k*k);
}
