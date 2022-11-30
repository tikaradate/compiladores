
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.

// Ainda precisa de suporte para booleanos


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabela_simb/tabela_simb.h"
#include "tabela_simb/simbolo.h"

int num_vars;
int nivel_lex;
int pos_var;
int qt_tipo_atual;

char mepa_buf[128];
struct tabela_de_simbolos *ts;
struct simbolo s, *sptr;
union cat_conteudo ti;

int str2type(const char *str){
   if (!strcmp(str, "integer")) return pas_integer;
   if (!strcmp(str, "boolean")) return pas_boolean;
   return undefined_type;
}

%}

%token PROGRAM LABEL TYPE ARRAY OF VAR 
%token PROCEDURE FUNCTION T_BEGIN T_END GOTO IF
%token THEN ELSE WHILE DO OR AND NOT
%token DIV ATRIBUICAO PONTO_E_VIRGULA
%token DOIS_PONTOS VIRGULA PONTO
%token ABRE_PARENTESES FECHA_PARENTESES
%token ABRE_COLCHETES FECHA_COLCHETES
%token ABRE_CHAVES FECHA_CHAVES
%token IDENT MAIOR MENOR IGUAL MAIS MENOS
%token VEZES NUMERO DIFERENTE MENOR_IGUAL
%token MAIOR_IGUAL VALOR_BOOL TIPO

%union{
   char * str;  // define o tipo str
   int int_val; // define o tipo int_val
}

%type <str> variavel; // atribui o tipo str a regra variavel
%type <str> mais_menos;
%type <str> vezes_div;
%type <int_val> fator_int;
%type <int_val> termo_int;
%type <int_val> tipo;

%%

programa    :{
             geraCodigo (NULL, "INPP");
             nivel_lex = 0;
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA");
             }
;

bloco       :
              parte_declara_vars
              {
               nivel_lex++;
              }

              comando_composto

              {
               nivel_lex--;
              }
              ;




parte_declara_vars:  var
;


var         : { num_vars = 0; } VAR declara_vars { 
               sprintf(mepa_buf, "AMEM %d", num_vars);
               geraCodigo(NULL, mepa_buf);
               }
            |
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : { qt_tipo_atual = 0; }
              lista_id_var DOIS_PONTOS
              tipo
              { atribui_tipo(&ts, variavel, $4, qt_tipo_atual); }
              PONTO_E_VIRGULA
;

tipo        : TIPO { $$ = str2type(token); }
;

lista_id_var: lista_id_var VIRGULA IDENT {
               ti.var.deslocamento = num_vars;
               s = cria_simbolo(token, variavel, nivel_lex, ti); 
               push(&ts, s);
               num_vars++; qt_tipo_atual++;
            }
            | IDENT { 
               ti.var.deslocamento = num_vars;
               s = cria_simbolo(token, variavel, nivel_lex, ti); 
               push(&ts, s);
               num_vars++; qt_tipo_atual++;
            }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END
;

comandos: comando_sem_rotulo | comandos PONTO_E_VIRGULA comando_sem_rotulo;


comando_sem_rotulo: atribuicao 
                  | expressao 
                  |
;


atribuicao: variavel ATRIBUICAO expressao {
   /* busca posição da variavel */
   sptr = busca( &ts, $1 );

   sprintf(mepa_buf, "ARMZ %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
   geraCodigo(NULL, mepa_buf);
}
;

expressao   : expressao_int {printf("aaaaa int\n");} | expressao_bool {printf("aaaaa bool\n");}

relacao_int : IGUAL
            | DIFERENTE
            | MENOR
            | MENOR_IGUAL
            | MAIOR_IGUAL
            | MAIOR
;

expressao_int : expressao_int mais_menos termo_int { geraCodigo(NULL, $2); }
                  | mais_menos_vazio termo_int { /* lidar com mais ou menos */ }
;

mais_menos_vazio  : MAIS 
                  | MENOS 
                  | 
;

mais_menos     : MAIS { $$ = strdup("SOMA"); }
               | MENOS { $$ = strdup("SUBT"); } 
; 

termo_int         : termo_int vezes_div fator_int { geraCodigo (NULL, $2); }
                  | fator_int { printf("AAAAAAAAAAAAA cheguei no fator\n") ;}
;

vezes_div      : VEZES { $$ = strdup("MULT"); }
               | DIV { $$ = strdup("DIVI"); }
;

fator_int         : variavel { 
                     sptr = busca(&ts, $1);
                     sprintf(mepa_buf, "CRVL %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
                     geraCodigo(NULL, mepa_buf);
                  } 
                  | ABRE_PARENTESES expressao_int FECHA_PARENTESES { /* ppc - acho que precisa dos parenteses */ }
                  {/*| NOT fator_int */}
                  | NUMERO {
                     sprintf (mepa_buf, "CRCT %d", atoi(token));
                     geraCodigo(NULL, mepa_buf);
                  }
;

expressao_bool : expressao_simples_bool relacao_bool expressao_simples_bool
               | expressao_int relacao_int expressao_int
               | expressao_simples_bool;

relacao_bool   : IGUAL
               | DIFERENTE
;

expressao_simples_bool : expressao_simples_bool OR termo_bool 
                  { geraCodigo(NULL, "DISJ"); }
                  | termo_bool 
;

termo_bool         : termo_bool AND fator_int { geraCodigo (NULL, "CONJ"); }
                  | fator_bool 
;

fator_bool         : variavel { 
                     sptr = busca(&ts, $1);
                     sprintf(mepa_buf, "CRVL %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
                     geraCodigo(NULL, mepa_buf);
                  } 
                  | ABRE_PARENTESES expressao_bool FECHA_PARENTESES { /* ppc - acho que precisa dos parenteses */ }
                  NOT fator_bool
                  | VALOR_BOOL {
                     sprintf (mepa_buf, "CRCT %d", atoi(token));
                     geraCodigo(NULL, mepa_buf);
                  }
;

variavel          :  IDENT { $$ = strdup(token); } ;

%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
   inicializa(&ts);

   yyin=fp;
   yyparse();

   return 0;
}
