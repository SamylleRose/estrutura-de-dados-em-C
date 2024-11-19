#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno *cadastrarAluno(int *contador, Aluno *alunos)
{
  alunos = (Aluno *)realloc(alunos, sizeof(Aluno) * (*(contador) + 1));
  printf("Nome: ");
  scanf("%s", alunos[*(contador)].nome);
  printf("Idade: ");
  scanf("%d", &alunos[*(contador)].idade);
  alunos[*(contador)].matricula = rand() % 89 + 10; // Gera uma matrícula aleatória
  alunos[*(contador)].notas = cadastrarNotas();
  (*contador)++;
  return alunos;
}

float *cadastrarNotas()
{
  float *notas = (float *)calloc(2, sizeof(float));
  for (int i = 0; i < 2; i++)
  {
    printf("Informe a nota %d: ", i + 1);
    scanf("%f", &notas[i]);
  }
  return notas;
}

void mostrarAlunos(Aluno *alunos, int contador)
{
  printf("Mostrando dados para %d alunos\n", contador);
  printf("------------PRINT ALUNOS -----------\n");
  for (int i = 0; i < contador; i++)
  {
    printf("\nNome: %s", alunos[i].nome);
    printf("\nMatrícula: %d", alunos[i].matricula);
    printf("\nIdade: %d", alunos[i].idade);
    printf("\n----Notas-----\n");
    for (int j = 0; j < 2; j++)
    {
      printf("%d - %.2f\n", j + 1, alunos[i].notas[j]);
    }
  }
}

void removerAluno(Aluno **alunos, int *contador, int matricula)
{
  for (int i = 0; i < *contador; i++)
  {
    if ((*alunos)[i].matricula == matricula)
    {
      printf("Removendo aluno:\n");
      printf("Nome: %s\n", (*alunos)[i].nome);
      printf("Matrícula: %d\n", (*alunos)[i].matricula);
      printf("Idade: %d\n", (*alunos)[i].idade);

      free((*alunos)[i].notas);

      for (int j = i; j < *contador - 1; j++)
      {
        (*alunos)[j] = (*alunos)[j + 1];
      }

      (*alunos) = (Aluno *)realloc(*alunos, sizeof(Aluno) * (*contador - 1));
      (*contador)--;
      printf("Aluno removido com sucesso.\n");
      return;
    }
  }
  printf("Aluno com matrícula %d não encontrado.\n", matricula);
}

void liberarMemoria(Aluno *alunos, int contador)
{
  for (int i = 0; i < contador; i++)
  {
    free(alunos[i].notas);
  }
  free(alunos);
  printf("Memória liberada com sucesso.\n");
}

Aluno *buscarAluno(Aluno *alunos, int contador, int matricula)
{
  for (int i = 0; i < contador; i++)
  {
    if (alunos[i].matricula == matricula)
    {
      printf("Aluno encontrado:\n");
      printf("Nome: %s\n", alunos[i].nome);
      printf("Idade: %d\n", alunos[i].idade);
      printf("Matrícula: %d\n", alunos[i].matricula);
      return &alunos[i];
    }
  }
  printf("Aluno com matrícula %d não encontrado.\n", matricula);
  return NULL;
}

void menuInterativo(Aluno **alunos, int *contador)
{
  int opcao, matricula;
  do
  {
    printf("\nMenu:\n");
    printf("1. Cadastrar Aluno\n");
    printf("2. Mostrar Alunos\n");
    printf("3. Remover Aluno\n");
    printf("4. Buscar Aluno\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      *alunos = cadastrarAluno(contador, *alunos);
      break;
    case 2:
      mostrarAlunos(*alunos, *contador);
      break;
    case 3:
      printf("Informe a matrícula do aluno a ser removido: ");
      scanf("%d", &matricula);
      removerAluno(alunos, contador, matricula);
      break;
    case 4:
      printf("Informe a matrícula do aluno a ser buscado: ");
      scanf("%d", &matricula);
      buscarAluno(*alunos, *contador, matricula);
      break;
    case 5:
      liberarMemoria(*alunos, *contador);
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 5);
}
