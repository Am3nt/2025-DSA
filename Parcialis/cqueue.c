//
// Created by oszti on 3/23/2025.
//

#include "cqueue.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void readOneBox(BOX *box) {
    scanf("\n%[^\n]",box->name);
    scanf("%f",&box->weight);
    scanf("%d",&box->type);
    scanf("%b",&box->fragile);
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
    printf("%s %.2f %s\n",box.name,box.weight,getDescriptionType(box.type),box.fragile);
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
    return (queue.front == -1);
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


