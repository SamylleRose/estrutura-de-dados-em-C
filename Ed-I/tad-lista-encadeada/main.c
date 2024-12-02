#include <stdio.h>
#include "lista.h"

int main()
{
  Lista *lista = cria_lista();

  lista = inserir_elemento_inicio(lista, 10);
  lista = inserir_elemento_inicio(lista, 20);
  lista = inserir_elemento_inicio(lista, 30);
  printf("Lista após inserções no início: ");
  mostrar_lista(lista);

  lista = inserir_elemento_final(lista, 5);
  lista = inserir_elemento_final(lista, 1);
  printf("Lista após inserções no final: ");
  mostrar_lista(lista);

  lista = inserir_elemento_ordenado(lista, 15);
  lista = inserir_elemento_ordenado(lista, 25);
  printf("Lista após inserções ordenadas: ");
  mostrar_lista(lista);

  Lista *encontrado = busca_elemento(lista, 15);
  if (encontrado != NULL)
  {
    printf("Elemento encontrado: %d\n", encontrado->info);
  }
  else
  {
    printf("Elemento não encontrado.\n");
  }

  lista = remove_elemento(lista, 20);
  printf("Lista após remoção do elemento 20: ");
  mostrar_lista(lista);

  libera_lista(lista);

  return 0;
}
