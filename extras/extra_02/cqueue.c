//
// Created by User on 4/8/2025.
//

#include "cqueue.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void readOneBox(BOX *box) {
    scanf("\n%[^\n]",box->name);
    scanf("%f[^\n]",&box->weight);
    scanf("%d[^\n]",&box->type);
    scanf("%d[^\n]",&box->fragile);
}

char *getDescriptionType(enum Type type) {
        switch (type) {
            case 0: return "NORMAL";
            case 1: return "EXPRESS";
            case 2: return "SAME_DAY";
            default: return "OTHER";
        }
}

void printOneBox(BOX box) {
  if(box.fragile==1){
    printf("%s %.2f %s Nem torekeny\n",box.name,box.weight,getDescriptionType(box.type));
    }
   else{
       printf("%s %.2f %s Torekeny\n",box.name,box.weight,getDescriptionType(box.type));
      }
}


void createQueue(int capacity, CircularQueue_t *queue) {
    queue->capacity = capacity;
    queue->elements = (BOX*)malloc(capacity*sizeof(BOX));
    if (!queue->elements) {perror("Memory allocation error!"); exit(-1);}
    queue->front = queue->rear = -1;
}
void destroyQueue(CircularQueue_t *queue) {
    free(queue->elements);
    queue->elements = NULL;
    queue->capacity = 0;
    queue->front = queue->rear = -1;
}
bool isFull(CircularQueue_t queue){
    return (queue.front == (queue.rear + 1) % queue.capacity);
 }
bool isEmpty(CircularQueue_t queue) {
    if(queue.front==-1)
      return true;
    else
      return false;
}
void enqueue(CircularQueue_t *queue, BOX item) {
    if (isFull(*queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    readOneBox(&item);
    queue->elements[queue->rear] = item;
}
BOX dequeue(CircularQueue_t *queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty!\n");
        return box0;
    }
    BOX temp = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
        printf("%i",queue->front);
    }
    return temp;
}
void display(CircularQueue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue.front;
    while (true) {
        printOneBox(queue.elements[i]);
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }
    printf("\n");
}
BOX peek(CircularQueue_t queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return box0;
    }
    return queue.elements[queue.front];
}

bool isFragile(BOX box,CircularQueue_t *queue,CircularQueue_t *tor,CircularQueue_t *ntor){
    int i = queue->front;
    while (true) {
        if(queue->elements[i].fragile==0)
          enqueue(&ntor,queue->elements[i]);
        if(queue->elements[i].fragile==1)
          enqueue(&tor,queue->elements[i]);
        if (i == queue->rear) break;
        i = (i + 1) % queue->capacity;
    }
}

int type(CircularQueue_t queue){
  int N=0,E=0,S=0;
    int i = queue.front;
    while (true) {
        if(queue.elements[i].type==1)
          N++;
        if(queue.elements[i].type==2)
          E++;
        if(queue.elements[i].type==3)
          S++;
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }
    if(N>E && N>S)
      return N;
    if(E>N && E>S)
      return E;
    if(S>N && S>E)
      return S;
}