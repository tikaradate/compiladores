
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
#include "pilha/pilha_int.h"

int num_vars;
int num_params;
int curr_params;
int nivel_lex;
int pos_var;
int qt_tipo_atual;
int referencia;
int dentro_proc;

char mepa_buf[128], proc_name[128], idents[128][128];
struct tabela_de_simbolos *ts;
struct simbolo s, *sptr, curr_proc;
struct pilha_int pilha_rotulos;
struct parametro lista_parametros[128];
union cat_conteudo ti;

int str2type(const char *str){
   if (!strcmp(str, "integer")) return pas_integer;
   if (!strcmp(str, "boolean")) return pas_boolean;
   return undefined_type;
}
short int rot_num;
char rot_str[4];
int rot_w;

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
   struct simbolo *simb;
}

%type <simb> variavel; // atribui o tipo str a regra variavel
%type <str> mais_menos_or; // numa expressão
%type <str> mais_menos_vazio; // antes de um fator
%type <str> vezes_div_and;
%type <str> relacao;
%type <int_val> expressao;
%type <int_val> expressao_simples;
%type <int_val> fator;
%type <int_val> termo;
%type <int_val> tipo;

%nonassoc "lower_then_else"
%nonassoc ELSE

%%

// ========== REGRA 01 ========== //
programa    :{
             geraCodigo (NULL, "INPP");
             nivel_lex = 0;
             rot_num = 0;
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA");
             }
;

// ========== REGRA 02 ========== //
bloco       :
              parte_declara_vars
              {
               nivel_lex++;
              }

              {
               sprintf(mepa_buf, "DSVS R%02d", rot_num);
               geraCodigo(NULL, mepa_buf);
               pilha_int_empilhar(&pilha_rotulos, rot_num);
               rot_num++;
              }
              parte_declara_subrotinas

              {
               sprintf(rot_str, "R%02d", pilha_int_topo(&pilha_rotulos));
               geraCodigo(rot_str, "NADA");
               pilha_int_desempilhar(&pilha_rotulos);
              }
              comando_composto

              {
               nivel_lex--;
              }

              ;

// ========== REGRA 08 ========== //
parte_declara_vars: { num_vars = 0; } VAR declara_vars { 
               sprintf(mepa_buf, "AMEM %d", num_vars);
               geraCodigo(NULL, mepa_buf);
               }
            |
;

// ========== REGRA 09 ========== //
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

// ========== REGRA 10 ========== //
lista_idents: lista_idents 
              {
               // lista_parametros[num_params].deslocamento = num_params;
               lista_parametros[num_params].passagem = referencia? parametro_ref : parametro_copia;
              }
              VIRGULA 
              IDENT
              {
               strcpy(idents[num_params], token);
               num_params++;
               curr_params++;
              }
            | IDENT 
              {
               strcpy(idents[num_params], token);
               // lista_parametros[num_params].deslocamento = num_params;
               lista_parametros[num_params].passagem = referencia? parametro_ref : parametro_copia;
               num_params++;
               curr_params++;
              }
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

// ========== REGRA 11 ========== //
parte_declara_subrotinas: parte_declara_subrotinas declara_proc | ;

// ========== REGRA 12 ========== //
declara_proc: PROCEDURE 
              IDENT
              {
               strcpy(proc_name, token);
               num_params = 0;
              }
              parametros_formais_ou_nada
              {
               sprintf(rot_str, "R%02d", rot_num);
               sprintf(mepa_buf, "ENPR %d", nivel_lex);
               geraCodigo(rot_str, mepa_buf);
               
               ti.proc.rotulo = rot_num;
               ti.proc.qtd_parametros = num_params;
               memcpy(ti.proc.lista, lista_parametros, sizeof(struct parametro)*num_params); 
               s = cria_simbolo(proc_name, procedimento, nivel_lex, ti);
               push(&ts, s);
               rot_num++; // para o desvio de procedures dentro dessa procedure
               dentro_proc = 1;
              }

              PONTO_E_VIRGULA 
              bloco 
              {
               sprintf(mepa_buf, "RTPR %d,%d", nivel_lex, 0);
               geraCodigo(NULL, mepa_buf);
               dentro_proc = 0;
              }
;
// ========== REGRA 14 ========== //
parametros_formais_ou_nada: parametros_formais | ;

parametros_formais: ABRE_PARENTESES
                     parametros
                    FECHA_PARENTESES
;

parametros: parametros PONTO_E_VIRGULA secao_parametros | secao_parametros
;

secao_parametros : var_ou_nada
                   {curr_params = 0;}
                   lista_idents 
                   {referencia = 0;}
                   DOIS_PONTOS 
                   tipo
                   {
                     for(int i = num_params-curr_params; i < num_params+curr_params; ++i){
                        ti.param = lista_parametros[i];
                        s = cria_simbolo(idents[i], parametro, nivel_lex, ti);
                        push(&ts, s);
                     }
                     atribui_tipo(&ts, parametro, $6, curr_params);
                   }                   
;

var_ou_nada: VAR {referencia = 1;} | ;
// ========== REGRA 16 ========== //
comando_composto: T_BEGIN comandos T_END
;

// ========== REGRA 17 ========== //
comandos: comando_sem_rotulo | comandos PONTO_E_VIRGULA comando_sem_rotulo;

// ========== REGRA 18 ========== //
comando_sem_rotulo: atribuicao_proc
                  | comando_repetitivo
                  | comando_condicional
                  |
;

atribuicao_proc: variavel a_continua;

a_continua: ATRIBUICAO atribuicao |
            procedimento_sem_parametro |
            procedimento;

// ========== REGRA 19 ========== //
atribuicao: expressao {
   if(sptr->conteudo.var.tipo != $1){
      fprintf(stderr, "COMPILATION ERROR!!!\n Variable type differs from expression type.\n"); 
      exit(1);
   }
   /* busca posição da variavel */
   sptr = busca( &ts, sptr->identificador );

   sprintf(mepa_buf, "ARMZ %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
   geraCodigo(NULL, mepa_buf);
}
;

// ========== REGRA 19 ========== //
procedimento:
             {
              if(!sptr){
                  fprintf(stderr, "COMPILATION ERROR!!!\n Procedure not found.\n"); 
                  exit(1);
              }
              memcpy(&curr_proc, sptr, sizeof(struct simbolo));
              sprintf(proc_name, "CHPR R%02d", sptr->conteudo.proc.rotulo);
             } 
             ABRE_PARENTESES 
             {
               curr_params = 0;
             }
             lista_expressoes
             FECHA_PARENTESES
             {
              if(curr_params != curr_proc.conteudo.proc.qtd_parametros){
                  fprintf(stderr, "COMPILATION ERROR!!!\n Wrong number of parameters.\n"); 
                  exit(1);
              }
              geraCodigo(NULL, proc_name);
             }
             PONTO_E_VIRGULA
;

procedimento_sem_parametro:
              {
               if(!sptr){
                  fprintf(stderr, "COMPILATION ERROR!!!\n Procedure not found.\n"); 
                  exit(1);
               }
               sprintf(mepa_buf, "CHPR R%02d", sptr->conteudo.proc.rotulo);
               geraCodigo(NULL, mepa_buf);
              }
              PONTO_E_VIRGULA;

// ========== REGRA 23 ========== //
comando_repetitivo:  WHILE {
                        pilha_int_empilhar(&pilha_rotulos, rot_num);
                         
                        sprintf(rot_str, "R%02d", rot_num);
                        geraCodigo(rot_str, "NADA");
                        rot_num += 2;
                     }
                     expressao {
                        sprintf(mepa_buf, "DSVF R%02d", pilha_int_topo(&pilha_rotulos)+1);
                        geraCodigo(NULL, mepa_buf); // falta testar expressão
                     }
                     DO 
                     comando_sem_rotulo_ou_composto {
                        sprintf(mepa_buf, "DSVS R%02d", pilha_int_topo(&pilha_rotulos));
                        geraCodigo(NULL, mepa_buf);

                        sprintf(rot_str, "R%02d", pilha_int_topo(&pilha_rotulos)+1);
                        geraCodigo(rot_str, "NADA");

                        pilha_int_desempilhar(&pilha_rotulos);
                     }
;

comando_sem_rotulo_ou_composto: comando_sem_rotulo | comando_composto;

// ========== REGRA 22 ========== //

comando_condicional: IF expressao {
                        if ($2 != pas_boolean){
                           fprintf(stderr, "COMPILATION ERROR!!!\n If expression is not boolean!\n");
                           exit(1);
                        }

                        sprintf(mepa_buf, "DSVF R%02d", rot_num);
                        geraCodigo(NULL, mepa_buf); // falta testar expressão

                        pilha_int_empilhar(&pilha_rotulos, rot_num);
                        rot_num += 2;
                     }  
                     THEN
                     comando_sem_rotulo_ou_composto {
                        sprintf(mepa_buf, "DSVS R%02d", pilha_int_topo(&pilha_rotulos)+1);
                        geraCodigo(NULL, mepa_buf);

                        sprintf(rot_str, "R%02d", pilha_int_topo(&pilha_rotulos));
                        geraCodigo(rot_str, "NADA");

                     } 
                     else_ou_nada{
                        sprintf(rot_str, "R%02d", pilha_int_topo(&pilha_rotulos)+1);
                        geraCodigo(rot_str, "NADA");

                        pilha_int_desempilhar(&pilha_rotulos);
                     }
;

else_ou_nada: ELSE comando_sem_rotulo_ou_composto 
            | %prec "lower_then_else"
;

// ========== REGRA 25 ========== //
lista_expressoes:  expressao {curr_params++;} VIRGULA lista_expressoes | expressao {curr_params++;};

expressao   : expressao_simples { $$ = $1; } 
            | expressao_simples relacao expressao_simples{
               if ($1 != $3){
                  fprintf(stderr, "COMPILATION ERROR!!!\nCannot compare expressions with different types!\n");
                  exit(1);
               }
               geraCodigo(NULL, $2);
               $$ = pas_boolean;
            }
;

// ========== REGRA 26 ========== //
relacao  : IGUAL        { $$ = "CMIG"; }
         | DIFERENTE    { $$ = "CMDG"; }
         | MENOR        { $$ = "CMME"; }
         | MENOR_IGUAL  { $$ = "CMEG"; }
         | MAIOR_IGUAL  { $$ = "CMAG"; }
         | MAIOR        { $$ = "CMMA"; }
;

// ========== REGRA 27 ========== //
expressao_simples : expressao_simples mais_menos_or termo {
                     if (strcmp($2, "DISJ") == 0){
                        if ($1 != pas_boolean || $3 != pas_boolean){
                           fprintf(stderr, "COMPILATION ERROR!!!\n Boolean operation with non-boolean operands!\n");
                           exit(1);
                        }
                        $$ = pas_boolean;
                     }
                     else {
                        if ($1 != pas_integer || $3 != pas_integer){
                           fprintf(stderr, "COMPILATION ERROR!!!\n Integer operation with non-integer operands!\n");
                           exit(1);
                        }
                        $$ = pas_integer;
                     }
                     
                     geraCodigo(NULL, $2);
                  }
                  | mais_menos_vazio termo{
                     if ( strcmp($1, "VAZIO") != 0){
                        if ($2 != pas_integer){
                           fprintf(stderr, "COMPILATION ERROR!!!\n Sign on non integer type!\n");
                           exit(1);
                        }
                        $$ = pas_integer;
                     } else {
                        $$ = $2;
                     }
                     
                     if ( strcmp($1, "MENOS") == 0 )
                        geraCodigo(NULL, "INVR");
                  } 
;

mais_menos_vazio  : MAIS  { $$ = "MAIS"; }
                  | MENOS { $$ = "MENOS"; }
                  |       { $$ = "VAZIO"; }
;

mais_menos_or  : MAIS { $$ = strdup("SOMA"); }
               | MENOS { $$ = strdup("SUBT"); } 
               | OR { $$ = strdup("DISJ"); }
; 

// ========== REGRA 28 ========== //
termo : termo vezes_div_and fator { 
         if (strcmp($2, "CONJ") == 0){
            if ($1 != pas_boolean || $3 != pas_boolean){
               fprintf(stderr, "COMPILATION ERROR!!!\n Boolean operation with non-boolean operands!\n");
               exit(1);
            }
            $$ = pas_boolean;
         }
         else {
            if ($1 != pas_integer || $3 != pas_integer){
               fprintf(stderr, "COMPILATION ERROR!!!\n Integer operation with non-integer operands!\n");
               exit(1);
            }
            $$ = pas_integer;
         }
         geraCodigo(NULL, $2);
      }
      | fator
;

vezes_div_and  : VEZES { $$ = strdup("MULT"); }
               | DIV { $$ = strdup("DIVI"); }
               | AND { $$ = strdup("CONJ"); }
;

// ========== REGRA 29 ========== //
fator : variavel { 
         if(!sptr){
            printf("Variável não encontrada\n");
            exit(1);
         }
         $$ = sptr->conteudo.var.tipo;
         if(!dentro_proc)
            sprintf(mepa_buf, "CRVL %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
         else
            sprintf(mepa_buf, "CRVL %d %d", sptr->nivel, sptr->conteudo.param.deslocamento);

         geraCodigo(NULL, mepa_buf);
      } 
      | NUMERO {
         $$ = pas_integer;
         sprintf (mepa_buf, "CRCT %d", atoi(token));
         geraCodigo(NULL, mepa_buf);
      }
      | VALOR_BOOL {
         $$ = pas_boolean;
         if(strcmp(token, "True") == 0)
            sprintf (mepa_buf, "CRCT %d", 1);
         else
            sprintf (mepa_buf, "CRCT %d", 0);
         geraCodigo(NULL, mepa_buf);
      }
      | ABRE_PARENTESES expressao FECHA_PARENTESES { $$ = $2; }
      | NOT fator {
         if ($2 != pas_boolean){
            fprintf(stderr, "COMPILATION ERROR!!! Boolean operation with non-boolean value!\n");
            exit(1);
         }
         $$ = pas_boolean;
         geraCodigo(NULL, "NEGA");
       }
         /* falta chamada de função */
;

// ========== REGRA 30 ========== //
variavel          :  IDENT { sptr = busca(&ts, token);} ;

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
   pilha_int_inicializar(&pilha_rotulos);

   yyin=fp;
   yyparse();

   pilha_int_destruir(&pilha_rotulos);

   return 0;
}
