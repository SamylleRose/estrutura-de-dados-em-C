#include <stdlib.h>
#include <string.h>
#include "programa.h"

static int altura(Programa *no)
{
  if (no == NULL)
    return 0;
  return no->altura;
}

static int maior(int a, int b)
{
  return (a > b) ? a : b;
}

static int fatorDeBalanceamento(Programa *no)
{
  if (no == NULL)
    return 0;
  return altura(no->esquerda) - altura(no->direita);
}

static Programa *rotacaoDireita(Programa *y)
{
  Programa *x = y->esquerda;
  Programa *T2 = x->direita;

  x->direita = y;
  y->esquerda = T2;

  y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1;
  x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1;

  return x;
}

static Programa *rotacaoEsquerda(Programa *x)
{
  Programa *y = x->direita;
  Programa *T2 = y->esquerda;

  y->esquerda = x;
  x->direita = T2;

  x->altura = maior(altura(x->esquerda), altura(x->direita)) + 1;
  y->altura = maior(altura(y->esquerda), altura(y->direita)) + 1;

  return y;
}

Programa *inserirProgramaNaArvore(Programa *raiz, const char nome[], const char periodicidade[], int tempo, int horario, const char tipo[], const char apresentador[])
{
  Programa *resultado = NULL;

  if (raiz == NULL)
  {
    Programa *novoPrograma = (Programa *)malloc(sizeof(Programa));
    if (novoPrograma == NULL)
    {
      exit(1);
    }

    strcpy(novoPrograma->nome, nome);
    strcpy(novoPrograma->periodicidade, periodicidade);
    novoPrograma->tempoMinutos = tempo;
    novoPrograma->horarioInicio = horario;
    strcpy(novoPrograma->tipo, tipo);
    strcpy(novoPrograma->nomeApresentador, apresentador);
    novoPrograma->esquerda = NULL;
    novoPrograma->direita = NULL;

    novoPrograma->altura = 1;

    resultado = novoPrograma;
  }
  else
  {
    int comparacao = strcmp(nome, raiz->nome);
    if (comparacao < 0)
    {
      raiz->esquerda = inserirProgramaNaArvore(raiz->esquerda, nome, periodicidade, tempo, horario, tipo, apresentador);
    }
    else if (comparacao > 0)
    {
      raiz->direita = inserirProgramaNaArvore(raiz->direita, nome, periodicidade, tempo, horario, tipo, apresentador);
    }

    raiz->altura = 1 + maior(altura(raiz->esquerda), altura(raiz->direita));

    int fatorBalanceamento = fatorDeBalanceamento(raiz);

    resultado = raiz;

    if (fatorBalanceamento > 1 && strcmp(nome, raiz->esquerda->nome) < 0)
    {
      resultado = rotacaoDireita(raiz);
    }

    else if (fatorBalanceamento < -1 && strcmp(nome, raiz->direita->nome) > 0)
    {
      resultado = rotacaoEsquerda(raiz);
    }

    else if (fatorBalanceamento > 1 && strcmp(nome, raiz->esquerda->nome) > 0)
    {
      raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
      resultado = rotacaoDireita(raiz);
    }

    else if (fatorBalanceamento < -1 && strcmp(nome, raiz->direita->nome) < 0)
    {
      raiz->direita = rotacaoDireita(raiz->direita);
      resultado = rotacaoEsquerda(raiz);
    }
  }

  return resultado;
}

Programa *buscarPrograma(Programa *raiz, const char nome[])
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

Programa *removerProgramaDaArvore(Programa *raiz, const char nome[])
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

      if (raiz->esquerda == NULL)
      {
        Programa *temp = raiz->direita;
        free(raiz);
        resultado = temp;
      }
      else if (raiz->direita == NULL)
      {
        Programa *temp = raiz->esquerda;
        free(raiz);
        resultado = temp;
      }
      else
      {

        Programa *temp = encontrarMenorNo(raiz->direita);

        strncpy(raiz->nome, temp->nome, sizeof(raiz->nome) - 1);
        strncpy(raiz->periodicidade, temp->periodicidade, sizeof(raiz->periodicidade) - 1);
        strncpy(raiz->tipo, temp->tipo, sizeof(raiz->tipo) - 1);
        strncpy(raiz->nomeApresentador, temp->nomeApresentador, sizeof(raiz->nomeApresentador) - 1);
        raiz->tempoMinutos = temp->tempoMinutos;
        raiz->horarioInicio = temp->horarioInicio;

        raiz->direita = removerProgramaDaArvore(raiz->direita, temp->nome);
        resultado = raiz;
      }
    }

    // Se a remoção esvaziou a árvore (ex: era o último nó), o resultado já é NULL.
    // Se não, o resultado aponta para a raiz atual da sub-árvore.
    if (resultado != NULL)
    {
      // --- Bloco de Balanceamento (inalterado, mas agora opera sobre um ponteiro seguro) ---
      resultado->altura = 1 + maior(altura(resultado->esquerda), altura(resultado->direita));

      int fatorBalanceamento = fatorDeBalanceamento(resultado);

      if (fatorBalanceamento > 1 && fatorDeBalanceamento(resultado->esquerda) >= 0)
      {
        resultado = rotacaoDireita(resultado);
      }
      else if (fatorBalanceamento > 1 && fatorDeBalanceamento(resultado->esquerda) < 0)
      {
        resultado->esquerda = rotacaoEsquerda(resultado->esquerda);
        resultado = rotacaoDireita(resultado);
      }
      else if (fatorBalanceamento < -1 && fatorDeBalanceamento(resultado->direita) <= 0)
      {
        resultado = rotacaoEsquerda(resultado);
      }
      else if (fatorBalanceamento < -1 && fatorDeBalanceamento(resultado->direita) > 0)
      {
        resultado->direita = rotacaoDireita(resultado->direita);
        resultado = rotacaoEsquerda(resultado);
      }
    }
  }

  return resultado;
}

int contarProgramasNaArvore(Programa *raiz)
{
  if (raiz == NULL)
    return 0;
  return 1 + contarProgramasNaArvore(raiz->esquerda) + contarProgramasNaArvore(raiz->direita);
}