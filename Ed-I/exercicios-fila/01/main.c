#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main()
{

  Fila *fila = fila_cria();
  Fila *fila2 = fila_cria();

  fila_insere(fila, 10);
  fila_insere(fila, 20);
  fila_insere(fila, 30);

  printf("Fila original:\n");
  fila_imprime(fila);

  printf("Elemento retirado: %d\n", fila_retira(fila));
  fila_imprime(fila);

  mostrar_inicio(fila);
  mostrar_fim(fila);

  printf("Inversão da fila:\n");
  fila_inverte(fila);
  fila_imprime(fila);

  printf("Tamanho da fila: %d\n", fila_tamanho(fila));

  printf("Cópia da fila:\n");
  fila_copia(fila, fila2);
  fila_imprime(fila2);

  fila_libera(fila);
  fila_libera(fila2);

  return 0;
}