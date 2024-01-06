
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 27 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 1676 of yacc.c  */
#line 105 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


