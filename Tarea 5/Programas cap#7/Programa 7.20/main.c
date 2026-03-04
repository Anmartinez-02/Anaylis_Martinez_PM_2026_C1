#include <stdio.h>
#include <string.h>

/* Prototipo de función corregido: recibe un puntero a char */
int longitud(char *cadena);

void main(void)
{
    int i, n, l = -1, p = 0, t;
    char FRA[20][50];
    char c;

    printf("\nIngrese el numero de filas del arreglo (max 20): ");
    scanf("%d", &n);

    /* Limpiamos el buffer despues del scanf para que el proximo
       getchar no lea el 'enter' pendiente */
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea de texto %d: ", i + 1);

        /* Uso de getchar para leer cada cadena */
        int j = 0;
        while (j < 49 && (c = getchar()) != '\n' && c != EOF) {
            FRA[i][j++] = c;
        }
        FRA[i][j] = '\0';

        fflush(stdin); // Limpiamos tras cada cadena
    }

    for (i = 0; i < n; i++)
    {
        t = longitud(FRA[i]);
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("Longitud: %d\n", l);
}

int longitud(char *cadena)
/* Esta función calcula la longitud de la cadena de forma manual */
{
    int cue = 0;
    /* Corregido: mientras el caracter actual NO sea el nulo */
    while (cadena[cue] != '\0') {
        cue++;
    }
    return (cue);
}
