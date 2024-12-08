#include <stdlib.h>
#include <stdio.h>

#include "animal.h"
// #include "criador.h"
// #include "fazenda.h"

int main()
{

  Animal *li = criar_animal();
  li = inserir_animal(li, 1, 56.5, 'M', 1);
  li = inserir_animal(li, 2, 36.5, 'F', 0);

  mostrar_animal(li);
  int id;
  printf("\nQual o id do animal deseja remover?");
  scanf("%d", &id);

  li = remover_animal(li, id);
  mostrar_animal(li);

  return 0;
}