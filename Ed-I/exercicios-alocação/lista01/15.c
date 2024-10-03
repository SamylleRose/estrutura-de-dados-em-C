#include <stdio.h>
#include <stdlib.h>

void uniao(int *vet1, int n1, int *vet2, int n2)
{
  int *result = (int *)malloc((n1 + n2) * sizeof(int));
  int size = 0;

  for (int i = 0; i < n1; i++)
  {
    result[size++] = vet1[i];
  }

  for (int i = 0; i < n2; i++)
  {
    int exists = 0;
    for (int j = 0; j < n1; j++)
    {
      if (vet2[i] == vet1[j])
      {
        exists = 1;
        break;
      }
    }
    if (!exists)
    {
      result[size++] = vet2[i];
    }
  }

  printf("União: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");

  free(result);
}

void interseccao(int *vet1, int n1, int *vet2, int n2)
{
  int *result = (int *)malloc((n1 < n2 ? n1 : n2) * sizeof(int));
  int size = 0;

  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++)
    {
      if (vet1[i] == vet2[j])
      {
        result[size++] = vet1[i];
        break;
      }
    }
  }

  printf("Interseção: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");

  free(result);
}

int main()
{
  int n1, n2, *vet1, *vet2;

  printf("Digite o size do primeiro vetor: ");
  scanf("%d", &n1);
  printf("Digite o size do segundo vetor: ");
  scanf("%d", &n2);

  vet1 = (int *)malloc(n1 * sizeof(int));
  vet2 = (int *)malloc(n2 * sizeof(int));

  if (vet1 == NULL || vet2 == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  printf("Preenchendo o primeiro vetor:\n");
  for (int i = 0; i < n1; i++)
  {
    printf("Digite o valor para vet1[%d]: ", i);
    scanf("%d", &vet1[i]);
  }

  printf("Preenchendo o segundo vetor:\n");
  for (int i = 0; i < n2; i++)
  {
    printf("Digite o valor para vet2[%d]: ", i);
    scanf("%d", &vet2[i]);
  }

  uniao(vet1, n1, vet2, n2);
  interseccao(vet1, n1, vet2, n2);

  free(vet1);
  free(vet2);

  return 0;
}
