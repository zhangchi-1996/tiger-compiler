#include "prog1.h"
#include "stdio.h"

A_stm prog(void) {
    return A_CompoundStm(A_AssignStm("a", A_OpExp(A_NumExp(5), A_puls, A_NumExp(3))),
                         A_CompoundStm(A_AssignStm("b", A_EseqExp(
                                               A_PrintStm(A_PairExpList(A_IdExp("a"),
                                                                        A_LastExpList(A_OpExp(A_IdExp("a"), A_minus,
                                                                                              A_NumExp(1))))),
                                               A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
                                       A_PrintStm(A_LastExpList(A_IdExp("b")))));
}

int nums = 0;

int maxargs(A_stm prog) {
    printf("in maxargs\n");
    if (prog->kind == A_assign_Stm) {
        printf("in assign\n");
        if(prog->u.assign.exp->kind == A_eseqExp){
            maxargs(prog->u.assign.exp->u.eseq.stm);
        }
    }

    if (prog->kind == A_printStm) {
        nums++;
        printf("in print\n");
        maxargs(prog->u.print.exps->u.last->u.eseq.stm);
    }

    if (prog->kind == A_compoundStm) {
        printf("in compound\n");
        maxargs(prog->u.compound.stm1);
        printf("printf stm2\n");
        maxargs(prog->u.compound.stm2);
    }

    return nums;
}

Table_ Table(string id, int value, struct table *tail){
    Table_ t = checked_malloc(sizeof(*t));
    t->id = id; t->value=value; t->tail =tail;
}