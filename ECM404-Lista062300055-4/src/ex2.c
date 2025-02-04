/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de diversas
 * pessoas, armazene esses dados em um array de estruturas (Pessoa). O programa
 * deve permitir a leitura de diferentes pessoas até que o usuário decida 
 * encerrar a inserção (caractere 'n'). Em seguida, o programa deve pedir para
 * o usuário digitar um nome a ser buscado no array de Pessoas. Caso o nome
 * seja encontrado, o endereço da Pessoa buscada deve ser exibido. Caso o nome
 * não seja encontrado, o usuário deve ser informado de que a busca não foi 
 * bem sucedida. Utilize o algoritmo de busca que preferir.
 *
 * Exemplos:
 *   Nome: Rodrigo
 *   Endereço: Aqui
 *   Idade: 31
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Alexandre
 *   Endereço: Ali
 *   Idade: 34
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   Endereço de Alexandre: Ali
 *
 *   Nome: Camila
 *   Endereço: Rua da Felicidade, 340
 *   Idade: 20
 *   Deseja adicionar outra pessoa? (s/n): s
 *   Nome: Diego
 *   Endereço: Rua da Miséria, 666
 *   Idade: 30
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Diego
 *   Endereço de Diego: Rua da Miséria, 666
 *
 *   Nome: Ahmad 
 *   Endereço: Avenida Brasil, 5670
 *   Idade: 19
 *   Deseja adicionar outra pessoa? (s/n): n
 *   Digite um nome para ser buscado: Alexandre
 *   'Alexandre' não foi encontrado
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
int busca_linear(Pessoa p[MAX_PESSOAS], char nome[MAX]);

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

  printf("Digite um nome para ser buscado:");
  char nome[MAX];
  ler_string(nome);
  int indice = busca_linear(pessoas, nome);
  if(indice == -1){
    printf("Pessoa não encontrada");
  }
  else{
    exibe_pessoa(pessoas[indice]);
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

int busca_linear(Pessoa p[MAX_PESSOAS], char nome[MAX]){
  for(int i = 0; i < MAX_PESSOAS; i++){
    if (strcmp(nome, p[i].nome) == 0){
      return i;
    }
  }
  return -1;
}