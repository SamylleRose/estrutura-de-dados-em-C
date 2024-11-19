// TAD para prover as assinaturas dos métodos e tipos da TAD Aluno

typedef struct aluno
{
  char nome[100];
  int idade, matricula;
  float *notas;
} Aluno;

Aluno *cadastrarAluno(int *contador, Aluno *alunos);
float *cadastrarNotas();
void mostrarAlunos(Aluno *alunos, int contador);
void removerAluno(Aluno **alunos, int *contador, int matricula);
void liberarMemoria(Aluno *alunos, int contador);
Aluno *buscarAluno(Aluno *alunos, int contador, int matricula);
void menuInterativo(Aluno **alunos, int *contador);
