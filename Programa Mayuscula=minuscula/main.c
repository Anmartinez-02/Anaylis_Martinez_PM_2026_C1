#include <stdio.h>

void main(void)
{
    char p1, p3 = '$';
    int c;

    printf("\nIngrese una letra: ");
    p1 = getchar();

    /* Proceso de conversión Mayuscula a minuscula */
    if (p1 >= 'A' && p1 <= 'Z')
        {

        p1 = p1 + 32;
    }
    else if (p1 >= 'a' && p1 <= 'z')
    {
        p1 = p1 - 32;
        /*En minúscula, la pasamos a Mayuscula*/

    }

    printf("El caracter transformado es: ");
    putchar(p1);
    printf("\n");

    /* Limpieza del búfer (Sustituto de fflush) */
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nEl caracter p3 sigue siendo: ");
    putchar(p3);
    printf("\n");

}
