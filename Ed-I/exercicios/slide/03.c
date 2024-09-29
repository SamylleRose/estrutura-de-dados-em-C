#include <stdio.h>
#include <math.h>

double media_harmonica(double *dados, int n)
{
  double soma = 0.0;
  for (int i = 0; i < n; i++)
  {
    soma += 1.0 / dados[i];
  }
  return n / soma;
}

double media_geometrica(double *dados, int n)
{
  double produto = 1.0;
  for (int i = 0; i < n; i++)
  {
    produto *= dados[i];
  }
  return pow(produto, 1.0 / n);
}

double media_ponderada(double *dados, double *pesos, int n)
{
  double soma_pesos = 0.0;
  double soma_ponderada = 0.0;
  for (int i = 0; i < n; i++)
  {
    soma_ponderada += dados[i] * pesos[i];
    soma_pesos += pesos[i];
  }
  return soma_ponderada / soma_pesos;
}

int main()
{
  int n;

  printf("Digite a quantidade de números: ");
  scanf("%d", &n);

  double dados[n], pesos[n];

  printf("Digite os números: \n");
  for (int i = 0; i < n; i++)
  {
    printf("Número %d: ", i + 1);
    scanf("%lf", &dados[i]);
  }

  printf("Digite os pesos: \n");
  for (int i = 0; i < n; i++)
  {
    printf("Peso %d: ", i + 1);
    scanf("%lf", &pesos[i]);
  }

  printf("Média harmônica: %.2lf\n", media_harmonica(dados, n));
  printf("Média geométrica: %.2lf\n", media_geometrica(dados, n));
  printf("Média ponderada: %.2lf\n", media_ponderada(dados, pesos, n));

  return 0;
}
