#include <stdio.h>

void velocidade_media(float *velocidade, float *tempo, float *espaco)
{

  *velocidade = *espaco / *tempo;
}
void tempo_percorrido(float *velocidade, float *tempo, float *espaco)
{
  *tempo = *espaco / *velocidade;
}
void espaco_percorrido(float *velocidade, float *tempo, float *espaco)
{
  *espaco = *velocidade * *tempo;
}

int main()
{
  float velocidade;
  float tempo;
  float espaco;
  float distancia;

  int codigo = 0;

  while (codigo != 4)
  {

    printf("--------menu--------\n");
    printf("1- Velocidade média\n");
    printf("2- Tempo\n");
    printf("3- Espaço\n");
    printf("4- Sair\n\n");

    printf("Digite um código: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:
      printf("Informe o espaço: ");
      scanf("%f", &espaco);
      printf("Informe o tempo: ");
      scanf("%f", &tempo);

      velocidade_media(&velocidade, &tempo, &espaco);

      printf("Velocidade média: %.2f\n", velocidade);
      break;

    case 2:
      printf("Informe o espaço: ");
      scanf("%f", &espaco);
      printf("Informe o velocidade média: ");
      scanf("%f", &velocidade);

      tempo_percorrido(&velocidade, &tempo, &espaco);

      printf("Tempo: %.2f\n", tempo);
      break;

    case 3:
      printf("Informe o tempo: ");
      scanf("%f", &tempo);
      printf("Informe o velocidade média: ");
      scanf("%f", &velocidade);

      espaco_percorrido(&velocidade, &tempo, &espaco);

      printf("Espaço: %.2f\n", espaco);
      break;

    case 4:
      printf("Saiando...");
      break;

    default:
      printf("Codigo incorreto!\n");

      break;
    }
  }
  return 0;
}