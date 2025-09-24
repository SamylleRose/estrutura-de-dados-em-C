#include <stdlib.h>
#include <string.h>
#include "apresentador.h"
#include "stream.h"

void cadastrarApresentador(Apresentador **inicioLista, char nome[], char categoria[], char stream[])
{
  Apresentador *novoApresentador = (Apresentador *)malloc(sizeof(Apresentador));
  if (novoApresentador == NULL)
  {
    printf("\nERRO: Falha na alocacao de memoria para o novo apresentador.\n");
    exit(1);
  }

  strcpy(novoApresentador->nome, nome);
  strcpy(novoApresentador->categoriaTrabalho, categoria);
  strcpy(novoApresentador->streamTrabalhaAtualmente, stream);
  novoApresentador->idade = 0;

  novoApresentador->historico = NULL;

  novoApresentador->proximo = NULL;
  novoApresentador->anterior = NULL;

  if (*inicioLista == NULL)
  {
    *inicioLista = novoApresentador;
  }
  else
  {
    Apresentador *atual = *inicioLista;
    Apresentador *anterior = NULL;

    while (atual != NULL && strcmp(novoApresentador->nome, atual->nome) > 0)
    {
      anterior = atual;
      atual = atual->proximo;
    }

    if (anterior == NULL)
    {
      novoApresentador->proximo = *inicioLista;
      (*inicioLista)->anterior = novoApresentador;
      *inicioLista = novoApresentador;
    }
    else
    {
      novoApresentador->proximo = atual;
      novoApresentador->anterior = anterior;
      anterior->proximo = novoApresentador;
      if (atual != NULL)
      {
        atual->anterior = novoApresentador;
      }
    }
  }

  printf("Apresentador '%s' cadastrado com sucesso!\n", nome);
}

void mostrarApresentadores(Apresentador *inicioLista)
{
  Apresentador *atual = inicioLista;
  if (atual == NULL)
  {
    printf("Nenhum apresentador cadastrado.\n");
    return;
  }

  printf("\n===== Lista de Apresentadores =====\n");
  while (atual != NULL)
  {
    printf("------------------------------------\n");
    printf("Nome: %s\nCategoria: %s\nStream Atual: %s\n",
           atual->nome, atual->categoriaTrabalho, atual->streamTrabalhaAtualmente);

    printf("Historico de Trabalhos:\n");
    if (atual->historico == NULL)
    {
      printf("  -> Nenhum trabalho anterior cadastrado.\n");
    }
    else
    {
      HistoricoTrabalho *hist = atual->historico;

      while (hist != NULL)
      {
        printf("  -> Stream: %-15s (Periodo: %02d/%02d/%d a %02d/%02d/%d)\n",
               hist->nomeStream,
               hist->dataInicio.dia, hist->dataInicio.mes, hist->dataInicio.ano,
               hist->dataTermino.dia, hist->dataTermino.mes, hist->dataTermino.ano);
        hist = hist->proximo;
      }
    }
    atual = atual->proximo;
  }
  printf("------------------------------------\n");
}

Apresentador *buscarApresentador(Apresentador *inicioLista, char nome[])

{
  Apresentador *atual = inicioLista;

  while (atual != NULL)
  {
    if (strcmp(atual->nome, nome) == 0)
    {
      return atual;
    }
    atual = atual->proximo;
  }

  return NULL;
}

Apresentador *selecionarApresentadorDeStream(Apresentador *listaCompleta, char nomeStream[])
{

  Apresentador *apresentadorSelecionado = NULL;

  if (listaCompleta == NULL)
  {
    printf("Nenhum apresentador cadastrado no sistema!\n");
  }
  else
  {

    Apresentador *arrayFiltrado[200];
    int contador = 0;
    Apresentador *atual = listaCompleta;

    while (atual != NULL)
    {
      if (strcmp(atual->streamTrabalhaAtualmente, nomeStream) == 0)
      {
        if (contador < 200)
        {
          arrayFiltrado[contador++] = atual;
        }
      }
      atual = atual->proximo;
    }

    if (contador == 0)
    {
      printf("Nenhum apresentador cadastrado para a stream '%s'!\n", nomeStream);
    }
    else
    {

      printf("Apresentadores disponiveis para a stream '%s':\n", nomeStream);
      for (int i = 0; i < contador; i++)
      {
        printf("  %d. "
               "%s (Categoria: %s)\n",
               i + 1, arrayFiltrado[i]->nome, arrayFiltrado[i]->categoriaTrabalho);
      }

      int escolha;
      printf("Digite o numero do apresentador: ");
      scanf("%d", &escolha);

      if (escolha > 0 && escolha <= contador)
      {

        apresentadorSelecionado = arrayFiltrado[escolha - 1];
      }
      else
      {
        printf("Selecao invalida!\n");
      }
    }
  }

  return apresentadorSelecionado;
}

void mostrarApresentadoresDeStream(Apresentador *inicioLista, char nomeStream[])
{
  Apresentador *atual = inicioLista;
  int encontrado = 0;

  printf("\n--- Apresentadores da Stream '%s' ---\n", nomeStream);
  while (atual != NULL)
  {
    if (strcmp(atual->streamTrabalhaAtualmente, nomeStream) == 0)
    {

      printf("------------------------------------\n");
      printf("Nome: %s\nCategoria: %s\n",
             atual->nome, atual->categoriaTrabalho);

      printf("Historico de Trabalhos:\n");
      if (atual->historico == NULL)
      {
        printf("  -> Nenhum trabalho anterior cadastrado.\n");
      }
      else
      {
        HistoricoTrabalho *hist = atual->historico;
        while (hist != NULL)
        {
          printf("  -> Stream: %-15s (Periodo: %02d/%02d/%d a %02d/%02d/%d)\n",
                 hist->nomeStream,
                 hist->dataInicio.dia, hist->dataInicio.mes, hist->dataInicio.ano,
                 hist->dataTermino.dia, hist->dataTermino.mes, hist->dataTermino.ano);
          hist = hist->proximo;
        }
      }
      encontrado = 1;
    }
    atual = atual->proximo;
  }

  if (!encontrado)
  {
    printf("Nenhum apresentador encontrado para a stream '%s'.\n", nomeStream);
  }
  else
  {
    printf("------------------------------------\n");
  }
}

void mostrarApresentadoresDeCategoria(Apresentador *inicioLista, char nomeCategoria[])
{
  Apresentador *atual = inicioLista;
  int encontrado = 0;

  printf("\n--- Apresentadores da Categoria '%s' ---\n", nomeCategoria);
  while (atual != NULL)
  {
    if (strcmp(atual->categoriaTrabalho, nomeCategoria) == 0)
    {

      printf("------------------------------------\n");
      printf("Nome: %s\nStream Atual: %s\n",
             atual->nome, atual->streamTrabalhaAtualmente);

      printf("Historico de Trabalhos:\n");
      if (atual->historico == NULL)
      {
        printf("  -> Nenhum trabalho anterior cadastrado.\n");
      }
      else
      {
        HistoricoTrabalho *hist = atual->historico;
        while (hist != NULL)
        {
          printf("  -> Stream: %-15s (Periodo: %02d/%02d/%d a %02d/%02d/%d)\n",
                 hist->nomeStream,
                 hist->dataInicio.dia, hist->dataInicio.mes, hist->dataInicio.ano,
                 hist->dataTermino.dia, hist->dataTermino.mes, hist->dataTermino.ano);
          hist = hist->proximo;
        }
      }
      encontrado = 1;
    }
    atual = atual->proximo;
  }

  if (!encontrado)
  {
    printf("Nenhum apresentador encontrado para a categoria '%s'.\n", nomeCategoria);
  }
  else
  {
    printf("------------------------------------\n");
  }
}

void alterarStreamApresentador(Apresentador *listaApresentadores, Stream *raizStreams, char nomeApresentador[], char novaStream[])
{
  printf("\nTentando alterar a stream de '%s' para '%s'...\n", nomeApresentador, novaStream);
  Stream *s = buscarStream(raizStreams, novaStream);

  if (s)
  {
    Apresentador *ap = buscarApresentador(listaApresentadores, nomeApresentador);
    if (ap)
    {
      HistoricoTrabalho *novoHistorico = (HistoricoTrabalho *)malloc(sizeof(HistoricoTrabalho));
      if (novoHistorico)
      {

        strcpy(novoHistorico->nomeStream, ap->streamTrabalhaAtualmente);

        printf("  Por favor, informe o periodo do trabalho na stream '%s'.\n", ap->streamTrabalhaAtualmente);
        printf("  Digite a data de inicio (dd mm aaaa): ");
        scanf("%d %d %d", &novoHistorico->dataInicio.dia, &novoHistorico->dataInicio.mes, &novoHistorico->dataInicio.ano);

        printf("  Digite a data de termino (dd mm aaaa): ");
        scanf("%d %d %d", &novoHistorico->dataTermino.dia, &novoHistorico->dataTermino.mes, &novoHistorico->dataTermino.ano);

        novoHistorico->proximo = ap->historico;
        ap->historico = novoHistorico;

        strcpy(ap->streamTrabalhaAtualmente, novaStream);
        printf("  Sucesso! A stream de '%s' foi alterada e o trabalho anterior foi registrado no historico.\n", nomeApresentador);
      }
      else
      {
        printf("  ERRO: Falha ao alocar memoria para o historico.\n");
      }
    }
    else
    {
      printf("  ERRO: Apresentador '%s' nao encontrado.\n", nomeApresentador);
    }
  }
  else
  {
    printf("  ERRO: A nova stream '%s' nao existe.\n", novaStream);
  }
}