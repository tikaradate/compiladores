
struct tabela_de_simbolos{
    struct simbolo *simbolos;
    unsigned int size;
};

struct simbolo{
    char *identificador;
    int categoria;
    int nivel;
    union {
        struct variavel var;
        struct parametro param;
        struct procedimento proc;
    };
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

void inicializa_pilha(struct tabela_de_simbolos **ts);

void insere(struct tabela_de_simbolos **ts);

void remove(struct tabela_de_simbolos **ts);

void topo(struct tabela_de_simbolos **ts);

void busca(struct tabela_de_simbolos **ts);
