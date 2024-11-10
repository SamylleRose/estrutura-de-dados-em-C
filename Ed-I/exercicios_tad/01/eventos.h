#ifndef EVENTOS_H
#define EVENTOS_H

typedef struct
{
  int id;
  char nome[100];
  char data[11];
  int num_participantes;
} Evento;

Evento *criar_evento(int id, const char *nome, const char *data, int num_participantes);
void cadastrar_evento(Evento *eventos[], int *count, Evento *novo_evento);
void listar_eventos_por_data(Evento *eventos[], int count, const char *data);
void atualizar_participantes(Evento *eventos[], int count, int id, int novos_participantes);

#endif
