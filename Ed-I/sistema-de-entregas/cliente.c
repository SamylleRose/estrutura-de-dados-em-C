#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

#include "cliente.h"

// função para inicializar a lista
Cliente *iniciarListaCliente()
{
  return NULL;
}

// função para liberar memoria da lista de clientes
void liberaListaClientes(Cliente *listaCliente)
{
  Cliente *aux;
  while (listaCliente != NULL)
  {
    aux = listaCliente;
    listaCliente = listaCliente->prox;
    free(aux);
  }
}

// função para adicionar um novo cliente
Cliente *adicionarNovoCliente(Cliente *listaClientes)
{
  Cliente *novo = (Cliente *)malloc(sizeof(Cliente));

  if (novo == NULL)
  {
    printf("\n\nErro na alocação de memória.\n\n");
    exit(1);
  }

  novo->id = 1;

  // Validação para nome
  do
  {
    printf("Informe o nome do cliente: ");
    // Evita estouro de buffer
    scanf(" %99[^\n]", novo->nome);
  } while (!validarEntrada(novo->nome, "nome"));

  // Validação para endereço
  do
  {
    printf("Informe o endereço do cliente: ");
    scanf(" %99[^\n]", novo->endereco);
  } while (!validarEntrada(novo->endereco, "endereco"));

  // Validação para telefone
  do
  {
    printf("Informe o telefone do cliente: ");
    scanf(" %19s", novo->telefone); // Limita o telefone a 19 caracteres
  } while (!validarEntrada(novo->telefone, "telefone"));

  novo->prox = listaClientes;
  return novo;
}

// função para buscar cliente por ID
Cliente *buscarClientePorId(Cliente *listaClientes)
{
  if (listaClientes == NULL)
  {
    printf("\n\nO sistema não possui clientes.\n\n");
    return NULL;
  }

  char idParaProcurar[100];
  printf("\nInsira o ID do cliente: ");
  scanf(" %99[^\n]", idParaProcurar);

  Cliente *atual = listaClientes;

  char idStr[20];                  // Buffer para armazenar o ID como string
  sprintf(idStr, "%d", atual->id); // Converte o ID (int) para string

  while (atual != NULL)
  { // caso o id ou endereço for encontrado
    if ((strcmp(idStr, idParaProcurar) == 0))
    {
      printf("\n\nID: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n\n", atual->id, atual->nome, atual->endereco, atual->telefone);

      return atual;
    }
    atual = atual->prox;
  }
  // caso não seja encontrado
  printf("\n\nID não encontrado, tente novamente!\n\n");
  return NULL;
}

// função para buscar cliente por endereço
void buscarClientesPeloEndereco(Cliente *listaClientes)
{
  if (listaClientes == NULL)
  {
    printf("\n\nO sistema não possui clientes.\n\n");
    return;
  }

  char enderecoParaProcurar[100];
  int encontrado = 0;
  printf("\nInsira o endereço do cliente: ");
  scanf(" %99[^\n]", enderecoParaProcurar);

  Cliente *atual = listaClientes;

  char idStr[20];                  // Buffer para armazenar o ID como string
  sprintf(idStr, "%d", atual->id); // Converte o ID (int) para string

  while (atual != NULL)
  { // caso o id ou endereço for encontrado
    if ((strcmp(atual->endereco, enderecoParaProcurar) == 0))
    {
      encontrado = 1;
      printf("\n\nID: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n\n", atual->id, atual->nome, atual->endereco, atual->telefone);
    }
    atual = atual->prox;
  }

  // caso não seja encontrado
  if (encontrado == 0)
  {
    printf("\n\nID ou endereço não encontrado, tente novamente!\n\n");
  }
}

// Mostrar todos os clientes da lista
void mostrarLista(Cliente *listaClientes)
{
  if (listaClientes == NULL)
  {
    printf("\n\nLista vazia!\n\n");
    return;
  }
  Cliente *aux = listaClientes;
  while (aux != NULL)
  {
    printf("ID: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n", aux->id, aux->nome, aux->endereco, aux->telefone);
    aux = aux->prox;
  }
}

// função para atualizar dados do cliente
void atualizarDadosCliente(Cliente *listaClientes)
{
  Cliente *clienteAtualizar = buscarClientePorId(listaClientes);

  if (clienteAtualizar != NULL)
  {
    // Validação para nome
    do
    {
      printf("Informe o novo nome do cliente: ");
      scanf(" %99[^\n]", clienteAtualizar->nome);
    } while (!validarEntrada(clienteAtualizar->nome, "nome"));

    // Validação para endereço
    do
    {
      printf("Informe o novo endereço do cliente: ");
      scanf(" %99[^\n]", clienteAtualizar->endereco);
    } while (!validarEntrada(clienteAtualizar->endereco, "endereco"));

    // Validação para telefone
    do
    {
      printf("Informe o novo telefone do cliente: ");
      scanf(" %19s", clienteAtualizar->telefone);
    } while (!validarEntrada(clienteAtualizar->telefone, "telefone"));

    printf("\n\nCliente atualizado com sucesso!\n\n");
  }
}

// função para remover cliente
Cliente *removerClienteInativo(Cliente *listaClientes)
{
  Cliente *clienteRemover = buscarClientePorId(listaClientes);
  if (clienteRemover == NULL)
  {
    return listaClientes;
  }
  // remove se caso seja o primeiro da lista
  if (clienteRemover == listaClientes)
  {
    listaClientes = clienteRemover->prox;
  }
  else // removoção de cliente do meio ou fim da lista
  {
    Cliente *anterior = listaClientes;
    while (anterior->prox != clienteRemover)
    {
      anterior = anterior->prox;
    }
    anterior->prox = clienteRemover->prox;
  }

  free(clienteRemover);
  printf("\n\nCliente removido com sucesso!\n");
  return listaClientes;
}

// função que faz a validação das entradas
int validarEntrada(const char *entrada, const char *tipo)
{
  int i = 0;

  if (strcmp(tipo, "telefone") == 0)
  {
    while (entrada[i] != '\0')
    {
      if (!isdigit(entrada[i]))
      {
        printf("\nErro: O telefone deve conter apenas números.\n");
        return 0;
      }
      i++;
    }
  }
  else if (strcmp(tipo, "nome") == 0)
  {
    while (entrada[i] != '\0')
    {
      if (!isalpha(entrada[i]) && entrada[i] != ' ')
      {
        printf("\nErro: O nome deve conter apenas letras e espaços.\n");
        return 0;
      }
      i++;
    }
  }
  else if (strcmp(tipo, "endereco") == 0)
  {
    while (entrada[i] != '\0')
    {
      if (!isalnum(entrada[i]) && entrada[i] != ' ')
      {
        printf("\nErro: O endereço deve conter apenas letras, números e espaços.\n");
        return 0;
      }
      i++;
    }
  }

  return 1;
}

void menuOpcoesCliente(Cliente *listaClientes)
{

  int codigo;

  while (1)
  {
    printf("\n\n---------- Menu Cliente ----------\n");
    printf("1 - Adicionar cliente\n");
    printf("2 - Buscar cliente\n");
    printf("3 - Mostrar todos os cliente\n");
    printf("4 - Atualizar cliente\n");
    printf("5 - Remover cliente\n\n");

    printf("Digite um codigo: ");
    scanf("%d", &codigo);

    switch (codigo)
    {

    case 1:
      listaClientes = adicionarNovoCliente(listaClientes);
      break;

    case 2:
      menuBuscar(listaClientes);

      break;
    case 3:
      mostrarLista(listaClientes);
      break;

    case 4:
      atualizarDadosCliente(listaClientes);
      break;

    case 5:
      listaClientes = removerClienteInativo(listaClientes);

      break;

    case 6:
      printf("Saindo...");
      return;
      break;

    default:
      printf("Valor inválido, tente novamente!");

      break;
    }
  }
}

void menuBuscar(Cliente *listaClientes)
{
  int codigo;

  while (1)
  {
    printf("\n\n---------- Buscar Clientes ----------\n");
    printf("1 - Buscar por ID\n");
    printf("2 - Buscar por endereço\n");
    printf("3 - Voltar\n\n");

    printf("Digite um codigo: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:
      buscarClientePorId(listaClientes);
      break;

    case 2:
      buscarClientesPeloEndereco(listaClientes);
      break;

    case 3:
      return;
      break;

    default:
      printf("Valor incorreto, tente novamente!");

      break;
    }
  }
}