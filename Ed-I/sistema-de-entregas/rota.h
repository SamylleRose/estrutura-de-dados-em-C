#include "cliente.h"

typedef struct encomenda Encomenda;

struct encomenda
{
  int id;
  char descricao[100];
};

typedef struct rota Rota;

struct rota // Tipo de ambas as filas (entrega e devolucao)
{
  Cliente *cliente;         // Referência a um cliente
  Encomenda *encomendas;    // Vetor dinâmico de encomendas
  int quantidadeEncomendas; // Número de encomendas
  struct rota *prox;        // Próxima rota
};

Encomenda *criarEncomenda();
Encomenda *adicionarEncomendaCliente(Encomenda *encomendas, int *quantidadeEncomendas, Encomenda *novaEncomenda);
Rota *adicionarRota(Rota *filaRota, Cliente *cliente, Encomenda *novaEncomenda);
Rota *buscarRotaCliente(Rota *filaRota, Cliente *cliente);
Rota *adicionarEncomenda(Rota *filaRota, Cliente *cliente);
void mostrarEncomendas(Encomenda *encomendas, int quantidadeEncomendas);
void mostrarRota(Rota *filaRota);
