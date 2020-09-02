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
		TRUE=10, NOT=11, NEGATE=12, VOID=13, INT=14, CHAR=15, UINT=16, BOOL=17, 
		THEN=18, OTHERWISE=19, FOR=20, WHILE=21, IF=22, ELSE=23, BREAK=24, CONTINUE=25, 
		RETURN=26, ADD=27, SUB=28, MUL=29, DIV=30, MOD=31, LT=32, GT=33, LE=34, 
		GE=35, AND=36, OR=37, EQ=38, NE=39, ASSIGN=40, PRINT=41, READ_INT=42, 
		READ_CHAR=43, READ_BOOL=44, INT_LIT=45, FLOAT_LIT=46, CHAR_LIT=47, ID=48, 
		STRING_LIT=49, WS=50;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "FALSE", 
			"TRUE", "NOT", "NEGATE", "VOID", "INT", "CHAR", "UINT", "BOOL", "THEN", 
			"OTHERWISE", "FOR", "WHILE", "IF", "ELSE", "BREAK", "CONTINUE", "RETURN", 
			"ADD", "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "AND", "OR", 
			"EQ", "NE", "ASSIGN", "PRINT", "READ_INT", "READ_CHAR", "READ_BOOL", 
			"INT_LIT", "FLOAT_LIT", "CHAR_LIT", "ID", "STRING_LIT", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'false'", 
			"'true'", "'!'", "'~'", "'void'", "'int'", "'char'", "'uint'", "'bool'", 
			"'?'", "':'", "'for'", "'while'", "'if'", "'else'", "'break'", "'continue'", 
			"'return'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'<='", 
			"'>='", "'&&'", "'||'", "'=='", "'!='", "'='", "'print'", "'read_int'", 
			"'read_char'", "'read_bool'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "FALSE", "TRUE", 
			"NOT", "NEGATE", "VOID", "INT", "CHAR", "UINT", "BOOL", "THEN", "OTHERWISE", 
			"FOR", "WHILE", "IF", "ELSE", "BREAK", "CONTINUE", "RETURN", "ADD", "SUB", 
			"MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "AND", "OR", "EQ", "NE", 
			"ASSIGN", "PRINT", "READ_INT", "READ_CHAR", "READ_BOOL", "INT_LIT", "FLOAT_LIT", 
			"CHAR_LIT", "ID", "STRING_LIT", "WS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\64\u0142\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\3\2"+
		"\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3"+
		"\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\16"+
		"\3\16\3\16\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\21\3\21\3\21"+
		"\3\21\3\21\3\22\3\22\3\22\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\25"+
		"\3\25\3\26\3\26\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\30\3\30\3\30\3\30"+
		"\3\30\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\32\3\32"+
		"\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\35\3\35\3\36"+
		"\3\36\3\37\3\37\3 \3 \3!\3!\3\"\3\"\3#\3#\3#\3$\3$\3$\3%\3%\3%\3&\3&\3"+
		"&\3\'\3\'\3\'\3(\3(\3(\3)\3)\3*\3*\3*\3*\3*\3*\3+\3+\3+\3+\3+\3+\3+\3"+
		"+\3+\3,\3,\3,\3,\3,\3,\3,\3,\3,\3,\3-\3-\3-\3-\3-\3-\3-\3-\3-\3-\3.\3"+
		".\7.\u0112\n.\f.\16.\u0115\13.\3/\3/\7/\u0119\n/\f/\16/\u011c\13/\3/\3"+
		"/\3/\7/\u0121\n/\f/\16/\u0124\13/\5/\u0126\n/\3\60\3\60\3\60\3\60\3\61"+
		"\3\61\7\61\u012e\n\61\f\61\16\61\u0131\13\61\3\62\3\62\7\62\u0135\n\62"+
		"\f\62\16\62\u0138\13\62\3\62\3\62\3\63\6\63\u013d\n\63\r\63\16\63\u013e"+
		"\3\63\3\63\2\2\64\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31"+
		"\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65"+
		"\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\62c\63e\64"+
		"\3\2\7\3\2\62;\n\2\"\"..\60\60\62;==C\\aac|\5\2C\\aac|\6\2\62;C\\aac|"+
		"\5\2\13\f\17\17\"\"\2\u0148\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3"+
		"\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2"+
		"\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37"+
		"\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3"+
		"\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2"+
		"\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C"+
		"\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2"+
		"\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2"+
		"\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\3g\3\2\2\2\5i"+
		"\3\2\2\2\7k\3\2\2\2\tm\3\2\2\2\13o\3\2\2\2\rq\3\2\2\2\17s\3\2\2\2\21u"+
		"\3\2\2\2\23w\3\2\2\2\25}\3\2\2\2\27\u0082\3\2\2\2\31\u0084\3\2\2\2\33"+
		"\u0086\3\2\2\2\35\u008b\3\2\2\2\37\u008f\3\2\2\2!\u0094\3\2\2\2#\u0099"+
		"\3\2\2\2%\u009e\3\2\2\2\'\u00a0\3\2\2\2)\u00a2\3\2\2\2+\u00a6\3\2\2\2"+
		"-\u00ac\3\2\2\2/\u00af\3\2\2\2\61\u00b4\3\2\2\2\63\u00ba\3\2\2\2\65\u00c3"+
		"\3\2\2\2\67\u00ca\3\2\2\29\u00cc\3\2\2\2;\u00ce\3\2\2\2=\u00d0\3\2\2\2"+
		"?\u00d2\3\2\2\2A\u00d4\3\2\2\2C\u00d6\3\2\2\2E\u00d8\3\2\2\2G\u00db\3"+
		"\2\2\2I\u00de\3\2\2\2K\u00e1\3\2\2\2M\u00e4\3\2\2\2O\u00e7\3\2\2\2Q\u00ea"+
		"\3\2\2\2S\u00ec\3\2\2\2U\u00f2\3\2\2\2W\u00fb\3\2\2\2Y\u0105\3\2\2\2["+
		"\u010f\3\2\2\2]\u0116\3\2\2\2_\u0127\3\2\2\2a\u012b\3\2\2\2c\u0132\3\2"+
		"\2\2e\u013c\3\2\2\2gh\7.\2\2h\4\3\2\2\2ij\7=\2\2j\6\3\2\2\2kl\7*\2\2l"+
		"\b\3\2\2\2mn\7+\2\2n\n\3\2\2\2op\7}\2\2p\f\3\2\2\2qr\7\177\2\2r\16\3\2"+
		"\2\2st\7]\2\2t\20\3\2\2\2uv\7_\2\2v\22\3\2\2\2wx\7h\2\2xy\7c\2\2yz\7n"+
		"\2\2z{\7u\2\2{|\7g\2\2|\24\3\2\2\2}~\7v\2\2~\177\7t\2\2\177\u0080\7w\2"+
		"\2\u0080\u0081\7g\2\2\u0081\26\3\2\2\2\u0082\u0083\7#\2\2\u0083\30\3\2"+
		"\2\2\u0084\u0085\7\u0080\2\2\u0085\32\3\2\2\2\u0086\u0087\7x\2\2\u0087"+
		"\u0088\7q\2\2\u0088\u0089\7k\2\2\u0089\u008a\7f\2\2\u008a\34\3\2\2\2\u008b"+
		"\u008c\7k\2\2\u008c\u008d\7p\2\2\u008d\u008e\7v\2\2\u008e\36\3\2\2\2\u008f"+
		"\u0090\7e\2\2\u0090\u0091\7j\2\2\u0091\u0092\7c\2\2\u0092\u0093\7t\2\2"+
		"\u0093 \3\2\2\2\u0094\u0095\7w\2\2\u0095\u0096\7k\2\2\u0096\u0097\7p\2"+
		"\2\u0097\u0098\7v\2\2\u0098\"\3\2\2\2\u0099\u009a\7d\2\2\u009a\u009b\7"+
		"q\2\2\u009b\u009c\7q\2\2\u009c\u009d\7n\2\2\u009d$\3\2\2\2\u009e\u009f"+
		"\7A\2\2\u009f&\3\2\2\2\u00a0\u00a1\7<\2\2\u00a1(\3\2\2\2\u00a2\u00a3\7"+
		"h\2\2\u00a3\u00a4\7q\2\2\u00a4\u00a5\7t\2\2\u00a5*\3\2\2\2\u00a6\u00a7"+
		"\7y\2\2\u00a7\u00a8\7j\2\2\u00a8\u00a9\7k\2\2\u00a9\u00aa\7n\2\2\u00aa"+
		"\u00ab\7g\2\2\u00ab,\3\2\2\2\u00ac\u00ad\7k\2\2\u00ad\u00ae\7h\2\2\u00ae"+
		".\3\2\2\2\u00af\u00b0\7g\2\2\u00b0\u00b1\7n\2\2\u00b1\u00b2\7u\2\2\u00b2"+
		"\u00b3\7g\2\2\u00b3\60\3\2\2\2\u00b4\u00b5\7d\2\2\u00b5\u00b6\7t\2\2\u00b6"+
		"\u00b7\7g\2\2\u00b7\u00b8\7c\2\2\u00b8\u00b9\7m\2\2\u00b9\62\3\2\2\2\u00ba"+
		"\u00bb\7e\2\2\u00bb\u00bc\7q\2\2\u00bc\u00bd\7p\2\2\u00bd\u00be\7v\2\2"+
		"\u00be\u00bf\7k\2\2\u00bf\u00c0\7p\2\2\u00c0\u00c1\7w\2\2\u00c1\u00c2"+
		"\7g\2\2\u00c2\64\3\2\2\2\u00c3\u00c4\7t\2\2\u00c4\u00c5\7g\2\2\u00c5\u00c6"+
		"\7v\2\2\u00c6\u00c7\7w\2\2\u00c7\u00c8\7t\2\2\u00c8\u00c9\7p\2\2\u00c9"+
		"\66\3\2\2\2\u00ca\u00cb\7-\2\2\u00cb8\3\2\2\2\u00cc\u00cd\7/\2\2\u00cd"+
		":\3\2\2\2\u00ce\u00cf\7,\2\2\u00cf<\3\2\2\2\u00d0\u00d1\7\61\2\2\u00d1"+
		">\3\2\2\2\u00d2\u00d3\7\'\2\2\u00d3@\3\2\2\2\u00d4\u00d5\7>\2\2\u00d5"+
		"B\3\2\2\2\u00d6\u00d7\7@\2\2\u00d7D\3\2\2\2\u00d8\u00d9\7>\2\2\u00d9\u00da"+
		"\7?\2\2\u00daF\3\2\2\2\u00db\u00dc\7@\2\2\u00dc\u00dd\7?\2\2\u00ddH\3"+
		"\2\2\2\u00de\u00df\7(\2\2\u00df\u00e0\7(\2\2\u00e0J\3\2\2\2\u00e1\u00e2"+
		"\7~\2\2\u00e2\u00e3\7~\2\2\u00e3L\3\2\2\2\u00e4\u00e5\7?\2\2\u00e5\u00e6"+
		"\7?\2\2\u00e6N\3\2\2\2\u00e7\u00e8\7#\2\2\u00e8\u00e9\7?\2\2\u00e9P\3"+
		"\2\2\2\u00ea\u00eb\7?\2\2\u00ebR\3\2\2\2\u00ec\u00ed\7r\2\2\u00ed\u00ee"+
		"\7t\2\2\u00ee\u00ef\7k\2\2\u00ef\u00f0\7p\2\2\u00f0\u00f1\7v\2\2\u00f1"+
		"T\3\2\2\2\u00f2\u00f3\7t\2\2\u00f3\u00f4\7g\2\2\u00f4\u00f5\7c\2\2\u00f5"+
		"\u00f6\7f\2\2\u00f6\u00f7\7a\2\2\u00f7\u00f8\7k\2\2\u00f8\u00f9\7p\2\2"+
		"\u00f9\u00fa\7v\2\2\u00faV\3\2\2\2\u00fb\u00fc\7t\2\2\u00fc\u00fd\7g\2"+
		"\2\u00fd\u00fe\7c\2\2\u00fe\u00ff\7f\2\2\u00ff\u0100\7a\2\2\u0100\u0101"+
		"\7e\2\2\u0101\u0102\7j\2\2\u0102\u0103\7c\2\2\u0103\u0104\7t\2\2\u0104"+
		"X\3\2\2\2\u0105\u0106\7t\2\2\u0106\u0107\7g\2\2\u0107\u0108\7c\2\2\u0108"+
		"\u0109\7f\2\2\u0109\u010a\7a\2\2\u010a\u010b\7d\2\2\u010b\u010c\7q\2\2"+
		"\u010c\u010d\7q\2\2\u010d\u010e\7n\2\2\u010eZ\3\2\2\2\u010f\u0113\t\2"+
		"\2\2\u0110\u0112\t\2\2\2\u0111\u0110\3\2\2\2\u0112\u0115\3\2\2\2\u0113"+
		"\u0111\3\2\2\2\u0113\u0114\3\2\2\2\u0114\\\3\2\2\2\u0115\u0113\3\2\2\2"+
		"\u0116\u011a\t\2\2\2\u0117\u0119\t\2\2\2\u0118\u0117\3\2\2\2\u0119\u011c"+
		"\3\2\2\2\u011a\u0118\3\2\2\2\u011a\u011b\3\2\2\2\u011b\u0125\3\2\2\2\u011c"+
		"\u011a\3\2\2\2\u011d\u011e\13\2\2\2\u011e\u0122\t\2\2\2\u011f\u0121\t"+
		"\2\2\2\u0120\u011f\3\2\2\2\u0121\u0124\3\2\2\2\u0122\u0120\3\2\2\2\u0122"+
		"\u0123\3\2\2\2\u0123\u0126\3\2\2\2\u0124\u0122\3\2\2\2\u0125\u011d\3\2"+
		"\2\2\u0125\u0126\3\2\2\2\u0126^\3\2\2\2\u0127\u0128\7)\2\2\u0128\u0129"+
		"\t\3\2\2\u0129\u012a\7)\2\2\u012a`\3\2\2\2\u012b\u012f\t\4\2\2\u012c\u012e"+
		"\t\5\2\2\u012d\u012c\3\2\2\2\u012e\u0131\3\2\2\2\u012f\u012d\3\2\2\2\u012f"+
		"\u0130\3\2\2\2\u0130b\3\2\2\2\u0131\u012f\3\2\2\2\u0132\u0136\7$\2\2\u0133"+
		"\u0135\t\3\2\2\u0134\u0133\3\2\2\2\u0135\u0138\3\2\2\2\u0136\u0134\3\2"+
		"\2\2\u0136\u0137\3\2\2\2\u0137\u0139\3\2\2\2\u0138\u0136\3\2\2\2\u0139"+
		"\u013a\7$\2\2\u013ad\3\2\2\2\u013b\u013d\t\6\2\2\u013c\u013b\3\2\2\2\u013d"+
		"\u013e\3\2\2\2\u013e\u013c\3\2\2\2\u013e\u013f\3\2\2\2\u013f\u0140\3\2"+
		"\2\2\u0140\u0141\b\63\2\2\u0141f\3\2\2\2\n\2\u0113\u011a\u0122\u0125\u012f"+
		"\u0136\u013e\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}