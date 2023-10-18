/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern FILE * yyin;
extern int yyerror (char *s);


#line 80 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFICADOR = 3,              /* IDENTIFICADOR  */
  YYSYMBOL_CONSTANTE_DECIMAL = 4,          /* CONSTANTE_DECIMAL  */
  YYSYMBOL_OPERADOR_LOGICO_OR = 5,         /* OPERADOR_LOGICO_OR  */
  YYSYMBOL_OPERADOR_LOGICO_AND = 6,        /* OPERADOR_LOGICO_AND  */
  YYSYMBOL_OPERADOR_DE_IGUALDAD = 7,       /* OPERADOR_DE_IGUALDAD  */
  YYSYMBOL_OPERADOR_DE_DESIGUALDAD = 8,    /* OPERADOR_DE_DESIGUALDAD  */
  YYSYMBOL_OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA = 9, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA  */
  YYSYMBOL_OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA = 10, /* OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA  */
  YYSYMBOL_OPERADOR_DE_COMPARACION = 11,   /* OPERADOR_DE_COMPARACION  */
  YYSYMBOL_MENOR_O_IGUAL = 12,             /* MENOR_O_IGUAL  */
  YYSYMBOL_MAYOR_O_IGUAL = 13,             /* MAYOR_O_IGUAL  */
  YYSYMBOL_INCREMENTO = 14,                /* INCREMENTO  */
  YYSYMBOL_DECREMENTO = 15,                /* DECREMENTO  */
  YYSYMBOL_SIZEOF = 16,                    /* SIZEOF  */
  YYSYMBOL_OPERADOR_FLECHA = 17,           /* OPERADOR_FLECHA  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_VOID = 20,                      /* VOID  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_SHORT = 22,                     /* SHORT  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_LONG = 24,                      /* LONG  */
  YYSYMBOL_FLOAT = 25,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 26,                    /* DOUBLE  */
  YYSYMBOL_SIGNED = 27,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 28,                  /* UNSIGNED  */
  YYSYMBOL_CONST = 29,                     /* CONST  */
  YYSYMBOL_VOLATILE = 30,                  /* VOLATILE  */
  YYSYMBOL_AUTO = 31,                      /* AUTO  */
  YYSYMBOL_REGISTER = 32,                  /* REGISTER  */
  YYSYMBOL_STATIC = 33,                    /* STATIC  */
  YYSYMBOL_EXTERN = 34,                    /* EXTERN  */
  YYSYMBOL_TYPEDEF = 35,                   /* TYPEDEF  */
  YYSYMBOL_ELIPSIS = 36,                   /* ELIPSIS  */
  YYSYMBOL_STRUCT = 37,                    /* STRUCT  */
  YYSYMBOL_UNION = 38,                     /* UNION  */
  YYSYMBOL_ENUM = 39,                      /* ENUM  */
  YYSYMBOL_IF = 40,                        /* IF  */
  YYSYMBOL_ELSE = 41,                      /* ELSE  */
  YYSYMBOL_SWITCH = 42,                    /* SWITCH  */
  YYSYMBOL_WHILE = 43,                     /* WHILE  */
  YYSYMBOL_DO = 44,                        /* DO  */
  YYSYMBOL_FOR = 45,                       /* FOR  */
  YYSYMBOL_GOTO = 46,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 47,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 48,                     /* BREAK  */
  YYSYMBOL_RETURN = 49,                    /* RETURN  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* '?'  */
  YYSYMBOL_53_ = 53,                       /* ':'  */
  YYSYMBOL_54_ = 54,                       /* '|'  */
  YYSYMBOL_55_ = 55,                       /* '&'  */
  YYSYMBOL_56_ = 56,                       /* '^'  */
  YYSYMBOL_57_ = 57,                       /* '<'  */
  YYSYMBOL_58_ = 58,                       /* '>'  */
  YYSYMBOL_59_ = 59,                       /* '+'  */
  YYSYMBOL_60_ = 60,                       /* '-'  */
  YYSYMBOL_61_ = 61,                       /* '*'  */
  YYSYMBOL_62_ = 62,                       /* '/'  */
  YYSYMBOL_63_ = 63,                       /* '%'  */
  YYSYMBOL_64_ = 64,                       /* '('  */
  YYSYMBOL_65_ = 65,                       /* ')'  */
  YYSYMBOL_DESPLAZAMIENTO_A_DERECHA = 66,  /* DESPLAZAMIENTO_A_DERECHA  */
  YYSYMBOL_DESPLAZAMIENTO_A_IZQUIERDA = 67, /* DESPLAZAMIENTO_A_IZQUIERDA  */
  YYSYMBOL_68_ = 68,                       /* '~'  */
  YYSYMBOL_69_ = 69,                       /* '!'  */
  YYSYMBOL_70_ = 70,                       /* '['  */
  YYSYMBOL_71_ = 71,                       /* ']'  */
  YYSYMBOL_THEN = 72,                      /* THEN  */
  YYSYMBOL_73_ = 73,                       /* ';'  */
  YYSYMBOL_74_ = 74,                       /* '{'  */
  YYSYMBOL_75_ = 75,                       /* '}'  */
  YYSYMBOL_76_ = 76,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_unidad_de_traduccion = 78,      /* unidad_de_traduccion  */
  YYSYMBOL_declaracion_externa = 79,       /* declaracion_externa  */
  YYSYMBOL_definicion_de_funcion = 80,     /* definicion_de_funcion  */
  YYSYMBOL_declaracion = 81,               /* declaracion  */
  YYSYMBOL_lista_de_declaraciones = 82,    /* lista_de_declaraciones  */
  YYSYMBOL_especificadores_de_declaracion = 83, /* especificadores_de_declaracion  */
  YYSYMBOL_especificador_de_clase_de_almacenamiento = 84, /* especificador_de_clase_de_almacenamiento  */
  YYSYMBOL_especificador_de_tipo = 85,     /* especificador_de_tipo  */
  YYSYMBOL_calificador_de_tipo = 86,       /* calificador_de_tipo  */
  YYSYMBOL_especificador_de_struct_o_union = 87, /* especificador_de_struct_o_union  */
  YYSYMBOL_struct_o_union = 88,            /* struct_o_union  */
  YYSYMBOL_lista_de_declaraciones_struct = 89, /* lista_de_declaraciones_struct  */
  YYSYMBOL_lista_de_declaradores_inicial = 90, /* lista_de_declaradores_inicial  */
  YYSYMBOL_declarador_inicial = 91,        /* declarador_inicial  */
  YYSYMBOL_declaracion_struct = 92,        /* declaracion_struct  */
  YYSYMBOL_lista_de_calificadores_y_especificadores = 93, /* lista_de_calificadores_y_especificadores  */
  YYSYMBOL_lista_de_declaradores_struct = 94, /* lista_de_declaradores_struct  */
  YYSYMBOL_declarador_struct = 95,         /* declarador_struct  */
  YYSYMBOL_especificador_enum = 96,        /* especificador_enum  */
  YYSYMBOL_lista_de_enumeradores = 97,     /* lista_de_enumeradores  */
  YYSYMBOL_enumerador = 98,                /* enumerador  */
  YYSYMBOL_declarador = 99,                /* declarador  */
  YYSYMBOL_declaracion_directa = 100,      /* declaracion_directa  */
  YYSYMBOL_puntero = 101,                  /* puntero  */
  YYSYMBOL_lista_de_calificadores_de_tipo = 102, /* lista_de_calificadores_de_tipo  */
  YYSYMBOL_lista_de_tipos_de_parametros = 103, /* lista_de_tipos_de_parametros  */
  YYSYMBOL_lista_de_parametros = 104,      /* lista_de_parametros  */
  YYSYMBOL_declaracion_de_parametro = 105, /* declaracion_de_parametro  */
  YYSYMBOL_lista_de_identificadores = 106, /* lista_de_identificadores  */
  YYSYMBOL_inicializador = 107,            /* inicializador  */
  YYSYMBOL_lista_de_inicializadores = 108, /* lista_de_inicializadores  */
  YYSYMBOL_nombre_de_tipo = 109,           /* nombre_de_tipo  */
  YYSYMBOL_sentencia = 110,                /* sentencia  */
  YYSYMBOL_sentencia_de_etiqueta = 111,    /* sentencia_de_etiqueta  */
  YYSYMBOL_sentencia_de_expresion = 112,   /* sentencia_de_expresion  */
  YYSYMBOL_sentencia_compuesta = 113,      /* sentencia_compuesta  */
  YYSYMBOL_lista_de_sentencias = 114,      /* lista_de_sentencias  */
  YYSYMBOL_sentencia_de_seleccion = 115,   /* sentencia_de_seleccion  */
  YYSYMBOL_sentencia_de_iteracion = 116,   /* sentencia_de_iteracion  */
  YYSYMBOL_sentencia_de_salto = 117,       /* sentencia_de_salto  */
  YYSYMBOL_expresion = 118,                /* expresion  */
  YYSYMBOL_expresion_de_asignacion = 119,  /* expresion_de_asignacion  */
  YYSYMBOL_expresion_condicional = 120,    /* expresion_condicional  */
  YYSYMBOL_expresion_constante = 121,      /* expresion_constante  */
  YYSYMBOL_expresion_logica_OR = 122,      /* expresion_logica_OR  */
  YYSYMBOL_expresion_logica_AND = 123,     /* expresion_logica_AND  */
  YYSYMBOL_expresion_OR_inclusiva = 124,   /* expresion_OR_inclusiva  */
  YYSYMBOL_expresion_OR_exclusiva = 125,   /* expresion_OR_exclusiva  */
  YYSYMBOL_expresion_AND = 126,            /* expresion_AND  */
  YYSYMBOL_expresion_de_igualdad = 127,    /* expresion_de_igualdad  */
  YYSYMBOL_expresion_relacional = 128,     /* expresion_relacional  */
  YYSYMBOL_expresion_de_desplazamiento = 129, /* expresion_de_desplazamiento  */
  YYSYMBOL_expresion_aditiva = 130,        /* expresion_aditiva  */
  YYSYMBOL_expresion_multiplicativa = 131, /* expresion_multiplicativa  */
  YYSYMBOL_expresion_de_casteo = 132,      /* expresion_de_casteo  */
  YYSYMBOL_expresion_unaria = 133,         /* expresion_unaria  */
  YYSYMBOL_operador_unario = 134,          /* operador_unario  */
  YYSYMBOL_expresion_posfija = 135,        /* expresion_posfija  */
  YYSYMBOL_expresion_primaria = 136,       /* expresion_primaria  */
  YYSYMBOL_lista_de_expresiones_de_argumentos = 137, /* lista_de_expresiones_de_argumentos  */
  YYSYMBOL_constante = 138                 /* constante  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  340

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,     2,    63,    55,     2,
      64,    65,    61,    59,    50,    60,    76,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    73,
      57,    51,    58,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,    54,    75,    68,     2,     2,     2,
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
      45,    46,    47,    48,    49,    66,    67,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    60,    64,    65,    69,    70,    71,    72,
      76,    77,    81,    82,    86,    87,    88,    89,    90,    91,
      95,    96,    97,    98,    99,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   118,   119,   123,
     124,   125,   129,   130,   134,   135,   139,   140,   144,   145,
     149,   153,   154,   155,   156,   160,   161,   165,   169,   170,
     171,   175,   176,   180,   181,   185,   186,   190,   191,   192,
     193,   194,   195,   196,   200,   201,   202,   203,   207,   208,
     212,   213,   217,   218,   222,   223,   227,   228,   232,   233,
     234,   238,   239,   243,   250,   251,   252,   253,   254,   255,
     259,   260,   261,   265,   266,   270,   271,   272,   273,   277,
     278,   282,   284,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   301,   302,   303,   304,   305,   309,   310,
     314,   315,   319,   320,   324,   328,   329,   333,   334,   338,
     339,   343,   344,   348,   349,   353,   354,   355,   359,   360,
     361,   362,   363,   367,   368,   369,   373,   374,   375,   379,
     380,   381,   382,   386,   387,   391,   392,   393,   394,   395,
     396,   400,   401,   402,   403,   404,   405,   409,   410,   411,
     412,   413,   414,   415,   416,   420,   421,   422,   426,   427,
     431
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFICADOR",
  "CONSTANTE_DECIMAL", "OPERADOR_LOGICO_OR", "OPERADOR_LOGICO_AND",
  "OPERADOR_DE_IGUALDAD", "OPERADOR_DE_DESIGUALDAD",
  "OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA",
  "OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA", "OPERADOR_DE_COMPARACION",
  "MENOR_O_IGUAL", "MAYOR_O_IGUAL", "INCREMENTO", "DECREMENTO", "SIZEOF",
  "OPERADOR_FLECHA", "CASE", "DEFAULT", "VOID", "CHAR", "SHORT", "INT",
  "LONG", "FLOAT", "DOUBLE", "SIGNED", "UNSIGNED", "CONST", "VOLATILE",
  "AUTO", "REGISTER", "STATIC", "EXTERN", "TYPEDEF", "ELIPSIS", "STRUCT",
  "UNION", "ENUM", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "','", "'='", "'?'", "':'", "'|'", "'&'",
  "'^'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'",
  "DESPLAZAMIENTO_A_DERECHA", "DESPLAZAMIENTO_A_IZQUIERDA", "'~'", "'!'",
  "'['", "']'", "THEN", "';'", "'{'", "'}'", "'.'", "$accept",
  "unidad_de_traduccion", "declaracion_externa", "definicion_de_funcion",
  "declaracion", "lista_de_declaraciones",
  "especificadores_de_declaracion",
  "especificador_de_clase_de_almacenamiento", "especificador_de_tipo",
  "calificador_de_tipo", "especificador_de_struct_o_union",
  "struct_o_union", "lista_de_declaraciones_struct",
  "lista_de_declaradores_inicial", "declarador_inicial",
  "declaracion_struct", "lista_de_calificadores_y_especificadores",
  "lista_de_declaradores_struct", "declarador_struct",
  "especificador_enum", "lista_de_enumeradores", "enumerador",
  "declarador", "declaracion_directa", "puntero",
  "lista_de_calificadores_de_tipo", "lista_de_tipos_de_parametros",
  "lista_de_parametros", "declaracion_de_parametro",
  "lista_de_identificadores", "inicializador", "lista_de_inicializadores",
  "nombre_de_tipo", "sentencia", "sentencia_de_etiqueta",
  "sentencia_de_expresion", "sentencia_compuesta", "lista_de_sentencias",
  "sentencia_de_seleccion", "sentencia_de_iteracion", "sentencia_de_salto",
  "expresion", "expresion_de_asignacion", "expresion_condicional",
  "expresion_constante", "expresion_logica_OR", "expresion_logica_AND",
  "expresion_OR_inclusiva", "expresion_OR_exclusiva", "expresion_AND",
  "expresion_de_igualdad", "expresion_relacional",
  "expresion_de_desplazamiento", "expresion_aditiva",
  "expresion_multiplicativa", "expresion_de_casteo", "expresion_unaria",
  "operador_unario", "expresion_posfija", "expresion_primaria",
  "lista_de_expresiones_de_argumentos", "constante", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-152)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1298,    28,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
       3,    -1,     9,  1174,  -152,  -152,  -152,    22,  1343,  1343,
    1343,  -152,     6,  -152,   648,    -7,    12,   -48,    42,  -152,
    -152,    -1,  -152,    -6,  -152,  -152,  -152,   -29,  -152,   615,
    -152,  -152,  -152,  -152,   -13,  1376,   247,  -152,   648,    22,
    -152,  1219,   860,    -7,    42,    49,   -28,  -152,  -152,  -152,
    -152,     9,  -152,   687,   648,  -152,  1376,  1376,  1376,   492,
    -152,     9,   706,  -152,  1096,  1096,  1124,  1155,    58,    79,
     130,   148,   560,   151,   156,   149,   158,   749,  -152,  -152,
    -152,  -152,   919,  -152,  -152,  -152,  -152,   309,  -152,  -152,
    -152,  -152,   371,  -152,  -152,  -152,    -9,  -152,  -152,    13,
     223,   185,   184,   186,   173,    30,   182,   146,   147,  -152,
     196,  1155,     2,  -152,  -152,  -152,  -152,   197,  -152,  -152,
       9,   187,   199,  -152,    70,  -152,  -152,  -152,   183,  -152,
     -17,  1155,    42,  -152,  -152,   687,  -152,  -152,  -152,   520,
    -152,  -152,  -152,  -152,    -2,  -152,  -152,   560,  1155,  -152,
    -152,   919,  -152,    51,   560,  1155,  1155,  1155,   200,   212,
     768,   191,  -152,  -152,  -152,    56,  1252,  -152,   194,    90,
    -152,   433,  -152,  -152,  1155,  -152,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,  1155,
    1155,  1155,  1155,  1155,  1155,  1155,  -152,  -152,  -152,   253,
     947,  1155,   280,  -152,  -152,   859,   285,  -152,  -152,  -152,
    -152,  -152,  -152,    44,  -152,     9,  -152,  -152,   232,   560,
    -152,    91,    92,    95,   234,   783,    59,  -152,  -152,  1155,
    -152,  -152,  -152,   223,   140,   185,   184,   186,   173,    30,
      30,   182,   182,   182,   182,   146,   146,   147,   147,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   133,    68,  -152,  -152,
    -152,  -152,   522,  -152,  -152,  -152,  -152,   560,   560,   560,
    1155,   978,    60,   845,  -152,  1155,  1155,  -152,  -152,  -152,
    -152,   259,  -152,  -152,   134,   560,   135,  1006,  1037,    65,
    -152,  -152,   236,   228,  -152,   560,   560,   136,   560,   137,
    1065,  1155,  -152,  -152,  -152,   560,  -152,   560,   560,   138,
     139,  -152,  -152,  -152,   560,   560,  -152,   262,   560,  -152
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    36,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    37,    38,    20,    21,    22,    23,    24,    42,    43,
       0,    74,     0,     0,     2,     4,     5,     0,    14,    16,
      18,    34,     0,    35,     0,    65,     0,    60,     0,    78,
      76,    75,    67,     0,     1,     3,    10,     0,    46,    48,
      36,    15,    17,    19,    41,     0,     0,    12,     0,     0,
       6,     0,     0,    66,     0,    63,     0,    61,    79,    77,
      68,     0,    11,     0,     0,     8,     0,    51,    53,     0,
      44,     0,   185,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   173,
     174,   175,     0,   171,   172,   103,   105,     0,   109,    94,
      95,    96,     0,    97,    98,    99,     0,   128,   130,   132,
     135,   137,   139,   141,   143,   145,   148,   153,   156,   159,
     163,     0,   165,   177,   186,    13,     7,    48,    36,    72,
      84,     0,    80,    82,     0,   185,    69,   134,     0,   163,
       0,     0,     0,    58,    47,     0,    49,    88,     9,     0,
      52,    54,    39,    45,     0,    55,    57,     0,     0,   166,
     167,     0,   169,     0,     0,     0,     0,     0,   185,     0,
       0,     0,   124,   125,   126,     0,   185,    93,     0,     0,
     107,     0,   106,   110,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   183,   184,     0,
       0,     0,     0,    85,    71,     0,     0,    73,    70,    59,
      64,    62,    91,     0,    40,     0,    50,   100,     0,     0,
     102,     0,     0,     0,     0,     0,     0,   123,   127,     0,
     187,   108,   129,   136,     0,   138,   140,   142,   144,   146,
     147,   150,   152,   149,   151,   154,   155,   157,   158,   160,
     161,   162,   131,   182,   179,   188,     0,     0,   181,    81,
      83,    87,     0,    89,    56,   170,   101,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,   180,   178,    90,
      92,     0,   112,   113,     0,     0,     0,     0,     0,     0,
     133,   189,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,   114,   118,   117,     0,   116,     0,     0,     0,
       0,   121,   120,   119,     0,     0,   122,     0,     0,   111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,   281,  -152,    23,    18,     7,  -152,   -23,    48,
    -152,  -152,   229,  -152,   238,   -74,   -64,  -152,    75,  -152,
     250,   165,   -19,   282,   -10,  -152,  -152,  -152,    94,  -152,
    -151,  -152,   155,   -92,  -152,  -152,    88,   243,  -152,  -152,
    -152,   -63,   -71,   -61,   208,  -152,   164,   163,   166,   145,
     161,    15,   -53,    29,    10,  -121,   -35,  -152,  -152,  -152,
    -152,  -152
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    23,    24,    25,    57,    58,    59,    28,    29,    30,
      31,    32,    79,    47,    48,    80,    81,   164,   165,    33,
      66,    67,    34,    35,    36,    41,   141,   142,   143,   144,
     156,   233,   188,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   148,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     276,   134
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     179,   147,   157,    43,   232,   163,    37,    27,    49,    54,
     216,    40,    42,   160,   161,    42,   217,   218,   196,   219,
     193,    71,   152,    26,   173,    42,    64,   149,    11,    12,
      27,    69,    77,   152,   185,    51,    52,    53,   187,   189,
     137,   194,   204,   205,    72,    65,    26,   153,   235,   169,
     170,   172,   137,    77,    77,    77,    77,    61,   229,    70,
      21,    76,   166,    62,   195,   197,   220,    74,   140,    39,
      21,   236,   221,    22,   107,   237,    22,    38,   222,    77,
      55,   135,   240,    21,   157,   163,    22,   206,   207,    68,
     147,   269,   270,   271,   282,    46,   149,   135,   -67,   193,
     151,   194,   -67,    78,   239,   189,   194,   187,   189,   194,
     194,   174,   241,   242,   243,   194,   149,   246,   194,   283,
     226,   223,    60,   252,    78,    78,    78,    78,   294,   248,
     135,   300,   293,   307,   254,   227,    77,    75,   320,   298,
     194,   194,   194,   175,   272,   194,   136,   286,    77,   275,
      78,   261,   262,   263,   264,   250,   287,   288,   277,   181,
     289,   149,   158,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     202,   203,   292,   296,   194,   194,   194,   194,   194,   194,
     194,   208,   209,   295,   176,   301,   302,   303,   297,   313,
     315,   325,   327,   334,   335,   210,   211,    78,   212,   213,
     214,   157,   177,   314,   149,   180,   166,   259,   260,    78,
     267,   268,   182,   323,   324,   311,   326,   304,   306,   198,
     309,   183,   140,   331,   310,   332,   333,   265,   266,   199,
     200,   201,   336,   337,   317,   319,   339,   215,    73,   225,
      82,    83,   224,   167,   228,   244,   273,   329,   330,   249,
     149,    84,    85,    86,   247,    87,    88,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   278,    18,    19,    20,    89,   281,    90,
      91,    92,    93,    94,    95,    96,    97,   285,   290,   312,
     321,   322,    98,   338,    45,   159,    99,   100,   101,   154,
     284,   102,    82,    83,   150,   103,   104,   231,    63,   280,
     105,    56,   106,    84,    85,    86,   238,    87,    88,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,   257,    18,    19,    20,    89,
     191,    90,    91,    92,    93,    94,    95,    96,    97,   230,
     253,   255,   258,     0,    98,   256,     0,     0,    99,   100,
     101,     0,     0,   102,   178,    83,     0,   103,   104,     0,
       0,     0,   105,    56,   190,    84,    85,    86,     0,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,    98,     0,     0,     0,
      99,   100,   101,     0,     0,   102,   178,    83,     0,   103,
     104,     0,     0,     0,   105,    56,   192,    84,    85,    86,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,    90,    91,    92,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,    98,     0,
       0,     0,    99,   100,   101,    50,     0,   102,     0,     0,
       0,   103,   104,     0,     0,     0,   105,    56,   251,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    50,     0,   145,    83,     0,     0,    18,
      19,    20,     0,     0,     0,     0,    84,    85,    86,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,    18,    19,    20,
       0,     0,     0,   178,    83,     0,     0,   162,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    98,    87,    88,
       0,    99,   100,   101,     0,     0,   102,     0,     0,     0,
     103,   104,     0,     0,     0,   234,   155,   299,     0,     0,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,    98,     0,     0,    50,    99,
     100,   101,     0,     0,   102,     0,     0,     0,   103,   104,
       0,     0,     0,   105,    56,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    50,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,     0,    56,
     145,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,   -36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,    98,   -36,   -36,   -36,    99,   100,   101,     0,
       0,   102,   145,    83,     0,   103,   104,     0,     0,   167,
       0,   155,     0,    84,    85,    86,     0,   -36,     0,     0,
     -36,   145,    83,     0,     0,     0,     0,     0,     0,   -36,
       0,     0,    84,    85,    86,     0,   145,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
       0,     0,     0,     0,    98,     0,     0,     0,    99,   100,
     101,     0,     0,   102,     0,     0,     0,   103,   104,     0,
       0,     0,   184,    98,     0,     0,     0,    99,   100,   101,
       0,     0,   102,     0,     0,     0,   103,   104,    98,     0,
       0,   245,    99,   100,   101,     0,     0,   102,   145,    83,
       0,   103,   104,     0,     0,     0,   291,     0,     0,    84,
      85,    86,    50,   145,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,   279,    18,    19,    20,     0,
      98,     0,     0,     0,    99,   100,   101,     0,     0,   102,
       0,     0,     0,   103,   104,    98,     0,     0,   308,    99,
     100,   101,   186,    83,   102,     0,     0,     0,   103,   104,
       0,   146,     0,    84,    85,    86,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
     145,    83,     0,     0,     0,     0,    18,    19,    20,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,    99,   100,
     101,   145,    83,   102,     0,     0,     0,   103,   104,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,    99,   100,   101,   145,
      83,   102,   274,     0,     0,   103,   104,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     0,    99,   100,   101,
     145,    83,   102,   305,     0,     0,   103,   104,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,    99,   100,   101,   145,    83,
     102,   316,     0,     0,   103,   104,     0,     0,     0,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,    99,   100,   101,   145,
      83,   102,   318,     0,     0,   103,   104,     0,     0,     0,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,    99,   100,   101,   145,    83,   102,
     328,     0,     0,   103,   104,     0,     0,     0,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,    99,   100,   101,   145,    83,
     168,     0,     0,     0,   103,   104,     0,     0,     0,    84,
      85,    86,     0,     0,    44,     0,     0,     1,     0,    98,
       0,     0,     0,    99,   100,   101,     0,     0,   171,     0,
       0,     0,   103,   104,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      98,    18,    19,    20,    99,   100,   101,     0,     0,   102,
       0,     0,   138,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,    22,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,   -36,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   139,     0,     0,     0,     0,   -36,
     -36,   -36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -36,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,    22,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    50,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
      92,    62,    73,    22,   155,    79,     3,     0,    27,     3,
     131,    21,     3,    77,    78,     3,    14,    15,     5,    17,
     112,    50,    50,     0,    87,     3,    74,    62,    29,    30,
      23,    41,    55,    50,    97,    28,    29,    30,   102,   102,
      59,    50,    12,    13,    73,     3,    23,    75,    50,    84,
      85,    86,    71,    76,    77,    78,    79,    64,    75,    65,
      61,    74,    81,    70,    73,    52,    64,    49,    61,    21,
      61,    73,    70,    64,    56,   167,    64,    74,    76,   102,
      74,    58,   174,    61,   155,   159,    64,    57,    58,    41,
     151,   212,   213,   214,    50,    73,   131,    74,    70,   191,
      51,    50,    74,    55,    53,   168,    50,   171,   171,    50,
      50,    53,   175,   176,   177,    50,   151,   180,    50,    75,
      50,   140,    34,   194,    76,    77,    78,    79,   249,    73,
     107,   282,    73,    73,   197,    65,   159,    49,    73,    71,
      50,    50,    50,    64,   215,    50,    58,   239,   171,   220,
     102,   204,   205,   206,   207,    65,    65,    65,   221,     3,
      65,   196,    74,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
       7,     8,   245,    50,    50,    50,    50,    50,    50,    50,
      50,     9,    10,    53,    64,   287,   288,   289,    65,    65,
      65,    65,    65,    65,    65,    59,    60,   159,    61,    62,
      63,   282,    64,   305,   249,    64,   235,   202,   203,   171,
     210,   211,    73,   315,   316,   296,   318,   290,   291,     6,
     293,    73,   225,   325,   295,   327,   328,   208,   209,    54,
      56,    55,   334,   335,   307,   308,   338,    51,    51,    50,
       3,     4,    65,    53,    71,    43,     3,   320,   321,    65,
     295,    14,    15,    16,    73,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     3,    37,    38,    39,    40,     3,    42,
      43,    44,    45,    46,    47,    48,    49,    65,    64,    40,
      64,    73,    55,    41,    23,    76,    59,    60,    61,    71,
     235,    64,     3,     4,    64,    68,    69,   152,    36,   225,
      73,    74,    75,    14,    15,    16,   171,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   200,    37,    38,    39,    40,
     107,    42,    43,    44,    45,    46,    47,    48,    49,   151,
     196,   198,   201,    -1,    55,   199,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,     3,     4,    -1,    68,    69,    -1,
      -1,    -1,    73,    74,    75,    14,    15,    16,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,     3,     4,    -1,    68,
      69,    -1,    -1,    -1,    73,    74,    75,    14,    15,    16,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,     3,    -1,    64,    -1,    -1,
      -1,    68,    69,    -1,    -1,    -1,    73,    74,    75,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     3,    -1,     3,     4,    -1,    -1,    37,
      38,    39,    -1,    -1,    -1,    -1,    14,    15,    16,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    -1,    -1,     3,     4,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    55,    18,    19,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      68,    69,    -1,    -1,    -1,    75,    74,    75,    -1,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,     3,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,
      -1,    -1,    -1,    73,    74,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     3,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    74,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    55,    37,    38,    39,    59,    60,    61,    -1,
      -1,    64,     3,     4,    -1,    68,    69,    -1,    -1,    53,
      -1,    74,    -1,    14,    15,    16,    -1,    61,    -1,    -1,
      64,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    14,    15,    16,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    73,    55,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    69,    55,    -1,
      -1,    73,    59,    60,    61,    -1,    -1,    64,     3,     4,
      -1,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,    14,
      15,    16,     3,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    69,    55,    -1,    -1,    73,    59,
      60,    61,     3,     4,    64,    -1,    -1,    -1,    68,    69,
      -1,    71,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       3,     4,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,     3,     4,    64,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,     3,
       4,    64,    65,    -1,    -1,    68,    69,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
       3,     4,    64,    65,    -1,    -1,    68,    69,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,     3,     4,
      64,    65,    -1,    -1,    68,    69,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,     3,
       4,    64,    65,    -1,    -1,    68,    69,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,     3,     4,    64,
      65,    -1,    -1,    68,    69,    -1,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,     3,     4,
      64,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,     0,    -1,    -1,     3,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    68,    69,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      55,    37,    38,    39,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,     3,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     3,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    65,    -1,    -1,    -1,    -1,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     3,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    37,    38,
      39,    61,    64,    78,    79,    80,    81,    83,    84,    85,
      86,    87,    88,    96,    99,   100,   101,     3,    74,    86,
     101,   102,     3,    99,     0,    79,    73,    90,    91,    99,
       3,    83,    83,    83,     3,    74,    74,    81,    82,    83,
     113,    64,    70,   100,    74,     3,    97,    98,    86,   101,
      65,    50,    73,    51,    82,   113,    74,    85,    86,    89,
      92,    93,     3,     4,    14,    15,    16,    18,    19,    40,
      42,    43,    44,    45,    46,    47,    48,    49,    55,    59,
      60,    61,    64,    68,    69,    73,    75,    82,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   138,    81,   113,    99,     3,    65,
      83,   103,   104,   105,   106,     3,    71,   120,   121,   133,
      97,    51,    50,    75,    91,    74,   107,   119,   113,    89,
      93,    93,    75,    92,    94,    95,    99,    53,    64,   133,
     133,    64,   133,   118,    53,    64,    64,    64,     3,   110,
      64,     3,    73,    73,    73,   118,     3,    93,   109,   118,
      75,   114,    75,   110,    50,    73,     5,    52,     6,    54,
      56,    55,     7,     8,    12,    13,    57,    58,     9,    10,
      59,    60,    61,    62,    63,    51,   132,    14,    15,    17,
      64,    70,    76,    99,    65,    50,    50,    65,    71,    75,
     121,    98,   107,   108,    75,    50,    73,   110,   109,    53,
     110,   118,   118,   118,    43,    73,   118,    73,    73,    65,
      65,    75,   119,   123,   118,   124,   125,   126,   127,   128,
     128,   129,   129,   129,   129,   130,   130,   131,   131,   132,
     132,   132,   119,     3,    65,   119,   137,   118,     3,    36,
     105,     3,    50,    75,    95,    65,   110,    65,    65,    65,
      64,    73,   118,    73,   132,    53,    50,    65,    71,    75,
     107,   110,   110,   110,   118,    65,   118,    73,    73,   118,
     120,   119,    40,    65,   110,    65,    65,   118,    65,   118,
      73,    64,    73,   110,   110,    65,   110,    65,    65,   118,
     118,   110,   110,   110,    65,    65,   110,   110,    41,   110
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    93,    93,    93,    93,    94,    94,    95,    96,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   108,   108,   109,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   129,   130,   130,   130,   131,
     131,   131,   131,   132,   132,   133,   133,   133,   133,   133,
     133,   134,   134,   134,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   136,   136,   137,   137,
     138
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     3,     4,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       3,     1,     2,     1,     2,     1,     3,     1,     4,     5,
       2,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       4,     4,     3,     4,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     1,     2,     2,     3,     3,     4,     1,
       2,    12,     5,     5,     7,     6,     7,     7,     7,     8,
       8,     8,     9,     3,     2,     2,     2,     3,     1,     3,
       1,     3,     1,     5,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     4,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     1,     3,     1,     3,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 71: /* declaracion_directa: declaracion_directa '(' lista_de_tipos_de_parametros ')'  */
#line 194 "parser.y"
                                                                         { printf("Funcion: %s\n", (yyvsp[-3].sval)); }
#line 1683 "parser.tab.c"
    break;

  case 85: /* declaracion_de_parametro: especificadores_de_declaracion declarador  */
#line 223 "parser.y"
                                                          { printf("Parametro: %s\n", (yyvsp[0].sval)); }
#line 1689 "parser.tab.c"
    break;


#line 1693 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 434 "parser.y"


int main (int argc, const char * argv[])
{
	#if YYDEBUG
        yydebug = 1;
	#endif
	if (argc != 2)
	{
		puts ("Error: Se espera el nombre del archivo a analizar");
		return 1;
	}
	yyin = fopen (argv[1], "r");
	
  yyparse ();
  return 0;
}
