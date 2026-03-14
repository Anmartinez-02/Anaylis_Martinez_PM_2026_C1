#include <stdio.h>
#include <stdlib.h>

void limpiar_buffer() {
    fflush(stdout);
    // Limpia el buffer de entrada para evitar saltos en getchar
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    float valor_inicial, valor_final, depreciacion_total, mensualidad;
    int meses;

    printf("--- Simulador de Depreciacion de Vehiculos ---\n");

    printf("Ingrese el valor inicial del vehiculo: ");
    scanf("%f", &valor_inicial);

    printf("Ingrese el valor residual (precio final): ");
    scanf("%f", &valor_final);

    printf("Ingrese el tiempo de amortizacion (en meses): ");
    scanf("%d", &meses);
    limpiar_buffer(); // Limpiamos buffer despues de scanf

    // Calculos basicos
    depreciacion_total = valor_inicial - valor_final;
    mensualidad = depreciacion_total / meses;

    // Crear y escribir en el archivo de texto
    FILE *archivo = fopen("tabla_amortizacion.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    // Cabecera de la tabla
    fprintf(archivo, "%-10s | %-15s | %-15s\n", "Mes", "Depreciacion", "Valor Actual");
    fprintf(archivo, "---------------------------------------------\n");

    printf("\nGenerando tabla...\n");
    printf("%-10s | %-15s | %-15s\n", "Mes", "Depreciacion", "Valor Actual");
    printf("---------------------------------------------\n");

    float valor_actual = valor_inicial;
    for (int i = 1; i <= meses; i++) {
        valor_actual -= mensualidad;

        // Escribir en consola
        printf("%-10d | %-15.2f | %-15.2f\n", i, mensualidad, valor_actual);

        // Escribir en archivo
        fprintf(archivo, "%-10d | %-15.2f | %-15.2f\n", i, mensualidad, valor_actual);
    }

    fclose(archivo);
    printf("\nTabla guardada con exito en 'tabla_amortizacion.txt'.\n");

    printf("\nPresione ENTER para salir...");
    getchar(); // Uso de getchar para pausar antes de cerrar

    return 0;
}
