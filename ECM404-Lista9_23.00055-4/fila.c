#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


void lerString(char s[])
{
setbuf(stdin,0);
fgets(s, MAX, stdin);
if(s[strlen(s) - 1] == '\n'){
s[strlen(s) - 1] = '\0';
  }
}

void CriarFila(TFila* f) {
  /* define valores iniciais das propriedades da fila */
  f->quantidade = 0;
  f->frente = 0;
  f->tras = -1;
}

int InserirNaFila(TFila *f, Dados dados) {
  int fc = FilaCheia(*f);
  if (!fc) {
    /* incrementa a posição "trás" no buffer circular*/
    f->tras = (f->tras + 1) % MAX_FILA;
    /* insere o elemento no fim da fila */
    f->elemento[f->tras] = dados;
    /* incrementa a quantidade */
    f->quantidade++;
  }
  return !fc; /* retorna se conseguiu inserir o dado */
}

int RetirarDaFila(TFila *f, Dados *dados) {
  int fv = FilaVazia(*f);
  if (!fv) {
    /* recupera o dado do início da fila */
    *dados = f->elemento[f->frente];
    /* incrementa a posição "frente" no buffer circular*/
    f->frente = (f->frente +1) % MAX_FILA;
    /* decrementa a quantidade */
    f->quantidade--;
  }
  return !fv; /* retorna se conseguiu remover o dado */
}

int FilaVazia(TFila f) {
  return f.quantidade == 0;
}

int FilaCheia(TFila f) {
  return f.quantidade == MAX_FILA;
}

int QuantidadeNaFila(TFila f) {
  return f.quantidade;
}

/*
Funções para o ex8
void ExibeFila(TFila *f){
  for(int i=0; i<f->quantidade; i++){
    if(i!=0) printf("->");
    printf("%i",f->elemento[i].numero);
    }
  printf("\n");
  }

TFila JuntaFilas(TFila *f1, TFila *f2){
  TFila fila_junta;
  CriarFila(&fila_junta);
  int maior_tam = (f1->quantidade > f2->quantidade)?f1->quantidade:f2->quantidade;
  for(int i=0; i<maior_tam; i++){
    if(i<f1->quantidade) InserirNaFila(&fila_junta, f1->elemento[i]);
    if(i<f2->quantidade) InserirNaFila(&fila_junta, f2->elemento[i]);
  }
  return fila_junta;
}
*/

void RegistraPlayers(TFila *f){
  int tam;
  printf("Quantos membros serão cadastrados [0-20]? ");
  scanf("%i",&tam);
  for(int i=0; i<tam; i++){
    Dados nick;
    printf("Digite o nickname do %iº integrante: ",i+1);
    scanf("%s",nick.nickname);
    InserirNaFila(f,nick);
    
  }
}

void ExibeFila(TFila *f){
  for(int i=0; i<f->quantidade; i++){
    if(i!=0) printf("->");
    printf("%s",f->elemento[i].nickname);
    }
  printf("\n");
  }

void ExibeFilaEx10(TFila *f){
  if(f->quantidade==0){
    printf("Fila vazia\n");
    return 0;
  }
  for(int i=0; i<f->quantidade; i++){
    if(i!=0) printf("\n");
    printf("Nickname: %s#%i",f->elemento[i].nickname,f->elemento[i].id);
    }
  printf("\n");
  }

void AndaFila(TFila *f){
  Dados andador;
  RetirarDaFila(f, &andador);
  ExibeFila(f);
  InserirNaFila(f, andador);
  ExibeFila(f);
}

Dados CriaJogador(){
  Dados jogador;
  printf("NICKNAME: ");
  lerString(jogador.nickname);
  printf("ID: ");
  scanf("%i", &jogador.id);
  return jogador;
}

void AdicionaJogador(TFila* espera, Dados jogador){
  if(espera->quantidade < MAX_ESPERA)
    InserirNaFila(espera,jogador);
  else printf("SALA DE ESPERA CHEIA");
}
