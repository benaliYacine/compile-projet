
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

/* Line 1676 of yacc.c  */
#line 28 "syntaxique.y"

    int entier;
    char* str;
    float reel;



/* Line 1676 of yacc.c  */
#line 107 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


