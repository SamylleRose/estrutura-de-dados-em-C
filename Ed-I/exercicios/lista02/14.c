#include <stdio.h>

int main()
{
  int y, *p, x;

  y = 0; // Atribui 0 para y. Neste ponto, y = 0.

  p = &y; // O ponteiro p passa a apontar para o endereço de y (p contém o endereço de y).

  x = *p; // Atribui a x o valor apontado por p, que é o valor de y (x = 0, pois y = 0).

  x = 4; // Atribui 4 para x. Agora, x = 4.

  (*p)++; // Incrementa o valor apontado por p (que é y). Como p aponta para y, y passa de 0 para 1. Agora, y = 1.

  x--; // Decrementa x. Como x era 4, agora x = 3.

  (*p) += x; // Adiciona o valor de x (3) ao valor apontado por p (que é y). y = y + 3, ou seja, y = 1 + 3. Agora, y = 4.

  printf("y = %d\n", y); // Exibe o valor de y. No final, y = 4.

  return 0;
}
