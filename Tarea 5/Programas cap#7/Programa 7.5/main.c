#include <stdio.h>
#include <stdlib.h>

/* Funciones para el manejo de caracteres de la biblioteca stdlib.h. */
int main(void)
{
    int i;
    double d;
    long l;
    char cad0[20], *cad1;

    printf("\nIngrese una cadena de caracteres (entero): ");
    gets(cad0);

    // atoi: ASCII to Integer
    i = atoi(cad0);
    printf("\n%s \t %d", cad0, i + 3);

    printf("\n\nIngrese una cadena de caracteres (decimal): ");
    gets(cad0);

    // atof: ASCII to Float (double)
    d = atof(cad0);
    printf("\n%s \t %.2lf ", cad0, d + 1.50);

    // strtod: String to Double (más robusta, separa el resto de la cadena)
    d = strtod(cad0, &cad1);
    printf("\n%s \t %.2lf", cad0, d + 1.50);
    printf("\nResto de la cadena en cad1: ");
    puts(cad1);

    // atol: ASCII to Long
    l = atol(cad0);
    printf("\n%s \t %ld ", cad0, l + 10);

    // strtol: String to Long (permite detectar bases como octal o hexa)
    l = strtol(cad0, &cad1, 0);
    printf("\n%s \t %ld", cad0, l + 10);
    printf("\nResto de la cadena en cad1: ");
    puts(cad1);

    return 0;
}
