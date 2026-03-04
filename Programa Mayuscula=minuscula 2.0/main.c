#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(void)
{
    char p1, p3 = '$';
    int c;

    printf("\nIngrese una letra: ");
    p1 = getchar();

    if (p1 >= 65 && p1 <= 90)
    { /* Es una mayúscula, usamos la función de la tabla para pasarla a minúscula */
        printf("Detectada mayuscula en rango ASCII 65-90.\n");
        p1 = islower(p1);
    }
    else if (p1 >= 97 && p1 <= 122)
    {

        p1 = toupper(p1);
    }

    printf("El caracter transformado es: ");
    putchar(tolower(p1));
    printf("\n");

    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nEl caracter p3 sigue siendo: ");
    putchar(p3);
    printf("\n");
}
