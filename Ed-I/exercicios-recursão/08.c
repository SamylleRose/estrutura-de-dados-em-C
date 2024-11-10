#include <stdio.h>
#include <string.h>

void permutar(char *str, int inicio, int fim)
{

  if (inicio == fim)
  {
    printf("%s\n", str);
  }
  else
  {

    for (int i = inicio; i <= fim; i++)
    {

      char temp = str[inicio];
      str[inicio] = str[i];
      str[i] = temp;

      permutar(str, inicio + 1, fim);

      temp = str[inicio];
      str[inicio] = str[i];
      str[i] = temp;
    }
  }
}

int main()
{
  char str[100];

  printf("Digite uma string: ");
  scanf("%99s", str);

  printf("Permutações da string:\n");
  permutar(str, 0, strlen(str) - 1);

  return 0;
}
