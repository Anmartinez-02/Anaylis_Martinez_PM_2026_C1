#include <stdio.h>
#include <stdlib.h>

/* Declaracion de la estructura para materias y calificaciones */
typedef struct {
    char materia[20];
    int calificacion;
} matcal;

/* Declaracion de la estructura alumno con estructura anidada */
typedef struct {
    int matricula;
    char nombre[20];
    matcal cal[5]; /* Arreglo de estructuras */
} alumno;

/* Prototipos de funciones */
void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

int main(void) {
    float pro;
    FILE *ap;

    /* Abrimos el archivo en modo lectura binaria */
    if ((ap = fopen("esc.dat", "rb")) != NULL) {
        F1(ap);
        F2(ap);
        pro = F3(ap);
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %.2f", pro);
        fclose(ap);
    } else {
        printf("\nEl archivo 'esc.dat' no se puede abrir o no existe.");
    }

    /* Tu preferencia: pausa final personalizada */
    printf("\n\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void F1(FILE *ap) {
    /* Escribe la matricula y el promedio de cada alumno */
    alumno alu;
    int j;
    float sum, pro;

    rewind(ap);
    printf("\n--- MATRICULAS Y PROMEDIOS ---");

    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        printf("\nMatricula: %d", alu.matricula);
        sum = 0.0;
        for (j = 0; j < 5; j++) {
            sum += alu.cal[j].calificacion;
        }
        pro = sum / 5;
        printf("\tPromedio: %.2f", pro);
        fread(&alu, sizeof(alumno), 1, ap);
    }
}

void F2(FILE *ap) {
    /* Alumnos con calificacion > 9 en la materia 3 (indice 2) */
    alumno alu;
    rewind(ap);
    printf("\n\n--- ALUMNOS CON CALIFICACION > 9 EN MATERIA 3 ---");

    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        if (alu.cal[2].calificacion > 9) {
            printf("\nMatricula del alumno: %d", alu.matricula);
        }
        fread(&alu, sizeof(alumno), 1, ap);
    }
}

float F3(FILE *ap) {
    /* Promedio general de la materia 4 (indice 3) entre todos los alumnos */
    alumno alu;
    int i = 0;
    float sum = 0, pro;

    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        i++;
        sum += alu.cal[3].calificacion;
        fread(&alu, sizeof(alumno), 1, ap);
    }

    if (i > 0) {
        pro = (float)sum / i;
    } else {
        pro = 0.0;
    }

    return pro;
}
