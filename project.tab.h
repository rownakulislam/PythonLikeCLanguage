
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 18 "project.y"

    #ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif



/* Line 1676 of yacc.c  */
#line 54 "project.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VARIABLE = 258,
     VARACCESS = 259,
     NUM = 260,
     STR = 261,
     LE_OP = 262,
     GE_OP = 263,
     EQ_OP = 264,
     NE_OP = 265,
     ALLOCATE = 266,
     SIN = 267,
     ASIN = 268,
     COS = 269,
     ACOS = 270,
     TAN = 271,
     ATAN = 272,
     POW = 273,
     LOG = 274,
     LOG10 = 275,
     RETURN = 276,
     INC = 277,
     DEC = 278,
     ADD = 279,
     SUB = 280,
     IF = 281,
     ELSE_IF = 282,
     ELSE = 283,
     FOR = 284,
     WHILE = 285,
     INT = 286,
     REAL = 287,
     DESCRIBE = 288,
     CLASS = 289,
     FUNC = 290,
     STRING = 291,
     VOID = 292,
     OPTIONS = 293,
     OPTION = 294,
     DEFAULT = 295,
     PRINT = 296,
     IMPORT = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 29 "project.y"

    char text[1009];
    struct datatype val;



/* Line 1676 of yacc.c  */
#line 120 "project.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


