#include <stdio.h>

/* Prototipo de la función */
void lectura(FILE *ar);

int main(void)
{
    FILE *ar;

    // Intentamos abrir el archivo en modo lectura ("r")
    if ((ar = fopen("arc8.txt", "r")) != NULL)
    {
        lectura(ar); // Llamada a la función para procesar los datos
        fclose(ar);  // El archivo se cierra en el programa principal
    }
    else
    {
        printf("No se puede abrir el archivo. Asegurate de que 'arc8.txt' exista.\n");
    }

    printf("\nPresione Enter para finalizar...");
    fflush(stdin); // Limpieza de búfer antes del getchar
    getchar();
    return 0;
}

/* Función para realizar la lectura y cálculo de promedios */
void lectura(FILE *ar)
{
    int i, j, n, mat;
    float cal, pro;

    // Leemos la cantidad de alumnos (n)
    if (fscanf(ar, "%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            // Leemos la matrícula
            fscanf(ar, "%d", &mat);
            printf("%d\t", mat);

            pro = 0;
            // Leemos las 5 calificaciones por alumno
            for (j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal);
                pro += cal;
            }

            // Calculamos y mostramos el promedio
            printf("\t %.2f\n", pro / 5);
        }
    }
}
