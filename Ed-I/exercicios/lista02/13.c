#include <stdio.h>

int main()
{
  int arr[] = {1, 2, 3};
  int *p = arr;

  printf("Antes de p++: %d\n", *p);  // 1
  p++;                               // Move para o próximo elemento
  printf("Depois de p++: %d\n", *p); // 2

  (*p)++;                               // Incrementa o valor no endereço apontado por p (2 se torna 3)
  printf("Depois de (*p)++: %d\n", *p); // 3

  p = arr;                                 // Volta o ponteiro para o início do array
  printf("Valor de *(p++): %d\n", *(p++)); // 1 (p é incrementado depois)
  printf("Valor após *(p++): %d\n", *p);   // 2 (p foi incrementado)

  printf("Valor de *(p + 10): %d\n", *(p + 10)); // 10 (acessa o 11º elemento do array)
  return 0;
}
