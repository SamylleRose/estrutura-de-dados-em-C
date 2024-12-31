#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

int main()
{

  Cliente *listaClientes = iniciarListaCliente();

  menuOpcoesCliente(listaClientes);

  liberaListaClientes(listaClientes);

  return 0;
}
