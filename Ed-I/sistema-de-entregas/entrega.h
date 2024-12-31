#include "cliente.h"
#include <stdlib.h>

typedef struct Entrega
{
  int id;
  int id_cliente;
  char endereco[100];
} Entrega;

typedef struct RotaEntrega
{
  Cliente *cliente;         // Referência a um cliente
  Entrega *entregas;        // Vetor dinâmico de entregas
  int quantidade;           // Número de entregas
  struct RotaEntrega *prox; // Próxima rota
} RotaEntrega;
