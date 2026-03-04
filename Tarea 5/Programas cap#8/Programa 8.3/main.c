#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura domicilio
typedef struct {
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

// Definición de la estructura empleado (anidada)
struct empleado {
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; // Estructura física dentro de otra
};

// Prototipo de la función
void Lectura(struct empleado *a);

int main(void) {
    // Inicialización de e0
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
    struct empleado *e1, *e2, e4; // e3 eliminada para simplificar el ejemplo

    // --- Configuración de Empleado 1 (Apuntador) ---
    e1 = (struct empleado *)malloc(sizeof(struct empleado));

    printf("\n--- Registro Empleado 1 ---\n");
    printf("Nombre: ");
    scanf("%19s", e1->nombre); // Usamos %s limitado para seguridad
    fflush(stdin);

    printf("Departamento: ");
    scanf("%19s", e1->departamento);
    fflush(stdin);

    printf("Sueldo: ");
    scanf("%f", &e1->sueldo);
    fflush(stdin);

    printf("Calle: ");
    scanf("%19s", e1->direccion.calle);
    printf("Numero: ");
    scanf("%d", &e1->direccion.numero);
    printf("CP: ");
    scanf("%d", &e1->direccion.cp);
    fflush(stdin);
    printf("Localidad: ");
    scanf("%19s", e1->direccion.localidad);
    fflush(stdin);

    // --- Uso de la función Lectura ---
    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    printf("\n--- Registro Empleado 2 (vía función) ---");
    Lectura(e2);

    printf("\n--- Registro Empleado 4 (vía función) ---");
    Lectura(&e4);

    // --- Mostrar Resultados ---
    printf("\n\nRESUMEN DE DATOS:\n");
    printf("Emp 1: %s, %s, Sueldo: %.2f, Calle: %s\n", e1->nombre, e1->departamento, e1->sueldo, e1->direccion.calle);
    printf("Emp 4: %s, %s, Sueldo: %.2f, Calle: %s\n", e4.nombre, e4.departamento, e4.sueldo, e4.direccion.calle);

    // Liberar memoria dinámica
    free(e1);
    free(e2);

    return 0;
}

void Lectura(struct empleado *a) {
    printf("\nNombre del empleado: ");
    scanf("%19s", a->nombre);
    fflush(stdin);

    printf("Sueldo: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);

    printf("Calle de residencia: ");
    scanf("%19s", a->direccion.calle);
    fflush(stdin);
}
