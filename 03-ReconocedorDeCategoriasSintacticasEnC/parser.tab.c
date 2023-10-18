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
extern int yyerror (char const*s);


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
  YYSYMBOL_declarador_abstracto = 110,     /* declarador_abstracto  */
  YYSYMBOL_declarador_abstracto_directo = 111, /* declarador_abstracto_directo  */
  YYSYMBOL_sentencia = 112,                /* sentencia  */
  YYSYMBOL_sentencia_de_etiqueta = 113,    /* sentencia_de_etiqueta  */
  YYSYMBOL_sentencia_de_expresion = 114,   /* sentencia_de_expresion  */
  YYSYMBOL_sentencia_compuesta = 115,      /* sentencia_compuesta  */
  YYSYMBOL_lista_de_sentencias = 116,      /* lista_de_sentencias  */
  YYSYMBOL_sentencia_de_seleccion = 117,   /* sentencia_de_seleccion  */
  YYSYMBOL_sentencia_de_iteracion = 118,   /* sentencia_de_iteracion  */
  YYSYMBOL_sentencia_de_salto = 119,       /* sentencia_de_salto  */
  YYSYMBOL_expresion = 120,                /* expresion  */
  YYSYMBOL_expresion_de_asignacion = 121,  /* expresion_de_asignacion  */
  YYSYMBOL_expresion_condicional = 122,    /* expresion_condicional  */
  YYSYMBOL_expresion_constante = 123,      /* expresion_constante  */
  YYSYMBOL_expresion_logica_OR = 124,      /* expresion_logica_OR  */
  YYSYMBOL_expresion_logica_AND = 125,     /* expresion_logica_AND  */
  YYSYMBOL_expresion_OR_inclusiva = 126,   /* expresion_OR_inclusiva  */
  YYSYMBOL_expresion_OR_exclusiva = 127,   /* expresion_OR_exclusiva  */
  YYSYMBOL_expresion_AND = 128,            /* expresion_AND  */
  YYSYMBOL_expresion_de_igualdad = 129,    /* expresion_de_igualdad  */
  YYSYMBOL_expresion_relacional = 130,     /* expresion_relacional  */
  YYSYMBOL_expresion_de_desplazamiento = 131, /* expresion_de_desplazamiento  */
  YYSYMBOL_expresion_aditiva = 132,        /* expresion_aditiva  */
  YYSYMBOL_expresion_multiplicativa = 133, /* expresion_multiplicativa  */
  YYSYMBOL_expresion_de_casteo = 134,      /* expresion_de_casteo  */
  YYSYMBOL_expresion_unaria = 135,         /* expresion_unaria  */
  YYSYMBOL_operador_unario = 136,          /* operador_unario  */
  YYSYMBOL_expresion_posfija = 137,        /* expresion_posfija  */
  YYSYMBOL_expresion_primaria = 138,       /* expresion_primaria  */
  YYSYMBOL_lista_de_expresiones_de_argumentos = 139, /* lista_de_expresiones_de_argumentos  */
  YYSYMBOL_constante = 140                 /* constante  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  357

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
       0,    61,    61,    62,    66,    67,    71,    72,    73,    74,
      78,    79,    83,    84,    88,    89,    90,    91,    92,    93,
      97,    98,    99,   100,   101,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   119,   120,   124,   125,
     126,   130,   131,   135,   136,   140,   141,   145,   146,   150,
     154,   155,   156,   157,   161,   162,   166,   170,   171,   172,
     176,   177,   181,   182,   186,   187,   191,   192,   193,   194,
     195,   196,   197,   201,   202,   203,   204,   208,   209,   213,
     214,   218,   219,   223,   224,   225,   229,   230,   234,   235,
     236,   240,   241,   245,   246,   250,   251,   252,   256,   257,
     258,   259,   260,   264,   265,   266,   267,   268,   269,   273,
     274,   275,   279,   280,   284,   285,   286,   287,   291,   292,
     296,   298,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   315,   316,   317,   318,   319,   323,   324,   328,
     329,   333,   334,   338,   342,   343,   347,   348,   352,   353,
     357,   358,   362,   363,   367,   368,   369,   373,   374,   375,
     376,   377,   381,   382,   383,   387,   388,   389,   393,   394,
     395,   396,   400,   401,   405,   406,   407,   408,   409,   410,
     414,   415,   416,   417,   418,   419,   423,   424,   425,   426,
     427,   428,   429,   430,   434,   435,   436,   440,   441,   445
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
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
  "nombre_de_tipo", "declarador_abstracto", "declarador_abstracto_directo",
  "sentencia", "sentencia_de_etiqueta", "sentencia_de_expresion",
  "sentencia_compuesta", "lista_de_sentencias", "sentencia_de_seleccion",
  "sentencia_de_iteracion", "sentencia_de_salto", "expresion",
  "expresion_de_asignacion", "expresion_condicional",
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

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1175,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
       6,    31,    40,  1084,  -203,  -203,  -203,     9,  1321,  1321,
    1321,  -203,    14,  -203,  1227,     5,    15,   -43,    32,  -203,
    -203,    31,   -21,  -203,  -203,  -203,     4,  -203,  1195,  -203,
    -203,  -203,   -34,  1270,   274,  -203,  1227,     9,  -203,  1129,
     725,     5,    32,    36,   -25,  -203,  -203,  -203,  -203,    40,
    -203,   556,  1227,  -203,  1270,  1270,  1270,   722,  -203,    40,
      -2,  -203,  1006,  1006,  1034,  1065,    44,    35,    45,    62,
     539,    67,   142,    82,   115,   618,  -203,  -203,  -203,  -203,
     829,  -203,  -203,  -203,  -203,   336,  -203,  -203,  -203,  -203,
     398,  -203,  -203,  -203,    22,  -203,  -203,    10,   187,   145,
     139,   149,   241,   124,   258,   224,   218,  -203,   164,  1065,
      51,  -203,  -203,  -203,  -203,   173,  -203,  -203,    71,   167,
     185,  -203,   127,  -203,  -203,  -203,   170,  -203,   -23,  1065,
      32,  -203,  -203,   556,  -203,  -203,  -203,   799,  -203,  -203,
    -203,  -203,    55,  -203,  -203,   539,  1065,  -203,  -203,   829,
    -203,    89,   539,  1065,  1065,  1065,   222,   633,   178,  -203,
    -203,  -203,    75,   221,   189,   137,  -203,   460,  -203,  -203,
    1065,  -203,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,
    1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,
    1065,  1065,  -203,  -203,  -203,   283,   857,  1065,   307,   778,
    1065,  -203,    30,  -203,   152,  -203,  1301,   312,  -203,  -203,
    -203,  -203,  -203,  -203,    -8,  -203,    40,  -203,  -203,   261,
     539,  -203,   140,   141,   146,   266,   648,   103,  -203,  -203,
    1250,   159,  -203,  1065,  -203,  -203,  -203,   187,   144,   145,
     139,   149,   241,   124,   124,   258,   258,   258,   258,   224,
     224,   218,   218,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
     163,   136,  -203,   267,   271,   260,   152,  1321,  1065,  -203,
    -203,  -203,   477,  -203,  -203,  -203,  -203,   539,   539,   539,
    1065,   888,   107,   710,  -203,  1065,  1065,  -203,  -203,  -203,
    -203,  -203,   272,   270,  -203,  -203,   304,  -203,  -203,   168,
     539,   171,   916,   947,   125,  -203,  -203,  -203,  -203,   281,
     273,  -203,   539,   539,   177,   539,   207,   975,  1065,  -203,
    -203,  -203,   539,  -203,   539,   539,   208,   211,  -203,  -203,
    -203,   539,   539,  -203,   331,   539,  -203
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    66,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    36,    37,    20,    21,    22,    23,    24,    41,    42,
       0,    73,     0,     0,     2,     4,     5,     0,    14,    16,
      18,    34,     0,    35,     0,    64,     0,    59,     0,    77,
      75,    74,     0,     1,     3,    10,     0,    45,    47,    15,
      17,    19,    40,     0,     0,    12,     0,     0,     6,     0,
       0,    65,     0,    62,     0,    60,    78,    76,    67,     0,
      11,     0,     0,     8,     0,    50,    52,     0,    43,     0,
     194,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   182,   183,   184,
       0,   180,   181,   112,   114,     0,   118,   103,   104,   105,
       0,   106,   107,   108,     0,   137,   139,   141,   144,   146,
     148,   150,   152,   154,   157,   162,   165,   168,   172,     0,
     174,   186,   195,    13,     7,    47,    86,    71,    83,     0,
      79,    81,     0,   194,    68,   143,     0,   172,     0,     0,
       0,    57,    46,     0,    48,    88,     9,     0,    51,    53,
      38,    44,     0,    54,    56,     0,     0,   175,   176,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,   133,
     134,   135,     0,    93,     0,     0,   116,     0,   115,   119,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   192,   193,     0,     0,     0,     0,     0,
       0,    84,    95,    85,    96,    70,     0,     0,    72,    69,
      58,    63,    61,    91,     0,    39,     0,    49,   109,     0,
       0,   111,     0,     0,     0,     0,     0,     0,   132,   136,
       0,    95,    94,     0,   196,   117,   138,   145,     0,   147,
     149,   151,   153,   155,   156,   159,   161,   158,   160,   163,
     164,   166,   167,   169,   170,   171,   140,   191,   188,   197,
       0,     0,   190,     0,     0,     0,    97,     0,     0,    80,
      82,    87,     0,    89,    55,   179,   110,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,   189,   187,   101,
      98,    99,     0,     0,    90,    92,     0,   121,   122,     0,
       0,     0,     0,     0,     0,   142,   198,   102,   100,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,   123,
     127,   126,     0,   125,     0,     0,     0,     0,   130,   129,
     128,     0,     0,   131,     0,     0,   120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,   330,  -203,   129,    -9,     0,  -203,   -19,    43,
    -203,  -203,   303,  -203,   321,   -72,   -62,  -203,   156,  -203,
     332,   243,   -16,   -33,    -5,  -203,   -57,  -203,   172,  -203,
    -145,  -203,   230,  -112,  -202,   -89,  -203,  -203,    68,   298,
    -203,  -203,  -203,   -63,   -67,   -41,  -142,  -203,   214,   213,
     220,   212,   223,    72,   186,   120,   121,  -119,   -36,  -203,
    -203,  -203,  -203,  -203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    23,    24,    25,    55,    56,    57,    28,    29,    30,
      31,    32,    77,    46,    47,    78,    79,   162,   163,    33,
      64,    65,    34,    35,    36,    41,   283,   140,   141,   142,
     154,   234,   184,   284,   224,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   146,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   280,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   176,   139,    61,   155,   161,    42,   231,   233,    37,
     212,    48,     1,   158,   159,   192,    40,    52,     1,   145,
     286,   189,   171,    27,   147,   150,   223,   150,    49,    50,
      51,    62,   182,     1,    75,    63,    67,   185,   183,    72,
      74,   135,   292,     1,    68,   105,   167,   168,   170,   286,
     151,   165,   230,   135,    69,    75,    75,    75,    75,   138,
      11,    12,   193,   164,    39,   213,   214,   293,   215,    59,
      21,   252,   190,    22,     1,    60,   238,    70,   285,    22,
      38,    75,    45,   241,    66,   161,   155,   149,    53,   273,
     274,   275,    21,   147,   219,   191,    76,   172,   189,   173,
     220,    21,    58,   185,    22,   236,   185,   183,   145,   174,
     242,   243,   244,   147,   247,   216,    73,    76,    76,    76,
      76,   217,   221,   256,   134,   190,   175,   218,   237,    26,
     258,   177,    21,   222,   304,   219,   200,   201,    75,   190,
     156,   220,   240,    76,   276,   178,   313,   315,   249,   279,
      75,   296,    26,   190,   281,   179,   147,   190,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   190,   303,   227,   251,   145,
     322,   202,   203,   302,   147,   133,   190,   190,   180,    61,
     190,   190,   228,   194,   190,   196,   190,   305,   337,   195,
      76,   133,   254,    42,   197,   297,   298,   308,   316,   317,
     318,   299,    76,   306,   222,   211,   287,   147,   190,   138,
     164,   190,   288,   250,    71,   155,   138,   190,   307,   220,
     312,   331,   225,   330,   133,   226,   332,   319,   321,   326,
     324,   229,   342,   340,   341,   251,   343,   145,   198,   199,
     138,   248,   147,   348,   253,   349,   350,   190,   190,   334,
     336,   190,   353,   354,   325,   245,   356,   204,   205,   147,
     263,   264,   344,   351,   346,   347,   352,    80,    81,   208,
     209,   210,    21,   206,   207,   250,   277,   138,    82,    83,
      84,   220,    85,    86,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     282,    18,    19,    20,    87,   291,    88,    89,    90,    91,
      92,    93,    94,    95,   269,   270,   295,   271,   272,    96,
     300,   311,   309,    97,    98,    99,   310,   327,   100,    80,
      81,   328,   101,   102,   329,   338,   339,   103,    54,   104,
      82,    83,    84,    44,    85,    86,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   355,    18,    19,    20,    87,   157,    88,    89,
      90,    91,    92,    93,    94,    95,   265,   266,   267,   268,
     152,    96,   294,   232,   148,    97,    98,    99,   290,   239,
     100,    80,    81,   187,   101,   102,   257,   259,   261,   103,
      54,   186,    82,    83,    84,   260,    85,    86,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,     0,     0,     0,    97,    98,    99,
       0,     0,   100,    80,    81,     0,   101,   102,     0,     0,
       0,   103,    54,   188,    82,    83,    84,     0,    85,    86,
     143,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,     0,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,     0,     0,     0,    97,
      98,    99,     0,     0,   100,     0,     0,     0,   101,   102,
       0,     0,    96,   103,    54,   255,    97,    98,    99,     0,
       0,   100,    80,    81,     0,   101,   102,     0,     0,     0,
       0,   153,   314,    82,    83,    84,     0,    85,    86,   143,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,     0,     0,     0,    97,    98,
      99,     0,     0,   100,     0,     0,     0,   101,   102,     0,
       0,    96,   103,    54,     0,    97,    98,    99,     0,     0,
     100,   143,    81,     0,   101,   102,     0,     0,     0,     0,
     153,     0,    82,    83,    84,     0,   143,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,   143,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,    97,    98,    99,
       0,     0,   100,     0,     0,     0,   101,   102,    96,     0,
       0,   181,    97,    98,    99,     0,     0,   100,     0,     0,
       0,   101,   102,    96,     0,     0,   246,    97,    98,    99,
       0,     0,   100,   143,    81,     0,   101,   102,     0,     0,
       0,   301,     0,     0,    82,    83,    84,     0,   143,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,    96,     0,     0,     0,    97,
      98,    99,     0,     0,   100,     0,     0,     0,   101,   102,
      96,     1,     0,   323,    97,    98,    99,     0,     0,   100,
       0,     0,     0,   101,   102,     0,   144,   160,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,   143,    81,     0,     0,    18,    19,    20,    21,
       0,     0,   219,    82,    83,    84,     0,     0,   220,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
     143,    81,     0,     0,     0,     0,    18,    19,    20,     0,
       0,    82,    83,    84,   235,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,    97,    98,
      99,   143,    81,   100,     0,     0,     0,   101,   102,     0,
       0,     0,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,    97,    98,    99,   143,
      81,   100,   278,     0,     0,   101,   102,     0,     0,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,    97,    98,    99,
     143,    81,   100,   320,     0,     0,   101,   102,     0,     0,
       0,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,    97,    98,    99,   143,    81,
     100,   333,     0,     0,   101,   102,     0,     0,     0,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,    97,    98,    99,   143,
      81,   100,   335,     0,     0,   101,   102,     0,     0,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,    97,    98,    99,   143,    81,   100,
     345,     0,     0,   101,   102,     0,     0,     0,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     0,    97,    98,    99,   143,    81,
     166,     0,     0,     0,   101,   102,     0,     0,     0,    82,
      83,    84,     0,     0,    43,     0,     0,     1,     0,    96,
       0,     0,     0,    97,    98,    99,     0,     0,   169,     0,
       0,     0,   101,   102,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      96,    18,    19,    20,    97,    98,    99,     0,     0,   100,
       0,     0,   136,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,    22,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,    18,    19,    20,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,    18,    19,    20,     0,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    71,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,    18,    19,    20,     0,     0,    54,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,    18,    19,    20,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    54,     0,     0,     0,     0,     0,    18,    19,    20,
       0,    21,     0,     0,   250,     0,     0,     0,     0,     0,
     220,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   289,    18,    19,
      20,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,    18,    19,
      20
};

static const yytype_int16 yycheck[] =
{
       0,    90,    59,    36,    71,    77,    22,   149,   153,     3,
     129,    27,     3,    75,    76,     5,    21,     3,     3,    60,
     222,   110,    85,    23,    60,    50,   138,    50,    28,    29,
      30,    74,    95,     3,    53,     3,    41,   100,   100,    48,
      74,    57,    50,     3,    65,    54,    82,    83,    84,   251,
      75,    53,    75,    69,    50,    74,    75,    76,    77,    59,
      29,    30,    52,    79,    21,    14,    15,    75,    17,    64,
      61,   183,    50,    64,     3,    70,   165,    73,   220,    64,
      74,   100,    73,   172,    41,   157,   153,    51,    74,   208,
     209,   210,    61,   129,    64,    73,    53,    53,   187,    64,
      70,    61,    34,   166,    64,    50,   169,   169,   149,    64,
     173,   174,   175,   149,   177,    64,    48,    74,    75,    76,
      77,    70,   138,   190,    56,    50,    64,    76,    73,     0,
     193,    64,    61,   138,   253,    64,    12,    13,   157,    50,
      72,    70,    53,   100,   211,     3,   288,   292,    73,   216,
     169,   240,    23,    50,   217,    73,   192,    50,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    50,    73,    50,   183,   220,
      73,    57,    58,   246,   220,    56,    50,    50,    73,   222,
      50,    50,    65,     6,    50,    56,    50,    53,    73,    54,
     157,    72,    65,   219,    55,    65,    65,    71,   297,   298,
     299,    65,   169,    50,   219,    51,    64,   253,    50,   219,
     236,    50,    70,    64,    51,   292,   226,    50,    65,    70,
     287,   320,    65,    65,   105,    50,    65,   300,   301,   306,
     303,    71,    65,   332,   333,   250,   335,   288,     7,     8,
     250,    73,   288,   342,    65,   344,   345,    50,    50,   322,
     323,    50,   351,   352,   305,    43,   355,     9,    10,   305,
     198,   199,    65,    65,   337,   338,    65,     3,     4,    61,
      62,    63,    61,    59,    60,    64,     3,   287,    14,    15,
      16,    70,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       3,    37,    38,    39,    40,     3,    42,    43,    44,    45,
      46,    47,    48,    49,   204,   205,    65,   206,   207,    55,
      64,    71,    65,    59,    60,    61,    65,    65,    64,     3,
       4,    71,    68,    69,    40,    64,    73,    73,    74,    75,
      14,    15,    16,    23,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    41,    37,    38,    39,    40,    74,    42,    43,
      44,    45,    46,    47,    48,    49,   200,   201,   202,   203,
      69,    55,   236,   150,    62,    59,    60,    61,   226,   169,
      64,     3,     4,   105,    68,    69,   192,   194,   196,    73,
      74,    75,    14,    15,    16,   195,    18,    19,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,     3,     4,    -1,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    14,    15,    16,    -1,    18,    19,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,
      -1,    -1,    55,    73,    74,    75,    59,    60,    61,    -1,
      -1,    64,     3,     4,    -1,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    14,    15,    16,    -1,    18,    19,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,    -1,
      -1,    55,    73,    74,    -1,    59,    60,    61,    -1,    -1,
      64,     3,     4,    -1,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    14,    15,    16,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    69,    55,    -1,
      -1,    73,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    69,    55,    -1,    -1,    73,    59,    60,    61,
      -1,    -1,    64,     3,     4,    -1,    68,    69,    -1,    -1,
      -1,    73,    -1,    -1,    14,    15,    16,    -1,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    68,    69,
      55,     3,    -1,    73,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    68,    69,    -1,    71,    75,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,     3,     4,    -1,    -1,    37,    38,    39,    61,
      -1,    -1,    64,    14,    15,    16,    -1,    -1,    70,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       3,     4,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      -1,    14,    15,    16,    75,    -1,    -1,    -1,    -1,    -1,
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
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    -1,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    -1,    -1,    74,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    38,    39,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    74,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    37,    38,
      39,    61,    64,    78,    79,    80,    81,    83,    84,    85,
      86,    87,    88,    96,    99,   100,   101,     3,    74,    86,
     101,   102,    99,     0,    79,    73,    90,    91,    99,    83,
      83,    83,     3,    74,    74,    81,    82,    83,   115,    64,
      70,   100,    74,     3,    97,    98,    86,   101,    65,    50,
      73,    51,    82,   115,    74,    85,    86,    89,    92,    93,
       3,     4,    14,    15,    16,    18,    19,    40,    42,    43,
      44,    45,    46,    47,    48,    49,    55,    59,    60,    61,
      64,    68,    69,    73,    75,    82,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   140,    81,   115,    99,     3,    65,    83,   103,
     104,   105,   106,     3,    71,   122,   123,   135,    97,    51,
      50,    75,    91,    74,   107,   121,   115,    89,    93,    93,
      75,    92,    94,    95,    99,    53,    64,   135,   135,    64,
     135,   120,    53,    64,    64,    64,   112,    64,     3,    73,
      73,    73,   120,    93,   109,   120,    75,   116,    75,   112,
      50,    73,     5,    52,     6,    54,    56,    55,     7,     8,
      12,    13,    57,    58,     9,    10,    59,    60,    61,    62,
      63,    51,   134,    14,    15,    17,    64,    70,    76,    64,
      70,    99,   101,   110,   111,    65,    50,    50,    65,    71,
      75,   123,    98,   107,   108,    75,    50,    73,   112,   109,
      53,   112,   120,   120,   120,    43,    73,   120,    73,    73,
      64,   101,   110,    65,    65,    75,   121,   125,   120,   126,
     127,   128,   129,   130,   130,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   134,   121,     3,    65,   121,
     139,   120,     3,   103,   110,   123,   111,    64,    70,    36,
     105,     3,    50,    75,    95,    65,   112,    65,    65,    65,
      64,    73,   120,    73,   134,    53,    50,    65,    71,    65,
      65,    71,   103,   123,    75,   107,   112,   112,   112,   120,
      65,   120,    73,    73,   120,   122,   121,    65,    71,    40,
      65,   112,    65,    65,   120,    65,   120,    73,    64,    73,
     112,   112,    65,   112,    65,    65,   120,   120,   112,   112,
     112,    65,    65,   112,   112,    41,   112
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      93,    93,    93,    93,    94,    94,    95,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   101,   101,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   106,   106,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   115,   115,   115,   115,   116,   116,
     117,   117,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   129,   130,   130,   130,
     130,   130,   131,   131,   131,   132,   132,   132,   133,   133,
     133,   133,   134,   134,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   137,   137,   137,   137,
     137,   137,   137,   137,   138,   138,   138,   139,   139,   140
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     3,     4,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     3,
       1,     2,     1,     2,     1,     3,     1,     4,     5,     2,
       1,     3,     1,     3,     1,     2,     1,     3,     3,     4,
       4,     3,     4,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     1,     2,     2,     1,     3,     1,     3,
       4,     1,     3,     1,     2,     1,     1,     2,     3,     3,
       4,     3,     4,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1,     2,     2,     3,     3,     4,     1,     2,
      12,     5,     5,     7,     6,     7,     7,     7,     8,     8,
       8,     9,     3,     2,     2,     2,     3,     1,     3,     1,
       3,     1,     5,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     1,     3,     1,     3,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 70: /* declaracion_directa: declaracion_directa '(' lista_de_tipos_de_parametros ')'  */
#line 195 "parser.y"
                                                                         { printf("Funcion: %s\n", (yyvsp[-3].sval)); }
#line 1952 "parser.tab.c"
    break;

  case 84: /* declaracion_de_parametro: especificadores_de_declaracion declarador  */
#line 224 "parser.y"
                                                          { printf("Parametro: %s\n", (yyvsp[0].sval)); }
#line 1958 "parser.tab.c"
    break;


#line 1962 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 448 "parser.y"


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
