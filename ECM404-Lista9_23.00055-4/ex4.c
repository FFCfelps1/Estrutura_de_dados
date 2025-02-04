#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main (int argc, char *argv[])
{
  TLista *lista = preenche_lista();
  float med = media(lista);
  printf("%f",med);
  return 0;
}
