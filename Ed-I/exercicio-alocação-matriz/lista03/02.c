#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, soma_impares = 0;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);

  int *vetor = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
    if (vetor[i] % 2 != 0)
    {
      soma_impares += vetor[i];
    }
  }

  printf("Elementos do vetor: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\nSoma dos ímpares: %d\n", soma_impares);

  free(vetor);
  return 0;
}
