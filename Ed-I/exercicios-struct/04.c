#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
  char name[50];
  int age;
} Person;

void update_person(Person *person, int tam_vet_person)
{
  int number;

  printf("\n--------Atualize os dados-------- \n\n");
  printf("Qual pessoa deseja atualizar? ");
  scanf("%d", &number);

  if (number < 0 || number >= tam_vet_person)
  {
    printf("Número inválido!\n");
    return;
  }

  printf("\nNovo nome da %d pessoa: ", number);
  scanf("%s", person[number - 1].name);
  printf("Nova idade da %d pessoa: ", number);
  scanf("%d", &person[number - 1].age);
  printf("--------------------------------\n");
}

int main()
{

  int tam_vet_person = 2;
  Person *vet_person;

  vet_person = (Person *)malloc(sizeof(Person) * tam_vet_person);

  if (vet_person == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return 1;
  }
  for (int i = 0; i < tam_vet_person; i++)
  {
    printf("Digite um nome: ");
    scanf("%s", vet_person[i].name);
    printf("Digite uma idade: ");
    scanf("%d", &vet_person[i].age);
  }

  update_person(vet_person, tam_vet_person);

  for (int i = 0; i < tam_vet_person; i++)
  {
    printf("%s\n", vet_person[i].name);
    printf("%d\n", vet_person[i].age);
    printf("\n");
  }

  free(vet_person);
  return 0;
}