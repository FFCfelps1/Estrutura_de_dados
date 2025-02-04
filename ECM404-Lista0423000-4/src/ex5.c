/* Enunciado:
 *   Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3 
 *   e, a seguir, calcule e exiba sua determinante. O cálculo da determinante 
 *   deve ser feito pela função determinante, que recebe por referência uma 
 *   matriz 3x3 e retorna o valor inteiro referente à determinante.
 *
 *   Exemplos: 
 *     Digite a linha 0: 2 3 4
 *     Digite a linha 1: 1 3 4
 *     Digite a linha 2: 5 6 7
 *     -3
 *
 *     Digite a linha 0: 1 0 0
 *     Digite a linha 1: 0 1 0
 *     Digite a linha 2: 0 0 1
 *     1
 *
 */

#include <stdio.h>

// Função para calcular a determinante da matriz 3x3
int determinante(int matriz[3][3]);

int main(int argc, char *argv[]) {
    int matriz[3][3];

    // Leitura da matriz
    printf("Digite a linha 0: ");
    scanf("%d %d %d", &matriz[0][0], &matriz[0][1], &matriz[0][2]);
    printf("Digite a linha 1: ");
    scanf("%d %d %d", &matriz[1][0], &matriz[1][1], &matriz[1][2]);
    printf("Digite a linha 2: ");
    scanf("%d %d %d", &matriz[2][0], &matriz[2][1], &matriz[2][2]);

    // Cálculo e exibição da determinante
    printf("%d\n", determinante(matriz));

    return 0;
}

int determinante (int matriz[3][3]){
      int det;
      det = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + 
            (matriz[0][1] * matriz[1][2] * matriz[2][0]) + 
            (matriz[0][2] * matriz[1][0] * matriz[2][1]) - 
            (matriz[0][2] * matriz[1][1] * matriz[2][0]) - 
            (matriz[0][1] * matriz[1][0] * matriz[2][2]) - 
            (matriz[0][0] * matriz[1][2] * matriz[2][1]);
      return det;
}