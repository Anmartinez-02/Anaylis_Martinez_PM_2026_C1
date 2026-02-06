#include <stdio.h>
#include <stdlib.h>


 /* Promedio curso.
 El programa, al recibir como dato el promedio de un alumno en un curso universitario, escribe aprobado si su promedio es mayor o igual a 6.
 PRO: Variable de tipo real. */

int main()
{
    float PRO;
    printf("Ingrese el promedio del alumno: ");
    scanf ("%f", &PRO);
    if (PRO >= 6)
        printf("\nAprovado");
    return 0;
}
