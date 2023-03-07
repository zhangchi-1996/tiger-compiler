#include <stdio.h>
#include "../include/util.h"
//#include "include/util.h"
//#include "include/LexicalSyntax/errormsg.h"
//#include "include/LexicalSyntax/tokens.h"
#include "../include/LexicalSyntax/errormsg.h"
#include "../include/LexicalSyntax/tokens.h"
#include <unistd.h>
#include <stdlib.h>


YYSTYPE yylval;
int yylex(void);

string toknames[] = {
"ID", "STRING", "INT", "COMMA", "COLON", "SEMICOLON", "LPAREN",
"RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS",
"MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT", "GE",
"AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR",
"TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
"VAR", "TYPE"
};

string tokename(tok){
    return tok < 257 || tok > 299 ? "BAD_TOKEN" : toknames[tok-257];
}

int main(int argc, char **argv){
    string fname;
    int tok;
    if (argc !=2 ){
        fprintf(stderr, "usage: a.out filename\n");
        exit(1);
    }
    fname = argv[1];

    EM_reset(fname);
    for(;;){
        tok = yylex();
        if (tok==0) break;
        switch (tok)
        {
        case ID: case STRING:
            printf("%10s %4d %s\n", tokename(tok), EM_tokPos, yylval.sval);
            break;

        case INT:
            printf("%10s %4d %d\n", tokename(tok), EM_tokPos, yylval.ival);
            break;

        default:
            printf("%10s %4d\n", tokename(tok), EM_tokPos);
            break;
        }
    }
    return 0;
}