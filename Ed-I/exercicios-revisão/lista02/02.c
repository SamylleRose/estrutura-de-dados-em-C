#include <stdio.h>

void calcular_volume(double *volume, double *comprimento, double *largura, double *altura)
{
  *volume = (*comprimento) * (*largura) * (*altura);
}

void calcular_area_superficial(double *area_superficial, double *comprimento, double *largura, double *altura)
{
  *area_superficial = 2 * ((*comprimento * *largura) + (*comprimento * *altura) + (*largura * *altura));
}

int main()
{
  double comprimento, largura, altura;
  double volume;
  double area_superficial;

  printf("Digite o comprimento do paralelepípedo: ");
  scanf("%lf", &comprimento);

  printf("Digite a largura do paralelepípedo: ");
  scanf("%lf", &largura);

  printf("Digite a altura do paralelepípedo: ");
  scanf("%lf", &altura);

  calcular_volume(&volume, &comprimento, &largura, &altura);
  calcular_area_superficial(&area_superficial, &comprimento, &largura, &altura);

  printf("Volume do paralelepípedo: %.2lf\n", volume);
  printf("Área superficial do paralelepípedo: %.2lf\n", area_superficial);

  return 0;
}
