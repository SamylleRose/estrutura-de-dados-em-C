#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

Fila *fila_cria()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));

  if (fila == NULL)
  {
    printf("Erro ao alocar memória para a pilha.\n");
    exit(1);
  }

  fila->prim = NULL;
  return fila;
}

int fila_vazia(Fila *f)
{
  return f->prim == NULL;
}

void fila_insere(Fila *f, int v)
{
  No *novo = (No *)malloc(sizeof(No));

  if (novo == NULL)
  {
    printf("Erro ao alocar memória para o nó.\n");
    exit(1);
  }

  novo->info = v;
  novo->prox = NULL;

  if (fila_vazia(f))
  {
    f->prim = novo;
  }
  else
  {
    No *aux = f->prim;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

int fila_retira(Fila *f)
{
  if (fila_vazia(f))
  {
    printf("Erro: Fila vazia!\n");
    exit(1);
  }

  No *temp = f->prim;
  int valor = temp->info;
  f->prim = temp->prox;
  free(temp);

  return valor;
}

void fila_libera(Fila *f)
{
  No *aux = f->prim;

  while (aux != NULL)
  {
    No *temp = aux;
    aux = aux->prox;
    free(temp);
  }

  free(f);
}

void fila_imprime(Fila *f)
{
  if (fila_vazia(f))
  {
    printf("Fila está vazia.\n");
    return;
  }

  No *aux = f->prim;
  printf("Fila: ");

  while (aux != NULL)
  {
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}

void mostrar_inicio(Fila *f)
{
  if (fila_vazia(f))
  {
    printf("Erro: Fila vazia!\n");
    return;
  }

  printf("Início da fila: %d\n", f->prim->info);
}

void mostrar_fim(Fila *f)
{
  if (fila_vazia(f))
  {
    printf("Erro: Fila vazia!\n");
    return;
  }

  No *aux = f->prim;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
  }
  printf("Fim da fila: %d\n", aux->info);
}

void fila_inverte(Fila *f)
{
  if (fila_vazia(f))
  {
    printf("Erro: Fila vazia!\n");
    return;
  }

  No *ant = NULL;
  No *atual = f->prim;
  No *next = NULL;

  while (atual != NULL)
  {
    next = atual->prox;
    atual->prox = ant;
    ant = atual;
    atual = next;
  }

  f->prim = ant;
}

int fila_tamanho(Fila *f)
{
  int size = 0;

  No *aux = f->prim;

  while (aux != NULL)
  {
    size++;
    aux = aux->prox;
  }

  return size;
}

void fila_copia(Fila *f, Fila *f2)
{

  No *aux = f->prim;
  while (aux != NULL)
  {
    fila_insere(f2, aux->info);
    aux = aux->prox;
  }
}
