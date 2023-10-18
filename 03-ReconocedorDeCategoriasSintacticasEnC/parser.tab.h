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
    CONSTANTE_REAL = 262,          /* CONSTANTE_REAL  */
    CONSTANTE_DECIMAL = 263,       /* CONSTANTE_DECIMAL  */
    CONSTANTE_OCTAL = 264,         /* CONSTANTE_OCTAL  */
    CONSTANTE_HEXADECIMAL = 265,   /* CONSTANTE_HEXADECIMAL  */
    OPERADOR_LOGICO_OR = 266,      /* OPERADOR_LOGICO_OR  */
    OPERADOR_LOGICO_AND = 267,     /* OPERADOR_LOGICO_AND  */
    OPERADOR_DE_IGUALDAD = 268,    /* OPERADOR_DE_IGUALDAD  */
    OPERADOR_DE_DESIGUALDAD = 269, /* OPERADOR_DE_DESIGUALDAD  */
    OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA = 270, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA  */
    OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA = 271, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA  */
    OPERADOR_DE_COMPARACION = 272, /* OPERADOR_DE_COMPARACION  */
    MENOR_O_IGUAL = 273,           /* MENOR_O_IGUAL  */
    MAYOR_O_IGUAL = 274,           /* MAYOR_O_IGUAL  */
    INCREMENTO = 275,              /* INCREMENTO  */
    DECREMENTO = 276,              /* DECREMENTO  */
    SIZEOF = 277,                  /* SIZEOF  */
    OPERADOR_FLECHA = 278,         /* OPERADOR_FLECHA  */
    CASE = 279,                    /* CASE  */
    DEFAULT = 280,                 /* DEFAULT  */
    VOID = 281,                    /* VOID  */
    CHAR = 282,                    /* CHAR  */
    SHORT = 283,                   /* SHORT  */
    INT = 284,                     /* INT  */
    LONG = 285,                    /* LONG  */
    FLOAT = 286,                   /* FLOAT  */
    DOUBLE = 287,                  /* DOUBLE  */
    SIGNED = 288,                  /* SIGNED  */
    UNSIGNED = 289,                /* UNSIGNED  */
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
