#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntStack/stack.h"

int main(void) {
    int n=5;
    Stack_t t;
    createStack(n,&t);
    push(&t,5);
    printf("%i",peek(t));
    char s[3];
    scanf("%c",&s);
    if (!(strcmp(s,"+")==1 || strcmp(s,"-")==1 || strcmp(s,"*")==1 || strcmp(s,"/")==1)) {
        push(&t,atoi(s));
        scanf("%s",s);
    }
    int a;
    if (strcmp(s,"*")==1) {
        a=pop(&t)*pop(&t);
        push(&t,a);
    }
    if (strcmp(s,"-")==1) {
        a=pop(&t)-pop(&t);
        push(&t,a);
    }
    if (strcmp(s,"+")==1) {
        a=pop(&t)+pop(&t);
        push(&t,a);
    }
    if (strcmp(s,"/")==1) {
        a=pop(&t)/pop(&t);
        push(&t,a);
    }
    freopen("CON", "w", stdout);
    printf("%i",peek(t));
    return 0;
}
