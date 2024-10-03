#include <stdio.h>
#include <string.h>

char *strins(char *dest, char *orig)
{
  int len_orig = strlen(orig);
  int len_dest = strlen(dest);

  for (int i = len_dest; i >= 0; i--)
  {
    dest[i + len_orig] = dest[i];
  }

  for (int i = 0; i < len_orig; i++)
  {
    dest[i] = orig[i];
  }

  return dest;
}

int main()
{
  char dest[100] = "mundo";
  char orig[] = "Ola ";

  strins(dest, orig);

  printf("Resultado apos insercao: %s\n", dest);

  return 0;
}
