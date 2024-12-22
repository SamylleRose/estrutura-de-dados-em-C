#include "fazenda.h"

typedef struct Criador
{
    char nome[100];
    char cpf[15];
    float patrimonio;
    struct Fazenda *fazendas; // Lista encadeada circular de fazendas
    struct Criador *prev;     // Ponteiro para o nó anterior na lista duplamente encadeada
    struct Criador *next;     // Ponteiro para o próximo nó na lista duplamente encadeada
} Criador;

void liberaCriador(Criador *liCriador);
Criador *inserirCriador(Criador *liCriador);
void mostrarCriador(Criador *liCriador);
Criador *removerCriador(Criador *liCriador);
void patrimonio(); // FAZER POR ULTIMO
