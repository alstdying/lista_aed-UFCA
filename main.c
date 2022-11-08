
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


void imprimeMenu(){
    printf("Digite o numero da opcao desejada:\n");
    printf("1- Inserir aluno\n");
    printf("2- Remover aluno\n");
    printf("3- Acessa aluno no topo da pilha\n");
    printf("4- Imprime a pilha\n");
    printf("5- Sair do Programa\n");
}

void preencheAluno(struct aluno *dados){
    printf("Digite o nome:\n");
    fflush(stdin);
    scanf("%s", dados->nome);
    printf("Digite a matricula:\n");
    scanf("%d", &dados->matricula);
}


int main()
{
    Pilha *pilha;
    pilha = NULL;
    pilha = criar();
    int opcao;
    opcao = -1;
    struct aluno dados;

    while(opcao != 5){
        imprimeMenu();
        scanf("%d", &opcao);
        if(opcao == 1){
            preencheAluno(&dados);
            inserir(pilha, dados);
        }else if(opcao == 2){
            remover(pilha);
        }else if(opcao == 3){
            acessar(pilha,&dados);
            printf("--------------------------------\n");
            printf("Nome: %s\nMatricula: %d\n", dados.nome, dados.matricula);
            printf("--------------------------------\n");
        }else if(opcao == 4){
            imprimePilha(pilha);
        }else if(opcao == 5){
            destruir(pilha);
            printf("Encerrando o programa\n");
        }else{
            printf("Opcao invalida, tente novamente\n");
        }
    }
    return 0;
}
