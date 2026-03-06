#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  /* Necesaria para islower e isupper */

/* Prototipo de función */
void minymay(FILE *);

int main(void)
{
    FILE *ap;

    /* Intentamos abrir el archivo arc.txt en modo lectura ("r") */
    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo arc.txt");
    }

    /* Pausa final usando tu preferencia: getchar */
    printf("\n\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void minymay(FILE *ap1)
/* Esta función lee cadenas de caracteres y cuenta minúsculas y mayúsculas */
{
    char cad[30];
    int i, mi = 0, ma = 0;

    /* Leemos bloques de hasta 30 caracteres hasta llegar al fin del archivo */
    while (fgets(cad, 30, ap1) != NULL)
    {
        i = 0;
        /* Recorremos la cadena leída hasta encontrar el fin de cadena '\0' */
        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
            {
                mi++;
            }
            else if (isupper(cad[i]))
            {
                ma++;
            }
            i++;
        }
    }

    printf("\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}
