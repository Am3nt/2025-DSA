//
// Created by User on 4/8/2025.
//

#ifndef CQUEUE_H
#define CQUEUE_H

enum Type {Normal, Express, Same_day,other};
typedef struct {
    char name[30];
    float weight;
    enum Type type;
    bool fragile;
}BOX;

static const BOX box0={"",0.0,5,false};

typedef struct {
    int capacity;
    int front;
    int rear;
    BOX *elements;
}CircularQueue_t;

void createQueue(int capacity, CircularQueue_t *queue);
/**
 * Deallocates the elements array -> free
 * @param queue
 */
void destroyQueue(CircularQueue_t* queue);
/**
 * Checks whether the queue is full or not
 * @param queue
 * @return true/false
 */
bool isFull(CircularQueue_t queue);
/**
 * Checks whether the queue is empty or not
 * @param queue
 * @return true/false
 */
bool isEmpty(CircularQueue_t queue);
/**
 * Adds a new item to the end of the queue
 * @param queue
 * @param item
 */
void enqueue(CircularQueue_t* queue, BOX item);
/**
 * Removes the first item from the queue
 * @param queue
 * @return
 */
BOX dequeue(CircularQueue_t* queue);
/**
 * Prints all items of the queue
 * @param queue
 */
void display(CircularQueue_t queue);
/**
 * Returns the element in the front
 * @param queue
 * @return the element in the front
 */
BOX peek(CircularQueue_t queue);
/**
 *
 * @param glass
 */
void readOneBox(BOX *box);
/**
 *
 * @param type
 * @return
 */
char *getDescriptionType(enum Type type);
/**
 *
 * @param glass
 */
void printOneBox(BOX box);
/**
 *
 * @param box
 * @return
 */
bool isRed(CircularQueue_t queue);

#endif //CQUEUE_H
