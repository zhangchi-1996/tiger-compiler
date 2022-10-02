#include "slp.h"
#include "util.h"

A_stm prog(void);

int maxargs(A_stm prog);

void interp(A_stm);

void interpStm();

void interpExp();

typedef struct table *Table_;
struct table{string id; int value, Table_ tail};
Table_ Table(string id, int value, struct table *tail);