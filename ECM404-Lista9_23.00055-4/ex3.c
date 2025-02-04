#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main (int argc, char *argv[])
{
  TLista *lista = preenche_lista();
  TLista *pares = lista_par(lista);
  exibe_lista(pares);
  return 0;
}

