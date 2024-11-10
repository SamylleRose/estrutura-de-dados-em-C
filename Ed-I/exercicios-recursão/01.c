#include <stdio.h>

double potencia(int x, int y)
{
  if (y == 0)
  {
    return 1;
  }
  else if (y > 0)
  {
    return x * potencia(x, y - 1);
  }
}

int main()
{
  int x;
  int y;
  int result;

  printf("Digite o valor x: ");
  scanf("%d", &x);
  printf("Digite o valor y: ");
  scanf("%d", &y);

  result = potencia(x, y);

  printf("Resultado: %d\n", result);

  return 0;
}