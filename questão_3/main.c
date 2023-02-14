#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void imprimeMenu(){
    printf("\nDigite o numero da opcao desejada:\n");
    printf("1- Adicionar um numero na fila\n");
    printf("2- Retirar um numero da fila\n");
    printf("3- Sair do programa\n\n");
}

int main(){
    Fila* f;
    f = NULL;
    f = criarFila();
    int opcao = 0, i;

    while (opcao != 3) {
        imprimeMenu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: printf("\nDigite um numero: ");
                    scanf("%d", &i);
                    enfileirar(f, i);
                     break;

            case 2: desenfileirar(f);
                     break;

            case 3: printf("Encerrando programa...");
                     break;

            default : printf("invalid\n");
                      break;
        }
    }
    return 0;
}


//obs: nao consegui implementar uma funcao para mostrar a fila :/
