typedef struct cliente Cliente;

struct cliente
{
  int id;
  char nome[100];
  char endereco[100];
  char telefone[19];
  Cliente *prox;
};

Cliente *iniciarListaCliente();
void liberaListaClientes(Cliente *listaCliente);
Cliente *adicionarNovoCliente(Cliente *listaClientes);
Cliente *buscarClientePorId(Cliente *listaClientes);
void buscarClientesPeloEndereco(Cliente *listaClientes);
void mostrarLista(Cliente *listaClientes);
void atualizarDadosCliente(Cliente *listaClientes);
Cliente *removerClienteInativo(Cliente *listaClientes);

int validarEntrada(const char *entrada, const char *tipo);
void menuOpcoesCliente(Cliente *listaClientes);
void menuBuscar(Cliente *listaClientes);
