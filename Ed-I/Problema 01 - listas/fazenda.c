#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fazenda.h"
#include "global.h"

void liberarFazenda(Fazenda *liFazenda) // libera a lista de fazenda
{

  if (liFazenda == NULL)
  {
    printf("\nLista vazia!\n");
    return;
  }

  Fazenda *inicio = liFazenda;
  Fazenda *atual = liFazenda->next;
  Fazenda *aux;

  while ((atual != inicio))
  {
    liberarAnimal(atual->rebanho); // libera ab lista de animais da fazenda
    aux = atual;
    atual = atual->next;
    free(aux);
  }

  liberarAnimal(inicio->rebanho); // libera a primeira fazenda
  free(inicio);
}

Fazenda *inserirFazenda(Fazenda *liFazenda) // insere uma fazenda a um criador
{
  Fazenda *novo = (Fazenda *)malloc(sizeof(Fazenda));

  if (novo == NULL)
  {
    printf("\nErro na alocação!\n");
    exit(1);
  }

  novo->id = gerarId(); // usa a função que cria um ID aleatorio

  printf("\nInforme os dados da Fazenda:\n");

  printf("\nNome da fazenda: ");
  scanf("%s", novo->nome);

  printf("Localização: ");
  scanf("%s", novo->localizacao);

  novo->rebanho = NULL;
  novo->next = NULL;

  if (liFazenda == NULL) // se a lista estiver vazia
  {

    novo->next = novo; // aponta para si mesmo (lista circular)
    return novo;
  }

  Fazenda *atual = liFazenda; // se a lista já possuir fazendas
  while (atual->next != liFazenda)
  {
    atual = atual->next; // percorre até o ultimo elemento
  }

  atual->next = novo;
  novo->next = liFazenda;

  printf("\nFazenda adicionada com sucesso!\n");

  return liFazenda;
}

void adicionarAnimal(Fazenda *fazenda, Animal *animal) // adiciona um animal a uma fazenda
{
  if (fazenda == NULL || animal == NULL) // verifica se a fazenda e animal passados como parametros são válidos
  {
    printf("\nFazenda ou animal inválida.\n");
  }

  if (fazenda->rebanho == NULL) // se a lista estiver vazia
  {
    fazenda->rebanho = animal; // aponta para si mesmo (lista circular)
  }
  else
  {

    Animal *atual = fazenda->rebanho; // se a lista já possuir fazendas
    while (atual->next != NULL)
    {
      atual = atual->next; // percorre até o ultimo elemento
    }

    atual->next = animal;
  }
}

void mostrarFazenda(Fazenda *liFazenda) // mostra a lista de fazendas
{

  Fazenda *atual = liFazenda;
  printf("\n-------------Fazendas--------------\n");

  if (atual == NULL)
    return;

  do
  {
    printf("Fazenda ID: %d\n", atual->id);
    printf("Nome: %s\n", atual->nome);
    printf("Localizacao: %s\n\n", atual->localizacao);
    atual = atual->next;
  } while (atual != liFazenda);
}

void realocarAnimal(Fazenda *fazendaOrigem, Fazenda *fazendaDestino) // faz a realocação dos animais
{

  if (fazendaOrigem->rebanho == NULL) // verifica se possui animais
  {
    printf("A fazenda origem não possui animais para realocar.\n");
    return;
  }

  if (fazendaDestino->rebanho == NULL)
  {
    fazendaDestino->rebanho = fazendaOrigem->rebanho; // caso o destino não tenha animais
  }
  else // caso a fazenda destino tenha animais
  {
    Animal *destAtual = fazendaDestino->rebanho;
    while (destAtual->next != NULL)
    {
      destAtual = destAtual->next;
    }
    destAtual->next = fazendaOrigem->rebanho; // será inserido no final da lista
  }

  fazendaOrigem->rebanho = NULL;
  printf("Animais realocados com sucesso.\n");
}

Fazenda *removerFazenda(Fazenda *liFazenda) // remove a fazenda
{
  Fazenda *anterior = NULL;
  Fazenda *atual = liFazenda;

  int id;

  printf("\n\nDigite o id correspondente a fazenda que deseja remover: ");
  scanf("%d", &id);

  do
  {
    if (atual->id == id) // se o id for encontrado
    {
      if (atual->rebanho != NULL)
      {
        char opcao;
        printf("\nA fazenda possui animais. Deseja realocar para outra fazenda? (S/N): ");
        scanf(" %c", &opcao);

        if (opcao == 'S' || opcao == 's')
        {
          solicitarRealocacao(liFazenda);
        }
      }

      if (atual->next == atual) // lista com apenas um elemento
      {
        free(atual);
        printf("\nFazenda removida com sucesso. A lista está vazia.\n");
        return NULL;
      }
      else
      {
        Fazenda *aux = atual->next;
        if (anterior == NULL) // Remover o primeiro elemento
        {
          while (aux->next != liFazenda)
          {
            aux = aux->next;
          }
          liFazenda = atual->next;
        }
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

void solicitarRealocacao(Fazenda *liFazenda)
{
  // if (liFazenda->rebanho == NULL)
  // {
  //   printf("\nA Fazenda não possui animais\n");
  //   return;
  // }

  int idOrigem, idDestino;

  printf("\n\nDigite o ID da fazenda origem da realocação: ");
  scanf("%d", &idOrigem);

  printf("\n\nDigite o ID da fazenda destino da realocação: ");
  scanf("%d", &idDestino);

  Fazenda *fazendaOrigem = NULL;
  Fazenda *fazendaDestino = NULL;

  Fazenda *atual = liFazenda;
  do // encontra o id correspondente
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

  if (fazendaOrigem == NULL) // caso o id origem não seja encontrado
  {
    printf("Fazenda origem com ID %d não encontrada.\n", idOrigem);
    return;
  }
  if (fazendaDestino == NULL) // caso o id origem não seja encontrado
  {
    printf("Fazenda destino com ID %d não encontrada.\n", idDestino);
    return;
  }

  if (fazendaOrigem != NULL && fazendaDestino != NULL) // caso o id origem não seja encontrado
  {
    realocarAnimal(fazendaOrigem, fazendaDestino);
  }
}

Fazenda *menuFazenda(Fazenda *atual) // menu para acessar as opções de fazenda
{

  while (1)
  {
    if (atual == NULL)
      return NULL;

    printf("\n--------Fazenda %s--------", atual->nome);

    printf("\n1- Adicionar animal\n");
    printf("2- Mostrar animais\n");
    printf("3- Atualizar Status\n");
    printf("4- Realocar animais\n");
    printf("5- Remover animal\n");
    printf("6- Remover Fazenda\n");
    printf("7- Voltar\n");

    int codigo;
    printf("\n\nDigite o codigo correspondente a sua escolha: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:

      Animal *novoAnimal = inserirAnimal(NULL);
      adicionarAnimal(atual, novoAnimal);

      break;

    case 2:
      if (atual->rebanho == NULL) // verifica se possui animais
      {
        printf("\nA fazenda não possui animais.\n");
      }
      else
      {
        mostrarAnimal(atual->rebanho);
      }

      break;

    case 3:

      if (atual->rebanho == NULL) // verifica se possui animais
      {
        printf("\nA fazenda não possui animais.\n");
      }
      else
      {
        atualizarStatus(atual->rebanho);
      }

      break;

    case 4:

      if (atual->rebanho == NULL) // verifica se possui animais
      {
        printf("\nA fazenda não possui animais.\n");
      }
      else
      {
        mostrarFazenda(atual);
        solicitarRealocacao(atual);
      }

      break;

    case 5:

      if (atual->rebanho == NULL) // verifica se possui animais
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

      mostrarFazenda(atual);
      atual = removerFazenda(atual);

      break;

    case 7:
      return atual; // sai do menu fazenda

    default:
      printf("\nOpção inválida, tente novamente!\n");
      break;
    }
  }

  return atual;
}

// recebe o id da fazenda que deseja acessar e chama a função menuFazenda
Fazenda *gerenciarFazendas(Fazenda *liFazendas)
{
  int id;

  mostrarFazenda(liFazendas);

  printf("\n\nInforme o ID da fazenda que deseja acessar (ou -1 para voltar): ");
  scanf("%d", &id);

  if (id == -1)
  {
    printf("\nVoltando...\n");
    return liFazendas; // Sai de gerenciarFazendas
  }

  Fazenda *atual = liFazendas;
  int fazendaEncontrada = 0;

  do
  {
    if (atual->id == id)
    {
      fazendaEncontrada = 1;
      // Chama o menu da fazenda selecionada
      atual = menuFazenda(atual);

      break;
    }

    atual = atual->next;
  } while (atual != liFazendas);

  if (!fazendaEncontrada)
  {
    printf("\nFazenda com ID %d não encontrada.\n", id);
  }
  // Continua o loop, mostrando fazendas novamente.

  return atual;
}
