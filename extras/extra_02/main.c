#include <stdio.h>
#include "cqueue.h"

int main(void) {
    BOX box;
    CircularQueue_t t;
    //readOneBox(&box);
    //printOneBox(box);
    int x=10;
    createQueue(23,&t);
    printf("\n");
    freopen("csomagok.txt","r",stdin);
    for (int i=0;i<x;i++) {
        enqueue(&t,box);
    }
    display(t);
    dequeue(&t);
    dequeue(&t);
    display(t);
    //dequeue(&box);
    enqueue(&t,box);
    enqueue(&t,box);
    //display(t);
    CircularQueue_t tor,ntor;
    isFragile(box,&t,&tor,&ntor);
    display(tor);
    display(ntor);
    type(t);
    return 0;
}
