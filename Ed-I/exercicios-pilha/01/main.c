#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main()
{

  Pilha *minha_pilha = pilha_cria();
  Pilha *copia_pilha = pilha_cria();

  pilha_push(minha_pilha, 10);
  pilha_push(minha_pilha, 20);
  pilha_push(minha_pilha, 30);

  pilha_imprime(minha_pilha);

  int valor = pilha_pop(minha_pilha);
  printf("Desempilhado: %d\n", valor);

  pilha_imprime(minha_pilha);

  // pilha_inverte(minha_pilha);

  pilha_imprime(minha_pilha);

  int size = pilha_tamanho(minha_pilha);

  // printf("Tamanho: %d\n", size);

  // mostrar_topo(minha_pilha);

  pilha_copia(minha_pilha, copia_pilha);

  printf("\nPilha copiada:\n");
  pilha_imprime(copia_pilha);

  pilha_libera(minha_pilha);

  return 0;
}