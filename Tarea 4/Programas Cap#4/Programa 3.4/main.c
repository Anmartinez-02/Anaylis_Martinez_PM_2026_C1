#include <stdio.h>
#include <stdlib.h>
//Prueba de variables globales, locales y estaticas.//

int f1 (void);
int f2 (void);
int f3 (void);
int f4 (void);

int k_global=3;
void main (void)

{
   int i;
   for (i=1; i<=3; i++)
   {
       printf("\nEl resultado de la funcion f1 es: %d", f1());
       printf("\nEl resultado de la función f2 es: %d", f2());
       printf("\nEl resultado de la función f3 es: %d", f3());
       printf("\nEl resultado de la función f4 es: %d", f4());
   }
}
int f1(void)
/* La función f1 utiliza la variable global. */
{
k_global += k_global;
return (k_global);
}
int f2(void)
/* La función f2 utiliza la variable local. */
{
int k = 1;
k++;
return (k);
}
int f3(void)
/* La función f3 utiliza la variable estática. */
{
static  int k = 8;
k += 2;
return (k);
}
int f4(void)
/* La función f4 utiliza dos variables con el mismo nombre: local y global. */
{
int k = 5;
k = k + k_global;       /* Uso de la variable local (kk) y global (::::kk) */
return (k);
}
