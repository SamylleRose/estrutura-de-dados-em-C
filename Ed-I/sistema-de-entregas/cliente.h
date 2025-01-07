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
Cliente *adicionarNovoCliente(Cliente *listaClientes);
Cliente *buscarClientePorId(Cliente *listaClientes);
Cliente *removerClienteInativo(Cliente *listaClientes);
void liberaListaClientes(Cliente *listaCliente);
void buscarClientesPeloEndereco(Cliente *listaClientes);
void mostrarListaCliente(Cliente *listaClientes);
Cliente *atualizarDadosCliente(Cliente *listaClientes);

int validarEntrada(const char *entrada, const char *tipo);
Cliente *menuOpcoesCliente(Cliente *listaClientes);
void menuBuscar(Cliente *listaClientes);
int gerarId();
