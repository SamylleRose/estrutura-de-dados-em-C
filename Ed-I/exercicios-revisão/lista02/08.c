#include <stdio.h>

char *strchr(char *s, char ch)
{
  while (*s != '\0')
  {
    if (*s == ch)
    {
      return s;
    }
    s++;
  }
  return NULL;
}

int main()
{
  char string[100];
  char caractere;
  char *resultado;

  printf("Digite uma string: ");
  scanf("%99s", string);

  printf("Digite um caractere: ");
  scanf(" %c", &caractere);

  resultado = strchr(string, caractere);

  if (resultado != NULL)
  {
    printf("Os caracteres a partir do caractere '%c' sao: %s\n", caractere, resultado);
  }
  else
  {
    printf("Caractere '%c' nao encontrado na string.\n", caractere);
  }

  return 0;
}
