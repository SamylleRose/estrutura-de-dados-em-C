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

Categoria *inserirCategoriaNaLista(Categoria *inicioLista, char nome[], char tipo[]);
Categoria *removerCategoriaDaLista(Categoria *inicioLista, char nome[], int *sucesso);

#endif