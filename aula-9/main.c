#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
  char rua[100];
  int numero;
} endereco;

typedef struct {
  char nome[50];
  int idade;
  char telefone[15];
  endereco end;
  int nota[4];
} pessoa;

void lerString(char c[]);
pessoa lerPessoa();

int main(void) {

  pessoa p[100];
  pessoa j = {"Joao", 20, "99999999"};

  strcpy(p[0].nome, "Felipe");
  p[0].idade = 18;
  strcpy(p[0].telefone, "0800-1234");

  p[1] = p[0];
  p[2] = lerPessoa();
  printf("Nome: %s, Idade: %i, Tel: %s\n", p[0].nome, p[0].idade,
         p[0].telefone);
  printf("Nome: %s, Idade: %i, Tel: %s\n", p[1].nome, p[1].idade,
         p[1].telefone);
  printf("Nome: %s, Idade: %i, Tel: %s\n", j.nome, j.idade, j.telefone);
  printf("Nome: %s, Idade: %i, Tel: %s, Rua: %s, Numero: %i\n", p[2].nome,
         p[2].idade, p[2].telefone, p[2].end.rua, p[2].end.numero);

  return 0;
}

void lerString(char s[]) {
  setbuf(stdin, 0);
  fgets(s, MAX, stdin);
  if (s[strlen(s) - 1] == '\n') {
    s[strlen(s) - 1] = '\0';
  }
}

pessoa lerPessoa() {
  pessoa p;

  printf("Digite o nome: ");
  lerString(p.nome);
  printf("Digite a idade: ");
  scanf("%i", &p.idade);
  printf("Digite o telefone: ");
  lerString(p.telefone);
  printf("Digite a rua:");
  lerString(p.end.rua);
  printf("Digite o numero: ");
  scanf("%i", &p.end.numero);

  return p; // Adicionando o retorno da struct pessoa
}
