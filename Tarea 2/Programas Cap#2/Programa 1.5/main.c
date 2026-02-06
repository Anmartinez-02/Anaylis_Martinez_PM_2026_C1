#include <stdio.h>
#include <stdlib.h>
/* Funcion matematica.
El programa obtiene el resultado de una funcion.
OP y T: Variable de tipo entero.
RES: Variable de tipo real. */

int main()
{

    int OP, T;
    float RES;
    printf("Ingrese la opcion del calculo y el valor entero: ");
    scanf("%d%d, &OP, &T");
    switch(OP)
           {

               case 1: RES = T / 5;
               break;
               case 2: RES = (T,T);
               /*La funcion pow esta definida en la biblioteca math.h */
               break;
               case 3:
                break;
                case 4: RES = 6 * T/2;
                break;
                default: RES = 1;
                break;

               }
   printf("\nResultado: %7.2f", RES);
    return 0;
}
