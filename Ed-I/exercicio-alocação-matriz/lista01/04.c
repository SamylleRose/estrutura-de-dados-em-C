#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz_2_mallocs(int m, int n)
{
  int **matriz = (int **)malloc(m * sizeof(int *));
  matriz[0] = (int *)malloc(m * n * sizeof(int));

  for (int i = 1; i < m; i++)
  {
    matriz[i] = matriz[0] + i * n;
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

  int **matriz = alocar_matriz_2_mallocs(m, n);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Digite o valor para a posição [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  printf("Matriz preenchida:\n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  free(matriz[0]);
  free(matriz);

  return 0;
}