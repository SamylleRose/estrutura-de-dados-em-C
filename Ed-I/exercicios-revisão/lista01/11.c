#include <stdio.h>

void hm(int mnts, int *h, int *m){

  *h = mnts / 60;
  *m = mnts % 60;

}


int main(){

  int minutos_totais = 64;
  int horas = 0;
  int minutos = 0;

  hm(minutos_totais, &horas, &minutos);

  printf("%d minutos equivalem a %d horas e %d minutos.\n", minutos_totais, horas, minutos);


  return 0;
}