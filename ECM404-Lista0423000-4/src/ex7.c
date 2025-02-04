/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de duas matriz 3x3 
 * e, a seguir, exiba a matriz resultante da multiplicação entre elas.
 *
 * Exemplos: 
 *
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[1, 1, 1],
 *    [2, 2, 2],
 *    [3, 3, 3]]
 *    
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[14, 14, 14],
 *    [32, 32, 32],
 *    [50, 50, 50]]
 * 
 *    Digite a linha 0: 2 0 0
 *    Digite a linha 1: 0 2 0
 *    Digite a linha 2: 0 0 2
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[2, 2, 2],
 *    [4, 4, 4],
 *    [6, 6, 6]]
 *    
 */

#include <stdio.h>

#define ARRAY_MAX 3 // Valor máximo para o tamanho do array. Não modifique.

/* Função para multiplicar duas matrizes 3x3 */
void multiplicarMatrizes(int matriz1[ARRAY_MAX][ARRAY_MAX], int matriz2[ARRAY_MAX][ARRAY_MAX], int resultado[ARRAY_MAX][ARRAY_MAX]);

/* Função para exibir a matriz */
void exibirMatriz(int matriz[ARRAY_MAX][ARRAY_MAX]);

int main(int argc, char *argv[]) {
    int matriz1[ARRAY_MAX][ARRAY_MAX], matriz2[ARRAY_MAX][ARRAY_MAX], resultado[ARRAY_MAX][ARRAY_MAX];

    // Leitura da primeira matriz
    printf("Digite os elementos da primeira matriz 3x3:\n");
    for (int i = 0; i < ARRAY_MAX; i++) {
        printf("Digite a linha %d: ", i);
        scanf("%d %d %d", &matriz1[i][0], &matriz1[i][1], &matriz1[i][2]);
    }

    // Leitura da segunda matriz
    printf("Digite os elementos da segunda matriz 3x3:\n");
    for (int i = 0; i < ARRAY_MAX; i++) {
        printf("Digite a linha %d: ", i);
        scanf("%d %d %d", &matriz2[i][0], &matriz2[i][1], &matriz2[i][2]);
    }

    // Chamada da função para multiplicar as matrizes
    multiplicarMatrizes(matriz1, matriz2, resultado);

    // Exibição do resultado
    printf("Resultado da multiplicação das matrizes:\n");
    exibirMatriz(resultado);

    return 0;
}

void exibirMatriz(int matriz[ARRAY_MAX][ARRAY_MAX]) {
    printf("[\n");
    for (int i = 0; i < ARRAY_MAX; i++) {
        printf("  [");
        for (int j = 0; j < ARRAY_MAX; j++) {
            printf("%d", matriz[i][j]);
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

void multiplicarMatrizes(int matriz1[ARRAY_MAX][ARRAY_MAX], int matriz2[ARRAY_MAX][ARRAY_MAX], int resultado[ARRAY_MAX][ARRAY_MAX]) {
    for (int i = 0; i < ARRAY_MAX; i++) {
        for (int j = 0; j < ARRAY_MAX; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < ARRAY_MAX; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}