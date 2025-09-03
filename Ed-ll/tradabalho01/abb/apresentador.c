#include <stdlib.h>
#include <string.h>
#include "apresentador.h"
#include "stream.h"

void cadastrarApresentador(Apresentador **inicioLista, char nome[], char categoria[], char stream[])
{
  Apresentador *novoApresentador = (Apresentador *)malloc(sizeof(Apresentador));
  if (novoApresentador == NULL)
  {
    printf("\nERRO: Falha na alocacao de memoria para o novo apresentador.\n");
    exit(0);
  }

  strcpy(novoApresentador->nome, nome);
  strcpy(novoApresentador->categoriaTrabalho, categoria);
  strcpy(novoApresentador->streamTrabalhaAtualmente, stream);
  novoApresentador->idade = 0;
  novoApresentador->numTrabalhosAnteriores = 0;
  novoApresentador->trabalhoAnterior.nomeStream[0] = '\0';
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

  Apresentador *resultado = NULL;

  while (atual != NULL)
  {
    if (strcmp(atual->nome, nome) == 0)
    {
      resultado = atual;
    }
    atual = atual->proximo;
  }

  return resultado;
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

  Stream *s = buscarStream(raizStreams, novaStream);
  if (s != NULL)
  {

    Apresentador *ap = buscarApresentador(listaApresentadores, nomeApresentador);
    if (ap != NULL)
    {

      if (!streamTemProgramasDoApresentador(s, nomeApresentador))
      {

        strcpy(ap->streamTrabalhaAtualmente, novaStream);
        printf("  Sucesso! A stream de '%s' foi alterada para '%s'.\n", nomeApresentador, novaStream);
      }
      else
      {

        printf("  ERRO: '%s' ja possui programas na stream '%s'. A alteracao nao pode ser feita.\n", nomeApresentador, novaStream);
      }
    }
    else
    {

      printf("  ERRO: Apresentador '%s' nao encontrado.\n", nomeApresentador);
    }
  }
  else
  {

    printf("  ERRO: A nova stream '%s' nao existe.\n", novaStream);
  }

  return;
}