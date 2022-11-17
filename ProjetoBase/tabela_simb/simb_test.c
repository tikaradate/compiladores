#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simb.h"
#include "simbolo.h"

int main(){
    struct simbolo var, param, proc;
    union tipo conteudo;
    // conteudo.var.tipo = 0;
    // conteudo.var.deslocamento = 99;
    // var = cria_simbolo("teste", 123, 532, variavel, conteudo);
    // printf("%d\n", var.tipo.var.deslocamento);

    // conteudo.param.deslocamento = 98;
    // conteudo.param.passagem = 1;
    // conteudo.param.tipo = 3;
    // param = cria_simbolo("cont", 123, 532, variavel, conteudo);
    // printf("%s\n", param.identificador);

    conteudo.proc.rotulo = malloc(strlen("soma"));
    strcpy(conteudo.proc.rotulo, "soma");
    conteudo.proc.qtd_parametros = 13;
    conteudo.proc.lista = NULL;
    proc = cria_simbolo("soma", 56, 65, procedimento, conteudo);


    struct tabela_de_simbolos *ts;
    inicializa(&ts);                 
    push(&ts, proc);
    push(&ts, proc);
    push(&ts, proc);
    push(&ts, proc);
    printf("%d\n", ts->qtd);

    struct simbolo s = pop(&ts);
    printf("%s\n", s.identificador);
    printf("%d\n", ts->qtd);


    return 0;
}