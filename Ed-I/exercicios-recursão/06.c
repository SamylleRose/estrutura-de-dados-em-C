#include <stdio.h>

void imprimir_numeros(int n)
{

  if (n < 1)
  {
    return;
  }

  printf("%d ", n);

  imprimir_numeros(n - 1);
}

int main()
{
  int n;

  printf("Digite um número natural: ");
  scanf("%d", &n);

  printf("Números de %d até 1:\n", n);
  imprimir_numeros(n);

  printf("\n");
  return 0;
}
