#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia os valores de duas resistencias eletricas (int)
 * e, em seguida, exiba o resultado da sua resistencia equivalente em serie
 * e em paralelo. O formato da saida deve ser:
 *
 * S: **Req_Serie** P: **Req_Paralelo**
 *
 *
 * Ex:
 *      R1: 3
 *      R2: 3
 *      S: 6 P: 1.50
 *
 *      R1: 5
 *      R2: 12
 *      S: 17 P: 3.53
 *
 * OBS: Utilize duas casas decimais para representar valores flutuantes.
 */

int main (int argc, char *argv[])
{
  printf("Digite a resistencia: ");
  int r1;
  scanf("%i", &r1);

  printf("Digite a resistencia: ");
  int r2;
  scanf("%i", &r2);

  float req_serie = r1 + r2;
  float req_paralelo = (1/(float)r1) + (1/(float)r2);

  printf("S: %.2f P: %.2f", req_serie, req_paralelo);
  return 0;
}
