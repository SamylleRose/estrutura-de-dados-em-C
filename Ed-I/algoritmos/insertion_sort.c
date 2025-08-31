#include <stdio.h>

// Função para executar o Insertion Sort
void insertionSort(int array[], int tamanho)
{
  for (int i = 1; i < tamanho; i++)
  {
    int chave = array[i];
    int j = i - 1;

    // Move os elementos maiores que a chave uma posição à frente
    while (j >= 0 && array[j] > chave)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = chave;
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
  int dados[] = {9, 5, 1, 4, 3};
  int tamanho = sizeof(dados) / sizeof(dados[0]);

  printf("Array antes da ordenação:\n");
  imprimirArray(dados, tamanho);

  insertionSort(dados, tamanho);

  printf("Array após a ordenação:\n");
  imprimirArray(dados, tamanho);

  return 0;
}
