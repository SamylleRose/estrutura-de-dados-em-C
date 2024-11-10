#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificar_palindromo(char *str, int inicio, int fim)
{
  if (inicio >= fim)
  {
    return 1;
  }

  while (!isalnum(str[inicio]) && inicio < fim)
  {
    inicio++;
  }
  while (!isalnum(str[fim]) && inicio < fim)
  {
    fim--;
  }

  if (tolower(str[inicio]) != tolower(str[fim]))
  {
    return 0;
  }

  return verificar_palindromo(str, inicio + 1, fim - 1);
}

int main()
{
  char str[100];

  printf("Digite uma string: ");
  fgets(str, sizeof(str), stdin);

  str[strcspn(str, "\n")] = 0;

  if (verificar_palindromo(str, 0, strlen(str) - 1))
  {
    printf("A string é um palíndromo.\n");
  }
  else
  {
    printf("A string não é um palíndromo.\n");
  }

  return 0;
}
