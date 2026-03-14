#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones
float** crearMatriz(int filas, int cols);
void liberarMatriz(float** matriz, int filas);
void imprimirMatriz(float** matriz, int filas, int cols);
void llenarTeclado(float** matriz, int filas, int cols);
float** leerDesdeArchivo(char* nombreArchivo, int* filas, int* cols);
float** sumarMatrices(float** A, float** B, int filas, int cols);

int main() {
    int f, c, opcion;
    float **A = NULL, **B = NULL, **Resultado = NULL;

    printf("--- Calculadora de Matrices Dinamicas ---\n");
    printf("1. Leer matrices desde teclado\n");
    printf("2. Leer matrices desde archivo (formato CSV)\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    fflush(stdin); // Limpiar el buffer tras leer entero

    if (opcion == 1) {
        printf("Ingrese filas y columnas: ");
        scanf("%d %d", &f, &c);
        fflush(stdin);

        A = crearMatriz(f, c);
        B = crearMatriz(f, c);

        printf("\nLlenar Matriz A:\n");
        llenarTeclado(A, f, c);
        printf("\nLlenar Matriz B:\n");
        llenarTeclado(B, f, c);
    } else {
        // Ejemplo: archivo.txt debe tener f,c en la primera linea y luego los datos
        A = leerDesdeArchivo("matrizA.txt", &f, &c);
        B = leerDesdeArchivo("matrizB.txt", &f, &c);
        if (!A || !B) return 1;
    }

    Resultado = sumarMatrices(A, B, f, c);

    printf("\nResultado de la Suma:\n");
    imprimirMatriz(Resultado, f, c);

    // Liberacion de memoria
    liberarMatriz(A, f);
    liberarMatriz(B, f);
    liberarMatriz(Resultado, f);

    printf("\nPresione cualquier tecla para salir...");
    getchar(); // Uso de getchar segun tu preferencia
    return 0;
}

// --- Implementacion de Funciones ---

float** crearMatriz(int filas, int cols) {
    float** m = (float**)malloc(filas * sizeof(float*));
    for (int i = 0; i < filas; i++) {
        m[i] = (float*)malloc(cols * sizeof(float));
    }
    return m;
}

void llenarTeclado(float** matriz, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
            fflush(stdin);
        }
    }
}

float** sumarMatrices(float** A, float** B, int filas, int cols) {
    float** res = crearMatriz(filas, cols);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
    return res;
}

float** leerDesdeArchivo(char* nombreArchivo, int* filas, int* cols) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir %s\n", nombreArchivo);
        return NULL;
    }
    // Formato esperado: primera linea "filas,cols"
    fscanf(archivo, "%d,%d", filas, cols);

    float** m = crearMatriz(*filas, *cols);
    for (int i = 0; i < *filas; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(archivo, "%f,", &m[i][j]);
        }
    }
    fclose(archivo);
    return m;
}

void imprimirMatriz(float** matriz, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(float** matriz, int filas) {
    for (int i = 0; i < filas; i++) free(matriz[i]);
    free(matriz);
}
