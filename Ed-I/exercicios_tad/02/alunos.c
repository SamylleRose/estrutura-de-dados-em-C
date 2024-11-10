#include "alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Aluno *criar_aluno(int matricula, const char *nome, float nota, int codigo_curso)
{
  Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
  novo_aluno->matricula = matricula;
  strcpy(novo_aluno->nome, nome);
  novo_aluno->nota = nota;
  novo_aluno->codigo_curso = codigo_curso;
  return novo_aluno;
}

void cadastrar_aluno(Aluno *alunos[], int *count, Aluno *novo_aluno)
{
  alunos[*count] = novo_aluno;
  (*count)++;
}

Aluno *consultar_aluno_por_matricula(Aluno *alunos[], int count, int matricula)
{
  for (int i = 0; i < count; i++)
  {
    if (alunos[i]->matricula == matricula)
    {
      return alunos[i];
    }
  }
  return NULL;
}

float calcular_media_por_curso(Aluno *alunos[], int count, int codigo_curso)
{
  int total = 0;
  float soma = 0;
  for (int i = 0; i < count; i++)
  {
    if (alunos[i]->codigo_curso == codigo_curso)
    {
      soma += alunos[i]->nota;
      total++;
    }
  }
  return total > 0 ? soma / total : 0;
}
