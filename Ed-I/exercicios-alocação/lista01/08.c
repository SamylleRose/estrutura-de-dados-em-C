#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, *vet;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Valor vet[%d]: ", i);
    scanf("%d", &vet[i]);
  }

  int inicio = 0;
  int fim = n - 1;
  int temp;

  while (inicio < fim)
  {
    temp = vet[inicio];
    vet[inicio] = vet[fim];
    vet[fim] = temp;

    inicio++;
    fim--;
  }

  printf("Vetor invertido:");

  for (int i = 0; i < n; i++)
  {

    printf("%d ", vet[i]);
  }
  free(vet);

  return 0;
}