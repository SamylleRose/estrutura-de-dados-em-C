#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;

struct funcionario
{
  char nome[100];
  float salario;
  int idade;
};

int main()
{
  int tam_vet_funcionarios = 10;
  Funcionario *vet_funcionarios;

  // alocar vet_funcionarios para tam_vet_funcionarios
  vet_funcionarios = (Funcionario *)malloc(sizeof(Funcionario) * tam_vet_funcionarios);

  // preencher o vetor de funcionarios
  int codigo;
  int i = 0;

  while (1)
  {
    printf("Informe o nome:");
    scanf("%s", vet_funcionarios[i].nome);
    printf("Informe a idade:");
    scanf("%d", &vet_funcionarios[i].idade);
    printf("Informe o salario:");
    scanf("%f", &vet_funcionarios[i].salario);

    printf("Deseja continuar? se não digite -1: ");
    scanf("%d", &codigo);

    if (codigo == -1) // Compare strings using strcmp
      break;

    i++;

    if (i >= tam_vet_funcionarios)
    {
      printf("Atingido o limite máximo de funcionários.\n");
      break;
    }
  }

  // mostrar os valores que estao no vetor de funcionarios
  printf("\n \n");

  for (int i = 0; i < 3; i++)
    printf("Nome: %s \nIdade: %d\n Salario %.2f\n", vet_funcionarios[i].nome, vet_funcionarios[i].idade, vet_funcionarios[i].salario);

  return 0;
}