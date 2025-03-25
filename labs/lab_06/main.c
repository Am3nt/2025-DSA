#include <stdio.h>
#include "Palidrom/stack.h"
#include <string.h>

int main(void) {
    char* stack;
    createStack(10,&stack);
    char szo[]="asztal";
    int x;
    x=strlen(szo);
    int s[x];
    printf("%i\n",x);
    createStack(x,&stack);
    for (int i=0;i<x;i++) {
        push(&stack,szo[i]);
        s[i]=szo[i];
    }
    if (isPalindrome(stack,s,x)==true) {
        printf("Palindrome\n");
    }
    else {
        printf("Not a palindrome\n");
    }
    return 0;
}
