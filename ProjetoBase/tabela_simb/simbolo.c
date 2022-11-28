#include <stdlib.h>
#include <string.h>

#include "simbolo.h"

struct simbolo cria_simbolo(char *ident, int cat, int niv, int tipo_simb, union cat_conteudo conteudo){
    struct simbolo s;
    s.identificador = malloc(strlen(ident)+1); 
    strcpy(s.identificador, ident);

    s.categoria = cat;
    s.nivel = niv;
    switch(cat) {
    case variavel:
        s.conteudo.var = conteudo.var;
        break;
    case parametro:
        s.conteudo.param = conteudo.param;
        break;
    case procedimento:
        s.conteudo.param = conteudo.param;
        break;
    }
    return s;
}
