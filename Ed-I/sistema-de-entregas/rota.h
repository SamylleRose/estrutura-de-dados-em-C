#include "cliente.h"

typedef struct encomenda Encomenda;

struct encomenda
{
  int id;
  char description[100];
};

typedef struct rota Rota;

struct rota // Tipo de ambas as filas (entrega e devolucao)
{
  Cliente *cliente;        // Referência a um cliente
  Encomenda *encomendas;   // Vetor dinâmico de encomendas
  int quantidadeEncomenda; // Número de encomendas
  struct rota *prox;       // Próxima rota
};

Rota *inserirEntrega(Rota *filaEntrega, Cliente *cliente);
