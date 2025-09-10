#include <stdlib.h>
#include <string.h>
#include "programa.h"

Programa *inserirProgramaNaArvoreBst(Programa *raiz, char nome[], char periodicidade[], int tempo, int horario, char tipo[], char apresentador[])
{

  Programa *resultado = NULL;

  if (raiz == NULL)
  {
    Programa *novoPrograma = (Programa *)malloc(sizeof(Programa));

    if (novoPrograma == NULL)
    {
      exit(0);
    }

    strcpy(novoPrograma->nome, nome);
    strcpy(novoPrograma->periodicidade, periodicidade);
    novoPrograma->tempoMinutos = tempo;
    novoPrograma->horarioInicio = horario;
    strcpy(novoPrograma->tipo, tipo);
    strcpy(novoPrograma->nomeApresentador, apresentador);
    novoPrograma->esquerda = NULL;
    novoPrograma->direita = NULL;

    resultado = novoPrograma;
  }
  else
  {

    if (strcmp(nome, raiz->nome) < 0)
    {
      raiz->esquerda = inserirProgramaNaArvoreBst(raiz->esquerda, nome, periodicidade, tempo, horario, tipo, apresentador);
    }

    else if (strcmp(nome, raiz->nome) > 0)
    {
      raiz->direita = inserirProgramaNaArvoreBst(raiz->direita, nome, periodicidade, tempo, horario, tipo, apresentador);
    }

    resultado = raiz;
  }

  return resultado;
}

Programa *buscarProgramaBst(Programa *raiz, char nome[])
{

  Programa *resultado = NULL;

  if (raiz != NULL)
  {
    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao == 0)
    {
      resultado = raiz;
    }
    else if (comparacao < 0)
    {
      resultado = buscarProgramaBst(raiz->esquerda, nome);
    }
    else
    {
      resultado = buscarProgramaBst(raiz->direita, nome);
    }
  }
  return resultado;
}

Programa *encontrarMenorNoBst(Programa *no)
{

  if (no == NULL || no->esquerda == NULL)
  {
    return no;
  }

  return encontrarMenorNoBst(no->esquerda);
}
// Em programa_bst.c

Programa *removerProgramaDaArvoreBst(Programa *raiz, char nome[])
{
  Programa *resultado = raiz;

  if (raiz != NULL)
  {
    if (strcmp(nome, raiz->nome) < 0)
    {
      raiz->esquerda = removerProgramaDaArvoreBst(raiz->esquerda, nome);
    }
    else if (strcmp(nome, raiz->nome) > 0)
    {
      raiz->direita = removerProgramaDaArvoreBst(raiz->direita, nome);
    }
    else
    {
      // Nó a ser removido foi encontrado
      Programa *temp = NULL;

      // Caso com 0 ou 1 filho à direita
      if (raiz->esquerda == NULL)
      {
        temp = raiz->direita;
        free(raiz);
        resultado = temp;
      }
      // Caso com 1 filho à esquerda
      else if (raiz->direita == NULL)
      {
        temp = raiz->esquerda;
        free(raiz);
        resultado = temp;
      }
      // Caso com 2 filhos
      else
      {
        Programa *sucessor = encontrarMenorNoBst(raiz->direita);

        // --- CORREÇÃO: Copiar TODOS os dados do sucessor ---
        // Usar strncpy é mais seguro para evitar buffer overflow
        strncpy(raiz->nome, sucessor->nome, sizeof(raiz->nome) - 1);
        strncpy(raiz->periodicidade, sucessor->periodicidade, sizeof(raiz->periodicidade) - 1);
        strncpy(raiz->tipo, sucessor->tipo, sizeof(raiz->tipo) - 1);
        strncpy(raiz->nomeApresentador, sucessor->nomeApresentador, sizeof(raiz->nomeApresentador) - 1);
        raiz->tempoMinutos = sucessor->tempoMinutos;
        raiz->horarioInicio = sucessor->horarioInicio;
        // O campo 'altura' não é usado na BST, então não precisa ser copiado.

        // Remove o nó sucessor que agora está duplicado
        raiz->direita = removerProgramaDaArvoreBst(raiz->direita, sucessor->nome);

        // O resultado ainda é a raiz atual, pois não a movemos, apenas mudamos o seu conteúdo
        resultado = raiz;
      }
    }
  }

  return resultado;
}

int contarProgramasNaArvoreBst(Programa *raiz)
{
  if (raiz == NULL)
    return 0;
  return 1 + contarProgramasNaArvoreBst(raiz->esquerda) + contarProgramasNaArvoreBst(raiz->direita);
}