%{
	#define YYDEBUG 1

	extern int yylex();
	extern int yyerror(const char *s);

	#include <stdio.h>
	/* #include "tree.h" */
	#include "type.h"
	#include "symboltable.h"

	struct tree *root;
%}

%union {
   struct tree *treeptr;
}

%glr-parser

// Originally in j0gram.y but not in j0lex.l
%token <treeptr> CLASSNAME STRING DOUBLELIT NULLVAL

// j0 Reserved Words
%token <treeptr> BOOL BREAK CASE CHAR CLASS CONTINUE DEFAULT DOUBLE ELSE FLOAT FOR IF
%token <treeptr> INSTANCEOF INT LONG NEW PUBLIC RETURN STATIC SWITCH VOID WHILE

// j0 Literals
%token <treeptr> REALLIT INTLIT STRINGLIT BOOLLIT CHARLIT

// j0 Comparison/Operators
%token <treeptr> INCREMENT DECREMENT ISEQUALTO NOTEQUALTO GREATERTHANOREQUAL
%token <treeptr> LESSTHANOREQUAL LOGICALAND LOGICALOR TYPE

//Indentifier
%token <treeptr> IDENTIFIER

// j0 Errors
%token <treeptr> INVALIDCHARLIT INVALID_PUNCTUATION NOT_IN_JZERO_RESERVED
%token <treeptr> UNRECOGNIZED_CHARACTER INTLIT_RANGE_INVALID
%token <treeptr> INVALID_ESCAPE_IN_STRING REALLIT_RANGE_INVALID
%token <treeptr> INVALID_CHARLIT_ESCAPE EMPTY_CHARLIT OPENENDED_CHARLIT
%token <treeptr> '-' '+' '!' '='

%left ELSE
%left LOGICALOR
%left LOGICALAND
%left ISEQUALTO NOTEQUALTO
%left '<' GREATERTHANOREQUAL '>' LESSTHANOREQUAL
%left '+' '-'
%left '*' '/' '%'

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
/* %type <treeptr> HeaderPS
%type <treeptr> HeaderOption
%type <treeptr> HeaderOptions */
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
%type <treeptr> Array
%type <treeptr> ArrayAccess
%type <treeptr> Index
%type <treeptr> OptArray

%start ClassDecl
%%


ClassDecl:
	PUBLIC CLASS IDENTIFIER ClassBody
		{root = create_branch(prodR_ClassDecl, "ClassDecl", 4, $1,$2,$3,$4);}
	;
ClassBody:
	'{' ClassBodyDecls '}'
		{$$ = $2;}
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
FieldDecl:
	Type VarDecls ';'
		{$$ = create_branch(prodR_FieldDecl,"FieldDecl",2, $1,$2);}
	| PUBLIC STATIC Type VarDecls ';'
		{$$ = create_branch(prodR_StaticFieldDecl,"StaticFieldDecl",2, $3,$4);}
	| PUBLIC STATIC Type VarDeclarator '=' Literal ';'
		{$$ = create_branch(prodR_FieldDeclAssign,"FieldDeclAssignment",4, $3,$4,$5,$6);}
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
	| CHAR
		{}
	| FLOAT
		{}
	;

Name:
	IDENTIFIER
		{} //
	| QualifiedName
		{}
	;
QualifiedName:
	IDENTIFIER '.' Name
		{$$ = create_branch(prodR_QualifiedName,"QualifiedName",2, $1,$3);}
	;

VarDecls:
	VarDeclarator
		{$$ = create_branch(prodR_VarDecls,"VarDecls",1, $1);}
	| VarDecls ',' VarDeclarator
		{throw_syntax_error("inline declarations not supported in j0.1");}
	;

VarDeclarator:
	VarDeclarator '[' ']'
		{$$ = create_branch(prodR_PostBracketArrayDeclarator,"PostBracketArrayDeclarator",1, $1);}
	| '[' ']' VarDeclarator
		{$$ = create_branch(prodR_PreBracketArrayDeclarator,"PreBracketArrayDeclarator",1, $3);} //Setting $$ = $3; causes a segfault in methodcall type case
			/* $$ = create_branch(prodR_PreBracketArrayDeclarator,"PreBracketArrayDeclarator",1, $3); */
	| IDENTIFIER
			{}
	;

MethodReturnVal:
	OptArray //was Type
		{}
	| VOID
		{}
	;

OptArray:
	Array
		{}
	| Type
		{}
	;

MethodDecl:
	MethodHeader Block
		{
			$$ = create_branch(prodR_MethodDecl,"MethodDecl",2, $1,$2);
		}
	;
MethodHeader:
	 PUBLIC STATIC MethodReturnVal MethodDeclarator
		{$$ = create_branch(prodR_MethodHeader,"MethodHeader",2, $3,$4);}
	;

MethodDeclarator:
	IDENTIFIER '(' FormalParmListOpt ')'
		{$$ = create_branch(prodR_MethodDeclarator, "MethodDeclarator", 2, $1, $3);}
	;
FormalParmListOpt:
	FormalParmList
		{}
	|
		{$$ = NULL;}
	;
FormalParmList:
	FormalParm
		{}
	| FormalParmList ',' FormalParm
		{$$ = create_branch(prodR_FormalParmList,"FormalParmList",2, $1,$3);}
	;
FormalParm:
	Type VarDeclarator
		{$$ = create_branch(prodR_FormalParm,"FormalParm",2, $1,$2);}
	;

ConstructorDecl:
	ConstructorDeclarator Block
		{$$ = create_branch(prodR_ConstructorDecl,"ConstructorDecl",2, $1,$2);}
	;
ConstructorDeclarator:
	IDENTIFIER '(' FormalParmListOpt ')'
		{$$ = create_branch(prodR_ConstructorDeclarator,"ConstructorDeclarator",2, $1,$3);}
	;
ArgListOpt:
	 ArgList
		{}
	|
		{$$ = NULL;}
	;
Block:
	'{' BlockStmtsOpt '}'
		{$$ = $2;}
	;
BlockStmtsOpt:
	BlockStmts
		{}
	|
		{$$ = NULL;}
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
		{$$ = create_branch(prodR_LocalVarDecl,"LocalVarDecl",2, $1,$2);}
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
		{$$ = $2;}
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
		{$$ = NULL;}
	;
ExprOpt:
	Expr
		{}
	|
		{$$ = NULL;}
	;
ForUpdate:
	StmtExprList
		{}
	|
		{$$ = NULL;}
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
		{$$ = $2;}
	;
ReturnStmt:
	RETURN ExprOpt ';'
		{$$ = $2;}
	;

Primary:
	 Literal
		{}
	| '(' Expr ')'
		{$$ = $2;}
	| FieldAccess
		{}
	| MethodCall
		{}
	| ArrayAccess
		{}
	;

Index:
	INTLIT
		{}
	|
		{$$ = NULL;}
	;

Literal:
	INTLIT
		{}
	| DOUBLELIT
		{}
	| REALLIT
		{}
	| BOOLLIT
		{}
	| CHARLIT
		{}
	| STRINGLIT
		{}
	| NULLVAL
		{}
	;

InstantiationExpr:
	NEW Type '(' ArgListOpt ')'
		{throw_syntax_error("class instantiation not supported in j0.1");}
	| NEW Array
		{$$ = create_branch(prodR_ArrayInstantiation, "ArrayInstantiation",1, $2);}
	;

Array:
	Type '[' Index ']'
		{$$ = create_branch(prodR_PostBracketArray, "PostBracketArray", 2, $1, $3);}
	| '[' ']' Type
		{$$ = $3;} //$$ = $3;
	;

ArrayAccess:
	IDENTIFIER '[' Expr ']'
		{$$ = create_branch(prodR_ArrayAccess, "ArrayAccess", 2, $1, $3);}
	;


ArgList:
	Expr
		{}
	| ArgList ',' Expr
		{$$ = create_branch(prodR_ArgList,"ArgList",2, $1,$3);}
	;
FieldAccess:
	Primary '.' IDENTIFIER
		{$$ = create_branch(prodR_FieldAccess,"FieldAccess",2, $1,$3);}
	;

MethodCall:
	Name '(' ArgListOpt ')'
		{$$ = create_branch(prodR_MethodCall,"MethodCall_parens",2, $1,$3);}

	| Name '{' ArgListOpt '}'
		{$$ = create_branch(prodR_MethodCall,"MethodCall_curly",2, $1,$3);}

	| Primary '.' IDENTIFIER '(' ArgListOpt ')'
		{$$ = create_branch(prodR_MethodCallPrimary,"MethodCall_primary_parens",3, $1,$3,$5);}

	| Primary '.' IDENTIFIER '{' ArgListOpt '}'
		{$$ = create_branch(prodR_MethodCallPrimary,"MethodCall_primary_curly",3, $1,$3,$5);}
	;

PostFixExpr:
	Primary
		{}
	| Name
		{}
	;
UnaryExpr:
	 '-' UnaryExpr
		{$$ = create_branch(prodR_UnaryExpr, "UnaryExpr_Neg", 2, $1, $2);}
	| '!' UnaryExpr
		{$$ = create_branch(prodR_UnaryExpr, "UnaryExpr_Excl", 2, $1, $2);}
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
	| InstantiationExpr
		{}
	;
Assignment:
	LeftHandSide AssignOp Expr
		{$$ = create_branch(prodR_Assignment,"Assignment",3, $1,$2,$3);}
	| LeftHandSide AssignOp
		{$$ = create_branch(prodR_UnaryAssignment,"Assignment_Unary",2, $1,$2);}
	| Type VarDeclarator AssignOp Expr
		{$$ = create_branch(prodR_TypeAssignment,"Assignment_Type",4, $1,$2,$3,$4);}
	;
LeftHandSide:
	Name
		{}
	| FieldAccess
		{}
	| Array
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
