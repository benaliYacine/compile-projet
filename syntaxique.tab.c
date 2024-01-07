
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
     err = 300
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    12,    14,    16,    17,    20,    22,
      27,    31,    39,    41,    43,    45,    47,    49,    51,    54,
      56,    60,    61,    68,    76,    79,    81,    86,    89,    93,
      97,    99,   103,   107,   111,   115,   119,   123,   125,   129,
     133,   135,   139,   143,   145,   149,   151,   153,   155,   157,
     159,   164,   170,   174,   176,   180,   182,   184,   186,   188,
     190,   194,   196,   198,   200,   203,   205,   207,   209,   211,
     213,   215,   217,   221,   223,   225,   231,   235,   239,   241,
     243,   248,   252,   256,   261,   264,   266,   271,   273,   275,
     281,   287,   291,   295,   297,   299,   303,   308,   310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    49,    48,    -1,     5,     3,    55,    72,
      22,    -1,    50,    -1,    51,    -1,    -1,    51,    52,    -1,
      52,    -1,    53,    73,    84,     9,    -1,    53,    84,     9,
      -1,    54,     6,     3,    42,    70,    43,    55,    -1,    20,
      -1,    21,    -1,    13,    -1,    12,    -1,    50,    -1,    56,
      -1,    56,    57,    -1,    57,    -1,    54,    60,    18,    -1,
      -1,    54,     3,    58,    36,     7,    18,    -1,    54,     3,
      11,    42,    68,    43,    18,    -1,     4,    85,    -1,    50,
      -1,    60,    44,     3,    59,    -1,     3,    59,    -1,    61,
      29,    62,    -1,    61,    38,    62,    -1,    62,    -1,    62,
      40,    63,    -1,    62,    41,    63,    -1,    62,    30,    63,
      -1,    62,    31,    63,    -1,    62,    32,    63,    -1,    62,
      33,    63,    -1,    63,    -1,    63,    34,    64,    -1,    63,
      35,    64,    -1,    64,    -1,    64,    36,    65,    -1,    64,
      37,    65,    -1,    65,    -1,    42,    61,    43,    -1,    66,
      -1,     3,    -1,    69,    -1,     7,    -1,     8,    -1,     3,
      42,    68,    43,    -1,    10,     3,    42,    67,    43,    -1,
      67,    44,    85,    -1,    85,    -1,    68,    44,    85,    -1,
      85,    -1,    14,    -1,    15,    -1,    71,    -1,    50,    -1,
      71,    44,     3,    -1,     3,    -1,    50,    -1,    73,    -1,
      73,    74,    -1,    74,    -1,    80,    -1,    86,    -1,    87,
      -1,    89,    -1,    84,    -1,    75,    -1,    28,    76,    18,
      -1,    77,    -1,    50,    -1,    77,    44,    42,    78,    43,
      -1,    42,    78,    43,    -1,    78,    44,    79,    -1,    79,
      -1,     3,    -1,     3,    42,    68,    43,    -1,    81,    83,
      39,    -1,    82,    24,    73,    -1,    23,    42,    92,    43,
      -1,    25,    73,    -1,    50,    -1,    79,     4,    85,    18,
      -1,    19,    -1,    61,    -1,    16,    42,    79,    43,    18,
      -1,    17,    42,    88,    43,    18,    -1,    88,    44,    19,
      -1,    88,    44,    79,    -1,    19,    -1,    79,    -1,    90,
      73,    27,    -1,    91,    42,    92,    43,    -1,    26,    -1,
      61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    63,    65,    65,    67,    69,    69,    72,
      77,    85,   124,   124,   124,   124,   126,   126,   128,   128,
     130,   130,   130,   134,   158,   158,   160,   180,   206,   224,
     242,   249,   265,   280,   294,   309,   324,   339,   346,   370,
     393,   400,   421,   447,   455,   460,   470,   485,   490,   499,
     506,   531,   579,   586,   592,   604,   615,   616,   618,   618,
     620,   620,   622,   622,   624,   624,   626,   626,   626,   626,
     626,   626,   628,   630,   630,   632,   632,   634,   634,   636,
     643,   666,   672,   680,   687,   687,   689,   739,   743,   749,
     751,   753,   753,   753,   753,   755,   762,   768,   772
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
  "err", "$accept", "s", "PRGM_PRIN", "FCTS", "VIDE", "ENSFCT", "FCT",
  "debut_fct", "TYPE", "DECS", "ENSDEC", "DEC", "$@1",
  "partie_gauch_affectation", "ENSIDF_dec", "EXPRE", "CONDIT", "EXPREt",
  "TERM", "FACTOR", "OPERAND", "ENSpara", "TAILLE", "LOGI", "IDFS",
  "ENSIDF", "INSTS", "ENSINST", "INST", "eqival_statement",
  "ens_list_vars", "ens_list_var", "list_var", "var", "if_statement",
  "B_if", "A_if", "else_clause", "assignment", "valeur", "read_statement",
  "write_statement", "ENS_PARA_WRITE", "dowhile_statement", "B_while",
  "A_while", "CONDI", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    58,    57,    57,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    81,    82,    83,    83,    84,    85,    85,    86,
      87,    88,    88,    88,    88,    89,    90,    91,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     1,     1,     0,     2,     1,     4,
       3,     7,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     0,     6,     7,     2,     1,     4,     2,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     5,     3,     3,     1,     1,
       4,     3,     3,     4,     2,     1,     4,     1,     1,     5,
       5,     3,     3,     1,     1,     3,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    15,    14,    12,    13,     0,     0,     4,     5,     8,
       0,     0,     1,     0,     2,     7,    79,     0,     0,     0,
      97,     6,     0,    65,    71,     0,    66,     6,     0,    70,
      67,    68,    69,     0,     0,     0,     6,     0,     0,     0,
       0,     0,    74,     0,    73,    64,    70,     0,     0,    85,
       0,     0,    10,     0,    70,     0,     0,    16,     0,     6,
      17,    19,    46,    48,    49,     0,    56,    57,    87,     0,
      88,    30,    37,    40,    43,    45,     0,    47,    55,     0,
      93,    94,     0,    98,     0,     0,    78,    72,     0,     9,
       0,    84,    81,    82,    95,     0,     6,     6,     0,    62,
       0,    63,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,    83,    76,     0,     0,    86,    96,    61,
      59,     0,    58,     0,     0,    25,     0,    27,    20,     0,
       3,     0,     0,    44,    28,    29,    33,    34,    35,    36,
      31,    32,    38,    39,    41,    42,    54,    89,    90,    91,
      92,    77,     0,     6,     0,    24,     0,     0,     6,    50,
       0,    53,    75,    11,    60,     0,     0,    26,    51,     0,
       0,    22,    52,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    14,     6,    57,     8,     9,    10,    58,    59,
      60,    61,   136,   137,    98,    70,    71,    72,    73,    74,
      75,   170,    76,    77,   131,   132,   100,    22,    23,    24,
      43,    44,    85,    25,    26,    27,    28,    50,    54,    78,
      30,    31,    82,    32,    33,    34,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
      87,  -102,  -102,  -102,  -102,    39,    29,  -102,    87,  -102,
      50,    38,  -102,    46,  -102,  -102,    10,    22,    27,    32,
    -102,    35,    50,  -102,  -102,    51,  -102,    54,    63,    62,
    -102,  -102,  -102,    50,    48,    92,    87,     3,   126,     6,
      16,   126,  -102,   114,    89,  -102,   125,     3,    50,  -102,
      97,    50,  -102,    34,  -102,    16,    95,  -102,   135,    50,
      87,  -102,    98,  -102,  -102,   136,  -102,  -102,  -102,    16,
      18,    53,    47,    73,  -102,  -102,    68,  -102,  -102,    99,
    -102,  -102,    70,    18,   100,    72,  -102,  -102,   102,  -102,
     123,    50,  -102,    50,  -102,   103,   142,     4,    -2,  -102,
     127,    50,  -102,     3,   105,    25,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,  -102,     3,
     130,   132,     9,  -102,  -102,   126,   126,  -102,  -102,  -102,
    -102,   108,   109,     3,   110,  -102,   118,  -102,  -102,   152,
    -102,    74,     3,  -102,    53,    53,    47,    47,    47,    47,
      47,    47,    73,    73,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,    76,    87,   153,  -102,     3,   150,   154,  -102,
      78,  -102,  -102,  -102,  -102,    80,   141,  -102,  -102,     3,
     143,  -102,  -102,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,  -102,     0,  -102,   155,  -102,    33,    -3,
    -102,   104,  -102,    -6,  -102,   -26,    19,    -7,    13,    14,
    -102,  -102,  -101,  -102,  -102,  -102,  -102,   -13,   -21,  -102,
    -102,  -102,    40,   -34,  -102,  -102,  -102,  -102,    26,   -44,
    -102,  -102,  -102,  -102,  -102,  -102,   112
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -22
static const yytype_int16 yytable[] =
{
       7,    45,   141,    90,    79,    81,    62,    86,   133,    16,
      63,    64,    16,    65,    83,   134,   138,    66,    67,    62,
      53,    42,    68,    63,    64,    80,    65,    49,   159,    83,
      66,    67,    45,    11,    13,    91,    29,    16,    93,    12,
     -21,    11,   139,   105,    35,    69,   101,   106,    46,    36,
      17,    18,    37,    16,   106,    47,   107,    19,    69,    99,
      20,    94,    21,   107,    38,   175,    17,    18,   143,    39,
      45,    52,    45,    19,    40,   156,    20,    41,    21,    48,
      45,   114,   115,   108,   109,   110,   111,    51,   160,   165,
      55,   161,    86,   112,   113,    56,   130,   135,   171,     1,
       2,   146,   147,   148,   149,   150,   151,     3,     4,   116,
     117,   118,   119,   121,   122,   124,   125,   169,   119,   172,
     125,   178,   179,   180,   119,   144,   145,   152,   153,    16,
     154,   155,    87,    88,    89,   182,    92,    96,    97,   104,
     103,   127,   120,   123,   126,   129,   128,   142,   157,   140,
     158,   163,   166,   164,   167,   168,   174,   176,   133,   181,
     173,   183,   177,    15,   102,     0,   162,    95,   135
};

static const yytype_int16 yycheck[] =
{
       0,    22,   103,    47,    38,    39,     3,    41,     4,     3,
       7,     8,     3,    10,    40,    11,    18,    14,    15,     3,
      33,    21,    19,     7,     8,    19,    10,    27,    19,    55,
      14,    15,    53,     0,     5,    48,    10,     3,    51,     0,
      36,     8,    44,    69,     6,    42,    59,    29,    22,     3,
      16,    17,    42,     3,    29,     4,    38,    23,    42,    59,
      26,    27,    28,    38,    42,   166,    16,    17,    43,    42,
      91,     9,    93,    23,    42,   119,    26,    42,    28,    25,
     101,    34,    35,    30,    31,    32,    33,    24,   122,   133,
      42,   125,   126,    40,    41,     3,    96,    97,   142,    12,
      13,   108,   109,   110,   111,   112,   113,    20,    21,    36,
      37,    43,    44,    43,    44,    43,    44,    43,    44,    43,
      44,    43,    44,    43,    44,   106,   107,   114,   115,     3,
     116,   117,    18,    44,     9,   179,    39,    42,     3,     3,
      42,    18,    43,    43,    42,     3,    43,    42,    18,    22,
      18,    43,    42,    44,    36,     3,     3,     7,     4,    18,
     163,    18,   168,     8,    60,    -1,   126,    55,   168
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    20,    21,    47,    49,    50,    51,    52,
      53,    54,     0,     5,    48,    52,     3,    16,    17,    23,
      26,    28,    73,    74,    75,    79,    80,    81,    82,    84,
      86,    87,    89,    90,    91,     6,     3,    42,    42,    42,
      42,    42,    50,    76,    77,    74,    84,     4,    25,    50,
      83,    24,     9,    73,    84,    42,     3,    50,    54,    55,
      56,    57,     3,     7,     8,    10,    14,    15,    19,    42,
      61,    62,    63,    64,    65,    66,    68,    69,    85,    79,
      19,    79,    88,    61,    92,    78,    79,    18,    44,     9,
      85,    73,    39,    73,    27,    92,    42,     3,    60,    50,
      72,    73,    57,    42,     3,    61,    29,    38,    30,    31,
      32,    33,    40,    41,    34,    35,    36,    37,    43,    44,
      43,    43,    44,    43,    43,    44,    42,    18,    43,     3,
      50,    70,    71,     4,    11,    50,    58,    59,    18,    44,
      22,    68,    42,    43,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    65,    85,    18,    18,    19,
      79,    79,    78,    43,    44,    85,    42,    36,     3,    43,
      67,    85,    43,    55,     3,    68,     7,    59,    43,    44,
      43,    18,    85,    18
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
#line 61 "syntaxique.y"
    {YYACCEPT;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 72 "syntaxique.y"
    {
        if(strcmp((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str))!=0){
            yyerror("Sementique error",(yyvsp[(3) - (4)].str),"est different du nom de la fonction.");
        }
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 77 "syntaxique.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str))!=0){
            yyerror("Sementique error",(yyvsp[(2) - (3)].str),"est different du nom de la fonction.");
        }
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 85 "syntaxique.y"
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
#line 130 "syntaxique.y"
    {printf("the dcr idf is :%s\n",(yyvsp[(2) - (2)].str));if(Declarer((yyvsp[(2) - (2)].str))){

        yyerror("Sementique error",(yyvsp[(2) - (2)].str),"est deja declare.");
    };}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 134 "syntaxique.y"
    {if(Declarer((yyvsp[(2) - (7)].str))){
        yyerror("Sementique error",(yyvsp[(2) - (7)].str),"est deja declare.");}
        rechercher((yyvsp[(2) - (7)].str),"IDF","TABLEAU",0,0,(yyvsp[(5) - (7)].str),0);
        initiali_tab((yyvsp[(2) - (7)].str),(yyvsp[(5) - (7)].str));

        char *tab_taille =(yyvsp[(5) - (7)].str);
        char *tab_name=(yyvsp[(2) - (7)].str);

        if (strstr(tab_taille,",")!=NULL){
            char *token = strtok(tab_taille, ",");
            while (token != NULL) {
                StackNode* operande_tmp = pop(&Operandes_pile);
                quadr("Bounds", "0", strdup(operande_tmp->operande_name), "vide");
                token = strtok(NULL, ",");
            }
        }else{
            StackNode* operande_tmp = pop(&Operandes_pile);
            quadr("Bounds", "0", strdup(operande_tmp->operande_name), "vide");
        }

        quadr("ADEC", tab_name, "vide", "vide");
          // <==*   9ader n remplasiw taille b ENSpara_arith chhi lazem expr ma tmedlekch real tema lazem difinit expr spesial mafihach les real wela nkhalou lewla w f semantique ndirouh ma y acceptich les real ==>en fin dert deuxieme bah ndirha kima C resultat 3adi real chahi ida kan real l compilateur wa7dou yrodo int w maydirch erreur 
        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 158 "syntaxique.y"
    {(yyval.str)=(yyvsp[(2) - (2)].str);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 158 "syntaxique.y"
    { (yyval.str)=" ";;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 160 "syntaxique.y"
    {
    if(Declarer((yyvsp[(3) - (4)].str))){
        yyerror("Sementique error",(yyvsp[(3) - (4)].str),"est deja declare.");
    }
    if(strcmp((yyvsp[(4) - (4)].str)," ")!=0){
        if (!areCompatible(GetTypeFromTS((yyvsp[(3) - (4)].str)), (yyvsp[(4) - (4)].str))) {
        yyerror("Sementique error","","incompatible type.");
    }
    printf("\n\n------------yes they are compatible for the assignment\n\n");

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

  case 27:

/* Line 1455 of yacc.c  */
#line 180 "syntaxique.y"
    {
    
    if(Declarer((yyvsp[(1) - (2)].str))){
        yyerror("Sementique error",(yyvsp[(1) - (2)].str),"est deja declare.");
    }

    if(strcmp((yyvsp[(2) - (2)].str)," ")!=0){
        if (!areCompatible(GetTypeFromTS((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str))) {
        yyerror("Sementique error","","incompatible type.");
    }
    printf("\n\n------------yes they are compatible for the assignment\n\n");

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

  case 28:

/* Line 1455 of yacc.c  */
#line 206 "syntaxique.y"
    {if (isBoolean((yyvsp[(1) - (3)].str)) && isBoolean((yyvsp[(3) - (3)].str))) {
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
    };}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 224 "syntaxique.y"
    {if (isBoolean((yyvsp[(1) - (3)].str)) && isBoolean((yyvsp[(3) - (3)].str))) {
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
    };}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 242 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPRE", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 249 "syntaxique.y"
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

  case 32:

/* Line 1455 of yacc.c  */
#line 265 "syntaxique.y"
    {   if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
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

  case 33:

/* Line 1455 of yacc.c  */
#line 280 "syntaxique.y"
    {   if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
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

  case 34:

/* Line 1455 of yacc.c  */
#line 294 "syntaxique.y"
    {   if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
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

  case 35:

/* Line 1455 of yacc.c  */
#line 309 "syntaxique.y"
    {   if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
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

  case 36:

/* Line 1455 of yacc.c  */
#line 324 "syntaxique.y"
    {   if (!canPerformArithmetic((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str))) {
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

  case 37:

/* Line 1455 of yacc.c  */
#line 339 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "CONDIT", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 346 "syntaxique.y"
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
        printf("\n\n------------res= %s\n\n",addEntities((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
        
        
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 370 "syntaxique.y"
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

  case 40:

/* Line 1455 of yacc.c  */
#line 393 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "EXPREt", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 400 "syntaxique.y"
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

  case 42:

/* Line 1455 of yacc.c  */
#line 421 "syntaxique.y"
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

  case 43:

/* Line 1455 of yacc.c  */
#line 447 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "TERM", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 455 "syntaxique.y"
    { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(2) - (3)].str);
        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 460 "syntaxique.y"
    { 
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "FACTOR", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 470 "syntaxique.y"
    {
            if(!Declarer((yyvsp[(1) - (1)].str))){
                yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");
            }
            char *res=strdup(GetValFromTS((yyvsp[(1) - (1)].str)));
            char *type=strdup(GetTypeFromTS((yyvsp[(1) - (1)].str)));// wela 9ader tejbed e type mel val b GetTypeFromVal mais ana seyiit nkhali koulech kima derna fel cour
            printf("\n\n------------val ta3 idf= %s\n\n",res);
            if ((res==NULL || strcmp(res," ")==0) && (strstr(type, "ARGUMENT") == NULL)){
                yyerror("Sementique error",(yyvsp[(1) - (1)].str),"n'a pas d'une valeur");
            } else{
                
                push(&Operandes_pile, "OPERAND", strdup((yyvsp[(1) - (1)].str)), type);
                (yyval.str)=strdup(res);
            }
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 485 "syntaxique.y"
    {
        push(&Operandes_pile, "OPERAND", (yyvsp[(1) - (1)].str), "LOGICAL");
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 490 "syntaxique.y"
    {
            char backToStr[20];
            sprintf(backToStr, "%d", (yyvsp[(1) - (1)].entier));
            printf("\npushed inti: %s \n", backToStr);
            push(&Operandes_pile, "OPERAND", backToStr, "INTEGER");
            push(&Operandes_pile, "OPERAND", backToStr, "INTEGER");
            (yyval.str)=strdup(backToStr);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 499 "syntaxique.y"
    {
            char backToStr[20];
            sprintf(backToStr, "%g", (yyvsp[(1) - (1)].reel));
            push(&Operandes_pile, "OPERAND", backToStr, "REAL");
            (yyval.str)=strdup(backToStr);
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 506 "syntaxique.y"
    {{if(!Declarer((yyvsp[(1) - (4)].str))){
        yyerror("Sementique error",(yyvsp[(1) - (4)].str),"est non declare.");      
        }}if(!verifier_in_out_table((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str)))yyerror("Sementique error","","out of rang"); 
        //strcpy(taille,$3);
        char table[100];

        char *tab_taille =(yyvsp[(3) - (4)].str);
        printf("\n-----------------------------------------taille:%s\n",tab_taille);
        
        char final_str[40] = "" ;
        if (strstr(tab_taille,",")!=NULL){
            char *token = strtok(tab_taille, ",");
            while (token != NULL) {
                StackNode* operande_tmp = pop(&Operandes_pile);
                sprintf(final_str, "%s,%s",  operande_tmp->operande_name,final_str);
                token = strtok(NULL, ",");
            }
        }else{
            StackNode* operande_tmp = pop(&Operandes_pile);
            strcpy(final_str,operande_tmp->operande_name);
        }
        sprintf(table, "%s(%s)", (yyvsp[(1) - (4)].str), final_str);
        push(&Operandes_pile, "OPERAND", table, GetTypeFromTS((yyvsp[(1) - (4)].str)));
        (yyval.str)=return_val_tab((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 531 "syntaxique.y"
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
        char *tab_taille =(yyvsp[(4) - (5)].str);
        printf("\n-----------------------------------------taille:%s\n",tab_taille);
        
        char final_str[40] = "" ;
        if (strstr(tab_taille,",")!=NULL){
            char *token = strtok(tab_taille, ",");
            while (token != NULL) {
                StackNode* operande_tmp = pop(&Operandes_pile);
                sprintf(final_str, "%s,%s",  operande_tmp->operande_name,final_str);
                token = strtok(NULL, ",");
            }
        }else{
            StackNode* operande_tmp = pop(&Operandes_pile);
            strcpy(final_str,operande_tmp->operande_name);
        }
        char fonct[100];
        sprintf(fonct, "%s(%s)", (yyvsp[(2) - (5)].str), final_str);
        push(&Operandes_pile, "OPERAND", fonct, GetTypeFromTS((yyvsp[(2) - (5)].str)));

        (yyval.str)=return_val_fonction((yyvsp[(2) - (5)].str));nb_argument=0;
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 579 "syntaxique.y"
    {
        StackNode* operande_tmp = pop(&Operandes_pile);
        char* final_str = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 4 + 1);
        sprintf(final_str, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str)=final_str;
        nb_argument++;
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 586 "syntaxique.y"
    {
        StackNode* operande_tmp = pop(&Operandes_pile);
        (yyval.str)=(yyvsp[(1) - (1)].str);
        nb_argument++;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 592 "syntaxique.y"
    {
        if(!isInteger((yyvsp[(3) - (3)].str))){
            yyerror("Sementique error",(yyvsp[(3) - (3)].str),"n'est pas un entier");
        }
        if(strtol((yyvsp[(3) - (3)].str), NULL, 10)<0){
            yyerror("Sementique error",(yyvsp[(3) - (3)].str),"est negative");
        }
        
        char* final_str = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 4 + 1);
        sprintf(final_str, "%s,%s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str)=final_str;
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 604 "syntaxique.y"
    {
        if(!isInteger((yyvsp[(1) - (1)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"n'est pas un entier");
        }
        if(strtol((yyvsp[(1) - (1)].str), NULL, 10)<0){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est negative");
        }
        
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 615 "syntaxique.y"
    {(yyval.str)=strdup("true");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 616 "syntaxique.y"
    {(yyval.str)=strdup("false");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 620 "syntaxique.y"
    {Declarer((yyvsp[(3) - (3)].str));nb_argument++;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 620 "syntaxique.y"
    {Declarer((yyvsp[(1) - (1)].str));nb_argument++;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 637 "syntaxique.y"
    {
        if(!Declarer((yyvsp[(1) - (1)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");
            (yyval.str)=(yyvsp[(1) - (1)].str);
        }
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 643 "syntaxique.y"
    {if(!Declarer((yyvsp[(1) - (4)].str))){
            yyerror("Sementique error",(yyvsp[(1) - (4)].str),"est non declare."); 
        }
        if(!verifier_in_out_table((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str)))
            yyerror("Sementique error","","out of rang"); 

        char *tab_taille =(yyvsp[(3) - (4)].str);

        if (strstr(tab_taille,",")!=NULL){
            char *token = strtok(tab_taille, ",");
            while (token != NULL) {
                StackNode* operande_tmp = pop(&Operandes_pile);
                token = strtok(NULL, ",");
            }
        }else{
            StackNode* operande_tmp = pop(&Operandes_pile);
        }
        

        (yyval.str)=(yyvsp[(1) - (4)].str);
        strcpy(taille,(yyvsp[(3) - (4)].str));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 666 "syntaxique.y"
    {
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_if),1,tmp);
    printf("pgm juste");
;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 672 "syntaxique.y"
    {
    // Fin_if=qc;
    push_int(&Fin_if, qc);
    quadr("BR", "","vide", "vide");
    sprintf(tmp,"%d",qc); // transformer entier vers string
    ajour_quad(pop_int(&deb_else),1,tmp);
;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 680 "syntaxique.y"
    {
    // deb_else=qc; // J'ai laisser le champs 2 vide. Je dois le remplir apres
    push_int(&deb_else, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 689 "syntaxique.y"
    {   if (!areCompatible(GetTypeFromTS((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].str))) {
                                        yyerror("Sementique error","","incompatible type.");
                                    }
                                    printf("\n\n------------yes they are compatible for the assignment\n\n");
                                    
                                    StackNode* poppedElement ;
                                    char* final_str;
                                    if(strstr(GetTypeFromTS((yyvsp[(1) - (4)].str)),"TABLEAU")!=NULL){
                                        A_M_tab((yyvsp[(1) - (4)].str), taille, (yyvsp[(3) - (4)].str));
                                        char table[100];

                                        StackNode* poppedElement_var = pop(&Operandes_pile);
                                        printf("\n-----------------------------------------taille0:%s\n",taille);
                                        char *tab_taille =strdup(taille);
                                        printf("\n-----------------------------------------taille1:%s\n",tab_taille);
                                        
                                        // Format and store the combined string in str3
                                        if (strstr(tab_taille,",")!=NULL){
                                            printf("\ndkhalna l if lazen taille fiha virgul: %s \n", tab_taille);
                                            char *token = strtok(tab_taille, ",");
                                            while (token != NULL) {
                
                                                StackNode* operande_tmp = pop(&Operandes_pile);
                                                sprintf(final_str, "%s,%s",operande_tmp->operande_name,final_str);
                                                token = strtok(NULL, ",");
                                            }
                                        }else{
                                            printf("\ndkhalna l else lazen taille mafihach virgul: %s \n", taille);
                                            StackNode* operande_tmp = pop(&Operandes_pile);
                                            printf("\npoped str2: %s \n",operande_tmp->operande_name);
                                            printf("\nbefore strdup\n");
                                            final_str=strdup(operande_tmp->operande_name);
                                            printf("\nfinal str2: %s \n", final_str);
                                        }
                                        printf("\nfinal str3: %s \n", final_str);
                                        sprintf(table, "%s(%s)", (yyvsp[(1) - (4)].str), final_str);
                                        printf("\nfinal str2: %s \n", final_str);
                                        quadr("=", poppedElement_var->operande_name,"vide", table);
                                    }else {
                                        if (!SetValInTS((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str))){
                                            yyerror("Sementique error",(yyvsp[(1) - (4)].str),",affectation non accepte.");
                                        }else{
                                            poppedElement = pop(&Operandes_pile);
                                            quadr("=", poppedElement->operande_name,"vide", (yyvsp[(1) - (4)].str));
                                        }
                                    }
        (yyval.str)=(yyvsp[(1) - (4)].str);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 739 "syntaxique.y"
    {
        push(&Operandes_pile, "valeur", (yyvsp[(1) - (1)].str), "CHARACTER");
        (yyval.str)=strdup(GetValFromTS((yyvsp[(1) - (1)].str)));
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 743 "syntaxique.y"
    {
        StackNode* poppedElement = pop(&Operandes_pile);
        push(&Operandes_pile, "valeur", poppedElement->operande_name, poppedElement->operande_type);
        (yyval.str)=(yyvsp[(1) - (1)].str);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 755 "syntaxique.y"
    {
    sprintf(tmp,"%d",pop_int(&deb_while));
    quadr("BR", tmp,"vide", "vide");
    sprintf(tmp,"%d",qc);
    ajour_quad(pop_int(&Fin_while),1,tmp);
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 762 "syntaxique.y"
    {
    push_int(&Fin_while, qc);
    StackNode* operande_tmp = pop(&Operandes_pile);
    quadr("BZ", "",strdup(operande_tmp->operande_name), "vide");
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 768 "syntaxique.y"
    {
    push_int(&deb_while, qc);
;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 772 "syntaxique.y"
    {if (isBoolean((yyvsp[(1) - (1)].str))) {
        (yyval.str)=(yyvsp[(1) - (1)].str);
    }
    else {
        yyerror("Sementique error",(yyvsp[(1) - (1)].str),"is not boolean");
    };}
    break;



/* Line 1455 of yacc.c  */
#line 2520 "syntaxique.tab.c"
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
#line 780 "syntaxique.y"


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
    yyparse();
    yylex();
    afficher();
    afficher_qdr();
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    
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

