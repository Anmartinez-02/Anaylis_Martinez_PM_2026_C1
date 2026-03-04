#include <stdio.h>
#include <ctype.h>

/* Prototipo de función */
void interpreta(char *cadena);

int main(void)
{
    char cad[50];
    int i = 0;
    char c;

    printf("\nIngrese la cadena de caracteres (ejemplo: 3a2b): ");

    /* Usando getchar para leer la cadena según tu preferencia.
       Leemos hasta encontrar un salto de línea o llenar el arreglo.
    */
    while (i < 49 && (c = getchar()) != '\n' && c != EOF) {
        cad[i++] = c;
    }
    cad[i] = '\0'; // Finalizamos la cadena correctamente

    /* Limpiamos el buffer de entrada si quedó algo */
    fflush(stdin);

    interpreta(cad);
    printf("\n");

    return 0;
}

void interpreta(char *cadena)
/* Esta función decodifica la cadena: si encuentra '3a', imprime 'aaa' */
{
    int i = 0, j, k;

    while (cadena[i] != '\0')
    {
        /* Verifica si el caracter actual es una letra */
        if (isalpha(cadena[i]))
        {
            /* Se asume que el caracter anterior es un número.
               Restamos 48 (ASCII de '0') para obtener el valor entero.
            */
            if (i > 0) {
                k = cadena[i - 1] - 48;

                for (j = 0; j < k; j++) {
                    putchar(cadena[i]);
                }
            }
        }
        i++;
    }
}
