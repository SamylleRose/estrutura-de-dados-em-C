#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fazenda.h"
#include "gerador_id.h"

typedef void (*FuncaoOperacao)(Fazenda *liFazenda, Animal *liAnimal);

Fazenda *criarFazenda()
{

  Fazenda *fazenda = (Fazenda *)malloc(sizeof(Fazenda));

  if (fazenda == NULL)
  {
    printf("Erro ao alocar memória para a fazenda.\n");
    exit(1);
  }

  fazenda = NULL;
  return fazenda;
}

void liberarFazenda(Fazenda *liFazenda)
{

  if (liFazenda == NULL)
  {
    printf("\nLista vazia!\n");
    return;
  }
  Fazenda *atual = liFazenda->next;
  Fazenda *proxima;

  while ((atual != liFazenda))
  {
    proxima = atual->next;
    free(atual);
    atual = proxima;
  }

  free(liFazenda);
}

Fazenda *inserirFazenda(Fazenda *liFazenda)
{
  Fazenda *novo = (Fazenda *)malloc(sizeof(Fazenda));

  if (novo == NULL)
  {
    printf("\nErro na alocação!\n");
    exit(1);
  }

  novo->id = gerarId();

  printf("\nInforme os dados da Fazenda:\n");

  printf("\nNome da fazenda: ");
  scanf("%s", novo->nome);

  printf("Localização: ");
  scanf("%s", novo->localizacao);

  novo->rebanho = NULL;
  novo->next = NULL;

  if (liFazenda == NULL)
  {

    novo->next = novo;
    // printf("Fazenda inserida: ID=%d, Nome=%s, Localização=%s\n", id, nome, localizacao);
    return novo;
  }

  Fazenda *atual = liFazenda;
  while (atual->next != liFazenda)
  {
    atual = atual->next;
  }
  // printf("Fazenda inserida: ID=%d, Nome=%s, Localização=%s\n", id, nome, localizacao);

  atual->next = novo;
  novo->next = liFazenda;

  printf("\nFazenda adicionada com sucesso!\n");

  return liFazenda;
}

void adicionarAnimal(Fazenda *fazenda, Animal *animal)
{
  if (fazenda == NULL || animal == NULL)
  {
    printf("\nFazenda ou animal inválida.\n");
  }

  if (fazenda->rebanho == NULL)
  {
    fazenda->rebanho = animal;
  }
  else
  {
    Animal *atual = fazenda->rebanho;

    while (atual->next != NULL)
    {
      atual = atual->next;
    }

    atual->next = animal;
  }
}

void mostrarFazenda(Fazenda *liFazenda)
{
  if (liFazenda == NULL)
  {
    printf("\nA lista de fazendas está vazia.\n");
    return;
  }

  Fazenda *atual = liFazenda;
  printf("\n-------------Fazendas--------------\n");
  do
  {
    printf("Fazenda ID: %d\n", atual->id);
    printf("Nome: %s\n", atual->nome);
    printf("Localizacao: %s\n\n", atual->localizacao);
    atual = atual->next;
  } while (atual != liFazenda);
}

void solicitarRealocacao(Fazenda *liFazenda)
{
  if (liFazenda == NULL)
  {
    printf("\nNão há fazendas cadastradas.\n");
    return;
  }

  int idOrigem, idDestino;
  printf("Digite o ID da fazenda origem da realocação: ");
  scanf("%d", &idOrigem);

  printf("Digite o ID da fazenda destino da realocação: ");
  scanf("%d", &idDestino);

  Fazenda *fazendaOrigem = NULL;
  Fazenda *fazendaDestino = NULL;

  Fazenda *atual = liFazenda;
  do
  {
    if (atual->id == idOrigem)
    {
      fazendaOrigem = atual;
    }
    if (atual->id == idDestino)
    {
      fazendaDestino = atual;
    }

    atual = atual->next;
  } while (atual != liFazenda && (fazendaOrigem == NULL || fazendaDestino == NULL));

  if (fazendaOrigem == NULL)
  {
    printf("Fazenda origem com ID %d não encontrada.\n", idOrigem);
  }
  if (fazendaDestino == NULL)
  {
    printf("Fazenda destino com ID %d não encontrada.\n", idDestino);
  }

  if (fazendaOrigem != NULL && fazendaDestino != NULL)
  {
    realocarAnimal(fazendaOrigem, fazendaDestino);
  }
}

void realocarAnimal(Fazenda *fazendaOrigem, Fazenda *fazendaDestino)
{
  if (fazendaOrigem == NULL || fazendaDestino == NULL)
  {
    printf("\nFazenda origem ou destino inválidas.\n");
    return;
  }

  if (fazendaOrigem->rebanho == NULL)
  {
    printf("A fazenda origem não possui animais para realocar.\n");
    return;
  }

  if (fazendaDestino->rebanho == NULL)
  {
    fazendaDestino->rebanho = fazendaOrigem->rebanho;
  }
  else
  {
    Animal *destAtual = fazendaDestino->rebanho;
    while (destAtual->next != NULL)
    {
      destAtual = destAtual->next;
    }
    destAtual->next = fazendaOrigem->rebanho;
  }

  fazendaOrigem->rebanho = NULL;
  printf("Animais realocados com sucesso.\n");
}

Fazenda *removerFazenda(Fazenda *liFazenda, int id)
{
  if (liFazenda == NULL)
  {
    printf("\nA lista de fazendas está vazia.\n");
    return NULL;
  }

  Fazenda *atual = liFazenda;
  Fazenda *anterior = NULL;

  do
  {
    if (atual->id == id)
    {
      if (anterior == NULL) // Caso especial: remover o nó inicial
      {
        if (atual->next == atual)
        {
          free(atual);
          printf("\nFazenda removida com sucesso. A lista está vazia.\n");
          return NULL; // lembre-se de verificar no main, se for null é vazia;
        }
        else
        {
          Fazenda *temp = atual;
          Fazenda *ultimo = atual;

          while (ultimo->next != liFazenda)
          {
            ultimo = ultimo->next;
          }

          liFazenda = atual->next;
          ultimo->next = liFazenda;
          free(temp);
          printf("\nFazenda removida com sucesso.\n");
          return liFazenda;
        }
      }
      else
      {
        anterior->next = atual->next;
        free(atual);
        printf("\nFazenda removida com sucesso.\n");
        return liFazenda;
      }
    }

    anterior = atual;
    atual = atual->next;
  } while (atual != liFazenda);

  printf("\nFazenda com ID %d não encontrada.\n", id);
  return liFazenda;
}

void menuFazenda(Fazenda *atual, Fazenda *lifazenda)
{

  while (1)
  {
    printf("\n--------Fazenda %s--------", atual->nome);

    printf("\n1- Adicionar animal\n");
    printf("2- Mostrar animais\n");
    printf("3- Atualizar Status\n");
    printf("4- Realocar animais\n");
    printf("5- Remover animais\n");
    printf("6- Voltar\n");

    int codigo;
    printf("\n\nDigite o codigo correspondente a sua escolha: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:

      float peso;
      char sexo;
      int novoId = gerarId();

      printf("\nInforme os dados do animal:\n");

      printf("\nPeso: ");
      scanf("%f", &peso);

      printf("\nSexo: (M/F) ");
      scanf("%s", &sexo);

      int status = menuStatus();

      Animal *novoAnimal = inserirAnimal(NULL, novoId, peso, sexo, status);
      adicionarAnimal(atual, novoAnimal);
      break;

    case 2:
      if (atual->rebanho == NULL)
      {
        printf("\nA fazenda não possui animais.\n");
      }
      else
      {
        mostrarAnimal(atual->rebanho);
      }

      break;

    case 3:

      if (atual->rebanho == NULL)
      {
        printf("\nA fazenda não possui animais.\n");
      }
      else
      {
        atualizarStatus(atual->rebanho);
      }

      break;

    case 4:

      solicitarRealocacao(lifazenda);
      break;

    case 5:

      if (atual->rebanho == NULL)
      {
        printf("\nA fazenda não possui animais.\n");
      }
      else
      {
        mostrarAnimal(atual->rebanho);
        atual->rebanho = removerAnimal(atual->rebanho);
      }

      break;

    case 6:
      return;

    default:
      printf("\nOpção inválida, tente novamente!\n");
      break;
    }
  }
}

void gerenciarFazendas(Fazenda *liFazendas)
{
  int id;

  while (1)
  {
    mostrarFazenda(liFazendas);

    printf("\nInforme o ID da fazenda que deseja acessar (ou -1 para voltar): ");
    scanf("%d", &id);

    if (id == -1)
    {
      printf("\nVoltando...\n");
      return; // Sai de gerenciarFazendas
    }

    Fazenda *atual = liFazendas;
    int fazendaEncontrada = 0;

    do
    {
      if (liFazendas->id == id)
      {
        fazendaEncontrada = 1;
        // Chama o menu da fazenda selecionada
        menuFazenda(atual, liFazendas);

        break;
      }

      atual = atual->next;
    } while (atual != liFazendas);

    if (!fazendaEncontrada)
    {
      printf("\nFazenda com ID %d não encontrada.\n", id);
    }
    // Continua o loop, mostrando fazendas novamente.
  }
}
