#ifndef __TABELA_SIMB__
#define __TABELA_SIMB__

#include <stdbool.h>

#include "simbolo.h"

struct tabela_de_simbolos{
    struct simbolo *simbolos;
    unsigned int qtd;
    unsigned int tam;
};


void inicializa(struct tabela_de_simbolos **);

void push(struct tabela_de_simbolos **, struct simbolo);

struct simbolo pop(struct tabela_de_simbolos **) ;

void remove_n(struct tabela_de_simbolos **, int);

// void topo(struct tabela_de_simbolos **ts);

bool busca(struct tabela_de_simbolos **, char *);

#endif