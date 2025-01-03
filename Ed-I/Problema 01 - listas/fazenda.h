#include "animal.h"

typedef struct Fazenda
{
    int id;
    char nome[100];
    char localizacao[100];
    struct Animal *rebanho; // Lista simples encadeada de animais
    struct Fazenda *next;   // Ponteiro para o próximo nó na lista encadeada circular
} Fazenda;

void liberarFazenda(Fazenda *liFazenda);
Fazenda *inserirFazenda(Fazenda *liFazenda);
void adicionarAnimal(Fazenda *fazenda, Animal *animal);
void mostrarFazenda(Fazenda *liFazenda);
void realocarAnimal(Fazenda *fazendaOrigem, Fazenda *fazendaDestino);
Fazenda *removerFazenda(Fazenda *liFazenda);

void solicitarRealocacao(Fazenda *liFazenda);
Fazenda *menuFazenda(Fazenda *atual);
Fazenda *gerenciarFazendas(Fazenda *liFazenda);
