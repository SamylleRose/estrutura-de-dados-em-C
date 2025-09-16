// stream_bst.h
#ifndef STREAM_BST_H
#define STREAM_BST_H

#include "stream.h"

Stream *cadastrarStreamBst(Stream *raiz, const char nome[], const char site[]);
Stream *buscarStreamBst(Stream *raiz, const char nome[]);
void removerProgramaBst(Stream *raizStream, const char nomeStream[], const char nomeCategoria[], const char nomePrograma[]);
void removerCategoriaBst(Stream *raizStream, const char nomeStream[], const char nomeCategoria[]);

void cadastrarCategoriaNaStreamBst(Stream *raiz, const char nomeStream[], const char nomeCategoria[], const char tipoCategoria[]);
Categoria *buscarCategoriaNaStreamBst(Stream *raiz, const char nomeStream[], const char nomeCategoria[]);

#endif