#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerString(char str[]);

int main(void) {

  int array[] = {1, 2, 3, 4, 5};
  char str[50];
  char str2[] = "eu sou uma string";
  float a = 0;
  float b = 10.5;
  

  setbuf(stdin, 0);
  scanf("%s\n", str);

  setbuf(stdin, 0); // limpa o buffer
  fgets(str, 10, stdin); //le string pelo código seco

  lerString(str); //le string
  
   printf("%s\n", str2);
   printf("%c\n", str2[5]);

  strcpy(str2, str); //copia string
  strcat(str2, str); //junta duas string
  int comp = strcmp(str, str2); //devolve um valor inteiro que indica a diferença entre as duas strings
  // 0 se as strings forem iguais
  // pega o caracter da primeira string e subtrai pelo caracter da segunda string e ve se deu 0
  // se a primeira string for maior que a segunda string, devolve um valor positivo
  // se a primeira string for menor que a segunda string, devolve um valor negativo
  a = atof(str); //converte string para float
  b = atoi(str); //converte string para int

  sprintf(str,"%s é igual a %i, b é igual a %f", str, comp, b);
  print("%s", str)
  
  return 0;
}

void lerString(char str[]){

  setbuf(stdin, 0);
  fgets(str, 50, stdin);

  if (str[strlen(str) - 1] == '\n'){
    str[strlen(str) - 1] = '\0';
  }
  
}