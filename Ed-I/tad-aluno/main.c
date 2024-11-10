#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  Aluno *alunos = NULL;
  int contador = 0;

  menuInterativo(&alunos, &contador);

  return 0;
}
