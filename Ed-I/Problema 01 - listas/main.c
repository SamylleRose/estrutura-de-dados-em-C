#include <stdlib.h>
#include <stdio.h>

#include "animal.h"
// #include "criador.h"
// #include "fazenda.h"

int main()
{

  Animal *li = criar_animal();
  li = inserir_animal(li, 1, 56.5, 1);
  amostrar_animal(li);

  return 0;
}