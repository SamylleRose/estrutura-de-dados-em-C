#include <stdlib.h>
#include <string.h>
#include "programa.h"

Programa *inserirProgramaNaArvore(Programa *raiz, char nome[], char periodicidade[], int tempo, int horario, char tipo[], char apresentador[])
{

  Programa *resultado = NULL;

  if (raiz == NULL)
  {
    Programa *novoPrograma = (Programa *)malloc(sizeof(Programa));

    if (novoPrograma == NULL)
    {
      printf("\nERRO: Falha na alocacao de memoria para o novo programa.\n");
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

    printf("Programa '%s' cadastrado com sucesso!\n", nome);
    resultado = novoPrograma;
  }
  else
  {

    if (strcmp(nome, raiz->nome) < 0)
    {
      raiz->esquerda = inserirProgramaNaArvore(raiz->esquerda, nome, periodicidade, tempo, horario, tipo, apresentador);
    }

    else if (strcmp(nome, raiz->nome) > 0)
    {
      raiz->direita = inserirProgramaNaArvore(raiz->direita, nome, periodicidade, tempo, horario, tipo, apresentador);
    }

    resultado = raiz;
  }

  return resultado;
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

void mostrarProgramasDaArvorePorPeriodicidade(Programa *raiz, const char *periodicidade)
{
  if (raiz == NULL)
  {
    return;
  }

  mostrarProgramasDaArvorePorPeriodicidade(raiz->esquerda, periodicidade);

  if (strcmp(raiz->periodicidade, periodicidade) == 0)
  {
    printf("Programa: %s (Apresentador: %s)\n", raiz->nome, raiz->nomeApresentador);
  }

  mostrarProgramasDaArvorePorPeriodicidade(raiz->direita, periodicidade);
}

void mostrarProgramasDaArvorePorDiaEHorario(Programa *raiz, const char *dia, int horario)
{
  if (raiz == NULL)
    return;

  mostrarProgramasDaArvorePorDiaEHorario(raiz->esquerda, dia, horario);

  if (strcmp(raiz->periodicidade, dia) == 0 && raiz->horarioInicio == horario)
  {
    printf("    -> Programa: %s (Apresentador: %s)\n", raiz->nome, raiz->nomeApresentador);
  }

  mostrarProgramasDaArvorePorDiaEHorario(raiz->direita, dia, horario);
}

Programa *buscarPrograma(Programa *raiz, char nome[])
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
      resultado = buscarPrograma(raiz->esquerda, nome);
    }
    else
    {
      resultado = buscarPrograma(raiz->direita, nome);
    }
  }
  return resultado;
}

Programa *encontrarMenorNo(Programa *no)
{

  if (no == NULL || no->esquerda == NULL)
  {
    return no;
  }

  return encontrarMenorNo(no->esquerda);
}

Programa *removerProgramaDaArvore(Programa *raiz, char nome[])
{
  Programa *resultado = raiz;

  if (raiz != NULL)
  {
    if (strcmp(nome, raiz->nome) < 0)
    {
      raiz->esquerda = removerProgramaDaArvore(raiz->esquerda, nome);
    }
    else if (strcmp(nome, raiz->nome) > 0)
    {
      raiz->direita = removerProgramaDaArvore(raiz->direita, nome);
    }
    else
    {

      Programa *temp = NULL;

      if (raiz->esquerda == NULL)
      {
        temp = raiz->direita;
        free(raiz);
        resultado = temp;
      }
      else if (raiz->direita == NULL)
      {
        temp = raiz->esquerda;
        free(raiz);
        resultado = temp;
      }
      else
      {

        Programa *sucessor = encontrarMenorNo(raiz->direita);

        strcpy(raiz->nome, sucessor->nome);

        raiz->direita = removerProgramaDaArvore(raiz->direita, sucessor->nome);
      }
    }
  }

  return resultado;
}