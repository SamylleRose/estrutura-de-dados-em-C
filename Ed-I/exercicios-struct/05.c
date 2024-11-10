// Defina uma struct `Library` que tenha um campo `Book *books` para armazenar
// um array dinâmico de livros e um campo `int num_books`. Escreva uma função
// que aloque um array dinâmico de `num_books` e permita
// ao usuário preencher os dados de cada livro. Observe que tanto `Library`
// quanto `Book` são structs.

#include <stdio.h>
#include <stdlib.h>

typedef struct book
{
  char title[100];
  char autor[100];
  int ano;

} Book;

typedef struct library
{
  Book *books;
  int num_books;

} Library;

void preencher_livraria(Library *library, int num_books)
{
  library->num_books = num_books;
  library->books = (Book *)malloc(num_books * sizeof(Book));

  if (library->books == NULL)
  {
    printf("Erro ao alocar memória para os livros.\n");
    exit(1);
  }

  for (int i = 0; i < num_books; i++)
  {

    printf("Digite o título do livro %d: ", i + 1);
    scanf("%s", library->books[i].title);

    printf("Digite o autor do livro %d: ", i + 1);
    scanf("%s", library->books[i].autor);

    printf("Digite o ano do livro %d: ", i + 1);
    scanf("%d", &library->books[i].ano);
  }
}

int main()
{

  Library minha_livraria;
  int num_books;

  printf("Quantos livros deseja adicionar? ");
  scanf("%d", &num_books);

  preencher_livraria(&minha_livraria, num_books);

  for (int i = 0; i < minha_livraria.num_books; i++)
  {
    printf("\nLivro %d\n", i + 1);
    printf("Título: %s", minha_livraria.books[i].title);
    printf("Autor: %s", minha_livraria.books[i].autor);
    printf("Ano de Publicação: %d\n", minha_livraria.books[i].ano);
  }

  return 0;
}