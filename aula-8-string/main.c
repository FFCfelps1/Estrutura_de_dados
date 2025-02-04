#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int i = 0;
  char c = 'a';

  printf("Digite um numero: ");
  scanf("%i", &i);
  printf("inteiro %i\n", i);

  
  printf("Digite um caracter: ");
  scanf(" %c", &c);
  printf("caracter %c enter\n", c);
  
  return 0;
}