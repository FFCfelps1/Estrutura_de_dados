#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

char algarismos[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','X','Y','Z'};


void CriarPilha(TPilha* f) {
  /* define valores iniciais das propriedades da Pilha */
  f->quantidade = 0;
  f->frente = 0;
  f->tras = -1;
}

int InserirNaPilha(TPilha *f, Dados dados) {
  int fc = PilhaCheia(*f);
  if (!fc) {
    /* incrementa a posição "trás" no buffer circular*/
    f->tras = (f->tras + 1) % MAX_PILHA;
    /* insere o elemento no fim da Pilha */
    f->elemento[f->tras] = dados;
    /* incrementa a quantidade */
    f->quantidade++;
  }
  return !fc; /* retorna se conseguiu inserir o dado */
}


int RetirarDaPilha(TPilha *f, Dados *dados) {
  int fv = PilhaVazia(*f);
  if (!fv) {
    /* recupera o dado do início da Pilha */
    *dados = f->elemento[f->tras];
    /* incrementa a posição "frente" no buffer circular*/
    f->tras = (f->tras -1) % MAX_PILHA;
    /* decrementa a quantidade */
    f->quantidade--;
  }
  return !fv; /* retorna se conseguiu remover o dado */
}

int PilhaVazia(TPilha f) {
  return f.quantidade == 0;
}

int PilhaCheia(TPilha f) {
  return f.quantidade == MAX_PILHA;
}

int QuantidadeNaPilha(TPilha f) {
  return f.quantidade;
}

void ExibePilha(TPilha *f){
  for(int i=(f->quantidade-1); i>-1; i--){
    printf("%c",f->elemento[i].resto);
    }
  printf("\n");
  }

void ConverteBinario(TPilha *f, int n){
  for(int i = 0; i<MAX_PILHA; i++){
    Dados num;
    num.resto = algarismos[n%2];
    n = n/2;
    InserirNaPilha(f, num);
  }
}

void ConverteOctal(TPilha *f, int n){
  for(int i = 0; i<MAX_PILHA; i++){
    Dados num;
    num.resto = algarismos[n%8];
    n = n/8;
    InserirNaPilha(f, num);
  }
}

void ConverteHex(TPilha *f, int n){
  for(int i = 0; i<MAX_PILHA; i++){
    Dados num;
    num.resto = algarismos[n%16];
    n = n/16;
    InserirNaPilha(f, num);
  }
}

void ConverteHextri(TPilha *f, int n){
  for(int i = 0; i<MAX_PILHA; i++){
    Dados num;
    num.resto = algarismos[n%36];
    n = n/36;
    InserirNaPilha(f, num);
  }
}

