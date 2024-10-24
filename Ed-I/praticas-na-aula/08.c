#include <stdio.h>
#include <stdlib.h>

Aluno preencher()
{
}
void mostrarMedia() {}
void verificarMaiorMedia() {}
void imprime() {}
void imprimeTudo() {}

typedef struct aluno
{

  char nome[100];
  int idade;
  int matricula;
  float media;

} Aluno;

int main()
{

  int tam_vet_alunos = 50;
  Aluno *vet_alunos;

  vet_alunos = (Aluno *)malloc(sizeof(Aluno) * tam_vet_alunos);
  preencher();

  return 0;
}