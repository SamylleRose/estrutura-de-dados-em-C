#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tentativa.h"
#include "score.h"

Rota *moverParaPilhaTentativas(Rota *filaRota, Tentativa **pilhaTentativas);
void moverParaFilaDevolucoes(Tentativa **pilhaTentativas, Rota **filaRotaDevolucao);
Rota *menuEntregaAtual(Rota *filaRota, Tentativa **pilhaTentativas, Rota **filaRotaDevolucao, Score **score);
Rota *menuRota(Rota *filaRota, Cliente *listaClientes, Tentativa **pilhaTentativas, Rota **filaRotaDevolucao, Score **score);
int fila_vazia(Rota *filaRota);

int main()
{
  srand((unsigned)time(NULL));

  Cliente *listaClientes = NULL; // atribuir null e remover a função
  Rota *filaRotaEntrega = NULL;
  Rota *filaRotaDevolucao = NULL;
  Tentativa *pilhaTentativas = NULL;
  Score *score = criarScore();

  int codigo;

  while (1)
  {
    printf("\n\n============= Sistema de Entregas =============\n");
    printf("1 - Clientes\n");
    printf("2 - Entregas\n");
    printf("3 - Devoluções\n");
    printf("4 - Score\n");
    printf("5 - sair\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:
      listaClientes = menuOpcoesCliente(listaClientes);
      break;

    case 2:

      if (listaClientes == NULL)
      {
        printf("O sistema não possui clientes, adicione um cliente.");
        break;
      }

      filaRotaEntrega = menuRota(filaRotaEntrega, listaClientes, &pilhaTentativas, &filaRotaDevolucao, &score);
      break;
    case 3:
      if (filaRotaDevolucao == NULL)
      {
        printf("\nO sistema não possui devoluções.");
        break;
      }
      printf("\nDevoluções: \n\n");
      mostrarRota(filaRotaDevolucao);
      break;
    case 4:
      mostrarScore(score);
      break;

    case 5:
      return 1;
      break;

    default:
      break;
    }
  }

  filaRotaEntrega = liberarMemoriaRota(filaRotaEntrega);
  filaRotaDevolucao = liberarMemoriaRota(filaRotaDevolucao);
  pilhaTentativas = liberarMemoriaTentativa(pilhaTentativas);
  score = liberarMemoriaScore(score);

  return 0;
}

Rota *moverParaPilhaTentativas(Rota *filaRota, Tentativa **pilhaTentativas)
{
  *pilhaTentativas = adicionarPilhaTentativas(*pilhaTentativas, filaRota);
  filaRota = filaRota->prox;

  printf("\nNumero de tentativas da encomenda atual %d\n", (*pilhaTentativas)->tentativas);

  printf("\nMovido para a pilha de tentativas\n");

  return filaRota;
}

void incrementarTentativas(Tentativa **pilhaTentativas, Rota **filaRotaDevolucao)
{
  int MAXIMO_TENTATIVAS = 2;

  (*pilhaTentativas)->tentativas += 1;

  printf("\nNumero de tentativas da encomenda atual %d\n", (*pilhaTentativas)->tentativas);

  if ((*pilhaTentativas)->tentativas >= MAXIMO_TENTATIVAS)
  {
    *filaRotaDevolucao = adicionarDevolucao(*filaRotaDevolucao, (*pilhaTentativas)->rota);

    *pilhaTentativas = (*pilhaTentativas)->prox;

    printf("\nMovido para as devolucoes\n");
  }
}
// menu para as opções de entrega, se foi entregue ou não
Rota *menuEntregaAtual(Rota *filaRota, Tentativa **pilhaTentativas, Rota **filaRotaDevolucao, Score **score)
{
  int codigo;

  while (1)
  {
    Rota *atual = filaRota;

    if (atual == NULL && (*pilhaTentativas) != NULL)
    {
      atual = (*pilhaTentativas)->rota;
    }

    printf("\n\n============= Entrega Atual =============\n");

    if (atual == NULL)
    {
      printf("Voce entregou todas as encomendas, parabéns!\n\n");
      return filaRota;
    }
    else
    {
      printf("Teste\n");
    }

    printf("\nEncomendas do(a) cliente %s:\n", atual->cliente->nome);
    mostrarEncomendas(atual->encomendas, atual->quantidadeEncomendas);
    printf("1 - Entregua efetuada\n");
    printf("2 - Tentativa de entregue feita mas sem sucesso\n");
    printf("3 - Voltar\n");

    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:
      if (filaRota != NULL)
      {
        filaRota = removerRota(filaRota);
        *score = entregueNaPrimeiraTentativa(*score);
        mostrarScore(*score);
      }
      else
      {
        *pilhaTentativas = removerPilhaTentativas(*pilhaTentativas);
        *score = entregueNaSegundaTentativa(*score);
        mostrarScore(*score);
      }

      break;

    case 2:
      if (filaRota != NULL)
      {
        filaRota = moverParaPilhaTentativas(filaRota, pilhaTentativas);
      }
      else
      {
        incrementarTentativas(pilhaTentativas, filaRotaDevolucao);
        *score = devolvida(*score);
        mostrarScore(*score);
      }

      break;

    default:
      return filaRota;
    }
  }
}
// verifica se a fila está vazia
int fila_vazia(Rota *filaRota)
{
  return filaRota == NULL;
}

// menu utilizado para executar as funcionalidades de rota
Rota *menuRota(Rota *filaRota, Cliente *listaClientes, Tentativa **pilhaTentativas, Rota **filaRotaDevolucao, Score **score)
{
  int codigo;

  while (1)
  {
    printf("\n\n============= Rotas de Entregas =============\n");
    printf("1 - Adicionar Encomendas\n");
    printf("2 - Mostrar Rotas Encomendas\n");
    printf("3 - Entrega atual\n");
    printf("4 -  Voltar\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:

      mostrarListaCliente(listaClientes);
      Cliente *clienteEncomenda = buscarClientePorId(listaClientes);

      if (clienteEncomenda != NULL)
      {

        filaRota = adicionarEncomenda(filaRota, clienteEncomenda);
      }

      break;

    case 2:
      if (fila_vazia(filaRota))
      {
        printf("Erro: Não possui rotas cadastradas!\n");
        break;
      }
      mostrarRota(filaRota);
      break;

    case 3:

      if (fila_vazia(filaRota))
      {
        printf("Erro: Não possui rotas cadastradas!\n");
        break;
      }
      filaRota = menuEntregaAtual(filaRota, pilhaTentativas, filaRotaDevolucao, score);
      break;

    case 4:

      return filaRota;
      break;

    default:

      printf("Opção invalida, tente novamente!");
      break;
    }
  }
}