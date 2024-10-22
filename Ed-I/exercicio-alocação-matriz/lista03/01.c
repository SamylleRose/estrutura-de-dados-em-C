#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int tamanho)
{
  int **matriz = (int **)malloc(tamanho * sizeof(int *));
  for (int i = 0; i < tamanho; i++)
  {
    matriz[i] = (int *)malloc(tamanho * sizeof(int));
  }
  return matriz;
}

void libera_matriz(int **matriz, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
}

int **soma_matrizes(int **A, int **B, int tamanho)
{
  int **C = aloca_matriz(tamanho);
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}

void imprime_matriz(int **matriz, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int tamanho = 5;
  int **A = aloca_matriz(tamanho);
  int **B = aloca_matriz(tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho; j++)
    {
      A[i][j] = i + j;
      B[i][j] = (i + 1) * (j + 1);
    }
  }

  int **C = soma_matrizes(A, B, tamanho);

  printf("Matriz A:\n");
  imprime_matriz(A, tamanho);

  printf("\nMatriz B:\n");
  imprime_matriz(B, tamanho);

  printf("\nSoma (Matriz C):\n");
  imprime_matriz(C, tamanho);

  libera_matriz(A, tamanho);
  libera_matriz(B, tamanho);
  libera_matriz(C, tamanho);

  return 0;
}
