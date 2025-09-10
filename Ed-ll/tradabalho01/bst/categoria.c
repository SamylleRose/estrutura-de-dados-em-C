#include <stdlib.h>
#include <string.h>
#include "categoria.h"

Categoria *inserirCategoriaNaLista(Categoria *inicioLista, char nome[], char tipo[])
{
  Categoria *ponteiroDeRetorno = inicioLista;

  Categoria *novaCategoria = (Categoria *)malloc(sizeof(Categoria));

  if (novaCategoria == NULL)
  {
    printf("\nERRO: Falha na alocacao de memoria para a nova categoria.\n");
    exit(0);
  }

  strcpy(novaCategoria->nome, nome);
  strcpy(novaCategoria->tipo, tipo);
  novaCategoria->arvoreProgramas = NULL;

  if (inicioLista == NULL)
  {
    novaCategoria->proxima = novaCategoria;
    ponteiroDeRetorno = novaCategoria;
    printf("Categoria '%s' cadastrada com sucesso!\n", nome);
  }
  else
  {
    Categoria *atual = inicioLista;
    int duplicadoEncontrado = 0;

    while (atual->proxima != inicioLista)
    {
      if (strcmp(atual->nome, nome) == 0)
      {
        duplicadoEncontrado = 1;
        break;
      }
      atual = atual->proxima;
    }

    if (!duplicadoEncontrado && strcmp(atual->nome, nome) == 0)
    {
      duplicadoEncontrado = 1;
    }

    if (duplicadoEncontrado)
    {

      printf("Categoria '%s' já existe na lista. Cadastro ignorado.\n", nome);
      free(novaCategoria);
    }
    else
    {
      atual->proxima = novaCategoria;
      novaCategoria->proxima = inicioLista;
      printf("Categoria '%s' cadastrada com sucesso!\n", nome);
    }
  }

  return ponteiroDeRetorno;
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
  Categoria *ponteiroDeRetorno = inicioLista;

  if (inicioLista == NULL)
  {
    ponteiroDeRetorno = NULL;
  }
  else
  {

    Categoria *atual = inicioLista;
    Categoria *anterior = NULL;

    do
    {
      if (strcmp(atual->nome, nome) == 0)
        break;
      anterior = atual;
      atual = atual->proxima;
    } while (atual != inicioLista);

    if (strcmp(atual->nome, nome) != 0)
    {
    }
    else if (atual->arvoreProgramas != NULL)
    {

      printf("  ERRO: A categoria '%s' nao pode ser removida pois possui programas cadastrados.\n", nome);
    }
    else
    {

      *sucesso = 1;

      if (atual->proxima == atual)
      {
        ponteiroDeRetorno = NULL;
      }

      else
      {

        if (anterior == NULL)
        {
          anterior = inicioLista;
          while (anterior->proxima != inicioLista)
            anterior = anterior->proxima;
        }

        anterior->proxima = atual->proxima;

        if (ponteiroDeRetorno == atual)
        {
          ponteiroDeRetorno = atual->proxima;
        }
      }

      free(atual);
    }
  }

  return ponteiroDeRetorno;
}
