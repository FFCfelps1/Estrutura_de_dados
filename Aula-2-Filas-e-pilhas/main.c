#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{

float valor;
char texto[MAX_SIZE];
}Dados;

typedef struct Slista{

Dados dado;
struct Slista* prox;
}Tlista;

Tlista* criarLista();
void inserirNoFim(Tlista* lista, Dados dado);
void exibirLista(Tlista* lista);
Tlista* destruirLista(Tlista* lista);
int listaVazia(Tlista* lista);
int retiraDaFila(Tlista* lista, Dados *dados);
int quantosNaLista(Tlista* lista);
int retiraDaPilha(Tlista* lista, Dados *dados);

int main(void){

  
  
  return 0;
}

Tlista* criarLista(){

  //Alocar memória dinâmica
  Tlista* lista = (Tlista*)malloc(sizeof(Tlista));

  //Verificar se a alocação foi bem sucedida
  if(lista == NULL){
    printf("Falha em alocar memória.\n");
    exit(EXIT_FAILURE);
  }

  //Atribui NULL para o ponteiro de próximo nó
  lista->prox = NULL;
  return lista;

}

void inserirNoFim(Tlista* lista, Dados dado){

  //Alocar memória dinâmica
  Tlista* novoNo = (Tlista*)malloc(sizeof(Tlista));

  //Verificar se a alocação foi bem sucedida
  if(lista == NULL){
    printf("Falha em alocar memória.\n");
    exit(EXIT_FAILURE);
  }

  //Coloca as informações dentro da lista 
  novoNo->dado = dado;
  novoNo->prox = NULL;

  //Percorrer a lista até o último nó
  Tlista* aux = lista;
  while(aux->prox != NULL){
    aux = aux->prox;
  }

  //Inserir o novo nó no final da lista
  aux->prox = novoNo;

}

void exibirLista(Tlista* lista){

  Tlista* aux = lista;
  aux = aux->prox;

  while(aux != NULL){
    printf("Valor: %.2f\nNome: %s\n", aux->dado.valor, aux->dado.texto);
    aux = aux->prox;
  }

}

Tlista* destruirLista(Tlista* lista){

  Tlista* aux = lista;

  while(aux->prox != NULL){
    aux = aux->prox;
    free(lista);
    lista = aux;
  }
  free(lista);
  return NULL;
}

int listaVazia(Tlista* lista){

  if(lista->prox == NULL)
    return 1;
  else
    return 0;
}

int retiraDaFila(Tlista* lista, Dados* dados) {
    if(listaVazia(lista)) {
        return 0;
    }

  Tlista* aux = lista->prox;
  *dados = aux->dado;
  lista->prox = aux->prox;
  free(aux);
  return 1;
}

int quantosNaLista(Tlista* lista){
  
  int qtd =0;
  Tlista* aux = lista;
  while(aux->prox != NULL){
    aux = aux->prox;
    qtd++;
  }
  
}

int retiraDaPilha(Tlista* lista, Dados* dados){

  if(listaVazia(lista))
    return 0;

  Tlista* aux = lista;
  Tlista* aux2 = aux->prox;
  while(aux2->prox != NULL){
    aux = aux->prox;
    aux2 = aux2->prox;
  }
  *dados = aux2->dado;
  free(aux2);
  aux->prox = NULL;
  
}