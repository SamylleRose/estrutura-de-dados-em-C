#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include "criador.h"

#include "fazenda.h"

int main()
{

  srand((unsigned)time(NULL));

  Animal *liAnimal = criarAnimal();
  // liAnimal = inserirAnimal(liAnimal, 1, 56.5, 'M', 1);
  // liAnimal = inserirAnimal(liAnimal, 2, 36.5, 'F', 0);

  Fazenda *liFazenda = criarFazenda();
  liFazenda = inserirFazenda(liFazenda, 98, "Fazendinha feliz", "Picos");
  liFazenda = inserirFazenda(liFazenda, 38, "Casa velha", "CG");

  // mostrarFazenda(liFazenda);

  // liFazenda = removerFazenda(liFazenda, 98);
  // if (liFazenda == NULL)
  // {
  //   printf("A lista de fazendas agora está vazia.\n");
  // }

  // mostrarFazenda(liFazenda);

  gerenciarFazendas(liFazenda, liAnimal);

  // mostrar_animal(li);
  // int id;
  // printf("\nQual o id do animal deseja remover?");
  // scanf("%d", &id);

  // li = remover_animal(li, id);
  // mostrarAnimal(liAnimal);

  return 0;
}