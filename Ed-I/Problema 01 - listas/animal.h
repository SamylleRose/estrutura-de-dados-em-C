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

// Dada a documentação, implementem as funcionalidades necessárias
Animal *criar_animal();
void liberar_animal(Animal *li);
Animal *inserir_animal(Animal *li, int id, float peso, StatusAnimal status);
void amostrar_animal(Animal *li);
Animal *atualizar_status(Animal *li, StatusAnimal status);
Animal *realocar_animal(Animal *li); // Não sei como fazer ainda
Animal *remover_animal(Animal *li, int id, float peso, StatusAnimal status);
