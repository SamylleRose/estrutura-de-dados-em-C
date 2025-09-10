
#ifndef APRESENTADOR_H // Se APRESENTADOR_H não foi definido ainda...
#define APRESENTADOR_H

#include <stdio.h>

struct Stream;

typedef struct TrabalhoAnterior
{
  char nomeStream[100];
} TrabalhoAnterior;

// lista ordenada duplamente encadeada
typedef struct Apresentador
{
  char nome[100];
  char categoriaTrabalho[100];
  char streamTrabalhaAtualmente[100];
  int idade;

  TrabalhoAnterior trabalhoAnterior;
  int numTrabalhosAnteriores;

  struct Apresentador *proximo;
  struct Apresentador *anterior;

} Apresentador;

void cadastrarApresentador(Apresentador **inicioLista, char nome[], char categoria[], char stream[]);
Apresentador *buscarApresentador(Apresentador *inicioLista, char nome[]);

#endif