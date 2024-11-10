#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct
{
  int codigo;
  char nome[100];
  int quantidade;
  float preco;
} Produto;

Produto *criar_produto(int codigo, const char *nome, int quantidade, float preco);
void adicionar_produto(Produto *estoque[], int *count, Produto *novo_produto);
void atualizar_quantidade(Produto *estoque[], int count, int codigo, int nova_quantidade);
void imprimir_relatorio_estoque(Produto *estoque[], int count);

#endif
