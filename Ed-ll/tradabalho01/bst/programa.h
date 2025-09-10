#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <stdio.h>

// Avl
typedef struct programa
{
  char nome[100];
  char periodicidade[100];
  char stream[100];
  char tipo[30];
  char nomeApresentador[100];

  int tempoMinutos;
  int horarioInicio;

  struct programa *esquerda;
  struct programa *direita;
} Programa;

Programa *inserirProgramaNaArvore(Programa *raiz, char nome[], char periodicidade[], int tempo, int horario, char tipo[], char apresentador[]);
void mostrarProgramasDaArvore(Programa *raiz);
void mostrarProgramasDaArvorePorPeriodicidade(Programa *raiz, const char *periodicidade);
void mostrarProgramasDaArvorePorDiaEHorario(Programa *raiz, const char *dia, int horario);

Programa *buscarPrograma(Programa *raiz, char nome[]);
Programa *removerProgramaDaArvore(Programa *raiz, char nome[]);

#endif