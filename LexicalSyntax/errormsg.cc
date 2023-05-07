#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <string>
#include <LexicalSyntax/errormsg.h>

ErrorMsg * ErrorMsg::instance = NULL;

ErrorMsg::ErrorMsg()
{
    fileName = "";
    lineNum = 1;
    tokPos = 0;
    //file = new std::ifstream(filename.c_str());
   //  if (!file){
   //      EM_error(0, "cannot open");
   //      exit(1);
   //  }
}

ErrorMsg::~ErrorMsg()
{
}

void ErrorMsg::Error(int pos, std::string message, ...)
{
    va_list ap;
    IntList lines = linePos;
    int num = lineNum;

    anyErrors=TRUE;
    while(lines && lines->i >= pos){
        lines = lines->rest;
        num--;
    }
    fprintf(stderr, "%s: ", fileName);
    if (lines) fprintf(stderr, "%d.%d: ", num, pos-lines->i);
    va_start(ap, message);
    vfprintf(stderr, message.c_str(), ap);
    va_end(ap);
    fprintf(stderr, "\n");
}

void ErrorMsg::Reset(std::string filename){
    anyErrors = FALSE;
    this->fileName = filename;
    this->lineNum  = 1;
    linePos   = intList(0, NULL);
//    yyin = fopen(filename.c_str(), "r");
//    if (!yyin){
//        EM_error(0, "cannot open");
//        exit(1);
//    }
}

void ErrorMsg::newline(void)
{
    lineNum ++;
    linePos = intList(tokPos, linePos);
}
