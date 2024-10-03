#include <stdio.h>

void reajustar_salario(float *salario)
{
  if (*salario < 500.00)
  {
    *salario = *salario * 1.15;
  }
  else if (*salario <= 1000.00)
  {
    *salario = *salario * 1.10;
  }
  else
  {
    *salario = *salario * 1.05;
  }
}

int main()
{
  char nome[100];
  float salario;

  printf("Digite o nome do funcionario: ");
  scanf("%s", nome);

  printf("Digite o salario atual de %s: R$ ", nome);
  scanf("%f", &salario);

  reajustar_salario(&salario);

  printf("O novo salario de %s e: R$ %.2f\n", nome, salario);

  return 0;
}
