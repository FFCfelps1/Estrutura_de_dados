//usar os includes para bibliotecas
#include <stdio.h> // esta biblioteca para passar info para o console
#include <stdlib.h> // esta biblioteca para alocar memoria

/*
  int -> numeros inteiros
  float -> numeros com casas decimais
  char -> 1 caractere 'a'
  double -> numeros com casas decimais
*/

//c é baseado em funções (colocar ponto e virgula no final de linhas de comando)
// todo programa tem uma função principal 
int main(void) { // cria a função principal e ela esta vazia para programar dentro dela

  int i = 0;
  float f = 1.0;
  char c = 'a';

  int a = 10;
  int b = 2;

  printf("2+10 = %i \n", a + b);
  printf("2-10 = %i \n", a - b);
  printf("2*10 = %i \n", a * b);
  printf("2/10 = %f \n", (float)a/b);

  scanf("%i", &i); //coloca o que se espera do usuario e qual variavel ele vai colocar

  i = 3 > 4; // retorna 0, porque é falso
  
  printf("Hello World\n"); //toda frase é em aspas duplas = cadeia de caracteres
  
  printf("%i\n", i); // porcentagem define o tipo da variavel que vai ser impressa, %i é para inteiro, %f é para float e fora coloca a variavel que vai ser impressa
  
  printf("%.2f\n", f);
  return 0; // para confirmar que o programa foi executado com sucesso
}

/*
todas as operações do python são validas: +, -, *, /, % (retorna o resto da divisão), ++ é o += e o -- é o -=
*/