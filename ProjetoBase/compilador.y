
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
%token MAIOR_IGUAL PAS_TRUE PAS_FALSE TIPO

%union{
   char * str;  // define o tipo str
   int int_val; // define o tipo int_val
}

%type <str> variavel; // atribui o tipo str a regra variavel
%type <str> mais_menos_or;
%type <str> vezes_div_and;
%type <int_val> expressao;
%type <int_val> expressao_simples;
%type <int_val> fator;
%type <int_val> termo;
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

comandos: comando | comandos PONTO_E_VIRGULA comando;

comando: numero_ou_nao comando_sem_rotulo;

numero_ou_nao: NUMERO DOIS_PONTOS | ;

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

expressao   : expressao_simples relacao expressao_simples 
            | expressao_simples  
; 

relacao     : IGUAL
            | DIFERENTE
            | MENOR
            | MENOR_IGUAL
            | MAIOR_IGUAL
            | MAIOR
;

expressao_simples : expressao_simples mais_menos_or termo { geraCodigo(NULL, $2); }
                  | mais_menos_vazio termo { /* lidar com mais ou menos */ }
;

mais_menos_vazio  : MAIS 
                  | MENOS 
                  | 
;

mais_menos_or     : MAIS { $$ = strdup("SOMA"); }
                  | MENOS { $$ = strdup("SUBT"); } 
                  | OR { /*Não sei como eh o or*/ }
; 
termo             : termo vezes_div_and fator { geraCodigo (NULL, $2); }
                  | fator 
;

vezes_div_and     : VEZES { $$ = strdup("MULT"); }
                  | DIV { $$ = strdup("DIVI"); }
                  | AND  {  } 
;

fator             : variavel { 
                     sptr = busca(&ts, $1);
                     sprintf(mepa_buf, "CRVL %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
                     geraCodigo(NULL, mepa_buf);
                  } 
                  | ABRE_PARENTESES expressao FECHA_PARENTESES { /* ppc - acho que precisa dos parenteses */ }
                  {/*| NOT fator */}
                  | NUMERO {
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
