#include <stdio.h>
#include <ctype.h>

void contar_caracteres_e_vogais(char *str, int *num_caracteres, int *num_vogais)
{
  *num_caracteres = 0;
  *num_vogais = 0;

  while (*str != '\0')
  {
    (*num_caracteres)++;

    char ch = tolower(*str);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      (*num_vogais)++;
    }

    str++;
  }
}

int main()
{
  char string[100];
  int num_caracteres, num_vogais;

  printf("Digite uma string: ");
  scanf("%s", string);

  contar_caracteres_e_vogais(string, &num_caracteres, &num_vogais);

  printf("Numero de caracteres: %d\n", num_caracteres);
  printf("Numero de vogais: %d\n", num_vogais);

  return 0;
}
