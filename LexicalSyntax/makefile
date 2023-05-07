INC = ../include/LexicalSyntax/
UTIL_INC = ../include/
UTIL_LIB_INC = ../support/
lextest: driver.o lex.yy.o errormsg.o util.o
		cc -g -o lextest driver.o lex.yy.o errormsg.o util.o

driver.o: driver.cc $(INC)tokens.h $(INC)errormsg.h $(UTIL_INC)util.h
		cc -g -c driver.cc

errormsg.o: errormsg.c $(INC)errormsg.h $(UTIL_INC)util.h
		cc -g -c errormsg.cc

lex.yy.o: lex.yy.c $(INC)tokens.h $(INC)errormsg.h $(UTIL_INC)util.h
		cc -g -c lex.yy.c

lex.yy.c: tiger.lex
		flex tiger.lex

util.o: $(UTIL_LIB_INC)util.cc $(UTIL_INC)util.h
		cc -g -c $(UTIL_LIB_INC)util.cc
	
clean: 
		rm -f lextest util.o driver.o lex.yy.o lex.yy.c errormsg.o lex.yy.c