
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
#line 1 "syntaxique_old.y"

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
#line 105 "syntaxique_old.tab.c"

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
     aff = 259,
     mc_prgrm = 260,
     mc_rtin = 261,
     inti = 262,
     real = 263,
     mc_endr = 264,
     mc_call = 265,
     mc_dim = 266,
     mc_logi = 267,
     mc_char = 268,
     mc_true = 269,
     mc_false = 270,
     mc_read = 271,
     mc_write = 272,
     pvg = 273,
     str = 274,
     mc_int = 275,
     mc_real = 276,
     mc_end = 277,
     mc_if = 278,
     mc_then = 279,
     mc_else = 280,
     mc_dowhile = 281,
     mc_enddo = 282,
     mc_equival = 283,
     mc_or = 284,
     ge = 285,
     eq = 286,
     ne = 287,
     le = 288,
     add = 289,
     sub = 290,
     mul = 291,
     divi = 292,
     mc_and = 293,
     mc_endif = 294,
     lt = 295,
     gt = 296,
     po = 297,
     pf = 298,
     verg = 299,
     err = 300,
     mc_for = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 32 "syntaxique_old.y"

         int     entier;
         char*   str;
         float reel;



/* Line 214 of yacc.c  */
#line 195 "syntaxique_old.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "syntaxique_old.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    12,    14,    16,    17,    20,    22,
      27,    31,    39,    41,    43,    45,    47,    49,    51,    54,
      56,    60,    66,    74,    77,    79,    84,    87,    91,    95,
      97,   101,   105,   109,   113,   117,   121,   123,   127,   131,
     133,   137,   141,   143,   147,   149,   151,   153,   155,   157,
     162,   168,   173,   177,   179,   183,   185,   187,   189,   191,
     193,   197,   199,   201,   203,   206,   208,   210,   212,   214,
     216,   218,   220,   222,   226,   228,   230,   236,   240,   244,
     246,   248,   253,   257,   261,   266,   269,   271,   276,   278,
     280,   286,   292,   296,   300,   302,   304,   308,   313,   315,
     317,   321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    50,    49,    -1,     5,     3,    56,    72,
      22,    -1,    51,    -1,    52,    -1,    -1,    52,    53,    -1,
      53,    -1,    54,    73,    84,     9,    -1,    54,    84,     9,
      -1,    55,     6,     3,    42,    70,    43,    56,    -1,    20,
      -1,    21,    -1,    13,    -1,    12,    -1,    51,    -1,    57,
      -1,    57,    58,    -1,    58,    -1,    55,    60,    18,    -1,
      55,     3,    36,     7,    18,    -1,    55,     3,    11,    42,
      68,    43,    18,    -1,     4,    85,    -1,    51,    -1,    60,
      44,     3,    59,    -1,     3,    59,    -1,    61,    29,    62,
      -1,    61,    38,    62,    -1,    62,    -1,    62,    40,    63,
      -1,    62,    41,    63,    -1,    62,    30,    63,    -1,    62,
      31,    63,    -1,    62,    32,    63,    -1,    62,    33,    63,
      -1,    63,    -1,    63,    34,    64,    -1,    63,    35,    64,
      -1,    64,    -1,    64,    36,    65,    -1,    64,    37,    65,
      -1,    65,    -1,    42,    61,    43,    -1,    66,    -1,     3,
      -1,    69,    -1,     7,    -1,     8,    -1,     3,    42,    68,
      43,    -1,    10,     3,    42,    67,    43,    -1,    10,     3,
      42,    43,    -1,    67,    44,    85,    -1,    85,    -1,    68,
      44,    85,    -1,    85,    -1,    14,    -1,    15,    -1,    71,
      -1,    51,    -1,    71,    44,     3,    -1,     3,    -1,    51,
      -1,    73,    -1,    73,    74,    -1,    74,    -1,    80,    -1,
      86,    -1,    87,    -1,    89,    -1,    84,    -1,    75,    -1,
      93,    -1,    28,    76,    18,    -1,    77,    -1,    51,    -1,
      77,    44,    42,    78,    43,    -1,    42,    78,    43,    -1,
      78,    44,    79,    -1,    79,    -1,     3,    -1,     3,    42,
      68,    43,    -1,    81,    83,    39,    -1,    82,    24,    73,
      -1,    23,    42,    92,    43,    -1,    25,    73,    -1,    51,
      -1,    79,     4,    85,    18,    -1,    19,    -1,    61,    -1,
      16,    42,    79,    43,    18,    -1,    17,    42,    88,    43,
      18,    -1,    88,    44,    19,    -1,    88,    44,    79,    -1,
      19,    -1,    79,    -1,    90,    73,    27,    -1,    91,    42,
      92,    43,    -1,    26,    -1,    61,    -1,    94,    73,    22,
      -1,    46,    42,     3,    44,    85,    44,    92,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    69,    71,    71,    73,    75,    75,    78,
      83,    91,   130,   130,   130,   130,   132,   132,   134,   134,
     137,   137,   143,   163,   163,   166,   186,   212,   232,   252,
     259,   275,   289,   304,   320,   335,   350,   357,   381,   402,
     409,   430,   456,   464,   469,   479,   493,   498,   506,   513,
     552,   607,   641,   647,   652,   666,   677,   678,   680,   680,
     682,   682,   684,   684,   686,   686,   688,   688,   688,   688,
     688,   688,   688,   690,   692,   692,   694,   694,   697,   700,
     705,   713,   754,   760,   768,   775,   775,   778,   801,   805,
     811,   813,   815,   815,   815,   815,   817,   824,   830,   835,
     844,   855
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "idf", "aff", "mc_prgrm", "mc_rtin",
  "inti", "real", "mc_endr", "mc_call", "mc_dim", "mc_logi", "mc_char",
  "mc_true", "mc_false", "mc_read", "mc_write", "pvg", "str", "mc_int",
  "mc_real", "mc_end", "mc_if", "mc_then", "mc_else", "mc_dowhile",
  "mc_enddo", "mc_equival", "mc_or", "ge", "eq", "ne", "le", "add", "sub",
  "mul", "divi", "mc_and", "mc_endif", "lt", "gt", "po", "pf", "verg",
  "err", "mc_for", "$accept", "s", "PRGM_PRIN", "FCTS", "VIDE", "ENSFCT",
  "FCT", "debut_fct", "TYPE", "DECS", "ENSDEC", "DEC",
  "partie_gauch_affectation", "ENSIDF_dec", "EXPRE", "CONDIT", "EXPREt",
  "TERM", "FACTOR", "OPERAND", "ENSpara", "TAILLE", "LOGI", "IDFS",
  "ENSIDF", "INSTS", "ENSINST", "INST", "eqival_statement",
  "ens_list_vars", "ens_list_var", "list_var", "var", "if_statement",
  "B_if", "A_if", "else_clause", "assignment", "valeur", "read_statement",
  "write_statement", "ENS_PARA_WRITE", "dowhile_statement", "B_while",
  "A_while", "CONDI", "for_statement", "A_for", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    81,    82,    83,    83,    84,    85,    85,
      86,    87,    88,    88,    88,    88,    89,    90,    91,    92,
      93,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     1,     1,     0,     2,     1,     4,
       3,     7,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     5,     7,     2,     1,     4,     2,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     4,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     5,     3,     3,     1,
       1,     4,     3,     3,     4,     2,     1,     4,     1,     1,
       5,     5,     3,     3,     1,     1,     3,     4,     1,     1,
       3,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    15,    14,    12,    13,     0,     0,     4,     5,     8,
       0,     0,     1,     0,     2,     7,    80,     0,     0,     0,
      98,     6,     0,     0,    65,    71,     0,    66,     6,     0,
      70,    67,    68,    69,     0,     0,    72,     0,     0,     6,
       0,     0,     0,     0,     0,    75,     0,    74,     0,    64,
      70,     0,     0,    86,     0,     0,    10,     0,    70,     0,
       0,     0,    16,     0,     6,    17,    19,    45,    47,    48,
       0,    56,    57,    88,     0,    89,    29,    36,    39,    42,
      44,     0,    46,    55,     0,    94,    95,     0,    99,     0,
       0,    79,    73,     0,     0,     9,     0,    85,    82,    83,
      96,     0,   100,     6,     6,     0,    62,     0,    63,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
      84,    77,     0,     0,     0,    87,    97,    61,    59,     0,
      58,     0,     0,     0,    24,    26,    20,     0,     3,     0,
       0,    43,    27,    28,    32,    33,    34,    35,    30,    31,
      37,    38,    40,    41,    54,    90,    91,    92,    93,    78,
       0,     0,     6,     0,    23,     0,     0,     6,    49,    51,
       0,    53,    76,     0,    11,    60,     0,    21,    25,    50,
       0,     0,     0,    52,   101,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    14,     6,    62,     8,     9,    10,    63,    64,
      65,    66,   145,   105,    75,    76,    77,    78,    79,    80,
     180,    81,    82,   139,   140,   107,    23,    24,    25,    46,
      47,    90,    26,    27,    28,    29,    54,    58,    83,    31,
      32,    87,    33,    34,    35,    89,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
      96,  -103,  -103,  -103,  -103,    14,    13,  -103,    96,  -103,
      39,     6,  -103,    44,  -103,  -103,     9,    18,    45,    65,
    -103,    68,    83,    39,  -103,  -103,    77,  -103,   103,   116,
     140,  -103,  -103,  -103,    39,   112,  -103,    39,   154,    96,
      12,   155,    10,    91,   155,  -103,   141,   117,   157,  -103,
     153,    12,    39,  -103,   124,    39,  -103,     7,  -103,    91,
      22,   122,  -103,   162,    39,    96,  -103,   125,  -103,  -103,
     163,  -103,  -103,  -103,    91,    28,    89,    40,    34,  -103,
    -103,    46,  -103,  -103,   126,  -103,  -103,    70,    28,   127,
      80,  -103,  -103,   129,   128,  -103,   150,    39,  -103,    39,
    -103,   130,  -103,   171,     5,    -7,  -103,   156,    39,  -103,
      12,   133,    20,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,  -103,    12,   158,   161,    33,
    -103,  -103,   155,   155,    12,  -103,  -103,  -103,  -103,   137,
     138,    12,   139,   176,  -103,  -103,  -103,   181,  -103,    88,
      69,  -103,    89,    89,    40,    40,    40,    40,    40,    40,
      34,    34,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     100,   142,    96,   182,  -103,    12,   169,   184,  -103,  -103,
     102,  -103,  -103,    91,  -103,  -103,   104,  -103,  -103,  -103,
      12,   146,   172,  -103,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,  -103,     0,  -103,   183,  -103,    61,    21,
    -103,   131,    15,  -103,   -42,    37,    19,    31,    32,  -103,
    -103,  -102,  -103,  -103,  -103,  -103,    63,   -17,  -103,  -103,
    -103,    62,   -37,  -103,  -103,  -103,  -103,    36,   -48,  -103,
    -103,  -103,  -103,  -103,  -103,   -57,  -103,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       7,    88,   101,    96,    84,    86,    49,    91,   149,   141,
      16,   146,    38,    16,    12,    67,   142,    88,    13,    68,
      69,    45,    70,    17,    18,    16,    71,    72,    53,    85,
      19,    73,   112,    20,   100,    21,    16,   147,    17,    18,
      49,   143,    16,    49,   102,    19,    30,    39,    20,   113,
      21,    40,   167,    22,    74,    17,    18,   113,   114,    50,
      41,    11,    19,   151,   106,    20,   114,    21,    22,    11,
     123,   124,    67,   186,   121,   122,    68,    69,   164,    70,
      49,    51,    49,    71,    72,    22,   171,    42,    73,   125,
     126,    49,   168,   174,    67,   169,    91,    57,    68,    69,
      60,    70,   181,   138,   144,    71,    72,    43,     1,     2,
      44,    74,   179,   128,   129,    97,     3,     4,    99,   115,
     116,   117,   118,   131,   132,    48,   191,   108,    52,   119,
     120,   178,   126,    74,   154,   155,   156,   157,   158,   159,
      55,    88,   193,   182,   132,   189,   190,   192,   126,    56,
     152,   153,   160,   161,    59,   162,   163,    61,    16,    92,
      94,    93,    95,    98,   103,   104,   111,   110,   135,   127,
     130,   133,   134,   136,   137,   150,   165,   144,   148,   166,
     172,   175,   173,   176,   177,   185,   183,   187,   141,   194,
     195,    15,   188,   184,     0,   170,   109
};

static const yytype_int16 yycheck[] =
{
       0,    43,    59,    51,    41,    42,    23,    44,   110,     4,
       3,    18,     6,     3,     0,     3,    11,    59,     5,     7,
       8,    21,    10,    16,    17,     3,    14,    15,    28,    19,
      23,    19,    74,    26,    27,    28,     3,    44,    16,    17,
      57,    36,     3,    60,    22,    23,    10,     3,    26,    29,
      28,    42,    19,    46,    42,    16,    17,    29,    38,    23,
      42,     0,    23,    43,    64,    26,    38,    28,    46,     8,
      36,    37,     3,   175,    34,    35,     7,     8,   126,    10,
      97,     4,    99,    14,    15,    46,   134,    42,    19,    43,
      44,   108,   129,   141,     3,   132,   133,    34,     7,     8,
      37,    10,   150,   103,   104,    14,    15,    42,    12,    13,
      42,    42,    43,    43,    44,    52,    20,    21,    55,    30,
      31,    32,    33,    43,    44,    42,   183,    64,    25,    40,
      41,    43,    44,    42,   115,   116,   117,   118,   119,   120,
      24,   183,   190,    43,    44,    43,    44,    43,    44,     9,
     113,   114,   121,   122,    42,   123,   124,     3,     3,    18,
       3,    44,     9,    39,    42,     3,     3,    42,    18,    43,
      43,    42,    44,    43,     3,    42,    18,   177,    22,    18,
      43,    42,    44,     7,     3,     3,    44,    18,     4,    43,
      18,     8,   177,   172,    -1,   133,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    20,    21,    48,    50,    51,    52,    53,
      54,    55,     0,     5,    49,    53,     3,    16,    17,    23,
      26,    28,    46,    73,    74,    75,    79,    80,    81,    82,
      84,    86,    87,    89,    90,    91,    93,    94,     6,     3,
      42,    42,    42,    42,    42,    51,    76,    77,    42,    74,
      84,     4,    25,    51,    83,    24,     9,    73,    84,    42,
      73,     3,    51,    55,    56,    57,    58,     3,     7,     8,
      10,    14,    15,    19,    42,    61,    62,    63,    64,    65,
      66,    68,    69,    85,    79,    19,    79,    88,    61,    92,
      78,    79,    18,    44,     3,     9,    85,    73,    39,    73,
      27,    92,    22,    42,     3,    60,    51,    72,    73,    58,
      42,     3,    61,    29,    38,    30,    31,    32,    33,    40,
      41,    34,    35,    36,    37,    43,    44,    43,    43,    44,
      43,    43,    44,    42,    44,    18,    43,     3,    51,    70,
      71,     4,    11,    36,    51,    59,    18,    44,    22,    68,
      42,    43,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    85,    18,    18,    19,    79,    79,
      78,    85,    43,    44,    85,    42,     7,     3,    43,    43,
      67,    85,    43,    44,    56,     3,    68,    18,    59,    43,
      44,    92,    43,    85,    43,    18
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
#line 67 "syntaxique_old.y"
    {YYACCEPT;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 78 "syntaxique_old.y"
    {
        if(strcmp((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str))!=0){
            yyerror("Sementique error",(yyvsp[(3) - (4)].str),"est different du nom de la fonction.");
        }
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 83 "syntaxique_old.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str))!=0){
            yyerror("Sementique error",(yyvsp[(2) - (3)].str),"est different du nom de la fonction.");
        }
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 "syntaxique_old.y"
    {
        //R1
        // int p = lookup($3);
        // printf("r1 look up p:%d\n",p);
        
        // if (p==-1){
        //     p=inserer_fct($3,false,0);
        //     printf("r1 inserer_fct p:%d\n",p);
        //     show_table();
        // }else{
        //     yyerror("Sementique error",$3,"est deja declare.");
        // }
        //R3
        // int p2 = lookup($3);
        // printf("r3 look up p:%d\n",p2);
        // int a,b;
        // if (p2==-1){
        //     yyerror("Sementique error",$3,"est non declare.1");
        // }else{
        //     if(table_fct[p2].util){
        //         yyerror("Sementique error",$3,"est deja declare.");
        //     }else{
        //         a = table_fct[p2].address;
        //         while(a!=0){
        //             b= strtol(quad[a].op1, NULL, 10);
        //             sprintf(tmp,"%d",qc);
        //             ajour_quad(a,1,tmp);
        //             a=b;
        //         }
        //         table_fct[p2].address=qc;
        //     }
        // }
        //R3 fin
        Declarer((yyvsp[(3) - (7)].str));
        inserer_fonction((yyvsp[(3) - (7)].str),nb_argument);
        nb_argument=0;
        (yyval.str)=(yyvsp[(3) - (7)].str);
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 137 "syntaxique_old.y"
    {
        // printf("the dcr idf is :%s\n",$2);
        if(Declarer((yyvsp[(2) - (5)].str))){
            yyerror("Sementique error",(yyvsp[(2) - (5)].str),"est deja declare.");
        }
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 143 "syntaxique_old.y"
    {
        if(Declarer((yyvsp[(2) - (7)].str))){
            yyerror("Sementique error",(yyvsp[(2) - (7)].str),"est deja declare.");}
            rechercher((yyvsp[(2) - (7)].str),"IDF","TABLEAU",0,0,(yyvsp[(5) - (7)].str),0);
            initiali_tab((yyvsp[(2) - (7)].str),(yyvsp[(5) - (7)].str));

            char *tab_taille =strdup((yyvsp[(5) - (7)].str));
            char *tab_name=(yyvsp[(2) - (7)].str);


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

  case 23:

/* Line 1455 of yacc.c  */
#line 163 "syntaxique_old.y"
    {(yyval.str)=(yyvsp[(2) - (2)].str);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 163 "syntaxique_old.y"
    { (yyval.str)=" ";;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 166 "syntaxique_old.y"
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

  case 26:

/* Line 1455 of yacc.c  */
#line 186 "syntaxique_old.y"
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

  case 27:

/* Line 1455 of yacc.c  */
#line 212 "syntaxique_old.y"
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

  case 28:

/* Line 1455 of yacc.c  */
#line 232 "syntaxique_old.y"
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

  case 29:

/* Line 1455 of yacc.c  */
#line 252 "syntaxique_old.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPRE", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 259 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }   


        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (5,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(ltEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 275 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }   

        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (6,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(gtEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 289 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (3,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(geEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 304 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (1,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                (yyval.str)=strdup(eqEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 



    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 320 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }   


        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (2,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);

        (yyval.str)=strdup(neEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 335 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
        }   

        
        StackNode* operande_tmp2 = pop(&Operandes_pile);
        StackNode* operande_tmp1 = pop(&Operandes_pile);
        char *res_tmp = strdup(Cree_temp_cond());
        push(&Operandes_pile, "CONDIT", res_tmp, "LOGICAL");
        createQuadCompare (4,operande_tmp1->operande_name,operande_tmp2->operande_name,res_tmp);
                
        (yyval.str)=strdup(leEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));// 3lah strdup: parce que add entite 3andha var pack to str hatet fiha l resulta w daret return doka $$ rah y pointi 3la hadi l var koun trouh wela tetbedel tani $$ tro7 wela tetbedel 3labiha str dup khir strdup cha dir treservi l $$ l espase li tehtajou fel mem dir strcpy lel back to str hadik w tdiir $$ t pointi 3la hada espase ejdiid bah $$ yweli 3andha l espase ta3ha ejdiid wahedha /koun fi union derna char str[20] mechi char* str koun diract derna strcpy parceque lespase rah reservi li houwa tab de 20 mais hna derna char * str tema lazem strdup 

    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 350 "syntaxique_old.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "CONDIT", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 357 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
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

  case 38:

/* Line 1455 of yacc.c  */
#line 381 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
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

  case 39:

/* Line 1455 of yacc.c  */
#line 402 "syntaxique_old.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPREt", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 409 "syntaxique_old.y"
    {   
        if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
            yyerror("Sementique error","","incompatible type.");
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

  case 41:

/* Line 1455 of yacc.c  */
#line 430 "syntaxique_old.y"
    {
        if(isEntityZero((yyvsp[(3) - (3)].str))){
            yyerror("Sementique error","","division sur zero.");
        }else {
            if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
                yyerror("Sementique error","","incompatible type.");
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

  case 42:

/* Line 1455 of yacc.c  */
#line 456 "syntaxique_old.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "TERM", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 464 "syntaxique_old.y"
    { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(2) - (3)].str);
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 469 "syntaxique_old.y"
    { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 479 "syntaxique_old.y"
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

  case 46:

/* Line 1455 of yacc.c  */
#line 493 "syntaxique_old.y"
    {
        push(&Operandes_pile, "OPERAND", (yyvsp[(1) - (1)].str), "LOGICAL");
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 498 "syntaxique_old.y"
    {
        char backToStr[20];
        sprintf(backToStr, "%d", (yyvsp[(1) - (1)].entier));
        // printf("\npushed inti: %s \n", backToStr);
        push(&Operandes_pile, "OPERAND", strdup(backToStr), "INTEGER");
        (yyval.str)=strdup(backToStr);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 506 "syntaxique_old.y"
    {
        char backToStr[20];
        sprintf(backToStr, "%g", (yyvsp[(1) - (1)].reel));
        push(&Operandes_pile, "OPERAND", backToStr, "REAL");
        (yyval.str)=strdup(backToStr);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 513 "syntaxique_old.y"
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

  case 50:

/* Line 1455 of yacc.c  */
#line 552 "syntaxique_old.y"
    {
        //R2
        // show_table();
        // int p = lookup($2);
        // printf("r2 look up p:%d\n",p);
        // if (p==-1){
        //     yyerror("Sementique error",$3,"est non declare.2");
        // }else{
        //     if(table_fct[p].util){
        //         sprintf(tmp,"%d",table_fct[p].address);
        //         quadr("BR---",tmp,"vide","vide");
        //     }else{
        //         sprintf(tmp,"%d",table_fct[p].address);
        //         quadr("BR---",tmp,"vide","vide");
        //         table_fct[p].address=qc;
        //     }
        //     push_int(&fin_routine, qc);
        // }

        //R2 fin 
        if(verifier_nb_argument((yyvsp[(2) - (5)].str),nb_argument)==1){
            yyerror("Sementique error","","le nombre d'argument est uncorrect.");
        }else if(verifier_nb_argument((yyvsp[(2) - (5)].str),nb_argument)==-1)
            yyerror("Sementique error",(yyvsp[(2) - (5)].str),"est non declare.");
        char *tab_taille =strdup((yyvsp[(4) - (5)].str));
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

        char fonct[100];
        sprintf(fonct, "%s(%s)", (yyvsp[(2) - (5)].str), final_str);
        push(&Operandes_pile, "OPERAND", fonct, GetTypeFromTS((yyvsp[(2) - (5)].str)));

        (yyval.str)=return_val_fonction((yyvsp[(2) - (5)].str));nb_argument=0;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 607 "syntaxique_old.y"
    {
        //R2
        // show_table();
        // int p = lookup($2);
        // printf("r2 look up p:%d\n",p);
        // if (p==-1){
        //     yyerror("Sementique error",$3,"est non declare.2");
        // }else{
        //     if(table_fct[p].util){
        //         sprintf(tmp,"%d",table_fct[p].address);
        //         quadr("BR---",tmp,"vide","vide");
        //     }else{
        //         sprintf(tmp,"%d",table_fct[p].address);
        //         quadr("BR---",tmp,"vide","vide");
        //         table_fct[p].address=qc;
        //     }
        //     push_int(&fin_routine, qc);
        // }

        //R2 fin 
        if(verifier_nb_argument((yyvsp[(2) - (4)].str),nb_argument)==1){
            yyerror("Sementique error","","le nombre d'argument est uncorrect.");
        }else if(verifier_nb_argument((yyvsp[(2) - (4)].str),nb_argument)==-1)
            yyerror("Sementique error",(yyvsp[(2) - (4)].str),"est non declare.");

        char fonct[100];
        sprintf(fonct, "%s()", (yyvsp[(2) - (4)].str));
        push(&Operandes_pile, "OPERAND", fonct, GetTypeFromTS((yyvsp[(2) - (4)].str)));

        (yyval.str)=return_val_fonction((yyvsp[(2) - (4)].str));nb_argument=0;
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 641 "syntaxique_old.y"
    {
        char* final_str = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 4 + 1);
        sprintf(final_str, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str)=strdup(final_str);
        nb_argument++;
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 647 "syntaxique_old.y"
    {
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
        nb_argument++;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 652 "syntaxique_old.y"
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

  case 55:

/* Line 1455 of yacc.c  */
#line 666 "syntaxique_old.y"
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

  case 56:

/* Line 1455 of yacc.c  */
#line 677 "syntaxique_old.y"
    {(yyval.str)=strdup("true");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 678 "syntaxique_old.y"
    {(yyval.str)=strdup("false");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 682 "syntaxique_old.y"
    {Declarer((yyvsp[(3) - (3)].str));nb_argument++;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 682 "syntaxique_old.y"
    {Declarer((yyvsp[(1) - (1)].str));nb_argument++;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 697 "syntaxique_old.y"
    {
        StackNode* operande_tmp = pop(&Operandes_pile);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 700 "syntaxique_old.y"
    {
        StackNode* operande_tmp = pop(&Operandes_pile);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 705 "syntaxique_old.y"
    {
        if(!Declarer((yyvsp[(1) - (1)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");
        }
        char *type=strdup(GetTypeFromTS((yyvsp[(1) - (1)].str)));
        push(&Operandes_pile, "OPERAND", strdup((yyvsp[(1) - (1)].str)), type);
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 713 "syntaxique_old.y"
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

  case 82:

/* Line 1455 of yacc.c  */
#line 754 "syntaxique_old.y"
    {
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_if),1,tmp);
    printf("pgm juste");
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 760 "syntaxique_old.y"
    {
    // Fin_if=qc;
    push_int(&Fin_if, qc);
    quadr("BR", "","vide", "vide");
    sprintf(tmp,"%d",qc); // transformer entier vers string
    ajour_quad(pop_int(&deb_else),1,tmp);
;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 768 "syntaxique_old.y"
    {
    // deb_else=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
    push_int(&deb_else, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 778 "syntaxique_old.y"
    {   
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

  case 88:

/* Line 1455 of yacc.c  */
#line 801 "syntaxique_old.y"
    {
        push(&Operandes_pile, "valeur", (yyvsp[(1) - (1)].str), "CHARACTER");
        (yyval.str)=strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 805 "syntaxique_old.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "valeur", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 811 "syntaxique_old.y"
    {StackNode* operande_tmp = pop(&Operandes_pile);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 815 "syntaxique_old.y"
    {StackNode* operande_tmp = pop(&Operandes_pile);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 815 "syntaxique_old.y"
    {StackNode* operande_tmp = pop(&Operandes_pile);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 817 "syntaxique_old.y"
    {
    sprintf(tmp,"%d",pop_int(&deb_while));
    quadr("BR", tmp,"vide", "vide");
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_while),1,tmp);
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 824 "syntaxique_old.y"
    {
    push_int(&Fin_while, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 830 "syntaxique_old.y"
    {
    push_int(&deb_while, qc);
;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 835 "syntaxique_old.y"
    {
        if (isBoolean((yyvsp[(1) - (1)].str))) {
            (yyval.str)=(yyvsp[(1) - (1)].str);
        } else {
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"is not boolean");
        }
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 844 "syntaxique_old.y"
    {
    // Go back to loop condition
    sprintf(tmp, "%d", pop_int(&deb_for));
    quadr("BR", tmp, "vide", "vide");
    
    // Update the exit jumps
    sprintf(tmp, "%d", qc);
    ajour_quad(pop_int(&Fin_for), 1, tmp);
;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 855 "syntaxique_old.y"
    {
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
    StackNode* operande_tmp = pop(&Operandes_pile);
    
    // Create conditional jump to exit loop if condition is false
    push_int(&Fin_for, qc);
    quadr("BZ", "", operande_tmp->operande_name, "vide");
;}
    break;



/* Line 1455 of yacc.c  */
#line 2676 "syntaxique_old.tab.c"
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
#line 883 "syntaxique_old.y"


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
    printf("File \"%s\", line %d, character %d: %s, %s %s\n", file_name, nb_ligne, Col, msg, entite, description);
    exit(EXIT_FAILURE);
  }

