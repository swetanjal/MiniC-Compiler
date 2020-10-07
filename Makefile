ANTLR4=java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH" org.antlr.v4.Tool

antlr:	MiniC.g4
		$(ANTLR4) -Dlanguage=Cpp -no-listener -visitor MiniC.g4
		g++ -g main.cpp -o MiniC -I/usr/local/include/antlr4-runtime -lantlr4-runtime

clean:	
		rm -f MiniCLexer.h MiniCParser.h MiniC *.tokens *.interp MiniCBaseVisitor.cpp \
		rm -f MiniCBaseVisitor.h MiniCParser.cpp MiniCLexer.cpp MiniCBaseVisitor.cpp  \ 
		rm -f MiniCVisitor.cpp  MiniCVisitor.h