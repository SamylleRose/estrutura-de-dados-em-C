#ifndef PROGRAMA_BST_H
#define PROGRAMA_BST_H

#include <stdio.h>

#include "programa.h"
Programa *inserirProgramaNaArvoreBst(Programa *raiz, const char nome[], const char periodicidade[], int tempo, int horario, const char tipo[], const char apresentador[]);

Programa *buscarProgramaBst(Programa *raiz, const char nome[]);
Programa *removerProgramaDaArvoreBst(Programa *raiz, const char nome[]);
int contarProgramasNaArvoreBst(Programa *raiz);
#endif