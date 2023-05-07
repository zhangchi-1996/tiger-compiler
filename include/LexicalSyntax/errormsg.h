#include <string>
#include "util.h"
#include <iostream>

typedef struct intList
{
    int i;
    struct intList *rest;
} *IntList;

static IntList intList(int i, IntList rest)
{
    IntList l = static_cast<IntList>(checked_malloc(sizeof *l));
    l->i=i;
    l->rest=rest;
    return l;
}

class ErrorMsg
{
private:
    std::string fileName;
    int lineNum;
    int tokPos;
    IntList linePos = nullptr;
    bool anyErrors = FALSE;
private:
    static ErrorMsg *instance;
private:
    ErrorMsg();
    ~ErrorMsg() = default;
    ErrorMsg(const ErrorMsg &);
    ErrorMsg &operator=(const ErrorMsg &);
private:
    class Deleter
    {
    public:
        Deleter() = default;
        ~Deleter(){
            delete ErrorMsg::instance;
        }
    };
    static Deleter deleter;
public:
    static ErrorMsg *getInstance(){
        if(instance == nullptr){
            instance = new ErrorMsg();
        }
        return instance;
    }

    void Error(int, const std::string&, ...);
    void Reset(std::string filename);
    void newline();

    void set_pos(int pos){tokPos = pos;};
    [[nodiscard]] int get_pos() const{return tokPos;};
    [[nodiscard]] bool isError() const{return anyErrors;};
};
