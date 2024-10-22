#include <stdio.h>
#include <stdlib.h>

void inverter_vetor(int *vetor, int tamanho)
{
  for (int i = 0; i < tamanho / 2; i++)
  {
    int temp = vetor[i];
    vetor[i] = vetor[tamanho - i - 1];
    vetor[tamanho - i - 1] = temp;
  }
}

int main()
{
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int *vetor = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%d", &vetor[i]);
  }

  inverter_vetor(vetor, n);

  printf("Vetor invertido: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  free(vetor);
  return 0;
}
