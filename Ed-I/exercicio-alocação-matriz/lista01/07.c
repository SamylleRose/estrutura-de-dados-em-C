#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repete(char *s, int n)
{
  int len = strlen(s);
  int total_len = n * len + (n - 1);
  char *nova_string = (char *)malloc((total_len + 1) * sizeof(char));

  nova_string[0] = '\0';
  for (int i = 0; i < n; i++)
  {
    strcat(nova_string, s);
    if (i < n - 1)
    {
      strcat(nova_string, " ");
    }
  }

  return nova_string;
}

int main()
{
  char s[100];
  int n;
  printf("Digite a string: ");
  scanf("%s", s);
  printf("Digite o número de repetições: ");
  scanf("%d", &n);

  char *resultado = repete(s, n);
  printf("Resultado: %s\n", resultado);

  free(resultado);

  return 0;
}