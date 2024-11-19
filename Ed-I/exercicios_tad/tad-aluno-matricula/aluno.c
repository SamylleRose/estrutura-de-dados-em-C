#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Aluno *cria_aluno(){
  return NULL;
}

void liberar_aluno(Aluno *li){

  Aluno *aux;
  while(li != NULL){
    aux = li;
    li = li->prox;

    for (int i = 0; i < 3; i++) {
      if (aux->notas[i] != NULL) {
        free(aux->notas[i]);
      }
    }

    free(aux);
  }
}

Aluno *inserir_aluno_matricula(Aluno *li){
  Aluno *novo = (Aluno *)malloc(sizeof(Aluno));

  if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }

  novo->matricula = 100 + rand() % 900;

  novo->nome[0] = (char *)malloc(100 * sizeof(char));

  if (novo->nome[0] == NULL) {
    printf("Erro ao alocar memória para o nome\n");
    free(novo);
    return NULL;
  }
  char nome[100];

  printf("Insira o nome: ");
  scanf("%99s", nome);

  strcpy(novo->nome[0], nome);

  int sum = 0;
  float nota;

  for(int i = 0; i < 3; i++){
    printf("Insira a nota %d: ", i+1);
    scanf("%f", &nota);

    novo->notas[i] = (float *)malloc(sizeof(float));

    if (novo->notas[i] == NULL) {
      printf("Erro ao alocar memória para a nota %d\n", i + 1);
      free(novo->nome[0]);
      free(novo);
      return NULL;
    }

    *(novo->notas[i]) = nota;

    sum += nota;
    

  }

  novo->media = sum / 3;
  novo->prox = li;

  return novo;

}

void mostrar_todos_aluno(Aluno *li){
  Aluno *aux = li;
  while (aux !=NULL){
    printf("\n=================================\n");
    printf("Matrícula: %d\n", aux->matricula);
    printf("Nome: %s\n", aux->nome[0]);

    for(int i = 0; i < 3; i++){
      printf("Nota %d: %.2f\n",i +1, *(aux->notas[i]));
    }
  
    
    printf("Média: %.2f\n", aux->media);
    printf("=================================\n");
    
    aux = aux->prox;
    
  }
}

// void mostrar_unico_aluno(Aluno *li){}

// Aluno *buscar_aluno(Aluno *li, int matricula){}

// Aluno *remover_aluno(Aluno *li, int matricula){}
// Aluno *buscar_aluno_por_media(Aluno *li, float media){}
// void mostrar_aluno_com_maior_media(Aluno *li){}
