#include <stdlib.h>
#include <stdio.h>

#include "lista_dupla.h"

int main()
{
  Lista *li;
  li = cria_lista();
  li = inserir_circular(li, 10);
  li = inserir_circular(li, 12);
  mostrar_lista(li);
  return 0;
}