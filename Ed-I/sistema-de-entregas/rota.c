#include <stdio.h>
#include <stdio.h>
#include "rota.h"

Encomenda *criarEncomenda() // acho que não funciona
{

  Encomenda *novaEncomenda = (Encomenda *)malloc(sizeof(Encomenda));

  if (novaEncomenda == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return NULL;
  }

  return novaEncomenda;
}

Rota *buscarRotaCliente(Rota *filaEntrega, Cliente *cliente)
{
  Rota *atual = filaEntrega;

  while (atual != NULL || atual->cliente != cliente) // acredito que sejá melhor &&, Caso contrário, mesmo que atual seja NULL.
  {
    atual = atual->prox;
  }

  return atual;
}

Rota *inserirEntrega(Rota *filaEntrega, Cliente *cliente)
{
  // Checar se já há uma encomenda para o cliente passado como parametro.
  // Se sim, adicionar a encomenda, se não, criar um novo nó Rota e adicionar no fim da fila.
  //
  Rota *rotaCliente = buscarRotaCliente(filaEntrega, cliente);

  if (rotaCliente != NULL)
  {
    // Cria uma nova encomenda
    // Adiciono nessa rota
    Encomenda *novaEncomenda = criarEncomenda();

    rotaCliente->encomendas = adicionarEncomenda(rotaCliente->encomendas, novaEncomenda);
  }
  else
  {
  }
}
