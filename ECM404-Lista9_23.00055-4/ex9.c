#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main (int argc, char *argv[])
{
  TFila time1;
  TFila time2;
  CriarFila(&time1);
  CriarFila(&time2);
  RegistraPlayers(&time1);
  RegistraPlayers(&time2);
  
  int vencedor=5;
  while(vencedor!=0){
    printf("%s vs %s\n",time1.elemento[time1.frente].nickname, time2.elemento[time2.frente].nickname);
    printf("\nVencedor [1-2]: ");
    scanf("%i",&vencedor);
    if(vencedor == 1) AndaFila(&time2);
    else if(vencedor == 2) AndaFila(&time1);
  }
return 0;
}
