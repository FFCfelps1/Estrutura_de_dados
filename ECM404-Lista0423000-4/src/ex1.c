/* Enunciado: Desenvolva um programa capaz de ler n valores inteiros e os
 *  insira em um array. A leitura deve ser feita em uma única linha, separando 
 *  os valores por espaço. A leitura deve ser encerrada quando um 
 *  valor -100 é lido. Após a leitura ser realizada, o programa deve utilizar 
 *  o procedimento exibe_array para exibir o array em uma única linha 
 *  e entre colchetes.
 *
 *  Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 8 -100
 *    [1, 2, 3, 4, 5, 6, 7, 8]
 *
 *    Digite os valores para o array: 1 2 3 4 -100
 *    [1, 2, 3, 4]
 *
 */

#include <stdio.h>

#define MAX_SIZE 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_array(int array[], int tam_array);

int main (int argc, char *argv[])
{

  int array[MAX_SIZE];
  int n, i = 0;

  printf("Digite os valores para o array: ");

  // Leitura dos valores inteiros e armazenamento no array
  while (scanf("%i", &n) && n != -100 && i < MAX_SIZE) {
      array[i++] = n;
  }

  // Chamada da função para exibir o array
  exibe_array(array, i);

  return 0;
}
void exibe_array(int arr[], int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
      printf("%i", arr[i]);
      if (i < size - 1) {
          printf(", ");
      }
  }
  printf("]\n");
}