#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, *vet;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    vet[i] = i + 1;
  }

  printf("Vetor: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vet[i]);
  }

  free(vet);

  return 0;
}