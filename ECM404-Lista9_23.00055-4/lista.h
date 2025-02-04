#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct {
  int codProd; //código do produto
  char nomeProd[10]; //nome do produto
  float valor; //valor do produto
  int qtdeEstoque; //quantidade disponível em estoque
  int numero;
} Dado;

typedef struct SLista {
  Dado dado;
  struct SLista* prox;
} TLista;



TLista* cria_lista();
TLista* destroi_lista(TLista* lista);
void insere_no_fim(TLista *lista, Dado dado);
TLista* preenche_lista();
int busca_menor(TLista *lista, Dado *menor);
int busca_par(TLista *lista);
TLista* lista_par(TLista *lista);
float media(TLista *lista);
int busca_primo(TLista *lista);
int checa_primo(int num);

/* Funções para uso livre */
void exibe_dado(Dado dado);
void exibe_lista(TLista* lista); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"


#endif // FILA_H_INCLUDED