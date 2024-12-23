
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "global.h"

int gerarId()
{
  // Gera um numero entre 100 e 999
  return (rand() % 900) + 100;
}
// Função para garantir que a entrada é um número inteiro
int obterInteiro()
{
  char input[20];
  int valor;

  while (1)
  {
    fgets(input, sizeof(input), stdin);

    // Tenta converter a entrada para inteiro
    if (sscanf(input, "%d", &valor) == 1)
    {
      return valor;
    }
    else
    {
      printf("Entrada inválida. Por favor, insira um número: ");
    }
  }
}