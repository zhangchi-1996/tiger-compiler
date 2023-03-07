#include "prog1.h"
#include <stdio.h>

int main(void){

    int a = maxargs(prog());
    printf("hello complier, args is %d\n",a);
    //printf("%d\n",a);

    return 0;
}