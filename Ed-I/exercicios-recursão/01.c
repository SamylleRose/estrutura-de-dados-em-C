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
  else
  {
    return 1 / potencia(x, -y);
  }
}

int main()
{
  int x;
  int y;

  printf("Digite o valor x: ");
  scanf("%d", &x);
  printf("Digite o valor y: ");
  scanf("%d", &y);

  potencia(x, y);

  return 0;
}