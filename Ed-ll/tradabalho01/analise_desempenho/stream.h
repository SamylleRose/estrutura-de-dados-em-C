#ifndef STREAM_H
#define STREAM_H

#include <stdio.h>
#include "categoria.h"

struct Apresentador;

// Arvore binaria de busca de streams
typedef struct Stream
{
  char nome[100];
  char site[100];
  Categoria *listaCategorias;
  int altura;

  struct Stream *esquerda;
  struct Stream *direita;
} Stream;

Stream *cadastrarStream(Stream *raiz, const char nome[], const char site[]);
Stream *buscarStream(Stream *raiz, const char nome[]);

void cadastrarCategoriaNaStream(Stream *raiz, const char nomeStream[], const char nomeCategoria[], const char tipoCategoria[]);
void cadastrarPrograma(Stream *raizStream, struct Apresentador *listaApresentadores, const char nomeStream[], const char nomeCategoria[], const char nomePrograma[], const char periodicidade[], int tempo, int horario, const char tipo[], const char nomeApresentador[]);

Categoria *buscarCategoriaNaStream(Stream *raiz, const char nomeStream[], const char nomeCategoria[]);
Categoria *buscarCategoria(Stream *stream, const char nomeCategoria[]);

void removerPrograma(Stream *raizStream, const char nomeStream[], const char nomeCategoria[], const char nomePrograma[]);
void removerCategoria(Stream *raizStream, const char nomeStream[], const char nomeCategoria[]);

int streamTemProgramasDoApresentador(Stream *stream, const char nomeApresentador[]);

#endif