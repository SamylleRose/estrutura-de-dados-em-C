#include <stdio.h>

int main (){

  int vet[] = {2,4,5,3,1,6,7};
  int tamanho = sizeof(vet) / sizeof(vet[0]);
  int *p1, *p2, temp;

  for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            p1 = vet + j;       
            p2 = vet + j + 1;   

            if (*p1 > *p2) {
               
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }

    printf("Vetor ordenado: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

}