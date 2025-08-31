#include <stdio.h>

// Função para executar o Selection Sort
void selectionSort(int array[], int tamanho)
{
  for (int i = 0; i < tamanho - 1; i++)
  {
    int indiceMin = i;

    // Encontra o menor elemento no restante do array
    for (int j = i + 1; j < tamanho; j++)
    {
      if (array[j] < array[indiceMin])
      {
        indiceMin = j;
      }
    }

    // Troca o elemento atual com o menor encontrado
    if (indiceMin != i)
    {
      int temp = array[i];
      array[i] = array[indiceMin];
      array[indiceMin] = temp;
    }
  }
}

// Função para imprimir o array
void imprimirArray(int array[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Função principal
int main()
{
  int dados[] = {29, 10, 14, 37, 13};
  int tamanho = sizeof(dados) / sizeof(dados[0]);

  printf("Array antes da ordenação:\n");
  imprimirArray(dados, tamanho);

  selectionSort(dados, tamanho);

  printf("Array após a ordenação:\n");
  imprimirArray(dados, tamanho);

  return 0;
}
