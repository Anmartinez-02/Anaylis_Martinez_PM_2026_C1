#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Prototipo de función */
int cuentap(char *);

void main(void)
{
    int i;
    char fra[60]; // Un poco más grande para el espacio extra
    int j = 0;
    char c;

    printf("\nIngrese la linea de texto: ");

    /* Uso de getchar para leer la cadena según tu preferencia */
    while (j < 49 && (c = getchar()) != '\n' && c != EOF) {
        fra[j++] = c;
    }
    fra[j] = '\0';

    /* Limpiamos el buffer de entrada */
    fflush(stdin);

    /* Agregamos un espacio al final para facilitar el conteo de la última palabra */
    strcat(fra, " ");

    i = cuentap(fra);
    printf("\nLa linea de texto tiene %d palabras\n", i);
}

int cuentap(char *cad)
/* Esta función cuenta las palabras localizando los espacios en blanco */
{
    char *cad0;
    int i = 0;

    /* Localiza el primer espacio en blanco */
    cad0 = strstr(cad, " ");

    /* Mientras cad0 no sea NULL (es decir, mientras encuentre espacios)
       y no sea el final de la cadena */
    while (cad0 != NULL)
    {
        i++;
        /* Buscamos el siguiente espacio a partir de la posición siguiente */
        cad0 = strstr(cad0 + 1, " ");

        /* Validación para evitar contar múltiples espacios seguidos
           como palabras diferentes */
        while (cad0 != NULL && *(cad0 - 1) == ' ') {
            cad0 = strstr(cad0 + 1, " ");
        }
    }
    return i;
}
