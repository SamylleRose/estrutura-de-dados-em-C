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
Fazenda *criar_Fazenda();
void liberar_Fazenda(Fazenda *li);
Fazenda *inserir_Fazenda(Fazenda *li, int id, char nome, char localizacao);
void adicionar_animal(Fazenda *fazenda, Animal *animal);
void gerenciar_fazendas(Fazenda *li);
void mostrar_Fazenda(Fazenda *li);
Fazenda *remover_fazenda(Fazenda *li, int id);
