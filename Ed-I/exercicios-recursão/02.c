#include <stdio.h>

int soma_digitos(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else
  {
    return (n % 10) + soma_digitos(n / 10);
  }
}

int main()
{
  int numero;

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &numero);

  if (numero < 0)
  {
    printf("Por favor, insira um número inteiro positivo.\n");
  }
  else
  {
    int resultado = soma_digitos(numero);
    printf("A soma dos dígitos de %d é: %d\n", numero, resultado);
  }

  return 0;
}
