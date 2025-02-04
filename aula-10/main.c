#include <stdio.h>

void exemplo(int a); //valor de i
void exemplo2(int *a); //enderço de i (referência)

int main(void) {

  int i = 10;
  int *ponteiro_i = NULL;

  printf("Valor de i: %i\nEndereço de i %p\n", i, &i);
  printf("\nValor de ponteiro_i: %p\nEndereço de ponteiro_i %p\n", ponteiro_i, &ponteiro_i);

  ponteiro_i++;
  printf("\nValor de somado 1: %p\nEndereço do ponteiro: %p\n",ponteiro_i, &ponteiro_i); //& é um operador de memória, referenciador

  ponteiro_i = &i;
  printf("\nValor de i: %p\nEndereço de i %p\n", ponteiro_i, &ponteiro_i);
  printf("\nValor de i por ponteiro_i: %i\n", *ponteiro_i);
  // * para puxar o valor do endereço de memória

  exemplo(i);
  printf("\nValor de i: %i\n", i);
  exemplo2(&i);
  printf("Valor de i: %i\n", i);
  
  return 0;
}

void exemplo(int a){
  exemplo2(&a); // envia o endereço do parâmetro da função, assim não terá o valor esperado
  a = a + 1;
  
}

void exemplo2(int *a){

  *a = *a + 1;
  
}