#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "apresentador.h"

Stream *cadastrarStream(Stream *raiz, char nome[], char site[])
{

  if (raiz == NULL)
  {
    Stream *novoStream = (Stream *)malloc(sizeof(Stream));
    if (novoStream == NULL)
    {
      printf("\nERRO: Falha na alocacao de memoria para a nova stream.\n");
      exit(1);
    }

    strcpy(novoStream->nome, nome);
    strcpy(novoStream->site, site);
    novoStream->listaCategorias = NULL;
    novoStream->esquerda = NULL;
    novoStream->direita = NULL;
    printf("Stream '%s' cadastrada com sucesso!\n", nome);
    return novoStream;
  }

  int comparacao = strcmp(nome, raiz->nome);

  if (comparacao < 0)
  {

    raiz->esquerda = cadastrarStream(raiz->esquerda, nome, site);
  }
  else if (comparacao > 0)
  {

    raiz->direita = cadastrarStream(raiz->direita, nome, site);
  }
  else
  {

    printf("\nERRO: A stream '%s' ja existe. Cadastro ignorado.\n", nome);
  }

  return raiz;
}

void mostrarStreams(Stream *raiz)
{
  if (raiz != NULL)
  {
    mostrarStreams(raiz->esquerda);
    printf("Nome: %s, Site: %s\n", raiz->nome, raiz->site);
    mostrarStreams(raiz->direita);
  }
}

void cadastrarCategoriaNaStream(Stream *raiz, char nomeStream[], char nomeCategoria[], char tipoCategoria[])
{
  Stream *stream = buscarStream(raiz, nomeStream);
  if (stream != NULL)
  {
    stream->listaCategorias = inserirCategoriaNaLista(stream->listaCategorias, nomeCategoria, tipoCategoria);
  }
  else
  {
    printf("Stream '%s' nao encontrada! Nao foi possivel cadastrar a categoria.\n", nomeStream);
  }
}

Stream *buscarStream(Stream *raiz, char nome[])
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

void mostrarCategoriasDeStream(Stream *raiz, char nomeStream[])
{
  Stream *stream = buscarStream(raiz, nomeStream);
  if (stream != NULL)
  {
    printf("Categorias da Stream '%s':\n", nomeStream);
    mostrarCategorias(stream->listaCategorias);
  }
  else
  {
    printf("Stream '%s' nao encontrada!\n", nomeStream);
  }
}

Categoria *buscarCategoriaNaStream(Stream *raiz, char nomeStream[], char nomeCategoria[])
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

Categoria *buscarCategoria(Stream *stream, char nomeCategoria[])
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

void cadastrarPrograma(Stream *raizStream, Apresentador *listaApresentadores, char nomeStream[], char nomeCategoria[], char nomePrograma[], char periodicidade[], int tempo, int horario, char tipo[], char nomeApresentador[])
{
  Categoria *categoria = buscarCategoriaNaStream(raizStream, nomeStream, nomeCategoria);
  if (categoria != NULL)
  {
    Apresentador *apresentador = buscarApresentador(listaApresentadores, nomeApresentador);
    if (apresentador != NULL)
    {

      Programa *programaExistente = buscarPrograma(categoria->arvoreProgramas, nomePrograma);

      if (programaExistente != NULL)
      {

        printf("Nao foi possivel cadastrar: O programa '%s' ja existe nesta categoria!\n", nomePrograma);
      }
      else
      {

        categoria->arvoreProgramas = inserirProgramaNaArvore(categoria->arvoreProgramas, nomePrograma, periodicidade, tempo, horario, tipo, nomeApresentador);
        printf("Programa '%s' cadastrado com sucesso na categoria '%s' da stream '%s'!\n", nomePrograma, nomeCategoria, nomeStream);
      }
    }
    else
    {
      printf("Apresentador '%s' nao encontrado! Nao foi possivel cadastrar o programa.\n", nomeApresentador);
    }
  }
  else
  {
    printf("Categoria '%s' nao encontrada na stream '%s'! Nao foi possivel cadastrar o programa.\n", nomeCategoria, nomeStream);
  }
}

void mostrarProgramasDeCategoria(Stream *raizStream, char nomeStream[], char nomeCategoria[])
{

  Categoria *categoria = buscarCategoriaNaStream(raizStream, nomeStream, nomeCategoria);

  if (categoria != NULL)
  {

    if (categoria->arvoreProgramas != NULL)
    {

      printf("Programas da Categoria '%s' na Stream '%s':\n", nomeCategoria, nomeStream);
      mostrarProgramasDaArvore(categoria->arvoreProgramas);
    }
    else
    {

      printf("Nenhum programa cadastrado na categoria '%s' da stream '%s'.\n", nomeCategoria, nomeStream);
    }
  }
  else
  {

    printf("Categoria '%s' nao encontrada na stream '%s'!\n", nomeCategoria, nomeStream);
  }
}

void mostrarDadosPrograma(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[])
{
  printf("\n--- Buscando dados do programa '%s' ---\n", nomePrograma);
  Stream *s = buscarStream(raizStream, nomeStream);
  if (!s)
  {
    printf("  ERRO: Stream nao encontrada.\n");
    return;
  }

  Categoria *c = buscarCategoria(s, nomeCategoria);
  if (!c)
  {
    printf("  ERRO: Categoria nao encontrada.\n");
    return;
  }

  Programa *p = buscarPrograma(c->arvoreProgramas, nomePrograma);
  if (!p)
  {
    printf("  ERRO: Programa nao encontrado.\n");
    return;
  }

  printf("  Nome: %s\n", p->nome);
  printf("  Apresentador: %s\n", p->nomeApresentador);
  printf("  Periodicidade: %s\n", p->periodicidade);
  printf("  Horario: %d\n", p->horarioInicio);
  printf("  Duracao: %d min\n", p->tempoMinutos);
  printf("  Tipo: %s\n", p->tipo);
  printf("-------------------------------------------\n");
}

void _percorrerStreams(Stream *raiz, void (*funcao)(Stream *))
{
  if (raiz == NULL)
    return;
  _percorrerStreams(raiz->esquerda, funcao);
  funcao(raiz);
  _percorrerStreams(raiz->direita, funcao);
}

void mostrarStreamsComCategoria(Stream *raizStream, char nomeCategoria[])
{

  if (raizStream == NULL)
    return;
  mostrarStreamsComCategoria(raizStream->esquerda, nomeCategoria);

  if (buscarCategoria(raizStream, nomeCategoria) != NULL)
  {
    printf("Stream '%s'\n", raizStream->nome);
  }

  mostrarStreamsComCategoria(raizStream->direita, nomeCategoria);
}

void mostrarStreamsComTipoCategoria(Stream *raizStream, char tipoCategoria[])
{

  if (raizStream == NULL)
    return;

  mostrarStreamsComTipoCategoria(raizStream->esquerda, tipoCategoria);

  Categoria *atual = raizStream->listaCategorias;
  if (atual)
  {
    do
    {
      if (strcmp(atual->tipo, tipoCategoria) == 0)
      {
        printf("Stream '%s'\n", raizStream->nome);
        break;
      }
      atual = atual->proxima;
    } while (atual != raizStream->listaCategorias);
  }

  mostrarStreamsComTipoCategoria(raizStream->direita, tipoCategoria);
}

void mostrarProgramasPorPeriodicidade(Stream *raizStream, char nomeStream[], char nomeCategoria[], char periodicidade[])
{
  printf("\n--- Programas da stream '%s' na categoria '%s' com periodicidade '%s' ---\n", nomeStream, nomeCategoria, periodicidade);

  Stream *s = buscarStream(raizStream, nomeStream);

  if (s != NULL)
  {

    Categoria *c = buscarCategoria(s, nomeCategoria);
    if (c != NULL)
    {

      if (c->arvoreProgramas != NULL)
      {

        mostrarProgramasDaArvorePorPeriodicidade(c->arvoreProgramas, periodicidade);
      }
      else
      {

        printf("  Nenhum programa cadastrado nesta categoria.\n");
      }
    }
    else
    {

      printf("  ERRO: Categoria nao encontrada.\n");
    }
  }
  else
  {

    printf("  ERRO: Stream nao encontrada.\n");
  }

  return;
}

void mostrarProgramasPorDiaEHorarioNaStream(Stream *raizStream, char nomeStream[], char dia[], int horario)
{
  printf("\n--- Programas da stream '%s' com periodicidade '%s' e horario '%d' ---\n", nomeStream, dia, horario);

  Stream *stream = buscarStream(raizStream, nomeStream);

  if (stream != NULL)
  {

    if (stream->listaCategorias != NULL)
    {

      Categoria *atual = stream->listaCategorias;
      do
      {
        printf("Verificando na Categoria: %s\n", atual->nome);
        mostrarProgramasDaArvorePorDiaEHorario(atual->arvoreProgramas, dia, horario);
        atual = atual->proxima;
      } while (atual != stream->listaCategorias);
    }
    else
    {

      printf("  Nenhuma categoria (e portanto nenhum programa) nesta stream.\n");
    }
  }
  else
  {

    printf("  ERRO: Stream nao encontrada.\n");
  }

  return;
}

void removerPrograma(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[])
{
  printf("\nTentando remover o programa '%s'...\n", nomePrograma);
  Stream *s = buscarStream(raizStream, nomeStream);

  if (s != NULL)
  {
    Categoria *c = buscarCategoria(s, nomeCategoria);

    if (c != NULL)
    {

      c->arvoreProgramas = removerProgramaDaArvore(c->arvoreProgramas, nomePrograma);
      printf("  Operacao de remocao finalizada.\n");
    }
    else
    {
      printf("  ERRO: Categoria nao encontrada.\n");
    }
  }
  else
  {
    printf("  ERRO: Stream nao encontrada.\n");
  }

  return;
}

void removerCategoria(Stream *raizStream, char nomeStream[], char nomeCategoria[])
{
  printf("\nTentando remover a categoria '%s'...\n", nomeCategoria);
  Stream *s = buscarStream(raizStream, nomeStream);
  if (!s)
  {
    printf("  ERRO: Stream nao encontrada.\n");
    return;
  }

  int sucesso = 0;
  s->listaCategorias = removerCategoriaDaLista(s->listaCategorias, nomeCategoria, &sucesso);

  if (sucesso)
  {
    printf("  Categoria '%s' removida com sucesso.\n", nomeCategoria);
  }
}

static int _arvoreTemProgramasDoApresentador(Programa *raiz, char nomeApresentador[])
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

      if (encontrado == 0)
      {
        encontrado = _arvoreTemProgramasDoApresentador(raiz->direita, nomeApresentador);
      }
    }
  }

  return encontrado;
}

int streamTemProgramasDoApresentador(Stream *stream, char nomeApresentador[])
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