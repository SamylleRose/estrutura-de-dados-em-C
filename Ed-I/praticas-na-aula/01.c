#include <stdlib.h>
#include <stdio.h>

float calcular_media(float *vet, int tamanho)
{
  float soma = 0;
  float media = 0;

  for (int i = 0; i < tamanho; i++)
  {
    soma += vet[i];
  }

  media = soma / tamanho;

  return media;
}

float calcular_variancia() {}
int main()
{
  int tamanho = 100;
  float vet[tamanho];

  for (int i = 0; i < tamanho; i++)
  {
    vet[i] = rand() % tamanho;
  }

  float media = calcular_media(vet, tamanho);
  float variancia = calcular_variancia();

  // for( int i = 0; i < tamanho; i++){

  //   printf("%.2f\n",vet[i]);
  // }

  printf("%.2f", media);
}