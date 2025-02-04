/* 
 * Enunciado: 
 * Repita o exercício anterior, mas agora ordene o array por idade.
 * 
 * Exemplos: 
 *
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Tawfik
 *   Endereço: Praça da Mesquita, 17
 *   Idade: 18
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Praça Mauá, 1
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   [Pessoa{'Tawfik',18,'Praça da Mesquita, 17'},Pessoa{'Diego',30,'Rua da Miséria, 666'},Pessoa{'Alexandre',34,'Praça Mauá, 1'}]
 *
 */

#include <stdio.h>
#include <string.h>


#define MAX 100
#define MAX_PESSOAS 100

typedef struct {

  char rua[MAX];
  int numero;

} endereco;

typedef struct {

char nome[MAX];
endereco end;
int idade;

} Pessoa;

void ler_string(char s[MAX]);
Pessoa ler_pessoa();
void exibe_pessoa(Pessoa p);
void troca_pessoa(int a, int b, Pessoa pessoas[MAX_PESSOAS]);
void bubbleSort(Pessoa pessoas[MAX_PESSOAS], int tamanho);

int main (int argc, char *argv[]){

  Pessoa pessoas[MAX_PESSOAS];
  char op[MAX];
  int j=0;

  do{
    pessoas[j] = ler_pessoa();
    printf("Deseja adicionar outra pessoa? (s/n):");
    ler_string(op);

  j++;
  }while(strcmp(op, "s") == 0 && j < MAX_PESSOAS);

  bubbleSort(pessoas, j);
  for(int i = 0; i<j; i++){
     exibe_pessoa(pessoas[i]);
  }


  return 0;
}

void ler_string(char s[]) {
  setbuf(stdin, 0);
  fgets(s, MAX, stdin);
  if (s[strlen(s) - 1] == '\n') {
    s[strlen(s) - 1] = '\0';
  }
}

Pessoa ler_pessoa() {
  Pessoa p;
  char op[MAX];
  printf("Digite o nome: ");
  ler_string(p.nome);
  printf("Digite a idade: ");
  scanf("%i", &p.idade);
  printf("Digite a rua:");
  ler_string(p.end.rua);
  printf("Digite o numero: ");
  scanf("%i", &p.end.numero);

  return p; // Adicionando o retorno da struct pessoa
}

void exibe_pessoa(Pessoa p){
  printf("Nome: %s, Idade: %i, Endereço: %s, %i\n", p.nome, p.idade, p.end.rua, p.end.numero); 

}

void troca_pessoa(int a, int b, Pessoa pessoas[MAX_PESSOAS]){

 Pessoa aux;
  aux = pessoas[a];
  pessoas[a] = pessoas[b];
  pessoas[b] = aux;

}

void bubbleSort(Pessoa pessoas[MAX_PESSOAS], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho-1; i++) {
        // Últimos i elementos já estão no lugar certo
        for (j = 0; j < tamanho-i-1; j++) {
            // Troca se o elemento atual for maior que o próximo
            if (pessoas[j].idade > pessoas[j+1].idade) {
              troca_pessoa(j, j + 1, pessoas);
            }
        }
    }
}
