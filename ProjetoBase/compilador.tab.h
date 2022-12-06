/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    LABEL = 259,                   /* LABEL  */
    TYPE = 260,                    /* TYPE  */
    ARRAY = 261,                   /* ARRAY  */
    OF = 262,                      /* OF  */
    VAR = 263,                     /* VAR  */
    PROCEDURE = 264,               /* PROCEDURE  */
    FUNCTION = 265,                /* FUNCTION  */
    T_BEGIN = 266,                 /* T_BEGIN  */
    T_END = 267,                   /* T_END  */
    GOTO = 268,                    /* GOTO  */
    IF = 269,                      /* IF  */
    THEN = 270,                    /* THEN  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    OR = 274,                      /* OR  */
    AND = 275,                     /* AND  */
    NOT = 276,                     /* NOT  */
    DIV = 277,                     /* DIV  */
    ATRIBUICAO = 278,              /* ATRIBUICAO  */
    PONTO_E_VIRGULA = 279,         /* PONTO_E_VIRGULA  */
    DOIS_PONTOS = 280,             /* DOIS_PONTOS  */
    VIRGULA = 281,                 /* VIRGULA  */
    PONTO = 282,                   /* PONTO  */
    ABRE_PARENTESES = 283,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 284,        /* FECHA_PARENTESES  */
    ABRE_COLCHETES = 285,          /* ABRE_COLCHETES  */
    FECHA_COLCHETES = 286,         /* FECHA_COLCHETES  */
    ABRE_CHAVES = 287,             /* ABRE_CHAVES  */
    FECHA_CHAVES = 288,            /* FECHA_CHAVES  */
    IDENT = 289,                   /* IDENT  */
    MAIOR = 290,                   /* MAIOR  */
    MENOR = 291,                   /* MENOR  */
    IGUAL = 292,                   /* IGUAL  */
    MAIS = 293,                    /* MAIS  */
    MENOS = 294,                   /* MENOS  */
    VEZES = 295,                   /* VEZES  */
    NUMERO = 296,                  /* NUMERO  */
    DIFERENTE = 297,               /* DIFERENTE  */
    MENOR_IGUAL = 298,             /* MENOR_IGUAL  */
    MAIOR_IGUAL = 299,             /* MAIOR_IGUAL  */
    VALOR_BOOL = 300,              /* VALOR_BOOL  */
    TIPO = 301                     /* TIPO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "compilador.y"

   char * str;  // define o tipo str
   int int_val; // define o tipo int_val
   struct simbolo *simb;

#line 116 "compilador.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */
