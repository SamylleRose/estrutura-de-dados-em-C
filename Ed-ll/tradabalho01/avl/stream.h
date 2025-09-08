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
void mostrarStreams(Stream *raiz);

void cadastrarCategoriaNaStream(Stream *raiz, char nomeStream[], char nomeCategoria[], char tipoCategoria[]);
void mostrarCategoriasDeStream(Stream *raiz, char nomeStream[]);

void cadastrarPrograma(Stream *raizStream, struct Apresentador *listaApresentadores, char nomeStream[], char nomeCategoria[], char nomePrograma[], char periodicidade[], int tempo, int horario, char tipo[], char nomeApresentador[]);
void mostrarProgramasDeCategoria(Stream *raizStream, char nomeStream[], char nomeCategoria[]);

void mostrarDadosPrograma(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[]);

void mostrarStreamsComCategoria(Stream *raizStream, char nomeCategoria[]);
void mostrarStreamsComTipoCategoria(Stream *raizStream, char tipoCategoria[]);
void mostrarProgramasPorPeriodicidade(Stream *raizStream, char nomeStream[], char nomeCategoria[], char periodicidade[]);
void mostrarProgramasPorDiaEHorarioNaStream(Stream *raizStream, char nomeStream[], char dia[], int horario);

Categoria *buscarCategoriaNaStream(Stream *raiz, char nomeStream[], char nomeCategoria[]);
Categoria *buscarCategoria(Stream *stream, char nomeCategoria[]);

void removerPrograma(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[]);
void removerCategoria(Stream *raizStream, char nomeStream[], char nomeCategoria[]);

int streamTemProgramasDoApresentador(Stream *stream, char nomeApresentador[]);

#endif