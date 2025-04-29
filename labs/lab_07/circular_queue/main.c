#include <stdio.h>
#include "circular_queue.h"
#include <string.h>

int main(void)
{
    GLASS glass;
    CircularQueue_t t;
    freopen("pohar.txt","r",stdin);
    createQueue(5,&t);
    enqueue(&t,glass);
    enqueue(&t,glass);
    enqueue(&t,glass);
    enqueue(&t,glass);
    dequeue(&t);
    enqueue(&t,glass);
    enqueue(&t,glass);
    display(t);
    if (isRed(t)==true) {
        printf("Van piros pohar");
    }
    else
        printf("Nincs piros pohar");
    return 0;
}