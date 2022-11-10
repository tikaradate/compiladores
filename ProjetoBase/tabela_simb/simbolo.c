#include <stdlib.h>
#include <string.h>

#include "simbolo.h"

struct simbolo cria_simbolo(char *ident, int cat, int niv, int tipo_simb, union tipo tipo){
    struct simbolo s;
    s.identificador = malloc(strlen(ident)+1); 
    strcpy(s.identificador, ident);

    s.categoria = cat;
    s.nivel = niv;
    s.tipo_simb = tipo_simb;
    switch(tipo_simb) {
    case variavel:
        s.tipo.var = tipo.var;
        break;
    case parametro:
        s.tipo.param = tipo.param;
        break;
    case procedimento:
        s.tipo.param = tipo.param;
        break;
    }
    return s;
}
