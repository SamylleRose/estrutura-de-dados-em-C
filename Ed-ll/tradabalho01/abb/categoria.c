#include <stdlib.h>
#include <string.h>
#include "categoria.h"

Categoria *inserirCategoriaNaLista(Categoria *inicioLista, char nome[], char tipo[])
{
  Categoria *novaCategoria = (Categoria *)malloc(sizeof(Categoria));
  strcpy(novaCategoria->nome, nome);
  strcpy(novaCategoria->tipo, tipo);
  novaCategoria->arvoreProgramas = NULL;

  if (inicioLista == NULL)
  {
    novaCategoria->proxima = novaCategoria;
    printf("Categoria '%s' cadastrada com sucesso!\n", nome);
    return novaCategoria;
  }

  Categoria *atual = inicioLista;
  while (atual->proxima != inicioLista)
  {
    if (strcmp(atual->nome, nome) == 0)
    {
      printf("Categoria '%s' já existe na lista. Cadastro ignorado.\n", nome);
      free(novaCategoria);
      return inicioLista;
    }
    atual = atual->proxima;
  }

  if (strcmp(atual->nome, nome) == 0)
  {
    printf("Categoria '%s' já existe na lista. Cadastro ignorado.\n", nome);
    free(novaCategoria);
    return inicioLista;
  }

  atual->proxima = novaCategoria;
  novaCategoria->proxima = inicioLista;

  printf("Categoria '%s' cadastrada com sucesso!\n", nome);
  return inicioLista;
}

void mostrarCategorias(Categoria *inicioLista)
{
  if (inicioLista == NULL)
  {
    printf("Nenhuma categoria cadastrada.\n");
    return;
  }

  Categoria *atual = inicioLista;
  do
  {
    printf("Nome: %s, Tipo: %s\n", atual->nome, atual->tipo);
    atual = atual->proxima;
  } while (atual != inicioLista);
}

Categoria *removerCategoriaDaLista(Categoria *inicioLista, char nome[], int *sucesso)
{
  *sucesso = 0;
  if (inicioLista == NULL)
    return NULL;

  Categoria *atual = inicioLista;
  Categoria *anterior = NULL;

  // Encontra o nó a ser removido e o seu anterior
  do
  {
    if (strcmp(atual->nome, nome) == 0)
      break;
    anterior = atual;
    atual = atual->proxima;
  } while (atual != inicioLista);

  // Se não encontrou o nó, retorna
  if (strcmp(atual->nome, nome) != 0)
    return inicioLista;

  // VALIDAÇÃO CRÍTICA: Verifica se a árvore de programas está vazia
  if (atual->arvoreProgramas != NULL)
  {
    printf("  ERRO: A categoria '%s' nao pode ser removida pois possui programas cadastrados.\n", nome);
    return inicioLista;
  }

  // Se a lista só tem um elemento
  if (atual->proxima == atual)
  {
    free(atual);
    *sucesso = 1;
    return NULL;
  }

  // Encontra o último nó para o caso de estarmos removendo o primeiro
  if (anterior == NULL)
  { // Estamos removendo o primeiro nó
    anterior = inicioLista;
    while (anterior->proxima != inicioLista)
      anterior = anterior->proxima;
  }

  // Remove o nó do círculo
  anterior->proxima = atual->proxima;
  if (inicioLista == atual)
  {                               // Se o nó removido era o início...
    inicioLista = atual->proxima; // ...o novo início é o próximo.
  }

  free(atual);
  *sucesso = 1;
  return inicioLista;
}