#include <stdio.h>
#include <stdlib.h>

int *aloca_vetor(int n)
{
  return (int *)malloc(n * sizeof(int));
}

void libera_vetor(int *vetor)
{
  free(vetor);
}

void imprime_vetor(int *vetor, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int *vetor = aloca_vetor(n);
  for (int i = 0; i < n; i++)
  {
    vetor[i] = i + 1;
  }

  imprime_vetor(vetor, n);
  libera_vetor(vetor);

  return 0;
}
