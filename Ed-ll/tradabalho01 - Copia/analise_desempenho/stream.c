#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "apresentador.h"

static int altura(Stream *no)
{
  if (no == NULL)
    return 0;
  return no->altura;
}

static int maior(int a, int b)
{
  return (a > b) ? a : b;
}

static int fatorDeBalanceamento(Stream *no)
{
  if (no == NULL)
    return 0;
  return altura(no->esquerda) - altura(no->direita);
}

static Stream *rotacaoDireita(Stream *y)
{
  Stream *x = y->esquerda;
  Stream *T2 = x->direita;

  x->direita = y;
  y->esquerda = T2;

  y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1;
  x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1;

  return x;
}

static Stream *rotacaoEsquerda(Stream *x)
{
  Stream *y = x->direita;
  Stream *T2 = y->esquerda;

  y->esquerda = x;
  x->direita = T2;

  x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1;
  y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1;

  return y;
}

Stream *cadastrarStream(Stream *raiz, const char nome[], const char site[])
{

  Stream *novaRaiz = raiz;

  if (raiz == NULL)
  {
    Stream *novoStream = (Stream *)malloc(sizeof(Stream));
    strcpy(novoStream->nome, nome);
    strcpy(novoStream->site, site);
    novoStream->listaCategorias = NULL;
    novoStream->esquerda = NULL;
    novoStream->direita = NULL;
    novoStream->altura = 1;
    novaRaiz = novoStream;
  }

  else
  {
    int comparacao = strcmp(nome, raiz->nome);
    if (comparacao < 0)
    {
      raiz->esquerda = cadastrarStream(raiz->esquerda, nome, site);
    }
    else if (comparacao > 0)
    {
      raiz->direita = cadastrarStream(raiz->direita, nome, site);
    }

    if (comparacao != 0)
    {
      raiz->altura = 1 + maior(altura(raiz->esquerda), altura(raiz->direita));
      int fatorBalanceamento = fatorDeBalanceamento(raiz);

      if (fatorBalanceamento > 1 && strcmp(nome, raiz->esquerda->nome) < 0)
      {
        novaRaiz = rotacaoDireita(raiz);
      }

      else if (fatorBalanceamento < -1 && strcmp(nome, raiz->direita->nome) > 0)
      {
        novaRaiz = rotacaoEsquerda(raiz);
      }

      else if (fatorBalanceamento > 1 && strcmp(nome, raiz->esquerda->nome) > 0)
      {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        novaRaiz = rotacaoDireita(raiz);
      }

      else if (fatorBalanceamento < -1 && strcmp(nome, raiz->direita->nome) < 0)
      {
        raiz->direita = rotacaoDireita(raiz->direita);
        novaRaiz = rotacaoEsquerda(raiz);
      }
    }
  }

  return novaRaiz;
}

void cadastrarCategoriaNaStream(Stream *raiz, const char nomeStream[], const char nomeCategoria[], const char tipoCategoria[])
{
  Stream *stream = buscarStream(raiz, nomeStream);
  if (stream != NULL)
  {
    stream->listaCategorias = inserirCategoriaNaLista(stream->listaCategorias, nomeCategoria, tipoCategoria);
  }
}

Stream *buscarStream(Stream *raiz, const char nome[])
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

      resultado = buscarStream(raiz->esquerda, nome);
    }
    else
    {

      resultado = buscarStream(raiz->direita, nome);
    }
  }

  return resultado;
}

Categoria *buscarCategoriaNaStream(Stream *raiz, const char nomeStream[], const char nomeCategoria[])
{

  Stream *stream = buscarStream(raiz, nomeStream);

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

Categoria *buscarCategoria(Stream *stream, const char nomeCategoria[])
{

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

void cadastrarPrograma(Stream *raizStream, Apresentador *listaApresentadores, const char nomeStream[], const char nomeCategoria[], const char nomePrograma[], const char periodicidade[], int tempo, int horario, const char tipo[], const char nomeApresentador[])
{
  Categoria *categoria = buscarCategoriaNaStream(raizStream, nomeStream, nomeCategoria);
  if (categoria != NULL)
  {
    Apresentador *apresentador = buscarApresentador(listaApresentadores, nomeApresentador);
    if (apresentador != NULL)
    {

      Programa *programaExistente = buscarPrograma(categoria->arvoreProgramas, nomePrograma);

      if (programaExistente == NULL)
      {
        categoria->arvoreProgramas = inserirProgramaNaArvore(categoria->arvoreProgramas, nomePrograma, periodicidade, tempo, horario, tipo, nomeApresentador);
      }
    }
  }
}

void removerPrograma(Stream *raizStream, const char nomeStream[], const char nomeCategoria[], const char nomePrograma[])
{

  Stream *s = buscarStream(raizStream, nomeStream);

  if (s)
  {
    Categoria *c = buscarCategoria(s, nomeCategoria);

    if (c)
    {

      c->arvoreProgramas = removerProgramaDaArvore(c->arvoreProgramas, nomePrograma);
    }
  }
}

void removerCategoria(Stream *raizStream, const char nomeStream[], const char nomeCategoria[])
{

  Stream *s = buscarStream(raizStream, nomeStream);
  if (!s)
  {

    return;
  }

  int sucesso = 0;
  s->listaCategorias = removerCategoriaDaLista(s->listaCategorias, nomeCategoria, &sucesso);
}

int _arvoreTemProgramasDoApresentador(Programa *raiz, const char nomeApresentador[])
{

  int encontrado = 0;

  if (raiz != NULL)
  {

    if (strcmp(raiz->nomeApresentador, nomeApresentador) == 0)
    {

      encontrado = 1;
    }
    else
    {

      encontrado = _arvoreTemProgramasDoApresentador(raiz->esquerda, nomeApresentador);

      if (!encontrado)
      {
        encontrado = _arvoreTemProgramasDoApresentador(raiz->direita, nomeApresentador);
      }
    }
  }

  return encontrado;
}

int streamTemProgramasDoApresentador(Stream *stream, const char nomeApresentador[])
{

  int encontrou = 0;

  if (stream != NULL && stream->listaCategorias != NULL)
  {
    Categoria *atual = stream->listaCategorias;

    do
    {

      if (_arvoreTemProgramasDoApresentador(atual->arvoreProgramas, nomeApresentador))
      {

        encontrou = 1;

        break;
      }
      atual = atual->proxima;
    } while (atual != stream->listaCategorias);
  }

  return encontrou;
}