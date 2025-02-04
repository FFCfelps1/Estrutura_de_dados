#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main (int argc, char *argv[])
{
  TLista *lista = preenche_lista();
  printf("%i",busca_par(lista));
  return 0;
}
