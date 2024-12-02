#include "fazenda.h"

typedef struct Criador {
    char nome[100];
    char cpf[15];
    float patrimonio;
    struct Fazenda *fazendas; // Lista encadeada circular de fazendas
    struct Criador *prev;     // Ponteiro para o nó anterior na lista duplamente encadeada
    struct Criador *next;     // Ponteiro para o próximo nó na lista duplamente encadeada
} Criador;


// Dada a documentação, implementem as funcionalidades necessárias