#ifndef APRESENTADOR_H
#define APRESENTADOR_H

#include <stdio.h>

struct Stream;

typedef struct Data
{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct HistoricoTrabalho
{
  char nomeStream[100];
  Data dataInicio;
  Data dataTermino;
  struct HistoricoTrabalho *proximo;
} HistoricoTrabalho;

typedef struct Apresentador
{
  char nome[100];
  char categoriaTrabalho[100];
  char streamTrabalhaAtualmente[100];
  int idade;

  HistoricoTrabalho *historico;
  struct Apresentador *proximo;
  struct Apresentador *anterior;

} Apresentador;

void cadastrarApresentador(Apresentador **inicioLista, char nome[], char categoria[], char stream[]);
void mostrarApresentadores(Apresentador *inicioLista);

Apresentador *buscarApresentador(Apresentador *inicioLista, char nome[]);
Apresentador *selecionarApresentadorDeStream(Apresentador *listaCompleta, char nomeStream[]);

void mostrarApresentadoresDeStream(Apresentador *inicioLista, char nomeStream[]);
void mostrarApresentadoresDeCategoria(Apresentador *inicioLista, char nomeCategoria[]);

void alterarStreamApresentador(Apresentador *listaApresentadores, struct Stream *raizStreams, char nomeApresentador[], char novaStream[]);

#endif