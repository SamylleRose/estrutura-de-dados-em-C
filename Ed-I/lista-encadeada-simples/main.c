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
  mostrar_lista(li);

  if (busca_elemento(li, 22) != NULL)
  {
    printf("Elemento encontrado\n");
  }
  else
  {
    printf("Elemento nao encontrado\n");
  }

  li = remove_elemento(li, 20);
  mostrar_lista(li);

  libera_lista(li);
  return 0;
}