#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int matricula;
  float notas[3];
} Aluno;

Aluno *criar_alunos(int qtd)
{
  return (Aluno *)malloc(qtd * sizeof(Aluno));
}

void liberar_alunos(Aluno *alunos)
{
  free(alunos);
}

void cadastrar_alunos(Aluno *alunos, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    printf("Aluno %d:\n", i + 1);
    printf("Nome: ");
    scanf("%s", alunos[i].nome);
    printf("Matrícula: ");
    scanf("%d", &alunos[i].matricula);
  }
}

void atribuir_notas(Aluno *alunos, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    printf("Atribuindo notas para %s:\n", alunos[i].nome);
    for (int j = 0; j < 3; j++)
    {
      printf("Nota %d: ", j + 1);
      scanf("%f", &alunos[i].notas[j]);
    }
  }
}

void imprimir_resultado(Aluno *alunos, int qtd, int aprovados)
{
  printf("%s:\n", aprovados ? "Aprovados" : "Reprovados");
  for (int i = 0; i < qtd; i++)
  {
    float media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
    if ((media >= 7 && aprovados) || (media < 7 && !aprovados))
    {
      printf("Nome: %s, Matrícula: %d, Média: %.2f\n", alunos[i].nome, alunos[i].matricula, media);
    }
  }
}

int main()
{
  int qtd;
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &qtd);

  Aluno *alunos = criar_alunos(qtd);

  cadastrar_alunos(alunos, qtd);
  atribuir_notas(alunos, qtd);

  imprimir_resultado(alunos, qtd, 1); // Aprovados
  imprimir_resultado(alunos, qtd, 0); // Reprovados

  liberar_alunos(alunos);

  return 0;
}
