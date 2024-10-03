#include <stdio.h>

void inverter(int *vet, int tamanho)
{

  int inicio = 0;
  int fim = tamanho - 1;
  int temp;

  while (inicio < fim)
  {
    temp = vet[inicio];
    vet[inicio] = vet[fim];
    vet[fim] = temp;

    inicio++;
    fim--;
  }
}

int main()
{
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int tamanho = 9;

  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vet[i]);
  }

  inverter(vet, tamanho);

  printf("\n");

  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vet[i]);
  }
}