#include <stdio.h>

/*Funciones para el manejo de caracteres de la biblioteca stido.h*/

void main(void)
{
    char p1, p3 = '$';
    int c; // Variable auxiliar para limpiar el búfer

    printf("\nIngrese un caracter: ");
    p1 = getchar();

    printf("El caracter ingresado es: ");
    putchar(p1);
    printf("\n");

    /* Limpieza del búfer de entrada de forma manual y segura */
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nEl caracter p3 es: ");
    putchar(p3);
    printf("\n");

    return 0;
}
