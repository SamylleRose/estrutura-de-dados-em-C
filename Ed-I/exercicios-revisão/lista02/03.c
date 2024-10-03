#include <stdio.h>
#include <ctype.h>
#include <string.h>

void inverter_string(char *str)
{
  int len = strlen(str);
  char inicio = 0;
  char fim = len - 1;
  char temp;

  while (inicio < fim)
  {
    temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    inicio++;
    fim--;
  }
}
void minusculo(char *str)
{
  while (*str != '\0')
  {
    *str = tolower(*str);
    str++;
  }
}

void maiusculo(char *str)
{
  while (*str != '\0')
  {
    *str = toupper(*str);
    str++;
  }
}

int main()
{

  char string[100];
  int escolha = 0;

  printf("Digite uma string: ");
  scanf("%s", string);

  while (escolha != 4)
  {
    printf("Escolha uma opcao:\n");
    printf("1 - Inverter a string\n");
    printf("2 - Converter para minusculo\n");
    printf("3 - Converter para maiusculo\n");
    printf("4 - Sair\n\n");

    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      inverter_string(string);
      printf("String invertida: %s\n", string);
      break;
    case 2:
      minusculo(string);
      printf("String convertida para minusculo: %s\n", string);
      break;
    case 3:
      maiusculo(string);
      printf("String convertida para maiusculo: %s\n", string);
      break;
    default:
      printf("Escolha invalida.\n");
    }
  }

  return 0;
}