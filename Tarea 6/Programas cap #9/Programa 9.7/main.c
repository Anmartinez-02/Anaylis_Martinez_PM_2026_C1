#include <stdio.h>

/* Prototipo de la función. Recibe un puntero a FILE como parámetro. */
void promedio(FILE *ar1);

int main(void)
{
    FILE *ar;

    /* Intentamos abrir el archivo "arc9.txt" en modo lectura */
    if ((ar = fopen("arc9.txt", "r")) != NULL)
    {
        // Se llama a la función pasando el puntero del archivo
        promedio(ar);

        // El archivo se cierra siempre en el programa principal
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo arc9.txt\n");
    }

    printf("\nProceso terminado. Presione Enter para salir...");
    fflush(stdin); // Limpieza de búfer
    getchar();     // Pausa de ejecución
    return 0;
}

/* Función que lee datos y calcula el promedio por alumno */
void promedio(FILE *ar1)
{
    int i, j, n, mat;
    float pro, cal;

    // Leemos la cantidad total de alumnos (n)
    if (fscanf(ar1, "%d", &n) != EOF)
    {
        printf("Matricula\tPromedio\n");
        printf("--------------------------\n");

        for (i = 0; i < n; i++)
        {
            // Leemos la matrícula del alumno
            fscanf(ar1, "%d", &mat);
            printf("%d\t", mat);

            pro = 0;
            // Leemos las 5 calificaciones y las sumamos
            for (j = 0; j < 5; j++)
            {
                fscanf(ar1, "%f", &cal);
                pro += cal;
            }

            // Calculamos y mostramos el promedio
            printf("\t %.2f\n", pro / 5);
        }
    }
    else
    {
        printf("El archivo esta vacio.\n");
    }
}
