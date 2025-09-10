#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stream.h"
#include "categoria.h"
#include "apresentador.h"
#include "programa.h"

#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"

void paraMinusculo(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    str[i] = tolower((unsigned char)str[i]);
  }
}

void menuGerenciarStreams(Stream **raizStreams);
void menuGerenciarProgramas(Stream *raizStreams, Apresentador *listaApresentadores);
void menuGerenciarApresentadores(Stream *raizStreams, Apresentador **listaApresentadores);
void menuRelatorios(Stream *raizStreams, Apresentador *listaApresentadores);

Stream *selecionarStream(Stream *raiz);
Categoria *selecionarCategoria(Stream *stream);
Apresentador *selecionarApresentador(Apresentador *lista);
Programa *selecionarPrograma(Categoria *categoria);

int main()
{
  Stream *raizStreams = NULL;
  Apresentador *listaApresentadores = NULL;
  int opcao;

  do
  {
    printf(BOLD CYAN "\n\n===== BIBLIOTECA DE STREAMS (MENU PRINCIPAL) =====\n" RESET);
    printf(CYAN "1." RESET " Gerenciar Streams e Categorias\n");
    printf(CYAN "2." RESET " Gerenciar Programas\n");
    printf(CYAN "3." RESET " Gerenciar Apresentadores\n");
    printf(CYAN "4." RESET " Relatorios e Consultas\n");
    printf(RED "0. Sair\n" RESET);
    printf(BOLD CYAN "====================================================\n" RESET);
    printf("Escolha uma area: ");
    scanf("%d", &opcao);
    while (getchar() != '\n')
      ;

    switch (opcao)
    {
    case 1:
      menuGerenciarStreams(&raizStreams);
      break;
    case 2:
      menuGerenciarProgramas(raizStreams, listaApresentadores);
      break;
    case 3:
      menuGerenciarApresentadores(raizStreams, &listaApresentadores);
      break;
    case 4:
      menuRelatorios(raizStreams, listaApresentadores);
      break;
    case 0:
      printf(YELLOW "Saindo do programa...\n" RESET);
      break;
    default:
      printf(RED "Opcao invalida! Tente novamente.\n" RESET);
    }
    if (opcao != 0)
    {
      printf(YELLOW "\nPressione Enter para voltar ao Menu Principal..." RESET);
      getchar();
    }
  } while (opcao != 0);
  return 0;
}

void menuGerenciarStreams(Stream **raizStreams)
{
  int opcao;
  printf(BOLD GREEN "\n--- Gerenciar Streams e Categorias ---\n" RESET);
  printf("1. Cadastrar nova Stream\n");
  printf("2. Adicionar Categoria a uma Stream\n");
  printf("3. Remover Categoria de uma Stream\n");
  printf(RED "0. Voltar\n" RESET);
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  while (getchar() != '\n')
    ;

  switch (opcao)
  {
  case 1:
  {
    char nome[100], site[100];
    printf("Digite o nome da Stream: ");
    scanf(" %[^\n]", nome);
    paraMinusculo(nome); // NORMALIZA
    printf("Digite o site da Stream: ");
    scanf(" %[^\n]", site);
    *raizStreams = cadastrarStream(*raizStreams, nome, site);
    break;
  }
  case 2:
  {
    printf("Selecione a Stream para adicionar a categoria:\n");
    Stream *streamAlvo = selecionarStream(*raizStreams);
    if (streamAlvo)
    {
      char nomeCat[100], tipoCat[100];
      printf("Digite o nome da nova Categoria: ");
      scanf(" %[^\n]", nomeCat);
      paraMinusculo(nomeCat); // NORMALIZA
      printf("Digite o tipo da Categoria (Noticias, Esporte, etc.): ");
      scanf(" %[^\n]", tipoCat);
      paraMinusculo(tipoCat); // NORMALIZA
      cadastrarCategoriaNaStream(*raizStreams, streamAlvo->nome, nomeCat, tipoCat);
    }
    break;
  }
  case 3:
  {
    printf("Selecione a Stream para remover a categoria:\n");
    Stream *streamAlvo = selecionarStream(*raizStreams);
    if (streamAlvo)
    {
      printf("Selecione a Categoria a ser removida:\n");
      Categoria *catAlvo = selecionarCategoria(streamAlvo);
      if (catAlvo)
      {
        removerCategoria(*raizStreams, streamAlvo->nome, catAlvo->nome);
      }
    }
    break;
  }
  case 0:
    break;
  default:
    printf(RED "Opcao invalida!\n" RESET);
  }
}

void menuGerenciarProgramas(Stream *raizStreams, Apresentador *listaApresentadores)
{
  int opcao;
  printf(BOLD MAGENTA "\n--- Gerenciar Programas ---\n" RESET);
  printf("1. Cadastrar novo Programa\n");
  printf("2. Remover Programa\n");
  printf(RED "0. Voltar\n" RESET);
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  while (getchar() != '\n')
    ;

  switch (opcao)
  {
  case 1:
  {
    printf("Selecione a Stream do programa:\n");
    Stream *s = selecionarStream(raizStreams);
    if (!s)
      break;
    printf("Selecione a Categoria do programa:\n");
    Categoria *c = selecionarCategoria(s);
    if (!c)
      break;
    printf("Selecione o Apresentador do programa:\n");
    Apresentador *a = selecionarApresentador(listaApresentadores);
    if (!a)
      break;

    char np[100], per[50], tipo[50];
    int tempo, horario;
    printf("Nome do novo programa: ");
    scanf(" %[^\n]", np);
    paraMinusculo(np);
    printf("Periodicidade (Diario, Semanal...): ");
    scanf(" %[^\n]", per);
    paraMinusculo(per);
    printf("Tipo (Ao vivo, Sob Demanda): ");
    scanf(" %[^\n]", tipo);
    paraMinusculo(tipo);
    printf("Tempo de duracao (minutos): ");
    scanf("%d", &tempo);
    printf("Horario de inicio (ex: 2130): ");
    scanf("%d", &horario);
    cadastrarPrograma(raizStreams, listaApresentadores, s->nome, c->nome, np, per, tempo, horario, tipo, a->nome);
    break;
  }
  case 2:
  {
    printf("Selecione a Stream do programa a ser removido:\n");
    Stream *s = selecionarStream(raizStreams);
    if (!s)
      break;
    printf("Selecione a Categoria do programa a ser removido:\n");
    Categoria *c = selecionarCategoria(s);
    if (!c)
      break;
    printf("Selecione o Programa a ser removido:\n");
    Programa *p = selecionarPrograma(c);
    if (!p)
      break;
    removerPrograma(raizStreams, s->nome, c->nome, p->nome);
    break;
  }
  case 0:
    break;
  default:
    printf(RED "Opcao invalida!\n" RESET);
  }
}

void menuGerenciarApresentadores(Stream *raizStreams, Apresentador **listaApresentadores)
{
  int opcao;
  printf(BOLD BLUE "\n--- Gerenciar Apresentadores ---\n" RESET);
  printf("1. Cadastrar novo Apresentador\n");
  printf("2. Alterar Stream de um Apresentador\n");
  printf(RED "0. Voltar\n" RESET);
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  while (getchar() != '\n')
    ;

  switch (opcao)
  {
  case 1:
  {
    char nome[100], cat[100];
    printf("Nome do Apresentador: ");
    scanf(" %[^\n]", nome);
    paraMinusculo(nome);
    printf("Categoria em que trabalha: ");
    scanf(" %[^\n]", cat);
    paraMinusculo(cat);
    printf("Selecione a Stream em que trabalha:\n");
    Stream *s = selecionarStream(raizStreams);
    if (s)
    {
      cadastrarApresentador(listaApresentadores, nome, cat, s->nome);
    }
    break;
  }
  case 2:
  {
    printf("Selecione o Apresentador a ser alterado:\n");
    Apresentador *ap = selecionarApresentador(*listaApresentadores);
    if (ap)
    {
      printf("Selecione a NOVA stream para '%s':\n", ap->nome);
      Stream *novaStream = selecionarStream(raizStreams);
      if (novaStream)
      {
        alterarStreamApresentador(*listaApresentadores, raizStreams, ap->nome, novaStream->nome);
      }
    }
    break;
  }
  case 0:
    break;
  default:
    printf(RED "Opcao invalida!\n" RESET);
  }
}

void menuRelatorios(Stream *raizStreams, Apresentador *listaApresentadores)
{
  int opcao;
  printf(BOLD YELLOW "\n--- Relatorios e Consultas ---\n" RESET);
  printf(" 1. Listar todas as Streams\n");
  printf(" 2. Listar Categorias de uma Stream\n");
  printf(" 3. Listar Programas de uma Categoria\n");
  printf(" 4. Listar Programas por Periodicidade (em uma Categoria)\n");
  printf(" 5. Listar Programas por Periodicidade e Horario (em uma Stream inteira)\n");
  printf(" 6. Listar Streams que possuem uma Categoria especifica\n");
  printf(" 7. Listar Streams que possuem um Tipo de Categoria\n");
  printf(" 8. Listar Apresentadores de uma Stream\n");
  printf(" 9. Listar Apresentadores de uma Categoria\n");
  printf("10. Buscar Dados de um Programa\n");
  printf(RED " 0. Voltar\n" RESET);
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  while (getchar() != '\n')
    ;

  switch (opcao)
  {
  case 1:
    mostrarStreams(raizStreams);
    break;
  case 2:
  {
    Stream *s = selecionarStream(raizStreams);
    if (s)
      mostrarCategoriasDeStream(raizStreams, s->nome);
    break;
  }
  case 3:
  {
    Stream *s = selecionarStream(raizStreams);
    if (s)
    {
      Categoria *c = selecionarCategoria(s);
      if (c)
        mostrarProgramasDeCategoria(raizStreams, s->nome, c->nome);
    }
    break;
  }
  case 4:
  {
    char periodicidade[100];
    Stream *s = selecionarStream(raizStreams);
    if (s)
    {
      Categoria *c = selecionarCategoria(s);
      if (c)
      {
        printf("Digite a periodicidade a ser buscada (ex: diario, semanal): ");
        scanf(" %[^\n]", periodicidade);
        paraMinusculo(periodicidade); // NORMALIZA
        mostrarProgramasPorPeriodicidade(raizStreams, s->nome, c->nome, periodicidade);
      }
    }
    break;
  }
  case 5:
  {
    char dia[100];
    int horario;
    Stream *s = selecionarStream(raizStreams);
    if (s)
    {
      printf("Digite a periodicidade (ex: diario, semanal): ");
      scanf(" %[^\n]", dia);
      paraMinusculo(dia); // NORMALIZA
      printf("Digite o horario (ex: 2130): ");
      scanf("%d", &horario);
      mostrarProgramasPorDiaEHorarioNaStream(raizStreams, s->nome, dia, horario);
    }
    break;
  }
  case 6:
  {
    char nc[100];
    printf("Digite o nome da Categoria a buscar: ");
    scanf(" %[^\n]", nc);
    paraMinusculo(nc);
    mostrarStreamsComCategoria(raizStreams, nc);
    break;
  }
  case 7:
  {
    char tc[100];
    printf("Digite o Tipo de Categoria a buscar (noticias, esporte, etc): ");
    scanf(" %[^\n]", tc);
    paraMinusculo(tc);
    mostrarStreamsComTipoCategoria(raizStreams, tc);
    break;
  }
  case 8:
  {
    Stream *s = selecionarStream(raizStreams);
    if (s)
      mostrarApresentadoresDeStream(listaApresentadores, s->nome);
    break;
  }
  case 9:
  {
    char nc[100];
    printf("Digite o nome da Categoria para listar apresentadores: ");
    scanf(" %[^\n]", nc);
    paraMinusculo(nc);
    mostrarApresentadoresDeCategoria(listaApresentadores, nc);
    break;
  }
  case 10:
  {
    char ns[100], nc[100], np[100];
    printf("Digite o nome da Stream: ");
    scanf(" %[^\n]", ns);
    paraMinusculo(ns);
    printf("Digite o nome da Categoria: ");
    scanf(" %[^\n]", nc);
    paraMinusculo(nc);
    printf("Digite o nome do Programa: ");
    scanf(" %[^\n]", np);
    paraMinusculo(np);
    mostrarDadosPrograma(raizStreams, ns, nc, np);
    break;
  }
  case 0:
    break;
  default:
    printf(RED "Opcao invalida!\n" RESET);
  }
}

void _popularArrayStream(Stream *raiz, Stream *array[], int *indice)
{
  if (raiz == NULL)
    return;
  _popularArrayStream(raiz->esquerda, array, indice);
  array[*indice] = raiz;
  (*indice)++;
  _popularArrayStream(raiz->direita, array, indice);
}

Stream *selecionarStream(Stream *raiz)
{
  if (raiz == NULL)
  {
    printf(RED "Nenhuma stream cadastrada!\n" RESET);
    return NULL;
  }
  Stream *arrayDeStreams[200];
  int contador = 0;
  _popularArrayStream(raiz, arrayDeStreams, &contador);

  if (contador == 0)
  {
    printf(RED "Nenhuma stream encontrada na estrutura de dados!\n" RESET);
    return NULL;
  }
  printf("Streams disponiveis:\n");
  for (int i = 0; i < contador; i++)
  {
    printf(GREEN "  %d. " RESET "%s\n", i + 1, arrayDeStreams[i]->nome);
  }
  int escolha;
  printf("Digite o numero da stream: ");
  scanf("%d", &escolha);
  while (getchar() != '\n')
    ;
  if (escolha > 0 && escolha <= contador)
  {
    return arrayDeStreams[escolha - 1];
  }
  else
  {
    printf(RED "Selecao invalida!\n" RESET);
    return NULL;
  }
}

Categoria *selecionarCategoria(Stream *stream)
{
  if (stream->listaCategorias == NULL)
  {
    printf(RED "Nenhuma categoria cadastrada para esta stream!\n" RESET);
    return NULL;
  }
  Categoria *arrayDeCategorias[100];
  int contador = 0;
  Categoria *atual = stream->listaCategorias;
  do
  {
    arrayDeCategorias[contador++] = atual;
    atual = atual->proxima;
  } while (atual != stream->listaCategorias);
  printf("Categorias disponiveis:\n");
  for (int i = 0; i < contador; i++)
  {
    printf(YELLOW "  %d. " RESET "%s\n", i + 1, arrayDeCategorias[i]->nome);
  }
  int escolha;
  printf("Digite o numero da categoria: ");
  scanf("%d", &escolha);
  while (getchar() != '\n')
    ;
  if (escolha > 0 && escolha <= contador)
  {
    return arrayDeCategorias[escolha - 1];
  }
  else
  {
    printf(RED "Selecao invalida!\n" RESET);
    return NULL;
  }
}

Apresentador *selecionarApresentador(Apresentador *lista)
{
  if (lista == NULL)
  {
    printf(RED "Nenhum apresentador cadastrado!\n" RESET);
    return NULL;
  }
  Apresentador *arrayDeApresentadores[200];
  int contador = 0;
  Apresentador *atual = lista;
  while (atual != NULL)
  {
    arrayDeApresentadores[contador++] = atual;
    atual = atual->proximo;
  }
  printf("Apresentadores disponiveis:\n");
  for (int i = 0; i < contador; i++)
  {
    printf(BLUE "  %d. " RESET "%s\n", i + 1, arrayDeApresentadores[i]->nome);
  }
  int escolha;
  printf("Digite o numero do apresentador: ");
  scanf("%d", &escolha);
  while (getchar() != '\n')
    ;
  if (escolha > 0 && escolha <= contador)
  {
    return arrayDeApresentadores[escolha - 1];
  }
  else
  {
    printf(RED "Selecao invalida!\n" RESET);
    return NULL;
  }
}

void _popularArrayPrograma(Programa *raiz, Programa *array[], int *indice)
{
  if (raiz == NULL)
    return;
  _popularArrayPrograma(raiz->esquerda, array, indice);
  array[*indice] = raiz;
  (*indice)++;
  _popularArrayPrograma(raiz->direita, array, indice);
}

Programa *selecionarPrograma(Categoria *categoria)
{
  if (categoria->arvoreProgramas == NULL)
  {
    printf(RED "Nenhum programa cadastrado nesta categoria!\n" RESET);
    return NULL;
  }
  Programa *arrayDeProgramas[200];
  int contador = 0;
  _popularArrayPrograma(categoria->arvoreProgramas, arrayDeProgramas, &contador);

  if (contador == 0)
  {
    printf(RED "Nenhum programa encontrado na estrutura de dados!\n" RESET);
    return NULL;
  }
  printf("Programas disponiveis:\n");
  for (int i = 0; i < contador; i++)
  {
    printf(MAGENTA "  %d. " RESET "%s\n", i + 1, arrayDeProgramas[i]->nome);
  }
  int escolha;
  printf("Digite o numero do programa: ");
  scanf("%d", &escolha);
  while (getchar() != '\n')
    ;
  if (escolha > 0 && escolha <= contador)
  {
    return arrayDeProgramas[escolha - 1];
  }
  else
  {
    printf(RED "Selecao invalida!\n" RESET);
    return NULL;
  }
}