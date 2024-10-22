#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int linhas, int colunas)
{
  int **matriz = (int **)malloc(linhas * sizeof(int *));
  for (int i = 0; i < linhas; i++)
  {
    matriz[i] = (int *)malloc(colunas * sizeof(int));
  }
  return matriz;
}

void libera_matriz(int **matriz, int linhas)
{
  for (int i = 0; i < linhas; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
}

void preenche_matriz(int **matriz, int linhas, int colunas)
{
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      printf("Digite o valor para [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void imprime_matriz(int **matriz, int linhas, int colunas)
{
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int **transpor_matriz(int **matriz, int linhas, int colunas)
{
  int **transposta = aloca_matriz(colunas, linhas);
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      transposta[j][i] = matriz[i][j];
    }
  }
  return transposta;
}

int main()
{
  int linhas, colunas;
  printf("Digite o número de linhas: ");
  scanf("%d", &linhas);
  printf("Digite o número de colunas: ");
  scanf("%d", &colunas);

  int **matriz = aloca_matriz(linhas, colunas);

  preenche_matriz(matriz, linhas, colunas);

  printf("Matriz original:\n");
  imprime_matriz(matriz, linhas, colunas);

  int **transposta = transpor_matriz(matriz, linhas, colunas);

  printf("Matriz transposta:\n");
  imprime_matriz(transposta, colunas, linhas);

  libera_matriz(matriz, linhas);
  libera_matriz(transposta, colunas);

  return 0;
}
