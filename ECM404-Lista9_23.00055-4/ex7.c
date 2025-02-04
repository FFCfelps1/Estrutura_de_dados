#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main (int argc, char *argv[])
{
  TPilha pilha;
  int numero;
  int escolha;
  CriarPilha(&pilha);
  printf("Digite o número em base decimal a ser convertido para outra base: ");
    scanf("%i",&numero);
  printf("Escolha a Base\nBinario[0]\nOctal[1]\nHexadecimal[2]\nHexatrigesimal[3}\n");
  scanf("%i",&escolha);
  if(escolha==0) ConverteBinario(&pilha, numero);
  else if(escolha==1)ConverteOctal(&pilha,numero);
  else if(escolha==2)ConverteHex(&pilha,numero);
  else if(escolha==3)ConverteHextri(&pilha,numero);
  
  ExibePilha(&pilha);
  return 0;
}
