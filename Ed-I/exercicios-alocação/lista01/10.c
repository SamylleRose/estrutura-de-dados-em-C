#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vet, size = 2, amount = 0, value;

  vet = (int *)malloc(size * sizeof(int));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  while (1)
  {
    printf("Digite um value (ou -1 para sair): ");
    scanf("%d", &value);
    if (value == -1)
    {
      break;
    }

    if (amount == size)
    {
      size *= 2;
      vet = (int *)realloc(vet, size * sizeof(int));
      if (vet == NULL)
      {
        printf("Erro de realocação de memória!\n");
        return 1;
      }
    }

    vet[amount] = value;
    amount++;
  }

  printf("valores armazenados: ");
  for (int i = 0; i < amount; i++)
  {
    printf("%d ", vet[i]);
  }

  free(vet);
  return 0;
}
