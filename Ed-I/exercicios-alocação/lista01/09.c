#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int n;
  char **vet;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &n);

  vet = (char **)malloc(n * sizeof(char *));

  if (vet == NULL)
  {
    printf("Erro de alocação de memória!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    vet[i] = (char *)malloc(100 * sizeof(char));
    printf("Escreva as strings do vet[%d]: ", i);
    scanf("%s", vet[i]);
  }

  printf("String: ");
  for (int i = 0; i < n; i++)
  {
    printf("%s ", vet[i]);
    free(vet[i]);
  }

  free(vet);

  return 0;
}