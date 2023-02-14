#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "agenda.h"

struct elemento{
	struct contato dados;
	struct elemento *prox;
};

typedef struct elemento Elemento;

Lista* criar(){
	Lista *agenda;
	agenda = (Lista *)malloc(sizeof(Lista));
	if(agenda != NULL){
		*agenda = NULL;
	}
	return agenda;
}

void destruir(Lista *agenda){
	if(agenda != NULL){
		Elemento *aux;
		while(*agenda != NULL){
			aux = *agenda;
			*agenda = (*agenda)->prox;
			free(aux);
		}
	}
}

int insereContato(Lista* agenda, struct contato dados){
	if(agenda == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            novo->prox = NULL;
            if(*agenda == NULL){
                *agenda = novo; //elemento inserido no inicio da lista, dado que esta vazia
                 printf("\nContato adicionado com sucesso!\n");
            }else{
                Elemento *aux = *agenda;
                //verifica o primeiro elemento
                if(strcmp(aux->dados.telefone, dados.telefone)==0){
                    printf("Nao foi possivel adicionar o novo contato pois o numero informado ja se encontra na agenda!");
                    return 0;
                }
                else{
                //verifica os outros elementos
                    while(aux->prox != NULL){
                        if(strcmp(aux->dados.telefone, dados.telefone)==0){
                            printf("Nao foi possivel adicionar o novo contato pois o numero informado ja se encontra na agenda!");
                            return 0;
                        }else{
                            aux = aux->prox;
                        }
                    }
                }
                aux->prox = novo;
                printf("\nContato adicionado com sucesso!\n");
                return 1;
            }
        }
    }
}

int buscaContato(Lista* agenda, char nome[50], struct contato **dados){
    if(agenda == NULL || *agenda == NULL){
        return 0;
    }else{
        Elemento *aux = *agenda;
        while(aux != NULL && strcmp(aux->dados.nome, nome)!=0){
            aux = aux->prox;
        }
        if(aux == NULL){
            return 0;
        }else{
            *dados = &(aux->dados);
            return 1;
        }
    }
}

int removeContato(Lista* agenda, char nome[50]){
    if(agenda == NULL){
        return 0;
    }else if(strcmp((*agenda)->dados.nome, nome) == 0){
        Elemento *aux = *agenda;
        *agenda = aux->prox;
        free(aux);
        printf("Contato removido!");
        return 1;
    }else{
        Elemento *ant = *agenda;
        Elemento *aux = ant->prox;
        while(aux != NULL && strcmp(aux->dados.nome, nome) != 0){
            ant = aux;
            aux = aux->prox;
        }
        //chegou ao fim da lista e nao achou o elemento
        if(aux == NULL){
        	printf("O contato informado nao esta na agenda!");
            return 0;
        }
        //achou o elemento
        ant->prox = aux->prox;
        free(aux);
        printf("Contato removido!");
        return 1;
    }
}

