#include <stdio.h>
#include <stdlib.h> /* Necesaria para atof */

/* Prototipo de función */
void sumypro(FILE *);

int main(void)
{
    FILE *ap;

    /* Abrimos el archivo arc2.txt para lectura */
    if ((ap = fopen("arc2.txt", "r")) != NULL)
    {
        sumypro(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo arc2.txt");
    }

    /* Pausa final personalizada */
    printf("\n\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void sumypro(FILE *ap1)
/* Esta función lee cadenas, detecta números al inicio y promedia */
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    /* Leemos mientras no lleguemos al final del archivo */
    while (fgets(cad, 30, ap1) != NULL)
    {
        /* atof convierte el inicio de la cadena en un número real */
        r = atof(cad);

        /* Si r es distinto de cero, se encontró un número válido */
        if (r != 0.0)
        {
            i++;
            sum += r;
        }
    }

    printf("\nSuma total: %.2f", sum);

    if (i != 0)
    {
        printf("\nPromedio: %.2f", sum / i);
    }
    else
    {
        printf("\nNo se encontraron valores numericos validos.");
    }
}
