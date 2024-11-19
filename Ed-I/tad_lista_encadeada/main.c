
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  Lista *li = cria_lista();
  li = insere_lista_inicio(li, 10);
  li = insere_lista_inicio(li, 20);
  li = insere_lista_inicio(li, 30);
  li = insere_lista_inicio(li, 40);
  li = remove_elemento(li, 80);
  mostrar_lista(li);
  libera_lista(li);

  return 0;
}