#include <stdio.h>
#include <stdlib.h>

int main(){

  int a = 10;
  int *p1 = &a;
  int **p2 = &p1;

  printf("&a = %p, a = %d\n", &a, a);
  printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
  printf("&p2 = %p, p2 = %p, *p2 = %p, **p2 = %d\n\n", &p2, p2, *p2, **p2);

  **p2 = 99;  

  
  printf("&a = %p, a = %d\n", &a, a);
  printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
  printf("&p2 = %p, p2 = %p, *p2 = %p, **p2 = %d\n\n", &p2, p2, *p2, **p2);

  float z = 2.5;
  float *fp;

  fp = &z;

  printf("*&z = %f\n", *&z);
  printf("*fp = %f\n", *fp);
  printf("**&fp = %f\n", **&fp);

  return 0;
} 