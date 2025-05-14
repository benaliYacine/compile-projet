
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxique.y"

    #include <stdio.h>
    int nb_ligne=1, Col=1;
    char* file_name;
    #include "ts_HASH_TABLE.c"
    #include "int_pile.c"
    #include "str_pile.c"
    #include "expre_pile.c"
    #include "fct_etiq.c"
    #include "pgm.c"
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    
    StackNode_int *deb_else = NULL;
    StackNode_int *deb_for = NULL;
    int qc=0;
    StackNode_int *Fin_if = NULL;
    StackNode_int *Fin_for = NULL;
    StackNode_int *fin_routine = NULL;
    StackNode* Operandes_pile = NULL;
    char tmp[20];
    int nb_argument=0;
    extern char *type;
    char taille[20];


/* Line 189 of yacc.c  */
#line 101 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     idf = 258,
     eq = 259,
     mc_data = 260,
     mc_code = 261,
     mc_end = 262,
     mc_vector = 263,
     inti = 264,
     real = 265,
     mc_integer = 266,
     mc_float = 267,
     mc_char = 268,
     mc_string = 269,
     mc_const = 270,
     mc_read = 271,
     mc_display = 272,
     pvg = 273,
     str = 274,
     ch = 275,
     mc_if = 276,
     mc_else = 277,
     mc_for = 278,
     mc_not = 279,
     deux_points = 280,
     crochet_ouv = 281,
     crochet_ferm = 282,
     par_ouv = 283,
     par_ferm = 284,
     virgule = 285,
     barre = 286,
     arobase = 287,
     plus = 288,
     minus = 289,
     mul = 290,
     divi = 291,
     err = 292,
     mc_and = 293,
     mc_or = 294,
     mc_g = 295,
     mc_l = 296,
     mc_ge = 297,
     mc_le = 298,
     mc_eq = 299,
     mc_di = 300,
     mc_true = 301,
     mc_false = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "syntaxique.y"

    int entier;
    char* str;
    float reel;



/* Line 214 of yacc.c  */
#line 192 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "syntaxique.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    14,    15,    18,    20,    22,    24,
      29,    31,    35,    47,    54,    56,    58,    60,    62,    63,
      66,    68,    70,    72,    74,    76,    81,    83,    88,    97,
     105,   110,   116,   117,   118,   123,   127,   136,   138,   142,
     146,   150,   154,   158,   162,   166,   170,   172,   176,   180,
     182,   186,   190,   192,   196,   199,   201,   203,   205,   207,
     209,   211,   213
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,     5,    51,     7,     6,    58,     7,
       7,    -1,     3,    -1,    -1,    51,    52,    -1,    53,    -1,
      55,    -1,    56,    -1,    57,    25,    54,    18,    -1,    61,
      -1,    54,    31,    61,    -1,     8,    25,     3,    26,    71,
      30,    71,    25,    57,    27,    18,    -1,    15,    25,     3,
       4,    75,    18,    -1,    11,    -1,    12,    -1,    13,    -1,
      14,    -1,    -1,    58,    59,    -1,    60,    -1,    62,    -1,
      63,    -1,    64,    -1,    68,    -1,    61,     4,    71,    18,
      -1,     3,    -1,     3,    26,    71,    27,    -1,    16,    28,
      19,    25,    32,     3,    29,    18,    -1,    17,    28,    19,
      25,    71,    29,    18,    -1,    65,    58,    66,     7,    -1,
      21,    28,    70,    29,    25,    -1,    -1,    -1,    22,    25,
      67,    58,    -1,    69,    58,     7,    -1,    23,    28,     3,
      25,    71,    25,    70,    29,    -1,    71,    -1,    71,    39,
      72,    -1,    71,    38,    72,    -1,    71,    40,    72,    -1,
      71,    41,    72,    -1,    71,    42,    72,    -1,    71,    43,
      72,    -1,    71,    44,    72,    -1,    71,    45,    72,    -1,
      72,    -1,    72,    33,    73,    -1,    72,    34,    73,    -1,
      73,    -1,    73,    35,    74,    -1,    73,    36,    74,    -1,
      74,    -1,    28,    71,    29,    -1,    24,    74,    -1,    75,
      -1,    61,    -1,     9,    -1,    10,    -1,    20,    -1,    19,
      -1,    46,    -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    58,    66,    67,    70,    71,    72,    75,
      78,    79,    82,   112,   130,   131,   132,   133,   136,   137,
     140,   141,   142,   143,   144,   147,   180,   191,   221,   251,
     276,   283,   295,   300,   300,   311,   322,   351,   361,   382,
     403,   420,   437,   454,   471,   488,   505,   512,   532,   552,
     559,   579,   603,   610,   615,   633,   638,   645,   651,   657,
     661,   665,   669
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "idf", "eq", "mc_data", "mc_code",
  "mc_end", "mc_vector", "inti", "real", "mc_integer", "mc_float",
  "mc_char", "mc_string", "mc_const", "mc_read", "mc_display", "pvg",
  "str", "ch", "mc_if", "mc_else", "mc_for", "mc_not", "deux_points",
  "crochet_ouv", "crochet_ferm", "par_ouv", "par_ferm", "virgule", "barre",
  "arobase", "plus", "minus", "mul", "divi", "err", "mc_and", "mc_or",
  "mc_g", "mc_l", "mc_ge", "mc_le", "mc_eq", "mc_di", "mc_true",
  "mc_false", "$accept", "PROGRAM", "PROGRAM_NAME", "DECLARATIONS",
  "DECLARATION", "VARIABLE_DECLARATION", "LIST_VARIABLES",
  "VECTOR_DECLARATION", "CONSTANT_DECLARATION", "TYPE", "INSTRUCTIONS",
  "INSTRUCTION", "AFFECTATION", "VAR", "INPUT", "OUTPUT", "IF_STATEMENT",
  "IF_START", "ELSE_PART", "$@1", "FOR_STATEMENT", "FOR_START",
  "CONDITION", "EXPRESSION", "TERM", "FACTOR", "PRIMARY", "VALUE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      54,    54,    55,    56,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    60,    61,    61,    62,    63,
      64,    65,    66,    67,    66,    68,    69,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     0,     2,     1,     1,     1,     4,
       1,     3,    11,     6,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     4,     1,     4,     8,     7,
       4,     5,     0,     0,     4,     3,     8,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     4,     0,     0,     0,    14,
      15,    16,    17,     0,     5,     6,     7,     8,     0,    18,
       0,     0,     0,     0,     0,     0,    26,     0,    10,     0,
       0,     0,     0,     0,    19,    20,     0,    21,    22,    23,
      18,    24,    18,     0,     0,     0,     9,     0,     2,     0,
       0,     0,     0,     0,    32,     0,    57,    58,    60,    59,
       0,     0,    61,    62,    56,     0,    46,    49,    52,    55,
       0,     0,    11,     0,     0,     0,    37,     0,     0,     0,
       0,    35,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    27,     0,
       0,     0,     0,    25,    33,    30,    53,     0,    39,    38,
      40,    41,    42,    43,    44,    45,    47,    48,    50,    51,
       0,     0,    31,     0,    18,     0,     0,     0,     0,    34,
       0,     0,    29,     0,     0,    28,    36,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    14,    15,    27,    16,    17,    18,
      23,    34,    35,    64,    37,    38,    39,    40,    80,   124,
      41,    42,    75,    76,    66,    67,    68,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
      21,   -72,    28,    24,   -72,   -72,    76,    30,     5,   -72,
     -72,   -72,   -72,     9,   -72,   -72,   -72,   -72,    13,   -72,
      36,    37,    44,    97,    22,    45,    26,   -11,   -72,    52,
      53,    57,    73,    74,   -72,   -72,    78,   -72,   -72,   -72,
     -72,   -72,   -72,     7,    -1,     7,   -72,    44,   -72,    42,
      61,     7,   100,     7,    34,   105,   -72,   -72,   -72,   -72,
       7,     7,   -72,   -72,   -72,   137,   -19,   -24,   -72,   -72,
      87,    96,   -72,    81,    84,    86,   113,    85,    25,    91,
     110,   -72,   -72,   104,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   -72,   -72,    95,
       7,    94,     7,   -72,   -72,   -72,   -72,    33,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -24,   -24,   -72,   -72,
     127,   121,   -72,    54,   -72,   157,   103,   154,     7,   108,
     146,   156,   -72,   162,   174,   -72,   -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    68,
     -38,   -72,   -72,   -22,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    66,   -40,    98,   -71,   -54,   151
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      28,    36,    54,    65,    55,    71,    82,    46,    56,    57,
      26,    95,    96,    78,    93,    94,    56,    57,    58,    59,
      47,    83,   116,   117,     1,    72,    58,    59,     4,     5,
      20,    60,    36,    36,    21,    61,    19,    26,    22,    24,
      25,   118,   119,   103,   107,    62,    63,    26,    43,    44,
      30,    31,    45,    62,    63,    32,    79,    33,   125,    48,
     121,    73,   123,    85,    86,    87,    88,    89,    90,    91,
      92,    85,    86,    87,    88,    89,    90,    91,    92,   128,
      74,    49,    53,     7,     8,    50,   129,     9,    10,    11,
      12,    13,    85,    86,    87,    88,    89,    90,    91,    92,
      26,    51,    52,    77,    29,    97,    99,    36,    26,   100,
     102,    26,    81,    30,    31,   101,   104,   105,    32,   122,
      33,    30,    31,    98,    30,    31,    32,   120,    33,    32,
     126,    33,   131,   106,    85,    86,    87,    88,    89,    90,
      91,    92,    85,    86,    87,    88,    89,    90,    91,    92,
     127,    85,    86,    87,    88,    89,    90,    91,    92,    85,
      86,    87,    88,    89,    90,    91,    92,    84,     9,    10,
      11,    12,   132,   134,   135,    85,    86,    87,    88,    89,
      90,    91,    92,   108,   109,   110,   111,   112,   113,   114,
     115,   136,   137,   130,   133,    70
};

static const yytype_uint8 yycheck[] =
{
      22,    23,    40,    43,    42,    45,    60,    18,     9,    10,
       3,    35,    36,    53,    33,    34,     9,    10,    19,    20,
      31,    61,    93,    94,     3,    47,    19,    20,     0,     5,
      25,    24,    54,    55,    25,    28,     6,     3,    25,     3,
       3,    95,    96,    18,    84,    46,    47,     3,    26,     4,
      16,    17,    26,    46,    47,    21,    22,    23,    25,     7,
     100,    19,   102,    38,    39,    40,    41,    42,    43,    44,
      45,    38,    39,    40,    41,    42,    43,    44,    45,    25,
      19,    28,     4,     7,     8,    28,   124,    11,    12,    13,
      14,    15,    38,    39,    40,    41,    42,    43,    44,    45,
       3,    28,    28,     3,     7,    18,    25,   129,     3,    25,
      25,     3,     7,    16,    17,    29,    25,     7,    21,    25,
      23,    16,    17,    27,    16,    17,    21,    32,    23,    21,
       3,    23,    29,    29,    38,    39,    40,    41,    42,    43,
      44,    45,    38,    39,    40,    41,    42,    43,    44,    45,
      29,    38,    39,    40,    41,    42,    43,    44,    45,    38,
      39,    40,    41,    42,    43,    44,    45,    30,    11,    12,
      13,    14,    18,    27,    18,    38,    39,    40,    41,    42,
      43,    44,    45,    85,    86,    87,    88,    89,    90,    91,
      92,    29,    18,   125,   128,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    50,     0,     5,    51,     7,     8,    11,
      12,    13,    14,    15,    52,    53,    55,    56,    57,     6,
      25,    25,    25,    58,     3,     3,     3,    54,    61,     7,
      16,    17,    21,    23,    59,    60,    61,    62,    63,    64,
      65,    68,    69,    26,     4,    26,    18,    31,     7,    28,
      28,    28,    28,     4,    58,    58,     9,    10,    19,    20,
      24,    28,    46,    47,    61,    71,    72,    73,    74,    75,
      75,    71,    61,    19,    19,    70,    71,     3,    71,    22,
      66,     7,    74,    71,    30,    38,    39,    40,    41,    42,
      43,    44,    45,    33,    34,    35,    36,    18,    27,    25,
      25,    29,    25,    18,    25,     7,    29,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      32,    71,    25,    71,    67,    25,     3,    29,    25,    58,
      57,    29,    18,    70,    27,    18,    29,    18
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 55 "syntaxique.y"
    { printf("Programme syntaxiquement correct!\n"); YYACCEPT; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 58 "syntaxique.y"
    {
    if(Declarer((yyvsp[(1) - (1)].str))){
        yyerror("Semantic error", (yyvsp[(1) - (1)].str), "already declared");
    }
    rechercher((yyvsp[(1) - (1)].str), "PROGRAM", " ", " ", 0, " ", 0);
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 82 "syntaxique.y"
    {
    if(Declarer((yyvsp[(3) - (11)].str))){
        yyerror("Semantic error", (yyvsp[(3) - (11)].str), "already declared");
    }
    
    // Verify array bounds
    if(!isInteger((yyvsp[(5) - (11)].str)) || !isInteger((yyvsp[(7) - (11)].str))){
        yyerror("Semantic error", "", "array bounds must be integers");
    }
    
    // Create array size string for table
    char arraySize[50];
    sprintf(arraySize, "%s,%s", (yyvsp[(5) - (11)].str), (yyvsp[(7) - (11)].str));
    
    // Add to symbol table as TABLEAU
    rechercher((yyvsp[(3) - (11)].str), "IDF", (yyvsp[(9) - (11)].str), "", 0, arraySize, 0);
    
    // Initialize array
    initiali_tab((yyvsp[(3) - (11)].str), arraySize);
    
    // Generate quadruples for array bounds
    StackNode* operande_high = pop(&Operandes_pile);
    StackNode* operande_low = pop(&Operandes_pile);
    
    quadr("Bounds", "0", strdup(operande_low->operande_name), "vide");
    quadr("Bounds", "0", strdup(operande_high->operande_name), "vide");
    quadr("ADEC", (yyvsp[(3) - (11)].str), "vide", "vide");
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 112 "syntaxique.y"
    {
    if(Declarer((yyvsp[(3) - (6)].str))){
        yyerror("Semantic error", (yyvsp[(3) - (6)].str), "already declared");
    }
    
    // Mark as constant in symbol table
    char constType[30];
    sprintf(constType, "CONST_%s", GetTypeFromVal((yyvsp[(5) - (6)].str)));
    
    // Set value directly in symbol table
    rechercher((yyvsp[(3) - (6)].str), "IDF", constType, (yyvsp[(5) - (6)].str), 0, "", 0);
    
    // Generate quadruple for constant initialization
    StackNode* poppedElement = pop(&Operandes_pile);
    quadr("=", poppedElement->operande_name, "vide", (yyvsp[(3) - (6)].str));
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 130 "syntaxique.y"
    { (yyval.str) = strdup("INTEGER"); strcpy(type, "INTEGER"); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 131 "syntaxique.y"
    { (yyval.str) = strdup("FLOAT"); strcpy(type, "FLOAT"); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 132 "syntaxique.y"
    { (yyval.str) = strdup("CHAR"); strcpy(type, "CHAR"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 133 "syntaxique.y"
    { (yyval.str) = strdup("STRING"); strcpy(type, "STRING"); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 147 "syntaxique.y"
    {
    // Check if variable is declared
    if(!Declarer((yyvsp[(1) - (4)].str))){
        yyerror("Semantic error", (yyvsp[(1) - (4)].str), "not declared");
    }
    
    // Check if it's a constant - cannot reassign
    if(strstr(GetTypeFromTS((yyvsp[(1) - (4)].str)), "CONST_") != NULL){
        yyerror("Semantic error", (yyvsp[(1) - (4)].str), "is a constant and cannot be reassigned");
    }
    
    // Check type compatibility
    if(!areCompatible(GetTypeFromTS((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].str))){
        yyerror("Semantic error", "", "incompatible types in assignment");
    }
    
    // Handle array assignment or regular variable assignment
    if(strstr(GetTypeFromTS((yyvsp[(1) - (4)].str)), "TABLEAU") != NULL){
        A_M_tab((yyvsp[(1) - (4)].str), taille, (yyvsp[(3) - (4)].str));
    } else {
        if(!SetValInTS((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str))){
            yyerror("Semantic error", (yyvsp[(1) - (4)].str), "assignment not accepted");
        }
    }
    
    // Generate quadruple for assignment
    StackNode* operande_expr = pop(&Operandes_pile);
    StackNode* operande_var = pop(&Operandes_pile);
    
    quadr("=", operande_expr->operande_name, "vide", operande_var->operande_name);
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 180 "syntaxique.y"
    {
    if(!Declarer((yyvsp[(1) - (1)].str))){
        yyerror("Semantic error", (yyvsp[(1) - (1)].str), "not declared");
    }
    
    // Push identifier to operand stack
    char *type = strdup(GetTypeFromTS((yyvsp[(1) - (1)].str)));
    push(&Operandes_pile, "VAR", strdup((yyvsp[(1) - (1)].str)), type);
    
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 191 "syntaxique.y"
    {
    if(!Declarer((yyvsp[(1) - (4)].str))){
        yyerror("Semantic error", (yyvsp[(1) - (4)].str), "not declared");
    }
    
    // Check if it's an array
    if(strstr(GetTypeFromTS((yyvsp[(1) - (4)].str)), "TABLEAU") == NULL){
        yyerror("Semantic error", (yyvsp[(1) - (4)].str), "is not an array");
    }
    
    // Check if index is an integer
    if(!isInteger((yyvsp[(3) - (4)].str))){
        yyerror("Semantic error", "", "array index must be an integer");
    }
    
    // Create indexed var representation
    char indexed_var[100];
    StackNode* operande_index = pop(&Operandes_pile);
    sprintf(indexed_var, "%s[%s]", (yyvsp[(1) - (4)].str), operande_index->operande_name);
    
    // Push to operand stack
    push(&Operandes_pile, "VAR", indexed_var, GetTypeFromTS((yyvsp[(1) - (4)].str)));
    
    // Store array index for potential use in quadruple generation
    strcpy(taille, (yyvsp[(3) - (4)].str));
    
    (yyval.str) = (yyvsp[(1) - (4)].str);
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 221 "syntaxique.y"
    {
    if(!Declarer((yyvsp[(6) - (8)].str))){
        yyerror("Semantic error", (yyvsp[(6) - (8)].str), "not declared");
    }
    
    // Get type of variable for compatibility check with format string
    char* varType = GetTypeFromTS((yyvsp[(6) - (8)].str));
    char* formatType = NULL;
    
    // Extract format from string literal (remove quotes)
    char* format = strdup((yyvsp[(3) - (8)].str));
    format++; // Skip opening quote
    format[strlen(format)-1] = '\0'; // Remove closing quote
    
    // Check format compatibility with variable type
    if(strcmp(format, "$") == 0) formatType = "INTEGER";
    else if(strcmp(format, "%") == 0) formatType = "FLOAT";
    else if(strcmp(format, "#") == 0) formatType = "STRING";
    else if(strcmp(format, "&") == 0) formatType = "CHAR";
    else yyerror("Semantic error", format, "invalid format specifier");
    
    if(strstr(varType, formatType) == NULL){
        yyerror("Semantic error", "", "format specifier doesn't match variable type");
    }
    
    // Generate quadruple for input
    quadr("READ", format, "vide", (yyvsp[(6) - (8)].str));
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 251 "syntaxique.y"
    {
    // Extract format from string literal (remove quotes)
    char* format = strdup((yyvsp[(3) - (7)].str));
    format++; // Skip opening quote
    format[strlen(format)-1] = '\0'; // Remove closing quote
    
    // Determine expected type from format
    char* formatType = NULL;
    if(strstr(format, "$") != NULL) formatType = "INTEGER";
    else if(strstr(format, "%") != NULL) formatType = "FLOAT";
    else if(strstr(format, "#") != NULL) formatType = "STRING";
    else if(strstr(format, "&") != NULL) formatType = "CHAR";
    
    // Generate quadruple for output
    StackNode* operande_expr = pop(&Operandes_pile);
    
    // Check type compatibility with format
    if(formatType != NULL && !areCompatible(formatType, operande_expr->operande_type)){
        yyerror("Semantic error", "", "expression type doesn't match format specifier");
    }
    
    quadr("DISPLAY", format, operande_expr->operande_name, "vide");
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 276 "syntaxique.y"
    {
    // Complete IF statement - set jump destination for the end of IF
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_if), 1, tmp);
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 283 "syntaxique.y"
    {
    // Start of IF - create conditional jump
    StackNode* operande_cond = pop(&Operandes_pile);
    
    // Save current quadruple position for the conditional jump
    push_int(&deb_else, qc);
    
    // Generate BZ (branch if zero/false) quadruple
    quadr("BZ", "", strdup(operande_cond->operande_name), "vide");
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 295 "syntaxique.y"
    {
    // No ELSE part - just set the branch target to current position
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&deb_else), 1, tmp);
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 300 "syntaxique.y"
    {
    // ELSE part exists - generate unconditional jump to skip ELSE when IF is taken
    push_int(&Fin_if, qc);
    quadr("BR", "", "vide", "vide");
    
    // Set the target for the conditional jump at the beginning of ELSE
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&deb_else), 1, tmp);
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 311 "syntaxique.y"
    {
    // End of FOR loop - create back jump to condition check
    sprintf(tmp, "%d", pop_int(&deb_for));
    quadr("BR", tmp, "vide", "vide");
    
    // Set jump destination for loop exit
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_for), 1, tmp);
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 322 "syntaxique.y"
    {
    // Initialize loop counter
    if(!Declarer((yyvsp[(3) - (8)].str))){
        yyerror("Semantic error", (yyvsp[(3) - (8)].str), "not declared");
    }
    
    if(!isInteger((yyvsp[(5) - (8)].str))){
        yyerror("Semantic error", "", "loop step must be an integer");
    }
    
    // Initialize loop counter with the initial value
    StackNode* operande_step = pop(&Operandes_pile);
    quadr("=", operande_step->operande_name, "vide", (yyvsp[(3) - (8)].str));
    
    // Save current position for loop condition check
    push_int(&deb_for, qc);
    
    // Evaluate loop condition
    StackNode* operande_cond = pop(&Operandes_pile);
    
    // Generate conditional jump to exit loop if condition is false
    push_int(&Fin_for, qc);
    quadr("BZ", "", strdup(operande_cond->operande_name), "vide");
    
    // Increment loop counter at the end of each iteration
    // Will be done in quadruple generation at the end of the loop
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 351 "syntaxique.y"
    {
    // Check if expression is boolean or can be converted to boolean
    if(!isBoolean((yyvsp[(1) - (1)].str)) && !canBeBoolean((yyvsp[(1) - (1)].str))){
        yyerror("Semantic error", (yyvsp[(1) - (1)].str), "not a boolean expression");
    }
    
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 361 "syntaxique.y"
    {
    if(!isBoolean((yyvsp[(1) - (3)].str)) || !isBoolean((yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "OR operator requires boolean operands");
    }
    
    // Generate quadruples for logical OR
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadLogic(2, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    bool val1 = strcmp((yyvsp[(1) - (3)].str), "true") == 0;
    bool val2 = strcmp((yyvsp[(3) - (3)].str), "true") == 0;
    bool result = val1 || val2;
    
    (yyval.str) = result ? strdup("true") : strdup("false");
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 382 "syntaxique.y"
    {
    if(!isBoolean((yyvsp[(1) - (3)].str)) || !isBoolean((yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "AND operator requires boolean operands");
    }
    
    // Generate quadruples for logical AND
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadLogic(3, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    bool val1 = strcmp((yyvsp[(1) - (3)].str), "true") == 0;
    bool val2 = strcmp((yyvsp[(3) - (3)].str), "true") == 0;
    bool result = val1 && val2;
    
    (yyval.str) = result ? strdup("true") : strdup("false");
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 403 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for greater than comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(6, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(gtEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 420 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for less than comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(5, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(ltEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 437 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for greater than or equal comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(3, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(geEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 454 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for less than or equal comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(4, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(leEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 471 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for equality comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(1, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(eqEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 488 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for comparison");
    }
    
    // Generate quadruples for inequality comparison
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    push(&Operandes_pile, "EXPRESSION", res_tmp, "LOGICAL");
    
    createQuadCompare(2, operande_left->operande_name, operande_right->operande_name, res_tmp);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(neEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 505 "syntaxique.y"
    {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "EXPRESSION", poppedElement->operande_name, poppedElement->operande_type);
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 512 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for addition");
    }
    
    // Generate quadruples for addition
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("+", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "TERM", T, type);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(addEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 532 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for subtraction");
    }
    
    // Generate quadruples for subtraction
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("-", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "TERM", T, type);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(subEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 552 "syntaxique.y"
    {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "TERM", poppedElement->operande_name, poppedElement->operande_type);
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 559 "syntaxique.y"
    {
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for multiplication");
    }
    
    // Generate quadruples for multiplication
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("*", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "FACTOR", T, type);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(mulEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 579 "syntaxique.y"
    {
    if(isEntityZero((yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "division by zero");
    }
    
    if(!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))){
        yyerror("Semantic error", "", "incompatible types for division");
    }
    
    // Generate quadruples for division
    StackNode* operande_right = pop(&Operandes_pile);
    StackNode* operande_left = pop(&Operandes_pile);
    
    char* T = strdup(Cree_temp());
    
    quadr("/", operande_left->operande_name, operande_right->operande_name, T);
    
    char* type = strdup(Calculer_type(operande_left->operande_type, operande_right->operande_type));
    
    push(&Operandes_pile, "FACTOR", T, type);
    
    // Compute result for semantic analysis
    (yyval.str) = strdup(divEntities((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 603 "syntaxique.y"
    {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 610 "syntaxique.y"
    {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "PRIMARY", poppedElement->operande_name, poppedElement->operande_type);
    (yyval.str) = (yyvsp[(2) - (3)].str);
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 615 "syntaxique.y"
    {
    if(!isBoolean((yyvsp[(2) - (2)].str)) && !canBeBoolean((yyvsp[(2) - (2)].str))){
        yyerror("Semantic error", "", "NOT operator requires boolean operand");
    }
    
    // Generate quadruple for logical NOT
    StackNode* operande = pop(&Operandes_pile);
    
    char* res_tmp = strdup(Cree_temp_cond());
    
    quadr("NOT", operande->operande_name, "vide", res_tmp);
    
    push(&Operandes_pile, "PRIMARY", res_tmp, "LOGICAL");
    
    // Compute result for semantic analysis
    bool val = strcmp((yyvsp[(2) - (2)].str), "true") == 0;
    (yyval.str) = !val ? strdup("true") : strdup("false");
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 633 "syntaxique.y"
    {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "PRIMARY", poppedElement->operande_name, poppedElement->operande_type);
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 638 "syntaxique.y"
    {
    StackNode* poppedElement = pop(&Operandes_pile);
    push(&Operandes_pile, "PRIMARY", poppedElement->operande_name, poppedElement->operande_type);
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 645 "syntaxique.y"
    {
    char backToStr[20];
    sprintf(backToStr, "%d", (yyvsp[(1) - (1)].entier));
    push(&Operandes_pile, "VALUE", strdup(backToStr), "INTEGER");
    (yyval.str) = strdup(backToStr);
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 651 "syntaxique.y"
    {
    char backToStr[20];
    sprintf(backToStr, "%g", (yyvsp[(1) - (1)].reel));
    push(&Operandes_pile, "VALUE", strdup(backToStr), "FLOAT");
    (yyval.str) = strdup(backToStr);
;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 657 "syntaxique.y"
    {
    push(&Operandes_pile, "VALUE", (yyvsp[(1) - (1)].str), "CHAR");
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 661 "syntaxique.y"
    {
    push(&Operandes_pile, "VALUE", (yyvsp[(1) - (1)].str), "STRING");
    (yyval.str) = (yyvsp[(1) - (1)].str);
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 665 "syntaxique.y"
    {
    push(&Operandes_pile, "VALUE", "true", "LOGICAL");
    (yyval.str) = strdup("true");
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 669 "syntaxique.y"
    {
    push(&Operandes_pile, "VALUE", "false", "LOGICAL");
    (yyval.str) = strdup("false");
;}
    break;



/* Line 1455 of yacc.c  */
#line 2350 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 675 "syntaxique.y"


int main(int argc, char** argv)
{
    if (argc > 1) {
        file_name = argv[1];
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            perror("Cannot open input file");
            return EXIT_FAILURE;
        }
        yyin = file;
    }
    
    yyparse(); // Launch syntactic analyzer
    yylex();   // Launch lexical analyzer
    
    printf("Analyse lexicale et syntaxique terminee avec succes.\n");
    printf("Affichage de la table des symboles.\n");
    afficher();
    printf("Affichage des quadruplets.\n");
    afficher_qdr();
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    printf("Affichage de la pile.\n");
    afficher_pile(Operandes_pile);
    
    return 0;
}

yywrap()
{}

int yyerror(char* msg, char* entite, char* description)
{
    printf("File \"%s\", line %d, character %d: %s, %s %s\n", file_name, nb_ligne, Col, msg, entite, description);
    
    printf("Affichage de la table des symboles.\n");
    afficher();
    printf("Affichage des quadruplets.\n");
    afficher_qdr();
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    printf("Affichage de la pile.\n");
    afficher_pile(Operandes_pile);
    
    exit(EXIT_FAILURE);
} 
