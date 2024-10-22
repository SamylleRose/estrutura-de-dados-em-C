#include <stdio.h>
#include <stdlib.h>

void imprimir_centro_para_fora(int *vetor, int tamanho)
{
  int centro = tamanho / 2;
  printf("%d\n", vetor[centro]);

  for (int i = 1; i <= centro; i++)
  {
    printf("%d %d\n", vetor[centro - i], vetor[centro + i]);
  }
}

int main()
{
  int n;
  printf("Digite o tamanho do vetor (ímpar): ");
  scanf("%d", &n);

  int *vetor = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%d", &vetor[i]);
  }

  imprimir_centro_para_fora(vetor, n);

  free(vetor);
  return 0;
}
