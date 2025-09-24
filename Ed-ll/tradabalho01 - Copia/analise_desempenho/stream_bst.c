#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "apresentador.h"

Stream *cadastrarStreamBst(Stream *raiz, const char nome[], const char site[])
{

  Stream *resultado = NULL;

  if (raiz == NULL)
  {
    Stream *novoStream = (Stream *)malloc(sizeof(Stream));
    if (novoStream == NULL)
    {

      exit(1);
    }

    strcpy(novoStream->nome, nome);
    strcpy(novoStream->site, site);
    novoStream->listaCategorias = NULL;
    novoStream->esquerda = NULL;
    novoStream->direita = NULL;

    resultado = novoStream;
  }

  else
  {
    int comparacao = strcmp(nome, raiz->nome);
    if (comparacao < 0)
    {
      raiz->esquerda = cadastrarStreamBst(raiz->esquerda, nome, site);
    }
    else if (comparacao > 0)
    {
      raiz->direita = cadastrarStreamBst(raiz->direita, nome, site);
    }

    resultado = raiz;
  }

  return resultado;
}

Stream *buscarStreamBst(Stream *raiz, const char nome[])
{

  Stream *resultado = NULL;

  if (raiz != NULL)
  {
    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao == 0)
    {
      resultado = raiz;
    }

    else if (comparacao < 0)
    {
      resultado = buscarStreamBst(raiz->esquerda, nome);
    }

    else
    {
      resultado = buscarStreamBst(raiz->direita, nome);
    }
  }

  return resultado;
}

void removerProgramaBst(Stream *raizStream, const char nomeStream[], const char nomeCategoria[], const char nomePrograma[])
{

  Stream *s = buscarStream(raizStream, nomeStream);

  if (s != NULL)
  {
    Categoria *c = buscarCategoria(s, nomeCategoria);

    if (c != NULL)
    {

      c->arvoreProgramas = removerProgramaDaArvore(c->arvoreProgramas, nomePrograma);
    }
  }

  return;
}

void removerCategoriaBst(Stream *raizStream, const char nomeStream[], const char nomeCategoria[])
{

  Stream *s = buscarStream(raizStream, nomeStream);
  if (!s)
  {

    return;
  }

  int sucesso = 0;
  s->listaCategorias = removerCategoriaDaLista(s->listaCategorias, nomeCategoria, &sucesso);
}

void cadastrarCategoriaNaStreamBst(Stream *raiz, const char nomeStream[], const char nomeCategoria[], const char tipoCategoria[])
{

  Stream *stream = buscarStreamBst(raiz, nomeStream);
  if (stream != NULL)
  {

    stream->listaCategorias = inserirCategoriaNaLista(stream->listaCategorias, nomeCategoria, tipoCategoria);
  }
}

Categoria *buscarCategoriaNaStreamBst(Stream *raiz, const char nomeStream[], const char nomeCategoria[])

{

  Stream *stream = buscarStreamBst(raiz, nomeStream);

  Categoria *resultado = NULL;
  if (stream != NULL && stream->listaCategorias != NULL)
  {
    Categoria *atual = stream->listaCategorias;
    do
    {
      if (strcmp(atual->nome, nomeCategoria) == 0)
      {
        resultado = atual;
        break;
      }
      atual = atual->proxima;
    } while (atual != stream->listaCategorias);
  }
  return resultado;
}
