#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int matricula, opcao;
  srand(time(NULL));

  Aluno *li = cria_aluno();

  do
  {
    printf("\n--- Menu ---\n");
    printf("1. Adicionar Aluno\n");
    printf("2. Listar alunos: \n");
    printf("3. Buscar aluno:\n");
    printf("4. Buscar aluno por media:\n");
    printf("5. Aluno com maior media:\n");
    printf("6. Remover aluno\n");
    printf("7. Sair\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      li = inserir_aluno_matricula(li);
      break;
    case 2:
      mostrar_todos_aluno(li);
      break;
    case 3:
    {
      printf("\nDigite a matricula: ");
      scanf("%d", &matricula);

      Aluno *aluno_encontrado = buscar_aluno(li, matricula);
      if (aluno_encontrado != NULL)
      {

        mostrar_unico_aluno(aluno_encontrado);
      }
      else
      {
        printf("\nAluno não encontrado!\n");
      }
    }
    break;
    case 4:

      float media;
      printf("Digite o valor da media: ");
      scanf("%f", &media);

      Aluno *resultado_busca = buscar_aluno_por_media(li, media);

      if (resultado_busca != NULL)
      {
        printf("\n--- Alunos com média %.2f ---\n", media);
        mostrar_todos_aluno(resultado_busca);
      }
      else
      {
        printf("\nNenhum aluno encontrado com média %.2f.\n", media);
      }
      break;
    case 5:
      mostrar_aluno_com_maior_media(li);
      break;

    case 6:
      printf("\nInforme uma matricula para remover: ");
      scanf("%d", &matricula);
      li = remover_aluno(li, matricula);
      break;

    case 7:
      liberar_aluno(li);
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida.\n");
    }
  } while (opcao != 7);

  return 0;
}
