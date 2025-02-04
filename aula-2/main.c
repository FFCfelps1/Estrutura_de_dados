#include <stdio.h>

int main(void) {
  float num = 0;
  printf("Enter a number: ");
  scanf("%f", &num);

  if (num> 6){
    printf("The number is greater than 6");
  }
  
  return 0;
}