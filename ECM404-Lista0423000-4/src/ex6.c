/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3 
 * e, a seguir, exiba a sua forma transposta
 *
 * Exemplos: 
 *
 *
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    [[1, 4, 7],
 *    [2, 5, 8],
 *    [3, 6, 9]]
 *    
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    [[1, 0, 0],
 *    [0, 1, 0],
 *    [0, 0, 1]]
 *    
 */

#include <stdio.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Função para calcular e exibir a transposta da matriz 3x3 */
void transposta(int matriz[ARRAY_MAX][ARRAY_MAX]);

int main(int argc, char *argv[]) {
    int matriz[ARRAY_MAX][ARRAY_MAX];

    // Leitura da matriz
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < ARRAY_MAX; i++) {
        printf("Digite a linha %d: ", i);
        scanf("%d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);
    }

    // Chama a função para calcular e exibir a transposta
    printf("Transposta da matriz:\n");
    transposta(matriz);

    return 0;
}

void transposta(int matriz[ARRAY_MAX][ARRAY_MAX]) {
    int transposta[ARRAY_MAX][ARRAY_MAX];

    // Calcula a transposta
    for (int i = 0; i < ARRAY_MAX; i++) {
        for (int j = 0; j < ARRAY_MAX; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Exibe a transposta
    printf("[\n");
    for (int i = 0; i < ARRAY_MAX; i++) {
        printf("  [");
        for (int j = 0; j < ARRAY_MAX; j++) {
            printf("%d", transposta[i][j]);
            if (j < ARRAY_MAX - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < ARRAY_MAX - 1) {
            printf(",\n");
        }
        printf("\n");
    }
    printf("]\n");
}

