
#include <time.h>
#include <stdlib.h>
#include "gerador_id.h"

int gerarId()
{
  // Gera um numero entre 100 e 999
  return (rand() % 900) + 100;
}