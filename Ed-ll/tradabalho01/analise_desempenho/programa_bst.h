#ifndef PROGRAMA_BST_H
#define PROGRAMA_BST_H

#include <stdio.h>

#include "programa.h"
Programa *inserirProgramaNaArvoreBst(Programa *raiz, char nome[], char periodicidade[], int tempo, int horario, char tipo[], char apresentador[]);

Programa *buscarProgramaBst(Programa *raiz, char nome[]);
Programa *removerProgramaDaArvoreBst(Programa *raiz, char nome[]);
int contarProgramasNaArvoreBst(Programa *raiz);
#endif