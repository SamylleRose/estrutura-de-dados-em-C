#include <stdio.h>

int main(){

 int y, *p, x; // declara a variável y e x, e o ponteiro p;

 y = 0; // atribui 0 a variável y;
 p = &y; // p recebe o endereço de y;
 x = *p; // x recebe o valor do endereço que o p guarda;
 x = 4; // x recebe um novo valor;

 (*p)++; // o valor qo endereço que p armazena foi encrementado;
 x--; // o valor de x é descrementado;

 (*p) += x; // o valor do endereço que P armazena foi somado com o valor de x;

 printf("y = %d\n", y); // a saída é y = 4 e x = 3.

 return (0); 
}