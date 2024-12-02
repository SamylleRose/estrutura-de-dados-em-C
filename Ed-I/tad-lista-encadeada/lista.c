#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista
{
  int info;
  Lista *prox, *ant;
};

Lista *cria_lista()
{
  return NULL;
}

void libera_lista(Lista *li)
{
  Lista *temp;
  while (li != NULL)
  {
    temp = li;
    li = li->prox;
    free(temp);
  }
}

Lista *inserir_elemento_inicio(Lista *li, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL)
  {
    printf("Erro de alocação de memória.\n");
    return li;
  }
  novo->info = i;
  novo->prox = li;
  novo->ant = NULL;

  if (li != NULL)
  {
    li->ant = novo;
  }

  return novo;
}

void mostrar_lista(Lista *li)
{
  Lista *p = li;
  while (p != NULL)
  {
    printf("%d ", p->info);
    p = p->prox;
  }
  printf("\n");
}

Lista *inserir_elemento_final(Lista *li, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL)
  {
    printf("Erro de alocação de memória.\n");
    return li;
  }

  novo->info = i;
  novo->prox = NULL;

  if (li == NULL)
  {
    novo->ant = NULL;
    return novo;
  }

  Lista *p = li;
  while (p->prox != NULL)
  {
    p = p->prox;
  }

  p->prox = novo;
  novo->ant = p;

  return li;
}

Lista *inserir_elemento_ordenado(Lista *li, int i)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo == NULL)
  {
    printf("Erro de alocação de memória.\n");
    return li;
  }

  novo->info = i;
  novo->prox = NULL;
  novo->ant = NULL;

  if (li == NULL)
  {
    return novo;
  }

  Lista *p = li;
  while (p != NULL && p->info < i)
  {
    p = p->prox;
  }

  if (p == NULL)
  {
    return inserir_elemento_final(li, i);
  }
  else
  {
    novo->prox = p;
    novo->ant = p->ant;
    if (p->ant != NULL)
    {
      p->ant->prox = novo;
    }
    p->ant = novo;

    if (p == li)
    {
      return novo;
    }
  }

  return li;
}

Lista *busca_elemento(Lista *li, int i)
{
  Lista *p = li;
  while (p != NULL && p->info != i)
  {
    p = p->prox;
  }
  return p;
}

Lista *remove_elemento(Lista *li, int i)
{
  Lista *p = busca_elemento(li, i);
  if (p == NULL)
  {
    printf("Elemento não encontrado.\n");
    return li;
  }

  if (p->ant != NULL)
  {
    p->ant->prox = p->prox;
  }
  else
  {
    li = p->prox;
  }

  if (p->prox != NULL)
  {
    p->prox->ant = p->ant;
  }

  free(p);
  return li;
}
