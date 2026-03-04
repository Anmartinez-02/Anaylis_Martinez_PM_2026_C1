#include <stdio.h>
#include <string.h>

/* Funciones de la biblioteca string.h para el manejo de cadenas. */
int main(void)
{
    int i;
    char cad0[20] = "Hola Mexico";
    char cad1[20] = "Hola Guatemala";
    char cad2[20] = "Hola Venezuela";
    char cad3[20] = "Hola Mexico";
    char *c, c3;

    // --- 1. COMPARACIÓN CON strcmp ---
    /* Compara dos cadenas. Regresa 0 si son iguales,
       positivo si la primera es mayor y negativo si es menor. */

    i = strcmp(cad0, cad1);
    printf("\nResultado de la comparacion --cad0 y cad1--: %d", i);

    i = strcmp(cad0, cad2);
    printf("\nResultado de la comparacion --cad0 y cad2--: %d", i);

    i = strcmp(cad0, cad3);
    printf("\nResultado de la comparacion --cad0 y cad3--: %d", i);

    // --- 2. LONGITUD CON strlen ---
    /* Obtiene el numero de caracteres sin contar el nulo (\0). */

    printf("\n\n--- Longitudes ---");
    i = strlen(cad0);
    printf("\nLongitud cadena cad0: %d", i);

    i = strlen(cad1);
    printf("\nLongitud cadena cad1: %d", i);

    // --- 3. BÚSQUEDA CON strchr ---
    /* Busca un caracter y regresa un puntero a su posicion. */

    printf("\n\n--- Busqueda de caracteres ---");

    // Buscando la 'G' en "Hola Guatemala"
    c = strchr(cad1, 'G');
    if (c != NULL)
    {
        c3 = *c; // Obtenemos el valor al que apunta
        printf("\nSe encontro el caracter: %c", c3);
    }

    // Buscando la 'V' en "Hola Venezuela"
    c = strchr(cad2, 'V');
    if (c != NULL)
    {
        c3 = *c;
        printf("\nSe encontro el caracter: %c", c3);
    }

    printf("\n");
    return 0;
}
