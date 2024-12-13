#include <stdio.h>
#include <stdlib.h>

#include "fazenda.h"

Fazenda *criar_Fazenda()
{

  Fazenda *fazenda = (Fazenda *)malloc(sizeof(Fazenda *));

  if (fazenda == NULL)
  {
    printf("Erro ao alocar memória para a pilha.\n");
    exit(1);
  }

  fazenda = NULL;
  return fazenda;
}

void liberar_Fazenda(Fazenda *li)
{

  if (li == NULL)
  {
    printf("Lista vazia!");
    return;
  }
  Fazenda *atual = li->next;
  Fazenda *proxima;

  while ((atual != li))
  {
    proxima = atual->next;
    free(atual);
    atual = proxima;
  }

  free(li);
}

Fazenda *inserir_Fazenda(Fazenda *li, int id, char nome, char localizacao)
{
  Fazenda *novo = (Fazenda *)malloc(sizeof(Fazenda));

  if (novo == NULL)
  {
    printf("\nErro na alocação!\n");
    exit(1);
  }

  novo->id;
  novo->nome;
  novo->localizacao;
  novo->rebanho = NULL;
  novo->next = NULL;

  return novo;
}

void adicionar_animal(Fazenda *fazenda, Animal *animal)
{
  if (fazenda == NULL || animal == NULL)
  {
    printf("\nFazenda ou animal inválida.\n");
  }

  if (fazenda->rebanho == NULL)
  {
    fazenda->rebanho = animal;
  }
  else
  {
    Animal *atual = fazenda->rebanho;

    while (atual->next != NULL)
    {
      atual = atual->next;
    }

    atual->next = animal;
  }
}

void gerenciar_fazendas(Fazenda *li)
{
}
void mostrar_Fazenda(Fazenda *li) {}
Fazenda *remover_fazenda(Fazenda *li, int id) {}