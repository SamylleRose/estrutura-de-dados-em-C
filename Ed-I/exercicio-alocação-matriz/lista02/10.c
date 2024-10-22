// Vazamento de Memória: Memória alocada que não é liberada, resultando no
// esgotamento dos recursos do sistema ao longo do tempo.

// Double Free: Tentar liberar a mesma região de memória duas vezes,
// causando comportamento indefinido ou travamentos.

// Ponteiros Soltos (Dangling Pointers): Acessar memória que já foi liberada,
// o que pode resultar em corrupção de dados ou falhas inesperadas no programa.

// Falta de Memória: Tentar alocar mais memória do que o disponível, causando
// falhas de alocação.

// Ataques de Segurança: Programas podem ser vulneráveis a exploits como buffer
// overflows ou heap spraying se a alocação e liberação de memória não forem feitas
// corretamente.