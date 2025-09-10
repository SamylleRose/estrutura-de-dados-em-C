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

Stream *cadastrarStream(Stream *raiz, char nome[], char site[]);
Stream *buscarStream(Stream *raiz, char nome[]);

void cadastrarCategoriaNaStream(Stream *raiz, char nomeStream[], char nomeCategoria[], char tipoCategoria[]);
void cadastrarPrograma(Stream *raizStream, struct Apresentador *listaApresentadores, char nomeStream[], char nomeCategoria[], char nomePrograma[], char periodicidade[], int tempo, int horario, char tipo[], char nomeApresentador[]);

Categoria *buscarCategoriaNaStream(Stream *raiz, char nomeStream[], char nomeCategoria[]);
Categoria *buscarCategoria(Stream *stream, char nomeCategoria[]);

void removerPrograma(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[]);
void removerCategoria(Stream *raizStream, char nomeStream[], char nomeCategoria[]);

int streamTemProgramasDoApresentador(Stream *stream, char nomeApresentador[]);

#endif