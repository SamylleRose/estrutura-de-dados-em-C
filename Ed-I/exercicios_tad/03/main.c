#include <stdio.h>
#include "pedidos.h"

int main()
{
  Pedido *pedidos[100];
  int count = 0;

  Pedido *p1 = criar_pedido(1, "Carlos", 100.5, "2023-11-01");
  adicionar_pedido(pedidos, &count, p1);

  listar_pedidos_por_cliente(pedidos, count, "Carlos");

  float total = calcular_valor_total_por_data(pedidos, count, "2023-11-01");
  printf("Total de pedidos em 2023-11-01: %.2f\n", total);

  return 0;
}
