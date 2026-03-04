#include <stdio.h>
#include <string.h>

/* Prototipo de función corregido */
void intercambia(char FRA[][30], int n);

void main(void)
{
    int i, n;
    char FRA[20][30];
    char c;

    printf("\nIngrese el numero de filas del arreglo (max 20): ");
    scanf("%d", &n);
    fflush(stdin); // Limpiamos el buffer tras el scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea de texto numero %d: ", i + 1);

        /* Uso de getchar para leer la cadena según tu preferencia */
        int k = 0;
        while (k < 29 && (c = getchar()) != '\n' && c != EOF) {
            FRA[i][k++] = c;
        }
        FRA[i][k] = '\0'; // Terminación de la cadena

        fflush(stdin); // Limpiamos el buffer para la siguiente lectura
    }

    printf("\n\n--- Intercambiando filas ---\n\n");
    intercambia(FRA, n);

    for(i = 0; i < n; i++)
    {
        printf("Impresion de la linea de texto %d: ", i + 1);
        puts(FRA[i]);
    }
}

void intercambia(char FRA[][30], int n)
/* Esta función intercambia las filas del arreglo (la primera con la última, etc.) */
{
    int i, j;
    char cad[30];
    j = n - 1;

    for(i = 0; i < (n / 2); i++)
    {
        /* Intercambio de cadenas usando una variable auxiliar */
        strcpy(cad, FRA[i]);
        strcpy(FRA[i], FRA[j]);
        strcpy(FRA[j], cad);

        j--; // Decremento corregido
    }
}
