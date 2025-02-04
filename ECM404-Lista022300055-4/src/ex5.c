#include <stdio.h>

/* Enunciado - Faça um programa que leia uma data no seguinte formato:
 * D/M/A. O programa deve determinar se a data digitada válida ou não.
 * Lembre-se que Fevereiro tem 29 dias em anos bissextos e 28 dias em anos não
 * bissextos.
 *
 * Exemplos:
 *
 * Data: 22/02/2022
 * Data valida!
 *
 * Data: 29/02/2020
 * Data valida!
 *
 * Data: 29/02/2022
 * Data invalida!
 *
 * Data: 31/06/2022
 * Data invalida!
 *
 * Data: 31/13/2022
 * Data invalida!
 */

int main (int argc, char *argv[])
{
  int Dia = 0;
  int Mes = 0;
  int Ano = 0;

  do{
    printf("Data: ");
    scanf("%i/%i/%i", &Dia, &Mes, &Ano);
    if (Dia < 1 || Dia > 31 || Mes < 1 || Mes > 12 || Ano < 1|| Ano%4 != 0 && Dia == 
      29||Mes%2 == 0 && Mes >= 7 && Dia == 31 ||Mes%2 != 0 && Mes <= 12 && Dia == 31){
      printf ("Data inválida!\n");
    }
    else
      printf("Data válida!");
  }
    while(Dia < 1 || Dia > 31 || Mes < 1 || Mes > 12 || Ano < 1);
return 0;
}
