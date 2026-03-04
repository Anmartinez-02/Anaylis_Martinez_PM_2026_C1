#include <stdio.h>
#include <string.h>

/* Estructuras-1.
El programa muestra cómo declarar una estructura y acceder a sus campos
mediante variables normales para asignación, lectura y escritura. */

struct alumno {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
}; // La declaración termina con punto y coma.

int main(void) {
    // Declaración e inicialización de variables tipo estructura
    struct alumno a1 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno a2, a3;

    char nom[20], car[20], dir[20];
    int mat;
    float pro;

    // --- Lectura de datos para a2 ---
    printf("\nIngrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);

    // Limpieza de buffer necesaria antes de usar gets o fgets
    while (getchar() != '\n');

    printf("Ingrese el nombre del alumno 2: ");
    gets(a2.nombre);

    printf("Ingrese la carrera del alumno 2: ");
    gets(a2.carrera);

    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);

    while (getchar() != '\n');

    printf("Ingrese la direccion del alumno 2: ");
    gets(a2.direccion);

    // --- Asignación manual para a3 ---
    printf("\nIngrese la matricula del alumno 3: ");
    scanf("%d", &mat);
    a3.matricula = mat;

    while (getchar() != '\n');

    printf("Ingrese el nombre del alumno 3: ");
    gets(nom);
    strcpy(a3.nombre, nom); // Copiamos la cadena al campo de la estructura

    printf("Ingrese la carrera del alumno 3: ");
    gets(car);
    strcpy(a3.carrera, car);

    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio = pro;

    while (getchar() != '\n');

    printf("Ingrese la direccion del alumno 3: ");
    gets(dir);
    strcpy(a3.direccion, dir);

    // --- Impresión de resultados ---
    printf("\nDatos del alumno 1\n");
    printf("%d\n%s\n%s\n%.2f\n%s\n", a1.matricula, a1.nombre, a1.carrera, a1.promedio, a1.direccion);

    printf("\nDatos del alumno 2\n");
    printf("%d\n%s\n%s\n%.2f\n%s\n", a2.matricula, a2.nombre, a2.carrera, a2.promedio, a2.direccion);

    printf("\nDatos del alumno 3\n");
    printf("%d \t %s \t %s \t %.2f \t %s\n", a3.matricula, a3.nombre, a3.carrera, a3.promedio, a3.direccion);

    return 0;
}
