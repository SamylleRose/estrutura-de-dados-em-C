#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n)
{
  int numero;
  for (int i = 0; i < n; i++)
  {
    do
    {
      printf("Digite o número %d da aposta (entre 0 e 100): ", i + 1);
      scanf("%d", &numero);
    } while (numero < 0 || numero > 100);
    aposta[i] = numero;
  }
}

void sorteia_valores(int *sorteio, int n)
{
  srand(time(NULL));

  for (int i = 0; i < n; i++)
  {
    sorteio[i] = rand() % 101;
  }
}

int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
  int *acertos = (int *)malloc(na * sizeof(int));
  *qtdacertos = 0;

  for (int i = 0; i < na; i++)
  {
    for (int j = 0; j < ns; j++)
    {
      if (aposta[i] == sorteio[j])
      {
        acertos[(*qtdacertos)++] = aposta[i];
        break;
      }
    }
  }

  return acertos;
}

int main()
{
  int na;
  int ns = 20;
  int qtdacertos;

  do
  {
    printf("Digite a quantidade de números que deseja apostar (entre 1 e 20): ");
    scanf("%d", &na);
  } while (na < 1 || na > 20);

  int *aposta = (int *)malloc(na * sizeof(int));
  int *sorteio = (int *)malloc(ns * sizeof(int));

  ler_aposta(aposta, na);

  sorteia_valores(sorteio, ns);

  int *acertos = compara_aposta(aposta, sorteio, &qtdacertos, na, ns);

  printf("Números sorteados: ");
  for (int i = 0; i < ns; i++)
  {
    printf("%d ", sorteio[i]);
  }
  printf("\n");

  if (qtdacertos > 0)
  {
    printf("Você acertou %d número(s): ", qtdacertos);
    for (int i = 0; i < qtdacertos; i++)
    {
      printf("%d ", acertos[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Você não acertou nenhum número.\n");
  }

  free(aposta);
  free(sorteio);
  free(acertos);

  return 0;
}
