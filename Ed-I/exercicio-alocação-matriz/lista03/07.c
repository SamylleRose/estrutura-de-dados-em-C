#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vetor = NULL;
  int n = 0, valor;

  while (1)
  {
    printf("Digite um valor (negativo para parar): ");
    scanf("%d", &valor);
    if (valor < 0)
      break;

    vetor = (int *)realloc(vetor, (n + 1) * sizeof(int));
    vetor[n] = valor;
    n++;
  }

  printf("Valores digitados: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  free(vetor);
  return 0;
}
