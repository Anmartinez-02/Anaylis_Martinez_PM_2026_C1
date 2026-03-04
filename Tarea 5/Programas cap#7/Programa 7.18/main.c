#include <stdio.h>

/* Prototipo de función */
void inverso(char *);

void main(void)
{
    char fra[50];
    int i = 0;
    char c;

    printf("\nIngrese la linea de texto: ");

    /* Uso de getchar para capturar la cadena de forma segura */
    while (i < 49 && (c = getchar()) != '\n' && c != EOF) {
        fra[i++] = c;
    }
    fra[i] = '\0'; // Finalizamos la cadena con el caracter nulo

    /* Limpiamos el buffer de entrada */
    fflush(stdin);

    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
    printf("\n"); // Salto de línea final para limpieza visual
}

void inverso(char *cadena)
/* Esta función utiliza recursividad. Se llama a sí misma hasta llegar
   al final de la cadena ('\0') y, al regresar (desapilar), imprime
   los caracteres en orden inverso. */
{
    if (cadena[0] != '\0')
    {
        /* Llamada recursiva con la dirección del siguiente caracter */
        inverso(&cadena[1]);

        /* Esta línea se ejecuta "de regreso", imprimiendo desde el
           último caracter hacia el primero. */
        putchar(cadena[0]);
    }
}
