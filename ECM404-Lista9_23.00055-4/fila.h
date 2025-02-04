#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define MAX 20
#define MAX_FILA 10
#define MAX_SALA 5
#define MAX_ESPERA 10

/* struct para ex8 e 9
typedef struct {
char nickname[MAX];
} Dados;
*/
typedef struct {
char nickname[MAX];
int id;
} Dados;

typedef struct
{
Dados elemento[MAX_FILA];
int quantidade, frente, tras;
} TFila;

//Protótipos de funções
void ExibeFila(TFila *f);

TFila JuntaFilas(TFila *f1, TFila *f2);
//cria uma fila nova
void CriarFila(TFila *f);
//insere elemento
int InserirNaFila(TFila *f, Dados dados);
//retira elemento
int RetirarDaFila(TFila *f, Dados *dados);
//indica se a fila está vazia
int FilaVazia(TFila f);
//indica se a fila está cheia
int FilaCheia(TFila f);
//retorna o tamanho da fila
int QuantidadeNaFila(TFila f);

void RegistraPlayers(TFila *f);

void AndaFila(TFila *f);

Dados CriaJogador();

void AdicionaJogador(TFila* espera, Dados jogador);

void lerString(char s[]);

#endif // FILA_H_INCLUDED