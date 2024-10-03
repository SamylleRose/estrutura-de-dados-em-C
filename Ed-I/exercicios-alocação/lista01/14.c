#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, *vet, *frequency;

  printf("Digite o tamanho do vet: ");
  scanf("%d", &n);

  vet = (int *)malloc(n * sizeof(int));
  frequency = (int *)calloc(n, sizeof(int));

  if (vet == NULL || frequency == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para vet[%d]: ", i);
    scanf("%d", &vet[i]);
  }

  for (int i = 0; i < n; i++)
  {
    int count = 1;
    if (frequency[i] == 0)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (vet[i] == vet[j])
        {
          count++;
          frequency[j] = -1;
        }
      }
      printf("O número %d aparece %d vez(es)\n", vet[i], count);
    }
  }

  free(vet);
  free(frequency);

  return 0;
}
