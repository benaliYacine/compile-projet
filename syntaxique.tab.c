
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
    #include "ts_HASH_TABLE.h"
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    char* tmp;
    int k;
    int nb_argument=0;



/* Line 189 of yacc.c  */
#line 88 "syntaxique.tab.c"

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
#line 15 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 214 of yacc.c  */
#line 177 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "syntaxique.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

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
      33,    43,    45,    47,    49,    51,    53,    55,    58,    60,
      64,    65,    72,    80,    83,    85,    90,    93,    97,    99,
     103,   107,   109,   113,   117,   119,   123,   125,   127,   129,
     131,   133,   138,   144,   148,   150,   152,   154,   156,   158,
     162,   164,   166,   168,   171,   173,   175,   177,   179,   181,
     183,   185,   189,   191,   193,   199,   203,   207,   209,   211,
     216,   225,   228,   229,   234,   236,   238,   244,   250,   254,
     258,   260,   262,   269,   273,   277,   279,   283,   285,   286,
     290,   294,   298,   302,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    49,    48,    -1,     5,     3,    54,    69,
      22,    -1,    50,    -1,    51,    -1,    -1,    51,    52,    -1,
      52,    -1,    53,     6,     3,    42,    67,    43,    54,    70,
      79,     9,    -1,    53,     6,     3,    42,    67,    43,    54,
      79,     9,    -1,    20,    -1,    21,    -1,    13,    -1,    12,
      -1,    50,    -1,    55,    -1,    55,    56,    -1,    56,    -1,
      53,    59,    18,    -1,    -1,    53,     3,    57,    36,     7,
      18,    -1,    53,     3,    11,    42,    60,    43,    18,    -1,
       4,    80,    -1,    50,    -1,    59,    44,     3,    58,    -1,
       3,    58,    -1,    60,    44,     7,    -1,     7,    -1,    61,
      34,    62,    -1,    61,    35,    62,    -1,    62,    -1,    62,
      36,    63,    -1,    62,    37,    63,    -1,    63,    -1,    42,
      61,    43,    -1,    64,    -1,     3,    -1,    66,    -1,     7,
      -1,     8,    -1,     3,    42,    60,    43,    -1,    10,     3,
      42,    65,    43,    -1,    65,    44,    80,    -1,    80,    -1,
      14,    -1,    15,    -1,    68,    -1,    50,    -1,    68,    44,
       3,    -1,     3,    -1,    50,    -1,    70,    -1,    70,    71,
      -1,    71,    -1,    77,    -1,    81,    -1,    82,    -1,    84,
      -1,    79,    -1,    72,    -1,    28,    73,    18,    -1,    74,
      -1,    50,    -1,    74,    44,    42,    75,    43,    -1,    42,
      75,    43,    -1,    75,    44,    76,    -1,    76,    -1,     3,
      -1,     3,    42,    65,    43,    -1,    23,    42,    85,    43,
      24,    70,    78,    39,    -1,    25,    70,    -1,    -1,    76,
       4,    80,    18,    -1,    19,    -1,    61,    -1,    16,    42,
      76,    43,    18,    -1,    17,    42,    83,    43,    18,    -1,
      83,    44,    19,    -1,    83,    44,    76,    -1,    19,    -1,
      76,    -1,    26,    42,    85,    43,    70,    27,    -1,    85,
      29,    86,    -1,    85,    38,    86,    -1,    86,    -1,    42,
      85,    43,    -1,    87,    -1,    -1,    61,    40,    61,    -1,
      61,    41,    61,    -1,    61,    30,    61,    -1,    61,    31,
      61,    -1,    61,    32,    61,    -1,    61,    33,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    39,    41,    41,    43,    45,    45,    47,
      47,    49,    49,    49,    49,    51,    51,    53,    53,    55,
      55,    55,    59,    62,    62,    64,    71,    80,    93,   107,
     108,   109,   113,   114,   115,   119,   120,   124,   127,   128,
     129,   130,   133,   135,   135,   137,   138,   140,   140,   142,
     142,   144,   144,   146,   146,   148,   148,   148,   148,   148,
     148,   150,   152,   152,   154,   154,   156,   156,   158,   161,
     165,   167,   167,   169,   171,   172,   174,   176,   178,   178,
     178,   178,   180,   182,   182,   182,   184,   184,   184,   186,
     186,   186,   186,   186,   186
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
  "TYPE", "DECS", "ENSDEC", "DEC", "$@1", "partie_gauch_affectation",
  "ENSIDF_dec", "TAILLE", "EXPRE", "TERM", "FACTOR", "OPERAND", "ENSpara",
  "LOGI", "IDFS", "ENSIDF", "INSTS", "ENSINST", "INST", "eqival_statement",
  "ens_list_vars", "ens_list_var", "list_var", "var", "if_statement",
  "else_clause", "assignment", "valeur", "read_statement",
  "write_statement", "ENS_PARA_WRITE", "dowhile_statement", "CONDI",
  "CONDIT", "EXPLOGI", 0
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
      52,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      57,    56,    56,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    80,    80,    81,    82,    83,    83,
      83,    83,    84,    85,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     1,     1,     0,     2,     1,    10,
       9,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       0,     6,     7,     2,     1,     4,     2,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     5,     3,     3,     1,     1,     4,
       8,     2,     0,     4,     1,     1,     5,     5,     3,     3,
       1,     1,     6,     3,     3,     1,     3,     1,     0,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    14,    13,    11,    12,     0,     0,     4,     5,     8,
       0,     1,     0,     2,     7,     0,     6,     0,    15,     0,
       6,    16,    18,     6,     6,     0,    68,     0,     0,     0,
       0,     6,    51,     0,    52,    54,    60,     0,    55,    59,
      56,    57,    58,    17,    50,    48,     0,    47,     0,     0,
      24,     0,    26,    19,     0,     0,     0,     0,    88,    88,
       0,    63,     0,    62,     3,    53,     0,     6,     0,    37,
      39,    40,     0,    45,    46,    74,     0,    75,    31,    34,
      36,    38,    23,     0,     0,     6,     0,    44,     0,    80,
      81,     0,    88,     0,     0,    85,    87,     0,     0,    67,
      61,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,    25,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      88,     0,     0,    65,     0,     0,    73,     0,    59,     0,
       0,    35,    29,    30,    32,    33,     0,     0,    21,    43,
      76,    77,    78,    79,    86,    91,    92,    93,    94,    89,
      90,    83,    84,     0,     0,    66,     0,    59,    10,    41,
       0,    22,    27,    72,    82,    64,     9,    42,     0,     0,
      71,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    13,     6,    18,     8,     9,    19,    20,    21,
      22,    51,    52,    25,   113,    77,    78,    79,    80,    86,
      81,    46,    47,    33,    34,    35,    36,    62,    63,    98,
      37,    38,   179,    39,    87,    40,    41,    91,    42,    94,
      95,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
     105,  -100,  -100,  -100,  -100,    36,    33,  -100,   105,  -100,
      51,  -100,    64,  -100,  -100,    71,   105,    23,  -100,    73,
     112,   105,  -100,    75,     3,     9,    41,    60,    72,    74,
      78,    85,  -100,    63,   112,  -100,  -100,    58,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,    80,   101,    27,   125,
    -100,   123,  -100,  -100,   165,    27,   166,    10,     2,     2,
     166,  -100,   152,   129,  -100,  -100,    27,   105,   171,   133,
    -100,  -100,   173,  -100,  -100,  -100,    40,    37,    59,  -100,
    -100,  -100,  -100,   170,   172,   174,    57,  -100,   137,  -100,
    -100,    62,     2,   131,    20,  -100,  -100,    30,    67,  -100,
    -100,   139,   164,   112,  -100,   170,   141,   -15,    40,    40,
      40,    40,  -100,    88,   167,  -100,  -100,    27,   168,   169,
      12,   117,    32,    40,    40,    40,    40,    40,    40,     2,
       2,   160,   112,  -100,   166,   166,  -100,   112,   179,    90,
      27,  -100,    59,    59,  -100,  -100,   175,   182,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,    37,    37,    37,    37,    37,
      37,  -100,  -100,   112,    81,  -100,    93,   181,  -100,  -100,
      98,  -100,  -100,    96,  -100,  -100,  -100,  -100,   112,   153,
     112,  -100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,  -100,     1,  -100,   183,    52,   127,  -100,
     176,  -100,   110,  -100,    91,   -36,    35,    43,  -100,    61,
    -100,  -100,  -100,  -100,   -99,   -34,  -100,  -100,  -100,    65,
     -54,  -100,  -100,   -92,   -40,  -100,  -100,  -100,  -100,   -41,
      26,  -100
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      65,     7,    88,    90,   137,    69,    99,    48,    82,    70,
      71,   138,    72,    26,    49,    26,    73,    74,    97,   108,
     109,    32,    93,    93,    45,    50,   102,    53,   141,    89,
      69,   152,    61,   164,    70,    71,    11,    72,    12,   -20,
     107,    73,    74,    69,    92,   167,    75,    70,    71,   129,
      72,   122,    10,    54,    73,    74,   121,    15,   130,   129,
      10,   129,    66,   131,   173,    23,   153,    16,   130,    76,
     130,   108,   109,   132,    17,   154,    24,   149,    44,   180,
     165,    99,    76,    55,    26,    64,    50,   155,   156,   157,
     158,   159,   160,    93,    93,   110,   111,    27,    28,    26,
     116,   117,    56,    65,    29,   119,   120,    30,   174,    31,
     133,   134,    27,    28,    57,    26,    58,     1,     2,    29,
      59,   178,    30,    67,    31,     3,     4,    60,    27,    28,
      65,   146,   147,   169,   147,    29,   175,   134,    30,    65,
      31,   177,   117,   142,   143,    68,    65,   123,   124,   125,
     126,   108,   109,   144,   145,   161,   162,   127,   128,    84,
     141,   123,   124,   125,   126,   108,   109,    83,    85,    26,
     100,   127,   128,   101,   104,   105,   106,   112,    48,   114,
     118,   135,   136,   140,   163,   148,   150,   151,   168,   172,
     176,    14,   181,   171,   103,   115,   139,    43,     0,     0,
     166,   170
};

static const yytype_int16 yycheck[] =
{
      34,     0,    56,    57,   103,     3,    60,     4,    48,     7,
       8,   103,    10,     3,    11,     3,    14,    15,    59,    34,
      35,    20,    58,    59,    23,    24,    66,    18,    43,    19,
       3,    19,    31,   132,     7,     8,     0,    10,     5,    36,
      76,    14,    15,     3,    42,   137,    19,     7,     8,    29,
      10,    92,     0,    44,    14,    15,    92,     6,    38,    29,
       8,    29,     4,    43,   163,    42,   120,     3,    38,    42,
      38,    34,    35,    43,     3,    43,     3,   117,     3,   178,
     134,   135,    42,    42,     3,    22,    85,   123,   124,   125,
     126,   127,   128,   129,   130,    36,    37,    16,    17,     3,
      43,    44,    42,   137,    23,    43,    44,    26,    27,    28,
      43,    44,    16,    17,    42,     3,    42,    12,    13,    23,
      42,    25,    26,    43,    28,    20,    21,    42,    16,    17,
     164,    43,    44,    43,    44,    23,    43,    44,    26,   173,
      28,    43,    44,   108,   109,    44,   180,    30,    31,    32,
      33,    34,    35,   110,   111,   129,   130,    40,    41,    36,
      43,    30,    31,    32,    33,    34,    35,    42,     3,     3,
      18,    40,    41,    44,     3,    42,     3,     7,     4,     7,
      43,    42,    18,    42,    24,    18,    18,    18,     9,     7,
       9,     8,    39,    18,    67,    85,   105,    21,    -1,    -1,
     135,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    20,    21,    47,    49,    50,    51,    52,
      53,     0,     5,    48,    52,     6,     3,     3,    50,    53,
      54,    55,    56,    42,     3,    59,     3,    16,    17,    23,
      26,    28,    50,    69,    70,    71,    72,    76,    77,    79,
      81,    82,    84,    56,     3,    50,    67,    68,     4,    11,
      50,    57,    58,    18,    44,    42,    42,    42,    42,    42,
      42,    50,    73,    74,    22,    71,     4,    43,    44,     3,
       7,     8,    10,    14,    15,    19,    42,    61,    62,    63,
      64,    66,    80,    42,    36,     3,    65,    80,    76,    19,
      76,    83,    42,    61,    85,    86,    87,    85,    75,    76,
      18,    44,    80,    54,     3,    42,     3,    61,    34,    35,
      36,    37,     7,    60,     7,    58,    43,    44,    43,    43,
      44,    61,    85,    30,    31,    32,    33,    40,    41,    29,
      38,    43,    43,    43,    44,    42,    18,    70,    79,    60,
      42,    43,    62,    62,    63,    63,    43,    44,    18,    80,
      18,    18,    19,    76,    43,    61,    61,    61,    61,    61,
      61,    86,    86,    24,    70,    76,    75,    79,     9,    43,
      65,    18,     7,    70,    27,    43,     9,    43,    25,    78,
      70,    39
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
#line 37 "syntaxique.y"
    {YYACCEPT;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 47 "syntaxique.y"
    {inserer_fonction((yyvsp[(3) - (10)].str),nb_argument);nb_argument=0;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 47 "syntaxique.y"
    {inserer_fonction((yyvsp[(3) - (9)].str),nb_argument);nb_argument=0;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 55 "syntaxique.y"
    {if(Declarer((yyvsp[(2) - (2)].str))){
        Col-=2;
        yyerror("Sementique error",(yyvsp[(2) - (2)].str),"est deja declare.");
    };}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 59 "syntaxique.y"
    {if(Declarer((yyvsp[(2) - (7)].str))){
        yyerror("Sementique error",(yyvsp[(2) - (7)].str),"est deja declare.");}rechercher((yyvsp[(2) - (7)].str),"IDF","TABLEAU",0,0,(yyvsp[(5) - (7)].str),0);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 62 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(2) - (2)].reel);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 62 "syntaxique.y"
    { (yyval.reel)=0;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 64 "syntaxique.y"
    {
    if(Declarer((yyvsp[(3) - (4)].str))){
        Col-=2;
        yyerror("Sementique error",(yyvsp[(3) - (4)].str),"est deja declare.");
    }
    rechercher((yyvsp[(3) - (4)].str),"IDF"," ",(yyvsp[(4) - (4)].reel),0," ",0);
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 71 "syntaxique.y"
    {
    if(Declarer((yyvsp[(1) - (2)].str))){
        Col-=2;
        yyerror("Sementique error",(yyvsp[(1) - (2)].str),"est deja declare.");
        
    }
    rechercher((yyvsp[(1) - (2)].str),"IDF"," ",(yyvsp[(2) - (2)].reel),0," ",0);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 80 "syntaxique.y"
    {
                                char* str_inti;
                                // Allocate memory for str_inti
                                str_inti = malloc(12 * sizeof(char)); // 12 is an example size, adjust as needed

                                sprintf(str_inti, "%d", (yyvsp[(3) - (3)].entier));
                                // printf("----------------%s\n", str_inti);
                                
                                
                                char* final_str = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen(str_inti) + 4 + 1);
                                sprintf(final_str, "%s,%s", (yyvsp[(1) - (3)].str), str_inti);
                                (yyval.str)=final_str;
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 93 "syntaxique.y"
    {
                                char* str_inti;
                                // Allocate memory for str_inti
                                str_inti = malloc(12 * sizeof(char)); // 12 is an example size, adjust as needed

                                sprintf(str_inti, "%d", (yyvsp[(1) - (1)].entier));
                                // printf("----------------%s\n", str_inti);

                                (yyval.str)=str_inti;
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 107 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (3)].reel)+(yyvsp[(2) - (3)].reel);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 108 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (3)].reel)-(yyvsp[(2) - (3)].reel);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 109 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (1)].reel);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 113 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (3)].reel)*(yyvsp[(2) - (3)].reel);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 114 "syntaxique.y"
    {if((yyvsp[(3) - (3)].reel)==0){yyerror("Sementique error","","division sur zero.");}else (yyval.reel)=(yyvsp[(1) - (3)].reel)/(yyvsp[(2) - (3)].reel);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 115 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (1)].reel);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 119 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(2) - (3)].reel);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 120 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (1)].reel);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 124 "syntaxique.y"
    {{if(!Declarer((yyvsp[(1) - (1)].str))){
       yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");      
    }} (yyval.reel)=0;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 127 "syntaxique.y"
    { (yyval.reel)=0;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 128 "syntaxique.y"
    {(yyval.reel)=(float)(yyvsp[(1) - (1)].entier);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 129 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (1)].reel);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 130 "syntaxique.y"
    {{if(!Declarer((yyvsp[(1) - (4)].str))){
        yyerror("Sementique error",(yyvsp[(1) - (4)].str),"est non declare.");      
    }} (yyval.reel)=0;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 133 "syntaxique.y"
    {if(verifier_nb_argument((yyvsp[(2) - (5)].str),nb_argument)){yyerror("Sementique error","","le nombre d'argument est uncorrect.");}else {(yyval.reel)=0;nb_argument=0;};}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 135 "syntaxique.y"
    {nb_argument++;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 135 "syntaxique.y"
    {nb_argument++;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 142 "syntaxique.y"
    {Declarer((yyvsp[(3) - (3)].str));nb_argument++;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 142 "syntaxique.y"
    {Declarer((yyvsp[(1) - (1)].str));nb_argument++;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 158 "syntaxique.y"
    {if(!Declarer((yyvsp[(1) - (1)].str))){
        yyerror("Sementique error",(yyvsp[(1) - (1)].str),"est non declare.");      
    };}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 161 "syntaxique.y"
    {if(!Declarer((yyvsp[(1) - (4)].str))){
        yyerror("Sementique error",(yyvsp[(1) - (4)].str),"est non declare.");      
    };}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 171 "syntaxique.y"
    { (yyval.reel)=0;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 172 "syntaxique.y"
    {(yyval.reel)=(yyvsp[(1) - (1)].reel);;}
    break;



/* Line 1455 of yacc.c  */
#line 1832 "syntaxique.tab.c"
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
#line 188 "syntaxique.y"


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

