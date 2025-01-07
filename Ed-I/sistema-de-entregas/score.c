#include <stdio.h>
#include <stdlib.h>

#include "score.h"

Score *criarScore()
{
  return (Score *)malloc(sizeof(Score));
}

Score *entregueNaPrimeiraTentativa(Score *score)
{
  int PRIMEIRA_TENTATIVA_PONTOS = 5;

  score->pontuacao += PRIMEIRA_TENTATIVA_PONTOS;

  return score;
}

Score *entregueNaSegundaTentativa(Score *score)
{
  int SEGUNDA_TENTATIVA_PONTOS = 3;

  score->pontuacao += SEGUNDA_TENTATIVA_PONTOS;

  return score;
}

Score *devolvida(Score *score)
{
  int DEVOLVIDA_PONTOS = -2;

  score->pontuacao += DEVOLVIDA_PONTOS;

  if (score->pontuacao < 0)
  {
    score->pontuacao = 0;
  }

  return score;
}

void mostrarScore(Score *score)
{
  printf("\nScore atual: %d\n", score->pontuacao);
}

Score *liberarMemoriaScore(Score *score)
{
  free(score);

  return NULL;
}