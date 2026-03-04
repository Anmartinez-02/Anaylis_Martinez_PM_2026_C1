#include <stdio.h>
#include <stdlib.h>

/* Suma y promedio.
El programa recibe cadenas que contienen numeros reales, los suma y obtiene el promedio. */

int main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();

    while (c == 'S' || c == 's') // Acepta tanto 'S' como 's'
    {
        printf("\nIngrese la cadena de caracteres (numero): ");

        /* Limpieza del buffer: necesaria para que el 'Enter' anterior
           no sea leido por el siguiente gets/getchar */
        while (getchar() != '\n');

        gets(cad);
        i++;
        sum += atof(cad); // Convierte la cadena a float

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
    }

    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f\n", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos.\n");
    }

    return 0;
}
