#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Pilha *pilha_cria()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

  if (pilha == NULL)
  {
    printf("Erro ao alocar memória para a pilha.\n");
    exit(1);
  }

  pilha->primeiro = NULL;
  return pilha;
}

void pilha_push(Pilha *pilha, int valor)
{
  No *novo = (No *)malloc(sizeof(No));

  if (novo == NULL)
  {
    printf("Erro ao alocar memória para o nó.\n");
    exit(1);
  }

  novo->info = valor;
  novo->proximo = pilha->primeiro;

  pilha->primeiro = novo;
}

int pilha_pop(Pilha *pilha)
{
  if (pilha_vazia(pilha))
  {
    printf("Pilha vazia! Não é possivel desempilhar. \n");
    exit(1);
  }

  No *temp = pilha->primeiro;
  int valor = temp->info;

  pilha->primeiro = temp->proximo;

  free(temp);

  return valor;
}

int pilha_vazia(Pilha *pilha)
{
  return (pilha->primeiro == NULL);
}

void pilha_libera(Pilha *pilha)
{
  while (!pilha_vazia(pilha))
  {
    pilha_pop(pilha);
  }

  free(pilha);
}

void pilha_imprime(Pilha *pilha)
{
  if (pilha == NULL)
  {
    printf("Erro: Pilha não inicializada.\n");
    exit(1);
  }

  No *atual = pilha->primeiro;

  printf("Pilha: ");
  while (atual != NULL)
  {
    {
      printf("%d ", atual->info);
      atual = atual->proximo;
    }
  }
}

void mostrar_topo(Pilha *pilha)
{
  if (pilha == NULL)
  {
    printf("Erro: Pilha não inicializada. \n");
    exit(1);
  }
  if (pilha_vazia(pilha))
  {
    printf("Erro: Pilha está vazia. Não há elemnto no topo. \n");
    exit(1);
  }

  printf("Topo da pilha: %d", pilha->primeiro->info);
}

void pilha_inverte(Pilha *pilha)
{
  if (pilha == NULL || pilha_vazia(pilha))
  {
    return;
  }

  Pilha *aux = pilha_cria();

  while (!pilha_vazia(pilha))
  {
    pilha_push(aux, pilha_pop(pilha));
  }

  *pilha = *aux;
  free(aux);
}
int pilha_tamanho(Pilha *pilha)
{

  int size = 0;

  No *atual = pilha->primeiro;

  while (atual != NULL)
  {
    atual = atual->proximo;
    size++;
  }

  return size;
}
void pilha_copia(Pilha *pilha, Pilha *pilha2)
{

  if (pilha == NULL || pilha2 == NULL)
  {
    printf("Erro: Uma ou ambas as pilhas não foram inicializadas.\n");
    return;
  }

  Pilha *aux = pilha_cria();

  No *atual = pilha->primeiro;

  while (atual != NULL)
  {
    pilha_push(aux, atual->info);
    atual = atual->proximo;
  }

  while (!pilha_vazia(aux))
  {
    pilha_push(pilha2, pilha_pop(aux));
  }

  free(aux);
}
