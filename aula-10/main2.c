#include <stdio.h>

int main(void) {

  int vet [] = {1, 2, 3, 4, 5};
  int *ponteiro = NULL;

  ponteiro = vet;

  printf("Primeiro elemento do array: %i\n", vet[0]);
  printf("Endereço do primeiro elemento do array: %p\n", &vet[0]);
  printf("Endereço do primeiro elemento do array: %p\n", &vet);
  printf("\nPrimeiro elemento do array: %i\n", vet[1]);
  printf("Endereço do segundo elemento do array: %p\n", &vet[1]);
  
  ponteiro++;
  printf("Endereço do primeiro elemento do array: %p\n", ponteiro);

  for(int i = 0; i < 5; i++){
    printf("Endereço do elemento %i: %p\n", i, &vet[i]);
    printf("Endereço do elemento %i: %i\n", i, *(ponteiro+i));
  }
}
