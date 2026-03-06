#include <stdio.h>
#include <stdlib.h>

/* Prototipo de función */
void mezcla(FILE *, FILE *, FILE *);

void main(void)
{
    FILE *ar, *ar1, *ar2;

    /* Intentamos abrir los archivos. arc9 y arc10 deben existir y estar ordenados. */
    ar = fopen("arc9.dat", "r");
    ar1 = fopen("arc10.dat", "r");
    ar2 = fopen("arc11.dat", "w");

    if (((ar != NULL) && (ar1 != NULL)) && (ar2 != NULL))
    {
        mezcla(ar, ar1, ar2);
        fclose(ar);
        fclose(ar1);
        fclose(ar2);
        printf("Mezcla completada exitosamente en arc11.dat\n");
    }
    else
    {
        printf("No se pueden abrir los archivos. Asegurate de que arc9.dat y arc10.dat existan.\n");
    }

    /* Pausa final personalizada */
    printf("\nPresione Enter para salir...");
    fflush(stdout);
    getchar();
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
/* Esta función mezcla dos archivos ordenados por matrícula. */
{
    int i, mat, mat1, b = 1, b1 = 1;
    float ca[3], ca1[3], cal;

    /*  */

    /* Ciclo principal: mientras haya datos en ambos archivos */
    while (((!feof(ar)) || !b) && ((!feof(ar1)) || !b1))
    {
        if (b && !feof(ar))
        {
            if (fscanf(ar, "%d", &mat) != EOF)
            {
                for (i = 0; i < 3; i++)
                    fscanf(ar, "%f", &ca[i]);
                b = 0;
            }
        }
        if (b1 && !feof(ar1))
        {
            if (fscanf(ar1, "%d", &mat1) != EOF)
            {
                for (i = 0; i < 3; i++)
                    fscanf(ar1, "%f", &ca1[i]);
                b1 = 0;
            }
        }

        if (mat < mat1)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%.2f\t", ca[i]);
            fputs("\n", ar2);
            b = 1; // Bandera para leer el siguiente de 'ar'
        }
        else
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
                fprintf(ar2, "%.2f\t", ca1[i]);
            fputs("\n", ar2);
            b1 = 1; // Bandera para leer el siguiente de 'ar1'
        }
    }

    /* Procesar el sobrante de arc9.dat si lo hay */
    if (!b)
    {
        fprintf(ar2, "%d\t", mat);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%.2f\t", ca[i]);
        fputs("\n", ar2);
        while (fscanf(ar, "%d", &mat) != EOF)
        {
            fprintf(ar2, "%d\t", mat);
            for (i = 0; i < 3; i++)
            {
                fscanf(ar, "%f", &cal);
                fprintf(ar2, "%.2f\t", cal);
            }
            fputs("\n", ar2);
        }
    }

    /* Procesar el sobrante de arc10.dat si lo hay */
    if (!b1)
    {
        fprintf(ar2, "%d\t", mat1);
        for (i = 0; i < 3; i++)
            fprintf(ar2, "%.2f\t", ca1[i]);
        fputs("\n", ar2);
        while (fscanf(ar1, "%d", &mat1) != EOF)
        {
            fprintf(ar2, "%d\t", mat1);
            for (i = 0; i < 3; i++)
            {
                fscanf(ar1, "%f", &cal);
                fprintf(ar2, "%.2f\t", cal);
            }
            fputs("\n", ar2);
        }
    }
}
