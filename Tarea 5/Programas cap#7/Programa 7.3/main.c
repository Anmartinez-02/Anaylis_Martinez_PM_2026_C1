#include <stdio.h>

void main(void)
{
    /* Declaración e inicialización de cadenas */
    char *cad0 = "Buenos dias";
    char cad1[20] = "Hola";
    char cad2[] = "Mexico";
    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};

    char cad4[20], cad5[20], cad6[20];
    char p;
    int i = 0;
    int c; // Variable para limpiar el búfer

    /* Impresión de cadenas predefinidas */
    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    printf("\nLa cadena cad1 es: ");
    printf("%s\n", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    /* Lectura con gets (Nota: gets es obsoleta, pero se incluye por el ejercicio) */
    printf("\nIngrese una linea de texto (se lee con gets): \n");
    gets(cad4);
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    /* Limpieza del búfer - Sustituto de fflush(stdin) */
    while ((c = getchar()) != '\n' && c != EOF);

    /* Lectura con scanf */
    printf("\nIngrese una linea de texto (se lee con scanf): \n");
    scanf("%s", cad5);
    printf("\nLa cadena cad5 es: ");
    printf("%s\n", cad5);

    /* Limpieza del búfer - Sustituto de fflush(stdin) */
    while ((c = getchar()) != '\n' && c != EOF);

    /* Lectura caracter por caracter con getchar */
    printf("\nIngrese una linea de texto (se lee cada caracter con getchar): \n");
    while ((p = getchar()) != '\n' && p != EOF)
    {
        cad6[i++] = p;
    }
    cad6[i] = '\0'; // Caracter de terminación nulo

    printf("\nLa cadena cad6 es: ");
    puts(cad6);
}
