/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings,
 * que deve ser exibido utilizando o procedimento exibe_nomes fornecido.
 * A quantidade de nomes digitado deve ser sempre 5 (definido por MAX_NOMES).
 *
 * Dica: pesquise pela função strtok
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['Matheus', 'Ana Julia', 'Marco Antonio', 'Joao', 'Victoria']
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['Julio', 'Tiririca', 'Diego', 'Alexandre', 'Nicola']
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMES 5 // Valor máximo para o tamanho do array. Não modifique.
#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_nomes(char nomes[MAX_NOMES][MAX]);
void ler_nomes(char str[], char nomes[MAX_NOMES][MAX]);

int main() {
    char nomes[MAX_NOMES][MAX];
    char entrada[MAX];

    // Ler os nomes digitados pelo usuário
    ler_nomes(entrada, nomes);

    // Exibir os nomes
    exibe_nomes(nomes);

    return 0;
}

// Define a função para exibir os nomes como uma lista
void exibe_nomes(char nomes[MAX_NOMES][MAX]) {
    printf("[");
    for(int i = 0; i < MAX_NOMES; ++i) {
        printf("'%s'", nomes[i]);
        if(i != MAX_NOMES - 1) printf(", ");
    }
    printf("]\n");
}

// Define a função para ler os nomes digitados pelo usuário
void ler_nomes(char str[], char nomes[MAX_NOMES][MAX]) {
    // Solicita que o usuário digite uma string
    printf("Nomes: ");
    fgets(str, MAX, stdin);

    // Usa a função strtok para separar os nomes usando a vírgula como delimitador
    char *token = strtok(str, ",");
    int i = 0;
    while(token != NULL && i < MAX_NOMES) {
        // Remove espaços em branco no início e no final do nome
        while(isspace(*token)) token++;
        int tamanho = strlen(token);
        while(tamanho > 0 && isspace(token[tamanho - 1])) {
            token[tamanho - 1] = '\0';
            tamanho--;
        }
        // Copia o nome para o array de nomes
        strcpy(nomes[i], token);
        // Obtém o próximo token
        token = strtok(NULL, ",");
        i++;
    }
}
