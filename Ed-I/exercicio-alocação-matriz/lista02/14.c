#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char cidade_origem[50];
  char cidade_destino[50];
  char horario[10];
  float preco;
} Passagem;

Passagem **aloca_matriz(int cidades)
{
  Passagem **matriz = (Passagem **)malloc(cidades * sizeof(Passagem *));
  for (int i = 0; i < cidades; i++)
  {
    matriz[i] = (Passagem *)malloc(cidades * sizeof(Passagem));
  }
  return matriz;
}

void libera_matriz(Passagem **matriz, int cidades)
{
  for (int i = 0; i < cidades; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
}

void cadastrar_passagens(Passagem **matriz, int cidades)
{
  for (int i = 0; i < cidades; i++)
  {
    for (int j = 0; j < cidades; j++)
    {
      if (i != j)
      {
        printf("Cadastro da passagem de %d para %d:\n", i + 1, j + 1);
        printf("Origem: ");
        scanf("%s", matriz[i][j].cidade_origem);
        printf("Destino: ");
        scanf("%s", matriz[i][j].cidade_destino);
        printf("Horário: ");
        scanf("%s", matriz[i][j].horario);
        printf("Preço: ");
        scanf("%f", &matriz[i][j].preco);
      }
    }
  }
}

void imprimir_passagens(Passagem **matriz, int cidades)
{
  for (int i = 0; i < cidades; i++)
  {
    for (int j = 0; j < cidades; j++)
    {
      if (i != j)
      {
        printf("Passagem de %s para %s: Horário: %s, Preço: %.2f\n",
               matriz[i][j].cidade_origem, matriz[i][j].cidade_destino,
               matriz[i][j].horario, matriz[i][j].preco);
      }
    }
  }
}

int main()
{
  int cidades;
  printf("Digite o número de cidades que a empresa trabalha: ");
  scanf("%d", &cidades);

  Passagem **matriz_passagens = aloca_matriz(cidades);

  cadastrar_passagens(matriz_passagens, cidades);
  imprimir_passagens(matriz_passagens, cidades);

  libera_matriz(matriz_passagens, cidades);

  return 0;
}
