#include <stdio.h>
#include <stdlib.h>

int main()
{
  int qtd_alunos;
  float soma = 0;

  printf("Digite a quantidade de alunos: ");
  scanf("%d", &qtd_alunos);

  float *notas = (float *)malloc(qtd_alunos * sizeof(float));

  for (int i = 0; i < qtd_alunos; i++)
  {
    printf("Digite a nota do aluno %d: ", i + 1);
    scanf("%f", &notas[i]);
    soma += notas[i];
  }

  printf("Média aritmética: %.2f\n", soma / qtd_alunos);

  free(notas);
  return 0;
}
