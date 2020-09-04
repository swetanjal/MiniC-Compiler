// Generated from MiniC.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniCLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, FALSE=9, 
		TRUE=10, NOT=11, NEGATE=12, VOID=13, INT=14, FILE=15, STRING=16, CHAR=17, 
		UINT=18, BOOL=19, THEN=20, OTHERWISE=21, FOR=22, WHILE=23, IF=24, ELSE=25, 
		BREAK=26, CONTINUE=27, RETURN=28, ADD=29, SUB=30, MUL=31, DIV=32, MOD=33, 
		LT=34, GT=35, LE=36, GE=37, AND=38, OR=39, EQ=40, NE=41, ASSIGN=42, PRINT=43, 
		PRINTLN=44, READ_INT=45, READ_CHAR=46, READ_BOOL=47, INT_LIT=48, FLOAT_LIT=49, 
		CHAR_LIT=50, ID=51, STRING_LIT=52, WS=53;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "FALSE", 
			"TRUE", "NOT", "NEGATE", "VOID", "INT", "FILE", "STRING", "CHAR", "UINT", 
			"BOOL", "THEN", "OTHERWISE", "FOR", "WHILE", "IF", "ELSE", "BREAK", "CONTINUE", 
			"RETURN", "ADD", "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", 
			"AND", "OR", "EQ", "NE", "ASSIGN", "PRINT", "PRINTLN", "READ_INT", "READ_CHAR", 
			"READ_BOOL", "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "ID", "STRING_LIT", 
			"WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'false'", 
			"'true'", "'!'", "'~'", "'void'", "'int'", "'FILE'", "'string'", "'char'", 
			"'uint'", "'bool'", "'?'", "':'", "'for'", "'while'", "'if'", "'else'", 
			"'break'", "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", 
			"'<'", "'>'", "'<='", "'>='", "'&&'", "'||'", "'=='", "'!='", "'='", 
			"'print'", "'println'", "'read_int'", "'read_char'", "'read_bool'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "FALSE", "TRUE", 
			"NOT", "NEGATE", "VOID", "INT", "FILE", "STRING", "CHAR", "UINT", "BOOL", 
			"THEN", "OTHERWISE", "FOR", "WHILE", "IF", "ELSE", "BREAK", "CONTINUE", 
			"RETURN", "ADD", "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", 
			"AND", "OR", "EQ", "NE", "ASSIGN", "PRINT", "PRINTLN", "READ_INT", "READ_CHAR", 
			"READ_BOOL", "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "ID", "STRING_LIT", 
			"WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public MiniCLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MiniC.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\67\u0161\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64"+
		"\t\64\4\65\t\65\4\66\t\66\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7"+
		"\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13"+
		"\3\f\3\f\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\20\3\20"+
		"\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\22\3\22"+
		"\3\22\3\23\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\26"+
		"\3\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31"+
		"\3\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34"+
		"\3\34\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\35\3\36"+
		"\3\36\3\37\3\37\3 \3 \3!\3!\3\"\3\"\3#\3#\3$\3$\3%\3%\3%\3&\3&\3&\3\'"+
		"\3\'\3\'\3(\3(\3(\3)\3)\3)\3*\3*\3*\3+\3+\3,\3,\3,\3,\3,\3,\3-\3-\3-\3"+
		"-\3-\3-\3-\3-\3.\3.\3.\3.\3.\3.\3.\3.\3.\3/\3/\3/\3/\3/\3/\3/\3/\3/\3"+
		"/\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\61\3\61\7\61\u012c"+
		"\n\61\f\61\16\61\u012f\13\61\3\62\3\62\7\62\u0133\n\62\f\62\16\62\u0136"+
		"\13\62\3\62\3\62\3\62\7\62\u013b\n\62\f\62\16\62\u013e\13\62\5\62\u0140"+
		"\n\62\3\63\3\63\3\63\3\63\3\63\3\63\3\63\5\63\u0149\n\63\3\64\3\64\7\64"+
		"\u014d\n\64\f\64\16\64\u0150\13\64\3\65\3\65\7\65\u0154\n\65\f\65\16\65"+
		"\u0157\13\65\3\65\3\65\3\66\6\66\u015c\n\66\r\66\16\66\u015d\3\66\3\66"+
		"\2\2\67\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17"+
		"\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\35"+
		"9\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\62c\63e\64g\65i\66"+
		"k\67\3\2\t\3\2\62;\n\2\"\"..\60\60\62;==C\\aac|\4\2ppvv\5\2C\\aac|\6\2"+
		"\62;C\\aac|\13\2\"\"..\60\60\62;==C\\^^aac|\5\2\13\f\17\17\"\"\2\u0168"+
		"\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2"+
		"\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2"+
		"\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2"+
		"\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2"+
		"\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3"+
		"\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2"+
		"\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2"+
		"U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3"+
		"\2\2\2\2c\3\2\2\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2\2\2k\3\2\2\2\3m\3\2\2"+
		"\2\5o\3\2\2\2\7q\3\2\2\2\ts\3\2\2\2\13u\3\2\2\2\rw\3\2\2\2\17y\3\2\2\2"+
		"\21{\3\2\2\2\23}\3\2\2\2\25\u0083\3\2\2\2\27\u0088\3\2\2\2\31\u008a\3"+
		"\2\2\2\33\u008c\3\2\2\2\35\u0091\3\2\2\2\37\u0095\3\2\2\2!\u009a\3\2\2"+
		"\2#\u00a1\3\2\2\2%\u00a6\3\2\2\2\'\u00ab\3\2\2\2)\u00b0\3\2\2\2+\u00b2"+
		"\3\2\2\2-\u00b4\3\2\2\2/\u00b8\3\2\2\2\61\u00be\3\2\2\2\63\u00c1\3\2\2"+
		"\2\65\u00c6\3\2\2\2\67\u00cc\3\2\2\29\u00d5\3\2\2\2;\u00dc\3\2\2\2=\u00de"+
		"\3\2\2\2?\u00e0\3\2\2\2A\u00e2\3\2\2\2C\u00e4\3\2\2\2E\u00e6\3\2\2\2G"+
		"\u00e8\3\2\2\2I\u00ea\3\2\2\2K\u00ed\3\2\2\2M\u00f0\3\2\2\2O\u00f3\3\2"+
		"\2\2Q\u00f6\3\2\2\2S\u00f9\3\2\2\2U\u00fc\3\2\2\2W\u00fe\3\2\2\2Y\u0104"+
		"\3\2\2\2[\u010c\3\2\2\2]\u0115\3\2\2\2_\u011f\3\2\2\2a\u0129\3\2\2\2c"+
		"\u0130\3\2\2\2e\u0148\3\2\2\2g\u014a\3\2\2\2i\u0151\3\2\2\2k\u015b\3\2"+
		"\2\2mn\7.\2\2n\4\3\2\2\2op\7=\2\2p\6\3\2\2\2qr\7*\2\2r\b\3\2\2\2st\7+"+
		"\2\2t\n\3\2\2\2uv\7}\2\2v\f\3\2\2\2wx\7\177\2\2x\16\3\2\2\2yz\7]\2\2z"+
		"\20\3\2\2\2{|\7_\2\2|\22\3\2\2\2}~\7h\2\2~\177\7c\2\2\177\u0080\7n\2\2"+
		"\u0080\u0081\7u\2\2\u0081\u0082\7g\2\2\u0082\24\3\2\2\2\u0083\u0084\7"+
		"v\2\2\u0084\u0085\7t\2\2\u0085\u0086\7w\2\2\u0086\u0087\7g\2\2\u0087\26"+
		"\3\2\2\2\u0088\u0089\7#\2\2\u0089\30\3\2\2\2\u008a\u008b\7\u0080\2\2\u008b"+
		"\32\3\2\2\2\u008c\u008d\7x\2\2\u008d\u008e\7q\2\2\u008e\u008f\7k\2\2\u008f"+
		"\u0090\7f\2\2\u0090\34\3\2\2\2\u0091\u0092\7k\2\2\u0092\u0093\7p\2\2\u0093"+
		"\u0094\7v\2\2\u0094\36\3\2\2\2\u0095\u0096\7H\2\2\u0096\u0097\7K\2\2\u0097"+
		"\u0098\7N\2\2\u0098\u0099\7G\2\2\u0099 \3\2\2\2\u009a\u009b\7u\2\2\u009b"+
		"\u009c\7v\2\2\u009c\u009d\7t\2\2\u009d\u009e\7k\2\2\u009e\u009f\7p\2\2"+
		"\u009f\u00a0\7i\2\2\u00a0\"\3\2\2\2\u00a1\u00a2\7e\2\2\u00a2\u00a3\7j"+
		"\2\2\u00a3\u00a4\7c\2\2\u00a4\u00a5\7t\2\2\u00a5$\3\2\2\2\u00a6\u00a7"+
		"\7w\2\2\u00a7\u00a8\7k\2\2\u00a8\u00a9\7p\2\2\u00a9\u00aa\7v\2\2\u00aa"+
		"&\3\2\2\2\u00ab\u00ac\7d\2\2\u00ac\u00ad\7q\2\2\u00ad\u00ae\7q\2\2\u00ae"+
		"\u00af\7n\2\2\u00af(\3\2\2\2\u00b0\u00b1\7A\2\2\u00b1*\3\2\2\2\u00b2\u00b3"+
		"\7<\2\2\u00b3,\3\2\2\2\u00b4\u00b5\7h\2\2\u00b5\u00b6\7q\2\2\u00b6\u00b7"+
		"\7t\2\2\u00b7.\3\2\2\2\u00b8\u00b9\7y\2\2\u00b9\u00ba\7j\2\2\u00ba\u00bb"+
		"\7k\2\2\u00bb\u00bc\7n\2\2\u00bc\u00bd\7g\2\2\u00bd\60\3\2\2\2\u00be\u00bf"+
		"\7k\2\2\u00bf\u00c0\7h\2\2\u00c0\62\3\2\2\2\u00c1\u00c2\7g\2\2\u00c2\u00c3"+
		"\7n\2\2\u00c3\u00c4\7u\2\2\u00c4\u00c5\7g\2\2\u00c5\64\3\2\2\2\u00c6\u00c7"+
		"\7d\2\2\u00c7\u00c8\7t\2\2\u00c8\u00c9\7g\2\2\u00c9\u00ca\7c\2\2\u00ca"+
		"\u00cb\7m\2\2\u00cb\66\3\2\2\2\u00cc\u00cd\7e\2\2\u00cd\u00ce\7q\2\2\u00ce"+
		"\u00cf\7p\2\2\u00cf\u00d0\7v\2\2\u00d0\u00d1\7k\2\2\u00d1\u00d2\7p\2\2"+
		"\u00d2\u00d3\7w\2\2\u00d3\u00d4\7g\2\2\u00d48\3\2\2\2\u00d5\u00d6\7t\2"+
		"\2\u00d6\u00d7\7g\2\2\u00d7\u00d8\7v\2\2\u00d8\u00d9\7w\2\2\u00d9\u00da"+
		"\7t\2\2\u00da\u00db\7p\2\2\u00db:\3\2\2\2\u00dc\u00dd\7-\2\2\u00dd<\3"+
		"\2\2\2\u00de\u00df\7/\2\2\u00df>\3\2\2\2\u00e0\u00e1\7,\2\2\u00e1@\3\2"+
		"\2\2\u00e2\u00e3\7\61\2\2\u00e3B\3\2\2\2\u00e4\u00e5\7\'\2\2\u00e5D\3"+
		"\2\2\2\u00e6\u00e7\7>\2\2\u00e7F\3\2\2\2\u00e8\u00e9\7@\2\2\u00e9H\3\2"+
		"\2\2\u00ea\u00eb\7>\2\2\u00eb\u00ec\7?\2\2\u00ecJ\3\2\2\2\u00ed\u00ee"+
		"\7@\2\2\u00ee\u00ef\7?\2\2\u00efL\3\2\2\2\u00f0\u00f1\7(\2\2\u00f1\u00f2"+
		"\7(\2\2\u00f2N\3\2\2\2\u00f3\u00f4\7~\2\2\u00f4\u00f5\7~\2\2\u00f5P\3"+
		"\2\2\2\u00f6\u00f7\7?\2\2\u00f7\u00f8\7?\2\2\u00f8R\3\2\2\2\u00f9\u00fa"+
		"\7#\2\2\u00fa\u00fb\7?\2\2\u00fbT\3\2\2\2\u00fc\u00fd\7?\2\2\u00fdV\3"+
		"\2\2\2\u00fe\u00ff\7r\2\2\u00ff\u0100\7t\2\2\u0100\u0101\7k\2\2\u0101"+
		"\u0102\7p\2\2\u0102\u0103\7v\2\2\u0103X\3\2\2\2\u0104\u0105\7r\2\2\u0105"+
		"\u0106\7t\2\2\u0106\u0107\7k\2\2\u0107\u0108\7p\2\2\u0108\u0109\7v\2\2"+
		"\u0109\u010a\7n\2\2\u010a\u010b\7p\2\2\u010bZ\3\2\2\2\u010c\u010d\7t\2"+
		"\2\u010d\u010e\7g\2\2\u010e\u010f\7c\2\2\u010f\u0110\7f\2\2\u0110\u0111"+
		"\7a\2\2\u0111\u0112\7k\2\2\u0112\u0113\7p\2\2\u0113\u0114\7v\2\2\u0114"+
		"\\\3\2\2\2\u0115\u0116\7t\2\2\u0116\u0117\7g\2\2\u0117\u0118\7c\2\2\u0118"+
		"\u0119\7f\2\2\u0119\u011a\7a\2\2\u011a\u011b\7e\2\2\u011b\u011c\7j\2\2"+
		"\u011c\u011d\7c\2\2\u011d\u011e\7t\2\2\u011e^\3\2\2\2\u011f\u0120\7t\2"+
		"\2\u0120\u0121\7g\2\2\u0121\u0122\7c\2\2\u0122\u0123\7f\2\2\u0123\u0124"+
		"\7a\2\2\u0124\u0125\7d\2\2\u0125\u0126\7q\2\2\u0126\u0127\7q\2\2\u0127"+
		"\u0128\7n\2\2\u0128`\3\2\2\2\u0129\u012d\t\2\2\2\u012a\u012c\t\2\2\2\u012b"+
		"\u012a\3\2\2\2\u012c\u012f\3\2\2\2\u012d\u012b\3\2\2\2\u012d\u012e\3\2"+
		"\2\2\u012eb\3\2\2\2\u012f\u012d\3\2\2\2\u0130\u0134\t\2\2\2\u0131\u0133"+
		"\t\2\2\2\u0132\u0131\3\2\2\2\u0133\u0136\3\2\2\2\u0134\u0132\3\2\2\2\u0134"+
		"\u0135\3\2\2\2\u0135\u013f\3\2\2\2\u0136\u0134\3\2\2\2\u0137\u0138\13"+
		"\2\2\2\u0138\u013c\t\2\2\2\u0139\u013b\t\2\2\2\u013a\u0139\3\2\2\2\u013b"+
		"\u013e\3\2\2\2\u013c\u013a\3\2\2\2\u013c\u013d\3\2\2\2\u013d\u0140\3\2"+
		"\2\2\u013e\u013c\3\2\2\2\u013f\u0137\3\2\2\2\u013f\u0140\3\2\2\2\u0140"+
		"d\3\2\2\2\u0141\u0142\7)\2\2\u0142\u0143\t\3\2\2\u0143\u0149\7)\2\2\u0144"+
		"\u0145\7)\2\2\u0145\u0146\7^\2\2\u0146\u0147\t\4\2\2\u0147\u0149\7)\2"+
		"\2\u0148\u0141\3\2\2\2\u0148\u0144\3\2\2\2\u0149f\3\2\2\2\u014a\u014e"+
		"\t\5\2\2\u014b\u014d\t\6\2\2\u014c\u014b\3\2\2\2\u014d\u0150\3\2\2\2\u014e"+
		"\u014c\3\2\2\2\u014e\u014f\3\2\2\2\u014fh\3\2\2\2\u0150\u014e\3\2\2\2"+
		"\u0151\u0155\7$\2\2\u0152\u0154\t\7\2\2\u0153\u0152\3\2\2\2\u0154\u0157"+
		"\3\2\2\2\u0155\u0153\3\2\2\2\u0155\u0156\3\2\2\2\u0156\u0158\3\2\2\2\u0157"+
		"\u0155\3\2\2\2\u0158\u0159\7$\2\2\u0159j\3\2\2\2\u015a\u015c\t\b\2\2\u015b"+
		"\u015a\3\2\2\2\u015c\u015d\3\2\2\2\u015d\u015b\3\2\2\2\u015d\u015e\3\2"+
		"\2\2\u015e\u015f\3\2\2\2\u015f\u0160\b\66\2\2\u0160l\3\2\2\2\13\2\u012d"+
		"\u0134\u013c\u013f\u0148\u014e\u0155\u015d\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}