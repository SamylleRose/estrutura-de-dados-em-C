typedef struct lista Lista;

struct lista
{
  int info;
  Lista *prox, *ant;
};

Lista *cria_lista();
void libera_lista(Lista *li);
Lista *inserir_elemento_inicio(Lista *li, int i);
void mostrar_lista(Lista *li);

Lista *inserir_elemento_final(Lista *li, int i);
Lista *inserir_elemento_ordenado(Lista *li, int i);
Lista *busca_elemento(Lista *li, int i);
Lista *remove_elemento(Lista *li, int i);