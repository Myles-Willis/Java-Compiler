#ifndef PRODRULES_H
#define PRODRULES_H

typedef enum {

	TOKEN = 1000,
	prodR_ClassDecl,
	prodR_ClassBodyDecls,
	prodR_FieldDecl,
	prodR_QualifiedName,
	prodR_VarDecls,
	prodR_MultiVarDecls,
	prodR_MethodDecl,
	prodR_MethodHeader,
	prodR_MethodDeclarator,
	prodR_FormalParmList,
	prodR_FormalParm,
	prodR_ConstructorDecl,
	prodR_ConstructorDeclarator,
	prodR_BlockStmts,
	prodR_LocalVarDecl,
	prodR_IfThenStmt,
	prodR_IfThenElseStmt,
	prodR_IfThenElseIfStmt,
	prodR_ElseIfSequence,
	prodR_WhileStmt,
	prodR_ForStmt,
	prodR_StmtExprList,
	prodR_InstantiationExpr,
	prodR_ArgList,
	prodR_FieldAccess,
	prodR_MethodCall,
	prodR_UnaryExpr,
	prodR_MulExpr,
	prodR_AddExpr,
	prodR_RelExpr,
	prodR_EqExpr,
	prodR_CondAndExpr,
	prodR_CondOrExpr,
	prodR_Assignment,
	prodR_TypeAssignment,

} prodrule;

#endif