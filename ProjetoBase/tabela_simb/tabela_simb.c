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

bool busca(struct tabela_de_simbolos **ts, struct simbolo s){
    int indice = (*ts)->qtd-1;
    while(indice >= 0){
        struct simbolo atual =(*ts)->simbolos[indice--]; 
        if(memcmp(&atual, &s, sizeof(struct simbolo))) return true;
    }
    return false;
}
