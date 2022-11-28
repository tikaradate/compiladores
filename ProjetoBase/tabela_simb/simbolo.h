#ifndef __SIMBOLO__
#define __SIMBOLO__

enum tipo_simbolo{
    variavel,
    parametro,
    procedimento
};

enum tipo_variavel{
    pas_integer,
    pas_float,
    pas_boolean
};

/* Três tipos de símbolos */
struct variavel{
    int tipo;
    int deslocamento;
};

struct parametro{
    int tipo;
    int deslocamento;
    int passagem;
};

struct procedimento{
    char *rotulo;
    int qtd_parametros;
    struct parametro *lista;
};
/*------------------------*/

struct simbolo{
    char *identificador;
    int categoria;
    int nivel;
    union cat_conteudo{
        struct variavel var;
        struct parametro param;
        struct procedimento proc;
    } conteudo;
};

struct simbolo cria_simbolo(char *ident, int cat, int niv, int tipo_simb, union cat_conteudo tipo);

#endif
