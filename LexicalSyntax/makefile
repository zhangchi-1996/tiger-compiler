INC = ../include/LexicalSyntax/
UTIL_INC = ../include/
UTIL_LIB_INC = ../chap1/
lextest: driver.o lex.yy.o errormsg.o util.o
		cc -g -o lextest driver.o lex.yy.o errormsg.o util.o

driver.o: driver.c $(INC)tokens.h $(INC)errormsg.h $(UTIL_INC)util.h
		cc -g -c driver.c

errormsg.o: errormsg.c $(INC)errormsg.h $(UTIL_INC)util.h
		cc -g -c errormsg.c

lex.yy.o: lex.yy.c $(INC)tokens.h $(INC)errormsg.h $(UTIL_INC)util.h
		cc -g -c lex.yy.c

lex.yy.c: tiger.lex
		lex tiger.lex

util.o: $(UTIL_LIB_INC)util.c $(UTIL_INC)util.h
		cc -g -c $(UTIL_LIB_INC)util.c
	
clean: 
		rm -f lextest util.o driver.o lex.yy.o lex.yy.c errormsg.o lex.yy.c