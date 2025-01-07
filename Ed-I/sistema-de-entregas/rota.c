#include <stdio.h>
#include <stdlib.h>

#include "rota.h"

Encomenda *criarEncomenda() // Cria uma nova encomenda
{
  Encomenda *novaEncomenda = (Encomenda *)malloc(sizeof(Encomenda));

  if (novaEncomenda == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return NULL;
  }

  printf("\nDescrição: ");
  scanf(" %99[^\n]", novaEncomenda->descricao);

  novaEncomenda->id = gerarId();

  return novaEncomenda;
}
// Adiciona uma nova encomenda a um array de encomendas de um cliente.
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

// Percorre a lista encadeada de rotas e retorna o último elemento.
Rota *buscarUltimoDaFila(Rota *filaRota)
{
  Rota *atual = filaRota;

  if (atual != NULL)
  {
    while (atual->prox != NULL)
    {
      atual = atual->prox;
    }
  }

  return atual;
}

// Cria uma nova rota e adiciona a encomenda de um cliente.
Rota *adicionarRota(Rota *filaRota, Cliente *cliente, Encomenda *novaEncomenda)
{
  Rota *novaRota = (Rota *)malloc(sizeof(Rota));

  novaRota->quantidadeEncomendas = 0;

  novaRota->encomendas = NULL;
  novaRota->encomendas = adicionarEncomendaCliente(novaRota->encomendas, &novaRota->quantidadeEncomendas, novaEncomenda);

  novaRota->cliente = cliente;
  novaRota->prox = NULL;

  if (filaRota != NULL)
  {
    Rota *ultimaRota = buscarUltimoDaFila(filaRota);

    ultimaRota->prox = novaRota;
  }
  else
  {
    filaRota = novaRota;
  }

  return filaRota;
}

// Adiciona uma nova devolução ao final da fila de devoluções.
Rota *adicionarDevolucao(Rota *filaDevolucao, Rota *novaDevolucao)
{

  if (filaDevolucao != NULL)
  {
    Rota *ultimaRota = buscarUltimoDaFila(filaDevolucao);

    ultimaRota->prox = novaDevolucao;
  }
  else
  {
    filaDevolucao = novaDevolucao;
  }

  return filaDevolucao;
}

// Busca a rota de um cliente específico na fila de rotas.
Rota *buscarRotaCliente(Rota *filaRota, Cliente *cliente)
{

  Rota *atual = filaRota;

  while (atual != NULL && atual->cliente != cliente)
  {
    atual = atual->prox;
  }

  return atual;
}

// adicionar uma nova encomenda à fila de rotas
Rota *adicionarEncomenda(Rota *filaRota, Cliente *cliente)
{

  Encomenda *novaEncomenda = criarEncomenda();

  Rota *rotaCliente = buscarRotaCliente(filaRota, cliente);

  // Se a rota já existir
  if (rotaCliente != NULL)
  {

    rotaCliente->encomendas = adicionarEncomendaCliente(rotaCliente->encomendas, &rotaCliente->quantidadeEncomendas, novaEncomenda);
  }
  else // Se o cliente não possui uma rota
  {
    filaRota = adicionarRota(filaRota, cliente, novaEncomenda);
  }

  return filaRota;
}

// Exibe todas as encomendas de um cliente.
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

// Remove a primeira rota da fila (FIFO – Primeiro a entrar, primeiro a sair).
Rota *removerRota(Rota *filaRota)
{
  if (filaRota != NULL)
  {
    Rota *atual = filaRota;

    filaRota = filaRota->prox;

    free(atual->encomendas);
    free(atual);
  }

  return filaRota;
}

// Percorre a lista de rotas e remove todas as rotas
Rota *liberarMemoriaRota(Rota *filaRota)
{
  while (filaRota != NULL)
  {
    filaRota = removerRota(filaRota);
  }

  return NULL;
}
