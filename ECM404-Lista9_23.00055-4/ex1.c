#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(int argc, char *argv[]) {
  
  TLista *produtos = preenche_lista();
  TLista *vazio = cria_lista();
  
  Dado *menor_preco = (Dado*) malloc(sizeof(Dado));
  if (busca_menor(produtos, menor_preco)){
    printf("Busca realizada com sucesso\n");
    exibe_dado(*menor_preco);    
    }
    
  else printf("Lista vazia\n");
  
  
  return 0;
}
