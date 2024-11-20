#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int matricula;
  srand(time(NULL)); // Inicializa o gerador de números aleatórios

  Aluno *li = cria_aluno();
  li = inserir_aluno_matricula(li);
  mostrar_todos_aluno(li);
  li = inserir_aluno_matricula(li);
  mostrar_todos_aluno(li);
  // mostrar_unico_aluno(li);
  // mostrar_unico_aluno(li);

  printf("\nInforme uma tricula para remover: ");
  scanf("%d", &matricula);
  li = remover_aluno(li, matricula);
  mostrar_todos_aluno(li);
}
