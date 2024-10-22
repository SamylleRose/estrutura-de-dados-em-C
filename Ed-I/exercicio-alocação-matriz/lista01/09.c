#include <stdio.h>

float *multiplica_terca_parte(float *V, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    V[i] *= (1.0 / 3.0);
  }
  return V;
}

int main()
{
  float V[10];
  for (int i = 0; i < 10; i++)
  {
    printf("Digite o valor para a posição %d: ", i);
    scanf("%f", &V[i]);
  }

  multiplica_terca_parte(V, 10);

  printf("Vetor após a multiplicação por 1/3:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%.2f ", V[i]);
  }
  printf("\n");

  return 0;
}
