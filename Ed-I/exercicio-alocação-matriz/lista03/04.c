#include <stdio.h>
#include <stdlib.h>

char *converte_para_string(char c)
{
  char *str = (char *)malloc(2 * sizeof(char));
  str[0] = c;
  str[1] = '\0';
  return str;
}

int main()
{
  char c;
  printf("Digite um caractere: ");
  scanf(" %c", &c);

  char *str = converte_para_string(c);
  printf("String: %s\n", str);

  free(str);
  return 0;
}
