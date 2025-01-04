#include <stdio.h>
#include <stdlib.h>
#include "rota.h"

int encomendaId = 0;

Encomenda *criarEncomenda()
{
  Encomenda *novaEncomenda = (Encomenda *)malloc(sizeof(Encomenda));

  if (novaEncomenda == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return NULL;
  }

  printf("\nDescrição: ");
  scanf(" %99[^\n]", novaEncomenda->descricao);

  encomendaId += 1;
  novaEncomenda->id = encomendaId;

  return novaEncomenda;
}

Encomenda *adicionarEncomendaCliente(Encomenda *encomendas, int *quantidadeEncomendas, Encomenda *novaEncomenda)
{
  encomendas = (Encomenda *)realloc(encomendas, (*quantidadeEncomendas + 1) * sizeof(Encomenda));
  if (encomendas == NULL)
  {
    printf("Erro ao realocar memória para a nova encomenda!\n");
    return NULL;
  }

  encomendas[*quantidadeEncomendas] = *novaEncomenda;
  (*quantidadeEncomendas)++;

  return encomendas;
}

Rota *adicionarRota(Rota *filaRota, Cliente *cliente, Encomenda *novaEncomenda)
{
  Rota *novaRota = (Rota *)malloc(sizeof(Rota));

  novaRota->quantidadeEncomendas = 0;

  novaRota->encomendas = NULL;
  novaRota->encomendas = adicionarEncomendaCliente(novaRota->encomendas, &novaRota->quantidadeEncomendas, novaEncomenda);

  novaRota->cliente = cliente;
  novaRota->prox = filaRota;

  return novaRota;
}

Rota *buscarRotaCliente(Rota *filaRota, Cliente *cliente)
{
  Rota *atual = filaRota;

  while (atual != NULL && atual->cliente != cliente)
  {
    atual = atual->prox;
  }

  return atual;
}

Rota *adicionarEncomenda(Rota *filaRota, Cliente *cliente)
{
  // Checar se já há uma encomenda para o cliente passado como parametro.
  // Se sim, adicionar a encomenda, se não, criar um novo nó Rota e adicionar no fim da fila.
  //
  Encomenda *novaEncomenda = criarEncomenda();

  Rota *rotaCliente = buscarRotaCliente(filaRota, cliente);

  if (rotaCliente != NULL)
  {
    // Cria uma nova encomenda
    // Adiciono nessa rota

    rotaCliente->encomendas = adicionarEncomendaCliente(rotaCliente->encomendas, &rotaCliente->quantidadeEncomendas, novaEncomenda);
  }
  else
  {
    filaRota = adicionarRota(filaRota, cliente, novaEncomenda);
  }

  return filaRota;
}

void mostrarEncomendas(Encomenda *encomendas, int quantidadeEncomendas)
{
  for (int i = 0; i < quantidadeEncomendas; i++)
  {
    printf("Encomenda ID %d descricao %s\n", encomendas[i].id, encomendas[i].descricao);
  }
}

void mostrarRota(Rota *filaRota)
{
  Rota *atual = filaRota;

  while (atual != NULL)
  {
    printf("\nEncomendas do cliente %s:\n", atual->cliente->nome);
    mostrarEncomendas(atual->encomendas, atual->quantidadeEncomendas);
    atual = atual->prox;
  }
}