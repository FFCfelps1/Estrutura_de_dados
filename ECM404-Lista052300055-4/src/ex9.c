#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

// Protótipo da função lerString
char* lerString(char str[]);
void substring(char str[], int inicio, int fim);

int main() {
    char str[MAX];
    int inicio, fim;

    // Chama a função lerString para ler a string do usuário
    lerString(str);

    // Solicita que o usuário digite o intervalo
    printf("Intervalo: ");
    scanf("%d, %d", &inicio, &fim);

    // Gera e imprime a substring com base no intervalo
    substring(str, inicio, fim);

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

// Define a função para gerar e imprimir a substring com base no intervalo
void substring(char str[], int inicio, int fim) {
    int i;

    // Imprime a substring com base no intervalo fornecido
    for (i = inicio; i <= fim; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}
