#include <stdio.h>
#include <ctype.h>

int eh_vogal(char c)
{
  c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void substituir_consoantes(char *str)
{
  while (*str != '\0')
  {
    if (isalpha(*str) && !eh_vogal(*str))
    {
      if (*str == 'z')
      {
        *str = 'a';
      }
      else if (*str == 'Z')
      {
        *str = 'A';
      }
      else
      {
        (*str)++;
      }
    }
    str++;
  }
}

int main()
{
  char string[100];

  printf("Digite uma string: ");
  scanf("%[^\n]", string);

  substituir_consoantes(string);

  printf("Resultado apos substituir as consoantes: %s\n", string);

  return 0;
}
