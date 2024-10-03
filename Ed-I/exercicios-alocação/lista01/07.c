#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, m, *vet01, *vet02, *vet_concatenado;

  printf("Informe o tamanho do vetor 01: ");
  scanf("%d", &n);

  printf("Informe o tamanho do vetor 02: ");
  scanf("%d", &m);

  vet01 = (int *)malloc(n * sizeof(int));
  vet02 = (int *)malloc(m * sizeof(int));

  if (vet01 == NULL || vet02 == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Valor vet01[%d]: ", i);
    scanf("%d", &vet01[i]);
  }

  for (int i = 0; i < m; i++)
  {
    printf("Valor vet02[%d]: ", i);
    scanf("%d", &vet02[i]);
  }

  vet_concatenado = (int *)malloc((n + m) * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    vet_concatenado[i] = vet01[i];
  }

  for (int i = 0; i < n; i++)
  {
    vet_concatenado[n + i] = vet02[i];
  }

  printf("Vetor Concatenado: ");
  for (int i = 0; i < (n + m); i++)
  {
    printf("%d ", vet_concatenado[i]);
  }

  free(vet01);
  free(vet02);
  free(vet_concatenado);

  return 0;
}