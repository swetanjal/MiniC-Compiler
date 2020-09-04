// Generated from MiniC.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MiniCParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MiniCVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MiniCParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(MiniCParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#decl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDecl(MiniCParser.DeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#var_decl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_decl(MiniCParser.Var_declContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#method_decl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMethod_decl(MiniCParser.Method_declContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(MiniCParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType(MiniCParser.TypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#statement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatement(MiniCParser.StatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#assignment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignment(MiniCParser.AssignmentContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#method_call}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMethod_call(MiniCParser.Method_callContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(MiniCParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr8}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr8(MiniCParser.Expr8Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr7}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr7(MiniCParser.Expr7Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr6}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr6(MiniCParser.Expr6Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr5}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr5(MiniCParser.Expr5Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr4}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr4(MiniCParser.Expr4Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr3}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr3(MiniCParser.Expr3Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr2}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr2(MiniCParser.Expr2Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr1}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr1(MiniCParser.Expr1Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#expr0}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr0(MiniCParser.Expr0Context ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#identifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIdentifier(MiniCParser.IdentifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(MiniCParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#bool_lit}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBool_lit(MiniCParser.Bool_litContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#arithmetic_op}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArithmetic_op(MiniCParser.Arithmetic_opContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#relational_op}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRelational_op(MiniCParser.Relational_opContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#conditional_op}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConditional_op(MiniCParser.Conditional_opContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniCParser#equality_op}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEquality_op(MiniCParser.Equality_opContext ctx);
}