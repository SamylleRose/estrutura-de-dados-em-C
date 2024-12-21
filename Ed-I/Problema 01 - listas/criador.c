#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "criador.h"

Criador *criarCriador()
{

  Criador *criador = (Criador *)malloc(sizeof(Criador));

  if (criador == NULL)
  {
    printf("Erro ao alocar memória para a fazenda.\n");
    exit(1);
  }

  criador = NULL;
  return NULL;
}

Criador *inserirCriador(Criador *liCriador)
{
  Criador *novo = (Criador *)malloc(sizeof(Criador));

  if (novo == NULL)
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  printf("\nInforme os dados do criador:\n");

  printf("\nNome: ");
  scanf("%s", novo->nome);

  printf("CPF: ");
  scanf("%s", novo->cpf);

  novo->prev = NULL;
  novo->next = liCriador;

  if (liCriador != NULL)
  {
    liCriador->prev = novo;
  }

  printf("\nCriador adicionado com sucesso!\n");

  return novo;
}

void mostrarCriador(Criador *liCriador)
{

  Criador *aux = liCriador;

  printf("\n-------------Criadores--------------\n");
  while (aux != NULL)
  {
    printf("Nome: %s\n", aux->nome);
    printf("CPF:  %s\n\n", aux->cpf);

    aux = aux->next; // avança para o próximo nó
  }
}

Criador *removerCriador(Criador *liCriador)
{

  char cpf[15];

  printf("\nInforme o CPF do criador que deseja remover: \n");

  printf("\nCPF: ");
  scanf("%s", cpf);

  // Ponteiro auxiliar para percorrer a lista
  Criador *atual = liCriador;

  // Percorre a lista procurando pelo CPF
  while (atual != NULL)
  {
    if (strcmp(atual->cpf, cpf) == 0)
    {
      // Encontramos o criador com o CPF desejado

      // Caso seja o primeiro nó (cabeça)
      if (atual->prev == NULL)
      {
        // O novo início da lista passa a ser o próximo elemento
        liCriador = atual->next;

        // Se a lista não ficou vazia, ajusta o ponteiro 'prev' do novo primeiro nó
        if (liCriador != NULL)
        {
          liCriador->prev = NULL;
        }
      }
      else
      {
        // Ajusta o encadeamento do nó anterior
        atual->prev->next = atual->next;
      }

      // Ajusta o encadeamento do nó seguinte (se existir)
      if (atual->next != NULL)
      {
        atual->next->prev = atual->prev;
      }

      // Libera a memória do nó removido
      free(atual);

      printf("\nCriador com CPF '%s' removido com sucesso!\n", cpf);
      return liCriador; // Retorna a nova cabeça da lista
    }
    atual = atual->next; // Avança para o próximo nó
  }

  // Se chegou até aqui, não encontrou o CPF
  printf("\nCriador com CPF '%s' não encontrado.\n", cpf);
  return liCriador;
}
