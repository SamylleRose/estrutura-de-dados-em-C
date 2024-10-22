#include <stdio.h>

void trocar(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void gerar_anagramas(char *vetor, int inicio, int fim)
{
  if (inicio == fim)
  {
    printf("%s\n", vetor);
  }
  else
  {
    for (int i = inicio; i <= fim; i++)
    {
      trocar(&vetor[inicio], &vetor[i]);
      gerar_anagramas(vetor, inicio + 1, fim);
      trocar(&vetor[inicio], &vetor[i]);
    }
  }
}

int main()
{
  char vetor[4];
  printf("Digite três caracteres: ");
  scanf("%s", vetor);

  gerar_anagramas(vetor, 0, 2);

  return 0;
}
