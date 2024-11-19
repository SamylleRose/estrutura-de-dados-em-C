
#ifndef ACERVO_H
#define ACERVO_H

typedef struct {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
    int num_paginas;
} Livro;

typedef struct {
    Livro *livros;
    int quantidade;
    int capacidade;
} Acervo;

// Funções do TAD Acervo
Acervo *inicializar_acervo(int capacidade_inicial);
void adicionar_livro(Acervo *acervo, const char *titulo, const char *autor, int ano_publicacao, int num_paginas);
void listar_livros(const Acervo *acervo);
Livro *buscar_livro(const Acervo *acervo, const char *titulo);
void remover_livro(Acervo *acervo, const char *titulo);
void liberar_acervo(Acervo *acervo);

#endif // ACERVO_H
