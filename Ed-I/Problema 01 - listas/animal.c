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

Animal *inserir_animal(Animal *li, int id, float peso, char sexo, StatusAnimal status)
{

  Animal *novo = (Animal *)malloc(sizeof(Animal));

  if (novo == NULL)
  {
    printf("Erro na alocação");
    exit(1);
  }
  novo->id = id;
  novo->peso = peso;
  novo->sexo = sexo;
  novo->status = status;
  novo->next = li;
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
    return "Valor do status inserido incorretamente!";
  }
}

void mostrar_animal(Animal *li)
{

  printf("-------------Animais---------------\n");
  while (li != NULL)
  {

    printf("ID: %d\n", li->id);
    printf("PESO: %.2f\n", li->peso);
    printf("SEXO: %c\n", li->sexo);
    printf("STATUS: %s\n\n", status_to_string(li->status));
    li = li->next;
  }
}

Animal *atualizar_status(Animal *li, int id)
{

  if (li == NULL)
  {
    printf("Erro: Lista vazia.\n");
    return li;
  }

  int status;

  Animal *aux = li;
  while (aux != NULL)
  {
    if (aux->id == id)
    {

      while (1)
      {
        printf("1 - Em Criação\n");
        printf("2 - Para Venda\n");
        printf("3 - Vendido\n");
        printf("4 - Troca\n");
        printf("5 - Nascimento\n");

        printf("Digite o valor novo status: ");
        scanf("%d", &status);

        if (status >= 1 && status <= 5)
        {
          aux->status = status - 1;
          return li;
        }
        else
          printf("Valor incorreto, tente novamente!\n");
      }
    }

    aux = aux->next;
  }

  printf("Erro: ID %d não encontrado na lista.\n", id);
  return li;
}

Animal *remover_animal(Animal *li, int id)
{

  if (li == NULL)
  {
    printf("Erro: Lista vazia.\n");
    return li;
  }

  Animal *ant = NULL;
  Animal *aux = li;

  while (aux != NULL && aux->id != id)
  {
    ant = aux;
    aux = aux->next;
  }
  if (aux == NULL)
  {
    printf("\nAnimal não encontrado! tente novamente.\n");
    return li;
  }

  if (ant == NULL)
  {
    printf("\nAnimal removido com sucesso!\n");

    li = aux->next;
  }
  else
  {
    printf("\nAnimal removido com sucesso!\n");
    ant->next = aux->next;
  }

  free(aux);

  return li;
}