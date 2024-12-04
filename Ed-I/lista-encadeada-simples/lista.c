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

Lista *busca_elemento(Lista *li, int i)
{
  Lista *aux = li;
  while (aux != NULL)
  {
    if (aux->info == i)
      return aux;
    aux = aux->prox;
  }
  return NULL;
}
Lista *remove_elemento(Lista *li, int i)
{
  Lista *ant = NULL;
  Lista *aux = li;
  while (aux != NULL && aux->info != i)
  {
    ant = aux;
    aux = aux->prox;
  }
  // nao encontrou o elemento
  if (aux == NULL)
    return li;

  // remove o elemento do inicio
  if (ant == NULL)
    li = aux->prox;
  else
    // remove o elemento do meio ou do fim
    ant->prox = aux->prox;

  // libera a memoria do elemento removido
  free(aux);

  // retorna a lista atualizada
  return li;
}