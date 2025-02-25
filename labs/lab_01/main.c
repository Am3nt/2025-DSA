#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main(void) {
    int n=5;
    float *t=allocateMemoryForArray1(n);
    fillWithRandomNumbers(n,t,0,100);
    printArray(n,t,"ki.txt");
    printf("%f",minimum(t[0],t[n/2],t[n]));
    deallocateMemoryForArray(t);
    return 0;
}
