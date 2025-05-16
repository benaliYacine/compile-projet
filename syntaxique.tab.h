
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

/* Line 1676 of yacc.c  */
#line 30 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 1676 of yacc.c  */
#line 111 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


