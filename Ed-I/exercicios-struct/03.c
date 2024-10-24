#include <stdio.h>
#include <stdlib.h>

typedef struct rectangle
{
  int length;
  int width;
} Rectangle;

void print_rectangle(Rectangle *retangle, int tam_vet_rectangle)
{
  float result;
  for (int i = 0; i < tam_vet_rectangle; i++)
  {
    result = retangle->length * retangle->width;
    printf("Área: %.2f\n", result);
  }
}

int main()
{

  int tam_vet_rectangle = 1;
  Rectangle *vet_rectangle;

  vet_rectangle = (Rectangle *)malloc(sizeof(Rectangle) * tam_vet_rectangle);

  if (vet_rectangle == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  for (int i = 0; i < tam_vet_rectangle; i++)
  {
    printf("Digite uma altura: ");
    scanf("%d", &vet_rectangle[i].length);
    printf("Digite uma largura: ");
    scanf("%d", &vet_rectangle[i].width);
  }

  print_rectangle(vet_rectangle, tam_vet_rectangle);

  free(vet_rectangle);
  return 0;
}