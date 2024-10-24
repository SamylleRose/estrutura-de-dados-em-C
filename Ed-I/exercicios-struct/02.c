#include <stdio.h>
#include <stdlib.h>

typedef struct book
{
  char title[50];
  float price;
} Book;

void print_student(Book *book, int tam_vet_book)
{

  for (int i = 0; i < tam_vet_book; i++)
  {
    printf("%s\n", book->title);
    printf("%f\n", book->price);
    printf("-----------------\n");
  }
}

int main()
{

  int tam_vet_book = 5;
  Book *vet_book;

  vet_book = (Book *)malloc(sizeof(Book) * tam_vet_book);

  if (vet_book == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return 1;
  }
  for (int i = 0; i < tam_vet_book; i++)
  {
    printf("Digite um título: ");
    scanf("%s", vet_book[i].title);
    printf("Digite um preço: ");
    scanf("%f", &vet_book[i].price);
  }

  print_student(vet_book, tam_vet_book);

  free(vet_book);
  return 0;
}