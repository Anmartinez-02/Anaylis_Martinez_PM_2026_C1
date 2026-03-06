#include <stdio.h>

/* Declaración de la estructura alumno (debe ser igual a la del programa anterior) */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de función */
void lee(FILE *ap);

int main(void)
{
    FILE *ar;

    /* Abrimos el archivo en modo "rb" (Read Binary / Lectura Binaria) */
    if ((ar = fopen("ad1.dat", "rb")) != NULL)
    {
        lee(ar);   /* Llamamos a la función de lectura */
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir. Asegurate de que 'ad1.dat' exista.\n");
    }

    printf("\n\nPresione Enter para salir...");
    fflush(stdin);
    getchar(); // Pausa para ver los resultados
    return 0;
}

void lee(FILE *ap)
{
    alumno alu;

    /* Realizamos una primera lectura antes del ciclo.
       fread devuelve el número de elementos leídos exitosamente.
    */
    fread(&alu, sizeof(alumno), 1, ap);

    /* El ciclo se ejecuta mientras no lleguemos al final del archivo (EOF) */
    while (!feof(ap))
    {
        printf("\nMatricula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %.2f", alu.promedio);
        printf("\tNombre: %s", alu.nombre);

        /* Leemos el siguiente registro al final del ciclo */
        fread(&alu, sizeof(alumno), 1, ap);
    }
}
