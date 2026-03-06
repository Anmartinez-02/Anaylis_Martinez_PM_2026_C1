#include <stdio.h>

/* Declaración de la estructura alumno */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de función */
void modifica(FILE *ap);

int main(void)
{
    FILE *ar;

    /* "r+b" abre el archivo para lectura y escritura sin borrar el contenido */
    if ((ar = fopen("ad1.dat", "r+b")) != NULL)
    {
        modifica(ar);
        fclose(ar);
        printf("\nArchivo actualizado correctamente.\n");
    }
    else
    {
        printf("\nEl archivo no se puede abrir. Asegurate de que 'ad1.dat' exista.");
    }

    printf("\nPresione Enter para salir...");
    fflush(stdin);
    getchar();
    return 0;
}

void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nIngrese el numero de registro que desea modificar (1, 2, ...): ");
    scanf("%d", &d);

    /* fseek posiciona el puntero en el registro deseado */
    /* (d-1) porque en C los registros empiezan en la posición 0 */
    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

    /* Leemos el registro actual para cargarlo en la variable 'alu' */
    if (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        printf("\nAlumno actual: %s", alu.nombre);
        printf("\nPromedio actual: %.2f", alu.promedio);

        printf("\n\nIngrese el nuevo promedio del alumno: ");
        scanf("%f", &alu.promedio);

        /* MUY IMPORTANTE: Después de leer, el puntero avanzó al siguiente registro.
           Debemos regresar el puntero al inicio del registro que queremos modificar. */
        fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);

        /* Sobreescribimos el registro con el promedio actualizado */
        fwrite(&alu, sizeof(alumno), 1, ap);

        printf("\nRegistro modificado con exito.");
    }
    else
    {
        printf("\nError: El registro no existe.");
    }
}
