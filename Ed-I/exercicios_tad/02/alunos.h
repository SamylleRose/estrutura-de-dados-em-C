#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct
{
  int matricula;
  char nome[100];
  float nota;
  int codigo_curso;
} Aluno;

Aluno *criar_aluno(int matricula, const char *nome, float nota, int codigo_curso);
void cadastrar_aluno(Aluno *alunos[], int *count, Aluno *novo_aluno);
Aluno *consultar_aluno_por_matricula(Aluno *alunos[], int count, int matricula);
float calcular_media_por_curso(Aluno *alunos[], int count, int codigo_curso);

#endif
