#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *);
void crearArchivoSiNoExiste(); // Nueva función de apoyo

int main(void) {
    FILE *ar;

    // Intentamos abrirlo. Si no existe, lo creamos primero.
    ar = fopen("ad5.dat", "r+");

    if (ar == NULL) {
        printf("El archivo no existe. Creando uno de prueba...\n");
        crearArchivoSiNoExiste();
        // Intentamos abrirlo de nuevo después de crearlo
        ar = fopen("ad5.dat", "r+");
    }

    if (ar != NULL) {
        incrementa(ar);
        rewind(ar);
        fclose(ar);
        printf("\nProceso de incremento finalizado con exito.\n");
    } else {
        printf("\nError critico: No se pudo acceder al archivo.\n");
    }

    printf("\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void crearArchivoSiNoExiste() {
    FILE *temp = fopen("ad5.dat", "wb");
    if (temp != NULL) {
        // Creamos un empleado de prueba con ventas de 100k al mes (1.2M al año)
        // para que el programa de incremento tenga algo que actualizar.
        empleado prueba = {101, 5, 1000.0, {100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000}};
        fwrite(&prueba, sizeof(empleado), 1, temp);
        fclose(temp);
        printf("Archivo 'ad5.dat' generado con un empleado de prueba (Salario inicial: 1000.0).\n");
    }
}

void incrementa(FILE *ap) {
    int i, j;
    long t;
    float sum;
    empleado emple;

    t = sizeof(empleado);
    fread(&emple, sizeof(empleado), 1, ap);

    while (!feof(ap)) {
        i = ftell(ap) / t;
        sum = 0;
        for (j = 0; j < 12; j++) {
            sum += emple.ventas[j];
        }

        if (sum > 1000000) {
            float salarioAnterior = emple.salario;
            emple.salario = emple.salario * 1.10;

            fseek(ap, (i - 1) * sizeof(empleado), SEEK_SET);
            fwrite(&emple, sizeof(empleado), 1, ap);
            fseek(ap, i * sizeof(empleado), SEEK_SET);

            printf("Empleado ID %d actualizado: %.2f -> %.2f\n", emple.clave, salarioAnterior, emple.salario);
        }
        fread(&emple, sizeof(empleado), 1, ap);
    }
}
