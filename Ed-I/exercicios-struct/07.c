#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *name;
  int age;
} Person;

Person *create_person_dynamic(char *name, int age)
{

  Person *p = (Person *)malloc(sizeof(Person));
  if (p == NULL)
  {
    printf("Erro ao alocar memória para a struct Person.\n");
    exit(1);
  }

  p->name = (char *)malloc((strlen(name) + 1) * sizeof(char));

  if (p->name == NULL)
  {
    printf("Erro ao alocar memória para o nome.\n");
    free(p);
    exit(1);
  }

  strcpy(p->name, name);
  p->age = age;

  return p;
}

void print_person(Person *p)
{
  if (p != NULL)
  {
    printf("Nome: %s\n", p->name);
    printf("Idade: %d\n", p->age);
  }
}

void free_person(Person *p)
{
  if (p != NULL)
  {
    free(p->name);
    free(p);
  }
}

int main()
{
  char name[] = "Alice";
  int age = 30;

  Person *person = create_person_dynamic(name, age);

  print_person(person);

  free_person(person);

  return 0;
}
