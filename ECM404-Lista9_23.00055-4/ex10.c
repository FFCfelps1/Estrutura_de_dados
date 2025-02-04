#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


int main (int argc, char *argv[])
{
  //system("clear");
  TFila sala1; 
  TFila sala2;
  TFila espera;
  CriarFila(&sala1);
  CriarFila(&sala2);
  CriarFila(&espera);
  int rodando=1;
  int jogando=0;


  while(rodando){
    int escolha;
    printf("\n");
    
    
    printf("\nEscolha ação:\n[1]Terminar partida\n[2]Adicionar jogador\n[3]Iniciar partida\n[4]Status\n");
    scanf("%i",&escolha);
    if(escolha==1){
      jogando = 0;
      int jogadores_sala1 = sala1.quantidade;
      int jogadores_sala2 = sala2.quantidade;
      for(int i=0;i<jogadores_sala1;i++){
        Dados lixo;
        RetirarDaFila(&sala1, &lixo);
      }
      for(int i=0;i<jogadores_sala2;i++){
        Dados lixo;
        RetirarDaFila(&sala2, &lixo);
      }
    }
    else if(escolha==2){ 
      Dados jogador = CriaJogador();
      AdicionaJogador(&espera,jogador);
      }
    
    
    else if(escolha==3){
      jogando = 1;
      int esperando = espera.quantidade;
      for(int i=0;i<esperando;i++){
        if(sala1.quantidade!=MAX_SALA){
          InserirNaFila(&sala1,espera.elemento[i]);
          }

        else if(sala2.quantidade!=MAX_SALA){
          InserirNaFila(&sala2,espera.elemento[i]);
          }
      }
      for(int i=0;i<esperando;i++){
        Dados lixo;
        RetirarDaFila(&espera, &lixo);
      }
      }
    else if(escolha==4){
      system("clear");
      printf("\nSTATUS:\n");
      printf("\nSala 1:\n");
      ExibeFilaEx10(&sala1);
      printf("\nSala 2:\n");
      ExibeFilaEx10(&sala2);
      printf("\nFila de espera:\n");
      ExibeFilaEx10(&espera);
      
    }
    }
    
    
  return 0;
}
