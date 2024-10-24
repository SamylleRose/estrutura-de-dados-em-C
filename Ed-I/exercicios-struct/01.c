#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
  int id;
  char name[50];
} Student;

void print_student(Student *student, int tam_vet_students)
{

  for (int i = 0; i < tam_vet_students; i++)
  {
    printf("%d\n", student->id);
    printf("%s\n", student->name);
    printf("-----------------\n");
  }
}

int main()
{

  int tam_vet_students = 3;
  Student *vet_student;

  vet_student = (Student *)malloc(sizeof(Student) * tam_vet_students);

  if (vet_student == NULL)
  {
    printf("Erro ao alocar memória!\n");
    return 1;
  }
  for (int i = 0; i < tam_vet_students; i++)
  {
    printf("Digite um id: ");
    scanf("%d", &vet_student[i].id);
    printf("Digite um nome: ");
    scanf("%s", vet_student[i].name);
  }

  print_student(vet_student, tam_vet_students);

  free(vet_student);
  return 0;
}