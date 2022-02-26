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
#line 1 "j0gram.y"

    #include <stdio.h>
		#define YYDEBUG 1

		extern int yyerror(char *s);
		extern int yylex();
		extern int yyparse();

		#include "tree.h"
		struct tree *root;

#line 83 "j0gram.tab.c"

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
#line 12 "j0gram.y"

   struct tree *treeptr;

#line 188 "j0gram.tab.c"

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
  YYSYMBOL_68_ = 68,                       /* ','  */
  YYSYMBOL_69_ = 69,                       /* '['  */
  YYSYMBOL_70_ = 70,                       /* ']'  */
  YYSYMBOL_71_ = 71,                       /* '('  */
  YYSYMBOL_72_ = 72,                       /* ')'  */
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
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
      71,    72,    61,    56,    68,    55,    67,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
      59,    58,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,     2,     2,     2,     2,     2,     2,
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   116,   118,   122,   124,   128,   130,   132,
     136,   140,   142,   144,   146,   148,   153,   155,   159,   164,
     166,   170,   172,   177,   179,   183,   187,   191,   195,   198,
     201,   203,   207,   212,   216,   220,   223,   227,   231,   234,
     237,   239,   243,   245,   250,   254,   259,   261,   263,   265,
     267,   270,   272,   274,   277,   279,   284,   289,   291,   293,
     298,   302,   306,   309,   314,   316,   320,   324,   329,   333,
     335,   338,   341,   344,   347,   350,   354,   356,   361,   363,
     367,   372,   374,   376,   378,   382,   384,   386,   388,   390,
     395,   399,   401,   405,   410,   413,   416,   419,   424,   426,
     430,   432,   434,   438,   440,   443,   445,   449,   451,   453,
     457,   459,   461,   463,   467,   469,   474,   476,   478,   482,
     484,   488,   490,   495,   497,   501,   505,   507,   511,   513,
     515
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
  "REALLIT_RANGE_INVALID", "INVALID_CHARLIT_ESCAPE", "EMPTY_CHARLIT",
  "OPENENDED_CHARLIT", "'-'", "'+'", "'!'", "'='", "'<'", "'>'", "'*'",
  "'/'", "'%'", "'{'", "'}'", "';'", "'.'", "','", "'['", "']'", "'('",
  "')'", "$accept", "ClassDecl", "ClassBody", "ClassBodyDecls",
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

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,     4,    18,    28,  -116,    36,    66,  -116,  -116,  -116,
    -116,  -116,    84,    45,  -116,   113,  -116,  -116,    74,    54,
    -116,  -116,    65,  -116,    65,   252,    22,  -116,  -116,  -116,
      35,    63,   100,   189,  -116,  -116,  -116,  -116,  -116,   103,
      74,    88,    93,  -116,  -116,    74,    94,  -116,  -116,  -116,
     -38,   101,   102,   121,    33,   106,  -116,  -116,  -116,  -116,
      33,    74,    55,  -116,   114,   189,  -116,  -116,   105,  -116,
    -116,   115,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   118,
    -116,  -116,   -10,   120,  -116,    72,   109,  -116,    63,  -116,
      22,    63,  -116,   122,  -116,    27,    33,   -27,    33,    33,
      44,   123,   118,  -116,  -116,  -116,   107,    13,    75,    57,
     150,   157,  -116,  -116,    33,   127,   132,    33,    33,  -116,
    -116,  -116,  -116,   158,  -116,  -116,  -116,    33,    22,  -116,
    -116,  -116,  -116,   135,   136,   133,    33,    91,  -116,  -116,
    -116,  -116,    33,    33,    33,    33,    33,  -116,  -116,  -116,
    -116,    33,    33,    33,    33,    33,   138,  -116,   143,   144,
    -116,   142,   -55,  -116,   152,    33,   217,    65,   153,  -116,
    -116,  -116,   107,   107,    13,    75,    75,    57,   150,   210,
    -116,    33,  -116,    33,    33,  -116,   160,    91,  -116,   214,
    -116,  -116,  -116,   165,   159,   217,    -4,   220,  -116,  -116,
    -116,   164,   136,   166,  -116,  -116,    -4,  -116,    65,    33,
    -116,  -116,   171,    65,  -116
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
       0,     0,    28,    30,    10,     0,     0,    18,    86,    89,
       0,     0,     0,     0,    73,     0,    85,    88,    87,    47,
       0,     0,   126,    46,     0,    38,    40,    42,     0,    43,
      48,     0,    51,    52,    53,    54,    55,    49,    50,     0,
      81,    59,    83,    58,    57,     0,     0,    26,    32,    34,
       0,    20,    22,     0,    78,    71,     0,     0,     0,     0,
      99,     0,    98,    84,   102,   103,   107,   114,   116,   119,
     121,   123,    72,   124,     0,     0,    45,    36,    36,    37,
      41,    44,    56,     0,   129,   130,   128,     0,    29,    31,
      79,    70,    76,     0,    69,     0,    36,    99,    83,   100,
     101,    80,     0,     0,     0,     0,     0,   111,   110,   112,
     113,     0,     0,     0,     0,     0,     0,    82,     0,    35,
      91,     0,    93,   125,     0,    73,     0,     0,     0,   104,
     105,   106,   109,   108,   115,   117,   118,   120,   122,     0,
      95,     0,    94,    36,    36,    27,     0,   126,    77,    60,
      90,    67,    92,     0,     0,    75,     0,    62,    64,    97,
      96,     0,    74,     0,    61,    66,     0,    65,     0,     0,
      63,    68,     0,     0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,   229,  -116,     2,    -3,  -116,   190,
       6,  -116,  -116,  -116,  -116,   124,  -116,   167,  -116,  -116,
     -99,   -22,  -116,  -116,   185,  -116,   163,    83,  -116,   -90,
    -115,  -116,  -116,  -116,    67,  -116,  -116,  -116,    98,  -116,
      70,  -116,  -116,   -20,  -116,  -116,  -116,   147,   -13,  -116,
     -88,    -8,   116,  -116,   -29,   117,   125,  -116,   -53,   -12,
    -116,  -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    15,    16,    17,    40,   100,    20,    30,
      31,    39,    21,    22,    87,    41,    42,    43,    23,    24,
     158,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   197,   198,    75,    76,   133,   101,   201,
     134,    77,    78,   102,    80,    81,   159,    82,   103,   104,
     105,   106,   107,   151,   108,   109,   110,   111,   160,   113,
      85,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   112,    35,    19,     1,   132,    93,   115,    18,   183,
     139,   140,    19,    79,   203,     3,   184,    18,     4,   161,
      83,    84,    19,    19,  -127,  -127,     8,    38,    94,     9,
      62,     8,    48,    49,     9,    61,    10,   168,    48,    49,
      32,    10,    11,   135,   136,    79,    88,    11,  -127,    53,
      97,    91,    83,    84,   169,   170,   171,    56,    57,    58,
      33,   156,    62,    56,    57,    58,    37,    61,   145,   146,
       8,    37,     5,     9,   163,    79,   188,    37,  -126,  -126,
      10,   205,    83,    84,   193,   194,    11,    19,    98,    12,
      99,   205,    62,   152,   153,   137,   137,    61,    60,   -15,
       6,    44,  -126,    45,    60,   132,   124,   125,   117,    25,
      13,    32,   112,   147,   148,   118,    26,     8,    29,   117,
       9,    32,    32,   175,   176,    19,   118,    10,   192,    33,
     126,    14,    46,    11,   149,   150,    12,   172,   173,   137,
     137,   137,   137,   137,    47,   189,    79,    86,   137,   137,
     137,   137,   137,    83,    84,   117,   212,    13,    32,    79,
      89,    90,   118,   187,    92,    37,    83,    84,   142,   143,
     144,   121,    95,    96,   204,    79,   187,   114,    27,   119,
     128,   122,    83,    84,   210,   123,   211,   -84,   130,   141,
     154,   214,   187,     8,    48,    49,     9,    50,   155,   157,
      45,   165,   162,    10,   166,   167,    51,    52,   180,    11,
     179,    53,   181,    54,   182,    48,    49,    55,    50,    56,
      57,    58,    48,    49,   185,   190,   195,    51,    52,   196,
     199,   200,    53,    37,    54,   206,   208,   209,    55,    53,
      56,    57,    58,   213,    28,   138,   138,    56,    57,    58,
     120,   116,   164,    33,    37,    59,     8,   129,   131,     9,
      60,    37,   191,   186,   207,   202,    10,   174,     0,     0,
       0,   177,    11,     0,    33,     0,    59,     0,     0,    36,
     178,    60,     0,     0,     0,     0,     0,     0,    60,   138,
     138,   138,   138,   138,     0,     0,    37,     0,   138,   138,
     138,   138,   138
};

static const yytype_int16 yycheck[] =
{
      22,    54,    24,     6,    23,    95,    44,    60,     6,    64,
      98,    99,    15,    33,    18,    11,    71,    15,     0,   118,
      33,    33,    25,    26,    34,    35,     4,    25,    66,     7,
      33,     4,     5,     6,     7,    33,    14,   136,     5,     6,
      67,    14,    20,    96,    71,    65,    40,    20,    58,    22,
      53,    45,    65,    65,   142,   143,   144,    30,    31,    32,
      64,   114,    65,    30,    31,    32,    44,    65,    55,    56,
       4,    44,    44,     7,   127,    95,   166,    44,    34,    35,
      14,   196,    95,    95,   183,   184,    20,    90,    55,    23,
      57,   206,    95,    36,    37,    98,    99,    95,    71,    44,
      64,    66,    58,    68,    71,   195,    34,    35,    64,    25,
      44,    67,   165,    38,    39,    71,    71,     4,    44,    64,
       7,    67,    67,   152,   153,   128,    71,    14,   181,    64,
      58,    65,    69,    20,    59,    60,    23,   145,   146,   142,
     143,   144,   145,   146,    44,   167,   166,    44,   151,   152,
     153,   154,   155,   166,   166,    64,   209,    44,    67,   179,
      72,    68,    71,   166,    70,    44,   179,   179,    61,    62,
      63,    66,    71,    71,   196,   195,   179,    71,    65,    65,
      71,    66,   195,   195,   206,    67,   208,    67,    66,    66,
      40,   213,   195,     4,     5,     6,     7,     8,    41,    72,
      68,    66,    44,    14,    68,    72,    17,    18,    65,    20,
      72,    22,    68,    24,    72,     5,     6,    28,     8,    30,
      31,    32,     5,     6,    72,    72,    66,    17,    18,    15,
      65,    72,    22,    44,    24,    15,    72,    71,    28,    22,
      30,    31,    32,    72,    15,    98,    99,    30,    31,    32,
      65,    61,   128,    64,    44,    66,     4,    90,    95,     7,
      71,    44,   179,   165,   197,   195,    14,   151,    -1,    -1,
      -1,   154,    20,    -1,    64,    -1,    66,    -1,    -1,    27,
     155,    71,    -1,    -1,    -1,    -1,    -1,    -1,    71,   142,
     143,   144,   145,   146,    -1,    -1,    44,    -1,   151,   152,
     153,   154,   155
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    74,    11,     0,    44,    64,    75,     4,     7,
      14,    20,    23,    44,    65,    76,    77,    78,    79,    80,
      81,    85,    86,    91,    92,    25,    71,    65,    77,    44,
      82,    83,    67,    64,    94,    94,    27,    44,    79,    84,
      79,    88,    89,    90,    66,    68,    69,    44,     5,     6,
       8,    17,    18,    22,    24,    28,    30,    31,    32,    66,
      71,    79,    80,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   108,   109,   114,   115,   116,
     117,   118,   120,   121,   132,   133,    44,    87,    83,    72,
      68,    83,    70,    44,    66,    71,    71,    80,    55,    57,
      80,   111,   116,   121,   122,   123,   124,   125,   127,   128,
     129,   130,   131,   132,    71,   131,    82,    64,    71,    65,
      97,    66,    66,    67,    34,    35,    58,   134,    71,    90,
      66,    99,   102,   110,   113,   131,    71,    80,   120,   123,
     123,    66,    61,    62,    63,    55,    56,    38,    39,    59,
      60,   126,    36,    37,    40,    41,   131,    72,    93,   119,
     131,    93,    44,   131,    88,    66,    68,    72,    93,   123,
     123,   123,   124,   124,   125,   127,   127,   128,   129,    72,
      65,    68,    72,    64,    71,    72,   111,    80,   102,    94,
      72,   100,   131,    93,    93,    66,    15,   106,   107,    65,
      72,   112,   113,    18,    94,   103,    15,   107,    72,    71,
      94,    94,   131,    72,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    79,    79,    79,    79,    79,    80,    80,    81,    82,
      82,    83,    83,    84,    84,    85,    86,    87,    88,    88,
      89,    89,    90,    91,    92,    93,    93,    94,    95,    95,
      96,    96,    97,    97,    98,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   102,   102,   102,
     103,   104,   105,   105,   106,   106,   107,   108,   109,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     118,   119,   119,   120,   121,   121,   121,   121,   122,   122,
     123,   123,   123,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   133,   133,   134,   134,
     134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     4,     4,     1,     0,
       1,     3,     2,     2,     4,     1,     0,     3,     1,     0,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       5,     7,     6,     8,     1,     2,     2,     5,     9,     1,
       1,     0,     1,     0,     1,     0,     1,     3,     2,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     3,     3,     4,     4,     6,     6,     1,     1,
       2,     2,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     3,     1,     1,     1,     1,
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
  case 2: /* ClassDecl: PUBLIC CLASS IDENTIFIER ClassBody  */
#line 113 "j0gram.y"
                {root = create_branch(prodR_ClassDecl, "ClassDecl", 4, (yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1491 "j0gram.tab.c"
    break;

  case 3: /* ClassBody: '{' ClassBodyDecls '}'  */
#line 117 "j0gram.y"
                {(yyval.treeptr) = (yyvsp[-1].treeptr);}
#line 1497 "j0gram.tab.c"
    break;

  case 4: /* ClassBody: '{' '}'  */
#line 119 "j0gram.y"
                {}
#line 1503 "j0gram.tab.c"
    break;

  case 5: /* ClassBodyDecls: ClassBodyDecl  */
#line 123 "j0gram.y"
                {}
#line 1509 "j0gram.tab.c"
    break;

  case 6: /* ClassBodyDecls: ClassBodyDecls ClassBodyDecl  */
#line 125 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_ClassBodyDecls,"ClassBodyDecls",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1515 "j0gram.tab.c"
    break;

  case 7: /* ClassBodyDecl: FieldDecl  */
#line 129 "j0gram.y"
                {}
#line 1521 "j0gram.tab.c"
    break;

  case 8: /* ClassBodyDecl: MethodDecl  */
#line 131 "j0gram.y"
                {}
#line 1527 "j0gram.tab.c"
    break;

  case 9: /* ClassBodyDecl: ConstructorDecl  */
#line 133 "j0gram.y"
                {}
#line 1533 "j0gram.tab.c"
    break;

  case 10: /* FieldDecl: Type VarDecls ';'  */
#line 137 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_FieldDecl,"FieldDecl",2, (yyvsp[-2].treeptr),(yyvsp[-1].treeptr));}
#line 1539 "j0gram.tab.c"
    break;

  case 11: /* Type: INT  */
#line 141 "j0gram.y"
                {}
#line 1545 "j0gram.tab.c"
    break;

  case 12: /* Type: DOUBLE  */
#line 143 "j0gram.y"
                {}
#line 1551 "j0gram.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 145 "j0gram.y"
                {}
#line 1557 "j0gram.tab.c"
    break;

  case 14: /* Type: STRING  */
#line 147 "j0gram.y"
                {}
#line 1563 "j0gram.tab.c"
    break;

  case 15: /* Type: Name  */
#line 149 "j0gram.y"
                {}
#line 1569 "j0gram.tab.c"
    break;

  case 16: /* Name: IDENTIFIER  */
#line 154 "j0gram.y"
                {}
#line 1575 "j0gram.tab.c"
    break;

  case 17: /* Name: QualifiedName  */
#line 156 "j0gram.y"
                {}
#line 1581 "j0gram.tab.c"
    break;

  case 18: /* QualifiedName: Name '.' IDENTIFIER  */
#line 160 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_QualifiedName,"QualifiedName",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1587 "j0gram.tab.c"
    break;

  case 19: /* VarDecls: VarDeclarator  */
#line 165 "j0gram.y"
                {}
#line 1593 "j0gram.tab.c"
    break;

  case 20: /* VarDecls: VarDecls ',' VarDeclarator  */
#line 167 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_VarDecls,"VarDecls_multi",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1599 "j0gram.tab.c"
    break;

  case 21: /* VarDeclarator: IDENTIFIER  */
#line 171 "j0gram.y"
                {}
#line 1605 "j0gram.tab.c"
    break;

  case 22: /* VarDeclarator: VarDeclarator '[' ']'  */
#line 173 "j0gram.y"
                {}
#line 1611 "j0gram.tab.c"
    break;

  case 23: /* MethodReturnVal: Type  */
#line 178 "j0gram.y"
                {}
#line 1617 "j0gram.tab.c"
    break;

  case 24: /* MethodReturnVal: VOID  */
#line 180 "j0gram.y"
                {}
#line 1623 "j0gram.tab.c"
    break;

  case 25: /* MethodDecl: MethodHeader Block  */
#line 184 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodDecl,"MethodDecl",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1629 "j0gram.tab.c"
    break;

  case 26: /* MethodHeader: PUBLIC STATIC MethodReturnVal MethodDeclarator  */
#line 188 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodHeader,"MethodHeader",4, (yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1635 "j0gram.tab.c"
    break;

  case 27: /* MethodDeclarator: IDENTIFIER '(' FormalParmListOpt ')'  */
#line 192 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodDeclarator, "MethodDeclarator", 2, (yyvsp[-3].treeptr), (yyvsp[-1].treeptr));}
#line 1641 "j0gram.tab.c"
    break;

  case 28: /* FormalParmListOpt: FormalParmList  */
#line 196 "j0gram.y"
                {}
#line 1647 "j0gram.tab.c"
    break;

  case 29: /* FormalParmListOpt: %empty  */
#line 198 "j0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1653 "j0gram.tab.c"
    break;

  case 30: /* FormalParmList: FormalParm  */
#line 202 "j0gram.y"
                {}
#line 1659 "j0gram.tab.c"
    break;

  case 31: /* FormalParmList: FormalParmList ',' FormalParm  */
#line 204 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_FormalParmList,"FormalParmList",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1665 "j0gram.tab.c"
    break;

  case 32: /* FormalParm: Type VarDeclarator  */
#line 208 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_FormalParm,"FormalParm",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1671 "j0gram.tab.c"
    break;

  case 33: /* ConstructorDecl: ConstructorDeclarator Block  */
#line 213 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_ConstructorDecl,"ConstructorDecl",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1677 "j0gram.tab.c"
    break;

  case 34: /* ConstructorDeclarator: IDENTIFIER '(' FormalParmListOpt ')'  */
#line 217 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_ConstructorDeclarator,"ConstructorDeclarator",2, (yyvsp[-3].treeptr),(yyvsp[-1].treeptr));}
#line 1683 "j0gram.tab.c"
    break;

  case 35: /* ArgListOpt: ArgList  */
#line 221 "j0gram.y"
                {}
#line 1689 "j0gram.tab.c"
    break;

  case 36: /* ArgListOpt: %empty  */
#line 223 "j0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1695 "j0gram.tab.c"
    break;

  case 37: /* Block: '{' BlockStmtsOpt '}'  */
#line 228 "j0gram.y"
                {(yyval.treeptr) = (yyvsp[-1].treeptr);}
#line 1701 "j0gram.tab.c"
    break;

  case 38: /* BlockStmtsOpt: BlockStmts  */
#line 232 "j0gram.y"
                {}
#line 1707 "j0gram.tab.c"
    break;

  case 39: /* BlockStmtsOpt: %empty  */
#line 234 "j0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1713 "j0gram.tab.c"
    break;

  case 40: /* BlockStmts: BlockStmt  */
#line 238 "j0gram.y"
                {}
#line 1719 "j0gram.tab.c"
    break;

  case 41: /* BlockStmts: BlockStmts BlockStmt  */
#line 240 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_BlockStmts,"BlockStmts",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1725 "j0gram.tab.c"
    break;

  case 42: /* BlockStmt: LocalVarDeclStmt  */
#line 244 "j0gram.y"
                {}
#line 1731 "j0gram.tab.c"
    break;

  case 43: /* BlockStmt: Stmt  */
#line 246 "j0gram.y"
                {}
#line 1737 "j0gram.tab.c"
    break;

  case 44: /* LocalVarDeclStmt: LocalVarDecl ';'  */
#line 251 "j0gram.y"
                {}
#line 1743 "j0gram.tab.c"
    break;

  case 45: /* LocalVarDecl: Type VarDecls  */
#line 255 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_LocalVarDecl,"LocalVarDecl",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1749 "j0gram.tab.c"
    break;

  case 46: /* Stmt: Block  */
#line 260 "j0gram.y"
                {}
#line 1755 "j0gram.tab.c"
    break;

  case 47: /* Stmt: ';'  */
#line 262 "j0gram.y"
                {}
#line 1761 "j0gram.tab.c"
    break;

  case 48: /* Stmt: ExprStmt  */
#line 264 "j0gram.y"
                {}
#line 1767 "j0gram.tab.c"
    break;

  case 49: /* Stmt: BreakStmt  */
#line 266 "j0gram.y"
                {}
#line 1773 "j0gram.tab.c"
    break;

  case 50: /* Stmt: ReturnStmt  */
#line 268 "j0gram.y"
                {}
#line 1779 "j0gram.tab.c"
    break;

  case 51: /* Stmt: IfThenStmt  */
#line 271 "j0gram.y"
                {}
#line 1785 "j0gram.tab.c"
    break;

  case 52: /* Stmt: IfThenElseStmt  */
#line 273 "j0gram.y"
                {}
#line 1791 "j0gram.tab.c"
    break;

  case 53: /* Stmt: IfThenElseIfStmt  */
#line 275 "j0gram.y"
                {}
#line 1797 "j0gram.tab.c"
    break;

  case 54: /* Stmt: WhileStmt  */
#line 278 "j0gram.y"
                {}
#line 1803 "j0gram.tab.c"
    break;

  case 55: /* Stmt: ForStmt  */
#line 280 "j0gram.y"
                {}
#line 1809 "j0gram.tab.c"
    break;

  case 56: /* ExprStmt: StmtExpr ';'  */
#line 285 "j0gram.y"
                {}
#line 1815 "j0gram.tab.c"
    break;

  case 57: /* StmtExpr: Assignment  */
#line 290 "j0gram.y"
                {}
#line 1821 "j0gram.tab.c"
    break;

  case 58: /* StmtExpr: MethodCall  */
#line 292 "j0gram.y"
                {}
#line 1827 "j0gram.tab.c"
    break;

  case 59: /* StmtExpr: InstantiationExpr  */
#line 294 "j0gram.y"
                {}
#line 1833 "j0gram.tab.c"
    break;

  case 60: /* IfThenStmt: IF '(' Expr ')' Block  */
#line 299 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_IfThenStmt,"IfThenStmt",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1839 "j0gram.tab.c"
    break;

  case 61: /* IfThenElseStmt: IF '(' Expr ')' Block ELSE Block  */
#line 303 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_IfThenElseStmt, "IfThenElseStmt",3, (yyvsp[-4].treeptr),(yyvsp[-2].treeptr), (yyvsp[0].treeptr));}
#line 1845 "j0gram.tab.c"
    break;

  case 62: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence  */
#line 307 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_IfThenElseIfStmt,"IfThenElseIfStmt",3,(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1851 "j0gram.tab.c"
    break;

  case 63: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence ELSE Block  */
#line 310 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_IfThenElseIfStmt,"IfThenElseIf_Else_Stmt",4, (yyvsp[-5].treeptr),(yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1857 "j0gram.tab.c"
    break;

  case 64: /* ElseIfSequence: ElseIfStmt  */
#line 315 "j0gram.y"
                {}
#line 1863 "j0gram.tab.c"
    break;

  case 65: /* ElseIfSequence: ElseIfSequence ElseIfStmt  */
#line 317 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_ElseIfSequence,"ElseIfSequence",2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1869 "j0gram.tab.c"
    break;

  case 66: /* ElseIfStmt: ELSE IfThenStmt  */
#line 321 "j0gram.y"
                {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1875 "j0gram.tab.c"
    break;

  case 67: /* WhileStmt: WHILE '(' Expr ')' Stmt  */
#line 325 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_WhileStmt,"WhileStmt",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1881 "j0gram.tab.c"
    break;

  case 68: /* ForStmt: FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block  */
#line 330 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_ForStmt,"ForStmt",4, (yyvsp[-6].treeptr),(yyvsp[-4].treeptr),(yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1887 "j0gram.tab.c"
    break;

  case 69: /* ForInit: StmtExprList  */
#line 334 "j0gram.y"
                {}
#line 1893 "j0gram.tab.c"
    break;

  case 70: /* ForInit: LocalVarDecl  */
#line 336 "j0gram.y"
                {}
#line 1899 "j0gram.tab.c"
    break;

  case 71: /* ForInit: %empty  */
#line 338 "j0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1905 "j0gram.tab.c"
    break;

  case 72: /* ExprOpt: Expr  */
#line 342 "j0gram.y"
                {}
#line 1911 "j0gram.tab.c"
    break;

  case 73: /* ExprOpt: %empty  */
#line 344 "j0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1917 "j0gram.tab.c"
    break;

  case 74: /* ForUpdate: StmtExprList  */
#line 348 "j0gram.y"
                {}
#line 1923 "j0gram.tab.c"
    break;

  case 75: /* ForUpdate: %empty  */
#line 350 "j0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1929 "j0gram.tab.c"
    break;

  case 76: /* StmtExprList: StmtExpr  */
#line 355 "j0gram.y"
                {}
#line 1935 "j0gram.tab.c"
    break;

  case 77: /* StmtExprList: StmtExprList ',' StmtExpr  */
#line 357 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_StmtExprList,"StmtExprList",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 1941 "j0gram.tab.c"
    break;

  case 78: /* BreakStmt: BREAK ';'  */
#line 362 "j0gram.y"
                {}
#line 1947 "j0gram.tab.c"
    break;

  case 79: /* BreakStmt: BREAK IDENTIFIER ';'  */
#line 364 "j0gram.y"
                {(yyval.treeptr) = (yyvsp[-1].treeptr);}
#line 1953 "j0gram.tab.c"
    break;

  case 80: /* ReturnStmt: RETURN ExprOpt ';'  */
#line 368 "j0gram.y"
                {(yyval.treeptr) = (yyvsp[-1].treeptr);}
#line 1959 "j0gram.tab.c"
    break;

  case 81: /* Primary: Literal  */
#line 373 "j0gram.y"
                {}
#line 1965 "j0gram.tab.c"
    break;

  case 82: /* Primary: '(' Expr ')'  */
#line 375 "j0gram.y"
                {(yyval.treeptr) = (yyvsp[-1].treeptr);}
#line 1971 "j0gram.tab.c"
    break;

  case 83: /* Primary: FieldAccess  */
#line 377 "j0gram.y"
                {}
#line 1977 "j0gram.tab.c"
    break;

  case 84: /* Primary: MethodCall  */
#line 379 "j0gram.y"
                {}
#line 1983 "j0gram.tab.c"
    break;

  case 85: /* Literal: INTLIT  */
#line 383 "j0gram.y"
                {}
#line 1989 "j0gram.tab.c"
    break;

  case 86: /* Literal: DOUBLELIT  */
#line 385 "j0gram.y"
                {}
#line 1995 "j0gram.tab.c"
    break;

  case 87: /* Literal: BOOLLIT  */
#line 387 "j0gram.y"
                {}
#line 2001 "j0gram.tab.c"
    break;

  case 88: /* Literal: STRINGLIT  */
#line 389 "j0gram.y"
                {}
#line 2007 "j0gram.tab.c"
    break;

  case 89: /* Literal: NULLVAL  */
#line 391 "j0gram.y"
                {}
#line 2013 "j0gram.tab.c"
    break;

  case 90: /* InstantiationExpr: NEW Name '(' ArgListOpt ')'  */
#line 396 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_InstantiationExpr,"InstantiationExpr",2, (yyvsp[-3].treeptr),(yyvsp[-1].treeptr));}
#line 2019 "j0gram.tab.c"
    break;

  case 91: /* ArgList: Expr  */
#line 400 "j0gram.y"
                {}
#line 2025 "j0gram.tab.c"
    break;

  case 92: /* ArgList: ArgList ',' Expr  */
#line 402 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_ArgList,"ArgList",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2031 "j0gram.tab.c"
    break;

  case 93: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 406 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_FieldAccess,"FieldAccess",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2037 "j0gram.tab.c"
    break;

  case 94: /* MethodCall: Name '(' ArgListOpt ')'  */
#line 411 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodCall,"MethodCall_parens",2, (yyvsp[-3].treeptr),(yyvsp[-1].treeptr));}
#line 2043 "j0gram.tab.c"
    break;

  case 95: /* MethodCall: Name '{' ArgListOpt '}'  */
#line 414 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodCall,"MethodCall_curly",2, (yyvsp[-3].treeptr),(yyvsp[-1].treeptr));}
#line 2049 "j0gram.tab.c"
    break;

  case 96: /* MethodCall: Primary '.' IDENTIFIER '(' ArgListOpt ')'  */
#line 417 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodCall,"MethodCall_primary_parens",3, (yyvsp[-5].treeptr),(yyvsp[-3].treeptr),(yyvsp[-1].treeptr));}
#line 2055 "j0gram.tab.c"
    break;

  case 97: /* MethodCall: Primary '.' IDENTIFIER '{' ArgListOpt '}'  */
#line 420 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MethodCall,"MethodCall_primary_curly",3, (yyvsp[-5].treeptr),(yyvsp[-3].treeptr),(yyvsp[-1].treeptr));}
#line 2061 "j0gram.tab.c"
    break;

  case 98: /* PostFixExpr: Primary  */
#line 425 "j0gram.y"
                {}
#line 2067 "j0gram.tab.c"
    break;

  case 99: /* PostFixExpr: Name  */
#line 427 "j0gram.y"
                {}
#line 2073 "j0gram.tab.c"
    break;

  case 100: /* UnaryExpr: '-' UnaryExpr  */
#line 431 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_UnaryExpr, "UnaryExpr_Neg", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2079 "j0gram.tab.c"
    break;

  case 101: /* UnaryExpr: '!' UnaryExpr  */
#line 433 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_UnaryExpr, "UnaryExpr_Excl", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2085 "j0gram.tab.c"
    break;

  case 102: /* UnaryExpr: PostFixExpr  */
#line 435 "j0gram.y"
                {}
#line 2091 "j0gram.tab.c"
    break;

  case 103: /* MulExpr: UnaryExpr  */
#line 439 "j0gram.y"
                {}
#line 2097 "j0gram.tab.c"
    break;

  case 104: /* MulExpr: MulExpr '*' UnaryExpr  */
#line 441 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MulExpr,"MulExpr_multiply",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2103 "j0gram.tab.c"
    break;

  case 105: /* MulExpr: MulExpr '/' UnaryExpr  */
#line 444 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MulExpr,"MulExpr_divide",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2109 "j0gram.tab.c"
    break;

  case 106: /* MulExpr: MulExpr '%' UnaryExpr  */
#line 446 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_MulExpr,"MulExpr_modulus",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2115 "j0gram.tab.c"
    break;

  case 107: /* AddExpr: MulExpr  */
#line 450 "j0gram.y"
                {}
#line 2121 "j0gram.tab.c"
    break;

  case 108: /* AddExpr: AddExpr '+' MulExpr  */
#line 452 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_AddExpr,"AddExpr_add",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2127 "j0gram.tab.c"
    break;

  case 109: /* AddExpr: AddExpr '-' MulExpr  */
#line 454 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_AddExpr,"AddExpr_subtract",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2133 "j0gram.tab.c"
    break;

  case 110: /* RelOp: LESSTHANOREQUAL  */
#line 458 "j0gram.y"
                {}
#line 2139 "j0gram.tab.c"
    break;

  case 111: /* RelOp: GREATERTHANOREQUAL  */
#line 460 "j0gram.y"
                {}
#line 2145 "j0gram.tab.c"
    break;

  case 112: /* RelOp: '<'  */
#line 462 "j0gram.y"
                {}
#line 2151 "j0gram.tab.c"
    break;

  case 113: /* RelOp: '>'  */
#line 464 "j0gram.y"
                {}
#line 2157 "j0gram.tab.c"
    break;

  case 114: /* RelExpr: AddExpr  */
#line 468 "j0gram.y"
                {}
#line 2163 "j0gram.tab.c"
    break;

  case 115: /* RelExpr: RelExpr RelOp AddExpr  */
#line 470 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_RelExpr,"RelExpr",3, (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2169 "j0gram.tab.c"
    break;

  case 116: /* EqExpr: RelExpr  */
#line 475 "j0gram.y"
                {}
#line 2175 "j0gram.tab.c"
    break;

  case 117: /* EqExpr: EqExpr ISEQUALTO RelExpr  */
#line 477 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_EqExpr,"EqExpr_isequal",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2181 "j0gram.tab.c"
    break;

  case 118: /* EqExpr: EqExpr NOTEQUALTO RelExpr  */
#line 479 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_EqExpr,"EqExpr_notequal",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2187 "j0gram.tab.c"
    break;

  case 119: /* CondAndExpr: EqExpr  */
#line 483 "j0gram.y"
                {}
#line 2193 "j0gram.tab.c"
    break;

  case 120: /* CondAndExpr: CondAndExpr LOGICALAND EqExpr  */
#line 485 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_CondAndExpr,"CondAndExpr",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2199 "j0gram.tab.c"
    break;

  case 121: /* CondOrExpr: CondAndExpr  */
#line 489 "j0gram.y"
                {}
#line 2205 "j0gram.tab.c"
    break;

  case 122: /* CondOrExpr: CondOrExpr LOGICALOR CondAndExpr  */
#line 491 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_CondOrExpr,"CondOrExpr",2, (yyvsp[-2].treeptr),(yyvsp[0].treeptr));}
#line 2211 "j0gram.tab.c"
    break;

  case 123: /* Expr: CondOrExpr  */
#line 496 "j0gram.y"
                {}
#line 2217 "j0gram.tab.c"
    break;

  case 124: /* Expr: Assignment  */
#line 498 "j0gram.y"
                {}
#line 2223 "j0gram.tab.c"
    break;

  case 125: /* Assignment: LeftHandSide AssignOp Expr  */
#line 502 "j0gram.y"
                {(yyval.treeptr) = create_branch(prodR_Assignment,"Assignment",3, (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2229 "j0gram.tab.c"
    break;

  case 126: /* LeftHandSide: Name  */
#line 506 "j0gram.y"
                {}
#line 2235 "j0gram.tab.c"
    break;

  case 127: /* LeftHandSide: FieldAccess  */
#line 508 "j0gram.y"
                {}
#line 2241 "j0gram.tab.c"
    break;

  case 128: /* AssignOp: '='  */
#line 512 "j0gram.y"
                {}
#line 2247 "j0gram.tab.c"
    break;

  case 129: /* AssignOp: INCREMENT  */
#line 514 "j0gram.y"
                {}
#line 2253 "j0gram.tab.c"
    break;

  case 130: /* AssignOp: DECREMENT  */
#line 516 "j0gram.y"
                {}
#line 2259 "j0gram.tab.c"
    break;


#line 2263 "j0gram.tab.c"

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

