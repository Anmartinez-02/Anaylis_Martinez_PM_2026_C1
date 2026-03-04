#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Estructura para la dirección del paciente */
typedef struct {
    char cal[20]; /* Calle */
    int num;      /* Número */
    char col[20]; /* Colonia */
    char cp[5];   /* Código Postal */
    char ciu[20]; /* Ciudad */
} domicilio;

/* Estructura principal para el paciente */
typedef struct {
    char nom[20];  /* Nombre y apellido */
    int edad;
    char sexo;     /* F o M */
    int con;       /* Condición (1..5) */
    domicilio dom; /* Estructura anidada */
    char tel[10];  /* Teléfono */
} paciente;

/* Prototipos de funciones */
void Lectura(paciente A[], int T);
void F1(paciente A[], int T);
void F2(paciente A[], int T);
void F3(paciente A[], int T);

int main(void) {
    paciente HOSPITAL[100];
    int TAM;

    do {
        printf("Ingrese el numero de pacientes (1-50): ");
        scanf("%d", &TAM);
    } while(TAM > 50 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d", I + 1);
        while (getchar() != '\n'); /* Limpiar buffer antes de un string */

        printf("\nNombre: ");
        gets(A[I].nom);

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        printf("Sexo (F-M): ");
        while (getchar() != '\n'); /* Limpiar buffer para leer un char */
        scanf("%c", &A[I].sexo);

        printf("Condicion (1..5): ");
        scanf("%d", &A[I].con);
        while (getchar() != '\n');

        printf("\tCalle: ");
        gets(A[I].dom.cal);

        printf("\tNumero: ");
        scanf("%d", &A[I].dom.num);
        while (getchar() != '\n');

        printf("\tColonia: ");
        gets(A[I].dom.col);

        printf("\tCodigo Postal: ");
        gets(A[I].dom.cp);

        printf("\tCiudad: ");
        gets(A[I].dom.ciu);

        printf("Telefono: ");
        gets(A[I].tel);
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0, TOT;
    for (I = 0; I < T; I++) {
        if (A[I].sexo == 'F' || A[I].sexo == 'f') FEM++;
        else if (A[I].sexo == 'M' || A[I].sexo == 'm') MAS++;
    }
    TOT = FEM + MAS;
    if (TOT > 0) {
        printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
        printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
    } else {
        printf("\nNo hay datos de sexo registrados.");
    }
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        switch(A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }
    printf("\n\nNumero pacientes en condicion 1: %d", C1);
    printf("\nNumero pacientes en condicion 2: %d", C2);
    printf("\nNumero pacientes en condicion 3: %d", C3);
    printf("\nNumero pacientes en condicion 4: %d", C4);
    printf("\nNumero pacientes en condicion 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\n\nPacientes ingresados en estado de gravedad (5):");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("\nNombre: %s\tTelefono: %s", A[I].nom, A[I].tel);
        }
    }
    printf("\n");
}
