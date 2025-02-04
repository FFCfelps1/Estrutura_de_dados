#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX 20
#define MAX_PILHA 8

typedef struct {
char resto;
} Dados;

typedef struct
{
Dados elemento[MAX_PILHA];
int quantidade, frente, tras;
} TPilha;


//Protótipos de funções
void ExibePilha(TPilha *f);

//cria uma pilha nova
void CriarPilha(TPilha *f);
//insere elemento
int InserirNaPilha(TPilha *f, Dados dados);
//retira elemento
int RetirarDaPilha(TPilha *f, Dados *dados);
//indica se a Pilha está vazia
int PilhaVazia(TPilha f);
//indica se a Pilha está cheia
int PilhaCheia(TPilha f);
//retorna o tamanho da Pilha
int QuantidadeNaPilha(TPilha f);

void ConverteBinario(TPilha *f, int n);

void ConverteOctal(TPilha *f, int n);

void ConverteHex(TPilha *f, int n);

void ConverteHextri(TPilha *f, int n);

#endif // FILA_H_INCLUDED