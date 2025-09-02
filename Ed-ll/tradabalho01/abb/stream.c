#include <stdlib.h>
#include <string.h>
#include "stream.h"
#include "apresentador.h"

Stream *cadastrarStream(Stream *raiz, char nome[], char site[])
{
  if (raiz == NULL)
  {
    Stream *novoStream = (Stream *)malloc(sizeof(Stream));
    strcpy(novoStream->nome, nome);
    strcpy(novoStream->site, site);
    novoStream->listaCategorias = NULL;
    novoStream->esquerda = NULL;
    novoStream->direita = NULL;
    printf("Stream '%s' cadastrada com sucesso!\n", nome); //
    return novoStream;
  }

  if (strcmp(nome, raiz->nome) < 0)
  {
    raiz->esquerda = cadastrarStream(raiz->esquerda, nome, site);
  }
  else if (strcmp(nome, raiz->nome) > 0)
  {
    raiz->direita = cadastrarStream(raiz->direita, nome, site);
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
  if (raiz == NULL)
  {
    return NULL;
  }

  if (strcmp(nome, raiz->nome) == 0)
  {
    return raiz;
  }
  else if (strcmp(nome, raiz->nome) < 0)
  {
    return buscarStream(raiz->esquerda, nome);
  }
  else
  {
    return buscarStream(raiz->direita, nome);
  }
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
  if (stream != NULL)
  {
    Categoria *atual = stream->listaCategorias;
    if (atual == NULL)
    {
      return NULL;
    }

    do
    {
      if (strcmp(atual->nome, nomeCategoria) == 0)
      {
        return atual;
      }
      atual = atual->proxima;
    } while (atual != stream->listaCategorias);
  }
  return NULL;
}

Categoria *buscarCategoria(Stream *stream, char nomeCategoria[])
{
  // Esta função assume que já recebemos o ponteiro para a stream correta.
  if (stream == NULL || stream->listaCategorias == NULL)
  {
    return NULL;
  }

  Categoria *atual = stream->listaCategorias;
  do
  {
    if (strcmp(atual->nome, nomeCategoria) == 0)
    {
      return atual; // Encontrou!
    }
    atual = atual->proxima;
  } while (atual != stream->listaCategorias);

  return NULL; // Não encontrou
}

void cadastrarPrograma(Stream *raizStream, Apresentador *listaApresentadores, char nomeStream[], char nomeCategoria[], char nomePrograma[], char periodicidade[], int tempo, int horario, char tipo[], char nomeApresentador[])
{
  Categoria *categoria = buscarCategoriaNaStream(raizStream, nomeStream, nomeCategoria);
  if (categoria != NULL)
  {
    Apresentador *apresentador = buscarApresentador(listaApresentadores, nomeApresentador);
    if (apresentador != NULL)
    {
      categoria->arvoreProgramas = inserirProgramaNaArvore(categoria->arvoreProgramas, nomePrograma, periodicidade, tempo, horario, tipo, nomeApresentador);
      printf("Programa '%s' cadastrado com sucesso na categoria '%s' da stream '%s'!\n", nomePrograma, nomeCategoria, nomeStream);
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
    printf("Programas da Categoria '%s' na Stream '%s':\n", nomeCategoria, nomeStream);
    mostrarProgramasDaArvore(categoria->arvoreProgramas);
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
  funcao(raiz); // Aplica a função em cada stream
  _percorrerStreams(raiz->direita, funcao);
}

void mostrarStreamsComCategoria(Stream *raizStream, char nomeCategoria[])
{
  printf("\n--- Streams com a Categoria '%s' ---\n", nomeCategoria);

  if (raizStream == NULL)
    return;
  mostrarStreamsComCategoria(raizStream->esquerda, nomeCategoria);

  if (buscarCategoria(raizStream, nomeCategoria) != NULL)
  {
    printf("  - %s\n", raizStream->nome);
  }

  mostrarStreamsComCategoria(raizStream->direita, nomeCategoria);
}

void mostrarStreamsComTipoCategoria(Stream *raizStream, char tipoCategoria[])
{
  printf("\n--- Streams com o Tipo de Categoria '%s' ---\n", tipoCategoria);
  if (raizStream == NULL)
    return;

  mostrarStreamsComTipoCategoria(raizStream->esquerda, tipoCategoria);

  // Processa o nó atual
  Categoria *atual = raizStream->listaCategorias;
  if (atual)
  {
    do
    {
      if (strcmp(atual->tipo, tipoCategoria) == 0)
      {
        printf("  - %s\n", raizStream->nome);
        break;
      }
      atual = atual->proxima;
    } while (atual != raizStream->listaCategorias);
  }

  mostrarStreamsComTipoCategoria(raizStream->direita, tipoCategoria);
}

// static void _percorrerEImprimirSePeriodicidade(Programa *p, const char periodicidade[])
// {
//   // Caso base da recursão: se o nó é nulo, não há nada a fazer.
//   if (p == NULL)
//   {
//     return;
//   }

//   // 1. Percorre a sub-árvore esquerda (em ordem)
//   _percorrerEImprimirSePeriodicidade(p->esquerda, periodicidade);

//   // 2. Processa o nó atual
//   if (strcmp(p->periodicidade, periodicidade) == 0)
//   {
//     printf("  - %s (Apresentador: %s, Horario: %d, Duracao: %d min, Tipo: %s)\n",
//            p->nome, p->nomeApresentador, p->horarioInicio, p->tempoMinutos, p->tipo);
//   }

//   // 3. Percorre a sub-árvore direita
//   _percorrerEImprimirSePeriodicidade(p->direita, periodicidade);
// }

// // --- FUNÇÃO PRINCIPAL ---
// // A função principal agora delega o trabalho de percorrer a árvore para a função auxiliar.
// void mostrarProgramasPorPeriodicidade(Stream *raizStream, const char nomeStream[], const char nomeCategoria[], const char periodicidade[])
// {
//   printf("\n--- Programas com periodicidade '%s' na Categoria '%s' da Stream '%s' ---\n", periodicidade, nomeCategoria, nomeStream);

//   Stream *s = buscarStream(raizStream, nomeStream);
//   if (!s)
//   {
//     printf("  ERRO: Stream nao encontrada.\n");
//     return;
//   }

//   Categoria *c = buscarCategoria(s, nomeCategoria);
//   if (!c)
//   {
//     printf("  ERRO: Categoria nao encontrada.\n");
//     return;
//   }

//   // Chama a função auxiliar para fazer o percurso na árvore de programas da categoria encontrada.
//   _percorrerEImprimirSePeriodicidade(c->arvoreProgramas, periodicidade);
// }
void removerPrograma(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[])
{
  printf("\nTentando remover o programa '%s'...\n", nomePrograma);
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

  c->arvoreProgramas = removerProgramaDaArvore(c->arvoreProgramas, nomePrograma);
  printf("  Operacao de remocao finalizada.\n");
}

// Em stream.c
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

int _arvoreTemProgramasDoApresentador(Programa *raiz, char nomeApresentador[])
{
  if (raiz == NULL)
    return 0; // Falso
  if (strcmp(raiz->nomeApresentador, nomeApresentador) == 0)
    return 1; // Verdadeiro
  return _arvoreTemProgramasDoApresentador(raiz->esquerda, nomeApresentador) || _arvoreTemProgramasDoApresentador(raiz->direita, nomeApresentador);
}

int streamTemProgramasDoApresentador(Stream *stream, char nomeApresentador[])
{
  if (stream == NULL || stream->listaCategorias == NULL)
    return 0;

  Categoria *atual = stream->listaCategorias;
  do
  {
    if (_arvoreTemProgramasDoApresentador(atual->arvoreProgramas, nomeApresentador))
    {
      return 1; // Encontrou um programa, pode parar a busca.
    }
    atual = atual->proxima;
  } while (atual != stream->listaCategorias);

  return 0; // Não encontrou nenhum programa do apresentador na stream.
}