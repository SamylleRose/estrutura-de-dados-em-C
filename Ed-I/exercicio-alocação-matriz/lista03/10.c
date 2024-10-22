// a. P++ e *p++

// P++: Avança o ponteiro P para o próximo elemento.
// *p++: Retorna o valor apontado por P e em seguida incrementa
// o ponteiro P para o próximo elemento.

// b. (*p) ++ e *(p++)

// (*p)++: Incrementa o valor apontado por P, sem mover o ponteiro.
// *(p++): Retorna o valor apontado por P e em seguida move o ponteiro
// para o próximo elemento.

// c. *(p + 8) e (*p) + 8

// *(p + 8): Retorna o valor armazenado na posição P + 8 (oitavo elemento
// após o ponteiro P).
// (*p) + 8: Soma 8 ao valor apontado por P sem mover o ponteiro.

// d. *(p + 2) e p[2]

// *(p + 2): Retorna o valor armazenado na posição P + 2.
// p[2]: É uma forma de acessar o terceiro elemento do vetor usando notação
// de índice.