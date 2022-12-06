/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "compilador.y"

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
short int rot_num;
char rot_str[4];
int rot_w;


#line 101 "compilador.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_LABEL = 4,                      /* LABEL  */
  YYSYMBOL_TYPE = 5,                       /* TYPE  */
  YYSYMBOL_ARRAY = 6,                      /* ARRAY  */
  YYSYMBOL_OF = 7,                         /* OF  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_PROCEDURE = 9,                  /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 10,                  /* FUNCTION  */
  YYSYMBOL_T_BEGIN = 11,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 12,                     /* T_END  */
  YYSYMBOL_GOTO = 13,                      /* GOTO  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_ATRIBUICAO = 23,                /* ATRIBUICAO  */
  YYSYMBOL_PONTO_E_VIRGULA = 24,           /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 25,               /* DOIS_PONTOS  */
  YYSYMBOL_VIRGULA = 26,                   /* VIRGULA  */
  YYSYMBOL_PONTO = 27,                     /* PONTO  */
  YYSYMBOL_ABRE_PARENTESES = 28,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 29,          /* FECHA_PARENTESES  */
  YYSYMBOL_ABRE_COLCHETES = 30,            /* ABRE_COLCHETES  */
  YYSYMBOL_FECHA_COLCHETES = 31,           /* FECHA_COLCHETES  */
  YYSYMBOL_ABRE_CHAVES = 32,               /* ABRE_CHAVES  */
  YYSYMBOL_FECHA_CHAVES = 33,              /* FECHA_CHAVES  */
  YYSYMBOL_IDENT = 34,                     /* IDENT  */
  YYSYMBOL_MAIOR = 35,                     /* MAIOR  */
  YYSYMBOL_MENOR = 36,                     /* MENOR  */
  YYSYMBOL_IGUAL = 37,                     /* IGUAL  */
  YYSYMBOL_MAIS = 38,                      /* MAIS  */
  YYSYMBOL_MENOS = 39,                     /* MENOS  */
  YYSYMBOL_VEZES = 40,                     /* VEZES  */
  YYSYMBOL_NUMERO = 41,                    /* NUMERO  */
  YYSYMBOL_DIFERENTE = 42,                 /* DIFERENTE  */
  YYSYMBOL_MENOR_IGUAL = 43,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 44,               /* MAIOR_IGUAL  */
  YYSYMBOL_VALOR_BOOL = 45,                /* VALOR_BOOL  */
  YYSYMBOL_TIPO = 46,                      /* TIPO  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_programa = 48,                  /* programa  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_bloco = 50,                     /* bloco  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_parte_declara_vars = 52,        /* parte_declara_vars  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_declara_vars = 55,              /* declara_vars  */
  YYSYMBOL_declara_var = 56,               /* declara_var  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_tipo = 59,                      /* tipo  */
  YYSYMBOL_lista_id_var = 60,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 61,              /* lista_idents  */
  YYSYMBOL_comando_composto = 62,          /* comando_composto  */
  YYSYMBOL_comandos = 63,                  /* comandos  */
  YYSYMBOL_comando_sem_rotulo = 64,        /* comando_sem_rotulo  */
  YYSYMBOL_atribuicao = 65,                /* atribuicao  */
  YYSYMBOL_expressao = 66,                 /* expressao  */
  YYSYMBOL_relacao = 67,                   /* relacao  */
  YYSYMBOL_expressao_simples = 68,         /* expressao_simples  */
  YYSYMBOL_mais_menos_vazio = 69,          /* mais_menos_vazio  */
  YYSYMBOL_mais_menos_or = 70,             /* mais_menos_or  */
  YYSYMBOL_termo = 71,                     /* termo  */
  YYSYMBOL_vezes_div_and = 72,             /* vezes_div_and  */
  YYSYMBOL_fator = 73,                     /* fator  */
  YYSYMBOL_variavel = 74,                  /* variavel  */
  YYSYMBOL_comando_repetitivo = 75,        /* comando_repetitivo  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_77_7 = 77                       /* $@7  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   61

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  84

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    69,    83,    82,    97,   101,   101,   105,
     108,   109,   112,   115,   112,   119,   122,   128,   136,   137,
     141,   144,   144,   147,   148,   149,   153,   167,   168,   178,
     179,   180,   181,   182,   183,   187,   205,   218,   219,   220,
     223,   224,   225,   229,   246,   249,   250,   251,   255,   261,
     266,   274,   275,   287,   289,   294,   289
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "LABEL",
  "TYPE", "ARRAY", "OF", "VAR", "PROCEDURE", "FUNCTION", "T_BEGIN",
  "T_END", "GOTO", "IF", "THEN", "ELSE", "WHILE", "DO", "OR", "AND", "NOT",
  "DIV", "ATRIBUICAO", "PONTO_E_VIRGULA", "DOIS_PONTOS", "VIRGULA",
  "PONTO", "ABRE_PARENTESES", "FECHA_PARENTESES", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "ABRE_CHAVES", "FECHA_CHAVES", "IDENT", "MAIOR",
  "MENOR", "IGUAL", "MAIS", "MENOS", "VEZES", "NUMERO", "DIFERENTE",
  "MENOR_IGUAL", "MAIOR_IGUAL", "VALOR_BOOL", "TIPO", "$accept",
  "programa", "$@1", "bloco", "$@2", "parte_declara_vars", "var", "$@3",
  "declara_vars", "declara_var", "$@4", "$@5", "tipo", "lista_id_var",
  "lista_idents", "comando_composto", "comandos", "comando_sem_rotulo",
  "atribuicao", "expressao", "relacao", "expressao_simples",
  "mais_menos_vazio", "mais_menos_or", "termo", "vezes_div_and", "fator",
  "variavel", "comando_repetitivo", "$@6", "$@7", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -37,     7,    12,   -37,   -18,     9,     4,   -37,   -21,     5,
      16,   -37,    30,    15,   -37,   -37,    36,   -37,    34,   -37,
      -6,   -37,    14,   -37,    18,   -37,   -37,    22,   -37,   -37,
      27,   -37,   -37,   -37,   -12,   -29,   -37,    -6,   -29,     8,
      19,   -37,   -37,   -37,   -17,     2,   -37,   -37,   -37,   -37,
     -37,    37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -29,     2,     2,   -29,   -37,   -37,   -16,   -37,   -37,
      32,    -6,    -7,   -16,   -37,    28,   -37,   -37,   -37,     2,
     -37,   -37,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    19,     0,     0,
       0,    18,     7,     0,     4,     6,     0,     3,     0,    12,
      25,     5,     8,    11,     0,    54,    53,     0,    21,    23,
       0,    24,    10,    17,     0,    39,    20,    25,    39,     0,
       0,    37,    38,    55,    27,     0,    22,    26,    15,    13,
      16,     0,    42,    34,    31,    29,    40,    41,    30,    32,
      33,    39,     0,     0,    39,    49,    50,    36,    44,    48,
       0,    25,    28,    35,    52,     0,    47,    46,    45,     0,
      14,    56,    51,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    38,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -36,   -37,   -35,
     -37,    -3,   -37,   -37,    -1,   -37,   -30,   -20,   -37,   -37,
     -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    18,    14,    15,    16,    22,    23,
      24,    70,    49,    34,     8,    21,    27,    28,    29,    43,
      61,    44,    45,    62,    67,    79,    68,    69,    31,    35,
      51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    46,    52,    47,    76,     9,    77,     3,    10,    41,
      42,    25,    52,    39,    40,     4,     5,    30,    53,    54,
      55,    56,    57,    63,    78,    58,    59,    60,    26,    75,
      64,    56,    57,    74,    36,    81,    26,     6,     7,    11,
      12,    -9,    17,    65,    19,    20,    37,    66,   -12,    83,
      38,    30,    33,    50,    48,    71,    80,    82,    72,     0,
      32,    73
};

static const yytype_int8 yycheck[] =
{
      20,    37,    19,    38,    20,    26,    22,     0,    29,    38,
      39,    17,    19,    25,    26,     3,    34,    37,    35,    36,
      37,    38,    39,    21,    40,    42,    43,    44,    34,    64,
      28,    38,    39,    63,    12,    71,    34,    28,    34,    34,
      24,    11,    27,    41,     8,    11,    24,    45,    34,    79,
      23,    71,    34,    34,    46,    18,    24,    29,    61,    -1,
      22,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,     3,    34,    28,    34,    61,    26,
      29,    34,    24,    50,    52,    53,    54,    27,    51,     8,
      11,    62,    55,    56,    57,    17,    34,    63,    64,    65,
      74,    75,    56,    34,    60,    76,    12,    24,    23,    25,
      26,    38,    39,    66,    68,    69,    64,    66,    46,    59,
      34,    77,    19,    35,    36,    37,    38,    39,    42,    43,
      44,    67,    70,    21,    28,    41,    45,    71,    73,    74,
      58,    18,    68,    71,    73,    66,    20,    22,    40,    72,
      24,    64,    29,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    49,    48,    51,    50,    52,    54,    53,    53,
      55,    55,    57,    58,    56,    59,    60,    60,    61,    61,
      62,    63,    63,    64,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    73,    74,    76,    77,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     1,     0,     3,     0,
       2,     1,     0,     0,     6,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     0,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     0,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     1,     0,     0,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 69 "compilador.y"
             {
             geraCodigo (NULL, "INPP");
             nivel_lex = 0;
             rot_num = 0;
             }
#line 1240 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA bloco PONTO  */
#line 76 "compilador.y"
                         {
             geraCodigo (NULL, "PARA");
             }
#line 1248 "compilador.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 83 "compilador.y"
              {
               nivel_lex++;
              }
#line 1256 "compilador.tab.c"
    break;

  case 5: /* bloco: parte_declara_vars $@2 comando_composto  */
#line 89 "compilador.y"
              {
               nivel_lex--;
              }
#line 1264 "compilador.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 101 "compilador.y"
              { num_vars = 0; }
#line 1270 "compilador.tab.c"
    break;

  case 8: /* var: $@3 VAR declara_vars  */
#line 101 "compilador.y"
                                                 { 
               sprintf(mepa_buf, "AMEM %d", num_vars);
               geraCodigo(NULL, mepa_buf);
               }
#line 1279 "compilador.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 112 "compilador.y"
              { qt_tipo_atual = 0; }
#line 1285 "compilador.tab.c"
    break;

  case 13: /* $@5: %empty  */
#line 115 "compilador.y"
              { atribui_tipo(&ts, variavel, (yyvsp[0].int_val), qt_tipo_atual); }
#line 1291 "compilador.tab.c"
    break;

  case 15: /* tipo: TIPO  */
#line 119 "compilador.y"
                   { (yyval.int_val) = str2type(token); }
#line 1297 "compilador.tab.c"
    break;

  case 16: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 122 "compilador.y"
                                         {
               ti.var.deslocamento = num_vars;
               s = cria_simbolo(token, variavel, nivel_lex, ti); 
               push(&ts, s);
               num_vars++; qt_tipo_atual++;
            }
#line 1308 "compilador.tab.c"
    break;

  case 17: /* lista_id_var: IDENT  */
#line 128 "compilador.y"
                    { 
               ti.var.deslocamento = num_vars;
               s = cria_simbolo(token, variavel, nivel_lex, ti); 
               push(&ts, s);
               num_vars++; qt_tipo_atual++;
            }
#line 1319 "compilador.tab.c"
    break;

  case 26: /* atribuicao: variavel ATRIBUICAO expressao  */
#line 153 "compilador.y"
                                          {
   if((yyvsp[-2].simb)->conteudo.var.tipo != (yyvsp[0].int_val)){
      fprintf(stderr, "COMPILATION ERROR!!!\n Variable type differs from expression type.\n"); 
      exit(1);
   }
   /* busca posição da variavel */
   sptr = busca( &ts, (yyvsp[-2].simb)->identificador );

   sprintf(mepa_buf, "ARMZ %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
   geraCodigo(NULL, mepa_buf);
}
#line 1335 "compilador.tab.c"
    break;

  case 27: /* expressao: expressao_simples  */
#line 167 "compilador.y"
                                { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1341 "compilador.tab.c"
    break;

  case 28: /* expressao: expressao_simples relacao expressao_simples  */
#line 168 "compilador.y"
                                                         {
               if ((yyvsp[-2].int_val) != (yyvsp[0].int_val)){
                  fprintf(stderr, "COMPILATION ERROR!!!\nCannot compare expressions with different types!\n");
                  exit(1);
               }
               (yyval.int_val) = pas_boolean;
            }
#line 1353 "compilador.tab.c"
    break;

  case 29: /* relacao: IGUAL  */
#line 178 "compilador.y"
                        { (yyval.str) = "CMIG"; }
#line 1359 "compilador.tab.c"
    break;

  case 30: /* relacao: DIFERENTE  */
#line 179 "compilador.y"
                        { (yyval.str) = "CMDG"; }
#line 1365 "compilador.tab.c"
    break;

  case 31: /* relacao: MENOR  */
#line 180 "compilador.y"
                        { (yyval.str) = "CMME"; }
#line 1371 "compilador.tab.c"
    break;

  case 32: /* relacao: MENOR_IGUAL  */
#line 181 "compilador.y"
                        { (yyval.str) = "CMEG"; }
#line 1377 "compilador.tab.c"
    break;

  case 33: /* relacao: MAIOR_IGUAL  */
#line 182 "compilador.y"
                        { (yyval.str) = "CMAG"; }
#line 1383 "compilador.tab.c"
    break;

  case 34: /* relacao: MAIOR  */
#line 183 "compilador.y"
                        { (yyval.str) = "CMMA"; }
#line 1389 "compilador.tab.c"
    break;

  case 35: /* expressao_simples: expressao_simples mais_menos_or termo  */
#line 187 "compilador.y"
                                                          {
                     if (strcmp((yyvsp[-1].str), "DISJ") == 0){
                        if ((yyvsp[-2].int_val) != pas_boolean || (yyvsp[0].int_val) != pas_boolean){
                           fprintf(stderr, "COMPILATION ERROR!!!\n Boolean operation with non-boolean operands!\n");
                           exit(1);
                        }
                        (yyval.int_val) = pas_boolean;
                     }
                     else {
                        if ((yyvsp[-2].int_val) != pas_integer || (yyvsp[0].int_val) != pas_integer){
                           fprintf(stderr, "COMPILATION ERROR!!!\n Integer operation with non-integer operands!\n");
                           exit(1);
                        }
                        (yyval.int_val) = pas_integer;
                     }
                     
                     geraCodigo(NULL, (yyvsp[-1].str));
                  }
#line 1412 "compilador.tab.c"
    break;

  case 36: /* expressao_simples: mais_menos_vazio termo  */
#line 205 "compilador.y"
                                          {
                     if ( strcmp((yyvsp[-1].str), "VAZIO") != 0){
                        if ((yyvsp[0].int_val) != pas_integer){
                           fprintf(stderr, "COMPILATION ERROR!!!\n Sign on non integer type!\n");
                           exit(1);
                        }
                        (yyval.int_val) = pas_integer;
                     } else {
                        (yyval.int_val) = (yyvsp[0].int_val);
                     }
                  }
#line 1428 "compilador.tab.c"
    break;

  case 37: /* mais_menos_vazio: MAIS  */
#line 218 "compilador.y"
                          { (yyval.str) = "MAIS"; }
#line 1434 "compilador.tab.c"
    break;

  case 38: /* mais_menos_vazio: MENOS  */
#line 219 "compilador.y"
                          { (yyval.str) = "MENOS"; }
#line 1440 "compilador.tab.c"
    break;

  case 39: /* mais_menos_vazio: %empty  */
#line 220 "compilador.y"
                          { (yyval.str) = "VAZIO"; }
#line 1446 "compilador.tab.c"
    break;

  case 40: /* mais_menos_or: MAIS  */
#line 223 "compilador.y"
                      { (yyval.str) = strdup("SOMA"); }
#line 1452 "compilador.tab.c"
    break;

  case 41: /* mais_menos_or: MENOS  */
#line 224 "compilador.y"
                       { (yyval.str) = strdup("SUBT"); }
#line 1458 "compilador.tab.c"
    break;

  case 42: /* mais_menos_or: OR  */
#line 225 "compilador.y"
                    { (yyval.str) = strdup("DISJ"); }
#line 1464 "compilador.tab.c"
    break;

  case 43: /* termo: termo vezes_div_and fator  */
#line 229 "compilador.y"
                                  { 
         if (strcmp((yyvsp[-1].str), "CONJ") == 0){
            if ((yyvsp[-2].int_val) != pas_boolean || (yyvsp[0].int_val) != pas_boolean){
               fprintf(stderr, "COMPILATION ERROR!!!\n Boolean operation with non-boolean operands!\n");
               exit(1);
            }
            (yyval.int_val) = pas_boolean;
         }
         else {
            if ((yyvsp[-2].int_val) != pas_integer || (yyvsp[0].int_val) != pas_integer){
               fprintf(stderr, "COMPILATION ERROR!!!\n Integer operation with non-integer operands!\n");
               exit(1);
            }
            (yyval.int_val) = pas_integer;
         }
         geraCodigo(NULL, (yyvsp[-1].str));
      }
#line 1486 "compilador.tab.c"
    break;

  case 45: /* vezes_div_and: VEZES  */
#line 249 "compilador.y"
                       { (yyval.str) = strdup("MULT"); }
#line 1492 "compilador.tab.c"
    break;

  case 46: /* vezes_div_and: DIV  */
#line 250 "compilador.y"
                     { (yyval.str) = strdup("DIVI"); }
#line 1498 "compilador.tab.c"
    break;

  case 47: /* vezes_div_and: AND  */
#line 251 "compilador.y"
                     { (yyval.str) = strdup("CONJ"); }
#line 1504 "compilador.tab.c"
    break;

  case 48: /* fator: variavel  */
#line 255 "compilador.y"
                 { 
         sptr = busca(&ts, (yyvsp[0].simb)->identificador);
         (yyval.int_val) = sptr->conteudo.var.tipo;
         sprintf(mepa_buf, "CRVL %d %d", sptr->nivel, sptr->conteudo.var.deslocamento);
         geraCodigo(NULL, mepa_buf);
      }
#line 1515 "compilador.tab.c"
    break;

  case 49: /* fator: NUMERO  */
#line 261 "compilador.y"
               {
         (yyval.int_val) = pas_integer;
         sprintf (mepa_buf, "CRCT %d", atoi(token));
         geraCodigo(NULL, mepa_buf);
      }
#line 1525 "compilador.tab.c"
    break;

  case 50: /* fator: VALOR_BOOL  */
#line 266 "compilador.y"
                   {
         (yyval.int_val) = pas_boolean;
         if(strcmp(token, "True") == 0)
            sprintf (mepa_buf, "CRCT %d", 1);
         else
            sprintf (mepa_buf, "CRCT %d", 0);
         geraCodigo(NULL, mepa_buf);
      }
#line 1538 "compilador.tab.c"
    break;

  case 51: /* fator: ABRE_PARENTESES expressao FECHA_PARENTESES  */
#line 274 "compilador.y"
                                                   { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1544 "compilador.tab.c"
    break;

  case 52: /* fator: NOT fator  */
#line 275 "compilador.y"
                  {
         printf("as coisa %d %d\n", (yyvsp[0].int_val), pas_boolean);
         if ((yyvsp[0].int_val) != pas_boolean){
            fprintf(stderr, "COMPILATION ERROR!!! Boolean operation with non-boolean value!\n");
            exit(1);
         }
         (yyval.int_val) = pas_boolean;
       }
#line 1557 "compilador.tab.c"
    break;

  case 53: /* variavel: IDENT  */
#line 287 "compilador.y"
                           { (yyval.simb) = busca(&ts, token); }
#line 1563 "compilador.tab.c"
    break;

  case 54: /* $@6: %empty  */
#line 289 "compilador.y"
                           {
                        sprintf(rot_str, "R%02d", rot_num++); 
                        geraCodigo(rot_str, "NADA");
                        rot_w = rot_num++;
                     }
#line 1573 "compilador.tab.c"
    break;

  case 55: /* $@7: %empty  */
#line 294 "compilador.y"
                               {
                        sprintf(mepa_buf, "DSVF R%02d", rot_w);
                        geraCodigo(NULL, mepa_buf);
                     }
#line 1582 "compilador.tab.c"
    break;

  case 56: /* comando_repetitivo: WHILE $@6 expressao $@7 DO comando_sem_rotulo  */
#line 299 "compilador.y"
                                       {
                        sprintf(mepa_buf, "DSVS R%02d", rot_w-1);
                        geraCodigo(NULL, mepa_buf);

                        sprintf(rot_str, "R%02d", rot_w);
                        geraCodigo(rot_str, "NADA");
                     }
#line 1594 "compilador.tab.c"
    break;


#line 1598 "compilador.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 309 "compilador.y"


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
