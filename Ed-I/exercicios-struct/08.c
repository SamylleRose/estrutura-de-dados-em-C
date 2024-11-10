#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[100];
  int age;
} Person;

void print_person_by_value(Person p)
{
  printf("Nome (por valor): %s\n", p.name);
  printf("Idade (por valor): %d\n", p.age);
  p.name, ("Modificado na função por valor");
  p.age = 99;
}

void print_person_by_reference(Person *p)
{
  printf("Nome (por referência): %s\n", p->name);
  printf("Idade (por referência): %d\n", p->age);
  (p->name, "Modificado na função por referência");
  p->age = 99;
}

int main()
{
  Person person;
  strcpy(person.name, "Alice");
  person.age = 30;

  print_person_by_value(person);
  printf("\nApós passar por valor, nome: %s, idade: %d\n", person.name, person.age);

  print_person_by_reference(&person);
  printf("\nApós passar por referência, nome: %s, idade: %d\n", person.name, person.age);

  return 0;
}
