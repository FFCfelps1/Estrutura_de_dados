/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings.
 * O array deve ser ordenado alfabéticamente e, a seguir, exibido utilizando o 
 * procedimento exibe_nomes fornecido. A quantidade de nomes digitado deve ser 
 * sempre 5 (definido por MAX_NOMES). O programa deve desconsiderar a diferença 
 * entre letras maiúsculas e minúsculas.
 *
 * Dica: pesquise pela função strtok
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['alexandre', 'diego', 'julio', 'nicola', 'tiririca']
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['ana julia', 'joao', 'marco antonio', 'matheus', 'victoria']
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_NOMES 5 // Definindo o número máximo de nomes
#define MAX 100  // Definindo o comprimento máximo de cada nome

/* Protótipos das funções */
void exibe_nomes(char nomes[][MAX], int tamanho);
void ler_nomes(char str[], char nomes[][MAX]);
void bubbleSort(char arr[][MAX], int tamanho);

int main() {
    char nomes[MAX_NOMES][MAX]; // Array de strings para armazenar os nomes
    char entrada[100]; // String para armazenar a entrada do usuário

    // Solicita que o usuário digite os nomes
    printf("Digite os nomes separados por vírgula: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Remove o caractere de nova linha (\n) do final da string de entrada
    int tamanho = strlen(entrada);
    if (entrada[tamanho - 1] == '\n') {
        entrada[tamanho - 1] = '\0';
    }

    // Lê os nomes da entrada e os armazena no array de strings
    ler_nomes(entrada, nomes);

    // Ordena os nomes em ordem alfabética
    bubbleSort(nomes, MAX_NOMES);

    // Exibe os nomes armazenados
    exibe_nomes(nomes, MAX_NOMES);

    return 0;
}

// Função para exibir os nomes armazenados no array de strings
void exibe_nomes(char nomes[][MAX], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("'%s'", nomes[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Função para ler os nomes da entrada do usuário e armazená-los no array de strings
void ler_nomes(char str[], char nomes[][MAX]) {
    char *token = strtok(str, ","); // Divide a string em tokens usando a vírgula como delimitador
    int i = 0;
    while (token != NULL && i < MAX_NOMES) {
        strcpy(nomes[i], token); // Copia o token (nome) para o array de strings
        token = strtok(NULL, ","); // Obtém o próximo token
        i++;
    }
}

// Função de ordenação Bubble Sort para ordenar os nomes em ordem alfabética
void bubbleSort(char arr[][MAX], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[MAX];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
