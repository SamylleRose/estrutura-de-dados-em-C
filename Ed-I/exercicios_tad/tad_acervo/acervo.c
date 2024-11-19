#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acervo.h"

Acervo *inicializar_acervo(int capacidade)
{

  Acervo *acervo = (Acervo *)malloc(sizeof(Acervo));

  if (acervo == NULL)
  {
    printf("Erro na alocação de memória");
    exit(1);
  }
  acervo->capacidade = capacidade;
  acervo->quantidade = 0;
  acervo->livros = (Livro *)malloc(capacidade * sizeof(Livro));

  if (acervo->livros == NULL)
  {
    printf("Erro na alocação de memória para livros");
    free(acervo);
    exit(1);
  }

  return acervo;
}

void adicionar_livro(Acervo *acervo, const char *titulo, const char *autor, int ano_publicacao, int num_paginas)
{

  if (acervo->capacidade == acervo->quantidade)
  {
    acervo->capacidade *= 2;
    acervo->livros = (Livro *)realloc(acervo->livros, acervo->capacidade * sizeof(Livro));

    if (acervo->livros == NULL)
    {
      printf("Erro na realocação de memória\n");
      exit(1);
    }
  }

  strcpy(acervo->livros[acervo->quantidade].titulo, titulo);
  strcpy(acervo->livros[acervo->quantidade].autor, autor);
  acervo->livros[acervo->quantidade].ano_publicacao = ano_publicacao;
  acervo->livros[acervo->quantidade].num_paginas = num_paginas;

  acervo->quantidade++;
}

void listar_livros(const Acervo *acervo)
{

  for (int i = 0; i < acervo->quantidade; i++)
  {

    printf("\nLivro %d----------", i + 1);
    printf("\nTitulo: %s", acervo->livros[i].titulo);
    printf("\nAutor: %s", acervo->livros[i].autor);
    printf("\nAno de publicação: %d", acervo->livros[i].ano_publicacao);
    printf("\nNumero de páginas: %d\n", acervo->livros[i].num_paginas);
  }
}

Livro *buscar_livro(const Acervo *acervo, const char *titulo)
{

  for (int i = 0; i < acervo->quantidade; i++)
  {

    if (strcmp(acervo->livros[i].titulo, titulo) == 0)
    {
      return &acervo->livros[i];
    }
  }
  return NULL;
}

void remover_livro(Acervo *acervo, const char *titulo)
{
  for (int i = 0; i < acervo->quantidade; i++)
  {
    if (strcmp(acervo->livros[i].titulo, titulo) == 0)
    {

      acervo->livros[i] = acervo->livros[acervo->quantidade - 1];
      acervo->quantidade--;

      return;
    }
  }
  printf("Livro não encontrado para remoção.\n");
}

void liberar_acervo(Acervo *acervo)
{

  for (int i = 0; i < acervo->quantidade; i++)
  {
    free(acervo->livros[i].titulo);
    free(acervo->livros[i].autor);
  }

  free(acervo->livros);
  free(acervo);
}
