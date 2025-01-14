#include <stdio.h>
#include <stdlib.h>

#include "tentativa.h"

// adiciona na pilha tentativa
Tentativa *adicionarPilhaTentativas(Tentativa *pilhaTentativa, Rota *rota)
{
  Tentativa *novoTentativa = (Tentativa *)malloc(sizeof(Tentativa));

  if (novoTentativa == NULL)
  {
    printf("Erro ao alocar memória para o nó pilha tentativa.\n");
    return NULL;
  }

  novoTentativa->rota = rota;
  novoTentativa->tentativas = 1;
  novoTentativa->prox = pilhaTentativa; // Aponta para o antigo topo da pilha

  return novoTentativa; // Retorna o novo topo da pilha
}
// remove da pilha tentativa
Tentativa *removerPilhaTentativas(Tentativa *pilhaTentativas)
{
  if (pilhaTentativas == NULL)
  {
    printf("Pilha vazia! Não é possivel desempilhar. \n");
    return NULL;
  }

  Tentativa *temp = pilhaTentativas;
  pilhaTentativas = pilhaTentativas->prox;

  free(temp);

  return pilhaTentativas;
}

// mostra a pilha tentativa
void mostrarPilhatentativas(Tentativa *pilhaTentativa)
{
  if (pilhaTentativa == NULL)
  {
    printf("Erro: Pilha não inicializada.\n");
    return;
  }

  Tentativa *atual = pilhaTentativa;

  while (atual != NULL)
  {
    mostrarRota(atual->rota);
    atual = atual->prox;
  }

  printf("\n");
}
// libera memoria da pilha tentativas
Tentativa *liberarMemoriaTentativa(Tentativa *pilhaTentativa)
{
  while (pilhaTentativa != NULL)
  {
    Tentativa *atual = pilhaTentativa;

    pilhaTentativa = pilhaTentativa->prox;

    atual->rota = liberarMemoriaRota(atual->rota);

    free(atual);
  }

  return NULL;
}