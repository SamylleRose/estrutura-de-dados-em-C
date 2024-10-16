#include <stdio.h>

int soma_linear(int size, int *vet)
{

  if (size == 0)
  {
    return vet[0];
  }

  return vet[size - 1] + soma_linear(vet, size - 1);
}

int main()
{

  int size = 5;
  int vet[] = {1, 2, 3, 4, 5};

  soma_linear(size, vet);

  return 0;
}