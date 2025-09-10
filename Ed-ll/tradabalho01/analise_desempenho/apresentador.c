#include <stdlib.h>
#include <string.h>
#include "apresentador.h"
#include "stream.h"

void cadastrarApresentador(Apresentador **inicioLista, char nome[], char categoria[], char stream[])
{
  Apresentador *novoApresentador = (Apresentador *)malloc(sizeof(Apresentador));
  if (novoApresentador == NULL)
  {

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
