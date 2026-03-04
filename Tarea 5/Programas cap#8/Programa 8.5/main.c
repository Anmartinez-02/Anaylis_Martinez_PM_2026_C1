#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 1. Definición de la unión: celular y correo comparten el mismo espacio */
union datos {
    char celular[15];
    char correo[20];
};

/* 2. Estructura que contiene la unión */
typedef struct {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
} alumno;

/* Prototipo de la función de lectura */
void Lectura(alumno *a);

int main(void) {
    // Inicialización de a1 (solo se puede inicializar el primer campo de la unión)
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, .personales.celular = "5-158-40-50"};
    alumno a2, a3;

    // --- Registro Alumno 2 ---
    printf("--- Registro Alumno 2 ---\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    while (getchar() != '\n'); // Limpiamos el buffer del teclado 🧹

    printf("Ingrese el nombre: ");
    gets(a2.nombre);

    printf("Ingrese la carrera: ");
    gets(a2.carrera);

    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    while (getchar() != '\n');

    // Aquí asignamos el SEGUNDO campo de la unión (correo)
    printf("Ingrese el correo electronico: ");
    gets(a2.personales.correo);

    // --- Registro Alumno 3 (usando la función) ---
    printf("\n--- Registro Alumno 3 ---\n");
    Lectura(&a3);

    /* --- Impresión de Resultados --- */
    printf("\n==============================");
    printf("\nDATOS DEL ALUMNO 1 (Celular original)");
    printf("\nMatricula: %d\nNombre: %s\nCelular: %s", a1.matricula, a1.nombre, a1.personales.celular);

    printf("\n\nDATOS DEL ALUMNO 2 (Correo asignado)");
    printf("\nMatricula: %d\nNombre: %s\nCorreo: %s", a2.matricula, a2.nombre, a2.personales.correo);
    printf("\nIntentando leer celular de Alumno 2 (Basura): %s", a2.personales.celular);

    printf("\n\nDATOS DEL ALUMNO 3");
    printf("\nMatricula: %d\nNombre: %s\nCelular: %s", a3.matricula, a3.nombre, a3.personales.celular);
    printf("\n==============================\n");

    return 0;
}

/* Función para leer datos usando un apuntador */
void Lectura(alumno *a) {
    printf("Matricula: ");
    scanf("%d", &a->matricula);
    while (getchar() != '\n');

    printf("Nombre: ");
    gets(a->nombre);

    printf("Carrera: ");
    gets(a->carrera);

    printf("Promedio: ");
    scanf("%f", &a->promedio);
    while (getchar() != '\n');

    printf("Telefono celular: ");
    gets(a->personales.celular);
}
