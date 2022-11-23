
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


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

char mepa_buf[128];
struct tabela_de_simbolos *ts;
struct simbolo s;
union tipo ti;


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
%token VEZES NUMERO

%union{
   char * str;
}

%type <str> variavel;

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

declara_var : { }
              lista_id_var DOIS_PONTOS
              tipo
              { /* AMEM (ppc - Pelo jeito essa é a forma burra?) */ }
              PONTO_E_VIRGULA
;

tipo        : IDENT
;

lista_id_var: lista_id_var VIRGULA IDENT{ 
               ti.var.tipo = pas_integer; /* TODO MUDAR ISTO */
               ti.var.deslocamento = num_vars;
               s = cria_simbolo(token, variavel, nivel_lex, pas_integer, ti); /* TODO MUDAR O PAS_INTEGER */
               push(&ts, s);
               num_vars++;
            }
            | IDENT { 
               ti.var.tipo = pas_integer; /* TODO MUDAR ISTO */
               ti.var.deslocamento = num_vars;
               s = cria_simbolo(token, variavel, nivel_lex, pas_integer, ti); /* TODO MUDAR O PAS_INTEGER */
               push(&ts, s);
               num_vars++; 
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
   printf("vou atribuir a variavel %s\n", $1);
   // busca(&ts, $1);
   // sprintf(mepa_buf, "ARMZ %d %d", nivel_lex, cur_deslocamento);
}
;

expressao   : expressao_simples relacao expressao_simples 
            | expressao_simples 
; /* ppc: acho que não precisa de regra auxiliar */

relacao     : IGUAL 
            | MENOR MAIOR
            | MENOR
            | MENOR IGUAL
            | MAIOR IGUAL
            | MAIOR
;

expressao_simples : expressao_simples mais_menos_or termo
                  | mais_menos_vazio termo
;

mais_menos_vazio  : MAIS | MENOS | ;

mais_menos_or     : MAIS | MENOS | OR ;

termo             : termo vezes_div_and fator
                  | fator
;

vezes_div_and     : VEZES | DIV | AND ;

fator             : variavel 
                  | ABRE_PARENTESES expressao FECHA_PARENTESES /* ppc - acho que precisa dos parenteses */
                  | NOT fator 
                  | NUMERO
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
