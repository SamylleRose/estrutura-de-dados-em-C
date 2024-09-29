#include <stdio.h>
#include <math.h>

typedef struct
{
  float x;
  float y;
  float z;
} Ponto;

float distancia(Ponto *p1, Ponto *p2)
{
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  float dz = p2->z - p1->z;

  return sqrt(dx * dx + dy * dy + dz * dz);
}

int main()
{
  Ponto p1, p2;

  printf("Digite as coordenadas do primeiro ponto (x y z): ");
  scanf("%f %f %f", &p1.x, &p1.y, &p1.z);

  printf("Digite as coordenadas do segundo ponto (x y z): ");
  scanf("%f %f %f", &p2.x, &p2.y, &p2.z);

  float dist = distancia(&p1, &p2);
  printf("A distancia entre os dois pontos e: %.2f\n", dist);

  return 0;
}
