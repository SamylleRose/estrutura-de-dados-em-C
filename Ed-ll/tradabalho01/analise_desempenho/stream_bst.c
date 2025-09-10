#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "apresentador.h"

Stream *cadastrarStreamBst(Stream *raiz, char nome[], char site[])
{

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

    return novoStream;
  }

  int comparacao = strcmp(nome, raiz->nome);

  if (comparacao < 0)
  {

    raiz->esquerda = cadastrarStreamBst(raiz->esquerda, nome, site);
  }
  else if (comparacao > 0)
  {

    raiz->direita = cadastrarStreamBst(raiz->direita, nome, site);
  }

  return raiz;
}

void removerProgramaBst(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[])
{
  printf("\nTentando remover o programa '%s'...\n", nomePrograma);
  Stream *s = buscarStream(raizStream, nomeStream);
  if (!s)
  {
    return;
  }

  Categoria *c = buscarCategoria(s, nomeCategoria);
  if (!c)
  {
    return;
  }

  c->arvoreProgramas = removerProgramaDaArvore(c->arvoreProgramas, nomePrograma);
}

void removerCategoriaBst(Stream *raizStream, char nomeStream[], char nomeCategoria[])
{
  printf("\nTentando remover a categoria '%s'...\n", nomeCategoria);
  Stream *s = buscarStream(raizStream, nomeStream);
  if (!s)
  {

    return;
  }

  int sucesso = 0;
  s->listaCategorias = removerCategoriaDaLista(s->listaCategorias, nomeCategoria, &sucesso);
}