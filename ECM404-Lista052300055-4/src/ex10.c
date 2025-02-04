/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, exibir o maior palíndromo possível dentro da string digitada.
 * Caso não haja nenhum palíndromo possível, o programa deve alertar o usuário.
 * O programa deve desconsiderar diferenças entre letras minúsculas e letras
 * maiúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: tiririca
 *   iriri
 *
 *   Digite uma string: I have a racecar
 *   racecar
 *
 *   Digite uma string: Cuidado com o Diego
 *   dad
 *
 *   Digite uma string: Alexandre
 *   Não existe nenhum palíndromo possível
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void ler_string(char s[MAX]);
void inverte_string(char s[MAX], char s_inv[MAX]);
void substring(char destino[MAX], char origem[MAX], int comeco, int fim);
int verifica_palindromo(char s[MAX]);
void maior_palindromo(char s[MAX], char s2[MAX]);
void to_lower_string(char s[MAX]);

int main (int argc, char *argv[])
{
  char s[MAX], s2[MAX];
  printf("Digite uma string: ");
  ler_string(s);
  to_lower_string(s);
  maior_palindromo(s, s2);
  if(strcmp(s2, "") != 0) printf("%s\n", s2);
  else printf("Não existe nenhum palíndromo possível\n");

  return 0;
}

void maior_palindromo(char s[MAX], char s2[MAX]) {
  int s_len = strlen(s);
  for(int j = s_len - 1; j > 0; --j)
    for(int i = 0; i < s_len - j; ++i) {
      substring(s2, s, i, i+j);
      if(verifica_palindromo(s2) == 1) {
        return;
      }
    }
  strcpy(s2, "");
}

int verifica_palindromo(char s[MAX]) {
  char _s[MAX];
  inverte_string(s, _s);
  if(strcmp(s, _s) == 0) return 1;
  return 0;
}

void substring(char destino[MAX], char origem[MAX], int comeco, int fim) {
  int j = 0;
  for(int i = comeco; i <= fim; ++i, ++j)
    destino[j] = origem[i];
  destino[j] = '\0';
}

void ler_string(char s[MAX]) {
  setbuf(stdin, 0);
  fgets(s, MAX, stdin);
  int s_final = strlen(s)-1;
  if(s[s_final] == '\n') s[s_final] = '\0';
}

void inverte_string(char s[MAX], char s_inv[MAX]){
  int s_final = strlen(s) - 1;
  for(int i = s_final, j = 0; i >= 0; --i, ++j) {
    s_inv[j] = s[i];
  }
  s_inv[s_final+1] = '\0';
}

void to_lower_string(char s[MAX]){
  int s_final = strlen(s) - 1;
  for(int i = 0; i <= s_final; ++i) {
    s[i] = tolower(s[i]);
  }
}
