#include <stdio.h>
#include <stdlib.h>

int *uniao_vetores(int *v1, int n1, int *v2, int n2)
{
  int *v3 = (int *)malloc((n1 + n2) * sizeof(int));

  for (int i = 0; i < n1; i++)
  {
    v3[i] = v1[i];
  }
  for (int i = 0; i < n2; i++)
  {
    v3[n1 + i] = v2[i];
  }

  return v3;
}

int main()
{
  int v1[] = {11, 13, 45, 7};
  int v2[] = {24, 4, 16, 81, 10, 12};

  int *v3 = uniao_vetores(v1, 4, v2, 6);

  printf("União dos vetores:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", v3[i]);
  }
  printf("\n");

  free(v3);
  return 0;
}
