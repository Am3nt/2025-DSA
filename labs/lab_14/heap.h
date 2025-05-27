//
// Created by User on 5/27/2025.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef HEAP_H
#define HEAP_H
#define CAPACITY 90

typedef struct Student{
    char Neptun[7];
    float average;
}Student;

void heapify(Student arr[], int n, int i);
void heapSort(Student arr[], int n);
void printArray(Student arr[], int n);

#endif //HEAP_H

