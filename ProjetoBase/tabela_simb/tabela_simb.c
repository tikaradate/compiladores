#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "tabela_simb.h"

void inicializa(struct tabela_de_simbolos **ts){
    *ts = malloc(sizeof(struct tabela_de_simbolos));
    (*ts)->simbolos = malloc(sizeof(struct simbolo));
    (*ts)->qtd = 0;
    (*ts)->tam = 1;
}

void push(struct tabela_de_simbolos **ts, struct simbolo s){
    int indice;
    (*ts)->qtd++;

    // se a quantidade de elementos ultrapassa o tamanho alocado
    if((*ts)->qtd > (*ts)->tam){
        (*ts)->tam <<= 1;
        (*ts)->simbolos = realloc((*ts)->simbolos, (*ts)->tam*(sizeof(struct simbolo)));
    }
    indice = (*ts)->qtd-1;
    (*ts)->simbolos[indice] = s; 
    
}

struct simbolo pop(struct tabela_de_simbolos **ts){
    struct simbolo ret;
    int indice = (*ts)->qtd-1;

    ret = (*ts)->simbolos[indice];

    (*ts)->qtd--;
    return ret;
}

void remove_n(struct tabela_de_simbolos **ts, int n){
    (*ts)->qtd -= n;
}

bool busca(struct tabela_de_simbolos **ts, char *ident){
    int indice = (*ts)->qtd-1;
    while(indice >= 0){
        struct simbolo atual =(*ts)->simbolos[indice--];
        if(strcmp(ident, atual.identificador) == 0) return true;
    }
    return false;
}

void atribui_tipo(struct tabela_de_simbolos **ts, int categoria, int tipo, int qtd){
    int indice = (*ts)->qtd-1;
    for(int i = 0; i < qtd; ++i){
        (*ts)->simbolos[indice - i].conteudo.var.tipo = tipo;
        /* acredito que isso atribua tanto pra variavel quanto
        quanto para parametros, por causa da forma que a union
        funciona, se quiser um jeito sem esse xunxo você faria
        um if com a categoria */
    }
}