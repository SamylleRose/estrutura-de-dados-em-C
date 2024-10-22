#include <stdio.h>
#include <stdlib.h>

double **aloca_matriz(int m, int n)
{
  double **matriz = (double **)malloc(m * sizeof(double *));
  for (int i = 0; i < m; i++)
  {
    matriz[i] = (double *)malloc(n * sizeof(double));
  }
  return matriz;
}

void preenche_matriz(double **matriz, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Digite o valor para [%d][%d]: ", i, j);
      scanf("%lf", &matriz[i][j]);
    }
  }
}

void soma_matrizes(double **A, double **B, double **C, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void imprime_matriz(double **matriz, int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int m, n;
  printf("Digite o número de linhas (m) e colunas (n): ");
  scanf("%d %d", &m, &n);

  double **A = aloca_matriz(m, n);
  double **B = aloca_matriz(m, n);
  double **C = aloca_matriz(m, n);

  printf("Preencha a matriz A:\n");
  preenche_matriz(A, m, n);

  printf("Preencha a matriz B:\n");
  preenche_matriz(B, m, n);

  soma_matrizes(A, B, C, m, n);

  printf("Resultado da soma das matrizes A e B:\n");
  imprime_matriz(C, m, n);

  for (int i = 0; i < m; i++)
  {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}
