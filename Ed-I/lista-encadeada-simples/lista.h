typedef struct lista Lista;

struct lista
{
  int info;
  Lista *prox;
};

Lista *cria_lista();
void libera_lista(Lista *li);
Lista *insere_lista_inicio(Lista *li, int i);
void mostrar_lista(Lista *li);

// funcoes para serem implementadas
Lista *busca_elemento(Lista *li, int i);
Lista *remove_elemento(Lista *li, int i);