#include <stdio.h>
#include "alunos.h"

int main()
{
  Aluno *alunos[100];
  int count = 0;

  Aluno *a1 = criar_aluno(1001, "Ana", 8.5, 1);
  cadastrar_aluno(alunos, &count, a1);

  Aluno *resultado = consultar_aluno_por_matricula(alunos, count, 1001);
  if (resultado)
  {
    printf("Aluno encontrado: %s, Nota: %.2f\n", resultado->nome, resultado->nota);
  }

  float media = calcular_media_por_curso(alunos, count, 1);
  printf("Media das notas do curso 1: %.2f\n", media);

  return 0;
}
