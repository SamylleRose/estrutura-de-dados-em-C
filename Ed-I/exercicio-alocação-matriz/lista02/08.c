#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *contar_ocorrencias(char *str, char caractere, int *qtd_ocorrencias)
{
  int tamanho = strlen(str);
  int *posicoes = (int *)malloc(tamanho * sizeof(int));
  *qtd_ocorrencias = 0;

  for (int i = 0; i < tamanho; i++)
  {
    if (str[i] == caractere)
    {
      posicoes[(*qtd_ocorrencias)++] = i;
    }
  }

  return posicoes;
}

int main()
{
  char str[100], caractere;
  int qtd_ocorrencias;

  printf("Digite uma string: ");
  scanf("%s", str);
  printf("Digite o caractere a ser contado: ");
  scanf(" %c", &caractere);

  int *posicoes = contar_ocorrencias(str, caractere, &qtd_ocorrencias);

  printf("O caractere '%c' foi encontrado %d vezes nas posições: ", caractere, qtd_ocorrencias);
  for (int i = 0; i < qtd_ocorrencias; i++)
  {
    printf("%d ", posicoes[i]);
  }
  printf("\n");

  free(posicoes);

  return 0;
}
