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
}