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

Fazenda *removerFazenda(Fazenda *liFazenda, int id) // remove a fazenda
{

  Fazenda *atual = liFazenda;
  Fazenda *anterior = NULL;

  do
  {
    if (atual->id == id) // se o id for encontrado
    {

      // Antes de remover, verifica se há animais e pergunta sobre realocação
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

      if (anterior == NULL) // caso especial: remover o nó inicial
      {
        if (atual->next == atual) // caso a lista tiver apenas um elemento
        {
          free(atual);
          printf("\nFazenda removida com sucesso. A lista está vazia.\n");
          return NULL;
        }
        else // lista com mais de um elemento
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
      else // remover um nó no meio ou fim da lista
      {
        anterior->next = atual->next;
        free(atual);
        printf("\nFazenda removida com sucesso.\n");
        return liFazenda;
      }
    }

    anterior = atual; // continua o laço
    atual = atual->next;
  } while (atual != liFazenda);

  printf("\nFazenda com ID %d não encontrada.\n", id); // fazenda não foi encontrada
  return liFazenda;
}

void solicitarRealocacao(Fazenda *liFazenda)
{
  if (liFazenda->rebanho == NULL)
  {
    printf("\nA Fazenda não possui animais\n");
    return;
  }

  int idOrigem, idDestino;
  printf("Digite o ID da fazenda origem da realocação: ");
  idOrigem = obterInteiro();

  printf("Digite o ID da fazenda destino da realocação: ");
  idDestino = obterInteiro();

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
  }
  if (fazendaDestino == NULL) // caso o id origem não seja encontrado
  {
    printf("Fazenda destino com ID %d não encontrada.\n", idDestino);
  }

  if (fazendaOrigem != NULL && fazendaDestino != NULL) // caso o id origem não seja encontrado
  {
    realocarAnimal(fazendaOrigem, fazendaDestino);
  }
}

void menuFazenda(Fazenda *atual, Fazenda *liFazenda) // menu para acessar as opções de fazenda
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
    codigo = obterInteiro();

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
      mostrarFazenda(liFazenda);
      solicitarRealocacao(liFazenda);
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
      return; // sai do menu fazenda

    default:
      printf("\nOpção inválida, tente novamente!\n");
      break;
    }
  }
}

// recebe o id da fazenda que deseja acessar e chama a função menuFazenda
void gerenciarFazendas(Fazenda *liFazendas)
{
  int id;

  while (1)
  {
    mostrarFazenda(liFazendas);

    printf("\nInforme o ID da fazenda que deseja acessar (ou -1 para voltar): ");
    id = obterInteiro();

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
