#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int idade;
  char posicao[20];
  int numero_camisa;
} Jogador;

Jogador *alocar_jogadores(int qtd)
{
  return (Jogador *)malloc(qtd * sizeof(Jogador));
}

void liberar_jogadores(Jogador *jogadores)
{
  free(jogadores);
}

void cadastrar_jogadores(Jogador *jogadores, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    printf("Jogador %d:\n", i + 1);
    printf("Nome: ");
    scanf("%s", jogadores[i].nome);
    printf("Idade: ");
    scanf("%d", &jogadores[i].idade);
    printf("Posição: ");
    scanf("%s", jogadores[i].posicao);
    printf("Número da Camisa: ");
    scanf("%d", &jogadores[i].numero_camisa);
    printf("\n");
  }
}

void imprimir_jogadores(Jogador *jogadores, int qtd, const char *tipo)
{
  printf("Jogadores %s:\n", tipo);
  for (int i = 0; i < qtd; i++)
  {
    printf("Nome: %s, Idade: %d, Posição: %s, Número: %d\n",
           jogadores[i].nome, jogadores[i].idade, jogadores[i].posicao, jogadores[i].numero_camisa);
  }
}

int main()
{
  int qtd_principais = 6, qtd_reservas = 4;

  Jogador *principais = alocar_jogadores(qtd_principais);
  Jogador *reservas = alocar_jogadores(qtd_reservas);

  printf("Cadastro dos Jogadores Principais:\n");
  cadastrar_jogadores(principais, qtd_principais);

  printf("Cadastro dos Jogadores Reservas:\n");
  cadastrar_jogadores(reservas, qtd_reservas);

  imprimir_jogadores(principais, qtd_principais, "Principais");
  imprimir_jogadores(reservas, qtd_reservas, "Reservas");

  liberar_jogadores(principais);
  liberar_jogadores(reservas);

  return 0;
}
