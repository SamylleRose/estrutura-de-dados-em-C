#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <stdio.h>

// Arvore binaria de busca
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

Programa *buscarPrograma(Programa *raiz, char nome[]);

Programa *removerProgramaDaArvore(Programa *raiz, char nome[]);

#endif