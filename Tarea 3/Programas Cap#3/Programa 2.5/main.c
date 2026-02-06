#include <stdio.h>
#include <stdlib.h>
//Suma pagos.
//El programa obtiene la suma de los pagos realizados el ultimo mes.
//PAG y SPA: Variable de tipo real//

int main()
{
  float PAG, SPA = 0;
  printf ("Ingrese el primer pago:\t");
  scanf ("%f", &PAG);
  //Observa que al utilizar la estructura do-wile al menos se necesita un pago//
  do
  {
      SPA = SPA + PAG;
      printf("Ingrese el siguiente pago -0 para terminar-:\t");
      scanf ("%f", &PAG);
  }
  while (PAG);
  printf ("\nEl total de pagos del mes es: %.2f", SPA);
  return 0;
}
