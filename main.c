#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
/*
Voce devera implementar uma programa que simule o funcionamento de uma
agenda telefonica. Para isso, implemente um programa principal que tenha
um menu retornavel onde o usuario escolhe dentre as opcoes poss�veis.

Requisitos funcionais:

-Funcoes da agenda:

1-Insere contato
2-Busca contato por nome
3-Edita contato (pode alterar o nome ou o telefone)
4-Remove contato pelo nome
5-Apagar todos os contatos
6-Encerrar o programa

-E possivel inserir contatos com o mesmo nome, porem nao e possivel inserir
contatos com o mesmo telefone
-Coloque mensagens para informar ao usuario sempre que houver erros.
Por exemplo, quando o contato nao for inserido, pois ja existe um contato
com o mesmo telefone na agenda, ou quando o contato nao for removido por nao
existir na agenda ninguem com aquele nome

Requisitos nao funcionais:

-Nao e permitido o uso de variaveis globais
-Utilize uma lista dinamica simplesmente encadeada como estrutura de dados,
 implementando as funcoes declaradas em agenda.h.
-Nao e permitido adicionar novas funcoes ou alterar a funcoes existentes em
agenda.h. Se for necessario, crie novas funcoes no programa principal

Opcional: implemente funcoes para carregar e salvar contatos em um arquivo
para nao precisar inserir contatos na mao toda vez que quiser testar o programa
*/

void imprimeMenu(){
	printf("\n---------------------\n	MENU\n---------------------\n");
	printf("1 - Inserir novo contato; \n");
	printf("2 - Buscar contato por nome; \n");
	printf("3 - Editar contato; \n");
	printf("4 - Remover contato; \n");
	printf("5 - Excluir todos os contatos; \n");
	printf("6 - Encerrar agenda; \n");
	printf("\n\nDigite a opcao desejada: ");
}

void preencheContato(struct contato *dados){
    printf("\nDigite o nome:\n");
    fflush(stdin);
    scanf("%s", dados->nome);
    printf("\nDigite o numero de telefone:\n");
    scanf("%s", dados->telefone);
}

void editaContato(Lista* agenda, struct contato* dados){
	if(agenda == NULL || *agenda == NULL){
		printf("Não foi possível realizar a alteração pois a agenda encontra-se vazia!");
	}else{
		int i;
		char nome[50];
		printf("\nInforme o nome do contato que deseja alterar: ");
		scanf("%s", nome);
        	if(buscaContato(agenda, nome, &dados)==1){
			do{
				printf("\nInforme o que deseja alterar: \n1-Nome\n2-Telefone\n");
				scanf("%d", &i);
			}while(i!=1 && i!=2);
				if(i==1){
					char novo[50];
					printf("\nNovo nome: ");
					fflush(stdin);
					scanf("%s", novo);
					strcpy(dados->nome, novo);
					printf("\nNome alterado!");
				}else if(i==2){
					char novo[11];
					printf("\nNovo telefone: ");
					fflush(stdin);
					scanf("%s", novo);
					strcpy(dados->telefone, novo);
					printf("\nTelefone alterado!");
				}else{
					printf("Não foi possível alterar o contato!");
				}
		}else{
			printf("\nO contato informado não existe! ");
		}
	}
}



int main(){

	Lista *agenda;
	int opcao=-1, x;
	char nome[50], tel[11];
	struct contato *dados;
	agenda = NULL;
	agenda = criar();
	dados = (struct contato*)malloc(sizeof(struct contato));

	while(opcao != 6){
        	imprimeMenu();
        	scanf("%d", &opcao);
        	switch(opcao){
			case 1:
				preencheContato(dados);
				insereContato(agenda, *dados);
				break;
			case 2:
				printf("\nDigite o nome:\n");
				fflush(stdin);
				scanf("%s", nome);
				if(buscaContato(agenda, nome, &dados)!=0){
					printf("--------------------------------\n");
					printf("Nome: %s\nTelefone: %s\n", dados->nome, dados->telefone);
					printf("--------------------------------\n");
				}else{
					printf("O contato informado nao esta na agenda!\n");
				}
				break;
			case 3:
				editaContato(agenda, dados);
				break;
			case 4:
				printf("Digite o nome:\n");
				fflush(stdin);
				scanf("%s", nome);
				removeContato(agenda, nome);
				break;
			case 5:
				destruir(agenda);
				printf("\nTodos os contatos foram excluidos!");
				break;
			case 6:
				destruir(agenda);
				printf("Encerrando programa...");
				opcao = 6;
				break;
			default:
				printf("Opcao invalida! Tente novamente.\n");
		}
	}

    return 0;
}
