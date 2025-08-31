#include <stdlib.h>
#include <string.h>
#include "apresentador.h"
#include "stream.h"

void cadastrarApresentador(Apresentador **inicioLista, char nome[], char categoria[], char stream[])
{
  Apresentador *novoApresentador = (Apresentador *)malloc(sizeof(Apresentador));
  if (!novoApresentador)
    return;

  strcpy(novoApresentador->nome, nome);
  strcpy(novoApresentador->categoriaTrabalho, categoria);
  strcpy(novoApresentador->streamTrabalhaAtualmente, stream);
  novoApresentador->idade = 0; // Idade inicializada como 0
  novoApresentador->numTrabalhosAnteriores = 0;
  novoApresentador->trabalhoAnterior.nomeStream[0] = '\0'; // Inicializa o nome do trabalho anterior como vazio
  novoApresentador->proximo = NULL;
  novoApresentador->anterior = NULL;

  if (*inicioLista == NULL)
  {
    *inicioLista = novoApresentador;
  }
  else
  {
    Apresentador *atual = *inicioLista;
    Apresentador *anterior = NULL;

    while (atual != NULL && strcmp(novoApresentador->nome, atual->nome) > 0)
    {
      anterior = atual;
      atual = atual->proximo;
    }

    if (anterior == NULL)
    {

      novoApresentador->proximo = *inicioLista;
      (*inicioLista)->anterior = novoApresentador;
      *inicioLista = novoApresentador;
    }
    else
    {

      novoApresentador->proximo = atual;
      novoApresentador->anterior = anterior;
      anterior->proximo = novoApresentador;
      if (atual != NULL)
      {
        atual->anterior = novoApresentador;
      }
    }
  }

  printf("Apresentador '%s' cadastrado com sucesso!\n", nome);
}

void mostrarApresentadores(Apresentador *inicioLista)
{
  Apresentador *atual = inicioLista;
  if (atual == NULL)
  {
    printf("Nenhum apresentador cadastrado.\n");
    return;
  }

  printf("Lista de Apresentadores:\n");
  while (atual != NULL)
  {
    printf("Nome: %s, Categoria: %s, Stream: %s, Idade: %d, Trabalhos Anteriores: %d\n",
           atual->nome, atual->categoriaTrabalho, atual->streamTrabalhaAtualmente,
           atual->idade, atual->numTrabalhosAnteriores);
    if (atual->numTrabalhosAnteriores > 0)
    {
      printf("  Ultimo Trabalho Anterior: %s\n", atual->trabalhoAnterior.nomeStream);
    }
    atual = atual->proximo;
  }
}

Apresentador *buscarApresentador(Apresentador *inicioLista, char nome[])
{
  Apresentador *atual = inicioLista;
  while (atual != NULL)
  {
    if (strcmp(atual->nome, nome) == 0)
    {
      return atual; // Apresentador encontrado
    }
    atual = atual->proximo;
  }
  return NULL; // Apresentador não encontrado
}

void mostrarApresentadoresDeStream(Apresentador *inicioLista, char nomeStream[])
{
  Apresentador *atual = inicioLista;
  int encontrado = 0;

  printf("Apresentadores da Stream '%s':\n", nomeStream);
  while (atual != NULL)
  {
    if (strcmp(atual->streamTrabalhaAtualmente, nomeStream) == 0)
    {
      printf("Nome: %s, Categoria: %s, Idade: %d, Trabalhos Anteriores: %d\n",
             atual->nome, atual->categoriaTrabalho,
             atual->idade, atual->numTrabalhosAnteriores);
      if (atual->numTrabalhosAnteriores > 0)
      {
        printf("  Ultimo Trabalho Anterior: %s\n", atual->trabalhoAnterior.nomeStream);
      }
      encontrado = 1;
    }
    atual = atual->proximo;
  }

  if (!encontrado)
  {
    printf("Nenhum apresentador encontrado para a stream '%s'.\n", nomeStream);
  }
}

void mostrarApresentadoresDeCategoria(Apresentador *inicioLista, char nomeCategoria[])
{
  Apresentador *atual = inicioLista;
  int encontrado = 0;

  printf("Apresentadores da Categoria '%s':\n", nomeCategoria);
  while (atual != NULL)
  {
    if (strcmp(atual->categoriaTrabalho, nomeCategoria) == 0)
    {
      printf("Nome: %s, Stream: %s, Idade: %d, Trabalhos Anteriores: %d\n",
             atual->nome, atual->streamTrabalhaAtualmente,
             atual->idade, atual->numTrabalhosAnteriores);
      if (atual->numTrabalhosAnteriores > 0)
      {
        printf("  Ultimo Trabalho Anterior: %s\n", atual->trabalhoAnterior.nomeStream);
      }
      encontrado = 1;
    }
    atual = atual->proximo;
  }

  if (!encontrado)
  {
    printf("Nenhum apresentador encontrado para a categoria '%s'.\n", nomeCategoria);
  }
}

void alterarStreamApresentador(Apresentador *listaApresentadores, Stream *raizStreams, char nomeApresentador[], char novaStream[])
{
  printf("\nTentando alterar a stream de '%s' para '%s'...\n", nomeApresentador, novaStream);

  // 1. A nova stream existe?
  Stream *s = buscarStream(raizStreams, novaStream);
  if (!s)
  {
    printf("  ERRO: A nova stream '%s' nao existe.\n", novaStream);
    return;
  }

  // 2. O apresentador existe?
  Apresentador *ap = buscarApresentador(listaApresentadores, nomeApresentador);
  if (!ap)
  {
    printf("  ERRO: Apresentador '%s' nao encontrado.\n", nomeApresentador);
    return;
  }

  // 3. VALIDAÇÃO CRÍTICA: O apresentador tem programas na stream para a qual ele quer se mudar?
  if (streamTemProgramasDoApresentador(s, nomeApresentador))
  {
    printf("  ERRO: '%s' ja possui programas na stream '%s'. A alteracao nao pode ser feita.\n", nomeApresentador, novaStream);
    return;
  }

  // Se tudo passou, altera
  strcpy(ap->streamTrabalhaAtualmente, novaStream);
  printf("  Sucesso! A stream de '%s' foi alterada para '%s'.\n", nomeApresentador, novaStream);
}