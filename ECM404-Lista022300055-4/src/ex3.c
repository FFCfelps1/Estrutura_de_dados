#include <stdio.h>

/* Enunciado - Faça um programa que receba um número inteiro e, a seguir,
 * exibe todos os seus possíveis divisores separados apenas por um espaço.
 *
 * Exemplos:
 *
 * Digite um numero: 7
 * 1 7
 *
 * Digite um numero: 12
 * 1 2 3 4 6 12
 */

int main (int argc, char *argv[])
{

  int num, i;
  printf("Digite um numero: ");
  scanf("%i", &num);

  for(i=1; i<=num; i++){

    int resultado = num % i;

    if (resultado == 0){
      printf("%i ", i);
    }
    else {
      continue;
    }
  }


  return 0;
}
