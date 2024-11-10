// main.c

#include <stdio.h>
#include "acervo.h"

int main()
{
    Acervo *acervo = inicializar_acervo(1);
    int opcao;
    char titulo[100], autor[50];
    int ano_publicacao, num_paginas;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar Livro\n");
        printf("4. Remover Livro\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o título: ");
            scanf(" %[^\n]", titulo);
            printf("Digite o autor: ");
            scanf(" %[^\n]", autor);
            printf("Digite o ano de publicação: ");
            scanf("%d", &ano_publicacao);
            printf("Digite o número de páginas: ");
            scanf("%d", &num_paginas);
            adicionar_livro(acervo, titulo, autor, ano_publicacao, num_paginas);
            break;
        case 2:
            listar_livros(acervo);
            break;
        case 3:
        {
            printf("Digite o título para buscar: ");
            scanf(" %[^\n]", titulo);
            Livro *livro = buscar_livro(acervo, titulo);
            if (livro)
            {
                printf("Título: %s\nAutor: %s\nAno: %d\nPáginas: %d\n", livro->titulo, livro->autor, livro->ano_publicacao, livro->num_paginas);
            }
            else
            {
                printf("Livro não encontrado.\n");
            }
            break;
        }
        case 4:
            printf("Digite o título para remover: ");
            scanf(" %[^\n]", titulo);
            remover_livro(acervo, titulo);
            break;
        case 5:
            liberar_acervo(acervo);
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}
