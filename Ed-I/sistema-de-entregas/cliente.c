#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

// função para inicializar a lista
Cliente *iniciarListaCliente()
{
  return NULL;
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

  printf("Informe o nome do cliente: ");
  scanf("%s", novo->nome);

  printf("Informe o endereço do cliente: ");
  scanf("%s", novo->endereco);

  printf("Informe o telefone do cliente: ");
  scanf("%s", novo->telefone);

  novo->prox = listaClientes;
  return novo;
}

// função para buscar cliente por ID ou endereço
Cliente *buscarCliente(Cliente *listaClientes)
{
  if (listaClientes == NULL)
  {
    printf("\n\nO sistema não possui clientes.\n\n");
    return NULL;
  }

  char idEndereco[100];
  printf("\nInsira o ID ou endereço do cliente: ");
  scanf("%s", idEndereco);

  Cliente *atual = listaClientes;

  char idStr[20];                  // Buffer para armazenar o ID como string
  sprintf(idStr, "%d", atual->id); // Converte o ID (int) para string

  while (atual != NULL)
  {
    if ((strcmp(idStr, idEndereco) == 0) || (strcmp(atual->endereco, idEndereco) == 0))
    {
      printf("Cliente encontrado:\n\n");
      printf("ID: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n", atual->id, atual->nome, atual->endereco, atual->telefone);

      return atual;
    }
    atual = atual->prox;
  }
  // caso não seja encontrado
  printf("\n\nID ou endereço não encontrado, tente novamente!\n\n");
  return NULL;
}

void mostrarLista(Cliente *listaClientes)
{
  if (listaClientes == NULL)
  {
    printf("\n\nLista vazia!\n\n");
    exit(1);
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
  Cliente *clienteAtualizar = buscarCliente(listaClientes);
  if (clienteAtualizar != NULL)
  {
    printf("Informe o novo nome do cliente: ");
    scanf("%s", clienteAtualizar->nome);

    printf("Informe o endereço do cliente: ");
    scanf("%s", clienteAtualizar->endereco);

    printf("Informe o telefone do cliente: ");
    scanf("%s", clienteAtualizar->telefone);

    printf("\n\nCliente atualizado com sucesso!\n\n");
  }
}
// função para remover cliente
Cliente *removerClienteInativo(Cliente *listaClientes)
{
  Cliente *clienteRemover = buscarCliente(listaClientes);
  if (clienteRemover == NULL)
  {
    return listaClientes;
  }

  if (clienteRemover == listaClientes)
  {
    listaClientes = clienteRemover->prox;
  }
  else
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
