
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

    int nb_ligne=1, Col=1;


/* Line 189 of yacc.c  */
#line 78 "syntaxique.tab.c"

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
     cst = 259,
     aff = 260,
     mc_prgrm = 261,
     mc_rtin = 262,
     inti = 263,
     real = 264,
     mc_endr = 265,
     mc_call = 266,
     mc_dim = 267,
     mc_logi = 268,
     mc_char = 269,
     mc_true = 270,
     mc_false = 271,
     mc_read = 272,
     mc_write = 273,
     pvg = 274,
     str = 275,
     mc_int = 276,
     mc_real = 277,
     mc_end = 278,
     mc_if = 279,
     mc_then = 280,
     mc_else = 281,
     mc_dowhile = 282,
     mc_enddo = 283,
     mc_equival = 284,
     mc_or = 285,
     ge = 286,
     eq = 287,
     ne = 288,
     le = 289,
     add = 290,
     sub = 291,
     mul = 292,
     divi = 293,
     mc_and = 294,
     mc_endif = 295,
     lt = 296,
     gt = 297,
     po = 298,
     pf = 299,
     verg = 300,
     err = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 5 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 214 of yacc.c  */
#line 168 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 180 "syntaxique.tab.c"

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
<<<<<<< HEAD
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138
=======
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142
=======
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785

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
<<<<<<< HEAD
       0,     0,     3,     6,     8,    14,    17,    19,    33,    35,
      37,    39,    41,    44,    46,    50,    56,    64,    68,    70,
      74,    78,    80,    84,    88,    90,    94,    96,    98,   100,
     102,   104,   109,   115,   117,   119,   121,   125,   127,   130,
     132,   134,   136,   138,   140,   149,   152,   153,   159,   167,
     173,   180,   184,   188,   190,   194,   196,   200,   204,   209,
     213,   217,   221
=======
       0,     0,     3,    10,    16,    22,    28,    33,    38,    42,
      47,    62,    76,    78,    80,    82,    84,    93,   100,   105,
     109,   115,   123,   127,   129,   133,   137,   139,   143,   147,
     149,   153,   155,   157,   159,   161,   163,   168,   174,   176,
     178,   180,   184,   186,   188,   190,   192,   194,   196,   199,
     202,   205,   208,   211,   220,   223,   224,   229,   235,   243,
     249,   256,   260,   264,   266,   270,   272,   276,   280,   285,
     289,   293,   297
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
<<<<<<< HEAD
      48,     0,    -1,    50,    49,    -1,    49,    -1,     6,     3,
      53,    62,    23,    -1,    51,    50,    -1,    51,    -1,    52,
       7,     3,    43,    61,    44,    54,    62,     3,     5,     3,
      19,    10,    -1,    21,    -1,    22,    -1,    14,    -1,    13,
      -1,    54,    53,    -1,    54,    -1,    52,    61,    19,    -1,
      52,     3,    37,     8,    19,    -1,    52,     3,    12,    43,
      55,    44,    19,    -1,    45,     8,    55,    -1,     8,    -1,
      57,    35,    56,    -1,    57,    36,    56,    -1,    57,    -1,
      58,    37,    57,    -1,    58,    38,    57,    -1,    58,    -1,
      43,    56,    44,    -1,    59,    -1,     3,    -1,     8,    -1,
       9,    -1,    60,    -1,     3,    43,    55,    44,    -1,    11,
       3,    43,    61,    44,    -1,    20,    -1,    15,    -1,    16,
      -1,     3,    45,    61,    -1,     3,    -1,    63,    62,    -1,
      63,    -1,    64,    -1,    66,    -1,    67,    -1,    68,    -1,
      24,    43,    69,    44,    25,    62,    65,    40,    -1,    26,
      62,    -1,    -1,    17,    43,     3,    44,    19,    -1,    18,
      43,    20,    45,    61,    44,    19,    -1,    18,    43,    20,
      44,    19,    -1,    27,    43,    69,    44,    62,    28,    -1,
      70,    30,    69,    -1,    70,    39,    69,    -1,    70,    -1,
      43,    69,    44,    -1,    71,    -1,    56,    41,    56,    -1,
      56,    42,    56,    -1,    56,     5,     5,    56,    -1,    56,
      31,    56,    -1,    56,    32,    56,    -1,    56,    33,    56,
      -1,    56,    34,    56,    -1
=======
      48,     0,    -1,    49,     6,     3,    51,    59,    23,    -1,
      49,     6,     3,    51,    23,    -1,    49,     6,     3,    59,
      23,    -1,     6,     3,    51,    59,    23,    -1,     6,     3,
      51,    23,    -1,     6,     3,    59,    23,    -1,     6,     3,
      23,    -1,    49,     6,     3,    23,    -1,    49,    50,     7,
       3,    43,    58,    44,    51,    59,     3,     5,     3,    19,
      10,    -1,    50,     7,     3,    43,    58,    44,    51,    59,
       3,     5,     3,    19,    10,    -1,    21,    -1,    22,    -1,
      14,    -1,    13,    -1,    50,     3,    12,    43,    52,    44,
      19,    51,    -1,    50,     3,    37,     8,    19,    51,    -1,
      50,    58,    19,    51,    -1,    50,    58,    19,    -1,    50,
       3,    37,     8,    19,    -1,    50,     3,    12,    43,    52,
      44,    19,    -1,    52,    45,     8,    -1,     8,    -1,    53,
      35,    54,    -1,    53,    36,    54,    -1,    54,    -1,    54,
      37,    55,    -1,    54,    38,    55,    -1,    55,    -1,    43,
      53,    44,    -1,    56,    -1,     3,    -1,     8,    -1,     9,
      -1,    57,    -1,     3,    43,    52,    44,    -1,    11,     3,
      43,    58,    44,    -1,    20,    -1,    15,    -1,    16,    -1,
      58,    45,     3,    -1,     3,    -1,    60,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    60,    59,    -1,    62,
      59,    -1,    63,    59,    -1,    64,    59,    -1,    65,    59,
      -1,    24,    43,    66,    44,    25,    59,    61,    40,    -1,
      26,    59,    -1,    -1,     3,     5,    53,    19,    -1,    17,
      43,     3,    44,    19,    -1,    18,    43,    20,    45,    58,
      44,    19,    -1,    18,    43,    20,    44,    19,    -1,    27,
      43,    66,    44,    59,    28,    -1,    66,    30,    67,    -1,
      66,    39,    67,    -1,    67,    -1,    43,    66,    44,    -1,
      68,    -1,    53,    41,    53,    -1,    53,    42,    53,    -1,
      53,     5,     5,    53,    -1,    53,    31,    53,    -1,    53,
      32,    53,    -1,    53,    33,    53,    -1,    53,    34,    53,
      -1
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
<<<<<<< HEAD
       0,    13,    13,    13,    15,    17,    17,    19,    21,    21,
      21,    21,    23,    23,    25,    25,    25,    27,    27,    29,
      29,    29,    31,    31,    31,    33,    33,    35,    35,    35,
      35,    35,    35,    35,    37,    37,    39,    39,    41,    41,
      43,    43,    43,    43,    45,    47,    47,    50,    52,    52,
      54,    56,    56,    56,    58,    58,    60,    60,    60,    60,
      60,    60,    60
=======
       0,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      15,    15,    17,    17,    17,    17,    19,    19,    19,    19,
      19,    19,    21,    21,    23,    23,    23,    25,    25,    25,
      27,    27,    29,    29,    29,    29,    29,    29,    29,    31,
      31,    33,    33,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    37,    39,    39,    41,    43,    45,    45,
      47,    49,    49,    49,    51,    51,    53,    53,    53,    53,
      53,    53,    53
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "idf", "cst", "aff", "mc_prgrm",
  "mc_rtin", "inti", "real", "mc_endr", "mc_call", "mc_dim", "mc_logi",
  "mc_char", "mc_true", "mc_false", "mc_read", "mc_write", "pvg", "str",
  "mc_int", "mc_real", "mc_end", "mc_if", "mc_then", "mc_else",
  "mc_dowhile", "mc_enddo", "mc_equival", "mc_or", "ge", "eq", "ne", "le",
  "add", "sub", "mul", "divi", "mc_and", "mc_endif", "lt", "gt", "po",
  "pf", "verg", "err", "$accept", "s", "PRGM_PRIN", "ENSFCT", "FCT",
  "TYPE", "ENSDEC", "DEC", "TAILLE", "EXPRE", "EXPRET", "EXPREF", "EXPREI",
  "LOGI", "ENSIDF", "ENSINST", "INST", "if_statement", "else_clause",
  "read_statement", "write_statement", "dowhile_statement", "CONDI",
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    47,    48,    48,    49,    50,    50,    51,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    65,    65,    66,    67,    67,
      68,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71
=======
       0,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      49,    49,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    53,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    61,    61,    62,    63,    64,    64,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
<<<<<<< HEAD
       0,     2,     2,     1,     5,     2,     1,    13,     1,     1,
       1,     1,     2,     1,     3,     5,     7,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     8,     2,     0,     5,     7,     5,
=======
       0,     2,     6,     5,     5,     5,     4,     4,     3,     4,
      14,    13,     1,     1,     1,     1,     8,     6,     4,     3,
       5,     7,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     8,     2,     0,     4,     5,     7,     5,
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
       6,     3,     3,     1,     3,     1,     3,     3,     4,     3,
       3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
       0,     0,    11,    10,     8,     9,     0,     3,     0,     6,
       0,     0,     1,     2,     5,     0,     0,     0,    13,     0,
      37,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    12,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     4,    38,    37,     0,     0,     0,    36,     0,
       0,    27,    28,    29,     0,    34,    35,    33,     0,     0,
      21,    24,    26,    30,     0,    53,    55,     0,     0,    18,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    49,
       0,     0,     0,    25,    54,     0,     0,    59,    60,    61,
      62,    56,    57,    19,    20,    22,    23,     0,    51,    52,
       0,     0,    17,    16,     0,    31,     0,    58,     0,    46,
      50,     0,    48,    32,     0,     0,     0,    45,    44,     0,
       0,     7
=======
       0,     0,    15,    14,    12,    13,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     6,     0,
       7,    48,    49,    50,    51,    52,     9,     0,     0,     0,
       0,    32,    33,    34,     0,    39,    40,    38,     0,     0,
      26,    29,    31,    35,     0,     0,     0,     0,     0,    63,
      65,     0,     0,     0,    19,     0,     5,     3,     0,     4,
       0,    42,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      41,     2,     0,     0,    23,     0,     0,    30,    24,    25,
      27,    28,    57,    59,     0,    64,     0,    69,    70,    71,
      72,    66,    67,    61,    62,     0,     0,     0,    20,     0,
       0,    36,     0,     0,     0,    68,    55,    60,     0,    17,
       0,     0,    22,    37,    58,     0,     0,    21,     0,     0,
      54,    53,    16,     0,     0,     0,     0,     0,     0,     0,
      11,    10
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
<<<<<<< HEAD
      -1,     6,     7,     8,     9,    16,    17,    18,    71,    59,
      60,    61,    62,    63,    21,    26,    27,    28,   135,    29,
      30,    31,    64,    65,    66
=======
      -1,     6,     7,    20,    21,   115,    67,    60,    61,    62,
      63,    37,    22,    23,   156,    24,    25,    26,    27,    68,
      69,    70
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
<<<<<<< HEAD
#define YYPACT_NINF -62
static const yytype_int16 yypact[] =
{
      65,     3,   -62,   -62,   -62,   -62,     8,   -62,    53,    80,
      17,    80,   -62,   -62,   -62,    44,    60,    71,    80,    23,
      -3,    57,    34,    37,    38,    48,    61,    71,   -62,   -62,
     -62,   -62,   -62,    93,    54,    91,    93,   -62,    97,    83,
       2,     2,   -62,   -62,    59,    62,    -1,    86,   -62,    64,
     -24,    66,   -62,   -62,   107,   -62,   -62,   -62,     2,     7,
       1,    18,   -62,   -62,    67,   -16,   -62,    68,    80,   -62,
     105,    70,   -62,    96,    98,    93,    -1,    73,    41,    74,
     114,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    95,     2,     2,    71,    71,    -1,   102,   -62,   -62,
      78,    79,    93,   -62,   -62,    49,    49,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    71,   -62,   -62,
      99,   121,   -62,   -62,   106,   -62,    82,   -62,    84,   103,
     -62,   125,   -62,   -62,    71,    92,   128,   -62,   -62,   115,
     123,   -62
=======
#define YYPACT_NINF -37
static const yytype_int16 yypact[] =
{
     147,    10,   -37,   -37,   -37,   -37,    34,   151,    14,    45,
     -37,    36,    46,    57,    60,    30,    53,   -37,    58,    67,
     103,    28,    76,    91,    91,    91,    91,    91,   124,   117,
      85,     7,   130,   116,    21,    21,     5,    -7,   -37,   129,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   132,   131,   115,
     173,   144,   -37,   -37,   185,   -37,   -37,   -37,     7,    35,
      44,   -37,   -37,   -37,   145,    39,    21,    90,   -19,   -37,
     -37,   -11,   148,   182,   149,   189,   -37,   -37,   170,   -37,
     173,   -37,    72,   186,   152,    69,   -37,     7,     7,     7,
       7,   177,   178,   173,    56,    63,   193,     7,     7,     7,
       7,     7,     7,    21,    21,   174,    91,   186,   181,   -37,
     -37,   -37,    95,   149,   -37,    99,   173,   -37,    44,    44,
     -37,   -37,   -37,   -37,   122,   -37,     7,   139,   139,   139,
     139,   139,   139,   -37,   -37,    91,   175,   133,   149,   149,
      91,   -37,   194,   135,   187,   139,   179,   -37,   188,   -37,
      91,   198,   -37,   -37,   -37,    91,   164,   149,   205,   204,
     -37,   -37,   -37,   206,   207,   209,   195,   196,   203,   208,
     -37,   -37
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
     -62,   -62,   127,   129,   -62,    16,   118,    69,   -61,   -55,
     -28,   -62,   -62,   -62,   -32,   -27,   -62,   -62,   -62,   -62,
     -62,   -62,   -39,   -62,   -62
=======
     -37,   -37,   -37,    49,   -27,   109,   -23,    94,    96,   -37,
     -37,   -36,   -21,   -37,   -37,   -37,   -37,   -37,   -37,   -26,
      80,   -37
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      43,    45,    67,    78,    48,    51,    11,    69,    12,    34,
      52,    53,    80,    54,    92,   101,    10,    55,    56,    79,
      74,    75,    57,    93,    15,    10,   107,   108,   109,   110,
     111,   112,   113,   114,    35,   122,    87,    88,    81,    82,
      83,    84,    36,   100,    70,    58,    80,    19,    85,    86,
     127,   128,    51,   118,   119,    89,    90,    52,    53,     1,
      54,   115,   116,    20,    55,    56,    33,   120,   121,    57,
     126,     1,    81,    82,    83,    84,    37,    38,     2,     3,
      39,    40,    85,    86,    42,   103,     4,     5,    22,    23,
     129,    41,   106,     2,     3,    24,    44,    46,    25,    47,
      49,     4,     5,    50,    36,    72,    68,   137,    73,    76,
      77,    91,    94,    96,    97,    98,   102,    99,   104,   105,
     117,   123,   124,   125,   131,   132,   133,   130,   103,   134,
     136,   139,   138,   141,   140,    13,    32,    95,    14
=======
      39,    47,    41,    42,    43,    44,    45,    48,    59,    71,
      51,   103,    74,     9,    82,    52,    53,    72,    54,   103,
     104,    13,    55,    56,    51,   105,    78,    57,   104,    52,
      53,    14,    54,   106,    10,    85,    55,    56,    75,    28,
      95,    57,    73,    94,   112,    15,    16,   109,    14,     8,
      58,    38,    18,    29,    86,    19,    12,   124,     2,     3,
      30,    96,    15,    16,    66,    31,     4,     5,    17,    18,
      87,    88,    19,    32,   127,   128,   129,   130,   131,   132,
     143,    89,    90,    92,    93,   136,   140,    97,    98,    99,
     100,    87,    88,   103,    14,    96,    33,   101,   102,    40,
     117,    34,   104,   145,    87,    88,    36,   125,    15,    16,
      35,   149,   150,   117,   146,    18,   113,    75,    19,   151,
      49,    97,    98,    99,   100,    87,    88,    14,    50,   158,
     162,   101,   102,    64,   160,    14,    65,     2,     3,   139,
      75,    15,    16,   141,   142,     4,     5,    46,    18,    15,
      16,    19,    76,     1,    79,    77,    18,    11,    80,    19,
       2,     3,     2,     3,     2,     3,   144,    75,     4,     5,
       4,     5,     4,     5,    87,    88,    81,   148,   142,   153,
      75,   118,   119,   133,   134,   120,   121,    83,    84,    91,
     108,   107,   110,   111,   114,   116,   122,   123,   126,   135,
     138,   159,   152,   147,   161,   155,   154,   157,   163,   164,
     166,   165,   167,   170,   168,   169,   137,     0,   171
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

static const yytype_uint8 yycheck[] =
{
<<<<<<< HEAD
      27,    33,    41,    58,    36,     3,     3,     8,     0,    12,
       8,     9,     5,    11,    30,    76,     0,    15,    16,    58,
      44,    45,    20,    39,     7,     9,    81,    82,    83,    84,
      85,    86,    87,    88,    37,    96,    35,    36,    31,    32,
      33,    34,    45,    75,    45,    43,     5,     3,    41,    42,
     105,   106,     3,    92,    93,    37,    38,     8,     9,     6,
      11,    89,    90,     3,    15,    16,    43,    94,    95,    20,
     102,     6,    31,    32,    33,    34,    19,    43,    13,    14,
      43,    43,    41,    42,    23,    44,    21,    22,    17,    18,
     117,    43,    43,    13,    14,    24,     3,    43,    27,     8,
       3,    21,    22,    20,    45,    19,    44,   134,    44,    43,
       3,    44,    44,     8,    44,    19,    43,    19,    44,     5,
      25,    19,    44,    44,     3,    19,    44,    28,    44,    26,
       5,     3,    40,    10,    19,     8,    18,    68,     9
=======
      21,    28,    23,    24,    25,    26,    27,    28,    31,    35,
       3,    30,    19,     3,    50,     8,     9,    12,    11,    30,
      39,     7,    15,    16,     3,    44,    47,    20,    39,     8,
       9,     3,    11,    44,     0,    58,    15,    16,    45,     3,
      66,    20,    37,    66,    80,    17,    18,    74,     3,     0,
      43,    23,    24,     7,    19,    27,     7,    93,    13,    14,
       3,     5,    17,    18,    43,     5,    21,    22,    23,    24,
      35,    36,    27,    43,    97,    98,    99,   100,   101,   102,
     116,    37,    38,    44,    45,   106,   113,    31,    32,    33,
      34,    35,    36,    30,     3,     5,    43,    41,    42,    23,
      44,    43,    39,   126,    35,    36,     3,    44,    17,    18,
      43,   138,   139,    44,   135,    24,    44,    45,    27,   140,
       3,    31,    32,    33,    34,    35,    36,     3,    43,   150,
     157,    41,    42,     3,   155,     3,    20,    13,    14,    44,
      45,    17,    18,    44,    45,    21,    22,    23,    24,    17,
      18,    27,    23,     6,    23,    23,    24,     6,    43,    27,
      13,    14,    13,    14,    13,    14,    44,    45,    21,    22,
      21,    22,    21,    22,    35,    36,     3,    44,    45,    44,
      45,    87,    88,   103,   104,    89,    90,    43,     3,    44,
       8,    43,     3,    23,     8,    43,    19,    19,     5,    25,
      19,     3,     8,    28,    40,    26,    19,    19,     3,     5,
       3,     5,     3,    10,    19,    19,   107,    -1,    10
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,     6,    13,    14,    21,    22,    48,    49,    50,    51,
      52,     3,     0,    49,    50,     7,    52,    53,    54,     3,
       3,    61,    17,    18,    24,    27,    62,    63,    64,    66,
      67,    68,    53,    43,    12,    37,    45,    19,    43,    43,
      43,    43,    23,    62,     3,    61,    43,     8,    61,     3,
      20,     3,     8,     9,    11,    15,    16,    20,    43,    56,
      57,    58,    59,    60,    69,    70,    71,    69,    44,     8,
      45,    55,    19,    44,    44,    45,    43,     3,    56,    69,
       5,    31,    32,    33,    34,    41,    42,    35,    36,    37,
      38,    44,    30,    39,    44,    54,     8,    44,    19,    19,
      61,    55,    43,    44,    44,     5,    43,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    25,    69,    69,
      62,    62,    55,    19,    44,    44,    61,    56,    56,    62,
      28,     3,    19,    44,    26,    65,     5,    62,    40,     3,
      19,    10
=======
       0,     6,    13,    14,    21,    22,    48,    49,    50,     3,
       0,     6,    50,     7,     3,    17,    18,    23,    24,    27,
      50,    51,    59,    60,    62,    63,    64,    65,     3,     7,
       3,     5,    43,    43,    43,    43,     3,    58,    23,    59,
      23,    59,    59,    59,    59,    59,    23,    51,    59,     3,
      43,     3,     8,     9,    11,    15,    16,    20,    43,    53,
      54,    55,    56,    57,     3,    20,    43,    53,    66,    67,
      68,    66,    12,    37,    19,    45,    23,    23,    59,    23,
      43,     3,    58,    43,     3,    53,    19,    35,    36,    37,
      38,    44,    44,    45,    53,    66,     5,    31,    32,    33,
      34,    41,    42,    30,    39,    44,    44,    43,     8,    51,
       3,    23,    58,    44,     8,    52,    43,    44,    54,    54,
      55,    55,    19,    19,    58,    44,     5,    53,    53,    53,
      53,    53,    53,    67,    67,    25,    59,    52,    19,    44,
      51,    44,    45,    58,    44,    53,    59,    28,    44,    51,
      51,    59,     8,    44,    19,    26,    61,    19,    59,     3,
      59,    40,    51,     3,     5,     5,     3,     3,    19,    19,
      10,    10
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
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
        case 3:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 13 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;



/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 1500 "syntaxique.tab.c"
=======
#line 1585 "syntaxique.tab.c"
>>>>>>> 60c31b45cf8d4d8d47883460fd9f9dfd9859e785
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
#line 62 "syntaxique.y"


int main ()
{
   initialisation();
   yyparse();
   afficher();
   return 0;
 }
 yywrap ()
 {}
 int yyerror ( char*  msg )
 {
    printf ("Erreur Syntaxique a ligne %d a colonne %d \n",nb_ligne,Col);
  }
