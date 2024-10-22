#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int matricula;
  int *questoes_dificeis;
  int qtd_dificuldade;
} Aluno;

Aluno *criar_alunos(int qtd)
{
  return (Aluno *)malloc(qtd * sizeof(Aluno));
}

void liberar_alunos(Aluno *alunos, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    free(alunos[i].questoes_dificeis);
  }
  free(alunos);
}

void cadastrar_dificuldades(Aluno *alunos, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    printf("Aluno %s, Matrícula: %d\n", alunos[i].nome, alunos[i].matricula);
    printf("Quantas questões ele teve dificuldade? ");
    scanf("%d", &alunos[i].qtd_dificuldade);
    alunos[i].questoes_dificeis = (int *)malloc(alunos[i].qtd_dificuldade * sizeof(int));

    for (int j = 0; j < alunos[i].qtd_dificuldade; j++)
    {
      printf("Digite a questão %d: ", j + 1);
      scanf("%d", &alunos[i].questoes_dificeis[j]);
    }
  }
}

void imprimir_dificuldades(Aluno *alunos, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    printf("Aluno %s teve dificuldades nas questões: ", alunos[i].nome);
    for (int j = 0; j < alunos[i].qtd_dificuldade; j++)
    {
      printf("%d ", alunos[i].questoes_dificeis[j]);
    }
    printf("\n");
  }
}

int main()
{
  int qtd;
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &qtd);

  Aluno *alunos = criar_alunos(qtd);

  for (int i = 0; i < qtd; i++)
  {
    printf("Nome do aluno %d: ", i + 1);
    scanf("%s", alunos[i].nome);
    printf("Matrícula do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].matricula);
  }

  cadastrar_dificuldades(alunos, qtd);
  imprimir_dificuldades(alunos, qtd);

  liberar_alunos(alunos, qtd);

  return 0;
}
