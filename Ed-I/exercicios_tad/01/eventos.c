#include "eventos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Evento *criar_evento(int id, const char *nome, const char *data, int num_participantes)
{
  Evento *novo_evento = (Evento *)malloc(sizeof(Evento));
  novo_evento->id = id;
  strcpy(novo_evento->nome, nome);
  strcpy(novo_evento->data, data);
  novo_evento->num_participantes = num_participantes;
  return novo_evento;
}

void cadastrar_evento(Evento *eventos[], int *count, Evento *novo_evento)
{
  eventos[*count] = novo_evento;
  (*count)++;
}

void listar_eventos_por_data(Evento *eventos[], int count, const char *data)
{
  for (int i = 0; i < count; i++)
  {
    if (strcmp(eventos[i]->data, data) == 0)
    {
      printf("ID: %d, Nome: %s, Participantes: %d\n", eventos[i]->id, eventos[i]->nome, eventos[i]->num_participantes);
    }
  }
}

void atualizar_participantes(Evento *eventos[], int count, int id, int novos_participantes)
{
  for (int i = 0; i < count; i++)
  {
    if (eventos[i]->id == id)
    {
      eventos[i]->num_participantes = novos_participantes;
      return;
    }
  }
}
