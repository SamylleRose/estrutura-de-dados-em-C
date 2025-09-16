#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <stdio.h>
#include "programa.h"

// lista circular simples
typedef struct Categoria
{
  char nome[100];
  char tipo[50];

  Programa *arvoreProgramas;

  struct Categoria *proxima;
} Categoria;

Categoria *inserirCategoriaNaLista(Categoria *inicioLista, const char nome[], const char tipo[]);
Categoria *removerCategoriaDaLista(Categoria *inicioLista, const char nome[], int *sucesso);

#endif