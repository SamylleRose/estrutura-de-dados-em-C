#include <stdio.h>
#include <stdlib.h>

#include "rota.h"

int main()
{
  Cliente *listaClientes = iniciarListaCliente();

  // menuOpcoesCliente(listaClientes);

  // liberaListaClientes(listaClientes);

  listaClientes = adicionarNovoCliente(listaClientes);
  listaClientes = adicionarNovoCliente(listaClientes);

  Rota *filaRotaEntrega = NULL;

  filaRotaEntrega = adicionarEncomenda(filaRotaEntrega, listaClientes);
  filaRotaEntrega = adicionarEncomenda(filaRotaEntrega, listaClientes);
  filaRotaEntrega = adicionarEncomenda(filaRotaEntrega, listaClientes->prox);
  filaRotaEntrega = adicionarEncomenda(filaRotaEntrega, listaClientes);
  mostrarRota(filaRotaEntrega);

  return 0;
}
