#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Estructuras */
typedef struct {
    char zona[20];
    char calle[20];
    char colo[20];        /* Colonia */
} ubicacion;

typedef struct {
    char clave[5];
    float scu;            /* Superficie cubierta */
    float ste;            /* Superficie terreno */
    char car[50];         /* Características */
    ubicacion ubi;        /* Estructura anidada */
    float precio;
    char dispo;           /* Disponibilidad: V (Venta), R (Renta) */
} propiedades;

/* Prototipos de funciones */
void Lectura(propiedades A[], int T);
void F1(propiedades A[], int T);
void F2(propiedades A[], int T);

int main(void) {
    propiedades PROPIE[100];
    int TAM;

    do {
        printf("Ingrese el numero de propiedades: ");
        scanf("%d", &TAM);
        fflush(stdin); // Limpieza de buffer tras leer entero
    } while (TAM > 100 || TAM < 1);

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    printf("\nPresione ENTER para finalizar...");
    fflush(stdout);
    getchar(); // Pausa final
    return 0;
}

void Lectura(propiedades A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n--- Ingrese datos de la propiedad %d ---\n", I + 1);
        printf("Clave: ");
        fflush(stdin);
        gets(A[I].clave);

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);

        printf("Caracteristicas: ");
        fflush(stdin);
        gets(A[I].car);

        printf("Zona: ");
        gets(A[I].ubi.zona);

        printf("Calle: ");
        gets(A[I].ubi.calle);

        printf("Colonia: ");
        gets(A[I].ubi.colo);

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        printf("Disponibilidad (V-Venta / R-Renta): ");
        fflush(stdin);
        A[I].dispo = getchar(); // Uso de getchar para un solo caracter
    }
}

void F1(propiedades A[], int T) {
    int I;
    printf("\n\tListado de Propiedades para Venta (450k - 650k)\n");
    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V' || A[I].dispo == 'v') &&
            (A[I].precio >= 450000) && (A[I].precio <= 650000)) {
            printf("\nClave: %s", A[I].clave);
            printf("\nSuperficie cubierta: %.2f", A[I].scu);
            printf("\nSuperficie terreno: %.2f", A[I].ste);
            printf("\nCaracteristicas: %s", A[I].car);
            printf("\nCalle: %s", A[I].ubi.calle);
            printf("\nColonia: %s", A[I].ubi.colo);
            printf("\nPrecio: %.2f\n", A[I].precio);
        }
    }
}

void F2(propiedades A[], int T) {
    int I;
    float li, ls;
    char zon[20];

    printf("\n\tListado de Propiedades para Renta");
    printf("\nIngrese zona geografica: ");
    fflush(stdin);
    gets(zon);

    printf("Ingrese el limite inferior del precio: ");
    scanf("%f", &li);
    printf("Ingrese el limite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R' || A[I].dispo == 'r') &&
            (strcmp(A[I].ubi.zona, zon) == 0) &&
            (A[I].precio >= li) && (A[I].precio <= ls)) {

            printf("\nClave: %s", A[I].clave);
            printf("\nSuperficie cubierta: %.2f", A[I].scu);
            printf("\nSuperficie terreno: %.2f", A[I].ste);
            printf("\nCaracteristicas: %s", A[I].car);
            printf("\nCalle: %s", A[I].ubi.calle);
            printf("\nColonia: %s", A[I].ubi.colo);
            printf("\nPrecio: %.2f\n", A[I].precio);
        }
    }
}
