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
    printf("Valor vet[%d]: ", i);
    scanf("%d", &vet[i]);
  }
  int sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += vet[i];
  }

  printf("Soma: %d ", sum);
  free(vet);

  return 0;
}