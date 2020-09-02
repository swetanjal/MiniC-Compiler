// Generated from MiniC.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MiniCParser}.
 */
public interface MiniCListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MiniCParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(MiniCParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(MiniCParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#decl}.
	 * @param ctx the parse tree
	 */
	void enterDecl(MiniCParser.DeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#decl}.
	 * @param ctx the parse tree
	 */
	void exitDecl(MiniCParser.DeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void enterVar_decl(MiniCParser.Var_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void exitVar_decl(MiniCParser.Var_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#method_decl}.
	 * @param ctx the parse tree
	 */
	void enterMethod_decl(MiniCParser.Method_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#method_decl}.
	 * @param ctx the parse tree
	 */
	void exitMethod_decl(MiniCParser.Method_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(MiniCParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(MiniCParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(MiniCParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(MiniCParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(MiniCParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(MiniCParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(MiniCParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(MiniCParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#method_call}.
	 * @param ctx the parse tree
	 */
	void enterMethod_call(MiniCParser.Method_callContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#method_call}.
	 * @param ctx the parse tree
	 */
	void exitMethod_call(MiniCParser.Method_callContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(MiniCParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(MiniCParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#identifier}.
	 * @param ctx the parse tree
	 */
	void enterIdentifier(MiniCParser.IdentifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#identifier}.
	 * @param ctx the parse tree
	 */
	void exitIdentifier(MiniCParser.IdentifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(MiniCParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(MiniCParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#bool_lit}.
	 * @param ctx the parse tree
	 */
	void enterBool_lit(MiniCParser.Bool_litContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#bool_lit}.
	 * @param ctx the parse tree
	 */
	void exitBool_lit(MiniCParser.Bool_litContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#arithmetic_op}.
	 * @param ctx the parse tree
	 */
	void enterArithmetic_op(MiniCParser.Arithmetic_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#arithmetic_op}.
	 * @param ctx the parse tree
	 */
	void exitArithmetic_op(MiniCParser.Arithmetic_opContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#relational_op}.
	 * @param ctx the parse tree
	 */
	void enterRelational_op(MiniCParser.Relational_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#relational_op}.
	 * @param ctx the parse tree
	 */
	void exitRelational_op(MiniCParser.Relational_opContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#conditional_op}.
	 * @param ctx the parse tree
	 */
	void enterConditional_op(MiniCParser.Conditional_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#conditional_op}.
	 * @param ctx the parse tree
	 */
	void exitConditional_op(MiniCParser.Conditional_opContext ctx);
	/**
	 * Enter a parse tree produced by {@link MiniCParser#equality_op}.
	 * @param ctx the parse tree
	 */
	void enterEquality_op(MiniCParser.Equality_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link MiniCParser#equality_op}.
	 * @param ctx the parse tree
	 */
	void exitEquality_op(MiniCParser.Equality_opContext ctx);
}