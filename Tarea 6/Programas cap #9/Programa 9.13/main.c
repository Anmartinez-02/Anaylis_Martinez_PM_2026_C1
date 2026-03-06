#include <stdio.h>
#include <stdlib.h>

/* Prototipo de función */
int cuenta(char);

void main(void)
{
    int res;
    char car;

    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    car = getchar();

    /* Limpiamos el buffer para evitar saltos en futuras lecturas */
    fflush(stdin);

    res = cuenta(car);

    if (res != -1)
    {
        printf("\nEl caracter '%c' se encuentra en el archivo %d veces", car, res);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo 'arc.txt'");
    }

    /* Pausa final antes de cerrar */
    printf("\n\nPresione Enter para salir...");
    fflush(stdout);
    getchar();
}

int cuenta(char car)
{
    int con = 0;
    char p;
    FILE *ar;

    /* Intentamos abrir el archivo arc.txt en modo lectura ("r") */
    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        /* Leemos caracter por caracter hasta llegar al final del archivo (EOF) */
        while ((p = getc(ar)) != EOF)
        {
            if (p == car)
            {
                con++;
            }
        }
        fclose(ar);
        return con;
    }
    else
    {
        /* Retornamos -1 si el archivo no existe o no se puede abrir */
        return -1;
    }
}
