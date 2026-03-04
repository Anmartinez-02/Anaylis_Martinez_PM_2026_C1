#include <stdio.h>
#include <string.h>

/* Definición de la estructura usando typedef */
typedef struct {
    int matricula;
    char nombre[30];
    float cal[5];
} alumno;

/* Prototipos de funciones */
void Lectura(alumno A[], int T);
void F1(alumno A[], int T);
void F2(alumno A[], int T);
void F3(alumno A[], int T);

int main(void) {
    alumno ARRE[50];
    int TAM;

    // Validación del tamaño del arreglo
    do {
        printf("Ingrese el numero de alumnos (1-50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1);

    // Llamada a las funciones
    Lectura(ARRE, TAM);
    F1(ARRE, TAM);
    F2(ARRE, TAM);
    F3(ARRE, TAM);

    return 0;
}

/* Función para leer los datos de los alumnos */
void Lectura(alumno A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\n--- Datos del alumno %d ---\n", I + 1);
        printf("Matricula: ");
        scanf("%d", &A[I].matricula);

        // Limpiamos el buffer para que gets() no falle
        while (getchar() != '\n');

        printf("Nombre: ");
        gets(A[I].nombre);

        for (J = 0; J < 5; J++) {
            printf("\tCalificacion materia %d: ", J + 1);
            scanf("%f", &A[I].cal[J]);
        }
    }
}

/* Función F1: Calcula promedio por alumno */
void F1(alumno A[], int T) {
    int I, J;
    float SUM, PRO;
    printf("\n--- Promedios Individuales ---");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 5; J++) {
            SUM += A[I].cal[J];
        }
        PRO = SUM / 5;
        printf("\nMatricula %d - Promedio: %.2f", A[I].matricula, PRO);
    }
}

/* Función F2: Alumnos con materia 3 > 9 */
void F2(alumno A[], int T) {
    int I;
    printf("\n\n--- Alumnos con Calificacion > 9 en Materia 3 ---");
    for (I = 0; I < T; I++) {
        if (A[I].cal[2] > 9) {
            printf("\nMatricula: %d", A[I].matricula);
        }
    }
}

/* Función F3: Promedio grupal de la materia 4 */
void F3(alumno A[], int T) {
    int I;
    float SUM = 0.0, PRO;
    for (I = 0; I < T; I++) {
        SUM += A[I].cal[3];
    }
    PRO = SUM / T;
    printf("\n\nPromedio general Materia 4: %.2f\n", PRO);
}
