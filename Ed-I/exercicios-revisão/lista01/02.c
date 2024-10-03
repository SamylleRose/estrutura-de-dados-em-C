#include <stdio.h>


void maximoMinimo( int *v, int n, int *maximo, int *minimo){

  *maximo = v[0];
  *minimo = v[0];

  for(int i = 0; i < n; i++){
    if (*maximo < v[i]){
      *maximo = v[i];
    }

    if (*minimo > v[i]){
      *minimo = v[i];
    }
  }

}

int main(){

  int v[] = {1, 2, 3, 4, 5};
  int n = 5;
  int maximo, minimo = 0;


  maximoMinimo(v, n, &maximo, &minimo);

  printf(" Máximo: %d Mínimo: %d\n", maximo, minimo);

  return 0;
}