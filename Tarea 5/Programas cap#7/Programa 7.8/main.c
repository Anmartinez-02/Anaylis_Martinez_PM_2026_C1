#include <stdio.h>
#include <string.h>
#include <ctype.h>

// El prototipo debe coincidir exactamente con la definicion
void minymay(char *cad);

int main(void) {
    int i, n;
    char FRA[20][50];

    printf("Ingrese el numero de filas: ");
    if (scanf("%d", &n) != 1) return 1;

    // Limpiamos el buffer para que el siguiente fgets no se salte
    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("Ingrese la linea %d: ", i + 1);
        fgets(FRA[i], 50, stdin);

        // Esto quita el 'Enter' que fgets guarda al final de la cadena
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    for (i = 0; i < n; i++) {
        minymay(FRA[i]);
    }

    return 0;
}

void minymay(char *cadena) {
    int i = 0, mi = 0, ma = 0;
    while(cadena[i] != '\0') {
        if (islower(cadena[i])) mi++;
        else if (isupper(cadena[i])) ma++;
        i++;
    }
    printf("\nCadena: %s", cadena);
    printf("\nMinusculas: %d | Mayusculas: %d\n", mi, ma);
}
