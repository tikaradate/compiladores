#include <stdbool.h>
#include "tabela_simb.h"

void inicializa(struct tabela_de_simbolos **ts){
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
        (*ts)->simbolos = realloc((*ts)->simbolos, (*ts)->tam*(struct simbolo));
    }
    indice = (*ts)->qtd-1;
    (*ts)->simbolos[indice] = s; 
}

struct simbolo pop(struct tabela_de_simbolos **ts){
    struct simbolo ret;

    ret = (*ts)->simbolos[(*ts)->qtd];
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
