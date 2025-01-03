
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "global.h"

int gerarId()
{
  // Gera um numero entre 100 e 999
  return (rand() % 900) + 100;
}
