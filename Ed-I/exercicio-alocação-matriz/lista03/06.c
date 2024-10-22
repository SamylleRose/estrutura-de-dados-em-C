#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vetor = (int *)malloc(1500 * sizeof(int));

  for (int i = 0; i < 1500; i++)
  {
    vetor[i] = i;
  }

  printf("Primeiras 10 posições: ");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  printf("Últimas 10 posições: ");
  for (int i = 1490; i < 1500; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  free(vetor);
  return 0;
}
