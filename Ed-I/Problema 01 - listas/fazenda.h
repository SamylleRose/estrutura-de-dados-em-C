#include "animal.h"

typedef struct Fazenda {
    int id;
    char nome[100];
    char localizacao[100];
    struct Animal *rebanho; // Lista simples encadeada de animais
    struct Fazenda *next;   // Ponteiro para o próximo nó na lista encadeada circular
} Fazenda;

// Dada a documentação, implementem as funcionalidades necessárias