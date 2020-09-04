ANTLR4=java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH" org.antlr.v4.Tool

antlr:	MiniC.g4
		$(ANTLR4) -visitor MiniC.g4
		javac *.java

clean:	
		rm -f *.java *.class *.tokens *.interp