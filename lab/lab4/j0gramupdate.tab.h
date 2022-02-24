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

#ifndef YY_YY_J0GRAMUPDATE_TAB_H_INCLUDED
# define YY_YY_J0GRAMUPDATE_TAB_H_INCLUDED
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

#line 119 "j0gramupdate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_J0GRAMUPDATE_TAB_H_INCLUDED  */
