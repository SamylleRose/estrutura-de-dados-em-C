// int main(){
//     ...
//     int i;                // Declaração de variável de controle para o loop
//     int x;                // Variável que armazena o número de linhas da matriz (número de cidades ou itinerários)
//     int y;                // Variável que armazena o número de colunas (tamanho de cada linha, como número de horários ou preços)
//     int **matriz = (int**)(malloc(x*sizeof(int*))); // Alocação dinâmica para um vetor de ponteiros de inteiros, onde cada ponteiro será uma linha da matriz
//     for(i=0; i<x; i++)
//         matriz[i] = (int*)(malloc(y*sizeof(int)));  // Alocação de memória para cada linha da matriz, onde cada linha pode conter 'y' elementos (colunas)
//     ...
// }
