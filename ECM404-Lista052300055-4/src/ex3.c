/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, solicite ao usuário que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usuário se o caractere foi
 * encontrado ou não. O programa deve desconsiderar a difereça entre maíusculas
 * e minúsculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b não foi encontrado.
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

// Protótipo da função lerString
char* lerString(char str[]);

int main() {
    char str[MAX];
    char parada;
    int tamanho, i;

    // Chama a função lerString para ler a string do usuário
    lerString(str);

    // Obtém o char de parada
    printf("Digite a chave: ");
    scanf(" %c", &parada);  // Usar um espaço antes de %c para consumir o caractere de nova linha residual

    // Converte todos os caracteres para minúsculas
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    // Verifica se o caractere de parada está na string
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == tolower(parada)) { // Comparação de caracteres individuais
            printf("Caractere %c encontrado na posição %d.\n", parada, i);
            return 0; // Termina o programa após encontrar o caractere
        }
    }

    // Se o caractere de parada não for encontrado
    printf("Caractere %c não foi encontrado.\n", parada);

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
