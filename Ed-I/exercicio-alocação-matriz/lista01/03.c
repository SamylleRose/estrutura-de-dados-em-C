#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int m, int n)
{
  int **matriz = (int **)malloc(m * sizeof(int *));

  if (matriz == NULL)
  {
    printf("Erro na alocação de memória para as linhas.\n");
    exit(1);
  }

  matriz[0] = (int *)malloc(m * n * sizeof(int));

  if (matriz[0] == NULL)
  {
    printf("Erro na alocação de memória para os elementos da matriz.\n");
    exit(1);
  }

  for (int i = 1; i < m; i++)
  {
    matriz[i] = matriz[0] + i * n;
  }

  return matriz;
}

void liberar_matriz(int **matriz)
{
  free(matriz[0]);
  free(matriz);
}

int main()
{
  int m, n;

  printf("Digite o número de linhas da matriz (m): ");
  scanf("%d", &m);
  printf("Digite o número de colunas da matriz (n): ");
  scanf("%d", &n);

  int **matriz = alocar_matriz(m, n);

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

  liberar_matriz(matriz);

  return 0;
}
