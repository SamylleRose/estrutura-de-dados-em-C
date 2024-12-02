typedef enum {
    EM_CRIACAO,
    PARA_VENDA,
    VENDIDO,
    TROCA,
    NASCIMENTO
} StatusAnimal;

typedef struct Animal {
    int id;
    float peso;
    char sexo; // 'M' para macho, 'F' para fêmea
    StatusAnimal status;
    struct Animal *next; // Ponteiro para o próximo nó na lista simples encadeada
} Animal;

// Dada a documentação, implementem as funcionalidades necessárias