typedef struct no No;
typedef struct fila Fila;

struct no
{
  int info;
  No *prox;
};

struct fila
{
  No *prim;
};

Fila *fila_cria();
int fila_vazia(Fila *f);
void fila_insere(Fila *f, int v);
int fila_retira(Fila *f);
void fila_libera(Fila *f);
void fila_imprime(Fila *f);
void mostrar_inicio(Fila *f);
void mostrar_fim(Fila *f);

void fila_inverte(Fila *f);         // funcao para inverter os elementos da fila
int fila_tamanho(Fila *f);          // funcao para retornar o tamanho da fila
void fila_copia(Fila *f, Fila *f2); // funcao para copiar uma fila para outra
