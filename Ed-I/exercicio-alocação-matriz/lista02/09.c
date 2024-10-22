#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char descricao[100];
  float valor;
} Dispositivo;

typedef struct
{
  char nome[50];
  char cpf[12];
  Dispositivo *dispositivos;
} Pessoa;

Dispositivo *criar_dispositivos(int qtd)
{
  return (Dispositivo *)malloc(qtd * sizeof(Dispositivo));
}

void liberar_dispositivos(Dispositivo *dispositivos)
{
  free(dispositivos);
}

Pessoa *criar_pessoas(int qtd_pessoas, int qtd_dispositivos)
{
  Pessoa *pessoas = (Pessoa *)malloc(qtd_pessoas * sizeof(Pessoa));
  for (int i = 0; i < qtd_pessoas; i++)
  {
    pessoas[i].dispositivos = criar_dispositivos(qtd_dispositivos);
  }
  return pessoas;
}

void liberar_pessoas(Pessoa *pessoas, int qtd_pessoas)
{
  for (int i = 0; i < qtd_pessoas; i++)
  {
    liberar_dispositivos(pessoas[i].dispositivos);
  }
  free(pessoas);
}

int main()
{
  int qtd_pessoas = 2, qtd_dispositivos = 3;

  Pessoa *pessoas = criar_pessoas(qtd_pessoas, qtd_dispositivos);

  for (int i = 0; i < qtd_pessoas; i++)
  {
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: ");
    scanf("%s", pessoas[i].nome);
    printf("CPF: ");
    scanf("%s", pessoas[i].cpf);

    for (int j = 0; j < qtd_dispositivos; j++)
    {
      printf("Dispositivo %d - Descrição: ", j + 1);
      scanf("%s", pessoas[i].dispositivos[j].descricao);
      printf("Valor: ");
      scanf("%f", &pessoas[i].dispositivos[j].valor);
    }
  }

  liberar_pessoas(pessoas, qtd_pessoas);

  return 0;
}
