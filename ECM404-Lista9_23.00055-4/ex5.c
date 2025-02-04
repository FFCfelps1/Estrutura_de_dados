#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main (int argc, char *argv[])
{
  TLista *lista = preenche_lista();
  int primos = busca_primo(lista);
  printf("%i",primos);
  return 0;
}
