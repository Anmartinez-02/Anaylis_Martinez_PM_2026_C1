#include <stdio.h>
#include <string.h>

/* Cuenta caracteres.
El programa cuenta cuántas veces se encuentra un caracter en una cadena. */

int cuenta(char *, char); /* Prototipo de función. */

int main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    // Usamos fgets por seguridad, ya que gets esta obsoleta
    fgets(cad, 50, stdin);
    // Eliminamos el salto de linea que deja fgets
    cad[strcspn(cad, "\n")] = '\0';

    printf("Ingrese el caracter: ");
    car = getchar();

    res = cuenta(cad, car);

    printf("\n\nEl caracter '%c' se encuentra %d veces en la cadena: %s\n", car, res, cad);

    return 0;
}

int cuenta(char *cad, char car)
/* Esta funcion recorre la cadena hasta encontrar el caracter nulo '\0' */
{
    int i = 0, r = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return (r);
}
