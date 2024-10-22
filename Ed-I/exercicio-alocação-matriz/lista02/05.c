#include <stdio.h>
#include <stdlib.h>

int **multiplica_vetores(int *v1, int *v2, int q1, int q2)
{
  int **matriz = (int **)malloc(q1 * sizeof(int *));
  for (int i = 0; i < q1; i++)
  {
    matriz[i] = (int *)malloc(q2 * sizeof(int));
    for (int j = 0; j < q2; j++)
    {
      matriz[i][j] = v1[i] * v2[j];
    }
  }
  return matriz;
}

int main()
{
  int q1 = 3, q2 = 4;
  int *v1 = (int *)malloc(q1 * sizeof(int));
  int *v2 = (int *)malloc(q2 * sizeof(int));

  for (int i = 0; i < q1; i++)
  {
    v1[i] = i + 1;
  }
  for (int i = 0; i < q2; i++)
  {
    v2[i] = i + 10;
  }

  int **matriz = multiplica_vetores(v1, v2, q1, q2);

  for (int i = 0; i < q1; i++)
  {
    for (int j = 0; j < q2; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < q1; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
  free(v1);
  free(v2);

  return 0;
}
