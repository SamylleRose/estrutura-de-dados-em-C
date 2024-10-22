#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int C;
  int H;
} Hidrocarboneto;

void calcular_massa_molecular(Hidrocarboneto *composto)
{
  printf("Digite a quantidade de carbonos (C): ");
  scanf("%d", &composto->C);
  printf("Digite a quantidade de hidrogênios (H): ");
  scanf("%d", &composto->H);

  int massa = (composto->C * 12) + (composto->H * 1);
  printf("Massa molecular: %d\n", massa);
}

int main()
{
  Hidrocarboneto *composto = (Hidrocarboneto *)malloc(sizeof(Hidrocarboneto));
  calcular_massa_molecular(composto);
  free(composto);
  return 0;
}
