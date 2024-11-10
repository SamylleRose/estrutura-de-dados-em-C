#include <stdio.h>
#include <string.h>

typedef struct person
{
  char name[100];
  int age;

} Person;

Person create_person(char *name, int age)
{

  Person p;
  strncpy(p.name, name, sizeof(p.name) - 1);
  p.name[sizeof(p.name) - 1] = '\0';
  p.age = age;
  return p;
}

int main()
{

  char name[] = "Alice";
  int age = 30;

  Person person = create_person(name, age);

  printf("Nome: %s\n", person.name);
  printf("Idade: %d\n", person.age);

  return 0;
}