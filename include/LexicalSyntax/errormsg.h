#include <string>
#include "util.h"

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
    IntList linePos = NULL;
    bool anyErrors = FALSE;
private:
    static ErrorMsg *instance;
private:
    ErrorMsg();
    ~ErrorMsg();
    ErrorMsg(const ErrorMsg &);
    ErrorMsg &operator=(const ErrorMsg &);
private:
    class Deletor
    {
    public:
        Deletor();
        ~Deletor(){
            if(ErrorMsg::instance != NULL)
                delete ErrorMsg::instance;
        }
    };
    static Deletor deletor;
public:
    static ErrorMsg *getInstance(){
        if(instance == NULL){
            instance = new ErrorMsg();
        }
        return instance;
    }

    void Error(int, std::string, ...);
    void Reset(std::string filename);
    void newline(void);

    void set_pos(int pos){tokPos = pos;};
    int get_pos(){return tokPos;};
    bool isError(){return anyErrors;};
};


    // COMPILE_FLAGS "-Cm -B -L --c++ --nounistd")
