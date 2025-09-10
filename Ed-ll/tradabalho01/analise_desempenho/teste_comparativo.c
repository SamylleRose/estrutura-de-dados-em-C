#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Interfaces das versões AVL (padrão)
#include "stream.h"
#include "programa.h"
#include "categoria.h"
#include "apresentador.h"

// Interfaces das versões BST (renomeadas)
#include "stream_bst.h"
#include "programa_bst.h"

// --- DEFINIÇÃO DE CORES ANSI ---
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define CYAN "\x1B[36m"

// --- PROTÓTIPOS DAS FUNÇÕES DE TESTE ---
void teste_a_insercao_streams(int quantidade, double *bst_ord, double *avl_ord, double *bst_rand, double *avl_rand);
void teste_b_busca_programas(int num_elementos, int num_buscas, double *bst_tempo, double *avl_tempo);
void teste_d_remocao_programas(int num_elementos, int num_remocoes, double *bst_tempo, double *avl_tempo);

// --- FUNÇÃO PRINCIPAL (ORQUESTRADOR E RELATÓRIO) ---
int main()
{
  const int QTD_INSERCAO = 70000;
  const int QTD_SETUP = 50000;
  const int QTD_BUSCA_EXEC = 100000;
  const int QTD_REMOCAO_EXEC = 25000;

  // --- VARIÁVEIS PARA GUARDAR OS RESULTADOS ---
  double bst_ord_t, avl_ord_t, bst_rand_t, avl_rand_t;
  double bst_busca_t, avl_busca_t;
  double bst_remocao_t, avl_remocao_t;

  printf(BOLD CYAN "===== INICIANDO SUITE COMPLETA DE TESTES DE DESEMPENHO =====\n" RESET);

  // --- EXECUÇÃO DOS TESTES ---
  teste_a_insercao_streams(QTD_INSERCAO, &bst_ord_t, &avl_ord_t, &bst_rand_t, &avl_rand_t);
  teste_b_busca_programas(QTD_SETUP, QTD_BUSCA_EXEC, &bst_busca_t, &avl_busca_t);
  teste_d_remocao_programas(QTD_SETUP, QTD_REMOCAO_EXEC, &bst_remocao_t, &avl_remocao_t);

  // --- APRESENTAÇÃO E ANÁLISE DOS RESULTADOS ---
  printf(BOLD CYAN "\n\n================== RELATORIO FINAL DE DESEMPENHO ==================\n" RESET);
  printf("-------------------------------------------------------------------\n");
  printf("| Teste Realizado          | Tempo BST Simples (s) | Tempo AVL (s)      \n");
  printf("-------------------------------------------------------------------\n");
  printf("| Insercao (Stream, Ord)   | " GREEN "%-19.6f" RESET " | " GREEN "%-18.6f" RESET " \n", bst_ord_t, avl_ord_t);
  printf("| Insercao (Stream, Rand)  | " GREEN "%-19.6f" RESET " | " GREEN "%-18.6f" RESET " \n", bst_rand_t, avl_rand_t);
  printf("| Busca (Programa, Rand)   | " GREEN "%-19.6f" RESET " | " GREEN "%-18.6f" RESET " \n", bst_busca_t, avl_busca_t);
  printf("| Remocao (Programa, Rand) | " GREEN "%-19.6f" RESET " | " GREEN "%-18.6f" RESET " \n", bst_remocao_t, avl_remocao_t);
  printf("-------------------------------------------------------------------\n");

  printf(BOLD "\n\n============================ ANALISE DETALHADA ============================\n" RESET);

  // --- Análise de Inserção Ordenada ---
  printf(BOLD "\nAnalise de Insercao Ordenada:\n" RESET);
  if (avl_ord_t > 0 && bst_ord_t > avl_ord_t)
  {
    printf(" -> AVL foi " YELLOW "%.2f vezes" RESET " mais rapida que a BST.\n", bst_ord_t / avl_ord_t);
  }
  else
  {
    printf(" -> Nao foi possivel obter uma melhoria clara da AVL.\n");
  }

  // --- Análise de Inserção Aleatória ---
  printf(BOLD "\nAnalise de Insercao Aleatoria:\n" RESET);
  if (avl_rand_t > 0 && bst_rand_t > avl_rand_t)
  {
    printf(" -> AVL foi " YELLOW "%.2f vezes" RESET " mais rapida que a BST.\n", bst_rand_t / avl_rand_t);
  }
  else
  {
    printf(" -> Nao foi possivel obter uma melhoria clara da AVL.\n");
  }

  // --- Análise de Busca Aleatória ---
  printf(BOLD "\nAnalise de Busca Aleatoria:\n" RESET);
  if (bst_busca_t > avl_busca_t)
  {
    printf(" -> AVL foi " YELLOW "%.2f vezes" RESET " mais rapida que a BST.\n", bst_busca_t / avl_busca_t);
  }
  else if (avl_busca_t > bst_busca_t)
  {
    printf(" -> BST foi " GREEN "%.2f vezes" RESET " mais rapida que a AVL.\n", avl_busca_t / bst_busca_t);
  }
  else
  {
    printf(" -> Desempenho praticamente identico.\n");
  }

  // --- Análise de Remoção Aleatória ---
  printf(BOLD "\nAnalise de Remocao Aleatoria:\n" RESET);
  if (bst_remocao_t < avl_remocao_t)
  {
    printf(" -> BST foi " GREEN "%.2f vezes" RESET " mais rapida que a AVL.\n", avl_remocao_t / bst_remocao_t);
  }
  else if (avl_remocao_t < bst_remocao_t)
  {
    printf(" -> AVL foi " YELLOW "%.2f vezes" RESET " mais rapida que a BST.\n", bst_remocao_t / avl_remocao_t);
  }
  else
  {
    printf(" -> Desempenho praticamente identico.\n");
  }

  printf(BOLD CYAN "\n=================================================================\n" RESET);
  return 0;
}

// --- IMPLEMENTAÇÃO DO TESTE (a): Inserção de Streams ---
void teste_a_insercao_streams(int quantidade, double *bst_ord, double *avl_ord, double *bst_rand, double *avl_rand)
{
  Stream *raiz_avl = NULL, *raiz_bst = NULL;
  clock_t inicio, fim;
  printf(BOLD "\n--- Executando Teste (a): Insercao de %d Streams ---\n" RESET, quantidade);

  inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    char n[50];
    sprintf(n, "s_%06d", i);
    raiz_bst = cadastrarStreamBst(raiz_bst, n, "s.com");
  }
  fim = clock();
  *bst_ord = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    char n[50];
    sprintf(n, "s_%06d", i);
    raiz_avl = cadastrarStream(raiz_avl, n, "s.com");
  }
  fim = clock();
  *avl_ord = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  srand(time(NULL));
  inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    char n[50];
    sprintf(n, "s_%d", rand());
    raiz_bst = cadastrarStreamBst(raiz_bst, n, "s.com");
  }
  fim = clock();
  *bst_rand = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  inicio = clock();
  for (int i = 0; i < quantidade; i++)
  {
    char n[50];
    sprintf(n, "s_%d", rand());
    raiz_avl = cadastrarStream(raiz_avl, n, "s.com");
  }
  fim = clock();
  *avl_rand = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  printf(GREEN "Teste de Insercao... Concluido.\n" RESET);
}

// --- IMPLEMENTAÇÃO DO TESTE (b): Busca de Programas (COM LÓGICA DE MÉDIA) ---
void teste_b_busca_programas(int num_elementos, int num_buscas, double *bst_tempo, double *avl_tempo)
{
  // A constante para o número de repetições é definida aqui dentro.
  const int NUM_REPETICOES = 30;

  printf(BOLD "\n--- Executando Teste (b): Busca de %d Programas (media de %d rodadas) ---\n" RESET, num_buscas, NUM_REPETICOES);

  // ETAPA 1: SETUP - Idêntico ao seu código original, executa uma vez.
  Programa *raiz_prog_bst = NULL, *raiz_prog_avl = NULL;
  char (*nomes_a_buscar)[50] = malloc(num_elementos * sizeof(char[50]));
  srand(time(NULL));
  for (int i = 0; i < num_elementos; i++)
  {
    sprintf(nomes_a_buscar[i], "programa_%d", rand());
    raiz_prog_bst = inserirProgramaNaArvoreBst(raiz_prog_bst, nomes_a_buscar[i], "d", 0, 0, "t", "a");
    raiz_prog_avl = inserirProgramaNaArvore(raiz_prog_avl, nomes_a_buscar[i], "d", 0, 0, "t", "a");
  }

  // ETAPA 2: MEDIÇÃO - Modificada para repetir 30 vezes e somar os tempos.
  clock_t inicio, fim;
  double soma_bst_ticks = 0;
  double soma_avl_ticks = 0;

  // --- Medição BST ---
  for (int i = 0; i < NUM_REPETICOES; i++)
  {
    inicio = clock();
    for (int j = 0; j < num_buscas; j++) // Loop interno é o seu original
    {
      buscarProgramaBst(raiz_prog_bst, nomes_a_buscar[rand() % num_elementos]);
    }
    fim = clock();
    soma_bst_ticks += (double)(fim - inicio);
  }

  // --- Medição AVL ---
  for (int i = 0; i < NUM_REPETICOES; i++)
  {
    inicio = clock();
    for (int j = 0; j < num_buscas; j++) // Loop interno é o seu original
    {
      buscarPrograma(raiz_prog_avl, nomes_a_buscar[rand() % num_elementos]);
    }
    fim = clock();
    soma_avl_ticks += (double)(fim - inicio);
  }

  // ETAPA 3: CÁLCULO DA MÉDIA - O resultado final é a média dos tempos.
  *bst_tempo = (soma_bst_ticks / NUM_REPETICOES) / CLOCKS_PER_SEC;
  *avl_tempo = (soma_avl_ticks / NUM_REPETICOES) / CLOCKS_PER_SEC;

  printf(GREEN "Teste de Busca... Concluido.\n" RESET);
  free(nomes_a_buscar);
}

// --- IMPLEMENTAÇÃO DO TESTE (d): Remoção de Programas (CORRIGIDO) ---
void teste_d_remocao_programas(int num_elementos, int num_remocoes, double *bst_tempo, double *avl_tempo)
{
  printf(BOLD "\n--- Executando Teste (d): Remocao de %d Programas ---\n" RESET, num_remocoes);

  Programa *raiz_prog_bst = NULL;
  Programa *raiz_prog_avl = NULL;
  char (*nomes_para_operacoes)[50] = malloc(num_elementos * sizeof(char[50]));
  if (nomes_para_operacoes == NULL)
  {
    printf(RED "Falha ao alocar memoria para o teste de remocao.\n" RESET);
    *bst_tempo = -1;
    *avl_tempo = -1;
    return;
  }

  // --- Setup: Cria duas árvores idênticas com NOMES ÚNICOS ---
  for (int i = 0; i < num_elementos; i++)
  {
    sprintf(nomes_para_operacoes[i], "programa_%07d", i); // Ex: programa_0000001
    raiz_prog_bst = inserirProgramaNaArvoreBst(raiz_prog_bst, nomes_para_operacoes[i], "d", 0, 0, "t", "a");
    raiz_prog_avl = inserirProgramaNaArvore(raiz_prog_avl, nomes_para_operacoes[i], "d", 0, 0, "t", "a");
  }

  clock_t inicio, fim;
  *bst_tempo = 0;
  *avl_tempo = 0;

  // --- Medição BST ---
  inicio = clock();
  for (int i = 0; i < num_remocoes; i++)
  {
    raiz_prog_bst = removerProgramaDaArvoreBst(raiz_prog_bst, nomes_para_operacoes[i]);
  }
  fim = clock();
  *bst_tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  // --- Medição AVL ---
  inicio = clock();
  for (int i = 0; i < num_remocoes; i++)
  {
    raiz_prog_avl = removerProgramaDaArvore(raiz_prog_avl, nomes_para_operacoes[i]);
  }
  fim = clock();
  *avl_tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  printf(GREEN "Teste de Remocao... Concluido.\n" RESET);
  free(nomes_para_operacoes);
}