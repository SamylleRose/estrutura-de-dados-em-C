#include <stdio.h>


void achar_posicao( char *v, char letra, int tamanho, int *indices, int *tamanho_indices){

  for(int i = 0; i < tamanho; i++){

    if(v[i] == letra){
      indices[*tamanho_indices] = i;
      (*tamanho_indices)++;
    }

  }
}
int main(){

  char v[] = "LeiteNinho";
  char letra = 'i';

  int tamanho = sizeof(v) - 1;

  int indices[100];
  int tamanho_indices = 0;


achar_posicao(v, letra, tamanho, indices, &tamanho_indices);

printf("A letra '%c' foi encontrada nas posições: ", letra);
    for (int i = 0; i < tamanho_indices; i++) {
        printf("%d ", indices[i]);
    }
printf("Tamanho do vetor dos indice: %d\n", tamanho_indices);


  return 0;
}