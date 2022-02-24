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
#line 1 "j0gramupdate.y"

    #include <stdio.h>
		#include "tree.h"
		#define YYDEBUG 1
    int yylex();
		int yyparse();
		extern int yyerror(char *s);

#line 80 "j0gramupdate.tab.c"

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
    CLASSNAME = 258,               /* CLASSNAME  */
    STRING = 259,                  /* STRING  */
    DOUBLELIT = 260,               /* DOUBLELIT  */
    NULLVAL = 261,                 /* NULLVAL  */
    BOOL = 262,                    /* BOOL  */
    BREAK = 263,                   /* BREAK  */
    CASE = 264,                    /* CASE  */
    CHAR = 265,                    /* CHAR  */
    CLASS = 266,                   /* CLASS  */
    CONTINUE = 267,                /* CONTINUE  */
    DEFAULT = 268,                 /* DEFAULT  */
    DOUBLE = 269,                  /* DOUBLE  */
    ELSE = 270,                    /* ELSE  */
    FLOAT = 271,                   /* FLOAT  */
    FOR = 272,                     /* FOR  */
    IF = 273,                      /* IF  */
    INSTANCEOF = 274,              /* INSTANCEOF  */
    INT = 275,                     /* INT  */
    LONG = 276,                    /* LONG  */
    NEW = 277,                     /* NEW  */
    PUBLIC = 278,                  /* PUBLIC  */
    RETURN = 279,                  /* RETURN  */
    STATIC = 280,                  /* STATIC  */
    SWITCH = 281,                  /* SWITCH  */
    VOID = 282,                    /* VOID  */
    WHILE = 283,                   /* WHILE  */
    REALLIT = 284,                 /* REALLIT  */
    INTLIT = 285,                  /* INTLIT  */
    STRINGLIT = 286,               /* STRINGLIT  */
    BOOLLIT = 287,                 /* BOOLLIT  */
    CHARLIT = 288,                 /* CHARLIT  */
    INCREMENT = 289,               /* INCREMENT  */
    DECREMENT = 290,               /* DECREMENT  */
    ISEQUALTO = 291,               /* ISEQUALTO  */
    NOTEQUALTO = 292,              /* NOTEQUALTO  */
    GREATERTHANOREQUAL = 293,      /* GREATERTHANOREQUAL  */
    LESSTHANOREQUAL = 294,         /* LESSTHANOREQUAL  */
    LOGICALAND = 295,              /* LOGICALAND  */
    LOGICALOR = 296,               /* LOGICALOR  */
    LOGICALNOT = 297,              /* LOGICALNOT  */
    TYPE = 298,                    /* TYPE  */
    IDENTIFIER = 299,              /* IDENTIFIER  */
    INVALIDCHARLIT = 300,          /* INVALIDCHARLIT  */
    INVALID_PUNCTUATION = 301,     /* INVALID_PUNCTUATION  */
    NOT_IN_JZERO_RESERVED = 302,   /* NOT_IN_JZERO_RESERVED  */
    UNRECOGNIZED_CHARACTER = 303,  /* UNRECOGNIZED_CHARACTER  */
    INTLIT_RANGE_INVALID = 304,    /* INTLIT_RANGE_INVALID  */
    INVALID_ESCAPE_IN_STRING = 305, /* INVALID_ESCAPE_IN_STRING  */
    REALLIT_RANGE_INVALID = 306    /* REALLIT_RANGE_INVALID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "j0gramupdate.y"

   struct tree *treeptr;

#line 182 "j0gramupdate.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASSNAME = 3,                  /* CLASSNAME  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_DOUBLELIT = 5,                  /* DOUBLELIT  */
  YYSYMBOL_NULLVAL = 6,                    /* NULLVAL  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_CASE = 9,                       /* CASE  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 13,                   /* DEFAULT  */
  YYSYMBOL_DOUBLE = 14,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_INSTANCEOF = 19,                /* INSTANCEOF  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_LONG = 21,                      /* LONG  */
  YYSYMBOL_NEW = 22,                       /* NEW  */
  YYSYMBOL_PUBLIC = 23,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_STATIC = 25,                    /* STATIC  */
  YYSYMBOL_SWITCH = 26,                    /* SWITCH  */
  YYSYMBOL_VOID = 27,                      /* VOID  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_REALLIT = 29,                   /* REALLIT  */
  YYSYMBOL_INTLIT = 30,                    /* INTLIT  */
  YYSYMBOL_STRINGLIT = 31,                 /* STRINGLIT  */
  YYSYMBOL_BOOLLIT = 32,                   /* BOOLLIT  */
  YYSYMBOL_CHARLIT = 33,                   /* CHARLIT  */
  YYSYMBOL_INCREMENT = 34,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 35,                 /* DECREMENT  */
  YYSYMBOL_ISEQUALTO = 36,                 /* ISEQUALTO  */
  YYSYMBOL_NOTEQUALTO = 37,                /* NOTEQUALTO  */
  YYSYMBOL_GREATERTHANOREQUAL = 38,        /* GREATERTHANOREQUAL  */
  YYSYMBOL_LESSTHANOREQUAL = 39,           /* LESSTHANOREQUAL  */
  YYSYMBOL_LOGICALAND = 40,                /* LOGICALAND  */
  YYSYMBOL_LOGICALOR = 41,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALNOT = 42,                /* LOGICALNOT  */
  YYSYMBOL_TYPE = 43,                      /* TYPE  */
  YYSYMBOL_IDENTIFIER = 44,                /* IDENTIFIER  */
  YYSYMBOL_INVALIDCHARLIT = 45,            /* INVALIDCHARLIT  */
  YYSYMBOL_INVALID_PUNCTUATION = 46,       /* INVALID_PUNCTUATION  */
  YYSYMBOL_NOT_IN_JZERO_RESERVED = 47,     /* NOT_IN_JZERO_RESERVED  */
  YYSYMBOL_UNRECOGNIZED_CHARACTER = 48,    /* UNRECOGNIZED_CHARACTER  */
  YYSYMBOL_INTLIT_RANGE_INVALID = 49,      /* INTLIT_RANGE_INVALID  */
  YYSYMBOL_INVALID_ESCAPE_IN_STRING = 50,  /* INVALID_ESCAPE_IN_STRING  */
  YYSYMBOL_REALLIT_RANGE_INVALID = 51,     /* REALLIT_RANGE_INVALID  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* '-'  */
  YYSYMBOL_62_ = 62,                       /* '!'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_66_ = 66,                       /* '+'  */
  YYSYMBOL_67_ = 67,                       /* '<'  */
  YYSYMBOL_68_ = 68,                       /* '>'  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_ClassDecl = 71,                 /* ClassDecl  */
  YYSYMBOL_ClassBody = 72,                 /* ClassBody  */
  YYSYMBOL_ClassBodyDecls = 73,            /* ClassBodyDecls  */
  YYSYMBOL_ClassBodyDecl = 74,             /* ClassBodyDecl  */
  YYSYMBOL_FieldDecl = 75,                 /* FieldDecl  */
  YYSYMBOL_Type = 76,                      /* Type  */
  YYSYMBOL_Name = 77,                      /* Name  */
  YYSYMBOL_QualifiedName = 78,             /* QualifiedName  */
  YYSYMBOL_VarDecls = 79,                  /* VarDecls  */
  YYSYMBOL_VarDeclarator = 80,             /* VarDeclarator  */
  YYSYMBOL_MethodReturnVal = 81,           /* MethodReturnVal  */
  YYSYMBOL_MethodDecl = 82,                /* MethodDecl  */
  YYSYMBOL_MethodHeader = 83,              /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 84,          /* MethodDeclarator  */
  YYSYMBOL_FormalParmListOpt = 85,         /* FormalParmListOpt  */
  YYSYMBOL_FormalParmList = 86,            /* FormalParmList  */
  YYSYMBOL_FormalParm = 87,                /* FormalParm  */
  YYSYMBOL_ConstructorDecl = 88,           /* ConstructorDecl  */
  YYSYMBOL_ConstructorDeclarator = 89,     /* ConstructorDeclarator  */
  YYSYMBOL_ArgListOpt = 90,                /* ArgListOpt  */
  YYSYMBOL_Block = 91,                     /* Block  */
  YYSYMBOL_BlockStmtsOpt = 92,             /* BlockStmtsOpt  */
  YYSYMBOL_BlockStmts = 93,                /* BlockStmts  */
  YYSYMBOL_BlockStmt = 94,                 /* BlockStmt  */
  YYSYMBOL_LocalVarDeclStmt = 95,          /* LocalVarDeclStmt  */
  YYSYMBOL_LocalVarDecl = 96,              /* LocalVarDecl  */
  YYSYMBOL_Stmt = 97,                      /* Stmt  */
  YYSYMBOL_ExprStmt = 98,                  /* ExprStmt  */
  YYSYMBOL_StmtExpr = 99,                  /* StmtExpr  */
  YYSYMBOL_IfThenStmt = 100,               /* IfThenStmt  */
  YYSYMBOL_IfThenElseStmt = 101,           /* IfThenElseStmt  */
  YYSYMBOL_IfThenElseIfStmt = 102,         /* IfThenElseIfStmt  */
  YYSYMBOL_ElseIfSequence = 103,           /* ElseIfSequence  */
  YYSYMBOL_ElseIfStmt = 104,               /* ElseIfStmt  */
  YYSYMBOL_WhileStmt = 105,                /* WhileStmt  */
  YYSYMBOL_ForStmt = 106,                  /* ForStmt  */
  YYSYMBOL_ForInit = 107,                  /* ForInit  */
  YYSYMBOL_ExprOpt = 108,                  /* ExprOpt  */
  YYSYMBOL_ForUpdate = 109,                /* ForUpdate  */
  YYSYMBOL_StmtExprList = 110,             /* StmtExprList  */
  YYSYMBOL_BreakStmt = 111,                /* BreakStmt  */
  YYSYMBOL_ReturnStmt = 112,               /* ReturnStmt  */
  YYSYMBOL_Primary = 113,                  /* Primary  */
  YYSYMBOL_Literal = 114,                  /* Literal  */
  YYSYMBOL_InstantiationExpr = 115,        /* InstantiationExpr  */
  YYSYMBOL_ArgList = 116,                  /* ArgList  */
  YYSYMBOL_FieldAccess = 117,              /* FieldAccess  */
  YYSYMBOL_MethodCall = 118,               /* MethodCall  */
  YYSYMBOL_PostFixExpr = 119,              /* PostFixExpr  */
  YYSYMBOL_UnaryExpr = 120,                /* UnaryExpr  */
  YYSYMBOL_MulExpr = 121,                  /* MulExpr  */
  YYSYMBOL_AddExpr = 122,                  /* AddExpr  */
  YYSYMBOL_RelOp = 123,                    /* RelOp  */
  YYSYMBOL_RelExpr = 124,                  /* RelExpr  */
  YYSYMBOL_EqExpr = 125,                   /* EqExpr  */
  YYSYMBOL_CondAndExpr = 126,              /* CondAndExpr  */
  YYSYMBOL_CondOrExpr = 127,               /* CondOrExpr  */
  YYSYMBOL_Expr = 128,                     /* Expr  */
  YYSYMBOL_Assignment = 129,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 130,             /* LeftHandSide  */
  YYSYMBOL_AssignOp = 131                  /* AssignOp  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
       2,     2,     2,    62,     2,     2,     2,    65,     2,     2,
      59,    60,    63,    66,    56,    61,    55,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
      67,    69,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    35,    35,    36,    36,    37,    37,    38,    38,    38,
      39,    40,    40,    40,    40,    40,    42,    42,    43,    45,
      45,    46,    46,    48,    48,    49,    50,    51,    52,    52,
      53,    53,    54,    56,    57,    58,    58,    60,    61,    61,
      62,    62,    63,    63,    65,    66,    68,    68,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    72,    74,    74,
      74,    76,    77,    78,    79,    81,    81,    82,    83,    85,
      86,    86,    86,    87,    87,    88,    88,    90,    90,    92,
      92,    93,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    98,    99,    99,   100,   102,   103,   104,   105,   107,
     107,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   112,   112,   112,   112,   113,   113,   115,   115,   115,
     116,   116,   117,   117,   119,   119,   120,   121,   121,   122,
     122,   122
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
  "\"end of file\"", "error", "\"invalid token\"", "CLASSNAME", "STRING",
  "DOUBLELIT", "NULLVAL", "BOOL", "BREAK", "CASE", "CHAR", "CLASS",
  "CONTINUE", "DEFAULT", "DOUBLE", "ELSE", "FLOAT", "FOR", "IF",
  "INSTANCEOF", "INT", "LONG", "NEW", "PUBLIC", "RETURN", "STATIC",
  "SWITCH", "VOID", "WHILE", "REALLIT", "INTLIT", "STRINGLIT", "BOOLLIT",
  "CHARLIT", "INCREMENT", "DECREMENT", "ISEQUALTO", "NOTEQUALTO",
  "GREATERTHANOREQUAL", "LESSTHANOREQUAL", "LOGICALAND", "LOGICALOR",
  "LOGICALNOT", "TYPE", "IDENTIFIER", "INVALIDCHARLIT",
  "INVALID_PUNCTUATION", "NOT_IN_JZERO_RESERVED", "UNRECOGNIZED_CHARACTER",
  "INTLIT_RANGE_INVALID", "INVALID_ESCAPE_IN_STRING",
  "REALLIT_RANGE_INVALID", "'{'", "'}'", "';'", "'.'", "','", "'['", "']'",
  "'('", "')'", "'-'", "'!'", "'*'", "'/'", "'%'", "'+'", "'<'", "'>'",
  "'='", "$accept", "ClassDecl", "ClassBody", "ClassBodyDecls",
  "ClassBodyDecl", "FieldDecl", "Type", "Name", "QualifiedName",
  "VarDecls", "VarDeclarator", "MethodReturnVal", "MethodDecl",
  "MethodHeader", "MethodDeclarator", "FormalParmListOpt",
  "FormalParmList", "FormalParm", "ConstructorDecl",
  "ConstructorDeclarator", "ArgListOpt", "Block", "BlockStmtsOpt",
  "BlockStmts", "BlockStmt", "LocalVarDeclStmt", "LocalVarDecl", "Stmt",
  "ExprStmt", "StmtExpr", "IfThenStmt", "IfThenElseStmt",
  "IfThenElseIfStmt", "ElseIfSequence", "ElseIfStmt", "WhileStmt",
  "ForStmt", "ForInit", "ExprOpt", "ForUpdate", "StmtExprList",
  "BreakStmt", "ReturnStmt", "Primary", "Literal", "InstantiationExpr",
  "ArgList", "FieldAccess", "MethodCall", "PostFixExpr", "UnaryExpr",
  "MulExpr", "AddExpr", "RelOp", "RelExpr", "EqExpr", "CondAndExpr",
  "CondOrExpr", "Expr", "Assignment", "LeftHandSide", "AssignOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,     7,    28,    -7,  -186,    -6,    27,  -186,  -186,  -186,
    -186,  -186,    31,    -1,  -186,   122,  -186,  -186,    23,    30,
    -186,  -186,    43,  -186,    43,    35,   114,  -186,  -186,  -186,
     -16,    46,    61,   187,  -186,  -186,  -186,  -186,  -186,    78,
      23,    64,    77,  -186,  -186,    23,    96,  -186,  -186,  -186,
     -38,    76,   100,    58,   110,  -186,  -186,  -186,  -186,    58,
      23,    13,  -186,   117,   187,  -186,  -186,   123,  -186,  -186,
     131,  -186,  -186,  -186,  -186,  -186,  -186,  -186,   116,  -186,
    -186,   -24,   132,  -186,   -10,   119,  -186,    46,  -186,   114,
      46,  -186,   134,  -186,   192,    58,    58,    58,   174,   146,
     116,  -186,  -186,  -186,    51,    26,    45,    95,   162,   145,
    -186,  -186,    58,   143,   154,    58,    58,  -186,  -186,  -186,
    -186,   169,  -186,  -186,  -186,    58,   114,  -186,  -186,  -186,
    -186,   160,   164,   156,   101,  -186,  -186,  -186,    58,  -186,
      58,    58,    58,    58,    58,  -186,  -186,  -186,  -186,    58,
      58,    58,    58,    58,   161,  -186,   172,   176,  -186,   170,
     -23,  -186,   175,    58,   222,    43,   182,  -186,  -186,  -186,
      51,    51,    26,    45,    45,    95,   162,   232,  -186,    58,
     179,    58,    58,  -186,   190,   124,  -186,   230,  -186,  -186,
    -186,   194,   188,   222,    -4,   240,  -186,  -186,  -186,   197,
     164,   199,  -186,  -186,    -4,  -186,    43,    58,  -186,  -186,
     201,    43,  -186
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,    14,    13,
      12,    11,     0,    16,     4,     0,     5,     7,     0,    15,
      17,     8,     0,     9,     0,     0,    29,     3,     6,    21,
       0,    19,     0,    39,    25,    33,    24,    16,    23,     0,
       0,     0,    28,    30,    10,     0,     0,    18,    87,    90,
       0,     0,     0,    74,     0,    86,    89,    88,    47,     0,
       0,   127,    46,     0,    38,    40,    42,     0,    43,    48,
       0,    52,    53,    54,    55,    56,    49,    50,     0,    82,
      60,    84,    59,    58,     0,     0,    26,    32,    34,     0,
      20,    22,     0,    79,    72,     0,     0,     0,   100,     0,
      99,    85,   103,   104,   108,   115,   117,   120,   122,   124,
      73,   125,     0,     0,    45,    36,    36,    37,    41,    44,
      57,     0,   130,   131,   129,     0,    29,    31,    80,    71,
      77,     0,    70,     0,   100,    84,   101,   102,    36,    81,
       0,     0,     0,     0,     0,   112,   111,   113,   114,     0,
       0,     0,     0,     0,     0,    83,     0,    35,    92,     0,
      94,   126,     0,    74,     0,     0,     0,   105,   106,   107,
     110,   109,   116,   118,   119,   121,   123,    51,    96,     0,
      91,    36,    36,    27,     0,   127,    78,    61,    95,    68,
      93,     0,     0,    76,     0,    63,    65,    98,    97,     0,
      75,     0,    62,    67,     0,    66,     0,     0,    64,    69,
       0,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -186,  -186,   244,  -186,     2,    -3,  -186,   205,
      85,  -186,  -186,  -186,  -186,   141,  -186,   180,  -186,  -186,
    -112,   -22,  -186,  -186,   204,  -186,   177,    93,  -186,   -89,
    -185,  -186,  -186,  -186,    79,  -186,  -186,  -186,   109,  -186,
      80,  -186,  -186,   -20,  -186,  -186,  -186,   -43,   -13,  -186,
     -64,    19,   126,  -186,    17,   125,   127,  -186,   -52,   -12,
    -186,  -186
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    15,    16,    17,    40,    98,    20,    30,
      31,    39,    21,    22,    86,    41,    42,    43,    23,    24,
     156,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,   195,   196,    74,    75,   131,    99,   199,
     132,    76,    77,   100,    79,    80,   157,    81,   101,   102,
     103,   104,   105,   149,   106,   107,   108,   109,   158,   111,
      84,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   110,    35,    19,   159,   130,    92,   113,    18,   203,
    -128,  -128,    19,    78,   201,     1,    93,    18,     3,   203,
      82,    83,    19,    19,   122,   123,   166,    38,     4,   181,
      61,     8,   136,   137,     9,    60,   182,     5,    44,     8,
      45,    10,     9,   133,    78,  -128,     6,    11,    33,    10,
      12,    82,    83,   135,   135,    11,    25,   -15,    26,   124,
     154,    61,    36,    48,    49,   115,    60,    29,    32,   191,
     192,    13,   116,   161,    78,   186,   167,   168,   169,    37,
      14,    82,    83,   145,   146,    32,    19,   143,    55,    56,
      57,    61,   144,   134,   134,    33,    60,   135,   135,   135,
     135,   135,    37,    46,   130,    47,   135,   135,   135,   135,
     135,   110,   147,   148,   140,   141,   142,    59,     8,    96,
      97,     9,    85,    19,    88,    87,     8,   190,    10,     9,
      90,   150,   151,    89,    11,    94,    10,   134,   134,   134,
     134,   134,    11,   187,    78,    12,   134,   134,   134,   134,
     134,    82,    83,   115,    91,   210,    32,    78,    37,    95,
     138,   185,   170,   171,    82,    83,    13,   173,   174,   112,
     117,   121,   202,    78,   185,    27,   115,   119,   126,    32,
      82,    83,   208,   116,   209,   120,   153,   -85,   128,   212,
     185,     8,    48,    49,     9,    50,     8,    48,    49,     9,
     139,    10,   152,   155,    51,    52,    10,    11,  -127,  -127,
      45,    53,    11,   160,   163,    54,   165,    55,    56,    57,
     164,   177,    55,    56,    57,   178,   115,    48,    49,    32,
     180,    37,   179,   138,   -95,   183,    37,    48,    49,    33,
      50,    58,   188,  -127,   193,   194,    59,   197,   198,    51,
      52,    59,    55,    56,    57,   204,    53,   206,   207,    28,
      54,   211,    55,    56,    57,   114,    37,   162,   118,   127,
     189,   129,   184,   200,   205,   172,    37,   175,     0,     0,
     176,    59,     0,     0,    33,     0,    58,     0,     0,     0,
       0,    59
};

static const yytype_int16 yycheck[] =
{
      22,    53,    24,     6,   116,    94,    44,    59,     6,   194,
      34,    35,    15,    33,    18,    23,    54,    15,    11,   204,
      33,    33,    25,    26,    34,    35,   138,    25,     0,    52,
      33,     4,    96,    97,     7,    33,    59,    44,    54,     4,
      56,    14,     7,    95,    64,    69,    52,    20,    52,    14,
      23,    64,    64,    96,    97,    20,    25,    44,    59,    69,
     112,    64,    27,     5,     6,    52,    64,    44,    55,   181,
     182,    44,    59,   125,    94,   164,   140,   141,   142,    44,
      53,    94,    94,    38,    39,    55,    89,    61,    30,    31,
      32,    94,    66,    96,    97,    52,    94,   140,   141,   142,
     143,   144,    44,    57,   193,    44,   149,   150,   151,   152,
     153,   163,    67,    68,    63,    64,    65,    59,     4,    61,
      62,     7,    44,   126,    60,    40,     4,   179,    14,     7,
      45,    36,    37,    56,    20,    59,    14,   140,   141,   142,
     143,   144,    20,   165,   164,    23,   149,   150,   151,   152,
     153,   164,   164,    52,    58,   207,    55,   177,    44,    59,
      59,   164,   143,   144,   177,   177,    44,   150,   151,    59,
      53,    55,   194,   193,   177,    53,    52,    54,    59,    55,
     193,   193,   204,    59,   206,    54,    41,    55,    54,   211,
     193,     4,     5,     6,     7,     8,     4,     5,     6,     7,
      54,    14,    40,    60,    17,    18,    14,    20,    34,    35,
      56,    24,    20,    44,    54,    28,    60,    30,    31,    32,
      56,    60,    30,    31,    32,    53,    52,     5,     6,    55,
      60,    44,    56,    59,    55,    60,    44,     5,     6,    52,
       8,    54,    60,    69,    54,    15,    59,    53,    60,    17,
      18,    59,    30,    31,    32,    15,    24,    60,    59,    15,
      28,    60,    30,    31,    32,    60,    44,   126,    64,    89,
     177,    94,   163,   193,   195,   149,    44,   152,    -1,    -1,
     153,    59,    -1,    -1,    52,    -1,    54,    -1,    -1,    -1,
      -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    71,    11,     0,    44,    52,    72,     4,     7,
      14,    20,    23,    44,    53,    73,    74,    75,    76,    77,
      78,    82,    83,    88,    89,    25,    59,    53,    74,    44,
      79,    80,    55,    52,    91,    91,    27,    44,    76,    81,
      76,    85,    86,    87,    54,    56,    57,    44,     5,     6,
       8,    17,    18,    24,    28,    30,    31,    32,    54,    59,
      76,    77,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   105,   106,   111,   112,   113,   114,
     115,   117,   118,   129,   130,    44,    84,    80,    60,    56,
      80,    58,    44,    54,    59,    59,    61,    62,    77,   108,
     113,   118,   119,   120,   121,   122,   124,   125,   126,   127,
     128,   129,    59,   128,    79,    52,    59,    53,    94,    54,
      54,    55,    34,    35,    69,   131,    59,    87,    54,    96,
      99,   107,   110,   128,    77,   117,   120,   120,    59,    54,
      63,    64,    65,    61,    66,    38,    39,    67,    68,   123,
      36,    37,    40,    41,   128,    60,    90,   116,   128,    90,
      44,   128,    85,    54,    56,    60,    90,   120,   120,   120,
     121,   121,   122,   124,   124,   125,   126,    60,    53,    56,
      60,    52,    59,    60,   108,    77,    99,    91,    60,    97,
     128,    90,    90,    54,    15,   103,   104,    53,    60,   109,
     110,    18,    91,   100,    15,   104,    60,    59,    91,    91,
     128,    60,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      75,    76,    76,    76,    76,    76,    77,    77,    78,    79,
      79,    80,    80,    81,    81,    82,    83,    84,    85,    85,
      86,    86,    87,    88,    89,    90,    90,    91,    92,    92,
      93,    93,    94,    94,    95,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    99,    99,
      99,   100,   101,   102,   102,   103,   103,   104,   105,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   115,   116,   116,   117,   118,   118,   118,   118,   119,
     119,   120,   120,   120,   121,   121,   121,   121,   122,   122,
     122,   123,   123,   123,   123,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   130,   130,   131,
     131,   131
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     4,     4,     1,     0,
       1,     3,     2,     2,     4,     1,     0,     3,     1,     0,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     5,     7,     6,     8,     1,     2,     2,     5,     9,
       1,     1,     0,     1,     0,     1,     0,     1,     3,     2,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     4,     4,     6,     6,     1,
       1,     2,     2,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1
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

#line 1477 "j0gramupdate.tab.c"

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

