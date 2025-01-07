#include "rota.h"

typedef struct tentativa Tentativa;

struct tentativa // pilha tentataivas
{
  Rota *rota;
  int tentativas;
  struct tentativa *prox;
};

Tentativa *adicionarPilhaTentativas(Tentativa *pilhaTentativa, Rota *rota);
Tentativa *removerPilhaTentativas(Tentativa *pilhaTentativas);
void mostrarPilhatentativas(Tentativa *pilhaTentativa);
