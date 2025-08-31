#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inclui os cabeçalhos de todos os seus módulos
#include "stream.h"
#include "categoria.h"
#include "apresentador.h"
#include "programa.h"

// --- DEFINIÇÃO DE CORES ANSI ---
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"

// --- PROTÓTIPOS DAS FUNÇÕES DE MENU E AJUDANTES ---
void popularDadosTeste(Stream **raizStreams, Apresentador **listaApresentadores);

// Menus
void menuGerenciarStreams(Stream **raizStreams);
void menuGerenciarProgramas(Stream *raizStreams, Apresentador *listaApresentadores);
void menuGerenciarApresentadores(Stream *raizStreams, Apresentador **listaApresentadores);
void menuRelatorios(Stream *raizStreams, Apresentador *listaApresentadores);

// Funções de Seleção Interativa
Stream *selecionarStream(Stream *raiz);
Categoria *selecionarCategoria(Stream *stream);
Apresentador *selecionarApresentador(Apresentador *lista);
Programa *selecionarPrograma(Categoria *categoria); // <-- NOVO!

// --- FUNÇÃO PRINCIPAL ---
int main()
{
  Stream *raizStreams = NULL;
  Apresentador *listaApresentadores = NULL;
  int opcao;

  popularDadosTeste(&raizStreams, &listaApresentadores);

  do
  {
    // system("clear || cls"); // Limpa a tela
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
      ; // Limpa o buffer

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

  // liberarTodaMemoria(raizStreams, listaApresentadores);
  return 0;
}

// --- SUB-MENU PARA PROGRAMAS (ATUALIZADO) ---
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
    printf("Periodicidade (Diario, Semanal...): ");
    scanf(" %[^\n]", per);
    printf("Tipo (Ao vivo, Sob Demanda): ");
    scanf(" %[^\n]", tipo);
    printf("Tempo de duracao (minutos): ");
    scanf("%d", &tempo);
    printf("Horario de inicio (ex: 2130): ");
    scanf("%d", &horario);
    cadastrarPrograma(raizStreams, listaApresentadores, s->nome, c->nome, np, per, tempo, horario, tipo, a->nome);
    break;
  }
  case 2:
  { // <-- LÓGICA DE REMOÇÃO ATUALIZADA
    printf("Selecione a Stream do programa a ser removido:\n");
    Stream *s = selecionarStream(raizStreams);
    if (!s)
      break;
    printf("Selecione a Categoria do programa a ser removido:\n");
    Categoria *c = selecionarCategoria(s);
    if (!c)
      break;

    printf("Selecione o Programa a ser removido:\n");
    Programa *p = selecionarPrograma(c); // <-- USA A NOVA FUNÇÃO DE SELEÇÃO
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

// --- SUB-MENU PARA RELATÓRIOS (ATUALIZADO) ---
void menuRelatorios(Stream *raizStreams, Apresentador *listaApresentadores)
{
  int opcao;
  printf(BOLD YELLOW "\n--- Relatorios e Consultas ---\n" RESET);
  printf("1. Listar todas as Streams\n");
  printf("2. Listar Categorias de uma Stream\n");
  printf("3. Listar Programas de uma Categoria\n"); // <-- NOVO!
  printf("4. Buscar Dados de um Programa\n");
  printf("5. Listar Apresentadores de uma Stream\n");
  printf("6. Listar Streams que possuem uma Categoria especifica\n");
  printf(RED "0. Voltar\n" RESET);
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
  { // <-- LÓGICA DA NOVA OPÇÃO
    Stream *s = selecionarStream(raizStreams);
    if (s)
    {
      Categoria *c = selecionarCategoria(s);
      if (c)
      {
        mostrarProgramasDeCategoria(raizStreams, s->nome, c->nome);
      }
    }
    break;
  }
  case 4:
  {
    char ns[100], nc[100], np[100];
    printf("Digite o nome da Stream: ");
    scanf(" %[^\n]", ns);
    printf("Digite o nome da Categoria: ");
    scanf(" %[^\n]", nc);
    printf("Digite o nome do Programa: ");
    scanf(" %[^\n]", np);
    mostrarDadosPrograma(raizStreams, ns, nc, np);
    break;
  }
  case 5:
  {
    Stream *s = selecionarStream(raizStreams);
    if (s)
      mostrarApresentadoresDeStream(listaApresentadores, s->nome);
    break;
  }
  case 6:
  {
    char nc[100];
    printf("Digite o nome da Categoria a buscar: ");
    scanf(" %[^\n]", nc);
    mostrarStreamsComCategoria(raizStreams, nc);
    break;
  }
  case 0:
    break;
  default:
    printf(RED "Opcao invalida!\n" RESET);
  }
}

// --- FUNÇÕES DE SELEÇÃO AUXILIARES (COM A NOVA FUNÇÃO) ---

// ... (as funções selecionarStream, selecionarCategoria, selecionarApresentador continuam iguais) ...

// Helper recursivo para popular um array de ponteiros para Programa
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
  Programa *arrayDeProgramas[200]; // Limite de 200 programas
  int contador = 0;
  _popularArrayPrograma(categoria->arvoreProgramas, arrayDeProgramas, &contador);

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

// COPIE E COLE ESTE BLOCO DE CÓDIGO DENTRO DO SEU main.c
// Um bom lugar é depois da sua função main() e antes da função popularDadosTeste()

// --- SUB-MENU PARA STREAMS E CATEGORIAS ---
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
      printf("Digite o tipo da Categoria (Noticias, Esporte, etc.): ");
      scanf(" %[^\n]", tipoCat);
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

// --- SUB-MENU PARA APRESENTADORES ---
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
    char nome[100], cat[100], streamNome[100];
    printf("Nome do Apresentador: ");
    scanf(" %[^\n]", nome);
    printf("Categoria em que trabalha: ");
    scanf(" %[^\n]", cat);
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

// --- FUNÇÕES DE SELEÇÃO AUXILIARES ---

// Helper recursivo para popular um array de ponteiros para Stream
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
  Stream *arrayDeStreams[200]; // Limite de 200 streams
  int contador = 0;
  _popularArrayStream(raiz, arrayDeStreams, &contador);

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

// --- DADOS INICIAIS ---
// (A função popularDadosTeste e as outras funções de menu/seleção que não foram
// alteradas continuam aqui, exatamente como no código anterior)
void popularDadosTeste(Stream **raizStreams, Apresentador **listaApresentadores)
{
  printf("Populando sistema com dados de teste...\n");
  *raizStreams = cadastrarStream(*raizStreams, "Netflix", "netflix.com");
  *raizStreams = cadastrarStream(*raizStreams, "GNT", "gnt.globo.com");
  *raizStreams = cadastrarStream(*raizStreams, "GloboNews", "globonews.com");
  *raizStreams = cadastrarStream(*raizStreams, "Band", "band.com.br");
  cadastrarCategoriaNaStream(*raizStreams, "Netflix", "Séries", "Entretenimento");
  cadastrarCategoriaNaStream(*raizStreams, "GNT", "Culinária", "Entretenimento");
  cadastrarCategoriaNaStream(*raizStreams, "GloboNews", "Política", "Notícias");
  cadastrarApresentador(listaApresentadores, "Rita Lobo", "Culinária", "GNT");
  cadastrarApresentador(listaApresentadores, "Wagner Moura", "Séries", "Netflix");
  cadastrarApresentador(listaApresentadores, "Andreia Sadi", "Política", "GloboNews");
  cadastrarPrograma(*raizStreams, *listaApresentadores, "GNT", "Culinária", "Cozinha Pratica", "Diario", 30, 2130, "Sob Demanda", "Rita Lobo");
  cadastrarPrograma(*raizStreams, *listaApresentadores, "Netflix", "Séries", "Narcos", "Anual", 50, 0, "Sob Demanda", "Wagner Moura");
  printf("Dados de teste carregados com sucesso!\n");
}
// Cole aqui as outras funções de menu e seleção que não foram alteradas
// (menuGerenciarStreams, menuGerenciarApresentadores, selecionarStream,
// selecionarCategoria, selecionarApresentador)