#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void alternar_maiusculas_minusculas(char *entrada, char *saida, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    if (i % 2 == 0)
    {
      saida[i] = toupper(entrada[i]);
    }
    else
    {
      saida[i] = tolower(entrada[i]);
    }
  }
  saida[tamanho] = '\0';
}

int main()
{
  char entrada[100];
  printf("Digite uma sequência de letras: ");
  scanf("%s", entrada);

  int tamanho = 0;
  while (entrada[tamanho] != '\0')
  {
    tamanho++;
  }

  char *alternada = (char *)malloc((tamanho + 1) * sizeof(char));

  printf("Maiúsculas: ");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%c", toupper(entrada[i]));
  }
  printf("\n");

  printf("Minúsculas: ");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%c", tolower(entrada[i]));
  }
  printf("\n");

  alternar_maiusculas_minusculas(entrada, alternada, tamanho);

  printf("Alternado: %s\n", alternada);

  free(alternada);
  return 0;
}
