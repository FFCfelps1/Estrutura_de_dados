#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define MAX 20

TLista* cria_lista() {
  TLista* cabeca = (TLista*) malloc(sizeof(TLista));
  cabeca->prox = NULL;
  return cabeca;
}

TLista* preenche_lista(){
  TLista* produtos;
  produtos = cria_lista();
  
  Dado produto1;
  produto1.codProd = 1;
  strcpy(produto1.nomeProd,"Produto1");
  produto1.valor = 10;
  produto1.qtdeEstoque = 5;
  produto1.numero = 17;
  
  Dado produto2;
  produto2.codProd = 2;
  strcpy(produto2.nomeProd,"Produto2");
  produto2.valor = 8;
  produto2.qtdeEstoque = 5;
  produto2.numero = 3;
  
  Dado produto3;
  produto3.codProd = 3;
  strcpy(produto3.nomeProd,"Produto3");
  produto3.valor = 80;
  produto3.qtdeEstoque = 4;
  produto3.numero = 2;
  
  Dado produto4;
  produto4.codProd = 4;
  strcpy(produto4.nomeProd,"Produto4");
  produto4.valor = 5;
  produto4.qtdeEstoque = 5;
  produto4.numero =12;
  
  Dado produto5;
  produto5.codProd = 5;
  strcpy(produto5.nomeProd,"Produto5");
  produto5.valor = 23;
  produto5.qtdeEstoque = 5;
  produto5.numero = 6;

  insere_no_fim(produtos, produto1);
  insere_no_fim(produtos, produto2);
  insere_no_fim(produtos, produto3);
  insere_no_fim(produtos, produto4);
  insere_no_fim(produtos, produto5);
  return produtos;
}

TLista* destroi_lista(TLista* dados) {
  TLista* aux = dados;
  while(aux->prox == NULL){
    aux = aux->prox;
    free(dados);
    dados = aux;
  }
  free(dados);
  return NULL;
}

void insere_no_fim(TLista *lista, Dado dados) {
  TLista* novo = (TLista*) malloc(sizeof(TLista));
  novo->prox = NULL;
  novo->dado = dados;

  TLista* aux = lista;
  while(aux->prox != NULL)
    aux = aux->prox;
  aux->prox = novo;  
}

void exibe_lista(TLista* dados) {
  TLista *aux = dados->prox;
  while(aux != NULL) {
    exibe_dado(aux->dado);
    if( aux->prox != NULL ) printf("\n");
    aux = aux->prox;
  }
  printf("\n");
}

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}

void exibe_dado(Dado dado) {
  printf("Código do produto: %i\n",dado.codProd);
  printf("Nome: %s\n",dado.nomeProd);
  printf("Preço: R$%.2f\n", dado.valor);
  printf("Quantidade em estoque: %i\n", dado.qtdeEstoque);
  printf("Número: %i\n", dado.numero);
}

int busca_menor(TLista *lista, Dado *menor){
  
  TLista *aux;
  if(lista->prox == NULL) return 0;
  aux = lista->prox;
  *menor = aux->dado;
  
  while(aux != NULL){
    if(aux->dado.valor < menor->valor){ 
      *menor = aux->dado;
      }
    aux = aux->prox; 
  }
  
  return 1;
}

int busca_par(TLista *lista){
  TLista *aux;
  aux = lista->prox;
  int pares=0;
  while(aux != NULL){
    if(aux->dado.numero%2 == 0) pares++;
    aux = aux->prox;
  }
  return pares;
}

TLista* lista_par(TLista *lista){
  TLista *pares = cria_lista();
  TLista *aux;
  aux = lista->prox;
  while(aux != NULL){
    if(aux->dado.numero%2 == 0) insere_no_fim(pares,aux->dado);
    aux = aux->prox;
  }
  return pares;
}

float media(TLista *lista){
  TLista *aux = lista->prox;
  float media = 0;
  float tamanho_da_lista = 0;
  while(aux!=NULL){
    media += aux->dado.numero;
    tamanho_da_lista ++;
    aux = aux->prox;
  }
  return media/tamanho_da_lista;
}

int busca_primo(TLista *lista){
  TLista *aux = lista->prox;
  int primos = 0;

  while(aux != NULL){
    if(checa_primo(aux->dado.numero)){
      primos++;
      }
    aux = aux->prox;
  }
  return primos;
}

int checa_primo(int num){
  for(int i = (num-1); i>1; i--){
    if (num%i == 0){
      return 0;  
      }
  }
  return 1;
}
