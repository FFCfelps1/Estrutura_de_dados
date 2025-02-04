#include <stdio.h>

/* Enunciado - Faça um programa que calcula a associação em paralelo 
 * de dois resistores R1 e R2 fornecidos pelo usuário via teclado e retorna seu valor com duas casas decimais. 
 * O programa deverá solicitar valores e calcular a resistência equivalente até 
 * que o usuário entre com um valor para alguma das resistências igual a 0
 *
 * Exemplos:
 *
 * Digite um valor para R1: 470
 * Digite um valor para R2: 2200
 * Resistencia equivalente em paralelo: 387.27
 *
 * Digite um valor para R1: 0
 * Digite um valor para R2: 100
 * Finalizando o programa!
*/

int main (int argc, char *argv[])
{
float R1, R2, Req;
  do{
  printf("Digite um valor para R1: ");
  scanf("%f", &R1);
  printf("Digite um valor para R2: ");
  scanf("%f", &R2);

if(R1 > 0 && R2 > 0){
  Req = (R1*R2)/(R1+R2);
   printf("%.2f \n", Req);
}
    else{
      continue;
    }
  }
while (R1 > 0 && R2 > 0);

printf("Finalizando o programa!");

  return 0;
}

