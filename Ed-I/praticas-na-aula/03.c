#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  int linhas, colunas, linha_central, coluna_central, raio;
  int **mat;

  // Alocar as linhas
  printf("Digite o numero de linhas: ");
  scanf("%d", &linhas);
  mat = (int **)malloc(sizeof(int *) * linhas);

  // Alocar as colunas
  printf("Digite o numero de colunas: ");
  scanf("%d", &colunas);
  for (int i = 0; i < linhas; i++)
    mat[i] = (int *)calloc(colunas, sizeof(int));

  // Verificar se alocacao funcionou
  if (!mat)
  {
    printf("Alocacao falhou");
    exit(1);
  }

  // pontos centrais
  linha_central = linhas / 2;
  coluna_central = colunas / 2;
  raio = linhas;

  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      float distancia = ((i - linha_central) * (i - linha_central)) + ((j - coluna_central) * (j - coluna_central));
      if (distancia <= raio)
      {

        mat[i][j] = 1;
      }
    }
  }

  printf("%d, %d, raio %d\n", linha_central, coluna_central, raio);

  // printar a matriz
  printf("Matriz gerada:\n");
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}