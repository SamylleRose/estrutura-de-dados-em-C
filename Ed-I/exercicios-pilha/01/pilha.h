typedef struct no No;
typedef struct pilha Pilha;

struct no
{
  int info;
  No *prox;
};

struct pilha
{
  No *prim;
};

Pilha *pilha_cria();
void pilha_push(Pilha *p, int v);
int pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);
void mostar_topo(Pilha *p);

void pilha_inverte(Pilha *p);          // funcao para inverter os elementos da pilha
int pilha_tamanho(Pilha *p);           // funcao para retornar o tamanho da pilha
void pilha_copia(Pilha *p, Pilha *p2); // funcao para copiar uma pilha para outra
