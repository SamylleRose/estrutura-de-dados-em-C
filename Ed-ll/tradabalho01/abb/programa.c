#include <stdlib.h>
#include <string.h>
#include "programa.h"

Programa *inserirProgramaNaArvore(Programa *raiz, char nome[], char periodicidade[], int tempo, int horario, char tipo[], char apresentador[])
{
  if (raiz == NULL)
  {
    Programa *novoPrograma = (Programa *)malloc(sizeof(Programa));
    strcpy(novoPrograma->nome, nome);
    strcpy(novoPrograma->periodicidade, periodicidade);
    novoPrograma->tempoMinutos = tempo;
    novoPrograma->horarioInicio = horario;
    strcpy(novoPrograma->tipo, tipo);
    strcpy(novoPrograma->nomeApresentador, apresentador);
    novoPrograma->esquerda = NULL;
    novoPrograma->direita = NULL;
    return novoPrograma;
  }

  if (strcmp(nome, raiz->nome) < 0)
  {
    raiz->esquerda = inserirProgramaNaArvore(raiz->esquerda, nome, periodicidade, tempo, horario, tipo, apresentador);
  }
  else if (strcmp(nome, raiz->nome) > 0)
  {
    raiz->direita = inserirProgramaNaArvore(raiz->direita, nome, periodicidade, tempo, horario, tipo, apresentador);
  }

  return raiz;
}

void mostrarProgramasDaArvore(Programa *raiz)
{
  if (raiz != NULL)
  {
    mostrarProgramasDaArvore(raiz->esquerda);
    printf("Nome: %s\n", raiz->nome);
    printf("Periodicidade: %s\n", raiz->periodicidade);
    printf("Tempo (minutos): %d\n", raiz->tempoMinutos);
    printf("Horario de Inicio: %d\n", raiz->horarioInicio);
    printf("Tipo: %s\n", raiz->tipo);
    printf("Apresentador: %s\n", raiz->nomeApresentador);
    printf("-------------------------\n");
    mostrarProgramasDaArvore(raiz->direita);
  }
}

Programa *buscarPrograma(Programa *raiz, char nome[])
{
  if (raiz == NULL)
  {
    return NULL;
  }

  if (strcmp(nome, raiz->nome) == 0)
  {
    return raiz;
  }
  else if (strcmp(nome, raiz->nome) < 0)
  {
    return buscarPrograma(raiz->esquerda, nome);
  }
  else
  {
    return buscarPrograma(raiz->direita, nome);
  }
}

// Função auxiliar para encontrar o menor nó em uma sub-árvore (sucessor em-ordem)
Programa *encontrarMenorNo(Programa *no)
{
  Programa *atual = no;
  while (atual && atual->esquerda != NULL)
  {
    atual = atual->esquerda;
  }
  return atual;
}

Programa *removerProgramaDaArvore(Programa *raiz, char nome[])
{
  if (raiz == NULL)
    return raiz;

  // 1. Encontra o nó a ser removido
  if (strcmp(nome, raiz->nome) < 0)
  {
    raiz->esquerda = removerProgramaDaArvore(raiz->esquerda, nome);
  }
  else if (strcmp(nome, raiz->nome) > 0)
  {
    raiz->direita = removerProgramaDaArvore(raiz->direita, nome);
  }
  // 2. Nó encontrado! Agora, trata os 3 casos de remoção:
  else
  {
    // Caso 1: Nó com 0 ou 1 filho
    if (raiz->esquerda == NULL)
    {
      Programa *temp = raiz->direita;
      free(raiz);
      return temp;
    }
    else if (raiz->direita == NULL)
    {
      Programa *temp = raiz->esquerda;
      free(raiz);
      return temp;
    }

    // Caso 3: Nó com 2 filhos
    // Pega o sucessor em-ordem (o menor na sub-árvore direita)
    Programa *temp = encontrarMenorNo(raiz->direita);

    // Copia o conteúdo do sucessor para este nó
    strcpy(raiz->nome, temp->nome);
    strcpy(raiz->periodicidade, temp->periodicidade);
    // ... copie todos os outros campos ...
    strcpy(raiz->nomeApresentador, temp->nomeApresentador);

    // Remove o sucessor em-ordem da sub-árvore direita
    raiz->direita = removerProgramaDaArvore(raiz->direita, temp->nome);
  }
  return raiz;
}