#include <stdio.h>
#include <stdlib.h>

void percorre_vetor(int *vetor, int tamanho)
{
  int *ptr = vetor;
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", *(ptr + i));
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int *vetor = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    vetor[i] = i + 1;
  }

  percorre_vetor(vetor, n);

  free(vetor);
  return 0;
}
