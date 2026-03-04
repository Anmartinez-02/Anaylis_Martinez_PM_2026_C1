#include <stdio.h>
#include <string.h>

/* Estructuras y Uniones */

typedef struct {
    char noba[10];        /* Nombre del banco. */
    char nucu[10];        /* Número de cuenta. */
} banco;

typedef union {
    banco che;            /* Cheque. */
    banco nomi;           /* Nómina. */
    char venta;           /* Ventanilla. */
} fpago;

typedef struct {
    char cnu[20];         /* Calle y número. */
    char col[20];         /* Colonia. */
    char cp[5];           /* Código Postal. */
    char ciu[15];         /* Ciudad. */
} domicilio;

typedef struct {
    int num;              /* Número de vendedor. */
    char nom[20];         /* Nombre del vendedor. */
    float ven[12];        /* Ventas del año. */
    domicilio domi;       /* Estructura domicilio. */
    float sal;            /* Salario mensual. */
    fpago pago;           /* Unión fpago. */
    int cla;              /* Clave forma de pago. */
} vendedor;

/* Prototipos de funciones */
void Lectura(vendedor A[], int T);
void F1(vendedor A[], int T);
void F2(vendedor A[], int T);
void F3(vendedor A[], int T);
void F4(vendedor A[], int T);

int main(void) {
    vendedor VENDEDORES[100];
    int TAM;

    do {
        printf("Ingrese el numero de vendedores: ");
        scanf("%d", &TAM);
        fflush(stdin);
    } while(TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA");
    printf("\nPresione ENTER para salir...");
    fflush(stdout);
    getchar();

    return 0;
}

void Lectura(vendedor A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos del vendedor %d", I + 1);
        printf("\nNumero de vendedor: ");
        scanf("%d", &A[I].num);

        printf("Nombre del vendedor: ");
        fflush(stdin);
        gets(A[I].nom);

        printf("Ventas del año: \n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        printf("Domicilio del vendedor: \n");
        printf("\tCalle y numero: ");
        fflush(stdin);
        gets(A[I].domi.cnu);
        printf("\tColonia: ");
        fflush(stdin);
        gets(A[I].domi.col);
        printf("\tCodigo Postal: ");
        fflush(stdin);
        gets(A[I].domi.cp);
        printf("\tCiudad: ");
        fflush(stdin);
        gets(A[I].domi.ciu);

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        printf("Forma de Pago (Banco-1 Nomina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);

        switch(A[I].cla) {
            case 1:
                printf("\tNombre del banco: ");
                fflush(stdin);
                gets(A[I].pago.che.noba);
                printf("\tNumero de cuenta: ");
                fflush(stdin);
                gets(A[I].pago.che.nucu);
                break;
            case 2:
                printf("\tNombre del banco: ");
                fflush(stdin);
                gets(A[I].pago.nomi.noba);
                printf("\tNumero de cuenta: ");
                fflush(stdin);
                gets(A[I].pago.nomi.nucu);
                break;
            case 3:
                A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for(J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        printf("\nVendedor: %d - Ventas: %.2f", A[I].num, SUM);
    }
    printf("\n");
}

void F2(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for(J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM > 1500000.00) {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNumero: %d - Nuevo salario: %.2f", A[I].num, A[I].sal);
        }
    }
    printf("\n");
}

void F3(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for(J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if(SUM < 300000.00)
            printf("\nEmpleado: %d - Nombre: %s - Ventas: %.2f", A[I].num, A[I].nom, SUM);
    }
    printf("\n");
}

void F4(vendedor A[], int T) {
    int I;
    printf("\n\t\tVendedores con Cuenta en el Banco (Cheques)");
    for (I = 0; I < T; I++) {
        if(A[I].cla == 1) {
            printf("\nNumero: %d - Banco: %s - Cuenta: %s",
                   A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
        }
    }
    printf("\n");
}
