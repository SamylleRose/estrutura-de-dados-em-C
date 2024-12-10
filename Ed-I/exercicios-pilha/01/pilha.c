#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Lista *cria_lista()
{
  return NULL;
}

Pilha *pilha_cria()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->prim = cria_lista();
}
