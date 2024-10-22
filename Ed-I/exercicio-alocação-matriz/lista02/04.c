#include <stdio.h>
#include <stdlib.h>

int *uniao_vetores(int *v1, int *v2, int q1, int q2)
{
  int *v3 = (int *)malloc((q1 + q2) * sizeof(int));
  for (int i = 0; i < q1; i++)
  {
    v3[i] = v1[i];
  }
  for (int i = 0; i < q2; i++)
  {
    v3[q1 + i] = v2[i];
  }
  return v3;
}

int main()
{
  int q1 = 3, q2 = 4;
  int *v1 = (int *)malloc(q1 * sizeof(int));
  int *v2 = (int *)malloc(q2 * sizeof(int));

  for (int i = 0; i < q1; i++)
  {
    v1[i] = i + 1;
  }
  for (int i = 0; i < q2; i++)
  {
    v2[i] = i + 10;
  }

  int *v3 = uniao_vetores(v1, v2, q1, q2);
  for (int i = 0; i < q1 + q2; i++)
  {
    printf("%d ", v3[i]);
  }
  printf("\n");

  free(v1);
  free(v2);
  free(v3);

  return 0;
}
