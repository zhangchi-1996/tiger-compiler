/*
* util.c - commonly used utility functions.
*/
#ifndef UTIL_H
#define UTIL_H
#include <cassert>

#define TRUE 1
#define FALSE 0

// # typedef char bool;
typedef struct U_boolList_ *U_boolList;

void *checked_malloc(int size);

#endif