#include "rota.h"

typedef struct tentativa Tentativa;

struct tentativa // pilha tentataivas
{
  Rota rota;
  int tentativas;
  struct tentativa *prox;
};
