#include "global.h"

typedef enum
{
    EM_CRIACAO,
    PARA_VENDA,
    VENDIDO,
    TROCA,
    NASCIMENTO

} StatusAnimal;

typedef struct Animal
{
    int id;
    float peso;
    char sexo; // 'M' para macho, 'F' para fêmea
    StatusAnimal status;
    struct Animal *next; // Ponteiro para o próximo nó na lista simples encadeada
} Animal;

void liberarAnimal(Animal *liAnimal);
Animal *inserirAnimal(Animal *liAnimal);
void mostrarAnimal(Animal *liAnimal);
Animal *atualizarStatus(Animal *liAnimal);
Animal *removerAnimal(Animal *liAnimal);

const char *statusToString(StatusAnimal status);
int menuStatus();
