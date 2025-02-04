#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main (int argc, char *argv[])
{
  TPilha pilha;
  int numero;
  CriarPilha(&pilha);
  printf("Digite o número em base decimal a ser convertido para binário: ");
    scanf("%i",&numero);
  for(int i = 0; i<MAX_PILHA; i++){
    Dados num;
    num.resto = numero%2;
    numero = numero/2;
    InserirNaPilha(&pilha, num);
  }
  
  ExibePilha(&pilha);
  return 0;
}
