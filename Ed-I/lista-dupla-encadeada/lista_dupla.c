#include <stdlib.h>
#include <stdio.h>

#include "lista_dupla.h"

Lista *cria_lista()
{
  return NULL;
}

Lista *inserir_elemento_inicio(Lista *li, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->ant = NULL;
  novo->prox = li;

  if (li != NULL)
  {
    li->ant = novo;
  }

  return novo;
}

Lista *inserir_circular(Lista *li, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;

  if (li == NULL)
  {

    novo->ant = novo;
    novo->prox = novo;
  }

  novo->ant = li->ant;
  novo->prox = li;
  li->ant->prox = novo;
  li->ant = novo;

  return novo;
}

void mostrar_lista(Lista *li)
{
  if (li == NULL)
  {
    printf("Lista vazia.\n");
    return;
  }

  Lista *aux = li;

  do
  {
    printf("%d <- %d -> %d", aux->ant->info, aux->info, aux->prox->info);
    aux = aux->prox;
  }

  while (aux != li);
}