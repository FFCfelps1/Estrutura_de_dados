#include <stdio.h>

/* Enunciado:
 *
 * Elabore um programa que receba um valor inteiro de 6 digitos do usuario
 * e, em seguida, exiba uma versao binaria falsa desse numero. Para calcular
 * a versao b inaria falsa, verifique cada um dos digitos do numero e, se o 
 * digito for maior ou igual a 5, transforme-o em 1, se for menor, transforme-o
 * em 0.
 *
 *
 * Ex:
 *     Digite um numero: 123456
 *     000011
 *
 *     Digite um numero: 583910
 *     110100
 *
 *     Digite um numero: 830209
 *     100001
 *
 * DICA: Lembre-se das ferramentas de quebra de fluxo que tinhamos em Python.
 * Como usa-las em C? Pesquise!
 *
 */

int main (int argc, char *argv[])
{
  printf("Digite o valor: ");
  int i;
  scanf("%i", &i);

  int d11 = i/100000;
  int d12 = i%100000;
  int d1 = d12/10000;
  int d2 = d12%10000;
  int d3 = d2/1000;
  int d4 = d2%1000;
  int d5 = d4/100;
  int d6 = d4%100;
  int d7 = d6/10;
  int d8 = d6%10;
  int d9 = d8/1;
  int d10 = d8%1;


  if(d11 >= 5){
    d11 = 1;
}
  else {
    d11 = 0;
  }
  if(d1 >= 5){
    d1 = 1;
  }
  else {
    d1 = 0;
  }

  if(d3 >= 5){
    d3 = 1;
  }
  else {
    d3 = 0;
  }

  if(d5 >= 5){
    d5 = 1;
  }

  else {
    d5 = 0;
  }

  if(d7 >= 5){
    d7 = 1;
  }

  else {
    d7 = 0;
  }

  if(d9 >= 5){
    d9 = 1;
  }

  else {
    d9 = 0;
  }

  printf("O valor é: %i%i%i%i%i%i", d11, d1, d3, d5, d7, d9);
  return 0;
}

