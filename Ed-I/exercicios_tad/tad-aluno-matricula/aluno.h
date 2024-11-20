typedef struct aluno Aluno;

struct aluno
{
    int matricula; // valor randomico de 100 ate 999 (este deve ser único para cada aluno)
    char *nome[100];
    float *notas[3]; // vetor para as notas dos alunos
    float media;
    Aluno *prox;
};

Aluno *cria_aluno();
void liberar_aluno(Aluno *li);
Aluno *inserir_aluno_matricula(Aluno *li);
void mostrar_todos_aluno(Aluno *li);
void mostrar_unico_aluno(Aluno *li);
Aluno *buscar_aluno(Aluno *li, int matricula);

// remover um aluno pela matricula (antes de remover, apresentar os dados do aluno que esta sendo revmoido, caso ele esteja presente na lista)
Aluno *remover_aluno(Aluno *li, int matricula);
// buscar aluno(s) por media (reutilizar as funcoes ja prontas)
Aluno *buscar_aluno_por_media(Aluno *li, float media);
// mostrar o aluno com maior media (reutilizar as funcoes ja prontas)
void mostrar_aluno_com_maior_media(Aluno *li);