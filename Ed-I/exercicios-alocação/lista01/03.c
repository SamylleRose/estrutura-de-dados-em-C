#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n;
  float *vet;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &n);

  vet = (float *)malloc(n * sizeof(float));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Valor vet[%d]: ", i);
    scanf("%f", &vet[i]);
  }
  int sum = 0;
  float average = 0;

  for (int i = 0; i < n; i++)
  {
    sum += vet[i];
  }

  average = sum / n;
  printf("Média: %.2f ", average);
  free(vet);

  return 0;
}