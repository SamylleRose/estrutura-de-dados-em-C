#ifndef PEDIDOS_H
#define PEDIDOS_H

typedef struct
{
  int id;
  char nome_cliente[100];
  float valor;
  char data[11];
} Pedido;

Pedido *criar_pedido(int id, const char *nome_cliente, float valor, const char *data);
void adicionar_pedido(Pedido *pedidos[], int *count, Pedido *novo_pedido);
void listar_pedidos_por_cliente(Pedido *pedidos[], int count, const char *nome_cliente);
float calcular_valor_total_por_data(Pedido *pedidos[], int count, const char *data);

#endif
