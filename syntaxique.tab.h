
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
     cst = 259,
     aff = 260,
     mc_prgrm = 261,
     mc_rtin = 262,
     int = 263,
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
     div = 293,
     mc_and = 294,
     mc_endif = 295,
     lt = 296,
     gt = 297,
     po = 298,
     pf = 299,
     de = 300,
     verg = 301,
     err = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 5 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 1676 of yacc.c  */
#line 107 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


