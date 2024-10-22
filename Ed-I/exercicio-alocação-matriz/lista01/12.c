#include <stdio.h>
#include <stdlib.h>

int *valores_entre_min_max(int *V, int n, int min, int max, int *tamanho_resultado)
{
  int *resultado = (int *)malloc(n * sizeof(int));
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (V[i] >= min && V[i] <= max)
    {
      resultado[count++] = V[i];
    }
  }

  *tamanho_resultado = count;
  return resultado;
}

int main()
{
  int n, min, max;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int *V = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%d", &V[i]);
  }

  printf("Digite o valor mínimo: ");
  scanf("%d", &min);
  printf("Digite o valor máximo: ");
  scanf("%d", &max);

  int tamanho_resultado;
  int *resultado = valores_entre_min_max(V, n, min, max, &tamanho_resultado);

  printf("Valores entre %d e %d:\n", min, max);
  for (int i = 0; i < tamanho_resultado; i++)
  {
    printf("%d ", resultado[i]);
  }
  printf("\n");

  free(V);
  free(resultado);
  return 0;
}
