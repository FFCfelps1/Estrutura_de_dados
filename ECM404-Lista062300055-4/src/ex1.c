/* 
 * Enunciado: 
 * Implemente um programa que leia o nome, a idade e o endereço de uma pessoa 
 * e armazene esses dados em uma estrutura. Em seguida, imprima na tela os 
 * dados da estrutura lida. Para armazenar os dados, escolha os tipos de dados 
 * mais adequados para cada informação. Utilize, obrigatoriamente, uma função 
 * para realizar a leitura da estrutura e outra função para realizar sua 
 * exibição. Outras funções auxiliares podem ser utilizadas.
 *
 * Exemplos:
 *
 *  Nome: Rodrigo Nicola
 *  Endereço: Praça Mauá, 1
 *  Idade: 31
 *  Pessoa{'Rodrigo Nicola',31,'Praça Mauá, 1'}
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

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

int main (int argc, char *argv[]){

  Pessoa p;
  p = ler_pessoa();
  exibe_pessoa(p);

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