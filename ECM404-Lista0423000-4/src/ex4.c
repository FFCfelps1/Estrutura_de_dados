/* Enunciado:
 *  Desenvolva um programa capaz de ler os valores de uma matriz m x n. 
 *  A leitura deve ser feita em uma linha para cada linha da matriz (ver ex1).
 *  A condição de parada para a leitura das linhas é uma linha vazia
 *  (apenas com -100). O programa deve assumir que a quantidade de colunas
 *  da primeira linha define a dimensão da matriz, ou seja, qualquer linha 
 *  subsequente que não tenha a mesma quantidade de linhas da linha inicial
 *  deve causar um erro e o encerramento do programa. Após a leitura da matriz,
 *  ela deve ser exibida seguindo o padrão mostrado nos exemplos a seguir.
 *
 *  Exemplos:
 *
 *   Linha 0: 1 1 1 -100
 *   Linha 1: 2 2 2 -100
 *   Linha 2: 3 3 3 -100
 *   Linha 3: -100
 *   [[1, 1, 1],
 *   [2, 2, 2],
 *   [3, 3, 3]]
 *
 *   Linha 0: 1 1 1 1 1 -100
 *   Linha 1: 1 2 3 -100
 *   Número de colunas incompatível. Saindo...
 *
 *   Linha 0: 1 2 3 4 5 6 7 8 -100
 *   Linha 1: 8 7 6 5 4 3 2 1 -100
 *   Linha 2: -100
 *   [[1, 2, 3, 4, 5, 6, 7, 8],
 *   [8, 7, 6, 5, 4, 3, 2, 1]]
 *
 */

#include <stdio.h>

#define ARRAY_MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_matriz(int matriz[][ARRAY_MAX], int tam_linha);

int main (int argc, char *argv[])
{

  int matriz[ARRAY_MAX][ARRAY_MAX];
  int i, n, j, buffer, tam_linha = ARRAY_MAX;
  int array[ARRAY_MAX];

  for(i = 0; i < ARRAY_MAX; i++){
    for (j =0; j < tam_linha; j++){
     scanf("%i", &buffer);
      if (buffer == -100){
        break;
      }      
      matriz[i][j] = buffer;
    }
  if(i == 0){
    tam_linha = j;
  }
  if (matriz[i][0] == -100){
    break;
  }
  } 
  return 0;

  exibe_matriz(matriz, tam_linha);
}

void exibe_matriz(int matriz[][ARRAY_MAX], int size) {
    printf("[\n");
    for (int i = 0; i < size; i++) {
        printf("  [");
        for (int j = 0; j < ARRAY_MAX; j++) {
            printf("%i", matriz[i][j]);
            if (j < ARRAY_MAX - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < size - 1) {
            printf(",\n");
        }
        printf("\n");
    }
    printf("]\n");
}
