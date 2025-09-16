#include <stdlib.h>
#include <string.h>
#include "categoria.h"

Categoria *inserirCategoriaNaLista(Categoria *inicioLista, const char nome[], const char tipo[])
{
  Categoria *ponteiroDeRetorno = inicioLista;

  Categoria *novaCategoria = (Categoria *)malloc(sizeof(Categoria));

  if (novaCategoria == NULL)
  {
    exit(0);
  }

  strcpy(novaCategoria->nome, nome);
  strcpy(novaCategoria->tipo, tipo);
  novaCategoria->arvoreProgramas = NULL;

  if (inicioLista == NULL)
  {
    novaCategoria->proxima = novaCategoria;
    ponteiroDeRetorno = novaCategoria;
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

      free(novaCategoria);
    }
    else
    {
      atual->proxima = novaCategoria;
      novaCategoria->proxima = inicioLista;
    }
  }

  return ponteiroDeRetorno;
}

Categoria *removerCategoriaDaLista(Categoria *inicioLista, const char nome[], int *sucesso)
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

    if (atual == inicioLista && strcmp(atual->nome, nome) != 0)
    {
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
