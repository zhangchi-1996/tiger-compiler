#include <cstdio>
#include <cstdarg>

#include <string>
#include <utility>
#include <LexicalSyntax/errormsg.h>

ErrorMsg * ErrorMsg::instance = nullptr;
ErrorMsg::Deleter ErrorMsg::deleter;
ErrorMsg::ErrorMsg()
{
    fileName = "";
    lineNum = 1;
    tokPos = 0;
}

void ErrorMsg::Error(int pos, const std::string& message, ...)
{
    va_list ap;
    IntList lines = linePos;
    int num = lineNum;

    anyErrors=TRUE;
    while(lines && lines->i >= pos){
        lines = lines->rest;
        num--;
    }
    fprintf(stderr, "%s: ", fileName.c_str());
    if (lines) fprintf(stderr, "%d.%d: ", num, pos-lines->i);
    va_start(ap, message);
    vfprintf(stderr, message.c_str(), ap);
    va_end(ap);
    fprintf(stderr, "\n");
}

void ErrorMsg::Reset(std::string filename){
    anyErrors = FALSE;
    this->fileName = std::move(filename);
    this->lineNum  = 1;
    linePos   = intList(0, nullptr);
}

void ErrorMsg::newline()
{
    lineNum ++;
    linePos = intList(tokPos, linePos);
}
