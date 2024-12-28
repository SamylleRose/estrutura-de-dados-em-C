#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

int main()
{

  Cliente *listaClientes = iniciarListaCliente();

  while (1)
  {
    listaClientes = adicionarNovoCliente(listaClientes);
    mostrarLista(listaClientes);

    atualizarDadosCliente(listaClientes);
    mostrarLista(listaClientes);

    listaClientes = removerClienteInativo(listaClientes);
    mostrarLista(listaClientes);
  }

  liberaListaClientes(listaClientes);

  return 0;
}
