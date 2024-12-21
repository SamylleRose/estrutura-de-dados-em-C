#include "animal.h"

typedef struct Fazenda
{
    int id;
    char nome[100];
    char localizacao[100];
    struct Animal *rebanho; // Lista simples encadeada de animais
    struct Fazenda *next;   // Ponteiro para o próximo nó na lista encadeada circular
} Fazenda;

// Dada a documentação, implementem as funcionalidades necessárias
Fazenda *criarFazenda();
void liberarFazenda(Fazenda *liFazenda);
Fazenda *inserirFazenda(Fazenda *liFazenda);
void adicionarAnimal(Fazenda *fazenda, Animal *animal);
void mostrarFazenda(Fazenda *liFazenda);
Fazenda *removerFazenda(Fazenda *liFazenda, int id);
void realocarAnimal(Fazenda *fazendaOrigem, Fazenda *fazendaDestino);

void solicitarRealocacao(Fazenda *liFazenda);
void gerenciarFazendas(Fazenda *liFazenda);
void menuFazenda(Fazenda *atual, Fazenda *lifazenda);
