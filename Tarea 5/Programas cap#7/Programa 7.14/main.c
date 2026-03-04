#include <stdio.h>
#include <ctype.h>

/* Prototipo de función */
void interpreta(char *cadena);

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres (ejemplo: 3a2b): ");

    /* Usamos fgets en lugar de gets por seguridad.
       Luego limpiamos el buffer si es necesario.
    */
    fgets(cad, 50, stdin);
    fflush(stdin);

    interpreta(cad);
    printf("\n");

    return 0;
}

void interpreta(char *cadena)
/* Esta función decodifica la cadena: un número seguido de una letra */
{
    int i = 0, j, k;

    while (cadena[i] != '\0')
    {
        /* Si el caracter actual es una letra, miramos el número anterior */
        if (isalpha(cadena[i]))
        {
            /* Convertimos el caracter numérico anterior a entero.
               '0' en ASCII es 48, por eso restamos 48 o '0'.
            */
            if (i > 0)
            {
                k = cadena[i - 1] - '0';

                for (j = 0; j < k; j++)
                {
                    putchar(cadena[i]);
                }
            }
        }
        i++;
    }
}
