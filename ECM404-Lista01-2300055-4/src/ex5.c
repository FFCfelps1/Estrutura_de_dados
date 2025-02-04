#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero de 5 digitos e, em seguida, exiba
 * o numero digitado com os digitos invertidos.
 *
 * Ex:
 *      Digite um numero: 54321
 *      12345
 *
 *      Digite um numero: 38271
 *      17283
 *
 */

int main (int argc, char *argv[])
{
  printf("Digite um numero: ");
  int i;
  scanf("%i", &i);
  int d1 = i/10000;
  int d2 = i%10000;
  int d3 = d2/1000;
  int d4 = d2%1000;
  int d5 = d4/100;
  int d6 = d4%100;
  int d7 = d6/10;
  int d8 = d6%10;
  int d9 = d8/1;
  int d10 = d8%1;

  printf("Numero invertido: %i%i%i%i%i\n", d9, d7, d5, d3, d1);

  return 0;
}