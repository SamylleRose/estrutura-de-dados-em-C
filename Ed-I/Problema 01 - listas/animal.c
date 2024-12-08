#include <stdio.h>
#include <stdlib.h>

#include "animal.h"

Animal *criar_animal()
{
  return NULL;
}

void liberar_animal(Animal *li)
{
  Animal *aux;
  while (li != NULL)
  {
    aux = li;
    li = li->next;
    free(aux);
  }
}

Animal *inserir_animal(Animal *li, int id, float peso, StatusAnimal status)
{

  Animal *novo = (Animal *)malloc(sizeof(Animal));

  if (novo == NULL)
  {
    printf("Erro na alocação");
    exit(1);
  }
  novo->id = id;
  novo->peso = peso;
  novo->status = status;
  return novo;
}

const char *status_to_string(StatusAnimal status)
{
  switch (status)
  {
  case EM_CRIACAO:
    return "Em Criação";
  case PARA_VENDA:
    return "Para Venda";
  case VENDIDO:
    return "Vendido";
  case TROCA:
    return "Troca";
  case NASCIMENTO:
    return "Nascimento";
  default:
    return "Desconhecido";
  }
}

void amostrar_animal(Animal *li)
{
  while (li != NULL)
  {
    printf("-------------Animais---------------\n");
    printf("ID: %d\n", li->id);
    printf("PESO: %.2f\n", li->peso);
    printf("Status: %s\n\n", status_to_string(li->status));
    li = li->next;
  }
}
