// stream_bst.h
#ifndef STREAM_BST_H
#define STREAM_BST_H

#include "stream.h"

Stream *cadastrarStreamBst(Stream *raiz, char nome[], char site[]);
void removerProgramaBst(Stream *raizStream, char nomeStream[], char nomeCategoria[], char nomePrograma[]);
void removerCategoriaBst(Stream *raizStream, char nomeStream[], char nomeCategoria[]);

#endif