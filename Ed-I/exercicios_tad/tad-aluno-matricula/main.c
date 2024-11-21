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
  li = inserir_aluno_matricula(li);
  li = inserir_aluno_matricula(li);
  mostrar_todos_aluno(li);
  // mostrar_unico_aluno(li);
  // mostrar_unico_aluno(li);

  // printf("\nInforme uma matricula para remover: ");
  // scanf("%d", &matricula);
  // li = remover_aluno(li, matricula);

  float media = 9;

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
  // mostrar_todos_aluno(li);

  liberar_aluno(li);
}
