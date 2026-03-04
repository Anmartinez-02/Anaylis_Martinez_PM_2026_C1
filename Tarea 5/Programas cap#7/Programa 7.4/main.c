#include <stdio.h>
#include <string.h>

/* Declaración de cadenas de caracteres y asignación de valores. */
int main(void)
{
    // --- CASO 0: Apuntadores ---
    char *cad0;
    cad0 = "Argentina";  /* Correcto: cad0 apunta a una constante de cadena */
    puts(cad0);

    cad0 = "Brasil";     /* Correcto: cad0 ahora apunta a otra dirección de memoria */
    puts(cad0);

    // --- CASO 1: Lectura con apuntadores ---
    // IMPORTANTE: char *cad1 = ""; solo reserva 1 byte (el nulo).
    // Usar gets() ahí es peligroso (Buffer Overflow).
    // Lo correcto es apuntar a un espacio reservado:
    char buffer[50];
    char *cad1 = buffer;

    printf("\nIngrese una cadena para el apuntador: ");
    fgets(cad1, 50, stdin); /* Sustituto seguro de gets() */
    puts(cad1);

    // --- CASO 2: Arreglos ---
    // char cad1[]; <- Esto daría error porque no tiene tamaño.

    char cad2[20] = "Mexico"; /* Correcto: reserva 20 bytes y guarda "Mexico" */
    printf("\nValor inicial de cad2: ");
    puts(cad2);

    printf("Ingrese un nuevo valor para cad2: ");
    fgets(cad2, 20, stdin);  /* Correcto: modifica el contenido del arreglo */
    puts(cad2);

    /* ERROR EXPLICADO:
       cad2[10] = "Guatemala";
       Esto falla porque cad2[10] es un solo CARACTER, no puedes asignarle una cadena.
       Para cambiar el valor de un arreglo se usa strcpy de <string.h>
    */
    strcpy(cad2, "Guatemala");
    printf("Valor de cad2 tras strcpy: ");
    puts(cad2);

    return 0;
}
