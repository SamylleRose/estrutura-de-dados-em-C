#include <stdio.h>

struct fone
{
  char Codigo[4];
  char Area[4];
  char Numero[5];
};

void MostrarFone(void *p, int tipo)
{
  if (tipo == 11)
  {
    char *s = (char *)p;
    printf("(%c%c%c) %c%c%c-%c%c%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9]);
  }
  else
  {
    struct fone *f = (struct fone *)p;
    printf("(%s) %s-%s\n", f->Codigo, f->Area, f->Numero);
  }
}

int main()
{
  char s[11] = "0413301515";
  struct fone f = {"041", "330", "1563"};

  MostrarFone(s, 11);
  MostrarFone(&f, sizeof(struct fone));

  return 0;
}
