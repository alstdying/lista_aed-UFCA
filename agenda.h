
#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

struct contato{
    char nome[50];
    char telefone[11];
};

typedef struct elemento *Lista;

Lista* criar(); //retorna um ponteiro para uma lista caso haja sucesso e NULL caso contrario

void destruir(Lista *);

int insereContato(Lista* , struct contato); //retorna 1 caso o contato seja inserido com sucesso na lista e 0 caso contrario

int buscaContato(Lista*, char nome[50], struct contato**); //retorna 1 caso o contato seja encontrado na lista e 0 caso contrario

int removeContato(Lista*, char nome[50]); //retorna 1 caso o contato seja encontrado na lista e 0 caso contrario

#endif // AGENDA_H_INCLUDED
