%{
    #include <stdio.h>
		#define YYDEBUG 1

		extern int yyerror(char *s);
		extern int yylex();
		extern int yyparse();

		#include "tree.h"
		extern struct tree *root;
%}
%union {
   struct tree *treeptr;
}
// Originally in j0gram.y but not in j0lex.l
%token <treeptr> CLASSNAME STRING DOUBLELIT NULLVAL

// j0 Reserved Words
%token <treeptr> BOOL BREAK CASE CHAR CLASS CONTINUE DEFAULT DOUBLE ELSE FLOAT FOR IF
%token <treeptr> INSTANCEOF INT LONG NEW PUBLIC RETURN STATIC SWITCH VOID WHILE

// j0 Literals
%token <treeptr> REALLIT INTLIT STRINGLIT BOOLLIT CHARLIT

// j0 Comparison/Operators
%token <treeptr> INCREMENT DECREMENT ISEQUALTO NOTEQUALTO GREATERTHANOREQUAL
%token <treeptr> LESSTHANOREQUAL LOGICALAND LOGICALOR LOGICALNOT TYPE

//Indentifier
%token <treeptr> IDENTIFIER

// j0 Errors
%token <treeptr> INVALIDCHARLIT INVALID_PUNCTUATION NOT_IN_JZERO_RESERVED
%token <treeptr> UNRECOGNIZED_CHARACTER INTLIT_RANGE_INVALID
%token <treeptr> INVALID_ESCAPE_IN_STRING REALLIT_RANGE_INVALID

%type <treeptr> ClassDecl
%type <treeptr> ClassBody
%type <treeptr> ClassBodyDecls
%type <treeptr> ClassBodyDecl
%type <treeptr> FieldDecl
%type <treeptr> Type
%type <treeptr> Name
%type <treeptr> QualifiedName
%type <treeptr> VarDecls
%type <treeptr> VarDeclarator
%type <treeptr> MethodReturnVal
%type <treeptr> MethodDecl
%type <treeptr> MethodHeader
%type <treeptr> MethodDeclarator
%type <treeptr> FormalParmListOpt
%type <treeptr> FormalParmList
%type <treeptr> FormalParm
%type <treeptr> ConstructorDecl
%type <treeptr> ConstructorDeclarator
%type <treeptr> ArgListOpt
%type <treeptr> Block
%type <treeptr> BlockStmtsOpt
%type <treeptr> BlockStmts
%type <treeptr> BlockStmt
%type <treeptr> LocalVarDeclStmt
%type <treeptr> LocalVarDecl
%type <treeptr> Stmt
%type <treeptr> ExprStmt
%type <treeptr> StmtExpr
%type <treeptr> IfThenStmt
%type <treeptr> IfThenElseStmt
%type <treeptr> IfThenElseIfStmt
%type <treeptr> ElseIfSequence
%type <treeptr> ElseIfStmt
%type <treeptr> WhileStmt
%type <treeptr> ForStmt
%type <treeptr> ForInit
%type <treeptr> ExprOpt
%type <treeptr> ForUpdate
%type <treeptr> StmtExprList
%type <treeptr> BreakStmt
%type <treeptr> ReturnStmt
%type <treeptr> Primary
%type <treeptr> Literal
%type <treeptr> InstantiationExpr
%type <treeptr> ArgList
%type <treeptr> FieldAccess
%type <treeptr> MethodCall
%type <treeptr> PostFixExpr
%type <treeptr> UnaryExpr
%type <treeptr> MulExpr
%type <treeptr> AddExpr
%type <treeptr> RelOp
%type <treeptr> RelExpr
%type <treeptr> EqExpr
%type <treeptr> CondAndExpr
%type <treeptr> CondOrExpr
%type <treeptr> Expr
%type <treeptr> Assignment
%type <treeptr> LeftHandSide
%type <treeptr> AssignOp
%%

ClassDecl:
	PUBLIC CLASS IDENTIFIER ClassBody
		{}
	;
ClassBody:
	'{' ClassBodyDecls '}'
		{}
	| '{' '}'
		{}
	;
ClassBodyDecls:
	ClassBodyDecl
		{}
	| ClassBodyDecls ClassBodyDecl
		{} //$$ = create_branch(prodR_,"temp",2, $1,$2);
	;
ClassBodyDecl:
	FieldDecl
		{}
	| MethodDecl
		{}
	| ConstructorDecl
		{}
	;
FieldDecl:
	Type VarDecls ';'
		{}
	;
Type:
	INT
		{}
	| DOUBLE
		{}
	| BOOL
		{}
	| STRING
		{}
	| Name
		{}
	;

Name:
	IDENTIFIER
		{}
	| QualifiedName
		{}
	;
QualifiedName:
	Name '.' IDENTIFIER
		{}
	;

VarDecls:
	VarDeclarator
		{}
	| VarDecls ',' VarDeclarator
		{}
	;
VarDeclarator:
	IDENTIFIER
		{}
	| VarDeclarator '[' ']'
		{}
	;

MethodReturnVal:
	Type
		{}
	| VOID
		{}
	;
MethodDecl:
	MethodHeader Block
		{}
	;
MethodHeader:
	PUBLIC STATIC MethodReturnVal MethodDeclarator
		{}
	;
MethodDeclarator:
	IDENTIFIER '(' FormalParmListOpt ')'
		{}
	;
FormalParmListOpt:
	FormalParmList
		{}
	|
		{}
	;
FormalParmList:
	FormalParm
		{}
	| FormalParmList ',' FormalParm
		{}
	;
FormalParm:
	Type VarDeclarator
		{}
	;

ConstructorDecl:
	ConstructorDeclarator Block
		{}
	;
ConstructorDeclarator:
	IDENTIFIER '(' FormalParmListOpt ')'
		{}
	;
ArgListOpt:
	 ArgList
		{}
	|
		{}
	;

Block:
	'{' BlockStmtsOpt '}'
		{}
	;
BlockStmtsOpt:
	BlockStmts
		{}
	|
		{}
	;
BlockStmts:
	 BlockStmt
		{}
	| BlockStmts BlockStmt
		{}
	;
BlockStmt:
	  LocalVarDeclStmt
		{}
	| Stmt
		{}
	;

LocalVarDeclStmt:
	LocalVarDecl ';'
		{}
	;
LocalVarDecl:
	Type VarDecls
		{}
	;

Stmt:
	Block
		{}
	| ';'
		{}
	| ExprStmt
		{}
	| BreakStmt
		{}
	| ReturnStmt
		{}

	| IfThenStmt
		{}
	| IfThenElseStmt
		{}
	| IfThenElseIfStmt
		{}

	| WhileStmt
		{}
	| ForStmt
		{}
	;

ExprStmt:
	StmtExpr ';'
		{}
	;

StmtExpr:
	Assignment
		{}
	| MethodCall
		{}
	| InstantiationExpr
		{}
	;

IfThenStmt:
	IF '(' Expr ')' Block
		{}
	;
IfThenElseStmt:
	IF '(' Expr ')' Block ELSE Block
		{}
	;
IfThenElseIfStmt:
	IF '(' Expr ')' Block ElseIfSequence
		{}

  |  IF '(' Expr ')' Block ElseIfSequence ELSE Block
		{}
  ;

ElseIfSequence:
	ElseIfStmt
		{}
	| ElseIfSequence ElseIfStmt
		{}
	;
ElseIfStmt:
	ELSE IfThenStmt
		{}
	;
WhileStmt:
	WHILE '(' Expr ')' Stmt
		{}
	;

ForStmt:
	FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block
		{}
	;
ForInit:
	StmtExprList
		{}
	| LocalVarDecl
		{}
	|
		{}
	;
ExprOpt:
	Expr
		{}
	|
		{}
	;
ForUpdate:
	StmtExprList
		{}
	|
		{}
	;

StmtExprList:
	StmtExpr
		{}
	| StmtExprList ',' StmtExpr
		{}
	;

BreakStmt:
	BREAK ';'
		{}
	| BREAK IDENTIFIER ';'
		{}
	;
ReturnStmt:
	RETURN ExprOpt ';'
		{}
	;

Primary:
	 Literal
		{}
	| '(' Expr ')'
		{}
	| FieldAccess
		{}
	| MethodCall
		{}
	;
Literal:
	INTLIT
		{}
	| DOUBLELIT
		{}
	| BOOLLIT
		{}
	| STRINGLIT
		{}
	| NULLVAL
		{}
	;

InstantiationExpr:
	NEW Name '(' ArgListOpt ')'
		{}
	;
ArgList:
	Expr
		{}
	| ArgList ',' Expr
		{}
	;
FieldAccess:
	Primary '.' IDENTIFIER
		{}
	;

MethodCall:
	Name '(' ArgListOpt ')'
		{}

	| Name '{' ArgListOpt '}'
		{}

	| Primary '.' IDENTIFIER '(' ArgListOpt ')'
		{}

	| Primary '.' IDENTIFIER '{' ArgListOpt '}'
		{}
	;

PostFixExpr:
	Primary
		{}
	| Name
		{}
	;
UnaryExpr:
	 '-' UnaryExpr
		{}
	| '!' UnaryExpr
		{}
	| PostFixExpr
		{}
	;
MulExpr:
	UnaryExpr
		{}
	| MulExpr '*' UnaryExpr
		{}

	| MulExpr '/' UnaryExpr
		{}
	| MulExpr '%' UnaryExpr
		{}
	;
AddExpr:
	MulExpr
		{}
	| AddExpr '+' MulExpr
		{}
	| AddExpr '-' MulExpr
		{}
	;
RelOp:
	LESSTHANOREQUAL
		{}
	| GREATERTHANOREQUAL
		{}
	| '<'
		{}
	| '>'
		{}
	;
RelExpr:
	AddExpr
		{}
	| RelExpr RelOp AddExpr
		{}
	;

EqExpr:
	RelExpr
		{}
	| EqExpr ISEQUALTO RelExpr
		{}
	| EqExpr NOTEQUALTO RelExpr
		{}
	;
CondAndExpr:
	EqExpr
		{}
	| CondAndExpr LOGICALAND EqExpr
		{}
	;
CondOrExpr:
	CondAndExpr
		{}
	| CondOrExpr LOGICALOR CondAndExpr
		{}
	;

Expr:
	CondOrExpr
		{}
	| Assignment
		{}
	;
Assignment:
	LeftHandSide AssignOp Expr
		{}
	;
LeftHandSide:
	Name
		{}
	| FieldAccess
		{}
	;
AssignOp:
	'='
		{}
	| INCREMENT
		{}
	| DECREMENT
		{}
	;
