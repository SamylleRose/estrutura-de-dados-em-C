#include <stdio.h>

// Função para executar o Bubble Sort
void bubbleSort(int array[], int tamanho)
{
  for (int i = 0; i < tamanho - 1; i++)
  {
    // Flag para verificar se houve troca
    int trocou = 0;

    // Percorre o array e faz as trocas necessárias
    for (int j = 0; j < tamanho - i - 1; j++)
    {

      if (array[j] > array[j + 1])
      {
        // Troca os elementos
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        trocou = 1;
      }
    }

    // Se não houve troca, o array já está ordenado
    if (trocou == 0)
    {
      break;
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
  int dados[] = {64, 34, 25, 12, 22, 11, 90};
  int tamanho = sizeof(dados) / sizeof(dados[0]);

  printf("Array antes da ordenação:\n");
  imprimirArray(dados, tamanho);

  bubbleSort(dados, tamanho);

  printf("Array após a ordenação:\n");
  imprimirArray(dados, tamanho);

  return 0;
}
