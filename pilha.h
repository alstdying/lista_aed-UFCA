
#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
struct aluno{
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct elemento* Pilha;
typedef struct conjunto_de_pilhas* Conjunto;

Pilha* criar();
Conjunto* criar_c();
int vazia(Pilha *);
int inserir(Pilha *, struct aluno);
int remover(Pilha *);
int acessar(Pilha*, struct aluno *);
void destruir(Pilha *);
int imprimePilha(Pilha* pd);


#endif // PILHADINAMICA_H_INCLUDED
