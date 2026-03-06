#include <stdio.h>
#include <ctype.h>  /* Necesaria para islower e isupper */
#include <stdlib.h>

/* Prototipo de función */
void minymay(FILE *);

void main(void)
{
    FILE *ar;

    /* Intentamos abrir el archivo arc5.txt en modo lectura */
    if ((ar = fopen("arc5.txt", "r")) != NULL)
    {
        minymay(ar);
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo arc5.txt");
    }

    /* Pausa para que el usuario vea el resultado */
    printf("\n\nPresione Enter para salir...");
    fflush(stdout);
    getchar();
}

void minymay(FILE *arc)
/* Esta función cuenta el número de minúsculas y mayúsculas */
{
    int min = 0, may = 0;
    int p; // Usamos int para capturar correctamente el EOF

    /* Leemos hasta encontrar el fin del archivo */
    while ((p = fgetc(arc)) != EOF)
    {
        if (islower(p))
        {
            min++;
        }
        else if (isupper(p))
        {
            may++;
        }
    }

    printf("\nNumero de minusculas: %d", min);
    printf("\nNumero de mayusculas: %d", may);
}
