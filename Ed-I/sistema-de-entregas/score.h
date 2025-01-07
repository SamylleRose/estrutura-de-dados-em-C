typedef struct score Score;

struct score
{
  int pontuacao;
};

Score *criarScore();
Score *entregueNaPrimeiraTentativa(Score *score);
Score *entregueNaSegundaTentativa(Score *score);
Score *devolvida(Score *score);
void mostrarScore(Score *score);
Score *liberarMemoriaScore(Score *score);