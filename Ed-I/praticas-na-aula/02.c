#include <stdlib.h>
#include <stdio.h>

// Programa que gera uma matriz randômica e conta as ocorrências de cada número gerado

int main()
{
  int **mat, linhas, colunas, *repetidos;
  int max_valor = 0;

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

  // Preencher a matriz com valores aleatórios e encontrar o maior valor
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      mat[i][j] = rand() % 50;
      if (mat[i][j] > max_valor)
        max_valor = mat[i][j];
    }
  }

  // Imprimir a matriz
  printf("Matriz gerada:\n");
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  // Alocar o vetor repetidos dinamicamente com o tamanho do maior valor encontrado + 1
  repetidos = (int *)calloc(max_valor + 1, sizeof(int));
  if (!repetidos)
  {
    printf("Falha na alocacao de memoria para repetidos");
    exit(1);
  }

  // Contar as ocorrências de cada elemento
  for (int i = 0; i < linhas; i++)
    for (int j = 0; j < colunas; j++)
      repetidos[mat[i][j]]++;

  // Imprimir os valores com suas respectivas ocorrências
  printf("\nOcorrências de cada valor:\n");
  for (int i = 0; i <= max_valor; i++)
    if (repetidos[i] > 0)
      printf("O valor %d ocorreu %d vez(es)\n", i, repetidos[i]);

  // Liberar memória
  for (int i = 0; i < linhas; i++)
    free(mat[i]);
  free(mat);
  free(repetidos);

  return 0;
}
