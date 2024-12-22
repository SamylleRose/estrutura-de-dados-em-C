#include <stdio.h>
#include <stdlib.h>

#include "animal.h"

void liberarAnimal(Animal *liAnimal) // libera memoria da lista animal
{
  Animal *aux;
  while (liAnimal != NULL)
  {
    aux = liAnimal;
    liAnimal = liAnimal->next;
    free(aux);
  }
}

Animal *inserirAnimal(Animal *liAnimal)
{

  Animal *novo = (Animal *)malloc(sizeof(Animal));

  if (novo == NULL)
  {
    printf("Erro na alocação");
    exit(1);
  }

  int novoId = gerarId();

  printf("\nInforme os dados do animal:\n"); // recebe os dados para criar animal

  printf("\nPeso: ");
  scanf("%f", &novo->peso);

  printf("\nSexo: (M/F) ");
  scanf("%s", &novo->sexo);

  novo->status = menuStatus();

  novo->next = liAnimal;
  return novo;
}

void mostrarAnimal(Animal *liAnimal) // mostra dados do animal
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

Animal *atualizarStatus(Animal *liAnimal) // atualiza o status de um animal existente na lista
{

  int status;
  int id;

  printf("\nDigite o ID do animal que deseja atualizar: ");
  scanf("%d", &id);

  Animal *aux = liAnimal;
  while (aux != NULL)
  {
    if (aux->id == id) // caso o id for encontrado.
    {
      aux->status = menuStatus();
      return liAnimal;
    }

    aux = aux->next;
  }

  printf("\nErro: ID %d não encontrado na lista.\n", id); // caso id não seja encontrado
  return liAnimal;
}

Animal *removerAnimal(Animal *liAnimal) // remove um animal da lista
{

  int id;

  printf("\nDigite o ID do animal que deseja remover: ");
  scanf("%d", &id);

  Animal *ant = NULL; // inicializa os ponteiros
  Animal *aux = liAnimal;

  while (aux != NULL && aux->id != id) // busca o animal na lista
  {
    ant = aux;
    aux = aux->next;
  }
  if (aux == NULL) // caso o animal não for encontrado
  {
    printf("\nAnimal não encontrado! tente novamente.\n");
    return liAnimal;
  }

  if (ant == NULL) // caso o animal é o primeiro da lista
  {
    printf("\nAnimal removido com sucesso!\n");
    liAnimal = aux->next;
  }
  else // caso o animal estiver no meio ou fim
  {
    printf("\nAnimal removido com sucesso!\n");
    ant->next = aux->next;
  }

  free(aux); // libera a memoria

  return liAnimal;
}

const char *statusToString(StatusAnimal status) // função que passa os status do animal para texto
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

int menuStatus() // menu para inserir o status do animal
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