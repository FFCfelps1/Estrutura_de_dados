/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usuário e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfabética. Utilize o algoritmo de ordenação que preferir.
 * O programa deve desconsiderar a diferença entre letras maíusculas e 
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

// Protótipo da função lerString
char* lerString(char str[]);
void bubbleSort(char str[], int tamanho);
void trocar(char *a, char *b);

int main() {
    char str[MAX];
    int tamanho, i;

    // Chama a função lerString para ler a string do usuário
    lerString(str);

    // Converte todos os caracteres para minúsculas
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    // Obtém o tamanho da string
    tamanho = strlen(str);

    // Ordena a string em ordem alfabética usando Bubble Sort
    bubbleSort(str, tamanho);

    // Imprime a string ordenada
    printf("%s\n", str);

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

// Define a função de ordenação Bubble Sort
void bubbleSort(char str[], int tamanho) {
    int i, j;

    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (str[j] > str[j+1]) {
                trocar(&str[j], &str[j+1]);
            }
        }
    }
}

// Define a função para trocar dois caracteres
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
