
int i;

typedef struct fila Fila;
typedef struct elemento* Pilha;

Pilha* criarPilha();
Fila* criarFila();
int vaziaPilha(Pilha *);
void push_empilhar(Fila *, int);
int pop_desempilhar(Fila *);
void enfileirar(Fila *, int);
void desenfileirar(Fila *);
