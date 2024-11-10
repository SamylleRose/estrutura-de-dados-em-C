#include <stdio.h>
#include "estoque.h"

int main()
{
  Produto *estoque[100];
  int count = 0;

  Produto *prod1 = criar_produto(1, "Caneta", 200, 1.50);
  adicionar_produto(estoque, &count, prod1);

  atualizar_quantidade(estoque, count, 1, 250);
  imprimir_relatorio_estoque(estoque, count);

  return 0;
}
