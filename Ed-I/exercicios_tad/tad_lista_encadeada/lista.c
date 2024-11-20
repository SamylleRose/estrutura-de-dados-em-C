#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *cria_lista()
{
  return NULL;
}

void libera_lista(Lista *li)
{
  Lista *aux;
  while (li != NULL)
  {
    aux = li;
    li = li->prox;
    free(aux);
  }
}

Lista *insere_lista_inicio(Lista *li, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = li;
  return novo;
}

void mostrar_lista(Lista *li)
{
  Lista *aux = li;
  while (aux != NULL)
  {
    printf("%d\n", aux->info);
    aux = aux->prox;
  }
}

Lista *remove_elemento(Lista *li, int i)
{
  Lista *aux = li;
  Lista *ant = NULL;

  while (aux != NULL && aux->info != i)
  {

    ant = aux;
    aux = aux->prox;
  }

  if (ant == NULL)
  {
    li = aux->prox;
    free(aux);
  }

  if (aux != NULL)
  {
    ant->prox = aux->prox;
    free(aux);
  }

  else
  {
    printf("Elemento não encontrado!");
  }

  return li;
}