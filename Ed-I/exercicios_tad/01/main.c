#include <stdio.h>
#include "eventos.h"

int main()
{
  Evento *eventos[100];
  int count = 0;

  Evento *e1 = criar_evento(1, "Workshop C", "2023-12-01", 30);
  cadastrar_evento(eventos, &count, e1);

  listar_eventos_por_data(eventos, count, "2023-12-01");

  atualizar_participantes(eventos, count, 1, 50);
  listar_eventos_por_data(eventos, count, "2023-12-01");

  return 0;
}
