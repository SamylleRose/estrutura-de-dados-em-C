#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "criador.h"

int main()
{

  srand((unsigned)time(NULL));

  Criador *liCriador = criarCriador();
  Fazenda *liFazenda = criarFazenda();
  Animal *liAnimal = criarAnimal();

  int codigo = 0;
  char nome[100], cpf[15], localizacao[100]; // variaveis que receberam os dados do usuario, para as funções receberem os dados por ponteiro.

  while (codigo != 5) // menu inicial do sistema
  {
    printf("\n-----------Sistema-----------");
    printf("\n1- Adicionar criadores\n");
    printf("2- mostrar criadores\n");
    printf("3- Acessar Fazendas\n");
    printf("4- Remover criador\n");
    printf("5- Sair\n");

    printf("\n\nDigite o codigo correspondente a sua escolha: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:

      liCriador = inserirCriador(liCriador);

      char confirmacao;

      printf("\nDeseja associar uma fazenda agora ao novo criador? S/N ");
      scanf("%s", &confirmacao);

      if (confirmacao == 'S' || confirmacao == 's')
      {

        liCriador->fazendas = inserirFazenda(liFazenda);
      }

      break;

    case 2:
      if (liCriador != NULL)
      {
        mostrarCriador(liCriador);
      }
      else
      {
        printf("\nO sistema não possui criadores\n");
      }
      break;

    case 3:
      if (liCriador != NULL)
      {
        while (1)
        {
          mostrarCriador(liCriador);

          char cpf[15];

          printf("\nInforme o CPF do criador que deseja acessar as suas fazendas (ou -1 para voltar): ");
          scanf("%s", cpf);

          printf("================================\n");
          printf("%d\n", strcmp(cpf, "-1"));
          printf("%d\n", strcmp(cpf, "-1") == 0);

          if ((strcmp(cpf, "-1") == 0))
          {
            printf("\nvoltando...\n");
            break;
          }

          Criador *atual = liCriador;
          int criadorEncontrado = 0;

          do
          {
            printf("================================\n");
            printf("%d\n", strcmp(atual->cpf, cpf));
            printf("%d\n", strcmp(atual->cpf, cpf) == 0);

            if ((strcmp(atual->cpf, cpf) == 0))
            {
              criadorEncontrado = 1;
              // Chama o menu do criador selecionado
              gerenciarFazendas(atual->fazendas);

              break;
            }

            atual = atual->next;
          } while (atual != liCriador);

          if (!criadorEncontrado)
          {
            printf("\nCriador com CPF %s não encontrado.\n", cpf);
          }
        }
      }
      else
      {
        printf("\nO sistema não possui criadores\n");
      }

      break;

    case 4:

      if (liCriador != NULL)
      {
        mostrarCriador(liCriador);
        liCriador = removerCriador(liCriador);
      }
      else
      {
        printf("\nO sistema não possui criadores\n");
      }

      break;

    case 5:
      printf("\n\nSaindo do sistema...\n\n");
      codigo = 5;

      break;

    default:
      printf("\nOpção inválida, tente novamente!\n");
      break;
    }
  }

  return 0;
}