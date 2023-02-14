#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct elemento {
    int dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;

struct fila{
    Pilha* pN;
    Pilha* pI;
};

Pilha* criarPilha(){
    Pilha *pd;
    pd = (Pilha*) malloc(sizeof(Pilha));
    if(pd != NULL){
        *pd = NULL;
    }
    return pd;
}

Fila* criarFila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL){
        Pilha *pN = criarPilha();
        Pilha *pI = criarPilha();
        if(pN != NULL && pI != NULL){
            fila->pN = pN;
            fila->pI = pI;
        }
    }
    return fila;
}

int vaziaPilha(Pilha *pd){
    if(pd == NULL){
        return 1;
    }else if(*pd == NULL){
        return 1;
    }else{
        return 0;
    }
}

int inserirPilha(Pilha *pd, int dados){
    if (pd == NULL){
        return 0;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return 0;
        }else{
            novo->dados = dados;
            novo->prox = *pd;
            *pd = novo;
            return 1;
        }
    }
}

void push_empilhar(Fila *fila, int dados){
    if (fila == NULL){
        return;
    }else{
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
        if(novo == NULL){
            return;
        }else{
            novo->dados = dados;
            novo->prox = *fila->pN;
            *fila->pN = novo;
            return;
        }
    }
}

int pop_desempilhar(Fila *fila){
    if(vaziaPilha(fila->pN)){
        return;
    }else{
        int a;
        Elemento *aux = *fila->pN;
        a = aux->dados;
        *fila->pN = aux->prox;
        free(aux);
        return a;
    }
}

void enfileirar(Fila *f, int dados){
    push_empilhar(&f->pN, dados);
}

void desenfileirar(Fila *f){
    int x;

    if(f->pN == NULL && f->pI == NULL){
        printf("A fila esta vazia!");
        return;
    }
    if(f->pI == NULL){
        while(f->pN != NULL){
            x = pop_desempilhar(&f->pN);
            push_empilhar(&f->pI, x);
        }
    }
    x = pop_desempilhar(&f->pI);
    printf("%d", x);
}
