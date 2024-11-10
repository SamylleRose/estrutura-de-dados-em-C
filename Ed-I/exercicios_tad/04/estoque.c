#include "estoque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produto *criar_produto(int codigo, const char *nome, int quantidade, float preco)
{
  Produto *novo_produto = (Produto *)malloc(sizeof(Produto));
  novo_produto->codigo = codigo;
  strcpy(novo_produto->nome, nome);
  novo_produto->quantidade = quantidade;
  novo_produto->preco = preco;
  return novo_produto;
}

void adicionar_produto(Produto *estoque[], int *count, Produto *novo_produto)
{
  estoque[*count] = novo_produto;
  (*count)++;
}

void atualizar_quantidade(Produto *estoque[], int count, int codigo, int nova_quantidade)
{
  for (int i = 0; i < count; i++)
  {
    if (estoque[i]->codigo == codigo)
    {
      estoque[i]->quantidade = nova_quantidade;
      return;
    }
  }
}

void imprimir_relatorio_estoque(Produto *estoque[], int count)
{
  float total_estoque = 0;
  for (int i = 0; i < count; i++)
  {
    float valor_total = estoque[i]->quantidade * estoque[i]->preco;
    total_estoque += valor_total;
    printf("Codigo: %d, Nome: %s, Quantidade: %d, Valor Total: %.2f\n",
           estoque[i]->codigo, estoque[i]->nome, estoque[i]->quantidade, valor_total);
  }
  printf("Valor total em estoque: %.2f\n", total_estoque);
}
