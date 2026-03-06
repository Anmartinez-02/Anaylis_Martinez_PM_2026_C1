#include <stdio.h>
#include <string.h>

/* Declaración de la estructura alumno */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de función */
void escribe(FILE *ap);

int main(void)
{
    FILE *ar;

    /* Abrimos el archivo en modo "wb" (Write Binary / Escritura Binaria) */
    if ((ar = fopen("ad1.dat", "wb")) != NULL)
    {
        escribe(ar);
        fclose(ar);
        printf("\nDatos guardados exitosamente en ad1.dat\n");
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }

    printf("\nPresione Enter para salir...");
    fflush(stdin);
    getchar();
    return 0;
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0, r;

    printf("\n¿Desea ingresar informacion sobre alumnos? (Si-1 No-0): ");
    scanf("%d", &r);

    while (r)
    {
        i++;
        printf("\n--- Alumno %d ---\n", i);

        printf("Matricula: ");
        scanf("%d", &alu.matricula);

        printf("Nombre: ");
        fflush(stdin); // Limpiamos el búfer antes de leer el nombre
        fgets(alu.nombre, 20, stdin);
        // Eliminamos el salto de línea que fgets agrega al final
        alu.nombre[strcspn(alu.nombre, "\n")] = '\0';

        printf("Carrera (Codigo): ");
        scanf("%d", &alu.carrera);

        printf("Promedio: ");
        scanf("%f", &alu.promedio);

        /* fwrite guarda la estructura completa en el archivo */
        fwrite(&alu, sizeof(alumno), 1, ap);

        printf("\n¿Desea ingresar informacion sobre mas alumnos? (Si-1 No-0): ");
        scanf("%d", &r);
    }
}
