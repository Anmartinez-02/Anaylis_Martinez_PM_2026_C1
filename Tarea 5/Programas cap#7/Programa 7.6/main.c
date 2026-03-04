
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declaramos las cadenas con suficiente espacio (50 bytes) para evitar errores de ejecución
    char cad0[50] = "Hola Mexico";
    char cad1[50] = "Texto";
    char cad2[50] = "";
    char cad3[50] = "ABCDE";
    char *ptr; // Usamos un apuntador auxiliar para las búsquedas

    // --- Prueba de strncpy ---
    // Copiamos los primeros 4 caracteres de cad0 ("Hola") a cad2
    strncpy(cad2, cad0, 4);
    cad2[4] = '\0'; // IMPORTANTE: strncpy no añade el terminador nulo automáticamente
    printf("\nPrueba de la funcion strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    // Copiamos los primeros 3 caracteres de cad3 ("ABC") a cad2
    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba de la funcion strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    // --- Prueba de strcat ---
    // Agregamos cad3 ("ABCDE") al final de cad0
    strcat(cad0, cad3);
    printf("\nPrueba de la funcion strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);

    // Agregamos " YY" al final de cad1
    strcat(cad1, " YY");
    printf("\nPrueba de la funcion strcat. Se incorpora la cadena YY a cad1: %s\n", cad1);

    // --- Prueba de strncat ---
    strcat(cad2, " "); // Añadimos un espacio manual a cad2
    strncat(cad2, cad0, 4); // Añadimos los primeros 4 caracteres de cad0 a cad2
    printf("\nPrueba de la funcion strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);

    // --- Prueba de strstr ---
    // Localizamos la subcadena "Mexico"
    ptr = strstr(cad0, "Mexico");
    if (ptr != NULL) {
        printf("\nPrueba de la funcion strstr. Se localiza 'Mexico' dentro de cad0: %s\n", ptr);
    } else {
        printf("\nPrueba de la funcion strstr. 'Mexico' no encontrado.\n");
    }

    // Localizamos la subcadena "Guatemala" (que no existe en cad0)
    ptr = strstr(cad0, "Guatemala");
    if (ptr != NULL) {
        printf("\nPrueba de la funcion strstr. Se localiza 'Guatemala' dentro de cad0: %s\n", ptr);
    } else {
        printf("\nPrueba de la funcion strstr. 'Guatemala' no se encuentra en la cadena (es NULL).\n");
    }

    return 0;
}
