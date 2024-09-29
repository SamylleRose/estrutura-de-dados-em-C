#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontrar_indices(char *str, char letra, int *tamanho_vetor, int *posicoes)
{
  int contador = 0;

  for (int i = 0; i < *tamanho_vetor; i++)
  {
    if (str[i] == letra)
    {
      posicoes[contador] = i;
      contador++;
    }
  }

  *tamanho_vetor = contador;
}

int main()
{
  char string[] = "programacao em C";
  char letra = 'a';
  int tamanho_vetor = sizeof(string) - 1;
  int posicoes[100];

  encontrar_indices(string, letra, &tamanho_vetor, posicoes);

  if (tamanho_vetor > 0)
  {
    printf("A letra '%c' foi encontrada nas posições: ", letra);
    for (int i = 0; i < tamanho_vetor; i++)
    {
      printf("%d ", posicoes[i]);
    }
    printf("\nTotal de ocorrências: %d\n", tamanho_vetor);
  }
  else
  {
    printf("A letra '%c' não foi encontrada.\n", letra);
  }

  return 0;
}
