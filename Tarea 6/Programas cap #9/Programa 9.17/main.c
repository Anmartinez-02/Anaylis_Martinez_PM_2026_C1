#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototipo de función */
void cambia(FILE *, FILE *);

int main(void)
{
    FILE *ar;
    FILE *ap;

    /* Abrimos arc.txt para lectura y arc1.txt para escritura */
    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
        printf("Proceso de correccion completado. Revise 'arc1.txt'.\n");
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }

    /* Pausa final personalizada con getchar */
    printf("\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
/* Busca "méxico" y lo cambia por "México" */
{
    char cad[30], cad1[30], aux[30];
    char *cad2;
    int i, j, k;

    while (fgets(cad, 30, ap1) != NULL)
    {
        strcpy(cad1, cad);
        /* strstr busca la primera aparicion de "méxico" */
        cad2 = strstr(cad1, "méxico");

        while (cad2 != NULL)
        {
            /* Reemplaza la 'm' por 'M' */
            cad2[0] = 'M';

            i = strlen(cad1);
            j = strlen(cad2);
            k = i - j;

            if (k > 0)
            {
                /* Copia la parte anterior a la palabra corregida */
                strncpy(aux, cad1, k);
                aux[k] = '\0';
                /* Une la parte anterior con la palabra ya corregida */
                strcat(aux, cad2);
                strcpy(cad1, aux);
            }
            else
            {
                strcpy(cad1, cad2);
            }

            /* Busca si hay mas ocurrencias en la misma linea */
            cad2 = strstr(cad1, "méxico");
        }
        /* Escribe el resultado en el segundo archivo */
        fputs(cad1, ap2);
    }
}
