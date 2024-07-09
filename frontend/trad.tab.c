/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "trad.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;
char funcion[64];

// Definitions for explicit attributes

typedef struct s_attr {
        int value ;
        char *code ;
} t_attr ;

#define YYSTYPE t_attr


#line 101 "trad.tab.c"

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

#include "trad.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PUTS = 9,                       /* PUTS  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NEQ = 13,                       /* NEQ  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_LEQ = 15,                       /* LEQ  */
  YYSYMBOL_GEQ = 16,                       /* GEQ  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_UNARY_SIGN = 28,                /* UNARY_SIGN  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_axioma = 39,                    /* axioma  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_variables = 41,                 /* variables  */
  YYSYMBOL_mas_definir = 42,               /* mas_definir  */
  YYSYMBOL_funciones = 43,                 /* funciones  */
  YYSYMBOL_lista_parametros = 44,          /* lista_parametros  */
  YYSYMBOL_return = 45,                    /* return  */
  YYSYMBOL_main = 46,                      /* main  */
  YYSYMBOL_sentencias = 47,                /* sentencias  */
  YYSYMBOL_sentencia = 48,                 /* sentencia  */
  YYSYMBOL_estructura = 49,                /* estructura  */
  YYSYMBOL_sentencias_if = 50,             /* sentencias_if  */
  YYSYMBOL_inicializ = 51,                 /* inicializ  */
  YYSYMBOL_incdec = 52,                    /* incdec  */
  YYSYMBOL_definiciones = 53,              /* definiciones  */
  YYSYMBOL_definir = 54,                   /* definir  */
  YYSYMBOL_expresiones = 55,               /* expresiones  */
  YYSYMBOL_nombre_funcion = 56,            /* nombre_funcion  */
  YYSYMBOL_nombre_main = 57,               /* nombre_main  */
  YYSYMBOL_expresion = 58,                 /* expresion  */
  YYSYMBOL_llamar_funcion = 59,            /* llamar_funcion  */
  YYSYMBOL_enter_parametros = 60,          /* enter_parametros  */
  YYSYMBOL_condicional = 61,               /* condicional  */
  YYSYMBOL_termino = 62,                   /* termino  */
  YYSYMBOL_operando = 63                   /* operando  */
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
typedef yytype_uint8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      31,    32,    26,    24,    30,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
      22,    21,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    72,    73,    74,    77,
      79,    83,    85,    88,    90,    92,    95,    97,    99,   103,
     105,   106,   108,   111,   113,   115,   117,   119,   121,   123,
     125,   127,   131,   133,   135,   137,   142,   144,   148,   150,
     152,   156,   158,   162,   164,   168,   170,   172,   176,   178,
     182,   187,   193,   194,   196,   198,   200,   202,   203,   204,
     209,   213,   215,   219,   221,   223,   225,   227,   229,   231,
     233,   235,   237,   239,   241,   243,   245,   247,   249,   251,
     253,   257,   258,   260,   264,   266,   268,   269
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "PUTS", "PRINTF", "AND", "OR",
  "NEQ", "EQ", "LEQ", "GEQ", "IF", "ELSE", "FOR", "RETURN", "'='", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "UNARY_SIGN", "';'", "','", "'('",
  "')'", "'{'", "'}'", "'['", "']'", "'%'", "$accept", "axioma",
  "programa", "variables", "mas_definir", "funciones", "lista_parametros",
  "return", "main", "sentencias", "sentencia", "estructura",
  "sentencias_if", "inicializ", "incdec", "definiciones", "definir",
  "expresiones", "nombre_funcion", "nombre_main", "expresion",
  "llamar_funcion", "enter_parametros", "condicional", "termino",
  "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,  -186,    -2,  -186,    11,  -186,    38,  -186,  -186,   -18,
      -9,    -1,     0,  -186,  -186,    23,     5,    49,    45,    36,
      -2,    46,    29,    35,  -186,    30,    32,    32,     1,  -186,
    -186,    48,    -2,  -186,    53,    56,    71,    74,    62,   122,
    -186,  -186,    12,  -186,    51,  -186,  -186,  -186,   104,   130,
      -2,    23,    62,    -4,    -2,   107,   117,    15,   119,   145,
     127,   159,    62,  -186,   154,    49,   128,     1,     1,     1,
       1,  -186,    36,  -186,  -186,  -186,   167,     1,   143,   161,
       1,   193,     1,    79,     1,   158,  -186,    62,  -186,  -186,
     169,   173,   168,   138,   138,  -186,  -186,  -186,     1,   172,
      79,   178,   179,    -2,   129,   157,   184,    63,   170,   196,
     201,   189,  -186,  -186,    49,  -186,   171,    38,   200,   202,
    -186,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,   191,     1,
    -186,     1,   192,    49,   206,     1,  -186,  -186,  -186,     1,
       1,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    62,    79,
     190,    72,    62,  -186,    49,   197,    79,    79,   194,  -186,
       1,   203,   195,  -186,   226,  -186,  -186,    62,   213,   212,
     204,  -186,   205,   231,   207,    62,   150,    62,   208,   234,
     236,   209,  -186,  -186,  -186,  -186
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    50,     0,    51,     0,     2,     0,     4,    12,     0,
       0,    46,     0,     1,     3,    15,     0,     0,     0,     6,
       0,     0,     0,     0,    85,    84,     0,     0,     0,    45,
      81,     0,     0,     5,     0,    44,    14,     0,     0,     0,
      82,    83,    84,    57,     0,    58,    52,    47,     0,     7,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    31,     0,     0,     0,     0,     0,     0,
       0,    86,    10,     8,    43,    13,    17,     0,     0,    28,
       0,     0,     0,    26,     0,     0,    18,    20,    21,    87,
       0,    62,     0,    53,    54,    55,    56,     9,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    60,     0,    59,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,    38,     0,    61,    16,    11,     0,
       0,    63,    64,    65,    66,    68,    70,    67,    69,    71,
      72,    73,    74,    75,    77,    79,    76,    78,     0,    80,
       0,    49,     0,    40,     0,     0,    24,    25,     0,    27,
       0,    36,     0,    39,     0,    32,    48,     0,    33,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    41,    42,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -186,   198,   174,    10,   199,  -186,  -186,   -29,
    -186,  -186,  -185,  -186,  -186,   -44,     6,    61,  -186,  -186,
     -13,   -38,   131,   -83,   -14,   151
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    33,     7,    22,    99,     8,   181,
      61,    62,   182,   111,   190,    34,    35,   170,     9,    10,
     104,    45,    90,   105,    46,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,   108,    11,    29,    24,    42,    74,    43,    12,    60,
     198,    13,   201,    15,    63,    44,    14,    77,    24,    42,
      17,    43,    16,    76,    63,    26,    27,    65,    21,    19,
      20,    78,    28,    88,    18,    24,    25,    23,    48,    26,
      27,    32,     1,    65,    83,     3,    82,    66,    31,    63,
      36,    91,    24,    25,    93,    94,    95,    96,   112,   120,
      79,    37,   175,    28,   100,    39,    53,    54,    38,   107,
      55,    56,    57,    26,    27,    67,    68,    69,    70,    58,
      28,    59,    49,    71,    47,   116,    50,    67,    68,    69,
      70,     1,     2,   141,     3,    71,    67,    68,    69,    70,
      91,    51,   180,    67,    68,    69,    70,    52,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    64,   169,   148,   171,   173,
      63,    64,    92,    72,    63,     2,   176,   177,    80,   178,
     121,   122,   123,   124,   125,   126,   101,   102,    81,    63,
      84,   127,   128,    67,    68,    69,    70,    63,   191,    63,
     183,    86,   109,   110,    69,    70,   129,   171,   130,   131,
     132,   133,   134,   135,   199,   200,    85,    40,    41,   136,
     137,   130,   131,   132,   133,   134,   135,    98,    87,   138,
      89,   103,   136,   137,   139,    67,    68,    69,    70,   106,
     147,   113,   142,   114,   115,   144,   117,   139,   130,   131,
     132,   133,   134,   135,   118,   119,   140,   143,   145,   136,
     137,   149,   179,   150,   168,   172,   184,   174,   185,   188,
     189,   192,   187,   193,   139,   196,   194,   203,   195,   204,
     197,   186,   202,   205,     0,   146,    97,    73,     0,     0,
      75
};

static const yytype_int16 yycheck[] =
{
      38,    84,     4,    17,     3,     4,    50,     6,     2,    38,
     195,     0,   197,    31,    52,    28,     6,    21,     3,     4,
      21,     6,    31,    52,    62,    24,    25,    31,     5,    29,
      30,    35,    31,    62,    35,     3,     4,    32,    32,    24,
      25,     5,     4,    31,    57,     7,    31,    35,     3,    87,
       4,    65,     3,     4,    67,    68,    69,    70,    87,   103,
      54,    32,   145,    31,    77,    35,     4,     5,    33,    82,
       8,     9,    10,    24,    25,    24,    25,    26,    27,    17,
      31,    19,    29,    32,    36,    98,    30,    24,    25,    26,
      27,     4,     5,    30,     7,    32,    24,    25,    26,    27,
     114,    30,    30,    24,    25,    26,    27,    33,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     3,   139,   117,   141,   143,
     168,     3,     4,    29,   172,     5,   149,   150,    31,   168,
      11,    12,    13,    14,    15,    16,     3,     4,    31,   187,
      31,    22,    23,    24,    25,    26,    27,   195,   187,   197,
     174,    34,     4,     5,    26,    27,    37,   180,    11,    12,
      13,    14,    15,    16,    24,    25,    31,    26,    27,    22,
      23,    11,    12,    13,    14,    15,    16,    20,    29,    32,
      36,    30,    22,    23,    37,    24,    25,    26,    27,     6,
      29,    32,    32,    30,    36,     4,    34,    37,    11,    12,
      13,    14,    15,    16,    36,    36,    32,    21,    29,    22,
      23,    21,    32,    21,    33,    33,    29,    21,    34,    34,
       4,    18,    29,    21,    37,     4,    32,     3,    33,     3,
      33,   180,    34,    34,    -1,   114,    72,    49,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,    39,    40,    41,    43,    46,    56,
      57,     4,    54,     0,    43,    31,    31,    21,    35,    29,
      30,     5,    44,    32,     3,     4,    24,    25,    31,    62,
      63,     3,     5,    42,    53,    54,     4,    32,    33,    35,
      63,    63,     4,     6,    58,    59,    62,    36,    54,    29,
      30,    30,    33,     4,     5,     8,     9,    10,    17,    19,
      47,    48,    49,    59,     3,    31,    35,    24,    25,    26,
      27,    32,    29,    41,    53,    44,    47,    21,    35,    54,
      31,    31,    31,    58,    31,    31,    34,    29,    47,    36,
      60,    62,     4,    58,    58,    58,    58,    42,    20,    45,
      58,     3,     4,    30,    58,    61,     6,    58,    61,     4,
       5,    51,    47,    32,    30,    36,    58,    34,    36,    36,
      53,    11,    12,    13,    14,    15,    16,    22,    23,    37,
      11,    12,    13,    14,    15,    16,    22,    23,    32,    37,
      32,    30,    32,    21,     4,    29,    60,    29,    43,    21,
      21,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    33,    58,
      55,    58,    33,    62,    21,    61,    58,    58,    47,    32,
      30,    47,    50,    62,    29,    34,    55,    29,    34,     4,
      52,    47,    18,    21,    32,    33,     4,    33,    50,    24,
      25,    50,    34,     3,     3,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    42,
      42,    43,    43,    44,    44,    44,    45,    45,    46,    47,
      47,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    55,    55,
      56,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     3,     5,     6,     4,
       3,     9,     1,     4,     2,     0,     3,     0,     6,     3,
       2,     2,     1,     3,     6,     6,     2,     6,     2,     4,
       4,     1,     7,     7,    11,    11,     1,     3,     2,     4,
       3,     5,     5,     3,     1,     3,     1,     4,     3,     1,
       1,     1,     1,     3,     3,     3,     3,     1,     1,     4,
       4,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     1,     1,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* axioma: programa  */
#line 64 "trad.y"
                                   { ; }
#line 1286 "trad.tab.c"
    break;

  case 3: /* programa: variables funciones  */
#line 67 "trad.y"
                                          { ; }
#line 1292 "trad.tab.c"
    break;

  case 4: /* programa: funciones  */
#line 68 "trad.y"
                                          { ; }
#line 1298 "trad.tab.c"
    break;

  case 5: /* variables: INTEGER definir ';' mas_definir  */
#line 71 "trad.y"
                                                   { printf ("(setq %s)\n%s", yyvsp[-2].code, yyvsp[0].code) ;  }
#line 1304 "trad.tab.c"
    break;

  case 6: /* variables: INTEGER definir ';'  */
#line 72 "trad.y"
                                                  { printf ("(setq %s)\n", yyvsp[-1].code) ;  }
#line 1310 "trad.tab.c"
    break;

  case 7: /* variables: INTEGER definir ',' definiciones ';'  */
#line 73 "trad.y"
                                                    { printf ("(setq %s) %s\n", yyvsp[-3].code, yyvsp[-1].code) ; }
#line 1316 "trad.tab.c"
    break;

  case 8: /* variables: INTEGER definir ',' definiciones ';' variables  */
#line 74 "trad.y"
                                                              { printf ("(setq %s) %s\n%s", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].code) ; }
#line 1322 "trad.tab.c"
    break;

  case 9: /* mas_definir: INTEGER definir ';' mas_definir  */
#line 77 "trad.y"
                                                {sprintf(temp, "(setq %s) \n%s", yyvsp[-2].code, yyvsp[0].code);
                                                yyval.code = gen_code(temp);}
#line 1329 "trad.tab.c"
    break;

  case 10: /* mas_definir: INTEGER definir ';'  */
#line 79 "trad.y"
                                                 {sprintf(temp, "(setq %s) \n", yyvsp[-1].code);
                                                yyval.code = gen_code(temp);}
#line 1336 "trad.tab.c"
    break;

  case 11: /* funciones: nombre_funcion '(' lista_parametros ')' '{' sentencias return '}' funciones  */
#line 83 "trad.y"
                                                                                          { printf("(defun %s(%s) %s %s)\n%s", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-3].code, yyvsp[-2].code, yyvsp[0].code);}
#line 1342 "trad.tab.c"
    break;

  case 12: /* funciones: main  */
#line 85 "trad.y"
                                          { ; }
#line 1348 "trad.tab.c"
    break;

  case 13: /* lista_parametros: INTEGER IDENTIF ',' lista_parametros  */
#line 88 "trad.y"
                                                          { sprintf (temp, "%s, %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1355 "trad.tab.c"
    break;

  case 14: /* lista_parametros: INTEGER IDENTIF  */
#line 90 "trad.y"
                                                          { sprintf (temp, "%s", yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1362 "trad.tab.c"
    break;

  case 15: /* lista_parametros: %empty  */
#line 92 "trad.y"
                  {;}
#line 1368 "trad.tab.c"
    break;

  case 16: /* return: RETURN expresion ';'  */
#line 95 "trad.y"
                               {sprintf(temp, "return-from %s %s", funcion, yyvsp[-1].code);
                            yyval.code = gen_code(temp);}
#line 1375 "trad.tab.c"
    break;

  case 17: /* return: %empty  */
#line 97 "trad.y"
          {;}
#line 1381 "trad.tab.c"
    break;

  case 18: /* main: nombre_main '(' ')' '{' sentencias '}'  */
#line 99 "trad.y"
                                                     { sprintf(temp, "(defun main() %s)", yyvsp[-1].code);
                                                			       yyval.code = gen_code(temp) ;}
#line 1388 "trad.tab.c"
    break;

  case 19: /* sentencias: sentencia ';' sentencias  */
#line 103 "trad.y"
                                        {sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
                                        yyval.code = gen_code(temp);}
#line 1395 "trad.tab.c"
    break;

  case 20: /* sentencias: sentencia ';'  */
#line 105 "trad.y"
                                        {yyval = yyvsp[-1]; }
#line 1401 "trad.tab.c"
    break;

  case 21: /* sentencias: estructura sentencias  */
#line 106 "trad.y"
                                       {sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code);
                                        yyval.code = gen_code(temp);}
#line 1408 "trad.tab.c"
    break;

  case 22: /* sentencias: estructura  */
#line 108 "trad.y"
                                       {yyval = yyvsp[0]; }
#line 1414 "trad.tab.c"
    break;

  case 23: /* sentencia: IDENTIF '=' expresion  */
#line 111 "trad.y"
                                         { sprintf (temp, "(setf %s_%s %s)", funcion, yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1421 "trad.tab.c"
    break;

  case 24: /* sentencia: IDENTIF '[' NUMBER ']' '=' expresion  */
#line 113 "trad.y"
                                                       { sprintf (temp, "(setf %s_(aref %s %d) %s)", funcion, yyvsp[-5].code, yyvsp[-3].value, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1428 "trad.tab.c"
    break;

  case 25: /* sentencia: IDENTIF '[' IDENTIF ']' '=' expresion  */
#line 115 "trad.y"
                                                    { sprintf (temp, "(setf %s_(aref %s %s) %s)", funcion, yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1435 "trad.tab.c"
    break;

  case 26: /* sentencia: PRINTF expresion  */
#line 117 "trad.y"
                                            { sprintf (temp, "(print %s)", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1442 "trad.tab.c"
    break;

  case 27: /* sentencia: PRINTF '(' expresion ',' expresiones ')'  */
#line 119 "trad.y"
                                                            { sprintf (temp, "(prin1 %s) %s", yyvsp[-3].code, yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1449 "trad.tab.c"
    break;

  case 28: /* sentencia: INTEGER definir  */
#line 121 "trad.y"
                                         { sprintf (temp, "(setq %s_%s)", funcion, yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1456 "trad.tab.c"
    break;

  case 29: /* sentencia: INTEGER definir ',' definiciones  */
#line 123 "trad.y"
                                                      { sprintf (temp, "(setq %s_%s) %s", funcion, yyvsp[-2].code, yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1463 "trad.tab.c"
    break;

  case 30: /* sentencia: PUTS '(' STRING ')'  */
#line 125 "trad.y"
                                         { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1470 "trad.tab.c"
    break;

  case 31: /* sentencia: llamar_funcion  */
#line 127 "trad.y"
                                      {yyval = yyvsp[0];}
#line 1476 "trad.tab.c"
    break;

  case 32: /* estructura: WHILE '(' condicional ')' '{' sentencias '}'  */
#line 131 "trad.y"
                                                             {sprintf(temp, "(loop while %s do %s)", yyvsp[-4].code, yyvsp[-1].code);
                                                             yyval.code = gen_code(temp);}
#line 1483 "trad.tab.c"
    break;

  case 33: /* estructura: IF '(' condicional ')' '{' sentencias_if '}'  */
#line 133 "trad.y"
                                                               {sprintf(temp, "(if %s %s)", yyvsp[-4].code, yyvsp[-1].code);
                                                             yyval.code = gen_code(temp);}
#line 1490 "trad.tab.c"
    break;

  case 34: /* estructura: IF '(' condicional ')' '{' sentencias_if '}' ELSE '{' sentencias_if '}'  */
#line 135 "trad.y"
                                                                                          {sprintf(temp, "(if %s %s %s)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            yyval.code = gen_code(temp);}
#line 1497 "trad.tab.c"
    break;

  case 35: /* estructura: FOR '(' inicializ ';' condicional ';' incdec ')' '{' sentencias_if '}'  */
#line 137 "trad.y"
                                                                                     { sprintf(temp, "%s (loop while %s do %s %s)", yyvsp[-8].code,
                                                                                                yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                                                                                yyval.code = gen_code (temp) ; }
#line 1505 "trad.tab.c"
    break;

  case 36: /* sentencias_if: sentencias  */
#line 142 "trad.y"
                              { sprintf (temp, "%s", yyvsp[0].code) ;
                                    yyval.code = gen_code (temp) ; }
#line 1512 "trad.tab.c"
    break;

  case 37: /* sentencias_if: sentencias ';' sentencias  */
#line 144 "trad.y"
                                             { sprintf (temp, "(progn %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                yyval.code = gen_code (temp) ; }
#line 1519 "trad.tab.c"
    break;

  case 38: /* inicializ: INTEGER IDENTIF  */
#line 148 "trad.y"
                               { sprintf (temp, "(setq %s_%s 0)", funcion, yyvsp[0].code) ;
                                    yyval.code = gen_code (temp) ; }
#line 1526 "trad.tab.c"
    break;

  case 39: /* inicializ: INTEGER IDENTIF '=' termino  */
#line 150 "trad.y"
                                                    { sprintf (temp, "(setq %s_%s %s)", funcion, yyvsp[-2].code, yyvsp[0].code) ;
                                                    yyval.code = gen_code (temp) ; }
#line 1533 "trad.tab.c"
    break;

  case 40: /* inicializ: IDENTIF '=' termino  */
#line 152 "trad.y"
                                                { sprintf (temp, "(setf %s_%s %s)", funcion, yyvsp[-2].code, yyvsp[0].code) ;
                                                yyval.code = gen_code (temp) ; }
#line 1540 "trad.tab.c"
    break;

  case 41: /* incdec: IDENTIF '=' IDENTIF '+' NUMBER  */
#line 156 "trad.y"
                                       { sprintf (temp, "(setf %s_%s (+ %s %d))", funcion, yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value) ;
                                            yyval.code = gen_code (temp) ; }
#line 1547 "trad.tab.c"
    break;

  case 42: /* incdec: IDENTIF '=' IDENTIF '-' NUMBER  */
#line 158 "trad.y"
                                             { sprintf (temp, "(setf %s_%s (- %s %d))", funcion, yyvsp[-4].code, yyvsp[-2].code,yyvsp[0].value) ;
                                            yyval.code = gen_code (temp) ; }
#line 1554 "trad.tab.c"
    break;

  case 43: /* definiciones: definir ',' definiciones  */
#line 162 "trad.y"
                                        { sprintf (temp, "(setq %s) %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1561 "trad.tab.c"
    break;

  case 44: /* definiciones: definir  */
#line 164 "trad.y"
                                         { sprintf (temp, "(setq %s)", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1568 "trad.tab.c"
    break;

  case 45: /* definir: IDENTIF '=' termino  */
#line 168 "trad.y"
                                         { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1575 "trad.tab.c"
    break;

  case 46: /* definir: IDENTIF  */
#line 170 "trad.y"
                                         { sprintf (temp, "%s 0", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1582 "trad.tab.c"
    break;

  case 47: /* definir: IDENTIF '[' NUMBER ']'  */
#line 172 "trad.y"
                                         { sprintf (temp, "%s (make-array %d)", yyvsp[-3].code, yyvsp[-1].value) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1589 "trad.tab.c"
    break;

  case 48: /* expresiones: expresion ',' expresiones  */
#line 176 "trad.y"
                                         { sprintf (temp, "(prin1 %s) %s", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1596 "trad.tab.c"
    break;

  case 49: /* expresiones: expresion  */
#line 178 "trad.y"
                                         { sprintf (temp, "(prin1 %s)", yyvsp[0].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1603 "trad.tab.c"
    break;

  case 50: /* nombre_funcion: IDENTIF  */
#line 182 "trad.y"
                                         { sprintf (temp, "%s", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; 
                                           sprintf (funcion, "%s", yyvsp[0].code); }
#line 1611 "trad.tab.c"
    break;

  case 51: /* nombre_main: MAIN  */
#line 187 "trad.y"
                                         { sprintf (temp, "%s", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; 
                                           sprintf (funcion, "%s", yyvsp[0].code); }
#line 1619 "trad.tab.c"
    break;

  case 52: /* expresion: termino  */
#line 193 "trad.y"
                                         { yyval = yyvsp[0] ; }
#line 1625 "trad.tab.c"
    break;

  case 53: /* expresion: expresion '+' expresion  */
#line 194 "trad.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1632 "trad.tab.c"
    break;

  case 54: /* expresion: expresion '-' expresion  */
#line 196 "trad.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1639 "trad.tab.c"
    break;

  case 55: /* expresion: expresion '*' expresion  */
#line 198 "trad.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1646 "trad.tab.c"
    break;

  case 56: /* expresion: expresion '/' expresion  */
#line 200 "trad.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1653 "trad.tab.c"
    break;

  case 57: /* expresion: STRING  */
#line 202 "trad.y"
                        {yyval.code = yyvsp[0].code;}
#line 1659 "trad.tab.c"
    break;

  case 58: /* expresion: llamar_funcion  */
#line 203 "trad.y"
                                        {yyval =yyvsp[0];}
#line 1665 "trad.tab.c"
    break;

  case 59: /* expresion: IDENTIF '[' IDENTIF ']'  */
#line 204 "trad.y"
                                          { sprintf (temp, "(setf %s_%s %s)", funcion, yyvsp[-3].code, yyvsp[-1].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1672 "trad.tab.c"
    break;

  case 60: /* llamar_funcion: IDENTIF '(' enter_parametros ')'  */
#line 209 "trad.y"
                                                     { sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                    yyval.code = gen_code (temp) ; }
#line 1679 "trad.tab.c"
    break;

  case 61: /* enter_parametros: termino ',' enter_parametros  */
#line 213 "trad.y"
                                                           { sprintf (temp, "%s, %s", yyvsp[-2].code, yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1686 "trad.tab.c"
    break;

  case 62: /* enter_parametros: termino  */
#line 215 "trad.y"
                                                           { sprintf (temp, "%s", yyvsp[0].code) ;
                                                            yyval.code = gen_code(temp);}
#line 1693 "trad.tab.c"
    break;

  case 63: /* condicional: expresion AND expresion  */
#line 219 "trad.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1700 "trad.tab.c"
    break;

  case 64: /* condicional: expresion OR expresion  */
#line 221 "trad.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1707 "trad.tab.c"
    break;

  case 65: /* condicional: expresion NEQ expresion  */
#line 223 "trad.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1714 "trad.tab.c"
    break;

  case 66: /* condicional: expresion EQ expresion  */
#line 225 "trad.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1721 "trad.tab.c"
    break;

  case 67: /* condicional: expresion '<' expresion  */
#line 227 "trad.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1728 "trad.tab.c"
    break;

  case 68: /* condicional: expresion LEQ expresion  */
#line 229 "trad.y"
                                         { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1735 "trad.tab.c"
    break;

  case 69: /* condicional: expresion '>' expresion  */
#line 231 "trad.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1742 "trad.tab.c"
    break;

  case 70: /* condicional: expresion GEQ expresion  */
#line 233 "trad.y"
                                         { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1749 "trad.tab.c"
    break;

  case 71: /* condicional: expresion '%' expresion  */
#line 235 "trad.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1756 "trad.tab.c"
    break;

  case 72: /* condicional: condicional AND expresion  */
#line 237 "trad.y"
                                            { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1763 "trad.tab.c"
    break;

  case 73: /* condicional: condicional OR expresion  */
#line 239 "trad.y"
                                          { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1770 "trad.tab.c"
    break;

  case 74: /* condicional: condicional NEQ expresion  */
#line 241 "trad.y"
                                           { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1777 "trad.tab.c"
    break;

  case 75: /* condicional: condicional EQ expresion  */
#line 243 "trad.y"
                                          { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1784 "trad.tab.c"
    break;

  case 76: /* condicional: condicional '<' expresion  */
#line 245 "trad.y"
                                           { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1791 "trad.tab.c"
    break;

  case 77: /* condicional: condicional LEQ expresion  */
#line 247 "trad.y"
                                           { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1798 "trad.tab.c"
    break;

  case 78: /* condicional: condicional '>' expresion  */
#line 249 "trad.y"
                                           { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1805 "trad.tab.c"
    break;

  case 79: /* condicional: condicional GEQ expresion  */
#line 251 "trad.y"
                                           { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1812 "trad.tab.c"
    break;

  case 80: /* condicional: condicional '%' expresion  */
#line 253 "trad.y"
                                           { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1819 "trad.tab.c"
    break;

  case 81: /* termino: operando  */
#line 257 "trad.y"
                                                   { yyval = yyvsp[0] ; }
#line 1825 "trad.tab.c"
    break;

  case 82: /* termino: '+' operando  */
#line 258 "trad.y"
                                                   { sprintf (temp, "(+ %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1832 "trad.tab.c"
    break;

  case 83: /* termino: '-' operando  */
#line 260 "trad.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1839 "trad.tab.c"
    break;

  case 84: /* operando: IDENTIF  */
#line 264 "trad.y"
                                         { sprintf (temp, "%s", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1846 "trad.tab.c"
    break;

  case 85: /* operando: NUMBER  */
#line 266 "trad.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 1853 "trad.tab.c"
    break;

  case 86: /* operando: '(' expresion ')'  */
#line 268 "trad.y"
                                         { yyval = yyvsp[-1] ; }
#line 1859 "trad.tab.c"
    break;

  case 87: /* operando: IDENTIF '[' NUMBER ']'  */
#line 269 "trad.y"
                                         { sprintf (temp, "(aref %s %d)", yyvsp[-3].code, yyvsp[-1].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 1866 "trad.tab.c"
    break;


#line 1870 "trad.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 274 "trad.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",	   PUTS,
    "printf",	   PRINTF,
    "while",	   WHILE,
    "if",      IF,
    "else",    ELSE,
    "for",     FOR,
    "return",  RETURN,
    "&&",	   AND,
    "||",	   OR,
    "!=",	   NEQ,
    "==",	   EQ,
    "<=",	   LEQ,
    ">=",	   GEQ,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=>|%/&+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
