#include <stdio.h>
#include <stdlib.h>

/* Declaracion de la estructura alumno */
typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Prototipo de funcion */
void ordena(FILE *ap1, FILE *ap2);

int main(void) {
    FILE *ar1, *ar2;

    /* Abrimos el archivo original en modo lectura binaria (rb) */
    /* Abrimos el nuevo archivo en modo escritura binaria (wb) */
    ar1 = fopen("ad5.dat", "rb");
    ar2 = fopen("ad6.dat", "wb");

    if (ar1 != NULL && ar2 != NULL) {
        ordena(ar1, ar2);
        fclose(ar1);
        fclose(ar2);
        printf("Archivo ordenado inversamente con exito en 'ad6.dat'.\n");
    } else {
        printf("\nEl o los archivos no se pudieron abrir.\n");
        /* Solo cerramos si no son nulos para evitar errores */
        if (ar1) fclose(ar1);
        if (ar2) fclose(ar2);
    }

    /* Tu preferencia: pausa final personalizada */
    printf("\nPresione Enter para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void ordena(FILE *ap1, FILE *ap2) {
    alumno alu;
    int t, n, i;

    t = sizeof(alumno);

    /* Nos posicionamos al final del archivo para saber el tamaño total */
    fseek(ap1, 0, SEEK_END);

    /* ftell nos da la posicion en bytes. Al dividir por el tamaño de la
       estructura (t), obtenemos el numero total de registros (n). */
    n = ftell(ap1) / t;

    /* Ciclo descendente: empezamos desde el ultimo registro (n-1) hasta el primero (0) */
    for (i = (n - 1); i >= 0; i--) {
        /* Nos movemos al registro i */
        fseek(ap1, i * t, SEEK_SET);

        /* Leemos el registro del archivo 1 */
        fread(&alu, t, 1, ap1);

        /* Lo escribimos en el archivo 2 */
        fwrite(&alu, t, 1, ap2);
    }
}
