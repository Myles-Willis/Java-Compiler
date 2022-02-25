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
		{$$ = create_branch(prodR_ClassBodyDecls,"ClassBodyDecls",2, $1,$2);}
	;
ClassBodyDecl:
	FieldDecl
		{}
	| MethodDecl
		{}
	| ConstructorDecl
		{}
	;
FieldDecl: //Case?
	Type VarDecls ';'
		{$$ = create_branch(prodR_FieldDecl,"FieldDecl",2, $1,$2);}
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
		{$$ = create_branch(prodR_VarDecls,"VarDecls_multi",2, $1,$3);}
	;
VarDeclarator: //case?
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
		{$$ = create_branch(prodR_MethodHeader,"MethodHeader",2, $3,$4);}
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
		{$$ = create_branch(prodR_FormalParmList,"FormalParmList",2, $1,$3);}
	;
FormalParm:
	Type VarDeclarator
		{}
	;

ConstructorDecl:
	ConstructorDeclarator Block
		{$$ = create_branch(prodR_ConstructorDecl,"ConstructorDecl",2, $1,$2);}
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
		{$$ = create_branch(prodR_BlockStmts,"BlockStmts",2, $1,$2);}
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
		{$$ = create_branch(prodR_IfThenStmt,"IfThenStmt",2, $3,$5);}
	;
IfThenElseStmt:
	IF '(' Expr ')' Block ELSE Block
		{$$ = create_branch(prodR_IfThenElseStmt, "IfThenElseStmt",3, $3,$5, $7);}
	;
IfThenElseIfStmt:
	IF '(' Expr ')' Block ElseIfSequence
		{$$ = create_branch(prodR_IfThenElseIfStmt,"IfThenElseIfStmt",3,$5,$6);}

  |  IF '(' Expr ')' Block ElseIfSequence ELSE Block
		{$$ = create_branch(prodR_IfThenElseIfStmt,"IfThenElseIf_Else_Stmt",4, $3,$5,$6,$8);}
  ;

ElseIfSequence:
	ElseIfStmt
		{}
	| ElseIfSequence ElseIfStmt
		{$$ = create_branch(prodR_ElseIfSequence,"ElseIfSequence",2, $1,$2);}
	;
ElseIfStmt:
	ELSE IfThenStmt
		{}
	;
WhileStmt:
	WHILE '(' Expr ')' Stmt
		{$$ = create_branch(prodR_WhileStmt,"WhileStmt",2, $3,$5);}
	;

ForStmt:
	FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block
		{$$ = create_branch(prodR_ForStmt,"ForStmt",4, $3,$5,$7,$9);}
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
		{$$ = create_branch(prodR_StmtExprList,"StmtExprList",2, $1,$3);}
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
		{$$ = create_branch(prodR_InstantiationExpr,"InstantiationExpr",2, $2,$4);}
	;
ArgList:
	Expr
		{}
	| ArgList ',' Expr
		{$$ = create_branch(prodR_ArgList,"ArgList",2, $1,$3);}
	;
FieldAccess:
	Primary '.' IDENTIFIER
		{}
	;

MethodCall:
	Name '(' ArgListOpt ')'
		{$$ = create_branch(prodR_MethodCall,"MethodCall_parens",2, $1,$3);}

	| Name '{' ArgListOpt '}'
		{$$ = create_branch(prodR_MethodCall,"MethodCall_curly",2, $1,$3);}

	| Primary '.' IDENTIFIER '(' ArgListOpt ')'
		{$$ = create_branch(prodR_MethodCall,"MethodCall_primary_parens",3, $1,$3,$5);}

	| Primary '.' IDENTIFIER '{' ArgListOpt '}'
		{$$ = create_branch(prodR_MethodCall,"MethodCall_primary_curly",3, $1,$3,$5);}
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
		{$$ = create_branch(prodR_MulExpr,"MulExpr_multiply",2, $1,$3);}

	| MulExpr '/' UnaryExpr
		{$$ = create_branch(prodR_MulExpr,"MulExpr_divide",2, $1,$3);}
	| MulExpr '%' UnaryExpr
		{$$ = create_branch(prodR_MulExpr,"MulExpr_modulus",2, $1,$3);}
	;
AddExpr:
	MulExpr
		{}
	| AddExpr '+' MulExpr
		{$$ = create_branch(prodR_AddExpr,"AddExpr_add",2, $1,$3);}
	| AddExpr '-' MulExpr
		{$$ = create_branch(prodR_AddExpr,"AddExpr_subtract",2, $1,$3);}
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
		{$$ = create_branch(prodR_RelExpr,"RelExpr",3, $1,$2,$3);}
	;

EqExpr:
	RelExpr
		{}
	| EqExpr ISEQUALTO RelExpr
		{$$ = create_branch(prodR_EqExpr,"EqExpr_isequal",2, $1,$3);}
	| EqExpr NOTEQUALTO RelExpr
		{$$ = create_branch(prodR_EqExpr,"EqExpr_notequal",2, $1,$3);}
	;
CondAndExpr:
	EqExpr
		{}
	| CondAndExpr LOGICALAND EqExpr
		{$$ = create_branch(prodR_CondAndExpr,"CondAndExpr",2, $1,$3);}
	;
CondOrExpr:
	CondAndExpr
		{}
	| CondOrExpr LOGICALOR CondAndExpr
		{$$ = create_branch(prodR_CondOrExpr,"CondOrExpr",2, $1,$3);}
	;

Expr:
	CondOrExpr
		{}
	| Assignment
		{}
	;
Assignment:
	LeftHandSide AssignOp Expr
		{$$ = create_branch(prodR_Assignment,"Assignment",3, $1,$2,$3);}
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
