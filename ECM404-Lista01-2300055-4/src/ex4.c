#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que leia dois numero inteiros
 * e os imprima na ordem inversa que eles foram inseridos
 *
 * Ex:
 *      Digite um numero: 5
 *      Digite um numero: 7
 *      7 5
 *
 */

int main (int argc, char *argv[])
{
  printf("Digite um numero: ");
  // Leitura do numero
  int i1;
  scanf(" %i", &i1);
  printf("Digite um numero: ");
  int i2;
  scanf(" %i", &i2);
  // Resto do seu codigo
  printf("%i, %i\n", i1, i2);
  
  return 0;
}