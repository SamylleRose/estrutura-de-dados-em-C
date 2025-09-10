
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
void mostrarApresentadores(Apresentador *inicioLista);

Apresentador *buscarApresentador(Apresentador *inicioLista, char nome[]);

void mostrarApresentadoresDeStream(Apresentador *inicioLista, char nomeStream[]);
void mostrarApresentadoresDeCategoria(Apresentador *inicioLista, char nomeCategoria[]);

void alterarStreamApresentador(Apresentador *listaApresentadores, struct Stream *raizStreams, char nomeApresentador[], char novaStream[]);

#endif