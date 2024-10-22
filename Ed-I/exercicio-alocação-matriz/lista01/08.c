#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverte(char *s)
{
  int len = strlen(s);
  char *invertida = (char *)malloc((len + 1) * sizeof(char));

  for (int i = 0; i < len; i++)
  {
    invertida[i] = s[len - i - 1];
  }

  invertida[len] = '\0';
  return invertida;
}

int main()
{
  char s[100];
  printf("Digite uma string: ");
  scanf("%s", s);

  char *resultado = inverte(s);
  printf("String invertida: %s\n", resultado);

  free(resultado);
  return 0;
}
