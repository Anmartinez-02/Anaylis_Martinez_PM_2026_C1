#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {

    int n, i;
    FILE *archivo;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    srand(time(NULL));

    // Crear archivo con numeros aleatorios
    archivo = fopen("numeros.txt", "w");

    for(i = 0; i < n; i++) {
        int num = rand() % 1000;
        fprintf(archivo, "%d\n", num);
    }

    fclose(archivo);

    // Reservar memoria dinamica
    int *numeros = (int*) malloc(n * sizeof(int));

    // Leer los numeros del archivo
    archivo = fopen("numeros.txt", "r");

    for(i = 0; i < n; i++) {
        fscanf(archivo, "%d", &numeros[i]);
    }

    fclose(archivo);

    // Ordenar numeros
    qsort(numeros, n, sizeof(int), comparar);

    // Guardar numeros ordenados en otro archivo
    archivo = fopen("ordenados.txt", "w");

    for(i = 0; i < n; i++) {
        fprintf(archivo, "%d\n", numeros[i]);
    }

    fclose(archivo);

    // Liberar memoria
    free(numeros);

    printf("Proceso terminado. Revisar archivos numeros.txt y ordenados.txt\n");

    return 0;
}
