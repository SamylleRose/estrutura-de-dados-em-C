#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ***alocarCubo(int profundidade, int linhas, int colunas)
{
  int ***cubo;

  cubo = (int ***)calloc(profundidade, sizeof(int **));

  for (int i = 0; i < profundidade; i++)
    cubo[i] = (int **)calloc(linhas, sizeof(int *));

  for (int i = 0; i < profundidade; i++)
    for (int j = 0; j < linhas; j++)
      cubo[i][j] = (int *)calloc(colunas, sizeof(int));

  return cubo;
}

void preencherCubo(int ***cubo, int profundidade, int linhas, int colunas, int range)
{
  for (int i = 0; i < profundidade; i++)
    for (int j = 0; j < linhas; j++)
      for (int k = 0; k < colunas; k++)
        cubo[i][j][k] = rand() % range;
}

void mostrarCubo(int ***cubo, int profundidade, int linhas, int colunas)
{
  for (int i = 0; i < profundidade; i++)
  {
    printf("Plano %d\n", i);
    for (int j = 0; j < linhas; j++)
    {
      for (int k = 0; k < colunas; k++)
        printf("%d ", cubo[i][j][k]);
      printf("\n");
    }
    printf("\n");
  }
}

void calcularEsferainscrita(int ***cubo, int profundidade, int linhas, int colunas, int centro_cubo)
{
  int raio = centro_cubo;
  for (int i = 0; i < profundidade; i++)
  {
    for (int j = 0; j < linhas; j++)
    {
      for (int k = 0; k < colunas; k++)
      {

        int dx = i - centro_cubo;
        int dy = j - centro_cubo;
        int dz = k - centro_cubo;
        double distancia = sqrt(dx * dx + dy * dy + dz * dz);

        if (distancia <= raio)
          cubo[i][j][k] = 1;
        else
          cubo[i][j][k] = 0;
      }
    }
  }
}

void liberarCubo(int ***cubo, int profundidade, int linhas, int colunas)
{
  for (int i = 0; i < profundidade; i++)
  {
    for (int j = 0; j < linhas; j++)
      free(cubo[i][j]);

    free(cubo[i]);
  }
  free(cubo);
}

int main()
{
  int ***cubo, profundidade = 3, linhas = 3, colunas = 3;

  profundidade = linhas = colunas = 11;
  cubo = alocarCubo(profundidade, linhas, colunas);
  preencherCubo(cubo, profundidade, linhas, colunas, 100);
  // mostrarCubo(cubo, profundidade, linhas, colunas);

  calcularEsferainscrita(cubo, profundidade, linhas, colunas, linhas / 2);

  mostrarCubo(cubo, profundidade, linhas, colunas);

  liberarCubo(cubo, profundidade, linhas, colunas);

  return 0;
}