/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "j0gram.y"

	#define YYDEBUG 1

	extern int yylex();
	extern int yyerror(const char *s);

	#include <stdio.h>
	#include "tree.h"
	#include "symboltable.h"

	struct tree *root;

#line 71 "j0gram.tab.c"

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
    REALLIT_RANGE_INVALID = 306,   /* REALLIT_RANGE_INVALID  */
    INVALID_CHARLIT_ESCAPE = 307,  /* INVALID_CHARLIT_ESCAPE  */
    EMPTY_CHARLIT = 308,           /* EMPTY_CHARLIT  */
    OPENENDED_CHARLIT = 309        /* OPENENDED_CHARLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "j0gram.y"

   struct tree *treeptr;

#line 175 "j0gram.tab.c"

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
  YYSYMBOL_INVALID_CHARLIT_ESCAPE = 52,    /* INVALID_CHARLIT_ESCAPE  */
  YYSYMBOL_EMPTY_CHARLIT = 53,             /* EMPTY_CHARLIT  */
  YYSYMBOL_OPENENDED_CHARLIT = 54,         /* OPENENDED_CHARLIT  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '+'  */
  YYSYMBOL_57_ = 57,                       /* '!'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* '<'  */
  YYSYMBOL_60_ = 60,                       /* '>'  */
  YYSYMBOL_61_ = 61,                       /* '*'  */
  YYSYMBOL_62_ = 62,                       /* '/'  */
  YYSYMBOL_63_ = 63,                       /* '%'  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* '.'  */
  YYSYMBOL_68_ = 68,                       /* '['  */
  YYSYMBOL_69_ = 69,                       /* ']'  */
  YYSYMBOL_70_ = 70,                       /* '('  */
  YYSYMBOL_71_ = 71,                       /* ')'  */
  YYSYMBOL_72_ = 72,                       /* ','  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_ClassDecl = 74,                 /* ClassDecl  */
  YYSYMBOL_ClassBody = 75,                 /* ClassBody  */
  YYSYMBOL_ClassBodyDecls = 76,            /* ClassBodyDecls  */
  YYSYMBOL_ClassBodyDecl = 77,             /* ClassBodyDecl  */
  YYSYMBOL_FieldDecl = 78,                 /* FieldDecl  */
  YYSYMBOL_Type = 79,                      /* Type  */
  YYSYMBOL_Name = 80,                      /* Name  */
  YYSYMBOL_QualifiedName = 81,             /* QualifiedName  */
  YYSYMBOL_VarDecls = 82,                  /* VarDecls  */
  YYSYMBOL_VarDeclarator = 83,             /* VarDeclarator  */
  YYSYMBOL_MethodReturnVal = 84,           /* MethodReturnVal  */
  YYSYMBOL_MethodDecl = 85,                /* MethodDecl  */
  YYSYMBOL_MethodHeader = 86,              /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 87,          /* MethodDeclarator  */
  YYSYMBOL_FormalParmListOpt = 88,         /* FormalParmListOpt  */
  YYSYMBOL_FormalParmList = 89,            /* FormalParmList  */
  YYSYMBOL_FormalParm = 90,                /* FormalParm  */
  YYSYMBOL_ConstructorDecl = 91,           /* ConstructorDecl  */
  YYSYMBOL_ConstructorDeclarator = 92,     /* ConstructorDeclarator  */
  YYSYMBOL_ArgListOpt = 93,                /* ArgListOpt  */
  YYSYMBOL_Block = 94,                     /* Block  */
  YYSYMBOL_BlockStmtsOpt = 95,             /* BlockStmtsOpt  */
  YYSYMBOL_BlockStmts = 96,                /* BlockStmts  */
  YYSYMBOL_BlockStmt = 97,                 /* BlockStmt  */
  YYSYMBOL_LocalVarDeclStmt = 98,          /* LocalVarDeclStmt  */
  YYSYMBOL_LocalVarDecl = 99,              /* LocalVarDecl  */
  YYSYMBOL_Stmt = 100,                     /* Stmt  */
  YYSYMBOL_ExprStmt = 101,                 /* ExprStmt  */
  YYSYMBOL_StmtExpr = 102,                 /* StmtExpr  */
  YYSYMBOL_IfThenStmt = 103,               /* IfThenStmt  */
  YYSYMBOL_IfThenElseStmt = 104,           /* IfThenElseStmt  */
  YYSYMBOL_IfThenElseIfStmt = 105,         /* IfThenElseIfStmt  */
  YYSYMBOL_ElseIfSequence = 106,           /* ElseIfSequence  */
  YYSYMBOL_ElseIfStmt = 107,               /* ElseIfStmt  */
  YYSYMBOL_WhileStmt = 108,                /* WhileStmt  */
  YYSYMBOL_ForStmt = 109,                  /* ForStmt  */
  YYSYMBOL_ForInit = 110,                  /* ForInit  */
  YYSYMBOL_ExprOpt = 111,                  /* ExprOpt  */
  YYSYMBOL_ForUpdate = 112,                /* ForUpdate  */
  YYSYMBOL_StmtExprList = 113,             /* StmtExprList  */
  YYSYMBOL_BreakStmt = 114,                /* BreakStmt  */
  YYSYMBOL_ReturnStmt = 115,               /* ReturnStmt  */
  YYSYMBOL_Primary = 116,                  /* Primary  */
  YYSYMBOL_Literal = 117,                  /* Literal  */
  YYSYMBOL_InstantiationExpr = 118,        /* InstantiationExpr  */
  YYSYMBOL_ArgList = 119,                  /* ArgList  */
  YYSYMBOL_FieldAccess = 120,              /* FieldAccess  */
  YYSYMBOL_MethodCall = 121,               /* MethodCall  */
  YYSYMBOL_PostFixExpr = 122,              /* PostFixExpr  */
  YYSYMBOL_UnaryExpr = 123,                /* UnaryExpr  */
  YYSYMBOL_MulExpr = 124,                  /* MulExpr  */
  YYSYMBOL_AddExpr = 125,                  /* AddExpr  */
  YYSYMBOL_RelOp = 126,                    /* RelOp  */
  YYSYMBOL_RelExpr = 127,                  /* RelExpr  */
  YYSYMBOL_EqExpr = 128,                   /* EqExpr  */
  YYSYMBOL_CondAndExpr = 129,              /* CondAndExpr  */
  YYSYMBOL_CondOrExpr = 130,               /* CondOrExpr  */
  YYSYMBOL_Expr = 131,                     /* Expr  */
  YYSYMBOL_Assignment = 132,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 133,             /* LeftHandSide  */
  YYSYMBOL_AssignOp = 134                  /* AssignOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309

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
       2,     2,     2,    57,     2,     2,     2,    63,     2,     2,
      70,    71,    61,    56,    72,    55,    67,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
      59,    58,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   127,   129,   133,   135,   139,   141,   143,
     147,   153,   155,   157,   159,   161,   163,   165,   169,   171,
     175,   180,   186,   188,   190,   195,   197,   201,   205,   231,
     235,   238,   241,   243,   247,   252,   256,   260,   263,   266,
     270,   273,   276,   278,   282,   284,   289,   293,   298,   300,
     302,   304,   306,   309,   311,   313,   316,   318,   323,   328,
     330,   332,   337,   341,   345,   348,   353,   355,   359,   363,
     368,   372,   374,   377,   380,   383,   386,   389,   393,   395,
     400,   402,   406,   411,   413,   415,   417,   421,   423,   425,
     427,   429,   431,   433,   438,   442,   444,   448,   453,   456,
     459,   462,   467,   469,   473,   475,   477,   481,   483,   486,
     488,   492,   494,   496,   500,   502,   504,   506,   510,   512,
     517,   519,   521,   525,   527,   531,   533,   538,   540,   544,
     546,   548,   552,   554,   558,   560,   562
};
#endif

#define YYPACT_NINF (-187)
#define YYTABLE_NINF (-134)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,     5,    20,    -4,  -187,   -29,    49,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,    30,    21,  -187,   305,  -187,  -187,
     -40,  -187,  -187,  -187,   -19,  -187,   -19,    99,    16,   248,
    -187,  -187,  -187,     2,     7,    11,   201,  -187,  -187,  -187,
       8,  -187,    48,  -187,   -40,    19,    24,  -187,   -40,  -187,
      33,  -187,  -187,    -8,    29,    35,    16,   243,    38,  -187,
    -187,  -187,  -187,  -187,  -187,   243,   -40,   -27,  -187,    45,
     201,  -187,  -187,    57,  -187,  -187,    74,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,    75,  -187,  -187,    -9,    92,  -187,
      46,   100,  -187,    11,  -187,   248,   103,  -187,   107,  -187,
     274,   243,   102,   106,   106,   -40,   156,   108,    75,  -187,
    -187,  -187,    69,    72,    62,    81,   135,   136,  -187,  -187,
     243,   112,  -187,    -1,   243,   243,  -187,  -187,  -187,  -187,
     140,  -187,  -187,  -187,   243,   248,  -187,  -187,  -187,  -187,
     113,   114,   117,   243,   -46,  -187,  -187,  -187,    -1,  -187,
     106,   106,   106,   106,   106,  -187,  -187,  -187,  -187,   106,
     106,   106,   106,   106,   118,  -187,   243,   120,   121,  -187,
     123,    -2,  -187,   124,   243,   274,   -19,   125,  -187,  -187,
    -187,    69,    69,    72,    62,    62,    81,   135,   201,  -187,
    -187,   243,  -187,   243,   243,  -187,   126,  -187,   186,  -187,
    -187,  -187,   137,   132,   274,   -16,   195,  -187,  -187,  -187,
     141,   114,   143,  -187,  -187,   -16,  -187,   -19,   243,  -187,
    -187,   145,   -19,  -187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,    14,    13,
      16,    12,    17,    11,     0,    18,     4,     0,     5,     7,
       0,    15,    19,     8,     0,     9,     0,     0,     0,    31,
       3,     6,    22,     0,     0,    21,    41,    27,    35,    26,
      18,    25,     0,    20,     0,     0,    30,    32,     0,    10,
       0,    88,    93,     0,     0,     0,     0,    75,     0,    89,
      87,    92,    90,    91,    49,     0,     0,   132,    48,     0,
      40,    42,    44,     0,    45,    50,     0,    53,    54,    55,
      56,    57,    51,    52,     0,    83,    61,    85,    60,    59,
       0,     0,    28,    34,    36,     0,    24,    23,     0,    80,
      73,     0,     0,     0,     0,     0,   103,     0,   102,    86,
     106,   107,   111,   118,   120,   123,   125,   127,    74,   128,
       0,     0,    47,    21,    38,    38,    39,    43,    46,    58,
       0,   135,   136,   134,   130,    31,    33,    81,    72,    78,
       0,    71,     0,    38,   103,    85,   104,   105,     0,    82,
       0,     0,     0,     0,     0,   115,   114,   116,   117,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    37,    95,
       0,    97,   129,     0,    75,     0,     0,     0,   108,   109,
     110,   113,   112,   119,   121,   122,   124,   126,     0,   131,
      99,     0,    98,    38,    38,    29,     0,    79,    62,    94,
      69,    96,     0,     0,    77,     0,    64,    66,   101,   100,
       0,    76,     0,    63,    68,     0,    67,     0,     0,    65,
      70,     0,     0,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,   205,  -187,    25,    -6,  -187,   161,
     -39,  -187,  -187,  -187,  -187,    93,  -187,   142,  -187,  -187,
    -111,   -18,  -187,  -187,   165,  -187,   138,    51,  -187,   -97,
    -186,  -187,  -187,  -187,    34,  -187,  -187,  -187,    67,  -187,
      32,  -187,  -187,   -26,  -187,  -187,  -187,   179,   -24,  -187,
     -65,   -20,    83,  -187,     6,    82,    80,  -187,   -50,   -23,
    -187,   164
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    17,    18,    19,   105,   106,    22,    34,
      35,    42,    23,    24,    92,    45,    46,    47,    25,    26,
     167,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   206,   207,    80,    81,   140,   107,   210,
     141,    82,    83,   108,    85,    86,   168,    87,   109,   110,
     111,   112,   113,   159,   114,   115,   116,   117,   169,   119,
      90,   166
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,     1,   212,   139,    32,    93,    37,   118,    38,    96,
      84,    21,    88,    89,   170,   121,     3,   -15,   124,   214,
       4,    21,    43,    21,   125,  -133,  -133,   123,    33,   214,
      67,    20,   177,   131,   132,     6,    98,   124,   146,   147,
       5,   -15,    20,   125,    84,    36,    88,    89,    36,  -133,
     102,   142,    41,     8,    44,    27,     9,   133,    99,    10,
      40,    66,   193,    11,    67,    12,   148,    50,   194,    13,
     164,    48,    14,    49,    84,    28,    88,    89,   197,    50,
     131,   132,   202,   203,   172,   178,   179,   180,    28,    21,
      94,    29,    91,    15,    67,    66,    95,   144,   144,   100,
     155,   156,    97,     8,   133,   101,     9,   139,   120,    10,
     126,    51,    52,    11,    16,    12,   189,   160,   161,    13,
      44,   157,   158,   128,   118,    66,    39,   153,   154,    21,
     150,   151,   152,   181,   182,    59,    60,    61,    62,    63,
     129,   201,   130,    40,   144,   144,   144,   144,   144,    84,
      40,    88,    89,   144,   144,   144,   144,   144,   198,   -86,
      44,   103,    84,   104,    88,    89,   184,   185,   221,    67,
     135,    50,   143,   137,   149,   162,    65,   163,    84,   174,
      88,    89,    67,   165,   171,   190,   175,   213,   176,   188,
    -132,  -132,   204,   191,   192,   195,   199,   219,    67,   220,
     -15,   205,   208,   209,   223,     8,    51,    52,     9,    53,
     215,    10,   217,   218,  -132,    11,   222,    12,    54,    55,
     124,    13,    31,    56,   -15,    57,   125,   122,   173,    58,
      59,    60,    61,    62,    63,   127,   211,   136,   138,   200,
     216,   196,   183,   187,   186,    40,     0,     8,    51,    52,
       9,     0,     8,    10,   134,     9,     0,    11,    10,    12,
       0,     0,    11,    13,    12,    36,     0,    64,    13,     0,
       0,    65,    59,    60,    61,    62,    63,     0,     8,    51,
      52,     9,   145,   145,    10,     0,     0,    40,    11,     0,
      12,     0,    40,     0,    13,     0,    56,     0,   103,     0,
     104,     0,     0,    59,    60,    61,    62,    63,     0,     8,
       0,     0,     9,    65,     0,    10,     0,     0,    40,    11,
       0,    12,     0,     0,     0,    13,     0,     0,    14,   145,
     145,   145,   145,   145,     0,     0,     0,     0,   145,   145,
     145,   145,   145,     0,    65,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30
};

static const yytype_int16 yycheck[] =
{
       6,    23,    18,   100,    44,    44,    24,    57,    26,    48,
      36,    17,    36,    36,   125,    65,    11,    44,    64,   205,
       0,    27,    28,    29,    70,    34,    35,    66,    68,   215,
      36,     6,   143,    34,    35,    64,    44,    64,   103,   104,
      44,    68,    17,    70,    70,    64,    70,    70,    64,    58,
      56,   101,    27,     4,    29,    25,     7,    58,    66,    10,
      44,    36,    64,    14,    70,    16,   105,    68,    70,    20,
     120,    69,    23,    66,   100,    67,   100,   100,   175,    68,
      34,    35,   193,   194,   134,   150,   151,   152,    67,    95,
      71,    70,    44,    44,   100,    70,    72,   103,   104,    70,
      38,    39,    69,     4,    58,    70,     7,   204,    70,    10,
      65,     5,     6,    14,    65,    16,   166,    36,    37,    20,
      95,    59,    60,    66,   174,   100,    27,    55,    56,   135,
      61,    62,    63,   153,   154,    29,    30,    31,    32,    33,
      66,   191,    67,    44,   150,   151,   152,   153,   154,   175,
      44,   175,   175,   159,   160,   161,   162,   163,   176,    67,
     135,    55,   188,    57,   188,   188,   160,   161,   218,   175,
      70,    68,    70,    66,    66,    40,    70,    41,   204,    66,
     204,   204,   188,    71,    44,    65,    72,   205,    71,    71,
      34,    35,    66,    72,    71,    71,    71,   215,   204,   217,
      44,    15,    65,    71,   222,     4,     5,     6,     7,     8,
      15,    10,    71,    70,    58,    14,    71,    16,    17,    18,
      64,    20,    17,    22,    68,    24,    70,    66,   135,    28,
      29,    30,    31,    32,    33,    70,   204,    95,   100,   188,
     206,   174,   159,   163,   162,    44,    -1,     4,     5,     6,
       7,    -1,     4,    10,    90,     7,    -1,    14,    10,    16,
      -1,    -1,    14,    20,    16,    64,    -1,    66,    20,    -1,
      -1,    70,    29,    30,    31,    32,    33,    -1,     4,     5,
       6,     7,   103,   104,    10,    -1,    -1,    44,    14,    -1,
      16,    -1,    44,    -1,    20,    -1,    22,    -1,    55,    -1,
      57,    -1,    -1,    29,    30,    31,    32,    33,    -1,     4,
      -1,    -1,     7,    70,    -1,    10,    -1,    -1,    44,    14,
      -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    23,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,    70,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    74,    11,     0,    44,    64,    75,     4,     7,
      10,    14,    16,    20,    23,    44,    65,    76,    77,    78,
      79,    80,    81,    85,    86,    91,    92,    25,    67,    70,
      65,    77,    44,    68,    82,    83,    64,    94,    94,    27,
      44,    79,    84,    80,    79,    88,    89,    90,    69,    66,
      68,     5,     6,     8,    17,    18,    22,    24,    28,    29,
      30,    31,    32,    33,    66,    70,    79,    80,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     108,   109,   114,   115,   116,   117,   118,   120,   121,   132,
     133,    44,    87,    83,    71,    72,    83,    69,    44,    66,
      70,    70,    80,    55,    57,    79,    80,   111,   116,   121,
     122,   123,   124,   125,   127,   128,   129,   130,   131,   132,
      70,   131,    82,    83,    64,    70,    65,    97,    66,    66,
      67,    34,    35,    58,   134,    70,    90,    66,    99,   102,
     110,   113,   131,    70,    80,   120,   123,   123,    83,    66,
      61,    62,    63,    55,    56,    38,    39,    59,    60,   126,
      36,    37,    40,    41,   131,    71,   134,    93,   119,   131,
      93,    44,   131,    88,    66,    72,    71,    93,   123,   123,
     123,   124,   124,   125,   127,   127,   128,   129,    71,   131,
      65,    72,    71,    64,    70,    71,   111,   102,    94,    71,
     100,   131,    93,    93,    66,    15,   106,   107,    65,    71,
     112,   113,    18,    94,   103,    15,   107,    71,    70,    94,
      94,   131,    71,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    82,    83,    83,    83,    84,    84,    85,    86,    87,
      88,    88,    89,    89,    90,    91,    92,    93,    93,    94,
      95,    95,    96,    96,    97,    97,    98,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   102,
     102,   102,   103,   104,   105,   105,   106,   106,   107,   108,
     109,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   118,   119,   119,   120,   121,   121,
     121,   121,   122,   122,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   125,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   132,   133,   133,   134,   134,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     3,     1,     1,     2,     4,     4,
       1,     0,     1,     3,     2,     2,     4,     1,     0,     3,
       1,     0,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     5,     7,     6,     8,     1,     2,     2,     5,
       9,     1,     1,     0,     1,     0,     1,     0,     1,     3,
       2,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     3,     3,     4,     4,
       6,     6,     1,     1,     2,     2,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     1,     3,
       2,     4,     1,     1,     1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    24,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

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
  "REALLIT_RANGE_INVALID", "INVALID_CHARLIT_ESCAPE", "EMPTY_CHARLIT",
  "OPENENDED_CHARLIT", "'-'", "'+'", "'!'", "'='", "'<'", "'>'", "'*'",
  "'/'", "'%'", "'{'", "'}'", "';'", "'.'", "'['", "']'", "'('", "')'",
  "','", "$accept", "ClassDecl", "ClassBody", "ClassBodyDecls",
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

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
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

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* ClassDecl: PUBLIC CLASS IDENTIFIER ClassBody  */
#line 124 "j0gram.y"
                {root = create_branch(prodR_ClassDecl, "ClassDecl", 4, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1464 "j0gram.tab.c"
    break;

  case 3: /* ClassBody: '{' ClassBodyDecls '}'  */
#line 128 "j0gram.y"
                {((*yyvalp).treeptr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr);}
#line 1470 "j0gram.tab.c"
    break;

  case 4: /* ClassBody: '{' '}'  */
#line 130 "j0gram.y"
                {}
#line 1476 "j0gram.tab.c"
    break;

  case 5: /* ClassBodyDecls: ClassBodyDecl  */
#line 134 "j0gram.y"
                {}
#line 1482 "j0gram.tab.c"
    break;

  case 6: /* ClassBodyDecls: ClassBodyDecls ClassBodyDecl  */
#line 136 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_ClassBodyDecls,"ClassBodyDecls",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1488 "j0gram.tab.c"
    break;

  case 7: /* ClassBodyDecl: FieldDecl  */
#line 140 "j0gram.y"
                {}
#line 1494 "j0gram.tab.c"
    break;

  case 8: /* ClassBodyDecl: MethodDecl  */
#line 142 "j0gram.y"
                {}
#line 1500 "j0gram.tab.c"
    break;

  case 9: /* ClassBodyDecl: ConstructorDecl  */
#line 144 "j0gram.y"
                {}
#line 1506 "j0gram.tab.c"
    break;

  case 10: /* FieldDecl: Type VarDecls ';'  */
#line 148 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_FieldDecl,"FieldDecl",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 1512 "j0gram.tab.c"
    break;

  case 11: /* Type: INT  */
#line 154 "j0gram.y"
                {}
#line 1518 "j0gram.tab.c"
    break;

  case 12: /* Type: DOUBLE  */
#line 156 "j0gram.y"
                {}
#line 1524 "j0gram.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 158 "j0gram.y"
                {}
#line 1530 "j0gram.tab.c"
    break;

  case 14: /* Type: STRING  */
#line 160 "j0gram.y"
                {}
#line 1536 "j0gram.tab.c"
    break;

  case 15: /* Type: Name  */
#line 162 "j0gram.y"
                {}
#line 1542 "j0gram.tab.c"
    break;

  case 16: /* Type: CHAR  */
#line 164 "j0gram.y"
                {}
#line 1548 "j0gram.tab.c"
    break;

  case 18: /* Name: IDENTIFIER  */
#line 170 "j0gram.y"
                {}
#line 1554 "j0gram.tab.c"
    break;

  case 19: /* Name: QualifiedName  */
#line 172 "j0gram.y"
                {}
#line 1560 "j0gram.tab.c"
    break;

  case 20: /* QualifiedName: IDENTIFIER '.' Name  */
#line 176 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_QualifiedName,"QualifiedName",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1566 "j0gram.tab.c"
    break;

  case 21: /* VarDecls: VarDeclarator  */
#line 181 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_VarDecls,"VarDecls",1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1572 "j0gram.tab.c"
    break;

  case 22: /* VarDeclarator: IDENTIFIER  */
#line 187 "j0gram.y"
                {}
#line 1578 "j0gram.tab.c"
    break;

  case 23: /* VarDeclarator: VarDeclarator '[' ']'  */
#line 189 "j0gram.y"
                {}
#line 1584 "j0gram.tab.c"
    break;

  case 24: /* VarDeclarator: '[' ']' VarDeclarator  */
#line 191 "j0gram.y"
                {}
#line 1590 "j0gram.tab.c"
    break;

  case 25: /* MethodReturnVal: Type  */
#line 196 "j0gram.y"
                {}
#line 1596 "j0gram.tab.c"
    break;

  case 26: /* MethodReturnVal: VOID  */
#line 198 "j0gram.y"
                {}
#line 1602 "j0gram.tab.c"
    break;

  case 27: /* MethodDecl: MethodHeader Block  */
#line 202 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodDecl,"MethodDecl",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1608 "j0gram.tab.c"
    break;

  case 28: /* MethodHeader: PUBLIC STATIC MethodReturnVal MethodDeclarator  */
#line 206 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodHeader,"MethodHeader",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1614 "j0gram.tab.c"
    break;

  case 29: /* MethodDeclarator: IDENTIFIER '(' FormalParmListOpt ')'  */
#line 232 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodDeclarator, "MethodDeclarator", 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 1620 "j0gram.tab.c"
    break;

  case 30: /* FormalParmListOpt: FormalParmList  */
#line 236 "j0gram.y"
                {}
#line 1626 "j0gram.tab.c"
    break;

  case 31: /* FormalParmListOpt: %empty  */
#line 238 "j0gram.y"
                {((*yyvalp).treeptr) = NULL;}
#line 1632 "j0gram.tab.c"
    break;

  case 32: /* FormalParmList: FormalParm  */
#line 242 "j0gram.y"
                {}
#line 1638 "j0gram.tab.c"
    break;

  case 33: /* FormalParmList: FormalParmList ',' FormalParm  */
#line 244 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_FormalParmList,"FormalParmList",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1644 "j0gram.tab.c"
    break;

  case 34: /* FormalParm: Type VarDeclarator  */
#line 248 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_FormalParm,"FormalParm",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1650 "j0gram.tab.c"
    break;

  case 35: /* ConstructorDecl: ConstructorDeclarator Block  */
#line 253 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_ConstructorDecl,"ConstructorDecl",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1656 "j0gram.tab.c"
    break;

  case 36: /* ConstructorDeclarator: IDENTIFIER '(' FormalParmListOpt ')'  */
#line 257 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_ConstructorDeclarator,"ConstructorDeclarator",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 1662 "j0gram.tab.c"
    break;

  case 37: /* ArgListOpt: ArgList  */
#line 261 "j0gram.y"
                {}
#line 1668 "j0gram.tab.c"
    break;

  case 38: /* ArgListOpt: %empty  */
#line 263 "j0gram.y"
                {((*yyvalp).treeptr) = NULL;}
#line 1674 "j0gram.tab.c"
    break;

  case 39: /* Block: '{' BlockStmtsOpt '}'  */
#line 267 "j0gram.y"
                {((*yyvalp).treeptr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr);}
#line 1680 "j0gram.tab.c"
    break;

  case 40: /* BlockStmtsOpt: BlockStmts  */
#line 271 "j0gram.y"
                {}
#line 1686 "j0gram.tab.c"
    break;

  case 41: /* BlockStmtsOpt: %empty  */
#line 273 "j0gram.y"
                {((*yyvalp).treeptr) = NULL;}
#line 1692 "j0gram.tab.c"
    break;

  case 42: /* BlockStmts: BlockStmt  */
#line 277 "j0gram.y"
                {}
#line 1698 "j0gram.tab.c"
    break;

  case 43: /* BlockStmts: BlockStmts BlockStmt  */
#line 279 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_BlockStmts,"BlockStmts",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1704 "j0gram.tab.c"
    break;

  case 44: /* BlockStmt: LocalVarDeclStmt  */
#line 283 "j0gram.y"
                {}
#line 1710 "j0gram.tab.c"
    break;

  case 45: /* BlockStmt: Stmt  */
#line 285 "j0gram.y"
                {}
#line 1716 "j0gram.tab.c"
    break;

  case 46: /* LocalVarDeclStmt: LocalVarDecl ';'  */
#line 290 "j0gram.y"
                {}
#line 1722 "j0gram.tab.c"
    break;

  case 47: /* LocalVarDecl: Type VarDecls  */
#line 294 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_LocalVarDecl,"LocalVarDecl",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1728 "j0gram.tab.c"
    break;

  case 48: /* Stmt: Block  */
#line 299 "j0gram.y"
                {}
#line 1734 "j0gram.tab.c"
    break;

  case 49: /* Stmt: ';'  */
#line 301 "j0gram.y"
                {}
#line 1740 "j0gram.tab.c"
    break;

  case 50: /* Stmt: ExprStmt  */
#line 303 "j0gram.y"
                {}
#line 1746 "j0gram.tab.c"
    break;

  case 51: /* Stmt: BreakStmt  */
#line 305 "j0gram.y"
                {}
#line 1752 "j0gram.tab.c"
    break;

  case 52: /* Stmt: ReturnStmt  */
#line 307 "j0gram.y"
                {}
#line 1758 "j0gram.tab.c"
    break;

  case 53: /* Stmt: IfThenStmt  */
#line 310 "j0gram.y"
                {}
#line 1764 "j0gram.tab.c"
    break;

  case 54: /* Stmt: IfThenElseStmt  */
#line 312 "j0gram.y"
                {}
#line 1770 "j0gram.tab.c"
    break;

  case 55: /* Stmt: IfThenElseIfStmt  */
#line 314 "j0gram.y"
                {}
#line 1776 "j0gram.tab.c"
    break;

  case 56: /* Stmt: WhileStmt  */
#line 317 "j0gram.y"
                {}
#line 1782 "j0gram.tab.c"
    break;

  case 57: /* Stmt: ForStmt  */
#line 319 "j0gram.y"
                {}
#line 1788 "j0gram.tab.c"
    break;

  case 58: /* ExprStmt: StmtExpr ';'  */
#line 324 "j0gram.y"
                {}
#line 1794 "j0gram.tab.c"
    break;

  case 59: /* StmtExpr: Assignment  */
#line 329 "j0gram.y"
                {}
#line 1800 "j0gram.tab.c"
    break;

  case 60: /* StmtExpr: MethodCall  */
#line 331 "j0gram.y"
                {}
#line 1806 "j0gram.tab.c"
    break;

  case 61: /* StmtExpr: InstantiationExpr  */
#line 333 "j0gram.y"
                {}
#line 1812 "j0gram.tab.c"
    break;

  case 62: /* IfThenStmt: IF '(' Expr ')' Block  */
#line 338 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_IfThenStmt,"IfThenStmt",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1818 "j0gram.tab.c"
    break;

  case 63: /* IfThenElseStmt: IF '(' Expr ')' Block ELSE Block  */
#line 342 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_IfThenElseStmt, "IfThenElseStmt",3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1824 "j0gram.tab.c"
    break;

  case 64: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence  */
#line 346 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_IfThenElseIfStmt,"IfThenElseIfStmt",3,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1830 "j0gram.tab.c"
    break;

  case 65: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence ELSE Block  */
#line 349 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_IfThenElseIfStmt,"IfThenElseIf_Else_Stmt",4, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1836 "j0gram.tab.c"
    break;

  case 66: /* ElseIfSequence: ElseIfStmt  */
#line 354 "j0gram.y"
                {}
#line 1842 "j0gram.tab.c"
    break;

  case 67: /* ElseIfSequence: ElseIfSequence ElseIfStmt  */
#line 356 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_ElseIfSequence,"ElseIfSequence",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1848 "j0gram.tab.c"
    break;

  case 68: /* ElseIfStmt: ELSE IfThenStmt  */
#line 360 "j0gram.y"
                {((*yyvalp).treeptr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr);}
#line 1854 "j0gram.tab.c"
    break;

  case 69: /* WhileStmt: WHILE '(' Expr ')' Stmt  */
#line 364 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_WhileStmt,"WhileStmt",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1860 "j0gram.tab.c"
    break;

  case 70: /* ForStmt: FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block  */
#line 369 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_ForStmt,"ForStmt",4, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1866 "j0gram.tab.c"
    break;

  case 71: /* ForInit: StmtExprList  */
#line 373 "j0gram.y"
                {}
#line 1872 "j0gram.tab.c"
    break;

  case 72: /* ForInit: LocalVarDecl  */
#line 375 "j0gram.y"
                {}
#line 1878 "j0gram.tab.c"
    break;

  case 73: /* ForInit: %empty  */
#line 377 "j0gram.y"
                {((*yyvalp).treeptr) = NULL;}
#line 1884 "j0gram.tab.c"
    break;

  case 74: /* ExprOpt: Expr  */
#line 381 "j0gram.y"
                {}
#line 1890 "j0gram.tab.c"
    break;

  case 75: /* ExprOpt: %empty  */
#line 383 "j0gram.y"
                {((*yyvalp).treeptr) = NULL;}
#line 1896 "j0gram.tab.c"
    break;

  case 76: /* ForUpdate: StmtExprList  */
#line 387 "j0gram.y"
                {}
#line 1902 "j0gram.tab.c"
    break;

  case 77: /* ForUpdate: %empty  */
#line 389 "j0gram.y"
                {((*yyvalp).treeptr) = NULL;}
#line 1908 "j0gram.tab.c"
    break;

  case 78: /* StmtExprList: StmtExpr  */
#line 394 "j0gram.y"
                {}
#line 1914 "j0gram.tab.c"
    break;

  case 79: /* StmtExprList: StmtExprList ',' StmtExpr  */
#line 396 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_StmtExprList,"StmtExprList",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 1920 "j0gram.tab.c"
    break;

  case 80: /* BreakStmt: BREAK ';'  */
#line 401 "j0gram.y"
                {}
#line 1926 "j0gram.tab.c"
    break;

  case 81: /* BreakStmt: BREAK IDENTIFIER ';'  */
#line 403 "j0gram.y"
                {((*yyvalp).treeptr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr);}
#line 1932 "j0gram.tab.c"
    break;

  case 82: /* ReturnStmt: RETURN ExprOpt ';'  */
#line 407 "j0gram.y"
                {((*yyvalp).treeptr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr);}
#line 1938 "j0gram.tab.c"
    break;

  case 83: /* Primary: Literal  */
#line 412 "j0gram.y"
                {}
#line 1944 "j0gram.tab.c"
    break;

  case 84: /* Primary: '(' Expr ')'  */
#line 414 "j0gram.y"
                {((*yyvalp).treeptr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr);}
#line 1950 "j0gram.tab.c"
    break;

  case 85: /* Primary: FieldAccess  */
#line 416 "j0gram.y"
                {}
#line 1956 "j0gram.tab.c"
    break;

  case 86: /* Primary: MethodCall  */
#line 418 "j0gram.y"
                {}
#line 1962 "j0gram.tab.c"
    break;

  case 87: /* Literal: INTLIT  */
#line 422 "j0gram.y"
                {}
#line 1968 "j0gram.tab.c"
    break;

  case 88: /* Literal: DOUBLELIT  */
#line 424 "j0gram.y"
                {}
#line 1974 "j0gram.tab.c"
    break;

  case 89: /* Literal: REALLIT  */
#line 426 "j0gram.y"
                {}
#line 1980 "j0gram.tab.c"
    break;

  case 90: /* Literal: BOOLLIT  */
#line 428 "j0gram.y"
                {}
#line 1986 "j0gram.tab.c"
    break;

  case 91: /* Literal: CHARLIT  */
#line 430 "j0gram.y"
                {}
#line 1992 "j0gram.tab.c"
    break;

  case 92: /* Literal: STRINGLIT  */
#line 432 "j0gram.y"
                {}
#line 1998 "j0gram.tab.c"
    break;

  case 93: /* Literal: NULLVAL  */
#line 434 "j0gram.y"
                {}
#line 2004 "j0gram.tab.c"
    break;

  case 94: /* InstantiationExpr: NEW Name '(' ArgListOpt ')'  */
#line 439 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_InstantiationExpr,"InstantiationExpr",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 2010 "j0gram.tab.c"
    break;

  case 95: /* ArgList: Expr  */
#line 443 "j0gram.y"
                {}
#line 2016 "j0gram.tab.c"
    break;

  case 96: /* ArgList: ArgList ',' Expr  */
#line 445 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_ArgList,"ArgList",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2022 "j0gram.tab.c"
    break;

  case 97: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 449 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_FieldAccess,"FieldAccess",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2028 "j0gram.tab.c"
    break;

  case 98: /* MethodCall: Name '(' ArgListOpt ')'  */
#line 454 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodCall,"MethodCall_parens",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 2034 "j0gram.tab.c"
    break;

  case 99: /* MethodCall: Name '{' ArgListOpt '}'  */
#line 457 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodCall,"MethodCall_curly",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 2040 "j0gram.tab.c"
    break;

  case 100: /* MethodCall: Primary '.' IDENTIFIER '(' ArgListOpt ')'  */
#line 460 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodCall,"MethodCall_primary_parens",3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 2046 "j0gram.tab.c"
    break;

  case 101: /* MethodCall: Primary '.' IDENTIFIER '{' ArgListOpt '}'  */
#line 463 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MethodCall,"MethodCall_primary_curly",3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr));}
#line 2052 "j0gram.tab.c"
    break;

  case 102: /* PostFixExpr: Primary  */
#line 468 "j0gram.y"
                {}
#line 2058 "j0gram.tab.c"
    break;

  case 103: /* PostFixExpr: Name  */
#line 470 "j0gram.y"
                {}
#line 2064 "j0gram.tab.c"
    break;

  case 104: /* UnaryExpr: '-' UnaryExpr  */
#line 474 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_UnaryExpr, "UnaryExpr_Neg", 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2070 "j0gram.tab.c"
    break;

  case 105: /* UnaryExpr: '!' UnaryExpr  */
#line 476 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_UnaryExpr, "UnaryExpr_Excl", 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2076 "j0gram.tab.c"
    break;

  case 106: /* UnaryExpr: PostFixExpr  */
#line 478 "j0gram.y"
                {}
#line 2082 "j0gram.tab.c"
    break;

  case 107: /* MulExpr: UnaryExpr  */
#line 482 "j0gram.y"
                {}
#line 2088 "j0gram.tab.c"
    break;

  case 108: /* MulExpr: MulExpr '*' UnaryExpr  */
#line 484 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MulExpr,"MulExpr_multiply",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2094 "j0gram.tab.c"
    break;

  case 109: /* MulExpr: MulExpr '/' UnaryExpr  */
#line 487 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MulExpr,"MulExpr_divide",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2100 "j0gram.tab.c"
    break;

  case 110: /* MulExpr: MulExpr '%' UnaryExpr  */
#line 489 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_MulExpr,"MulExpr_modulus",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2106 "j0gram.tab.c"
    break;

  case 111: /* AddExpr: MulExpr  */
#line 493 "j0gram.y"
                {}
#line 2112 "j0gram.tab.c"
    break;

  case 112: /* AddExpr: AddExpr '+' MulExpr  */
#line 495 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_AddExpr,"AddExpr_add",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2118 "j0gram.tab.c"
    break;

  case 113: /* AddExpr: AddExpr '-' MulExpr  */
#line 497 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_AddExpr,"AddExpr_subtract",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2124 "j0gram.tab.c"
    break;

  case 114: /* RelOp: LESSTHANOREQUAL  */
#line 501 "j0gram.y"
                {}
#line 2130 "j0gram.tab.c"
    break;

  case 115: /* RelOp: GREATERTHANOREQUAL  */
#line 503 "j0gram.y"
                {}
#line 2136 "j0gram.tab.c"
    break;

  case 116: /* RelOp: '<'  */
#line 505 "j0gram.y"
                {}
#line 2142 "j0gram.tab.c"
    break;

  case 117: /* RelOp: '>'  */
#line 507 "j0gram.y"
                {}
#line 2148 "j0gram.tab.c"
    break;

  case 118: /* RelExpr: AddExpr  */
#line 511 "j0gram.y"
                {}
#line 2154 "j0gram.tab.c"
    break;

  case 119: /* RelExpr: RelExpr RelOp AddExpr  */
#line 513 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_RelExpr,"RelExpr",3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2160 "j0gram.tab.c"
    break;

  case 120: /* EqExpr: RelExpr  */
#line 518 "j0gram.y"
                {}
#line 2166 "j0gram.tab.c"
    break;

  case 121: /* EqExpr: EqExpr ISEQUALTO RelExpr  */
#line 520 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_EqExpr,"EqExpr_isequal",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2172 "j0gram.tab.c"
    break;

  case 122: /* EqExpr: EqExpr NOTEQUALTO RelExpr  */
#line 522 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_EqExpr,"EqExpr_notequal",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2178 "j0gram.tab.c"
    break;

  case 123: /* CondAndExpr: EqExpr  */
#line 526 "j0gram.y"
                {}
#line 2184 "j0gram.tab.c"
    break;

  case 124: /* CondAndExpr: CondAndExpr LOGICALAND EqExpr  */
#line 528 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_CondAndExpr,"CondAndExpr",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2190 "j0gram.tab.c"
    break;

  case 125: /* CondOrExpr: CondAndExpr  */
#line 532 "j0gram.y"
                {}
#line 2196 "j0gram.tab.c"
    break;

  case 126: /* CondOrExpr: CondOrExpr LOGICALOR CondAndExpr  */
#line 534 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_CondOrExpr,"CondOrExpr",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2202 "j0gram.tab.c"
    break;

  case 127: /* Expr: CondOrExpr  */
#line 539 "j0gram.y"
                {}
#line 2208 "j0gram.tab.c"
    break;

  case 128: /* Expr: Assignment  */
#line 541 "j0gram.y"
                {}
#line 2214 "j0gram.tab.c"
    break;

  case 129: /* Assignment: LeftHandSide AssignOp Expr  */
#line 545 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_Assignment,"Assignment",3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2220 "j0gram.tab.c"
    break;

  case 130: /* Assignment: LeftHandSide AssignOp  */
#line 547 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_Assignment,"Assignment_Unary",2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2226 "j0gram.tab.c"
    break;

  case 131: /* Assignment: Type VarDeclarator AssignOp Expr  */
#line 549 "j0gram.y"
                {((*yyvalp).treeptr) = create_branch(prodR_TypeAssignment,"Assignment_Type",4, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.treeptr),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.treeptr));}
#line 2232 "j0gram.tab.c"
    break;

  case 132: /* LeftHandSide: Name  */
#line 553 "j0gram.y"
                {}
#line 2238 "j0gram.tab.c"
    break;

  case 133: /* LeftHandSide: FieldAccess  */
#line 555 "j0gram.y"
                {}
#line 2244 "j0gram.tab.c"
    break;

  case 134: /* AssignOp: '='  */
#line 559 "j0gram.y"
                {}
#line 2250 "j0gram.tab.c"
    break;

  case 135: /* AssignOp: INCREMENT  */
#line 561 "j0gram.y"
                {}
#line 2256 "j0gram.tab.c"
    break;

  case 136: /* AssignOp: DECREMENT  */
#line 563 "j0gram.y"
                {}
#line 2262 "j0gram.tab.c"
    break;


#line 2266 "j0gram.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

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

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}






static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  yyerror (YY_("syntax error"));
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




