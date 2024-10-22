#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, soma_impares = 0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int *vetor = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%d", &vetor[i]);
  }

  printf("Vetor lido:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
    if (vetor[i] % 2 != 0)
    {
      soma_impares += vetor[i];
    }
  }
  printf("\n");

  printf("Soma dos números ímpares: %d\n", soma_impares);

  free(vetor);
  return 0;
}
