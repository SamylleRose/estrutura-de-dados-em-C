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
  char sexo[200];

  Animal *novo = (Animal *)malloc(sizeof(Animal));

  if (novo == NULL)
  {
    printf("Erro na alocação");
    exit(1);
  }

  novo->id = gerarId();

  printf("\nInforme os dados do animal:\n"); // recebe os dados para criar animal

  printf("\nPeso: ");
  scanf("%f", &novo->peso);

  printf("\nSexo: (1 - Femea / 2 - Macho): ");
  scanf("%s", sexo);

  // Operador ternário, se o caractere da posicao 0 for '1' entao e femea se nao macho
  novo->sexo = sexo[0] == '1' ? 'F' : 'M';

  novo->status = menuStatus();

  novo->next = liAnimal;
  return novo;
}

void printAnimal(Animal *animal)
{
  printf("ID: %d\n", animal->id);
  printf("PESO: %.2f\n", animal->peso);
  printf("SEXO: %c\n", animal->sexo);
  printf("STATUS: %s\n\n", statusToString(animal->status));
}

void mostrarAnimal(Animal *liAnimal)
{
  int opcaoFiltro;
  char sexoFiltro[200];
  char sexo;
  int statusFiltro;
  float pesoMin, pesoMax;
  int encontrado = 0;

  printf("\n-------------Filtrar Animais---------------\n");
  printf("1 - Todos\n");
  printf("2 - Filtrar por Sexo\n");
  printf("3 - Filtrar por Status\n");
  printf("4 - Filtrar por Faixa de Peso\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcaoFiltro);

  printf("\n-------------Animais---------------\n");

  switch (opcaoFiltro)
  {
  case 1: // Mostrar todos os animais
    while (liAnimal != NULL)
    {
      printAnimal(liAnimal);
      liAnimal = liAnimal->next;
      encontrado = 1;
    }
    break;

  case 2: // Filtrar por sexo
    printf("Sexo: (1 - Femea / 2 - Macho): ");
    scanf("%s", sexoFiltro);

    // Operador ternário, se o caractere da posicao 0 for '1' entao e femea se nao macho
    sexo = sexoFiltro[0] == '1' ? 'F' : 'M';

    while (liAnimal != NULL)
    {
      if (liAnimal->sexo == sexo)
      {
        printAnimal(liAnimal);
        encontrado = 1;
      }
      liAnimal = liAnimal->next;
    }
    break;

  case 3: // Filtrar por status

    int statusFiltro = menuStatus();

    while (liAnimal != NULL)
    {
      if (liAnimal->status == statusFiltro)
      {
        printAnimal(liAnimal);
        encontrado = 1;
      }
      liAnimal = liAnimal->next;
    }
    break;

  case 4: // Filtrar por faixa de peso
    printf("Digite o peso mínimo: ");
    scanf("%f", &pesoMin);
    printf("Digite o peso máximo: ");
    scanf("%f", &pesoMax);
    while (liAnimal != NULL)
    {
      if (liAnimal->peso >= pesoMin && liAnimal->peso <= pesoMax)
      {
        printAnimal(liAnimal);
        encontrado = 1;
      }
      liAnimal = liAnimal->next;
    }
    break;

  default:
    printf("Opção inválida.\n");
    return;
  }

  if (!encontrado)
  {
    printf("Nenhum animal encontrado com os critérios fornecidos.\n");
  }
}

Animal *atualizarStatus(Animal *liAnimal) // atualiza o status de um animal existente na lista
{

  int status;
  int id;

  printf("\n\nDigite o ID do animal que deseja atualizar: ");
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

  printf("\n\nDigite o ID do animal que deseja remover: ");
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

    printf("\n\nDigite o valor do status: ");
    scanf("%d", &status);

    if (status >= 1 && status <= 5)
    {

      return status - 1;
    }
    else
      printf("\nValor incorreto, tente novamente!\n");
  }
}