/*
* util.c - commonly used utility functions.
*/
#ifndef UTIL_H
#define UTIL_H
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef char *string;
typedef char bool;
typedef struct U_boolList_ *U_boolList;


void *checked_malloc(int size);
string String(char *a);

struct U_boolList_{
    bool head;
    U_boolList tail;
};

U_boolList U_BoolList(bool head, U_boolList tail);

#endif