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
    CADENA_DE_CARACTERES = 259,    /* CADENA_DE_CARACTERES  */
    CONSTANTE_CARACTER = 260,      /* CONSTANTE_CARACTER  */
    CONSTANTE_DE_ENUMERACION = 261, /* CONSTANTE_DE_ENUMERACION  */
    VOID = 262,                    /* VOID  */
    CHAR = 263,                    /* CHAR  */
    SHORT = 264,                   /* SHORT  */
    INT = 265,                     /* INT  */
    LONG = 266,                    /* LONG  */
    FLOAT = 267,                   /* FLOAT  */
    DOUBLE = 268,                  /* DOUBLE  */
    SIGNED = 269,                  /* SIGNED  */
    UNSIGNED = 270,                /* UNSIGNED  */
    CONSTANTE_REAL = 271,          /* CONSTANTE_REAL  */
    CONSTANTE_DECIMAL = 272,       /* CONSTANTE_DECIMAL  */
    CONSTANTE_OCTAL = 273,         /* CONSTANTE_OCTAL  */
    CONSTANTE_HEXADECIMAL = 274,   /* CONSTANTE_HEXADECIMAL  */
    OPERADOR_LOGICO_OR = 275,      /* OPERADOR_LOGICO_OR  */
    OPERADOR_LOGICO_AND = 276,     /* OPERADOR_LOGICO_AND  */
    OPERADOR_DE_IGUALDAD = 277,    /* OPERADOR_DE_IGUALDAD  */
    OPERADOR_DE_DESIGUALDAD = 278, /* OPERADOR_DE_DESIGUALDAD  */
    OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA = 279, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA  */
    OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA = 280, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA  */
    OPERADOR_DE_COMPARACION = 281, /* OPERADOR_DE_COMPARACION  */
    MENOR_O_IGUAL = 282,           /* MENOR_O_IGUAL  */
    MAYOR_O_IGUAL = 283,           /* MAYOR_O_IGUAL  */
    INCREMENTO = 284,              /* INCREMENTO  */
    DECREMENTO = 285,              /* DECREMENTO  */
    SIZEOF = 286,                  /* SIZEOF  */
    OPERADOR_FLECHA = 287,         /* OPERADOR_FLECHA  */
    CASE = 288,                    /* CASE  */
    DEFAULT = 289,                 /* DEFAULT  */
    CONST = 290,                   /* CONST  */
    VOLATILE = 291,                /* VOLATILE  */
    AUTO = 292,                    /* AUTO  */
    REGISTER = 293,                /* REGISTER  */
    STATIC = 294,                  /* STATIC  */
    EXTERN = 295,                  /* EXTERN  */
    TYPEDEF = 296,                 /* TYPEDEF  */
    ELIPSIS = 297,                 /* ELIPSIS  */
    STRUCT = 298,                  /* STRUCT  */
    UNION = 299,                   /* UNION  */
    ENUM = 300,                    /* ENUM  */
    IF = 301,                      /* IF  */
    ELSE = 302,                    /* ELSE  */
    SWITCH = 303,                  /* SWITCH  */
    WHILE = 304,                   /* WHILE  */
    DO = 305,                      /* DO  */
    FOR = 306,                     /* FOR  */
    GOTO = 307,                    /* GOTO  */
    CONTINUE = 308,                /* CONTINUE  */
    BREAK = 309,                   /* BREAK  */
    RETURN = 310,                  /* RETURN  */
    OPERADOR_ASIGNACION_MULTIPLICACION = 311, /* OPERADOR_ASIGNACION_MULTIPLICACION  */
    OPERADOR_ASIGNACION_DIVISION = 312, /* OPERADOR_ASIGNACION_DIVISION  */
    OPERADOR_ASIGNACION_RESTO = 313, /* OPERADOR_ASIGNACION_RESTO  */
    OPERADOR_ASIGNACION_SUMA = 314, /* OPERADOR_ASIGNACION_SUMA  */
    OPERADOR_ASIGNACION_RESTA = 315, /* OPERADOR_ASIGNACION_RESTA  */
    OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA = 316, /* OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA  */
    OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA = 317, /* OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA  */
    OPERADOR_ASIGNACION_AND_BIT_A_BIT = 318, /* OPERADOR_ASIGNACION_AND_BIT_A_BIT  */
    OPERADOR_ASIGNACION_XOR_BIT_A_BIT = 319, /* OPERADOR_ASIGNACION_XOR_BIT_A_BIT  */
    OPERADOR_ASIGNACION_OR_BIT_A_BIT = 320, /* OPERADOR_ASIGNACION_OR_BIT_A_BIT  */
    DESPLAZAMIENTO_A_DERECHA = 321, /* DESPLAZAMIENTO_A_DERECHA  */
    DESPLAZAMIENTO_A_IZQUIERDA = 322, /* DESPLAZAMIENTO_A_IZQUIERDA  */
    THEN = 323                     /* THEN  */
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
	double dval;

#line 138 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
