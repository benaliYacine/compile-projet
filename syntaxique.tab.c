
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
    #include "expre_pile.c"
    #include "pgm_optimized.c"
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    // int deb_else=0;
     StackNode_int *deb_else = NULL;
     StackNode_int *deb_while = NULL;
    int qc=0;
    // int Fin_if=0;
     StackNode_int *Fin_if = NULL;
     StackNode_int *Fin_while = NULL;
     StackNode_int *fin_routine = NULL;
     StackNode* Operandes_pile = NULL;
    char tmp [20];
    int nb_argument=0;
    extern char *type;
    char taille[20];
    StackNode_int *deb_for = NULL;
    StackNode_int *Fin_for = NULL;



/* Line 189 of yacc.c  */
#line 103 "syntaxique.tab.c"

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
     str = 259,
     character = 260,
     inti = 261,
     real = 262,
     mc_logi = 263,
     mc_data = 264,
     mc_end = 265,
     mc_code = 266,
     mc_integer = 267,
     verg = 268,
     mc_float = 269,
     mc_char = 270,
     mc_string = 271,
     mc_const = 272,
     mc_vector = 273,
     mc_read = 274,
     mc_display = 275,
     mc_if = 276,
     mc_else = 277,
     mc_for = 278,
     mc_not = 279,
     mc_true = 280,
     mc_false = 281,
     mc_and = 282,
     mc_or = 283,
     mc_g = 284,
     mc_l = 285,
     mc_ge = 286,
     mc_le = 287,
     mc_eq = 288,
     mc_di = 289,
     add = 290,
     sub = 291,
     mul = 292,
     divi = 293,
     aff = 294,
     mc_dowhile = 295,
     mc_enddo = 296,
     pvg = 297,
     deux_points = 298,
     crochet_ouv = 299,
     crochet_ferm = 300,
     po = 301,
     pf = 302,
     virg = 303,
     barre = 304,
     arobase = 305,
     err = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 214 of yacc.c  */
#line 198 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 210 "syntaxique.tab.c"

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
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    13,    15,    17,    19,    21,    23,
      25,    27,    30,    32,    37,    43,    53,    56,    58,    63,
      66,    70,    74,    76,    80,    84,    88,    92,    96,   100,
     102,   106,   110,   112,   116,   120,   122,   126,   128,   131,
     133,   135,   137,   139,   144,   148,   150,   152,   154,   156,
     158,   161,   163,   165,   167,   169,   171,   173,   175,   177,
     182,   186,   190,   195,   199,   201,   206,   208,   210,   212,
     221,   229,   235,   239,   244,   246,   248,   252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,     3,     9,    56,    10,    11,    69,    10,
      10,    -1,    -1,    12,    -1,    14,    -1,    15,    -1,     8,
      -1,    16,    -1,    54,    -1,    57,    -1,    57,    58,    -1,
      58,    -1,    55,    43,    60,    42,    -1,    17,    43,     3,
      59,    42,    -1,    18,    43,     3,    44,    67,    43,    55,
      45,    42,    -1,    39,    78,    -1,    54,    -1,    60,    49,
       3,    59,    -1,     3,    59,    -1,    61,    28,    62,    -1,
      61,    27,    62,    -1,    62,    -1,    62,    30,    63,    -1,
      62,    29,    63,    -1,    62,    31,    63,    -1,    62,    33,
      63,    -1,    62,    34,    63,    -1,    62,    32,    63,    -1,
      63,    -1,    63,    35,    64,    -1,    63,    36,    64,    -1,
      64,    -1,    64,    37,    65,    -1,    64,    38,    65,    -1,
      65,    -1,    46,    61,    47,    -1,    66,    -1,    24,    65,
      -1,     3,    -1,    68,    -1,     6,    -1,     7,    -1,     3,
      44,    67,    45,    -1,    67,    13,    78,    -1,    78,    -1,
      25,    -1,    26,    -1,    54,    -1,    70,    -1,    70,    71,
      -1,    71,    -1,    73,    -1,    79,    -1,    80,    -1,    81,
      -1,    77,    -1,    85,    -1,     3,    -1,     3,    46,    67,
      47,    -1,    74,    76,    10,    -1,    75,    43,    69,    -1,
      21,    46,    84,    47,    -1,    22,    43,    69,    -1,    54,
      -1,    72,    39,    78,    42,    -1,     4,    -1,     5,    -1,
      61,    -1,    19,    46,     4,    43,    50,    72,    47,    42,
      -1,    20,    46,     4,    43,    72,    47,    42,    -1,    20,
      46,     4,    47,    42,    -1,    82,    69,    41,    -1,    83,
      46,    84,    47,    -1,    40,    -1,    61,    -1,    86,    69,
      10,    -1,    23,    46,     3,    43,    78,    43,    84,    47,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    67,    69,    69,    69,    69,    69,    71,
      71,    73,    73,    76,    77,    87,   107,   107,   110,   130,
     156,   176,   196,   203,   217,   231,   246,   262,   277,   292,
     299,   323,   344,   351,   372,   399,   407,   412,   418,   435,
     449,   454,   462,   468,   508,   522,   533,   534,   536,   536,
     538,   538,   540,   540,   540,   540,   540,   540,   543,   551,
     592,   598,   606,   613,   613,   616,   642,   646,   650,   656,
     697,   765,   770,   777,   783,   788,   797,   808
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "idf", "str", "character", "inti",
  "real", "mc_logi", "mc_data", "mc_end", "mc_code", "mc_integer", "verg",
  "mc_float", "mc_char", "mc_string", "mc_const", "mc_vector", "mc_read",
  "mc_display", "mc_if", "mc_else", "mc_for", "mc_not", "mc_true",
  "mc_false", "mc_and", "mc_or", "mc_g", "mc_l", "mc_ge", "mc_le", "mc_eq",
  "mc_di", "add", "sub", "mul", "divi", "aff", "mc_dowhile", "mc_enddo",
  "pvg", "deux_points", "crochet_ouv", "crochet_ferm", "po", "pf", "virg",
  "barre", "arobase", "err", "$accept", "s", "VIDE", "TYPE", "DECS",
  "ENSDEC", "DEC", "partie_gauch_affectation", "ENSIDF_dec", "EXPRE",
  "CONDIT", "EXPREt", "TERM", "FACTOR", "OPERAND", "TAILLE", "LOGI",
  "INSTS", "ENSINST", "INST", "var", "if_statement", "B_if", "A_if",
  "else_clause", "assignment", "valeur", "read_statement",
  "write_statement", "dowhile_statement", "B_while", "A_while", "CONDI",
  "for_statement", "A_for", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    74,    75,    76,    76,    77,    78,    78,    78,    79,
      80,    80,    81,    82,    83,    84,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     4,     5,     9,     2,     1,     4,     2,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     3,     4,     3,     1,     4,     1,     1,     1,     8,
       7,     5,     3,     4,     1,     1,     3,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     7,     4,     5,     6,     8,
       0,     0,     9,     0,     0,    10,    12,     0,     0,     0,
       0,    11,     3,     0,     3,     0,     3,     0,    17,     0,
       0,    19,    13,     0,    58,     0,     0,     0,     0,    74,
      48,     0,    49,    51,     0,    52,     3,     0,    56,    53,
      54,    55,     3,     0,    57,     3,    39,    66,    67,    41,
      42,     0,    46,    47,     0,    68,    22,    29,    32,    35,
      37,    40,    16,    14,     0,    45,     3,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    64,     0,     3,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    75,     0,     0,     2,     0,     3,    60,
      61,    72,     0,    76,     0,    36,    21,    20,    24,    23,
      25,    28,    26,    27,    30,    31,    33,    34,    44,     0,
      59,     0,     0,     0,    62,     0,    65,    63,    73,    43,
       0,     0,     0,    71,     0,    15,     0,     0,     0,     0,
      70,     0,    69,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    40,    13,    14,    15,    16,    29,    25,    65,
      66,    67,    68,    69,    70,    74,    71,    41,    42,    43,
      44,    45,    46,    47,    87,    48,    75,    49,    50,    51,
      52,    53,   114,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
      21,    27,    48,    69,  -111,  -111,  -111,  -111,  -111,  -111,
      19,    26,  -111,    31,    46,    69,  -111,    73,    79,    91,
      93,  -111,    68,    64,    68,   -14,    23,     5,  -111,    67,
       5,  -111,  -111,   107,    65,    66,    70,    71,    74,  -111,
    -111,   103,    23,  -111,    75,  -111,    97,    72,  -111,  -111,
    -111,  -111,    23,    76,  -111,    23,    77,  -111,  -111,  -111,
    -111,    13,  -111,  -111,    13,    25,    59,    37,    41,  -111,
    -111,  -111,  -111,  -111,    12,  -111,    68,     5,   119,   120,
      13,   122,   116,  -111,     5,    84,  -111,   118,    23,    88,
      13,   121,     5,  -111,   -13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,     5,    52,  -111,
       0,    87,    18,    25,    85,    90,  -111,    92,    23,  -111,
    -111,  -111,    89,  -111,     9,  -111,    59,    59,    37,    37,
      37,    37,    37,    37,    41,    41,  -111,  -111,  -111,    94,
    -111,    95,   132,    96,  -111,     5,  -111,  -111,  -111,  -111,
      98,   132,    99,  -111,   100,  -111,   101,   102,    13,   105,
    -111,   104,  -111,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,    -1,    29,  -111,  -111,   126,   -18,  -111,   -63,
      10,     1,    -7,   -56,  -111,   -59,  -111,   -48,  -111,   108,
    -110,  -111,  -111,  -111,  -111,  -111,   -27,  -111,  -111,  -111,
    -111,  -111,   -87,  -111,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      72,    94,    12,   122,    89,    93,    31,    91,    56,    57,
      58,    59,    60,   107,    95,    96,    56,   113,   110,    59,
      60,    28,   107,    28,     1,   107,    34,   113,    32,    61,
      62,    63,   152,   124,   125,    33,     3,    61,    62,    63,
     120,   156,    35,    36,    37,    86,    38,   140,     4,   136,
     137,    64,    95,    96,   149,   108,    20,   117,   109,    64,
       5,   142,    17,    39,     6,   143,     7,     8,     9,    18,
     147,   161,   103,   104,    19,    28,    22,     5,   105,   106,
     138,     6,    23,     7,     8,     9,    10,    11,    97,    98,
      99,   100,   101,   102,    24,   113,   134,   135,   128,   129,
     130,   131,   132,   133,    26,   126,   127,    27,    30,    73,
      76,    77,    78,    82,    84,    88,    79,    80,   154,    85,
      81,    92,    90,   111,   112,   115,   116,   118,   119,   121,
     141,   123,   144,   145,   146,    34,   148,   139,   153,   150,
     155,    21,     0,   158,   160,   151,   157,   162,   159,     0,
      83,   163
};

static const yytype_int16 yycheck[] =
{
      27,    64,     3,    90,    52,    61,    24,    55,     3,     4,
       5,     6,     7,    13,    27,    28,     3,    80,    77,     6,
       7,    22,    13,    24,     3,    13,     3,    90,    42,    24,
      25,    26,   142,    92,    47,    49,     9,    24,    25,    26,
      88,   151,    19,    20,    21,    46,    23,    47,     0,   105,
     106,    46,    27,    28,    45,    43,    10,    84,    76,    46,
       8,    43,    43,    40,    12,    47,    14,    15,    16,    43,
     118,   158,    35,    36,    43,    76,     3,     8,    37,    38,
     107,    12,     3,    14,    15,    16,    17,    18,    29,    30,
      31,    32,    33,    34,     3,   158,   103,   104,    97,    98,
      99,   100,   101,   102,    11,    95,    96,    39,    44,    42,
       3,    46,    46,    10,    39,    43,    46,    46,   145,    22,
      46,    44,    46,     4,     4,     3,    10,    43,    10,    41,
      43,    10,    47,    43,    42,     3,    47,   108,    42,    45,
      42,    15,    -1,    43,    42,    50,    47,    42,    47,    -1,
      42,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,     9,     0,     8,    12,    14,    15,    16,
      17,    18,    54,    55,    56,    57,    58,    43,    43,    43,
      10,    58,     3,     3,     3,    60,    11,    39,    54,    59,
      44,    59,    42,    49,     3,    19,    20,    21,    23,    40,
      54,    69,    70,    71,    72,    73,    74,    75,    77,    79,
      80,    81,    82,    83,    85,    86,     3,     4,     5,     6,
       7,    24,    25,    26,    46,    61,    62,    63,    64,    65,
      66,    68,    78,    42,    67,    78,     3,    46,    46,    46,
      46,    46,    10,    71,    39,    22,    54,    76,    43,    69,
      46,    69,    44,    65,    61,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    13,    43,    59,
      67,     4,     4,    61,    84,     3,    10,    78,    43,    10,
      69,    41,    84,    10,    67,    47,    62,    62,    63,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    78,    55,
      47,    43,    43,    47,    47,    43,    42,    69,    47,    45,
      45,    50,    72,    42,    78,    42,    72,    47,    43,    47,
      42,    84,    42,    47
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
#line 65 "syntaxique.y"
    {YYACCEPT;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 77 "syntaxique.y"
    {
    if(Declarer((yyvsp[(3) - (5)].str))){
        yyerror("Sementique error",(yyvsp[(3) - (5)].str),"est deja declare.");
    }

    StackNode* poppedElement = pop(&Operandes_pile);
    quadr("=", poppedElement->operande_name,"vide", (yyvsp[(3) - (5)].str));

    rechercher((yyvsp[(3) - (5)].str),"IDF"," ",(yyvsp[(4) - (5)].str),0," ",0);
            ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 87 "syntaxique.y"
    {
        if(Declarer((yyvsp[(3) - (9)].str))){
            yyerror("Sementique error",(yyvsp[(3) - (9)].str),"est deja declare.");}
            rechercher((yyvsp[(3) - (9)].str),"IDF","TABLEAU",0,0,(yyvsp[(5) - (9)].str),0);
            initiali_tab((yyvsp[(3) - (9)].str),(yyvsp[(5) - (9)].str));

            char *tab_taille =strdup((yyvsp[(5) - (9)].str));
            char *tab_name=(yyvsp[(3) - (9)].str);


            char *token = strtok(tab_taille, ",");
            while (token != NULL) {
                StackNode* operande_tmp = pop(&Operandes_pile);
                quadr("Bounds", "0", strdup(operande_tmp->operande_name), "vide");
                token = strtok(NULL, ",");
            }
            quadr("ADEC", tab_name, "vide", "vide");
            // <==*   9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur 
            ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 107 "syntaxique.y"
    {(yyval.str)=(yyvsp[(2) - (2)].str);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 107 "syntaxique.y"
    { (yyval.str)=" ";;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 110 "syntaxique.y"
    {
        if(Declarer((yyvsp[(3) - (4)].str))){
            yyerror("Sementique error",(yyvsp[(3) - (4)].str),"est deja declare.");
        }
        if(strcmp((yyvsp[(4) - (4)].str)," ")!=0){
            if (!areCompatible(GetTypeFromTS((yyvsp[(3) - (4)].str)), (yyvsp[(4) - (4)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }
        // printf("\n\n------------yes they are compatible for the assignment\n\n");

            if (strstr(GetTypeFromTS((yyvsp[(3) - (4)].str)),"TABLEAU")==NULL && !SetValInTS((yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str))){
                yyerror("Sementique error",(yyvsp[(3) - (4)].str),",affectation non accepte.");
            }else{
                StackNode* poppedElement = pop(&Operandes_pile);
                quadr("=", poppedElement->operande_name,"vide", (yyvsp[(3) - (4)].str));
            }
        }

        rechercher((yyvsp[(3) - (4)].str),"IDF"," ",(yyvsp[(4) - (4)].str),0," ",0);
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 130 "syntaxique.y"
    {
    
    if(Declarer((yyvsp[(1) - (2)].str))){
        yyerror("Sementique error",(yyvsp[(1) - (2)].str),"est deja declare.");
    }

    if(strcmp((yyvsp[(2) - (2)].str)," ")!=0){
        if (!areCompatible(GetTypeFromTS((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str))) {
        yyerror("Sementique error","","incompatible type.");
    }
    // printf("\n\n------------yes they are compatible for the assignment\n\n");

        if (strstr(GetTypeFromTS((yyvsp[(1) - (2)].str)),"TABLEAU")==NULL && !SetValInTS((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (2)].str),",affectation non accepte.");
        }else{
            StackNode* poppedElement = pop(&Operandes_pile);
            quadr("=", poppedElement->operande_name,"vide", (yyvsp[(1) - (2)].str));
        }
    }
    rechercher((yyvsp[(1) - (2)].str),"IDF"," ",(yyvsp[(2) - (2)].str),0," ",0);   
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 156 "syntaxique.y"
    {
        if (isBoolean((yyvsp[(1) - (3)].str)) && isBoolean((yyvsp[(3) - (3)].str))) {
            bool val1 = strcmp((yyvsp[(1) - (3)].str), "true") == 0;
            bool val2 = strcmp((yyvsp[(3) - (3)].str), "true") == 0;
            bool res = val1 | val2;
            // Conversion back to string is trivial here
            char *backToStr = res ? "true" : "false";


            StackNode* operande_tmp2 = pop(&Operandes_pile);
            StackNode* operande_tmp1 = pop(&Operandes_pile);
            char *res_tmp = strdup(Cree_temp_cond());
            push(&Operandes_pile, "EXPRE", res_tmp, "LOGICAL");
            createQuadLogic (2,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
            (yyval.str)=backToStr;
        }
        else {
            yyerror("Sementique error","","cannot use or with non boolean operands");
        }
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 176 "syntaxique.y"
    {
        if (isBoolean((yyvsp[(1) - (3)].str)) && isBoolean((yyvsp[(3) - (3)].str))) {
            bool val1 = strcmp((yyvsp[(1) - (3)].str), "true") == 0;
            bool val2 = strcmp((yyvsp[(3) - (3)].str), "true") == 0;
            bool res = val1 & val2;
            // Conversion back to string is trivial here
            char *backToStr = res ? "true" : "false";
            
            
            StackNode* operande_tmp2 = pop(&Operandes_pile);
            StackNode* operande_tmp1 = pop(&Operandes_pile);
            char *res_tmp = strdup(Cree_temp_cond());
            push(&Operandes_pile, "EXPRE", res_tmp, "LOGICAL");
            createQuadLogic (3,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
            (yyval.str)=backToStr;
        }
        else {
            yyerror("Sementique error","","cannot use and with non boolean operands");
        }
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 196 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPRE", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 203 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   

        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (5,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(ltEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 217 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   

        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (6,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(gtEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 231 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (3,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(geEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 246 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (1,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                (yyval.str)=strdup(eqEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 



    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 262 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (2,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(neEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 277 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (4,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                
        (yyval.str)=strdup(leEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 292 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "CONDIT", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
        ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 299 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }


        StackNode* poppedOpernade2 = pop(&Operandes_pile);
        StackNode* poppedOpernade1 = pop(&Operandes_pile);

        char *T=strdup(Cree_temp());

        quadr("+",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

        char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

        push(&Operandes_pile, "EXPREt", T, type);



        (yyval.str)=strdup(addEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 
        // printf("\n\n------------res= %s\n\n",addEntities($1,$3));
        
        
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 323 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }


        StackNode* poppedOpernade2 = pop(&Operandes_pile);
        StackNode* poppedOpernade1 = pop(&Operandes_pile);

        char *T=strdup(Cree_temp());

        quadr("-",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

        char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

        push(&Operandes_pile, "EXPREt", T, type);



        (yyval.str)=strdup(subEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 344 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPREt", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 351 "syntaxique.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   


        StackNode* poppedOpernade2 = pop(&Operandes_pile);
        StackNode* poppedOpernade1 = pop(&Operandes_pile);

        char *T=strdup(Cree_temp());

        quadr("*",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

        char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

        push(&Operandes_pile, "TERM", T, type);


        (yyval.str)=strdup(mulEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));

    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 372 "syntaxique.y"
    {
        if(isEntityZero((yyvsp[(3) - (3)].str))){
            printf("\n\n------------division sur zero. $3= %s\n\n",(yyvsp[(3) - (3)].str));
            yyerror("Sementique error","","division sur zero.");
        }else {
            if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
                yyerror("Sementique error","","incompatible type");
            }  



            StackNode* poppedOpernade2 = pop(&Operandes_pile);
            StackNode* poppedOpernade1 = pop(&Operandes_pile);

            char *T=strdup(Cree_temp());

            quadr("/",poppedOpernade1->operande_name,poppedOpernade2->operande_name,T);

            char *type=strdup(Calculer_type(poppedOpernade1->operande_type,poppedOpernade2->operande_type));

            push(&Operandes_pile, "TERM", T, type);



            (yyval.str)=strdup(divEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
        } 
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 399 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "TERM", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 407 "syntaxique.y"
    { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(2) - (3)].str);
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 412 "syntaxique.y"
    { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 418 "syntaxique.y"
    {   
        if (!isBoolean((yyvsp[(2) - (2)].str))) {
            yyerror("Sementique error","","incompatible type");
        }   

        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "FACTOR", res_tmp, "LOGICAL");
        createQuadLogic(1,operande_tmp1->operande_name,"vide",res_tmp);

        (yyval.str)=strdup(notEntities((yyvsp[(2) - (2)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 435 "syntaxique.y"
    {
        if(!Declarer((yyvsp[(1) - (1)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");
        }
        char *res=strdup(GetValFromTS((yyvsp[(1) - (1)].str)));
        char *type=strdup(GetTypeFromTS((yyvsp[(1) - (1)].str)));// wela 9ader tejbed e type mel val b GetTypeFromVal mais ana seyiit nkhali koulech kima derna fel cour
        // printf("\n\n------------val ta3 idf= %s\n\n",res);
        if ((res==NULL || strcmp(res," ")==0) && (strstr(type, "ARGUMENT") == NULL)){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"n'a pas d'une valeur");
        } else{
            push(&Operandes_pile, "OPERAND", strdup((yyvsp[(1) - (1)].str)), type);
            (yyval.str)=strdup(res);
        }
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 449 "syntaxique.y"
    {
        push(&Operandes_pile, "OPERAND", (yyvsp[(1) - (1)].str), "LOGICAL");
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 454 "syntaxique.y"
    {
        char backToStr[20];
        sprintf(backToStr, "%d", (yyvsp[(1) - (1)].entier));
        // printf("\npushed inti: %s \n", backToStr);
        push(&Operandes_pile, "OPERAND", strdup(backToStr), "INTEGER");
        (yyval.str)=strdup(backToStr);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 462 "syntaxique.y"
    {
        char backToStr[20];
        sprintf(backToStr, "%g", (yyvsp[(1) - (1)].reel));
        push(&Operandes_pile, "OPERAND", backToStr, "FLOAT");
        (yyval.str)=strdup(backToStr);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 468 "syntaxique.y"
    {
        
        if(!Declarer((yyvsp[(1) - (4)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (4)].str),"est non declare.");      
        }
        if(!verifier_in_out_table((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str)))
            yyerror("Sementique error","","out of rang"); 
        //strcpy(taille,$3);
        char table[100];
        char *tab_taille =strdup((yyvsp[(3) - (4)].str));
        // printf("\n-----------------------------------------taille:%s\n",tab_taille);
        


        char final_str[1024] = "";
        char temp[1024];
        int firstElement = 1;

        char *token = strtok(tab_taille, ",");
        while (token != NULL) {

            StackNode* operande_tmp = pop(&Operandes_pile);
            if (firstElement) {
                // For the first element, directly copy it to final_str
                snprintf(final_str, sizeof(final_str), "%s", operande_tmp->operande_name);
                firstElement = 0; // Set the flag to 0 as the first element is added
            } else {
                // For subsequent elements, add a comma before the element
                snprintf(temp, sizeof(temp), "%s,%s",operande_tmp->operande_name, final_str);
                strcpy(final_str, temp); // Copy the temporary string back to final_str
            }
            token = strtok(NULL, ",");
        }

        sprintf(table, "%s(%s)", (yyvsp[(1) - (4)].str), final_str);
        push(&Operandes_pile, "OPERAND", table, GetTypeFromTS((yyvsp[(1) - (4)].str)));
        (yyval.str)=return_val_tab((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 508 "syntaxique.y"
    {
        if(!isInteger((yyvsp[(3) - (3)].str))){
            yyerror("Sementique error",(yyvsp[(3) - (3)].str),"n'est pas un entier");
        }
        if(strtol((yyvsp[(3) - (3)].str), NULL, 10)<0){
            yyerror("Sementique error",(yyvsp[(3) - (3)].str),"est negative");
        }
        
        char* final_str = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 4 + 1);
        sprintf(final_str, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        // printf("\n-----------------------------------------final str ta3 TAILLE MOR SPRINTF:%s\n",final_str);
        (yyval.str)=strdup(final_str);
        // printf("\n-----------------------------------------str ta3 $$ TAILLE:%s\n",$$);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 522 "syntaxique.y"
    {
        if(!isInteger((yyvsp[(1) - (1)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"n'est pas un entier");
        }
        if(strtol((yyvsp[(1) - (1)].str), NULL, 10)<0){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est negative");
        }
        
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 533 "syntaxique.y"
    {(yyval.str)=strdup("true");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 534 "syntaxique.y"
    {(yyval.str)=strdup("false");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 543 "syntaxique.y"
    {
        if(!Declarer((yyvsp[(1) - (1)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");
        }
        char *type=strdup(GetTypeFromTS((yyvsp[(1) - (1)].str)));
        push(&Operandes_pile, "OPERAND", strdup((yyvsp[(1) - (1)].str)), type);
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 551 "syntaxique.y"
    {
        // printf("\n-----------------------------------------taille ta3 $3 1:%s\n",$3);
        if(!Declarer((yyvsp[(1) - (4)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (4)].str),"est non declare."); 
        }
        if(!verifier_in_out_table((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str))){
            yyerror("Sementique error","","out of rang"); 
        }

        char table[100];
        char *tab_taille =strdup((yyvsp[(3) - (4)].str));
        char final_str[1024] = "";
        char temp[1024];
        int firstElement = 1;

        char *token = strtok(tab_taille, ",");
        while (token != NULL) {

            StackNode* operande_tmp = pop(&Operandes_pile);
            if (firstElement) {
                // For the first element, directly copy it to final_str
                snprintf(final_str, sizeof(final_str), "%s", operande_tmp->operande_name);
                firstElement = 0; // Set the flag to 0 as the first element is added
            } else {
                // For subsequent elements, add a comma before the element
                snprintf(temp, sizeof(temp), "%s,%s",operande_tmp->operande_name, final_str);
                strcpy(final_str, temp); // Copy the temporary string back to final_str
            }
            token = strtok(NULL, ",");
        }

        sprintf(table, "%s(%s)", (yyvsp[(1) - (4)].str), final_str);
        push(&Operandes_pile, "OPERAND", table, GetTypeFromTS((yyvsp[(1) - (4)].str)));


        (yyval.str)=(yyvsp[(1) - (4)].str);
        
        strcpy(taille,(yyvsp[(3) - (4)].str));
        // printf("\n-----------------------------------------taille ta3 $3 2:%s\n",taille);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 592 "syntaxique.y"
    {
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_if),1,tmp);
    printf("pgm juste");
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 598 "syntaxique.y"
    {
    // Fin_if=qc;
    push_int(&Fin_if, qc);
    quadr("BR", "","vide", "vide");
    sprintf(tmp,"%d",qc); // transformer entier vers string
    ajour_quad(pop_int(&deb_else),1,tmp);
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 606 "syntaxique.y"
    {
    // deb_else=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
    push_int(&deb_else, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 616 "syntaxique.y"
    {
        if (strcmp(GetTypeFromTS((yyvsp[(1) - (4)].str)), "CONST") == 0) {
            yyerror("Sementique error","","constantes are not assignable.");
        }
        if (!areCompatible(GetTypeFromTS((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }
        // printf("\n\n------------yes they are compatible for the assignment\n\n");
        if(strstr(GetTypeFromTS((yyvsp[(1) - (4)].str)),"TABLEAU")!=NULL){
            A_M_tab((yyvsp[(1) - (4)].str), taille, (yyvsp[(3) - (4)].str));
            char table[100];

        }else {
            if (!SetValInTS((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str))){
                yyerror("Sementique error",(yyvsp[(1) - (4)].str),",affectation non accepte.");
            }
        }

        StackNode* operande_tmp = pop(&Operandes_pile);
        StackNode* poppedElement_var = pop(&Operandes_pile);
        
        quadr("=", operande_tmp->operande_name,"vide", poppedElement_var->operande_name);
        (yyval.str)=(yyvsp[(1) - (4)].str);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 642 "syntaxique.y"
    {
        push(&Operandes_pile, "valeur", (yyvsp[(1) - (1)].str), "STRING");
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 646 "syntaxique.y"
    {
        push(&Operandes_pile, "valeur", (yyvsp[(1) - (1)].str), "CHAR");
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 650 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "valeur", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 657 "syntaxique.y"
    {
    StackNode* operande_tmp = pop(&Operandes_pile);
    // Check if $3 is exactly one of the format strings
    char* format = (yyvsp[(3) - (8)].str);
    if (strcmp(format, "\"$\"") != 0 && 
        strcmp(format, "\"%\"") != 0 && 
        strcmp(format, "\"#\"") != 0 && 
        strcmp(format, "\"&\"") != 0) {
        yyerror("Semantic error", format, "is not a valid format sign. Use $ % # or &");
    }
    
    // Then check if the format matches variable type
    char* varType = GetTypeFromTS((yyvsp[(6) - (8)].str));
    char* expectedType = NULL;
    
    // Determine expected type based on format
    if (strcmp(format, "\"$\"") == 0)
        expectedType = "INTEGER";
    else if (strcmp(format, "\"%\"") == 0)
        expectedType = "FLOAT";
    else if (strcmp(format, "\"#\"") == 0)
        expectedType = "STRING";
    else if (strcmp(format, "\"&\"") == 0)
        expectedType = "CHAR";
    
    // Check if variable type matches expected type
    if (strcmp(varType, expectedType) != 0) {
        // For constants, check the value type
        if (strcmp(varType, "CONST") == 0) {
            char* typeFromVal = GetTypeFromVal(GetValFromTS((yyvsp[(6) - (8)].str)));
            if (strcmp(typeFromVal, expectedType) != 0) {
                yyerror("Semantic error", format, "does not match variable type");
            }
        } else {
            yyerror("Semantic error", format, "does not match variable type");
        }
    }
    quadr("READ", format, operande_tmp->operande_name, "vide");
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 698 "syntaxique.y"
    {
    StackNode* operande_tmp = pop(&Operandes_pile);
    // Check if the string contains one of the format signs at the end
    char* message = (yyvsp[(3) - (7)].str);
    int len = strlen(message);
    
    // Check if string ends with a format sign
    if (len < 3) {
        yyerror("Semantic error", message, "does not contain a format sign");
    }
    
    char formatChar = message[len-2]; // Get the character before the closing quote
    char formatStr[2];
    
    //for yyerror
    formatStr[0] = formatChar;
    formatStr[1] = '\0';

    // Verify format sign is valid
    if (formatChar != '$' && formatChar != '%' && formatChar != '#' && formatChar != '&') {
        yyerror("Semantic error", message, "does not end with a valid format sign ($ % # &)");
    }
    
    
    
    
    // Then check if the format matches variable type
    char* varType = GetTypeFromTS((yyvsp[(5) - (7)].str));
    char* expectedType = NULL;
    // Determine expected type based on format
    if (formatChar == '$')
        expectedType = "INTEGER";
    else if (formatChar == '%')
        expectedType = "FLOAT";
    else if (formatChar == '#')
        expectedType = "STRING";
    else if (formatChar == '&')
        expectedType = "CHAR";
    // Check if variable type matches expected type
    if (strcmp(varType, expectedType) != 0) {
        // For constants, check the value type
        if (strcmp(varType, "CONST") == 0) {
            char* typeFromVal = GetTypeFromVal(GetValFromTS((yyvsp[(5) - (7)].str)));
            if (strcmp(typeFromVal, expectedType) != 0) {
                yyerror("Semantic error", formatStr, "does not match variable type");
                
            }
        } else {
            yyerror("Semantic error", formatStr, "does not match variable type");
            
        }
    }
    printf("\n-----------------------------------------message ta3 $3:%s\n",message);
    // Create display message without format character but keep quotes
    char* displayMessage = (char*)malloc(len); // -1 for removing just the format char
    if (displayMessage == NULL) {
        yyerror("Semantic error", "memory allocation", "failed for display message");
    }
    // Copy the message up to but not including the format character
    strncpy(displayMessage, message, len - 2);
    // Add the closing quote
    displayMessage[len - 2] = '"';
    displayMessage[len - 1] = '\0';

    quadr("WRITE", displayMessage, operande_tmp->operande_name, "vide");
    free(displayMessage);
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 766 "syntaxique.y"
    {
    quadr("WRITE", (yyvsp[(3) - (5)].str), "vide", "vide");
;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 770 "syntaxique.y"
    {
    sprintf(tmp,"%d",pop_int(&deb_while));
    quadr("BR", tmp,"vide", "vide");
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_while),1,tmp);
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 777 "syntaxique.y"
    {
    push_int(&Fin_while, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 783 "syntaxique.y"
    {
    push_int(&deb_while, qc);
;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 788 "syntaxique.y"
    {
        if (isBoolean((yyvsp[(1) - (1)].str))) {
            (yyval.str)=(yyvsp[(1) - (1)].str);
        } else {
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"is not boolean");
        }
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 797 "syntaxique.y"
    {
    // Go back to loop condition
    sprintf(tmp, "%d", pop_int(&deb_for));
    quadr("BR", tmp, "vide", "vide");
    
    // Update the exit jumps
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_for), 1, tmp);
;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 808 "syntaxique.y"
    {
    StackNode* operande_tmp = pop(&Operandes_pile);
    
    // Check if the counter variable is declared
    if(!Declarer((yyvsp[(3) - (8)].str))){
        yyerror("Sementique error", (yyvsp[(3) - (8)].str), "est non declare.");
    }
    
    // Check if the step is valid (integer)
    if(!isInteger((yyvsp[(5) - (8)].str))){
        yyerror("Sementique error", (yyvsp[(5) - (8)].str), "n'est pas un entier valide pour le pas.");
    }
    
    // Initialize counter variable with the step value
    char *T = strdup(Cree_temp());
    quadr("=", (yyvsp[(5) - (8)].str), "vide", T);
    quadr("+", (yyvsp[(3) - (8)].str), T, (yyvsp[(3) - (8)].str));
    
    // Store position for loop condition
    push_int(&deb_for, qc);
    
    // Evaluate condition
    operande_tmp = pop(&Operandes_pile);
    
    // Create conditional jump to exit loop if condition is false
    push_int(&Fin_for, qc);
    quadr("BZ", "", operande_tmp->operande_name, "vide");
;}
    break;



/* Line 1455 of yacc.c  */
#line 2569 "syntaxique.tab.c"
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
#line 838 "syntaxique.y"


int main(int argc, char** argv)
{
    if (argc > 1) {
        file_name = argv[1];
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            // Handle error
            perror("Cannot open input_file.txt");
            return EXIT_FAILURE;
        }
        yyin = file;
    }
    yyparse(); // la fct qui lance l analyseur syntaxique
    // yylex(); // lance lexical
    afficher();
    afficher_qdr();

    apply_all_optimizations();
    generate_assembly("output.asm");

    if (yyin != stdin) {
        fclose(yyin);
    }
    afficher_pile(Operandes_pile);
    
   return 0;
 }
 yywrap ()
 {}

// int yyerror ( char*  msg )
//  {
//     printf("File \"%s\", line %d, character %d: %s\n",file_name, nb_ligne, Col,msg);
//     exit(EXIT_FAILURE);
//   }
int yyerror ( char*  msg, char* entite, char* description)
 {
    afficher();
    afficher_qdr();
    afficher_pile(Operandes_pile);
    printf("File \"%s\", line %d, character %d: %s, %s %s\n", file_name, nb_ligne, Col, msg, entite, description);
    exit(EXIT_FAILURE);
  }

