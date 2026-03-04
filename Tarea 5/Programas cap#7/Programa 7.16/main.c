#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(void)
{
    char cad1[50], cad2[50];
    char *cad0;
    int i = 0, j = 0;
    char c;

    // --- Lectura de la primera cadena ---
    printf("\nIngrese la primera cadena de caracteres: ");
    while (j < 49 && (c = getchar()) != '\n' && c != EOF) {
        cad1[j++] = c;
    }
    cad1[j] = '\0';
    fflush(stdin); // Limpiamos el buffer

    // --- Lectura de la cadena a buscar ---
    j = 0;
    printf("Ingrese la cadena a buscar: ");
    while (j < 49 && (c = getchar()) != '\n' && c != EOF) {
        cad2[j++] = c;
    }
    cad2[j] = '\0';
    fflush(stdin);

    /* IMPORTANTE: cad0 debe apuntar a la dirección de memoria de cad1.
       No es necesario usar strcpy si solo queremos recorrer la cadena.
    */
    cad0 = cad1;

    /* Buscamos la primera ocurrencia */
    cad0 = strstr(cad0, cad2);

    while(cad0 != NULL)
    {
        i++;
        /* Avanzamos el puntero una posición después del hallazgo
           para seguir buscando el resto de la cadena.
        */
        cad0 = strstr(cad0 + 1, cad2);
    }

    printf("\nEl numero de veces que aparece la segunda cadena es: %d\n", i);
}
