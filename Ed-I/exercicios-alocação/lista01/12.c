#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, *vet01, *vet02, dot_product = 0;

  printf("Digite o tamanho dos vetores: ");
  scanf("%d", &n);

  vet01 = (int *)malloc(n * sizeof(int));
  vet02 = (int *)malloc(n * sizeof(int));

  if (vet01 == NULL || vet02 == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  printf("Preenchendo o primeiro vetor:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para vet01[%d]: ", i);
    scanf("%d", &vet01[i]);
  }

  printf("Preenchendo o segundo vetor:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para vet02[%d]: ", i);
    scanf("%d", &vet02[i]);
  }

  for (int i = 0; i < n; i++)
  {
    dot_product += vet01[i] * vet02[i];
  }

  printf("O produto escalar é: %d\n", dot_product);

  free(vet01);
  free(vet02);

  return 0;
}
