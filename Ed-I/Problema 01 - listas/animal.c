#include <stdio.h>
#include <stdlib.h>

#include "animal.h"

Animal *criarAnimal()
{

  Animal *animal = (Animal *)malloc(sizeof(Animal));

  if (animal == NULL)
  {
    printf("Erro ao alocar memória para a fazenda.\n");
    exit(1);
  }

  animal = NULL;
  return NULL;
}

void liberarAnimal(Animal *liAnimal)
{
  Animal *aux;
  while (liAnimal != NULL)
  {
    aux = liAnimal;
    liAnimal = liAnimal->next;
    free(aux);
  }
}

Animal *inserirAnimal(Animal *liAnimal, int id, float peso, char sexo, StatusAnimal status)
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

  novo->next = liAnimal;
  return novo;
}

const char *statusToString(StatusAnimal status)
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

void mostrarAnimal(Animal *liAnimal)
{

  printf("\n-------------Animais---------------\n");
  while (liAnimal != NULL)
  {

    printf("ID: %d\n", liAnimal->id);
    printf("PESO: %.2f\n", liAnimal->peso);
    printf("SEXO: %c\n", liAnimal->sexo);
    printf("STATUS: %s\n\n", statusToString(liAnimal->status));
    liAnimal = liAnimal->next;
  }
}

int menuStatus()
{
  int status;
  while (1)
  {
    printf("\nEscolha o status do animal\n");

    printf("1 - Em Criação\n");
    printf("2 - Para Venda\n");
    printf("3 - Vendido\n");
    printf("4 - Troca\n");
    printf("5 - Nascimento\n");

    printf("Digite o valor do status: ");
    scanf("%d", &status);

    if (status >= 1 && status <= 5)
    {

      return status - 1;
    }
    else
      printf("\nValor incorreto, tente novamente!\n");
  }
}

Animal *atualizarStatus(Animal *liAnimal)
{

  int status;
  int id;

  printf("\nDigite o ID do animal que deseja atualizar: ");
  scanf("%d", &id);

  Animal *aux = liAnimal;
  while (aux != NULL)
  {
    if (aux->id == id)
    {
      aux->status = menuStatus();
      return liAnimal;
    }

    aux = aux->next;
  }

  printf("\nErro: ID %d não encontrado na lista.\n", id);
  return liAnimal;
}

Animal *removerAnimal(Animal *liAnimal)
{

  int id;

  printf("\nDigite o ID do animal que deseja remover: ");
  scanf("%d", &id);

  Animal *ant = NULL;
  Animal *aux = liAnimal;

  while (aux != NULL && aux->id != id)
  {
    ant = aux;
    aux = aux->next;
  }
  if (aux == NULL)
  {
    printf("\nAnimal não encontrado! tente novamente.\n");
    return liAnimal;
  }

  if (ant == NULL)
  {
    printf("\nAnimal removido com sucesso!\n");

    liAnimal = aux->next;
  }
  else
  {
    printf("\nAnimal removido com sucesso!\n");
    ant->next = aux->next;
  }

  free(aux);

  return liAnimal;
}