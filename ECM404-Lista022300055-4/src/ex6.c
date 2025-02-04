#include <stdio.h>

/* Enunciado - Faça um programa que leia um numero inteiro positivo par e,
 * a seguir, exiba todos os numeros pares de 0 ate o numero digitado em ordem
 * crescente, separados apenas por um espaco.
 *
 * Exemplos:
 *
 * Numero: 5
 * Digite um numero par!
 *
 * Numero: -5
 * Digite um numero positivo!
 *
 * Numero: 6
 * 0 2 4 6
 *
 * Numero: 14
 * 0 2 4 6 8 10 12 14
 */

int main (int argc, char *argv[])
{

  int num = 0;
  int i = 0;
  printf("Digite um numero: ");
  scanf("%i", &num);

  if (num % 2 == 0 && num >= 0){
  printf("0 ");
  for(i=2; i<=num; i+= 2){

    int resultado = num % i;
    printf("%i ", i);
      //printf("%i ", i);
  }
  }
  else {
    printf("Digite um numero par!");
  }

  return 0;
}

