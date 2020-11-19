/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_EXO1_TAB_H_INCLUDED
# define YY_YY_EXO1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    X = 258,
    P = 259,
    IF = 260,
    ELSE = 261,
    CARACTERE = 262,
    NUM = 263,
    IDENT = 264,
    TYPE = 265,
    EQ = 266,
    ADDSUB = 267,
    DIVSTAR = 268,
    OR = 269,
    AND = 270,
    WHILE = 271,
    RETURN = 272,
    PRINT = 273,
    RACC = 274,
    PO = 275,
    PF = 276,
    LACC = 277,
    READC = 278,
    READE = 279,
    EQUAL = 280,
    CONST = 281,
    VOID = 282,
    ORDERC = 283,
    ORDER = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "exo1.y" /* yacc.c:1909  */

  int value;
  int type;
  char carac[3];
  char caractere;
  char name[32];
  char string[2];
  Bvalue litteral;
  Variable var;


#line 96 "exo1.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXO1_TAB_H_INCLUDED  */
