#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Estructura para manejar productos farmacéuticos */
typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

/* Prototipos de funciones */
void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

int main(void) {
    producto INV[100];
    int TAM, OPE;

    do {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(INV, TAM);

    printf("\nIngrese operacion a realizar.\n1 - Ventas\n2 - Reabastecimiento\n3 - Nuevos Productos\n4 - Inventario\n0 - Salir: ");
    scanf("%d", &OPE);

    while (OPE != 0) {
        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
            default: printf("\nOperacion no valida."); break;
        }
        printf("\nIngrese operacion a realizar.\n1 - Ventas\n2 - Reabastecimiento\n3 - Nuevos Productos\n4 - Inventario\n0 - Salir: ");
        scanf("%d", &OPE);
    }
    return 0;
}

void Lectura(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese informacion del producto %d", I + 1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);
        printf("\tNombre: ");
        scanf("%14s", A[I].nombre); // Uso de scanf limitado para evitar errores
        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;
    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);
    while (CLA != 0) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        I = 0;
        while ((I < T) && (A[I].clave < CLA)) I++;

        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nLa clave del producto es incorrecta");
        } else if (A[I].existencia >= CAN) {
            A[I].existencia -= CAN;
            PAR = A[I].precio * CAN;
            TOT += PAR;
        } else {
            printf("\nStock insuficiente. Solo hay %d. ¿Lleva el resto? (1-Si/0-No): ", A[I].existencia);
            scanf("%d", &RES);
            if (RES) {
                PAR = A[I].precio * A[I].existencia;
                A[I].existencia = 0;
                TOT += PAR;
            }
        }
        printf("\nIngrese clave del producto (0 para salir): ");
        scanf("%d", &CLA);
    }
    printf("\nTotal de la venta: %.2f\n", TOT);
}

void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I;
    printf("\n--- Reabastecimiento ---");
    printf("\nIngrese clave del producto (0 para salir): ");
    scanf("%d", &CLA);
    while (CLA != 0) {
        I = 0;
        while ((I < T) && (A[I].clave < CLA)) I++;
        if ((I == T) || (A[I].clave > CLA)) {
            printf("\nClave incorrecta.");
        } else {
            printf("\tCantidad a añadir: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;
        }
        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T) {
    int CLA, I, J;
    printf("\n--- Nuevos Productos ---");
    printf("\nIngrese clave: ");
    scanf("%d", &CLA);
    while ((*T < 100) && (CLA != 0)) {
        I = 0;
        while ((I < *T) && (A[I].clave < CLA)) I++;

        if (I < *T && A[I].clave == CLA) {
            printf("\nEl producto ya existe.");
        } else {
            for (J = *T; J > I; J--) A[J] = A[J - 1]; // Desplazar para mantener orden
            A[I].clave = CLA;
            printf("\tNombre: ");
            scanf("%14s", A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            *T = *T + 1;
        }
        printf("\nIngrese otra clave (0 para salir): ");
        scanf("%d", &CLA);
    }
}

void Inventario(producto A[], int T) {
    int I;
    printf("\n--- Inventario Actual ---");
    for (I = 0; I < T; I++) {
        printf("\nClave: %d | Nombre: %-15s | Precio: %6.2f | Stock: %d",
               A[I].clave, A[I].nombre, A[I].precio, A[I].existencia);
    }
    printf("\n");
}
