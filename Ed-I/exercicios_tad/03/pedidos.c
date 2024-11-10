#include "pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pedido *criar_pedido(int id, const char *nome_cliente, float valor, const char *data)
{
  Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
  novo_pedido->id = id;
  strcpy(novo_pedido->nome_cliente, nome_cliente);
  novo_pedido->valor = valor;
  strcpy(novo_pedido->data, data);
  return novo_pedido;
}

void adicionar_pedido(Pedido *pedidos[], int *count, Pedido *novo_pedido)
{
  pedidos[*count] = novo_pedido;
  (*count)++;
}

void listar_pedidos_por_cliente(Pedido *pedidos[], int count, const char *nome_cliente)
{
  for (int i = 0; i < count; i++)
  {
    if (strcmp(pedidos[i]->nome_cliente, nome_cliente) == 0)
    {
      printf("ID: %d, Valor: %.2f, Data: %s\n", pedidos[i]->id, pedidos[i]->valor, pedidos[i]->data);
    }
  }
}

float calcular_valor_total_por_data(Pedido *pedidos[], int count, const char *data)
{
  float total = 0;
  for (int i = 0; i < count; i++)
  {
    if (strcmp(pedidos[i]->data, data) == 0)
    {
      total += pedidos[i]->valor;
    }
  }
  return total;
}
