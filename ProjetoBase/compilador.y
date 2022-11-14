
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars;
char mepa_buf[128];

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
%token VEZES

%%

programa    :{
             geraCodigo (NULL, "INPP");
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
              }

              comando_composto
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

lista_id_var: lista_id_var VIRGULA IDENT
              { num_vars++; /* insere �ltima vars na tabela de s�mbolos */ }
            | IDENT { num_vars++; /* insere vars na tabela de s�mbolos */}
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END
;

comandos: expressao PONTO_E_VIRGULA | comandos PONTO_E_VIRGULA expressao ;


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
;

variavel          : IDENT ;

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

   yyin=fp;
   yyparse();

   return 0;
}
