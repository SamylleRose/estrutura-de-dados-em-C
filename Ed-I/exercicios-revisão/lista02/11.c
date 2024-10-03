#include <stdio.h>

int fatorial(int num)
{
  int fat = 1;
  for (int i = 1; i <= num; i++)
  {
    fat *= i;
  }
  return fat;
}

int main()
{
  int n;

  printf("Digite o numero de elementos: ");
  scanf("%d", &n);

  int num[100], fat[100];

  printf("Digite %d numeros inteiros e positivos:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &num[i]);
  }

  for (int i = 0; i < n; i++)
  {
    fat[i] = fatorial(num[i]);
  }

  printf("Numeros e seus fatoriais correspondentes:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Numero: %d, Fatorial: %d\n", num[i], fat[i]);
  }

  return 0;
}
