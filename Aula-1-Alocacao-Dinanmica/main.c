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

//int main(void) {

  //int* dados;
  //printf("%p\n", dados);
 //dados = (int*)malloc(sizeof(int*)); //calcula o tamanho do inteiro
  //converte qualquer coisa para um inteiro de um ponteiro
  //printf("%p\n", dados); // está em uma parte alocada, não está em um parte qualquer
  //free(dados); //está livre para ser utilizado, ainda está porque ainda não é NULL
  //printf("%p\n", dados);
  //return 0;
//}

// No final são listas interligadas, pois todas são strucut que tem um ponteiro apontando para o próximo item.
// Com tudo uma regra Geral a primeira variável tem dados = NULL e o ultimo tem ponteiro = NULL

int main(void){

  Dados dado = {1.2, "teste"};
  
  Tlista *lista = criarLista();
  printf("lista: %p\n", lista);
  printf("lista prox: %p\n", lista->prox);
  inserirNoFim(lista, dado);
  exibirLista(lista);
  lista = destruirLista(lista);
  printf("lista: %p\n", lista);
  
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