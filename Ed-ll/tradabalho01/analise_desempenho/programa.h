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

  int altura;
  int tempoMinutos;
  int horarioInicio;

  struct programa *esquerda;
  struct programa *direita;
} Programa;

Programa *inserirProgramaNaArvore(Programa *raiz, const char nome[], const char periodicidade[], int tempo, int horario, const char tipo[], const char apresentador[]);

Programa *buscarPrograma(Programa *raiz, const char nome[]);
Programa *removerProgramaDaArvore(Programa *raiz, const char nome[]);

int contarProgramasNaArvore(Programa *raiz);

#endif