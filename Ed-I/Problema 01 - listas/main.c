#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "criador.h"

int main()
{

  srand((unsigned)time(NULL));

  // inicializa as lista  com NULL
  Criador *liCriador = NULL;
  Fazenda *liFazenda = NULL;
  Animal *liAnimal = NULL;

  int codigo = 0;
  char nome[100], cpf[15], localizacao[100]; // variaveis que recebem os dados do usuario, serão repassadas como parâmetros.
  char input[10];

  while (codigo != 6) // menu inicial do sistema
  {
    printf("\n-----------Sistema-----------");
    printf("\n1- Adicionar criadores\n");
    printf("2- mostrar criadores\n");
    printf("3- Adicionar fazenda\n");
    printf("4- Acessar Fazendas\n");
    printf("5- Remover criador\n");
    printf("6- Sair\n");

    printf("\n\nDigite o codigo correspondente a sua escolha: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:

      liCriador = inserirCriador(liCriador); // inseri um criador a lista.

      char confirmacao;

      printf("\nDeseja associar uma fazenda agora ao novo criador? S/N ");
      scanf("%s", &confirmacao);

      if (confirmacao == 'S' || confirmacao == 's') // caso o usuário já queira associar uma fazenda no cadastro do cliente
      {

        liCriador->fazendas = inserirFazenda(liFazenda);
      }

      break;

    case 2:
      if (liCriador != NULL) // verifica se já possui criadores cadastrados.
      {
        mostrarCriador(liCriador);
      }
      else // caso não ouver criadores cadastrados
      {
        printf("\nO sistema não possui criadores\n");
      }
      break;

    case 3:
      if (liCriador != NULL)
      {
        mostrarCriador(liCriador);
        printf("\nInforme o CPF do criador que deseja associar a fazendas: ");
        scanf("%s", cpf);

        Criador *atual = liCriador;
        int criadorEncontrado = 0; // contador para verificar se foi encontrado um criador com o cpf inserido pelo usuario

        do
        {
          if ((strcmp(atual->cpf, cpf) == 0)) // se o cpf é igual ao criador
          {
            criadorEncontrado = 1;
            atual->fazendas = inserirFazenda(atual->fazendas);
          }

          atual = atual->next;
        } while (atual != NULL);

        if (criadorEncontrado == 0)
        {
          printf("Criador não encontrado\n");
        }
      }
      else // caso não ouver criadores cadastrados
      {
        printf("\nO sistema não possui criadores\n");
      }

      break;

    case 4:
      if (liCriador != NULL) // verifica se já possui criadores cadastrados.
      {
        while (1)
        {
          mostrarCriador(liCriador); // mostra a lista de criadores

          char cpf[15];

          printf("\nInforme o CPF do criador que deseja acessar as suas fazendas (ou -1 para voltar): "); // escolhe qual criador desse acessar
          scanf("%s", cpf);

          if ((strcmp(cpf, "-1") == 0)) // caso o usuario deseje retornar ao menu sistema
          {
            printf("\nvoltando...\n");
            break;
          }

          Criador *atual = liCriador;
          int criadorEncontrado = 0; // contador para verificar se foi encontrado um criador com o cpf inserido pelo usuario

          do
          {

            if ((strcmp(atual->cpf, cpf) == 0)) // se o cpf é igual ao criador
            {
              criadorEncontrado = 1;

              // Verifica se o criador possuí fazendas
              if (atual->fazendas != NULL)
              {
                atual->fazendas = gerenciarFazendas(atual->fazendas); // Chama o menu gerenciar fazenda do criador selecionado
              }
              else
              {
                printf("\nEsse criador não possuí fazendas\n");
              }

              printf("main");

              break;
            }

            atual = atual->next;
          } while (atual != liCriador);

          if (!criadorEncontrado) // caso o cpf inserido não existir na lista criadores
          {
            printf("\nCriador com CPF %s não encontrado.\n", cpf);
          }
        }
      }
      else // caso não ouver criadores cadastrados
      {
        printf("\nO sistema não possui criadores\n");
      }

      break;

    case 5:

      if (liCriador != NULL) // verifica se já possui criadores cadastrados.
      {
        mostrarCriador(liCriador);
        liCriador = removerCriador(liCriador);
      }
      else // caso não ouver criadores cadastrados'
      {
        printf("\nO sistema não possui criadores\n");
      }

      break;

    case 6:
      printf("\n\nSaindo do sistema...\n\n"); // encerra o programa
      codigo = 6;

      break;

    default:
      printf("\nOpção inválida, tente novamente!\n");
      break;
    }
  }

  liberaCriador(liCriador); // libera as listas criador, fazenda e animal.

  return 0;
}