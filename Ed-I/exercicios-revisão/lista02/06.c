#include <stdio.h>

typedef struct
{
  float x;
  float y;
} Ponto;

int interior_retangulo(Ponto *v1, Ponto *v2, Ponto *p)
{
  if (p->x >= v1->x && p->x <= v2->x && p->y >= v1->y && p->y <= v2->y)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  Ponto v1, v2, p;

  printf("Digite as coordenadas do vertice inferior esquerdo do retangulo (x y): ");
  scanf("%f %f", &v1.x, &v1.y);

  printf("Digite as coordenadas do vertice superior direito do retangulo (x y): ");
  scanf("%f %f", &v2.x, &v2.y);

  printf("Digite as coordenadas do ponto (x y): ");
  scanf("%f %f", &p.x, &p.y);

  if (interior_retangulo(&v1, &v2, &p))
  {
    printf("O ponto esta dentro do retangulo.\n");
  }
  else
  {
    printf("O ponto esta fora do retangulo.\n");
  }

  return 0;
}
