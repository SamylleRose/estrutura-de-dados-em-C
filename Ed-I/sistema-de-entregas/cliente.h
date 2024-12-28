typedef struct cliente Cliente;

struct cliente
{
  int id;
  char nome[100];
  char endereco[100];
  char telefone[13];
  Cliente *prox;
};

Cliente *iniciarListaCliente();
void liberaListaClientes(Cliente *listaCliente);
Cliente *adicionarNovoCliente(Cliente *listaClientes);
Cliente *buscarCliente(Cliente *listaClientes);
void mostrarLista(Cliente *listaClientes);
void atualizarDadosCliente(Cliente *listaClientes);
Cliente *removerClienteInativo(Cliente *listaClientes);
