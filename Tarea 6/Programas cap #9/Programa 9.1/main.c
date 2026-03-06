#include <stdio.h>

/* Archivos y caracteres
El programa escribe caracteres en un archivo hasta presionar Enter */

int main(void) // Se recomienda usar int main por estándar
{
    int p1; // Cambiado a int para mayor seguridad con getchar()
    FILE *ar;

    // Intentamos abrir el archivo
    ar = fopen("arc.txt", "w");

    if (ar != NULL)
    {
        printf("Escriba una frase y presione Enter para guardar:\n");

        // Lee caracteres uno por uno hasta encontrar un salto de línea
        while ((p1 = getchar()) != '\n' && p1 != EOF)
        {
            fputc(p1, ar);
        }

        fclose(ar); // Cerramos el flujo del archivo
        printf("\nTexto guardado correctamente en arc.txt\n");
    }
    else
    {
        printf("Error: No se puede abrir o crear el archivo.\n");
    }

    return 0;
}
