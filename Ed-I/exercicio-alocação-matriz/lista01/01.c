#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int *vet, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor do elemento %d: ", i + 1);
    scanf("%d", &vet[i]);
  }
}

int main()
{

  int n;
  int *vet;

  printf("Digite o número de elementos do vetor: ");
  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));

  if (vet == NULL)
  {
    printf("Erro na alocação de memória.\n");
    return 1;
  }

  ler_vetor(vet, n);

  printf("Vetor preenchido: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vet[i]);
  }

  printf("\n");

  free(vet);

  return 0;
}