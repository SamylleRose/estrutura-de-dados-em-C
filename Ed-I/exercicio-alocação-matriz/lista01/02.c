#include <stdio.h>
#include <stdlib.h>

int *criar_vetor(int n)
{
  int *vetor = (int *)malloc(n * sizeof(int));

  if (vetor == NULL)
  {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }
  return vetor;
}

void imprimir_vetor(int *vetor, int n)
{
  printf("Vetor preenchido: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

void liberar_vetor(int *vetor)
{
  free(vetor);
}

int main()
{
  int n;
  int *vetor;

  printf("Digite o número de elementos do vetor: ");
  scanf("%d", &n);

  vetor = criar_vetor(n);

  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor do elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  imprimir_vetor(vetor, n);

  liberar_vetor(vetor);

  return 0;
}
