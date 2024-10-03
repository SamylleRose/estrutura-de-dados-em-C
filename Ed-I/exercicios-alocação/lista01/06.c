#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n, *vet, *novo_vet, size = 0;

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

  novo_vet = (int *)malloc(n * sizeof(int));

  if (novo_vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

    for (int i = 0; i < n; i++)
  {
    int existe = 0;
    for (int j = 0; j < size; j++)
    {
      if (vet[i] == novo_vet[j])
      {
        existe = 1;
        break;
      }
    }
    if (!existe)
    {
      novo_vet[size] = vet[i];
      size++;
    }
  }

  printf("Vetor sem duplicatas: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", novo_vet[i]);
  }

  free(vet);
  free(novo_vet);

  return 0;
}