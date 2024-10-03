#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vet, int n)
{
  int temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (vet[j] > vet[j + 1])
      {

        temp = vet[j];
        vet[j] = vet[j + 1];
        vet[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int n, *vet;

  printf("Digite o tamanho do vet: ");
  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para vet[%d]: ", i);
    scanf("%d", &vet[i]);
  }

  bubbleSort(vet, n);

  printf("vet ordenado: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");

  free(vet);

  return 0;
}
