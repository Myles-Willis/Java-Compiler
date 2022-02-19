%{
    #include <stdio.h>
		#include "tree.h"
		#define YYDEBUG 1
    int yylex();
		int yyparse();
		extern int yyerror(char *s);
%}

%union {
   struct tree *treeptr;
}
// Originally in j0gram.y but not in j0lex.l
%token CLASSNAME STRING DOUBLELIT NULLVAL

// j0 Reserved Words
%token BOOL BREAK CASE CHAR CLASS CONTINUE DEFAULT DOUBLE ELSE FLOAT FOR IF
%token INSTANCEOF INT LONG NEW PUBLIC RETURN STATIC SWITCH VOID WHILE

// j0 Literals
%token REALLIT INTLIT STRINGLIT BOOLLIT CHARLIT

// j0 Comparison/Operators
%token INCREMENT DECREMENT ISEQUALTO NOTEQUALTO GREATERTHANOREQUAL
%token LESSTHANOREQUAL LOGICALAND LOGICALOR LOGICALNOT TYPE

//Indentifier
%token IDENTIFIER

// j0 Errors
%token INVALIDCHARLIT INVALID_PUNCTUATION NOT_IN_JZERO_RESERVED
%token UNRECOGNIZED_CHARACTER INTLIT_RANGE_INVALID
%token INVALID_ESCAPE_IN_STRING REALLIT_RANGE_INVALID
%%

ClassDecl: PUBLIC CLASS IDENTIFIER ClassBody;
ClassBody: '{' ClassBodyDecls '}' | '{' '}' ;
ClassBodyDecls: ClassBodyDecl | ClassBodyDecls ClassBodyDecl ;
ClassBodyDecl: FieldDecl | MethodDecl | ConstructorDecl ;
FieldDecl: Type VarDecls ';' ;
Type: INT | DOUBLE | BOOL | STRING | Name | LONG | FLOAT | CHAR ;

Name: IDENTIFIER  | QualifiedName ;
QualifiedName: Name '.' IDENTIFIER ;

VarDecls: VarDeclarator | VarDecls ',' VarDeclarator ;
VarDeclarator: IDENTIFIER | VarDeclarator '[' ']' ;

MethodReturnVal : Type | VOID ;
MethodDecl: MethodHeader Block ;
MethodHeader: PUBLIC STATIC MethodReturnVal MethodDeclarator ;
MethodDeclarator: IDENTIFIER '(' FormalParmListOpt ')' ;
FormalParmListOpt: FormalParmList | ;
FormalParmList: FormalParm | FormalParmList ',' FormalParm ;
FormalParm: Type VarDeclarator ;

ConstructorDecl: ConstructorDeclarator Block ;
ConstructorDeclarator: IDENTIFIER '(' FormalParmListOpt ')' ;
ArgListOpt:  ArgList | ;

Block: '{' BlockStmtsOpt '}' ;
BlockStmtsOpt: BlockStmts | ;
BlockStmts:  BlockStmt | BlockStmts BlockStmt ;
BlockStmt:   LocalVarDeclStmt | Stmt ;

LocalVarDeclStmt: LocalVarDecl ';' ;
LocalVarDecl: Type VarDecls ;

Stmt: Block | ';' | ExprStmt | BreakStmt | ReturnStmt |
      | IfThenStmt | IfThenElseStmt | IfThenElseIfStmt
      | WhileStmt | ForStmt ;

ExprStmt: StmtExpr ';' ;

StmtExpr: Assignment | MethodCall | InstantiationExpr ;

IfThenStmt: IF '(' Expr ')' Block ;
IfThenElseStmt: IF '(' Expr ')' Block ELSE Block ;
IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence
       |  IF '(' Expr ')' Block ElseIfSequence ELSE Block ;

ElseIfSequence: ElseIfStmt | ElseIfSequence ElseIfStmt ;
ElseIfStmt: ELSE IfThenStmt ;
WhileStmt: WHILE '(' Expr ')' Stmt ;

ForStmt: FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block ;
ForInit: StmtExprList | LocalVarDecl | ;
ExprOpt: Expr |  ;
ForUpdate: StmtExprList | ;

StmtExprList: StmtExpr | StmtExprList ',' StmtExpr ;

BreakStmt: BREAK ';' | BREAK IDENTIFIER ';' ;
ReturnStmt: RETURN ExprOpt ';' ;

Primary:  Literal | '(' Expr ')' | FieldAccess | MethodCall ;
Literal: INTLIT	| DOUBLELIT | BOOLLIT | STRINGLIT | NULLVAL ;

InstantiationExpr: Name '(' ArgListOpt ')' ;
ArgList: Expr | ArgList ',' Expr ;
FieldAccess: Primary '.' IDENTIFIER ;

MethodCall: Name '(' ArgListOpt ')'
	| Name '{' ArgListOpt '}'
	| Primary '.' IDENTIFIER '(' ArgListOpt ')'
	| Primary '.' IDENTIFIER '{' ArgListOpt '}' ;

PostFixExpr: Primary | Name ;
UnaryExpr:  '-' UnaryExpr | '!' UnaryExpr | PostFixExpr ;
MulExpr: UnaryExpr | MulExpr '*' UnaryExpr
    | MulExpr '/' UnaryExpr | MulExpr '%' UnaryExpr ;
AddExpr: MulExpr | AddExpr '+' MulExpr | AddExpr '-' MulExpr ;
RelOp: LESSTHANOREQUAL | GREATERTHANOREQUAL | '<' | '>' ;
RelExpr: AddExpr | RelExpr RelOp AddExpr ;

EqExpr: RelExpr | EqExpr ISEQUALTO RelExpr | EqExpr NOTEQUALTO RelExpr ;
CondAndExpr: EqExpr | CondAndExpr LOGICALAND EqExpr ;
CondOrExpr: CondAndExpr | CondOrExpr LOGICALOR CondAndExpr ;

Expr: CondOrExpr | Assignment ;
Assignment: LeftHandSide AssignOp Expr ;
LeftHandSide: Name | FieldAccess ;
AssignOp: '=' | INCREMENT | DECREMENT ;
