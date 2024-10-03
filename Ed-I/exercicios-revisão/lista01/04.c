#include <stdio.h>

int main(){

  int inteiro = 7;
  float real = 4.5;

  int *p1 =  0;
  float *p2 = 0;

  p1 = &inteiro;
  p2 = &real;

  printf("Valor: %d\n", inteiro);
  printf("Endereço: %p\n", &inteiro);
  printf("Valor: %f\n", real);
  printf("Endereço: %p\n\n", &real);

  printf("Valor: %p\n", p1);
  printf("Valor apontado: %d\n", *p1);
  printf("Endereço: %p\n", &p1);
  printf("Valor: %p\n", p2);
  printf("Valor apontado: %f\n", *p2);
  printf("Endereço: %p\n\n", &p2);

  
}