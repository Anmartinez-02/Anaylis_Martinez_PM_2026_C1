#include <stdio.h>
#include <string.h>

/* Prototipo de función */
char * inverso(char *);

void main(void)
{
    char fra[50], aux[50];
    int i = 0;
    char c;

    printf("\nIngrese la linea de texto: ");

    /* Uso de getchar para leer la cadena */
    while (i < 49 && (c = getchar()) != '\n' && c != EOF) {
        fra[i++] = c;
    }
    fra[i] = '\0';

    /* Limpiamos el buffer */
    fflush(stdin);

    /* Se copia a aux el resultado de la función inverso */
    strcpy(aux, inverso(fra));

    printf("\nEscribe la linea de texto en forma inversa: ");
    puts(aux);
}

char * inverso(char *cadena)
/* Esta función invierte la cadena in situ y retorna el puntero */
{
    int i = 0, j;
    int lon;
    char temp;

    lon = strlen(cadena);
    j = lon - 1;

    /* La condición debe ser i < lon / 2 para asegurar
       que recorra hasta el punto medio exacto.
    */
    while (i < (lon / 2))
    {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;

        i++;
        j--;
    }
    return (cadena);
}
