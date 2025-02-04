/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, informe-o se o valor digitado se trata de um palíndromo ou não.
 * O programa deve descosiderar diferença entre maíusculas e minúsculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  É palíndromo
 *
 *  Digite uma string: oi
 *  Não é palíndromo
 *
 *  Digite uma string: RaceCar
 *  É palíndromo
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

// Protótipo da função lerString
char* lerString(char str[]);

int main() {
    char str[MAX], str2[MAX];
    int tamanho, i;

    // Chama a função lerString para ler a string do usuário
    lerString(str);

    // Obtém o tamanho da string
    tamanho = strlen(str);

    // Converte todos os caracteres para minúsculas
    for (i = 0; i < tamanho; i++) {
        str[i] = tolower(str[i]);
    }

    // Inverte a string
    for (i = tamanho - 1; i >= 0; i--) {
      printf("%i\n%i\n", i, tamanho);
      printf("%i\n", tamanho - i - 1);
        str2[tamanho - i - 1] = str[i];
    }
    str2[tamanho] = '\0'; // Adiciona o caractere nulo ao final da string invertida

    // Verifica se a string original e a invertida são iguais
    if (strcmp(str, str2) == 0) {
        printf("É palíndromo\n");
    } else {
        printf("Não é palíndromo\n");
    }

    return 0;
}

// Define a função lerString
char* lerString(char str[]){
    // Solicita que o usuário digite uma string
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);

    // Remove o caractere de nova linha (\n) do final da string, se presente
      int tamanho = strlen(str);
      if (str[tamanho - 1] == '\n') {
          str[tamanho - 1] = '\0';
      }

      // Retorna a string lida
      return str;
  }

