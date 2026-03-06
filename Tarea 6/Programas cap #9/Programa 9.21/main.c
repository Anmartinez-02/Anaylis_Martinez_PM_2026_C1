#include <stdio.h>
#include <stdlib.h>

/* Declaracion de la estructura alumno */
typedef struct {
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

/* Prototipos de funciones */
float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);

int main(void) {
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    /* Apertura de archivos */
    ap = fopen("alu1.dat", "rb"); // Modo lectura binaria
    c1 = fopen("car1.dat", "wb+"); // Modo escritura/lectura binaria
    c2 = fopen("car2.dat", "wb+");
    c3 = fopen("car3.dat", "wb+");
    c4 = fopen("car4.dat", "wb+");
    c5 = fopen("car5.dat", "wb+");

    if (ap != NULL && c1 != NULL && c2 != NULL && c3 != NULL && c4 != NULL && c5 != NULL) {
        /* F1: Calcula promedio general del examen de admision */
        pro = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISION: %.2f\n", pro);

        /* F2: Clasifica alumnos en archivos por carrera */
        F2(ap, c1, c2, c3, c4, c5);

        /* F3: Calcula promedios de admitidos por carrera */
        F3(c1, c2, c3, c4, c5);

        /* Cierre de todos los archivos */
        fclose(ap);
        fclose(c1);
        fclose(c2);
        fclose(c3);
        fclose(c4);
        fclose(c5);
    } else {
        printf("\nEl o los archivos no se pudieron abrir.");
    }

    /* Tu preferencia: pausa final personalizada */
    printf("\n\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

float F1(FILE *ap) {
    alumno alu;
    float sum = 0;
    int i = 0;

    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        i++;
        sum += alu.examen;
        fread(&alu, sizeof(alumno), 1, ap);
    }
    return (i > 0) ? (sum / i) : 0;
}

void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5) {
    alumno alu;
    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        /* Criterio de admision corregido:
           (Examen >= 1300 Y promedio >= 8) O (Examen >= 1400 Y promedio >= 7) */
        if (((alu.examen >= 1300) && (alu.promedio >= 8)) || ((alu.examen >= 1400) && (alu.promedio >= 7))) {
            switch (alu.carrera) {
                case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
                case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
                case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
                case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
                case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
            }
        }
        fread(&alu, sizeof(alumno), 1, ap);
    }
}

void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5) {
    alumno alu;
    FILE *archivos[5] = {c1, c2, c3, c4, c5};
    float cal[5], sum;
    int i, j;

    for (i = 0; i < 5; i++) {
        sum = 0;
        j = 0;
        rewind(archivos[i]);
        fread(&alu, sizeof(alumno), 1, archivos[i]);
        while (!feof(archivos[i])) {
            j++;
            sum += alu.examen;
            fread(&alu, sizeof(alumno), 1, archivos[i]);
        }
        cal[i] = (j > 0) ? (sum / j) : 0;
    }

    /* Impresion de resultados */
    for (i = 0; i < 5; i++) {
        printf("\nPromedio admitidos carrera %d: %.2f", i + 1, cal[i]);
    }
}
