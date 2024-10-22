// Declaração de dois ponteiros de inteiros, p e q, ambos inicialmente não apontam para nada.

// Alocação dinâmica de memória para armazenar um inteiro e p passa a apontar para essa área de memória.

// O valor 123 é armazenado na área de memória para a qual p aponta.

// Alocação dinâmica de memória para q, que agora aponta para outra área de memória separada, suficiente para armazenar um inteiro.

// O valor armazenado na área de memória apontada por p (123) é copiado para a área de memória apontada por q.

// q passa a apontar para o mesmo endereço de memória que p, fazendo com que q perca a referência à área de memória previamente alocada para ele (causando um vazamento de memória).

// A memória apontada por p (que agora também é apontada por q) é liberada, tornando p e q ponteiros soltos (dangling pointers).

// Tentativa de liberar novamente a mesma área de memória já liberada anteriormente, resultando em comportamento indefinido (potencial "double free").

// O ponteiro q é atribuído como NULL para evitar que ele seja um ponteiro solto, uma prática de segurança para evitar acessos acidentais.
