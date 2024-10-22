#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar_strings(char **s1, char **s2)
{
  char *temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}

int main()
{
  char *s1 = (char *)malloc(100 * sizeof(char));
  char *s2 = (char *)malloc(100 * sizeof(char));

  printf("Digite a string 1: ");
  scanf("%s", s1);
  printf("Digite a string 2: ");
  scanf("%s", s2);

  trocar_strings(&s1, &s2);

  printf("Após a troca:\n");
  printf("String 1: %s\n", s1);
  printf("String 2: %s\n", s2);

  free(s1);
  free(s2);
  return 0;
}
