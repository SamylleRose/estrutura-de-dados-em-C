#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *name;
  int age;
  int *grades;
} Student;

typedef struct
{
  Student *students;
  int num_students;
} Classroom;

Classroom *create_classroom(int num_students, int num_grades_per_student)
{
  Classroom *classroom = (Classroom *)malloc(sizeof(Classroom));
  classroom->num_students = num_students;
  classroom->students = (Student *)malloc(num_students * sizeof(Student));

  for (int i = 0; i < num_students; i++)
  {
    classroom->students[i].name = (char *)malloc(100 * sizeof(char));
    classroom->students[i].grades = (int *)malloc(num_grades_per_student * sizeof(int));
  }

  return classroom;
}

void fill_classroom(Classroom *classroom, int num_grades_per_student)
{
  for (int i = 0; i < classroom->num_students; i++)
  {
    printf("Digite o nome do estudante %d: ", i + 1);
    scanf(" %99[^\n]", classroom->students[i].name);

    printf("Digite a idade do estudante %d: ", i + 1);
    scanf("%d", &classroom->students[i].age);

    printf("Digite as notas do estudante %d:\n", i + 1);
    for (int j = 0; j < num_grades_per_student; j++)
    {
      printf("Nota %d: ", j + 1);
      scanf("%d", &classroom->students[i].grades[j]);
    }
  }
}

void print_classroom(Classroom *classroom, int num_grades_per_student)
{
  for (int i = 0; i < classroom->num_students; i++)
  {
    printf("\nEstudante %d\n", i + 1);
    printf("Nome: %s\n", classroom->students[i].name);
    printf("Idade: %d\n", classroom->students[i].age);
    printf("Notas: ");
    for (int j = 0; j < num_grades_per_student; j++)
    {
      printf("%d ", classroom->students[i].grades[j]);
    }
    printf("\n");
  }
}

void free_classroom(Classroom *classroom, int num_grades_per_student)
{
  for (int i = 0; i < classroom->num_students; i++)
  {
    free(classroom->students[i].name);
    free(classroom->students[i].grades);
  }
  free(classroom->students);
  free(classroom);
}

int main()
{
  int num_students, num_grades_per_student;

  printf("Digite o número de estudantes: ");
  scanf("%d", &num_students);

  printf("Digite o número de notas por estudante: ");
  scanf("%d", &num_grades_per_student);

  Classroom *classroom = create_classroom(num_students, num_grades_per_student);

  fill_classroom(classroom, num_grades_per_student);

  printf("\nDados da sala de aula:\n");
  print_classroom(classroom, num_grades_per_student);

  free_classroom(classroom, num_grades_per_student);

  return 0;
}
