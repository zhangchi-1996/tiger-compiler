#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include <LexicalSyntax/errormsg.h>
#include <LexicalSyntax/tokens.h>

YYSTYPE yylval;
int yylex();
extern FILE *yyin;

std::string toknames[] = {
"ID", "STRING", "INT", "COMMA", "COLON", "SEMICOLON", "LPAREN",
"RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT", "PLUS",
"MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT", "GE",
"AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR",
"TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
"VAR", "TYPE"
};

std::string tokename(int tok){
    if (tok < 257 || tok > 299)
    {
        return "BAD_TOKEN";
    }
    else
    {
        return toknames[tok-257];
    }
}

int main(int argc, char **argv){
    if (argc !=2 ){
        fprintf(stderr, "usage: a.out filename\n");
        exit(1);
    }

    int tok;
    std::string fname = argv[1];

    yyin = fopen(fname.c_str(), "r");
    if (!yyin){
        ErrorMsg::getInstance()->Error(0, "cannot open");
        exit(1);
    }

    for(;;){
        tok = yylex();  // start flex
        if (tok==0) break;
        switch (tok)
        {
        case ID: case STRING:
            std::cout << tokename(tok) << " " << ErrorMsg::getInstance()->get_pos() << " " << yylval.sval << std::endl;
            break;

        case INT:
            std::cout << tokename(tok) << " " << ErrorMsg::getInstance()->get_pos() << " " << yylval.ival << std::endl;
            break;

        default:
            std::cout << tokename(tok) << " " << ErrorMsg::getInstance()->get_pos() << std::endl;
            break;
        }
    }
    return 0;
}