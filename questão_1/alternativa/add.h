#include "agenda.h"

struct elemento {
    struct contato dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;
