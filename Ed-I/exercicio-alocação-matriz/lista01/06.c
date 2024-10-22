#include <stdio.h>
#include <stdlib.h>

float **criar_matriz_float(int m, int n)
{
  float **matriz = (float **)malloc(m * sizeof(float *));
  for (int i = 0; i < m; i++)
  {
    matriz[i] = (float *)malloc(n * sizeof(float));
  }
  return matriz;
}

int main()
{
  int m, n;
  printf("Digite o número de linhas da matriz (m): ");
  scanf("%d", &m);
  printf("Digite o número de colunas da matriz (n): ");
  scanf("%d", &n);

  float **matriz = criar_matriz_float(m, n);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Digite o valor para a posição [%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  printf("Matriz preenchida:\n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < m; i++)
  {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}