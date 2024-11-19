#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

  Aluno *li = cria_aluno();
  li = inserir_aluno_matricula(li);
  mostrar_todos_aluno(li);
  li = inserir_aluno_matricula(li);
  mostrar_todos_aluno(li);
  
}