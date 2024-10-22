#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int m, int n)
{
  int **matriz = (int **)malloc(m * sizeof(int *));
  matriz[0] = (int *)malloc(m * n * sizeof(int));
  for (int i = 1; i < m; i++)
  {
    matriz[i] = matriz[0] + i * n;
  }
  return matriz;
}

void libera_matriz(int **matriz)
{
  free(matriz[0]);
  free(matriz);
}

int main()
{
  int m = 3, n = 4;
  int **matriz = aloca_matriz(m, n);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matriz[i][j] = i + j;
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  libera_matriz(matriz);

  return 0;
}
