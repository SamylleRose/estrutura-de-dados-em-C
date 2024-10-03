#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, *vet, position;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para vetor[%d]: ", i);
    scanf("%d", &vet[i]);
  }

  printf("Digite a posição do elemento a ser removido (0 a %d): ", n - 1);
  scanf("%d", &position);

  for (int i = position; i < n - 1; i++)
  {
    vet[i] = vet[i + 1];
  }

  n--;

  printf("Vetor após a remoção: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");

  free(vet);

  return 0;
}