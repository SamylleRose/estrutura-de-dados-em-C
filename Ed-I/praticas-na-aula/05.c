#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial(int number)
{

  if (number == 0)
  {
    return 1;
  }

  return number * fatorial(number - 1);
}

int main()
{

  int number = 7;

  fatorial(number);

  return 0;
}