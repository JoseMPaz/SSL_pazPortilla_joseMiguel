/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFICADOR = 258,           /* IDENTIFICADOR  */
    CONSTANTE_DECIMAL = 259,       /* CONSTANTE_DECIMAL  */
    OPERADOR_LOGICO_OR = 260,      /* OPERADOR_LOGICO_OR  */
    OPERADOR_LOGICO_AND = 261,     /* OPERADOR_LOGICO_AND  */
    OPERADOR_DE_IGUALDAD = 262,    /* OPERADOR_DE_IGUALDAD  */
    OPERADOR_DE_DESIGUALDAD = 263, /* OPERADOR_DE_DESIGUALDAD  */
    OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA = 264, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA  */
    OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA = 265, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA  */
    OPERADOR_DE_COMPARACION = 266, /* OPERADOR_DE_COMPARACION  */
    MENOR_O_IGUAL = 267,           /* MENOR_O_IGUAL  */
    MAYOR_O_IGUAL = 268,           /* MAYOR_O_IGUAL  */
    INCREMENTO = 269,              /* INCREMENTO  */
    DECREMENTO = 270,              /* DECREMENTO  */
    SIZEOF = 271,                  /* SIZEOF  */
    OPERADOR_FLECHA = 272,         /* OPERADOR_FLECHA  */
    CASE = 273,                    /* CASE  */
    DEFAULT = 274,                 /* DEFAULT  */
    VOID = 275,                    /* VOID  */
    CHAR = 276,                    /* CHAR  */
    SHORT = 277,                   /* SHORT  */
    INT = 278,                     /* INT  */
    LONG = 279,                    /* LONG  */
    FLOAT = 280,                   /* FLOAT  */
    DOUBLE = 281,                  /* DOUBLE  */
    SIGNED = 282,                  /* SIGNED  */
    UNSIGNED = 283,                /* UNSIGNED  */
    CONST = 284,                   /* CONST  */
    VOLATILE = 285,                /* VOLATILE  */
    AUTO = 286,                    /* AUTO  */
    REGISTER = 287,                /* REGISTER  */
    STATIC = 288,                  /* STATIC  */
    EXTERN = 289,                  /* EXTERN  */
    TYPEDEF = 290,                 /* TYPEDEF  */
    ELIPSIS = 291,                 /* ELIPSIS  */
    STRUCT = 292,                  /* STRUCT  */
    UNION = 293,                   /* UNION  */
    ENUM = 294,                    /* ENUM  */
    IF = 295,                      /* IF  */
    ELSE = 296,                    /* ELSE  */
    SWITCH = 297,                  /* SWITCH  */
    WHILE = 298,                   /* WHILE  */
    DO = 299,                      /* DO  */
    FOR = 300,                     /* FOR  */
    GOTO = 301,                    /* GOTO  */
    CONTINUE = 302,                /* CONTINUE  */
    BREAK = 303,                   /* BREAK  */
    RETURN = 304,                  /* RETURN  */
    DESPLAZAMIENTO_A_DERECHA = 305, /* DESPLAZAMIENTO_A_DERECHA  */
    DESPLAZAMIENTO_A_IZQUIERDA = 306, /* DESPLAZAMIENTO_A_IZQUIERDA  */
    THEN = 307                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser.y"

	char * sval;
	int ival;

#line 121 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
