#include <stdio.h>

int mdc(int a, int b)
{

  if (b == 0)
  {
    return a;
  }

  return mdc(b, a % b);
}

int main()
{
  int num1, num2;

  printf("Digite o primeiro número: ");
  scanf("%d", &num1);

  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  int resultado = mdc(num1, num2);

  printf("O maior divisor comum entre %d e %d é: %d\n", num1, num2, resultado);

  return 0;
}
