#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontrar_menor_maior(char **strings, int n)
{
  char *menor = strings[0];
  char *maior = strings[0];

  for (int i = 1; i < n; i++)
  {
    if (strlen(strings[i]) < strlen(menor))
    {
      menor = strings[i];
    }
    if (strlen(strings[i]) > strlen(maior))
    {
      maior = strings[i];
    }
  }

  printf("Menor string: %s\n", menor);
  printf("Maior string: %s\n", maior);
}

int main()
{
  char *strings[6];
  for (int i = 0; i < 6; i++)
  {
    strings[i] = (char *)malloc(100 * sizeof(char));
    printf("Digite a string %d: ", i + 1);
    scanf("%s", strings[i]);
  }

  encontrar_menor_maior(strings, 6);

  for (int i = 0; i < 6; i++)
  {
    free(strings[i]);
  }

  return 0;
}
