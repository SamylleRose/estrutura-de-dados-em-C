#include <stdio.h>

int compara_arrays(int *p1, int *p2, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (p1[i] != p2[i])
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int array1[] = {1, 2, 3, 4, 5};
  int array2[] = {1, 2, 3, 4, 5};
  int array3[] = {1, 2, 3, 0, 5};
  int n = 5;

  if (compara_arrays(array1, array2, n))
  {
    printf("array1 e array2 sao iguais.\n");
  }
  else
  {
    printf("array1 e array2 sao diferentes.\n");
  }

  if (compara_arrays(array1, array3, n))
  {
    printf("array1 e array3 sao iguais.\n");
  }
  else
  {
    printf("array1 e array3 sao diferentes.\n");
  }

  return 0;
}
