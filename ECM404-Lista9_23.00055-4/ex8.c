#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main (int argc, char *argv[])
{
  system("clear");
  int tam_1;
  int tam_2;
  TFila *fila1 = (TFila*) malloc(sizeof(TFila));
  TFila *fila2 = (TFila*) malloc(sizeof(TFila));
  CriarFila(fila1);
  CriarFila(fila2);
  printf("Tamanho da primeira fila: ");
  scanf("%i",&tam_1);
  printf("Tamanho da segunda fila: ");
  scanf("%i",&tam_2);
  
  for(int i = 0; i<tam_1; i++){
    Dados dado;
    printf("Digite um numero para adicionar na fila1: ");
    scanf("%i", &dado.numero);
    InserirNaFila(fila1, dado);
  }
  for(int i = 0; i<tam_2; i++){
    Dados dado;
    printf("Digite um numero para adicionar na fila2: ");
    scanf("%i", &dado.numero);
    InserirNaFila(fila2, dado);
  }

  TFila junta = JuntaFilas(fila1, fila2);
  ExibeFila(&junta);
  return 0;
}
